/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    WORD = 259,                    /* WORD  */
    TOK_ENTER = 260,               /* TOK_ENTER  */
    TOK_ALL = 261,                 /* TOK_ALL  */
    TOK_SB = 262,                  /* TOK_SB  */
    TOK_RB = 263,                  /* TOK_RB  */
    TOK_DB = 264,                  /* TOK_DB  */
    TOK_DE = 265,                  /* TOK_DE  */
    TOK_DI = 266,                  /* TOK_DI  */
    TOK_DP = 267,                  /* TOK_DP  */
    TOK_DR = 268,                  /* TOK_DR  */
    TOK_HELP = 269,                /* TOK_HELP  */
    TOK_RUN = 270,                 /* TOK_RUN  */
    TOK_RST = 271,                 /* TOK_RST  */
    TOK_RST_TIMER = 272,           /* TOK_RST_TIMER  */
    TOK_STEP = 273,                /* TOK_STEP  */
    TOK_UNASM = 274,               /* TOK_UNASM  */
    TOK_MOD_EXT = 275,             /* TOK_MOD_EXT  */
    TOK_MOD_INT = 276,             /* TOK_MOD_INT  */
    TOK_MOD_PROG = 277,            /* TOK_MOD_PROG  */
    TOK_MOD_REG = 278,             /* TOK_MOD_REG  */
    TOK_QUIT = 279,                /* TOK_QUIT  */
    TOK_A = 280,                   /* TOK_A  */
    TOK_B = 281,                   /* TOK_B  */
    TOK_C = 282,                   /* TOK_C  */
    TOK_D = 283                    /* TOK_D  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define WORD 259
#define TOK_ENTER 260
#define TOK_ALL 261
#define TOK_SB 262
#define TOK_RB 263
#define TOK_DB 264
#define TOK_DE 265
#define TOK_DI 266
#define TOK_DP 267
#define TOK_DR 268
#define TOK_HELP 269
#define TOK_RUN 270
#define TOK_RST 271
#define TOK_RST_TIMER 272
#define TOK_STEP 273
#define TOK_UNASM 274
#define TOK_MOD_EXT 275
#define TOK_MOD_INT 276
#define TOK_MOD_PROG 277
#define TOK_MOD_REG 278
#define TOK_QUIT 279
#define TOK_A 280
#define TOK_B 281
#define TOK_C 282
#define TOK_D 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "parser.y"

        int number;
        char *string;

#line 128 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
