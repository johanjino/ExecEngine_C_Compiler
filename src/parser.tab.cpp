/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_SIZEOF = 6,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 7,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 8,                     /* INC_OP  */
  YYSYMBOL_DEC_OP = 9,                     /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 10,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 11,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 13,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 16,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 17,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 18,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 19,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 20,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 21,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 22,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 23,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 24,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 25,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 26,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 27,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPE_NAME = 28,                 /* TYPE_NAME  */
  YYSYMBOL_TYPEDEF = 29,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 30,                    /* EXTERN  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_AUTO = 32,                      /* AUTO  */
  YYSYMBOL_REGISTER = 33,                  /* REGISTER  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_SHORT = 35,                     /* SHORT  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_LONG = 37,                      /* LONG  */
  YYSYMBOL_SIGNED = 38,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 39,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 41,                    /* DOUBLE  */
  YYSYMBOL_VOLATILE = 42,                  /* VOLATILE  */
  YYSYMBOL_VOID = 43,                      /* VOID  */
  YYSYMBOL_STRUCT = 44,                    /* STRUCT  */
  YYSYMBOL_UNION = 45,                     /* UNION  */
  YYSYMBOL_ENUM = 46,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 47,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 48,                      /* CASE  */
  YYSYMBOL_DEFAULT = 49,                   /* DEFAULT  */
  YYSYMBOL_IF = 50,                        /* IF  */
  YYSYMBOL_ELSE = 51,                      /* ELSE  */
  YYSYMBOL_SWITCH = 52,                    /* SWITCH  */
  YYSYMBOL_WHILE = 53,                     /* WHILE  */
  YYSYMBOL_DO = 54,                        /* DO  */
  YYSYMBOL_FOR = 55,                       /* FOR  */
  YYSYMBOL_GOTO = 56,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 57,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 58,                     /* BREAK  */
  YYSYMBOL_RETURN = 59,                    /* RETURN  */
  YYSYMBOL_60_ = 60,                       /* '('  */
  YYSYMBOL_61_ = 61,                       /* ')'  */
  YYSYMBOL_62_ = 62,                       /* ';'  */
  YYSYMBOL_63_ = 63,                       /* ','  */
  YYSYMBOL_64_ = 64,                       /* '{'  */
  YYSYMBOL_65_ = 65,                       /* '}'  */
  YYSYMBOL_66_ = 66,                       /* '='  */
  YYSYMBOL_67_ = 67,                       /* '+'  */
  YYSYMBOL_68_ = 68,                       /* '-'  */
  YYSYMBOL_69_ = 69,                       /* '>'  */
  YYSYMBOL_70_ = 70,                       /* '<'  */
  YYSYMBOL_71_ = 71,                       /* '!'  */
  YYSYMBOL_72_ = 72,                       /* '&'  */
  YYSYMBOL_73_ = 73,                       /* '|'  */
  YYSYMBOL_74_ = 74,                       /* '^'  */
  YYSYMBOL_75_ = 75,                       /* '*'  */
  YYSYMBOL_76_ = 76,                       /* '/'  */
  YYSYMBOL_77_ = 77,                       /* '?'  */
  YYSYMBOL_78_ = 78,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_ROOT = 80,                      /* ROOT  */
  YYSYMBOL_OUTPUT = 81,                    /* OUTPUT  */
  YYSYMBOL_HEADS = 82,                     /* HEADS  */
  YYSYMBOL_HEAD = 83,                      /* HEAD  */
  YYSYMBOL_PARAMETER = 84,                 /* PARAMETER  */
  YYSYMBOL_BLOCK = 85,                     /* BLOCK  */
  YYSYMBOL_BODY = 86,                      /* BODY  */
  YYSYMBOL_LINE = 87,                      /* LINE  */
  YYSYMBOL_STATEMENT = 88,                 /* STATEMENT  */
  YYSYMBOL_DECLARATION = 89,               /* DECLARATION  */
  YYSYMBOL_EXPR = 90,                      /* EXPR  */
  YYSYMBOL_TERM = 91,                      /* TERM  */
  YYSYMBOL_UNARY = 92,                     /* UNARY  */
  YYSYMBOL_FACTOR = 93,                    /* FACTOR  */
  YYSYMBOL_ARGUMENTS = 94,                 /* ARGUMENTS  */
  YYSYMBOL_IF_ELSE_SWITCH = 95,            /* IF_ELSE_SWITCH  */
  YYSYMBOL_CASES = 96,                     /* CASES  */
  YYSYMBOL_SWITCH_BLOCK = 97,              /* SWITCH_BLOCK  */
  YYSYMBOL_SWITCH_BODY = 98,               /* SWITCH_BODY  */
  YYSYMBOL_LOOP = 99,                      /* LOOP  */
  YYSYMBOL_DATA_TYPES = 100                /* DATA_TYPES  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   698

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,     2,     2,     2,    72,     2,
      60,    61,    75,    67,    63,    68,     2,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    78,    62,
      70,    66,    69,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    74,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    73,    65,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    59,    67,    68,    74,    75,    76,    77,
      81,    82,    86,    87,    90,    91,    94,    95,    96,    97,
     101,   102,   103,   104,   107,   108,   109,   110,   119,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   146,   147,   148,   149,   150,   151,   154,
     155,   156,   160,   161,   165,   166,   167,   168,   169,   172,
     173,   182,   183,   184,   185,   188,   189,   192,   196,   197,
     204,   205,   206,   216,   217,   218,   219,   220,   221,   222,
     223,   224
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM",
  "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'('", "')'", "';'", "','",
  "'{'", "'}'", "'='", "'+'", "'-'", "'>'", "'<'", "'!'", "'&'", "'|'",
  "'^'", "'*'", "'/'", "'?'", "':'", "$accept", "ROOT", "OUTPUT", "HEADS",
  "HEAD", "PARAMETER", "BLOCK", "BODY", "LINE", "STATEMENT", "DECLARATION",
  "EXPR", "TERM", "UNARY", "FACTOR", "ARGUMENTS", "IF_ELSE_SWITCH",
  "CASES", "SWITCH_BLOCK", "SWITCH_BODY", "LOOP", "DATA_TYPES", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     123,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
      15,   -90,   123,   -90,    24,   -90,   -90,   -48,    56,   -56,
     -90,    58,    58,    58,   -38,     3,    58,     9,   -90,   624,
     -67,   -90,   -90,    66,    13,    58,   -41,   624,   624,   363,
     -90,   241,   -90,   -90,   624,    14,   357,   -90,   -90,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    53,    53,    19,   -90,   624,    16,
     624,   -90,    20,    22,    29,    34,    40,   -90,   -90,    58,
     -90,    10,   299,    39,    41,   189,   -90,   -90,   -90,   -90,
     -90,   624,   624,   624,   624,   624,   624,   624,   624,   624,
     624,   624,   624,   624,   624,   624,   624,   624,   624,   624,
     624,   624,   624,   624,   624,   624,   -67,   -67,    58,   -90,
      58,    58,    58,    58,    49,   357,   624,   -90,   -90,   -90,
     -90,    34,   624,   624,   430,   450,   517,    44,    43,    28,
      34,    51,    34,    58,    58,    34,    57,     6,   -90,   -90,
     537,   604,   -90,    34,    58,    42,     6,    54,    60,   357,
     -90,   169,   299,   -90,   -90,   -90,    69,   299,   -90,    34,
     -90,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    85,    86,    83,    84,    87,    88,    89,    90,    91,
       0,     2,     3,     5,     0,     1,     4,     0,     0,    66,
      64,     0,     0,     0,     0,     0,     0,     0,    11,    27,
      28,    59,    62,     0,     0,     0,    66,    56,    58,     0,
       6,     0,     8,    63,    39,     0,     0,    55,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    67,    70,     0,
      24,    65,     0,     0,     0,     0,     0,    22,    23,    21,
      13,     0,    15,     0,     0,    27,    18,    19,     7,     9,
      10,    54,    53,    36,    35,    34,    33,    38,    37,    44,
      45,    46,    42,    43,    41,    40,    47,    48,    49,    29,
      30,    31,    32,    50,    51,    52,    60,    61,     0,    68,
       0,     0,     0,     0,     0,     0,    20,    12,    14,    16,
      17,     0,    26,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,     0,    74,    81,
       0,     0,    73,     0,     0,     0,    79,     0,     0,     0,
      72,     0,     0,    78,    77,    82,     0,     0,    76,     0,
      75,    80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,   -90,   119,   -90,   -27,   -89,   -90,   -90,
       7,   -21,    12,   -90,   109,   -90,   -90,   -90,   -90,   -31,
     -90,    11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    27,    42,    91,    92,    93,
      94,    29,    30,    31,    32,    79,    96,   166,   158,   167,
      97,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    38,    39,   138,    34,    44,    36,    20,    74,    75,
      35,    14,    18,    78,    80,    15,    36,    20,    99,    34,
      95,    21,    22,    14,    40,    28,    41,    17,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   100,   164,   165,    36,    20,   134,    19,
      20,    36,    20,    23,    21,    22,    21,    22,   136,    76,
      45,    95,    46,    23,    77,   137,    98,   129,    41,   130,
     131,    25,   132,   178,    26,   128,   126,   127,   180,   133,
       1,     2,     3,     4,     5,     6,     7,     8,    41,     9,
     135,   139,   147,   140,   153,   154,   155,   142,   163,   143,
     144,   145,   146,    23,   149,   157,    23,    24,    23,   174,
     172,    25,   175,   156,    25,   159,    25,    26,   162,    26,
     179,    16,   160,   161,    43,   173,   170,     0,     0,     0,
       0,     0,   148,   171,     0,     0,     0,     0,     0,     0,
       0,    95,   181,     0,     0,     0,    95,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   176,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,    70,
       0,    71,    72,    73,    19,    20,     0,   177,     0,    21,
      22,     0,     0,     0,     0,     0,    67,    68,    69,    70,
       0,    71,    72,    73,     0,     0,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,     0,     0,
       0,    82,     0,    83,    84,    85,    86,     0,    87,    88,
      89,    23,    19,    20,     0,     0,    90,    21,    22,    25,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,     0,     0,     0,    82,
       0,    83,    84,    85,    86,     0,    87,    88,    89,    23,
      19,    20,     0,     0,     0,    21,    22,    25,     0,     0,
      26,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     0,    81,    25,     0,     0,    26,     0,
      67,    68,    69,    70,     0,    71,    72,    73,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,     0,     0,     0,     0,     0,    67,    68,    69,
      70,     0,    71,    72,    73,     0,     0,     0,     0,     0,
       0,   151,     0,     0,     0,     0,     0,    67,    68,    69,
      70,     0,    71,    72,    73,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,    67,    68,    69,    70,     0,    71,
      72,    73,     0,     0,     0,     0,     0,     0,   168,     0,
       0,     0,     0,     0,    67,    68,    69,    70,     0,    71,
      72,    73,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,     0,     0,
       0,    67,    68,    69,    70,     0,    71,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,    69,    70,     0,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
      21,    22,    23,    92,    60,    26,     3,     4,    75,    76,
      66,     0,    60,    34,    35,     0,     3,     4,    45,    60,
      41,     8,     9,    12,    62,    18,    64,     3,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    46,    48,    49,     3,     4,    85,     3,
       4,     3,     4,    60,     8,     9,     8,     9,    89,     3,
      61,    92,    63,    60,    61,    65,    62,    61,    64,    63,
      60,    68,    60,   172,    71,    66,    74,    75,   177,    60,
      34,    35,    36,    37,    38,    39,    40,    41,    64,    43,
      60,    62,    53,    62,    60,    62,    78,   128,    51,   130,
     131,   132,   133,    60,   141,    64,    60,    61,    60,    65,
      78,    68,    62,   150,    68,   152,    68,    71,   155,    71,
      61,    12,   153,   154,    25,   166,   163,    -1,    -1,    -1,
      -1,    -1,   135,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   179,    -1,    -1,    -1,   177,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      -1,    72,    73,    74,     3,     4,    -1,    78,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      -1,    72,    73,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,     3,     4,    -1,    -1,    65,     8,     9,    68,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
       3,     4,    -1,    -1,    -1,     8,     9,    68,    -1,    -1,
      71,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    68,    -1,    -1,    71,    -1,
      67,    68,    69,    70,    -1,    72,    73,    74,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    72,    73,    74,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    72,
      73,    74,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    -1,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    -1,    72,    73,    74
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    35,    36,    37,    38,    39,    40,    41,    43,
      80,    81,    82,    83,   100,     0,    83,     3,    60,     3,
       4,     8,     9,    60,    61,    68,    71,    84,    89,    90,
      91,    92,    93,   100,    60,    66,     3,    90,    90,    90,
      62,    64,    85,    93,    90,    61,    63,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    67,    68,    69,
      70,    72,    73,    74,    75,    76,     3,    61,    90,    94,
      90,    61,    50,    52,    53,    54,    55,    57,    58,    59,
      65,    86,    87,    88,    89,    90,    95,    99,    62,    85,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    91,    66,    61,
      63,    60,    60,    60,    85,    60,    90,    65,    86,    62,
      62,    77,    90,    90,    90,    90,    90,    53,    89,    85,
      61,    61,    61,    60,    62,    78,    85,    64,    97,    85,
      90,    90,    85,    51,    48,    49,    96,    98,    61,    62,
      85,    90,    78,    98,    65,    62,    89,    78,    86,    61,
      86,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    79,    80,    81,    82,    82,    83,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    87,    87,
      88,    88,    88,    88,    89,    89,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    91,
      91,    91,    92,    92,    93,    93,    93,    93,    93,    94,
      94,    95,    95,    95,    95,    96,    96,    97,    98,    98,
      99,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     5,     6,     5,     6,
       3,     1,     3,     2,     2,     1,     2,     2,     1,     1,
       2,     1,     1,     1,     3,     2,     4,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     1,
       3,     3,     1,     2,     1,     3,     1,     3,     4,     3,
       1,     5,     7,     5,     5,     4,     3,     3,     2,     1,
       9,     5,     7,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* ROOT: OUTPUT  */
