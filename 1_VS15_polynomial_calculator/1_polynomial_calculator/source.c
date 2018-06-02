#define _CRT_SECURE_NO_WARNINGS		// fopen
#define _CRT_NONSTDC_NO_DEPRECATE	// strdup

#include "polyc.h"

extern int		g_num_lines;

struct _variable * g_list_variables = NULL;

void Insert_Variable_In_Global_List(char *letter, struct _polynomial polynomial)
{
	struct _variable *tmp = g_list_variables,
		*tmp_variable = (struct _variable *)malloc(sizeof(struct _variable));

	tmp_variable->variable = letter;
	tmp_variable->polynomial = polynomial;
	tmp_variable->next = NULL;
	tmp_variable->prev = NULL;

	// Если ни разу не объявляли перемнные
	if (g_list_variables == NULL)
	{
		g_list_variables = tmp_variable;
		return;
	}
	
	while (tmp->next != NULL)
	{
		// Если такая перемнная уже есть. то перезаписываем ее
		if (!strcmp(tmp->variable, letter))
		{
			tmp->polynomial = polynomial;
			return;
		}
		tmp = tmp->next;
	}

	if (!strcmp(tmp->variable, letter))
	{
		tmp->polynomial = polynomial;
		return;
	}

	// Если же нет, то вставляем в конец
	tmp_variable->prev = tmp;
	tmp->next = tmp_variable;
}

struct _polynomial Search_Variable_In_Global_List(char *variable)
{
	struct _variable * tmp = g_list_variables;
	struct _polynomial result;

	while (tmp != NULL)
	{
		if (!strcmp(tmp->variable, variable))
		{
			result = tmp->polynomial;
			return result;
		}
		tmp = tmp->next;
	}
	// Lexical error
	Report_Bug("not initialize variable ", variable);
}


struct _monomial Set_Monomial(int coefficient, char *letter, int power)
{
	struct _monomial result;

	result.coefficient = coefficient;

	if ((strcmp(letter, "") && power == 0) || coefficient == 0)
	{
		result.variable = "";
		result.power = 0;
		return result;
	}

	result.variable = letter;
	result.power = power;

	//printf("Set_monom: %d%s^%d\n", result.coefficient, result.variable, result.power);
	return result;
}

struct _polynomial Initialize_Polynomial(void)
{
	struct _polynomial result;

	result.begin = (struct _node *) malloc(sizeof(struct _node));
	result.begin->prev = NULL;
	result.begin->next = NULL;

	result.count = 0;

	return result;
}

struct _polynomial Add_Monomial_in_Polynomial(struct _polynomial polynomial, struct _monomial monomial)
{
	struct _polynomial	result;
	struct _node		* tmp;

	result = polynomial;

	tmp = result.begin;

	// Если в многочлене нет одночленов
	if (result.count == 0)
	{
		tmp->item = monomial;

		result.count++;

		return result;
	}

	// Доходим до конца и добавляем
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = (struct _node *)malloc(sizeof(struct _node));

	tmp->next->prev = tmp;
	tmp->next->next = NULL;

	tmp = tmp->next;

	tmp->item = monomial;

	result.count++;

	return result;
}

struct _node * Remove_Node(struct _polynomial *polynomial, struct _node *node)
{
	struct _node * result = node;

	// Если удаляемый узел начало полинома
	if (polynomial->begin == node)
	{
		// Еслм последний узел в полиноме, возрат ноль
		if (node->next == NULL)
		{
			free(node);
			// error!!!
			return NULL;
		}

		node->next->prev = NULL;

		result = node->next;
		free(node);

		polynomial->begin = result;
		return result;
	}

	// Если дошли до конца полинома, возвратить предыдущий, т.к. все равно выполнится "tmp2 = tmp2->next;"
	if (node->next == NULL)
	{
		node->prev->next = NULL;
		result = node->prev;

		free(node);
		return result;
	}

	node->next->prev = node->prev;
	node->prev->next = node->next;
	// Удаление узла, возвратить предыдущий, т.к. в привидении подобных все равно перейдет на следующий
	result = node->prev;
	free(node);
	return result;
}

struct _polynomial Remove_Similar_Summands(struct _polynomial polynomial)
{
	struct _polynomial result = Initialize_Polynomial();
	struct _monomial tmp_monom;
	struct _node	* tmp1 = polynomial.begin,
		*tmp2;

