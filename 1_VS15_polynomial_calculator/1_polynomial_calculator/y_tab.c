
/*  A Bison parser, made from polyc_yacc.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	DIGIT	258
#define	LETTER	259
#define	PRINT	260
#define	UMINUS	261

#line 1 "polyc_yacc.y"

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

#line 19 "polyc_yacc.y"
typedef union	// what types will be used further
{
	//struct _variable	var;
	struct _polynomial 	poly;
	struct _monomial	mono;
	int 				num;
	char *				str;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		52
#define	YYFLAG		-32768
#define	YYNTBASE	17

#define YYTRANSLATE(x) ((unsigned)(x) <= 261 ? yytranslate[x] : 23)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    11,
     2,     2,    12,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,    16,     2,     2,     2,    14,
    15,     8,     6,     2,     7,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    13,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    10,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     9
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     4,     7,    10,    15,    19,    23,    27,    31,
    35,    39,    42,    46,    48,    50,    53,    56,    60,    64,
    68,    70,    72,    75,    79,    84,    87,    89,    93
};

static const short yyrhs[] = {    -1,
    17,    11,     0,    17,    12,     0,    17,    18,     0,    21,
    13,    19,    11,     0,     5,    21,    11,     0,     5,    19,
    11,     0,    14,    19,    15,     0,    19,     6,    19,     0,
    19,     7,    19,     0,    19,     8,    19,     0,     7,    19,
     0,    19,    10,    22,     0,    20,     0,    21,     0,     6,
    19,     0,     8,    19,     0,    19,     6,     6,     0,    19,
    10,    10,     0,    19,    10,     7,     0,     3,     0,     4,
     0,     3,     4,     0,     4,    10,    22,     0,     3,     4,
    10,    22,     0,    16,     4,     0,     3,     0,    14,    22,
    15,     0,    22,    10,    22,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    46,    48,    51,    54,    59,    67,    77,    87,    94,   101,
   108,   115,   123,   152,   158,   171,   176,   181,   186,   191,
   198,   203,   208,   214,   221,   231,   239,   244,   251
};

static const char * const yytname[] = {   "$","error","$undefined.","DIGIT",
"LETTER","PRINT","'+'","'-'","'*'","UMINUS","'^'","'\\n'","'\\r'","'='","'('",
"')'","'$'","list","begin","polynomial","monomial","variable","digit",""
};
#endif

static const short yyr1[] = {     0,
    17,    17,    17,    17,    18,    18,    18,    19,    19,    19,
    19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
    20,    20,    20,    20,    20,    21,    22,    22,    22
};

static const short yyr2[] = {     0,
     0,     2,     2,     2,     4,     3,     3,     3,     3,     3,
     3,     2,     3,     1,     1,     2,     2,     3,     3,     3,
     1,     1,     2,     3,     4,     2,     1,     3,     3
};

static const short yydefact[] = {     1,
     0,     0,     2,     3,     0,     4,     0,    21,    22,     0,
     0,     0,     0,     0,    14,    15,    26,     0,    23,     0,
    16,    15,    12,    17,     0,     0,     0,     0,     0,     7,
     6,     0,     0,    27,     0,    24,     8,    18,     9,    10,
    11,    20,    19,    13,     5,    25,     0,     0,    28,    29,
     0,     0
};

static const short yydefgoto[] = {     1,
     6,    21,    15,    22,    36
};

static const short yypact[] = {-32768,
     3,    24,-32768,-32768,    14,-32768,    10,    25,    23,    24,
    24,    24,    24,    63,-32768,    26,-32768,    24,    29,    -1,
    -4,-32768,    33,    33,    57,    38,    24,    24,    48,-32768,
-32768,    69,    -1,-32768,    -1,    37,-32768,    45,    -4,    -4,
    33,-32768,-32768,    37,-32768,    37,     2,    -1,-32768,    37,
    34,-32768
};

static const short yypgoto[] = {-32768,
-32768,    -2,-32768,    20,   -28
};


#define	YYLAST		80


static const short yytable[] = {    14,
    44,    34,    51,    28,    46,    29,    47,     2,    23,    24,
    25,    48,    35,     3,     4,    32,    49,    17,     5,    50,
     7,    16,    18,    39,    40,    41,     8,     9,    19,    10,
    11,    12,    20,    52,     0,     0,    31,    13,    33,     5,
     8,     9,    29,    38,    11,    12,    48,     8,     9,     0,
    34,    13,    12,     5,    42,     0,     0,    43,    13,     0,
     5,    35,    26,    27,    28,     0,    29,     0,    26,    27,
    28,    37,    29,    30,    26,    27,    28,     0,    29,    45
};

static const short yycheck[] = {     2,
    29,     3,     0,     8,    33,    10,    35,     5,    11,    12,
    13,    10,    14,    11,    12,    18,    15,     4,    16,    48,
     1,     2,    13,    26,    27,    28,     3,     4,     4,     6,
     7,     8,    10,     0,    -1,    -1,    11,    14,    10,    16,
     3,     4,    10,     6,     7,     8,    10,     3,     4,    -1,
     3,    14,     8,    16,     7,    -1,    -1,    10,    14,    -1,
    16,    14,     6,     7,     8,    -1,    10,    -1,     6,     7,
     8,    15,    10,    11,     6,     7,     8,    -1,    10,    11
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */
   