#line 52 "src/parser.y"
                 { g_root =  (yyvsp[0].node);}
#line 1384 "src/parser.tab.cpp"
    break;

  case 3: /* OUTPUT: HEADS  */
#line 59 "src/parser.y"
                {(yyval.node) = new Output((yyvsp[0].branch));}
#line 1390 "src/parser.tab.cpp"
    break;

  case 4: /* HEADS: HEADS HEAD  */
#line 67 "src/parser.y"
                                {(yyval.branch) = concat_list((yyvsp[0].node),(yyvsp[-1].branch));}
#line 1396 "src/parser.tab.cpp"
    break;

  case 5: /* HEADS: HEAD  */
#line 68 "src/parser.y"
                                        {(yyval.branch) = init_list((yyvsp[0].node));}
#line 1402 "src/parser.tab.cpp"
    break;

  case 6: /* HEAD: DATA_TYPES IDENTIFIER '(' ')' ';'  */
#line 74 "src/parser.y"
                                                                                {(yyval.node) = new FunctionDef((yyvsp[-4].node),(yyvsp[-3].string),NULL,NULL);}
#line 1408 "src/parser.tab.cpp"
    break;

  case 7: /* HEAD: DATA_TYPES IDENTIFIER '(' PARAMETER ')' ';'  */