	while (tmp1 != NULL)
	{
		// Ищем все подобные для этого элемента
		tmp_monom = tmp1->item;

		tmp2 = polynomial.begin;

		while (tmp2 != NULL)
		{
			if (
				//!strcmp(tmp1->item.variable_with_power, tmp2->item.variable_with_power) &&

				!strcmp(tmp1->item.variable, tmp2->item.variable) &&
				tmp1->item.power == tmp2->item.power &&

				tmp1 != tmp2)
			{
				tmp_monom.coefficient += tmp2->item.coefficient;

				// Удалаем узел, т.к. добавили значение коэффициета
				tmp2 = Remove_Node(&polynomial, tmp2);
			}

			tmp2 = tmp2->next;
		}

		// Удаляем узел, т.к. результирующий одночлен будет занесен в результирующий многочлен
		tmp1 = Remove_Node(&polynomial, tmp1);

		/*
		if (tmp_monom.coefficient == 0)
		{
			continue;
		}
		//*/

		result = Add_Monomial_in_Polynomial(result, tmp_monom);
	}

	return result;
}


struct _polynomial Add_Polynomials(struct _polynomial polynomial_one, struct _polynomial polynomial_two)
{
	struct _polynomial result = polynomial_one;
	struct _node * tmp = polynomial_two.begin;

	result = Add_Monomial_in_Polynomial(result, tmp->item);
	// Сначала добавить одночлен из "головы", потом все остальные
	while (tmp->next != NULL)
	{
		tmp = tmp->next;

		result = Add_Monomial_in_Polynomial(result, tmp->item);

		//Print_Monomial(&(tmp->item));
	}

	return result = Remove_Similar_Summands(result);
}

struct _polynomial Uminus_Polynomial(struct _polynomial *polynomial)
{
	struct _node * tmp = polynomial->begin;

	while (tmp != NULL)
	{
		tmp->item.coefficient *= (-1);

		tmp = tmp->next;
	}

	return *polynomial;
}

struct _polynomial Subtract_Polynomials(struct _polynomial polynomial_one, struct _polynomial polynomial_two)
{
	struct _polynomial result = Add_Polynomials(polynomial_one, Uminus_Polynomial(&polynomial_two));

	return result;
}

struct _polynomial Multiply_Polynomials(struct _polynomial polynomial_one, struct _polynomial polynomial_two)
{
	struct _polynomial result = Initialize_Polynomial();
	struct _monomial tmp_monom;
	struct _node	* tmp1 = polynomial_one.begin,
		*tmp2;

	while (tmp1 != NULL)
	{
		tmp2 = polynomial_two.begin;

		while (tmp2 != NULL)
		{
			// Раскрываем "фонтанчиком"
			tmp_monom = tmp1->item;

			tmp_monom.coefficient *= tmp2->item.coefficient;
			
			if (!strcmp(tmp_monom.variable, tmp2->item.variable))
			{
				tmp_monom.power += tmp2->item.power;
			}
			else
			{
				if (!strcmp(tmp_monom.variable, ""))
				{
					tmp_monom.variable = strdup(tmp2->item.variable);
					tmp_monom.power += tmp2->item.power;
				}
				else if (!strcmp(tmp2->item.variable, ""))
				{
					;
				}
				else
				{
					// Если умножаем разные переменные, и они не совпадают
					// Semantic error
					//g_num_lines;
					Report_Bug("inccorect multiplication of variables", "");
				}
			}

			if (tmp_monom.coefficient == 0)
			{
				tmp_monom.variable = strdup("");
				tmp_monom.power = 0;
			}
			
			result = Add_Monomial_in_Polynomial(result, tmp_monom);

			tmp2 = tmp2->next;
		}

		tmp1 = tmp1->next;
	}

	return result = Remove_Similar_Summands(result);
}


void Print_Monomial(struct _monomial *monomial)
{
	if (!strcmp(monomial->variable, ""))
	{
		printf("%d", monomial->coefficient);
	}
	else
	{
		if (abs(monomial->coefficient) == 1)
		{
			if (monomial->coefficient == -1)
			{
				printf("-");
			}
			if (monomial->power == 1)
			{
				printf("%s", monomial->variable);
			}
			else
			{
				printf("%s^%d", monomial->variable, monomial->power);
			}
		}
		else
		{
			if (monomial->power == 1)
			{
				printf("%d%s", monomial->coefficient, monomial->variable);
			}
			else
			{
				if (monomial->coefficient == 1)
				{
					printf("%s^%d", monomial->variable, monomial->power);
				}
				else
				{
					printf("%d%s^%d", monomial->coefficient, monomial->variable, monomial->power);
				}
			}
		}
	}
}