#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 5:
#line 64 "polyc_yacc.y"
{
				Insert_Variable_In_Global_List(yyvsp[-3].str, yyvsp[-1].poly);
			;
    break;}
case 6:
#line 71 "polyc_yacc.y"
{
				struct _polynomial tmp;
				printf("variable \"%s\" ", yyvsp[-1].str);
				tmp = Search_Variable_In_Global_List(yyvsp[-1].str);
				Print_Polynomial(&tmp);
			;
    break;}
case 7:
#line 81 "polyc_yacc.y"
{
				printf("polynomial ");
				Print_Polynomial(&yyvsp[-1].poly);
			;
    break;}
case 8:
#line 91 "polyc_yacc.y"
{
					yyval.poly = yyvsp[-1].poly;
				;
    break;}
case 9:
#line 98 "polyc_yacc.y"
{
					yyval.poly = Add_Polynomials(yyvsp[-2].poly, yyvsp[0].poly);
				;
    break;}
case 10:
#line 105 "polyc_yacc.y"
{
					yyval.poly = Subtract_Polynomials(yyvsp[-2].poly, yyvsp[0].poly);
				;
    break;}
case 11:
#line 112 "polyc_yacc.y"
{
					yyval.poly = Multiply_Polynomials(yyvsp[-2].poly, yyvsp[0].poly);
				;
    break;}
case 12:
#line 120 "polyc_yacc.y"
{
					yyval.poly = Uminus_Polynomial(&yyvsp[0].poly);
				;
    break;}
case 13:
#line 127 "polyc_yacc.y"
{
					if (yyvsp[0].num == 0)
					{
						if (yyvsp[-2].poly.begin->item.coefficient == 0)
						{
							// Semantic error
							Report_Bug("uncertainty (0^0)", "");
						}

						yyval.poly = Initialize_Polynomial();
						yyval.poly = Add_Monomial_in_Polynomial(yyval.poly, Set_Monomial(1, "", 0));
					}
					else if (yyvsp[0].num == 1)
					{
						yyval.poly = yyvsp[-2].poly;
					}
					else if (yyvsp[0].num >= 2)
					{
						int i;
						for (i = 0; i < yyvsp[0].num - 1; i++)
						{
							yyval.poly = Multiply_Polynomials(yyval.poly, yyvsp[-2].poly);
						}
					}
				;
    break;}
case 14:
#line 154 "polyc_yacc.y"
{
					yyval.poly = Initialize_Polynomial();
					yyval.poly = Add_Monomial_in_Polynomial(yyval.poly, yyvsp[0].mono);
				;
    break;}
case 15:
#line 160 "polyc_yacc.y"
{ 
					struct _polynomial tmp;
					tmp = Initialize_Polynomial();
					tmp = Add_Monomial_in_Polynomial(tmp, Set_Monomial(1, "", 0));

					yyval.poly = Search_Variable_In_Global_List(yyvsp[0].str); 

					yyval.poly = Multiply_Polynomials(yyval.poly, tmp);
				;
    break;}
case 16:
#line 173 "polyc_yacc.y"
{
					Report_Bug("incorrect '+ <polynomial>'","");
				;
    break;}
case 17:
#line 178 "polyc_yacc.y"
{
					Report_Bug("incorrect '* <polynomial>'","");
				;
    break;}
case 18:
#line 183 "polyc_yacc.y"
{
					Report_Bug("incorrect +","");
				;
    break;}
case 19:
#line 188 "polyc_yacc.y"
{
					Report_Bug("incorrect ^","");
				;
    break;}
case 20:
#line 193 "polyc_yacc.y"
{
					Report_Bug("incorrect ^-","");
				;
    break;}
case 21:
#line 200 "polyc_yacc.y"
{
					yyval.mono = Set_Monomial(yyvsp[0].num, "", 0);
				;
    break;}
case 22:
#line 205 "polyc_yacc.y"
{
					yyval.mono = Set_Monomial(1, yyvsp[0].str, 1);
				;
    break;}
case 23:
#line 211 "polyc_yacc.y"
{
					yyval.mono = Set_Monomial(yyvsp[-1].num, yyvsp[0].str, 1);
				;
    break;}
case 24:
#line 218 "polyc_yacc.y"
{
					yyval.mono = Set_Monomial(1, yyvsp[-2].str, yyvsp[0].num);
				;
    break;}
case 25:
#line 226 "polyc_yacc.y"
{
					yyval.mono = Set_Monomial(yyvsp[-3].num, yyvsp[-2].str, yyvsp[0].num);
				;
    break;}
case 26:
#line 234 "polyc_yacc.y"
{
					yyval.str = yyvsp[0].str;
				;
    break;}
case 27:
#line 241 "polyc_yacc.y"
{
				yyval.num = yyvsp[0].num;
			;
    break;}
case 28:
#line 248 "polyc_yacc.y"
{
				yyval.num = yyvsp[-1].num;
			;
    break;}
case 29:
#line 253 "polyc_yacc.y"
{
				yyval.num = yyvsp[-2].num;
				int i = 0;
				for (i = 0; i < yyvsp[0].num - 1; i++)
				{
					yyval.num = yyval.num * yyvsp[-2].num;
				}
				if (yyvsp[0].num == 0)
				{
					yyval.num = 1;

					if(yyvsp[-2].num == 0)
					{
						Report_Bug("incorrect 0^0","");
					}
				}
				
			;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 273 "polyc_yacc.y"
	// end's grammatics