#line 75 "src/parser.y"
                                                                {(yyval.node) = new FunctionDef((yyvsp[-5].node),(yyvsp[-4].string),(yyvsp[-2].branch),NULL);}
#line 1414 "src/parser.tab.cpp"
    break;

  case 8: /* HEAD: DATA_TYPES IDENTIFIER '(' ')' BLOCK  */
#line 76 "src/parser.y"
                                                                        {(yyval.node) = new FunctionDef((yyvsp[-4].node),(yyvsp[-3].string),NULL,(yyvsp[0].node));}
#line 1420 "src/parser.tab.cpp"
    break;

  case 9: /* HEAD: DATA_TYPES IDENTIFIER '(' PARAMETER ')' BLOCK  */
#line 77 "src/parser.y"
                                                                {(yyval.node) = new FunctionDef((yyvsp[-5].node),(yyvsp[-4].string),(yyvsp[-2].branch),(yyvsp[0].node));}
#line 1426 "src/parser.tab.cpp"
    break;

  case 10: /* PARAMETER: PARAMETER ',' DECLARATION  */
#line 81 "src/parser.y"
                                                {(yyval.branch) = concat_list((yyvsp[0].node),(yyvsp[-2].branch));}
#line 1432 "src/parser.tab.cpp"
    break;

  case 11: /* PARAMETER: DECLARATION  */
