%{
	//#define _CRT_SECURE_NO_WARNINGS	// fopen
	//#define _CRT_NONSTDC_NO_DEPRECATE // fgetchar

	#include "polyc.h"

	//#ifdef __unix__ 
		// __unix__ is usually defined by compilers targeting Unix systems
	
	//#elif defined _WIN32 
		// _Win32 is usually defined by compilers targeting 32 or 64 bit Windows systems
		#define alloca malloc
	//#endif
		
	int yylex (void);
	void yyerror(char const *s);
%}

%union	// what types will be used further
{
	//struct _variable	var;
	struct _polynomial 	poly;
	struct _monomial	mono;
	int 				num;
	char *				str;
}

%type <str>		variable
%type <poly> 	polynomial
%type <mono> 	monomial
%type <num> 	digit

%token <num> 	DIGIT
%token <str> 	LETTER PRINT

%left '+' '-'
%left '*'
%right UMINUS

%right '^'

%start list

%%	// follows grammatics

list	:	
			// empty
		|	
			list 
			'\n'
		|	
			list 
			'\r'
		| 
			list 
			begin
	;

begin 	:
			variable
			'='
			polynomial
			'\n'
			{
				Insert_Variable_In_Global_List($1, $3);
			}
		|
			PRINT
			variable
			'\n'
			{
				struct _polynomial tmp;
				printf("variable \"%s\" ", $2);
				tmp = Search_Variable_In_Global_List($2);
				Print_Polynomial(&tmp);
			}
		|
			PRINT
			polynomial
			'\n'
			{
				printf("polynomial ");
				Print_Polynomial(&$2);
			}
	;

polynomial	:	
				'('
				polynomial
				')'
				{
					$$ = $2;
				}
			|
				polynomial
				'+'
				polynomial
				{
					$$ = Add_Polynomials($1, $3);
				}
			|
				polynomial
				'-'
				polynomial
				{
					$$ = Subtract_Polynomials($1, $3);
				}
			|
				polynomial
				'*'
				polynomial
				{
					$$ = Multiply_Polynomials($1, $3);
				}
			|
				'-'
				polynomial
				%prec
				UMINUS
				{
					$$ = Uminus_Polynomial(&$2);
				}
			|
				polynomial
				'^'
				digit
				{
					if ($3 == 0)
					{
						if ($1.begin->item.coefficient == 0)
						{
							// Semantic error
							Report_Bug("uncertainty (0^0)", "");
						}

						$$ = Initialize_Polynomial();
						$$ = Add_Monomial_in_Polynomial($$, Set_Monomial(1, "", 0));
					}
					else if ($3 == 1)
					{
						$$ = $1;
					}
					else if ($3 >= 2)
					{
						int i;
						for (i = 0; i < $3 - 1; i++)
						{
							$$ = Multiply_Polynomials($$, $1);
						}
					}
				}
			|
				monomial
				{
					$$ = Initialize_Polynomial();
					$$ = Add_Monomial_in_Polynomial($$, $1);
				}
			|
				variable
				{ 
					struct _polynomial tmp;
					tmp = Initialize_Polynomial();
					tmp = Add_Monomial_in_Polynomial(tmp, Set_Monomial(1, "", 0));

					$$ = Search_Variable_In_Global_List($1); 

					$$ = Multiply_Polynomials($$, tmp);
				}

// pseudo rules for error
			|
				'+' polynomial
				{
					Report_Bug("incorrect '+ <polynomial>'","");
				}
			|
				'*' polynomial
				{
					Report_Bug("incorrect '* <polynomial>'","");
				}
			|
				polynomial '+' '+'
				{
					Report_Bug("incorrect +","");
				}
			|
				polynomial '^' '^'
				{
					Report_Bug("incorrect ^","");
				}
			|
				polynomial '^' '-'
				{
					Report_Bug("incorrect ^-","");
				}
	;

monomial	:	
				DIGIT
				{
					$$ = Set_Monomial($1, "", 0);
				}
			|
				LETTER
				{
					$$ = Set_Monomial(1, $1, 1);
				}
			|
				DIGIT
				LETTER
				{
					$$ = Set_Monomial($1, $2, 1);
				}
			|
				LETTER
				'^'
				digit
				{
					$$ = Set_Monomial(1, $1, $3);
				}
			|
				DIGIT
				LETTER
				'^'
				digit
				{
					$$ = Set_Monomial($1, $2, $4);
				}
	;

variable	:
				'$'
				LETTER
				{
					$$ = $2;
				}
	;

digit	:
			DIGIT
			{
				$$ = $1;
			}
		|
			'('
			digit
			')'
			{
				$$ = $2;
			}
		|
			digit '^' digit
			{
				$$ = $1;
				int i = 0;
				for (i = 0; i < $3 - 1; i++)
				{
					$$ = $$ * $1;
				}
				if ($3 == 0)
				{
					$$ = 1;

					if($1 == 0)
					{
						Report_Bug("incorrect 0^0","");
					}
				}
				
			}
	;

%%	// end's grammatics