void Print_Polynomial(struct _polynomial *polynomial)
{
	struct _node *tmp = polynomial->begin;
	printf("= ");
	
	while (tmp->item.coefficient == 0 && tmp->next != NULL)
	{
		tmp = tmp->next;
		continue;
	}

	Print_Monomial(&(tmp->item));
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->item.coefficient == 0)
		{
			tmp = tmp->next;
			continue;
		}
		if (tmp->item.coefficient < 0)
		{
			;// printf("-");
		}
		else
		{
			printf("+");
		}
		Print_Monomial(&(tmp->item));
		tmp = tmp->next;
	}
	printf(".\n");
}


#ifdef __unix__ 
	// __unix__ is usually defined by compilers targeting Unix systems
	#include "y.tab.h"
#elif defined _WIN32 
	// _Win32 is usually defined by compilers targeting 32 or 64 bit Windows systems
	#include "y_tab.h"
#endif

int g_get;

void yyerror(char const *s)
{
	if (g_get == EOF || g_get == '\n')
	{
		printf("ERROR in line %d: maybe forgot '\\n' in end file\n", g_num_lines + 1, g_get);
	}
	else if (g_get == '+' || g_get == '-' || g_get == '=' || g_get == '^' || g_get == '*')
	{
		printf("ERROR in line %d: incorrect operator '%c'\n", g_num_lines + 1, g_get);
	}
	else
	{
		// Syntax error
		printf("ERROR in line %d: '%s' on token ...\n", g_num_lines + 1, s);
	}
}

void Report_Bug(const char *s, const char *s2)
{
	printf("ERROR in line %d: %s%s\n", g_num_lines, s, s2);
	exit(-1);
}

//*
FILE *inputStream;

#define yyin inputStream
#define tmp_scanf(f_, ...) fscanf(yyin, (f_), __VA_ARGS__)

int yylex(void)
{
	while ((g_get = fgetc(yyin)) == ' ' || g_get == '\t')
	{
		;
	}

	while (g_get == '/')
	{
		g_get = fgetc(yyin);


		if (g_get == '/')
		{
			while ((g_get = fgetc(yyin)) != '\n')
			{
				;
			}
			g_num_lines++;
		}
		else
		{
			g_num_lines++;
			Report_Bug("incorrect comment", "");
		}

		g_get = fgetc(yyin);
	}

	if (g_get == EOF)
	{
		return 0;
	}
	else if (isdigit(g_get))
	{
		yylval.num = 0;
		ungetc(g_get, yyin);
		tmp_scanf("%d", &yylval.num);

		return DIGIT;
	}
	else if (isalpha(g_get))
	{
		static char *symbuf = 0;
		int  length = 0;
		int  i = 0;

		// Initially make the buffer long enough
		// for a 40-character symbol name.
		if (length == 0)
		{
			length = 40;
			symbuf = (char *)malloc(length + 1);
		}
		do
		{
			// If buffer is full, make it bigger.
			if (i == length)
			{
				length *= 2;
				symbuf = (char *)realloc(symbuf, length + 1);
			}

			// Add this character to the buffer.
			symbuf[i++] = g_get;

			// Get another character.
			g_get = fgetc(yyin);
		//} while (isalnum(get));
		} while (isalpha(g_get));

		ungetc(g_get, yyin);

		symbuf[i] = '\0';

		//ungetc(get, yyin);
		//tmp_scanf("%s", symbuf);

		if (!strcmp("PRINT", symbuf) || !strcmp("print", symbuf))
		{
			return PRINT;
		}

		yylval.str = symbuf;

		return LETTER;
	}
	else
	{
		switch (g_get)
		{
		case '+':
		{
			return g_get;
		}
		case '-':
		{
			return g_get;
		}
		case '^':
		{
			return g_get;
		}
		case '*':
		{
			return g_get;
		}
		case '(':
		{
			return g_get;
		}
		case ')':
		{
			return g_get;
		}
		case '=':
		{
			return g_get;
		}
		case '$':
		{
			return g_get;
		}
		case '\n':
		{
			g_num_lines++;
			return g_get;
		}
		}
	}
	return g_get;
}

int main(void)
{
	inputStream = fopen("input.txt", "r");
	if (inputStream == NULL)
	{
		printf("Not found file. Creadte file \"input.txt\" and input in file polynom.\n");
		exit(-1);
	}

	//yyset_in(inputStream);
	yyparse();

	fclose(inputStream);
}
//*/