#line 82 "src/parser.y"
                                                        {(yyval.branch) = init_list((yyvsp[0].node));}
#line 1438 "src/parser.tab.cpp"
    break;

  case 12: /* BLOCK: '{' BODY '}'  */
#line 86 "src/parser.y"
                                        {(yyval.node) = new Block((yyvsp[-1].branch));}
#line 1444 "src/parser.tab.cpp"
    break;

  case 13: /* BLOCK: '{' '}'  */
#line 87 "src/parser.y"
                                                {(yyval.node) = NULL;}
#line 1450 "src/parser.tab.cpp"
    break;

  case 14: /* BODY: LINE BODY  */
#line 90 "src/parser.y"
                                {(yyval.branch) = concat_list((yyvsp[-1].node),(yyvsp[0].branch));}
#line 1456 "src/parser.tab.cpp"
    break;

  case 15: /* BODY: LINE  */
#line 91 "src/parser.y"
                                {(yyval.branch) = init_list((yyvsp[0].node));}
#line 1462 "src/parser.tab.cpp"
    break;

  case 16: /* LINE: STATEMENT ';'  */
#line 94 "src/parser.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1468 "src/parser.tab.cpp"
    break;

  case 17: /* LINE: DECLARATION ';'  */
#line 95 "src/parser.y"
                                {(yyval.node) = (yyvsp[-1].node);}
