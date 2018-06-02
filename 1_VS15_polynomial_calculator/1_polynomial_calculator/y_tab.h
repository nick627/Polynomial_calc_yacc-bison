typedef union	// what types will be used further
{
	//struct _variable	var;
	struct _polynomial 	poly;
	struct _monomial	mono;
	int 				num;
	char *				str;
} YYSTYPE;
#define	DIGIT	258
#define	LETTER	259
#define	PRINT	260
#define	UMINUS	261


extern YYSTYPE yylval;
