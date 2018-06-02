#ifndef POLYC_H_
#define POLYC_H_

#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int		g_num_lines;

struct _monomial
{
	int 	coefficient;	// коэффициент
	char 	* variable;		// имя переменной 
	int 	power;			// степень
};

struct _polynomial
{
	struct _node 	* begin;	// указатель на первый одночлен в полиноме
	int 			count;		// число элементов в полиноме
};

struct _node
{
	struct _monomial 	item;		// указатель на одночлен
	struct _node		* next;		// указатель на след. узел
	struct _node 		* prev;		// указатель на пред. узел
};

struct _variable
{
	char				* variable;	// имя переменной
	struct _polynomial	polynomial; // копия полинома
	struct _variable	* next;		// указатель на следующую переменную
	struct _variable	* prev;		// указатель на следующую переменную
};

void	Report_Bug	(const char *, const char *);

void				Insert_Variable_In_Global_List	(char *, struct _polynomial );
struct _polynomial	Search_Variable_In_Global_List	(char *);

struct _monomial	Set_Monomial	(int, char *, int);

struct _polynomial	Initialize_Polynomial		(void);
struct _polynomial 	Add_Monomial_in_Polynomial	(struct _polynomial, struct _monomial);

struct _node *		Remove_Node				(struct _polynomial *, struct _node *);
struct _polynomial	Remove_Similar_Summands	(struct _polynomial);

struct _polynomial Add_Polynomials		(struct _polynomial, struct _polynomial);
struct _polynomial Subtract_Polynomials	(struct _polynomial, struct _polynomial);
struct _polynomial Multiply_Polynomials	(struct _polynomial, struct _polynomial);
struct _polynomial Uminus_Polynomial	(struct _polynomial *);

void Print_Monomial		(struct _monomial *);
void Print_Polynomial	(struct _polynomial *);

#endif

//x^2+3x+1+(x^2+2*(x^4+1)*(x^3-3)-3x-4)-3