#line 1474 "src/parser.tab.cpp"
    break;

  case 18: /* LINE: IF_ELSE_SWITCH  */
#line 96 "src/parser.y"
                                {(yyval.node) = (yyvsp[0].node);}
#line 1480 "src/parser.tab.cpp"
    break;

  case 19: /* LINE: LOOP  */
#line 97 "src/parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1486 "src/parser.tab.cpp"
    break;

  case 20: /* STATEMENT: RETURN EXPR  */
#line 101 "src/parser.y"
                                        { (yyval.node) = new Return((yyvsp[0].node));}
#line 1492 "src/parser.tab.cpp"
    break;

  case 21: /* STATEMENT: RETURN  */
#line 102 "src/parser.y"
                                                { (yyval.node) = new Return(NULL);}
#line 1498 "src/parser.tab.cpp"
    break;

  case 22: /* STATEMENT: CONTINUE  */
#line 103 "src/parser.y"
                                                { (yyval.node) = new Continue();}
#line 1504 "src/parser.tab.cpp"
    break;

  case 23: /* STATEMENT: BREAK  */
#line 104 "src/parser.y"
                                                { (yyval.node) = new Break();}
#line 1510 "src/parser.tab.cpp"
    break;

  case 24: /* DECLARATION: IDENTIFIER '=' EXPR  */
#line 107 "src/parser.y"
                                                        {(yyval.node) = new Declaration(NULL,(new Variable(*(yyvsp[-2].string))),(yyvsp[0].node));}
#line 1516 "src/parser.tab.cpp"
    break;

  case 25: /* DECLARATION: DATA_TYPES IDENTIFIER  */
#line 108 "src/parser.y"
                                                        {(yyval.node) = new Declaration((yyvsp[-1].node),(new Variable(*(yyvsp[0].string))),NULL);}
#line 1522 "src/parser.tab.cpp"
    break;

  case 26: /* DECLARATION: DATA_TYPES IDENTIFIER '=' EXPR  */
#line 109 "src/parser.y"
                                                {(yyval.node) = new Declaration((yyvsp[-3].node),(new Variable(*(yyvsp[-2].string))),(yyvsp[0].node));}
#line 1528 "src/parser.tab.cpp"
    break;

  case 28: /* EXPR: TERM  */
#line 119 "src/parser.y"
                                        { (yyval.node) = (yyvsp[0].node); }
#line 1534 "src/parser.tab.cpp"
    break;

  case 29: /* EXPR: EXPR '+' EXPR  */
#line 121 "src/parser.y"
                                        { (yyval.node) = new AddOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1540 "src/parser.tab.cpp"
    break;

  case 30: /* EXPR: EXPR '-' EXPR  */
#line 122 "src/parser.y"
                                        { (yyval.node) = new SubOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1546 "src/parser.tab.cpp"
    break;

  case 31: /* EXPR: EXPR '>' EXPR  */
#line 123 "src/parser.y"
                                                { (yyval.node) = new GthanOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1552 "src/parser.tab.cpp"
    break;

  case 32: /* EXPR: EXPR '<' EXPR  */
#line 124 "src/parser.y"
                                                { (yyval.node) = new LthanOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1558 "src/parser.tab.cpp"
    break;

  case 33: /* EXPR: EXPR NE_OP EXPR  */
#line 125 "src/parser.y"
                                                { (yyval.node) = new NEqOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1564 "src/parser.tab.cpp"
    break;

  case 34: /* EXPR: EXPR EQ_OP EXPR  */
#line 126 "src/parser.y"
                                                { (yyval.node) = new EqOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1570 "src/parser.tab.cpp"
    break;

  case 35: /* EXPR: EXPR GE_OP EXPR  */
#line 127 "src/parser.y"
                                                { (yyval.node) = new GthanEqOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1576 "src/parser.tab.cpp"
    break;

  case 36: /* EXPR: EXPR LE_OP EXPR  */
#line 128 "src/parser.y"
                                                { (yyval.node) = new LthanEqOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1582 "src/parser.tab.cpp"
    break;

  case 37: /* EXPR: EXPR OR_OP EXPR  */
#line 129 "src/parser.y"
                                                { (yyval.node) = new OrOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1588 "src/parser.tab.cpp"
    break;

  case 38: /* EXPR: EXPR AND_OP EXPR  */
#line 130 "src/parser.y"
                                        { (yyval.node) = new AndOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1594 "src/parser.tab.cpp"
    break;

  case 39: /* EXPR: '!' EXPR  */
#line 131 "src/parser.y"
                                                        { (yyval.node) = new NotOperator((yyvsp[0].node)); }
#line 1600 "src/parser.tab.cpp"
    break;

  case 40: /* EXPR: EXPR RIGHT_ASSIGN EXPR  */
#line 132 "src/parser.y"
                                        { (yyval.node) = new RightAssignOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1606 "src/parser.tab.cpp"
    break;

  case 41: /* EXPR: EXPR LEFT_ASSIGN EXPR  */
#line 133 "src/parser.y"
                                        { (yyval.node) = new LeftAssignOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1612 "src/parser.tab.cpp"
    break;

  case 42: /* EXPR: EXPR ADD_ASSIGN EXPR  */
#line 134 "src/parser.y"
                                        { (yyval.node) = new AddAssignOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1618 "src/parser.tab.cpp"
    break;

  case 43: /* EXPR: EXPR SUB_ASSIGN EXPR  */
#line 135 "src/parser.y"
                                        { (yyval.node) = new SubAssignOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1624 "src/parser.tab.cpp"
    break;

  case 44: /* EXPR: EXPR MUL_ASSIGN EXPR  */
#line 136 "src/parser.y"
                                        { (yyval.node) = new MulAssignOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1630 "src/parser.tab.cpp"
    break;

  case 45: /* EXPR: EXPR DIV_ASSIGN EXPR  */
#line 137 "src/parser.y"
                                        { (yyval.node) = new DivAssignOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1636 "src/parser.tab.cpp"
    break;

  case 46: /* EXPR: EXPR MOD_ASSIGN EXPR  */
#line 138 "src/parser.y"
                                        { (yyval.node) = new ModAssignOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1642 "src/parser.tab.cpp"
    break;

  case 47: /* EXPR: EXPR AND_ASSIGN EXPR  */
#line 139 "src/parser.y"
                                        { (yyval.node) = new AndAssignOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1648 "src/parser.tab.cpp"
    break;

  case 48: /* EXPR: EXPR XOR_ASSIGN EXPR  */
#line 140 "src/parser.y"
                                        { (yyval.node) = new XorAssignOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1654 "src/parser.tab.cpp"
    break;

  case 49: /* EXPR: EXPR OR_ASSIGN EXPR  */
#line 141 "src/parser.y"
                                        { (yyval.node) = new OrAssignOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1660 "src/parser.tab.cpp"
    break;

  case 50: /* EXPR: EXPR '&' EXPR  */
#line 142 "src/parser.y"
                                                { (yyval.node) = new AndBitwiseOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1666 "src/parser.tab.cpp"
    break;

  case 51: /* EXPR: EXPR '|' EXPR  */
#line 143 "src/parser.y"
                                                { (yyval.node) = new OrBitwiseOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1672 "src/parser.tab.cpp"
    break;

  case 52: /* EXPR: EXPR '^' EXPR  */
#line 144 "src/parser.y"
                                                { (yyval.node) = new XorBitwiseOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1678 "src/parser.tab.cpp"
    break;

  case 53: /* EXPR: EXPR RIGHT_OP EXPR  */
#line 146 "src/parser.y"
                                        { (yyval.node) = new RightShiftOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1684 "src/parser.tab.cpp"
    break;

  case 54: /* EXPR: EXPR LEFT_OP EXPR  */
#line 147 "src/parser.y"
                                        { (yyval.node) = new LeftShiftOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1690 "src/parser.tab.cpp"
    break;

  case 55: /* EXPR: EXPR INC_OP  */
#line 148 "src/parser.y"
                                                { (yyval.node) = new IncOperator_Post((yyvsp[-1].node)); }
#line 1696 "src/parser.tab.cpp"
    break;

  case 56: /* EXPR: INC_OP EXPR  */
#line 149 "src/parser.y"
                                                { (yyval.node) = new IncOperator_Pre((yyvsp[0].node)); }
#line 1702 "src/parser.tab.cpp"
    break;

  case 57: /* EXPR: EXPR DEC_OP  */
#line 150 "src/parser.y"
                                                { (yyval.node) = new DecOperator_Post((yyvsp[-1].node)); }
#line 1708 "src/parser.tab.cpp"
    break;

  case 58: /* EXPR: DEC_OP EXPR  */
#line 151 "src/parser.y"
                                                { (yyval.node) = new DecOperator_Pre((yyvsp[0].node)); }
#line 1714 "src/parser.tab.cpp"
    break;

  case 59: /* TERM: UNARY  */
#line 154 "src/parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1720 "src/parser.tab.cpp"
    break;

  case 60: /* TERM: TERM '*' TERM  */
#line 155 "src/parser.y"
                        { (yyval.node) = new MulOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1726 "src/parser.tab.cpp"
    break;

  case 61: /* TERM: TERM '/' TERM  */
#line 156 "src/parser.y"
                        { (yyval.node) = new DivOperator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1732 "src/parser.tab.cpp"
    break;

  case 62: /* UNARY: FACTOR  */
#line 160 "src/parser.y"
                                        { (yyval.node) = (yyvsp[0].node); }
#line 1738 "src/parser.tab.cpp"
    break;

  case 63: /* UNARY: '-' FACTOR  */
#line 161 "src/parser.y"
                                { (yyval.node) = new NegOperator((yyvsp[0].node)); }
#line 1744 "src/parser.tab.cpp"
    break;

  case 64: /* FACTOR: CONSTANT  */
#line 165 "src/parser.y"
                                                        {(yyval.node) = new Number( (yyvsp[0].number) );}
#line 1750 "src/parser.tab.cpp"
    break;

  case 65: /* FACTOR: '(' EXPR ')'  */
#line 166 "src/parser.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1756 "src/parser.tab.cpp"
    break;

  case 66: /* FACTOR: IDENTIFIER  */
#line 167 "src/parser.y"
                                                        {(yyval.node) = new Variable( *(yyvsp[0].string) );}
#line 1762 "src/parser.tab.cpp"
    break;

  case 67: /* FACTOR: IDENTIFIER '(' ')'  */
#line 168 "src/parser.y"
                                                {(yyval.node) = new FunctionCall((yyvsp[-2].string),NULL);}
#line 1768 "src/parser.tab.cpp"
    break;

  case 68: /* FACTOR: IDENTIFIER '(' ARGUMENTS ')'  */
#line 169 "src/parser.y"
                                        {(yyval.node) = new FunctionCall((yyvsp[-3].string),(yyvsp[-1].branch));}
#line 1774 "src/parser.tab.cpp"
    break;

  case 69: /* ARGUMENTS: ARGUMENTS ',' EXPR  */
#line 172 "src/parser.y"
                                                {(yyval.branch) = concat_list((yyvsp[0].node),(yyvsp[-2].branch));}
#line 1780 "src/parser.tab.cpp"
    break;

  case 70: /* ARGUMENTS: EXPR  */
#line 173 "src/parser.y"
                                                                {(yyval.branch) = init_list((yyvsp[0].node));}
#line 1786 "src/parser.tab.cpp"
    break;

  case 71: /* IF_ELSE_SWITCH: IF '(' EXPR ')' BLOCK  */
#line 182 "src/parser.y"
                                                        {(yyval.node) = new ifelse((yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1792 "src/parser.tab.cpp"
    break;

  case 72: /* IF_ELSE_SWITCH: IF '(' EXPR ')' BLOCK ELSE BLOCK  */
#line 183 "src/parser.y"
                                                {(yyval.node) = new ifelse((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1798 "src/parser.tab.cpp"
    break;

  case 73: /* IF_ELSE_SWITCH: EXPR '?' BLOCK ':' BLOCK  */
#line 184 "src/parser.y"
                                                        {(yyval.node) = new ifelse((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1804 "src/parser.tab.cpp"
    break;

  case 74: /* IF_ELSE_SWITCH: SWITCH '(' EXPR ')' SWITCH_BLOCK  */
#line 185 "src/parser.y"
                                                        {(yyval.node) = new switch_statement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1810 "src/parser.tab.cpp"
    break;

  case 75: /* CASES: CASE EXPR ':' BODY  */
#line 188 "src/parser.y"
                                                { (yyval.node) = new case_statement((yyvsp[-2].node), (yyvsp[0].branch)); }
#line 1816 "src/parser.tab.cpp"
    break;

  case 76: /* CASES: DEFAULT ':' BODY  */
#line 189 "src/parser.y"
                                                        { (yyval.node) = new default_statement((yyvsp[0].branch)); }
#line 1822 "src/parser.tab.cpp"
    break;

  case 77: /* SWITCH_BLOCK: '{' SWITCH_BODY '}'  */
#line 192 "src/parser.y"
                                    {(yyval.node) = new Block((yyvsp[-1].branch));}
#line 1828 "src/parser.tab.cpp"
    break;

  case 78: /* SWITCH_BODY: CASES SWITCH_BODY  */
#line 196 "src/parser.y"
                                                    {(yyval.branch) = concat_list((yyvsp[-1].node),(yyvsp[0].branch));}
#line 1834 "src/parser.tab.cpp"
    break;

  case 79: /* SWITCH_BODY: CASES  */
#line 197 "src/parser.y"
                                                                {(yyval.branch) = init_list((yyvsp[0].node));}
#line 1840 "src/parser.tab.cpp"
    break;

  case 80: /* LOOP: FOR '(' DECLARATION ';' EXPR ';' DECLARATION ')' BLOCK  */
#line 204 "src/parser.y"
                                                                        {(yyval.node) = new forloop((yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1846 "src/parser.tab.cpp"
    break;

  case 81: /* LOOP: WHILE '(' EXPR ')' BLOCK  */
#line 205 "src/parser.y"
                                                                                                        {(yyval.node) = new whileloop((yyvsp[-2].node),(yyvsp[0].node));}
#line 1852 "src/parser.tab.cpp"
    break;

  case 83: /* DATA_TYPES: INT  */
#line 216 "src/parser.y"
                        {(yyval.node) = new Type(_Types::_int);}
#line 1858 "src/parser.tab.cpp"
    break;

  case 84: /* DATA_TYPES: LONG  */
#line 217 "src/parser.y"
                        {(yyval.node) = new Type(_Types::_long);}
#line 1864 "src/parser.tab.cpp"
    break;

  case 85: /* DATA_TYPES: CHAR  */
#line 218 "src/parser.y"
                        {(yyval.node) = new Type(_Types::_char);}
#line 1870 "src/parser.tab.cpp"
    break;

  case 86: /* DATA_TYPES: SHORT  */
#line 219 "src/parser.y"
                        {(yyval.node) = new Type(_Types::_short);}
#line 1876 "src/parser.tab.cpp"
    break;

  case 87: /* DATA_TYPES: SIGNED  */
#line 220 "src/parser.y"
                        {(yyval.node) = new Type(_Types::_signed);}
#line 1882 "src/parser.tab.cpp"
    break;

  case 88: /* DATA_TYPES: UNSIGNED  */
#line 221 "src/parser.y"
                        {(yyval.node) = new Type(_Types::_unsigned);}
#line 1888 "src/parser.tab.cpp"
    break;

  case 89: /* DATA_TYPES: FLOAT  */
#line 222 "src/parser.y"
                        {(yyval.node) = new Type(_Types::_float);}
#line 1894 "src/parser.tab.cpp"
    break;

  case 90: /* DATA_TYPES: DOUBLE  */
#line 223 "src/parser.y"
                        {(yyval.node) = new Type(_Types::_double);}
#line 1900 "src/parser.tab.cpp"
    break;

  case 91: /* DATA_TYPES: VOID  */
#line 224 "src/parser.y"
                        {(yyval.node) = new Type(_Types::_void);}
#line 1906 "src/parser.tab.cpp"
    break;


#line 1910 "src/parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 227 "src/parser.y"



const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST(std::string filename){
  yyin = fopen(filename.c_str(), "r");
  if(yyin == NULL){
    std::cerr << "Couldn't open input file: " << filename << std::endl;
    exit(1);
  }
  g_root = NULL;
  yyparse();
  return g_root;
}

