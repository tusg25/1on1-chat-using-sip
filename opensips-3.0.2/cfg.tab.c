/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 79 "cfg.y"


#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include "route_struct.h"
#include "globals.h"
#include "route.h"
#include "dprint.h"
#include "cfg_pp.h"
#include "sr_module.h"
#include "modparam.h"
#include "ip_addr.h"
#include "resolve.h"
#include "socket_info.h"
#include "name_alias.h"
#include "ut.h"
#include "pt_scaling.h"
#include "dset.h"
#include "pvar.h"
#include "blacklists.h"
#include "xlog.h"
#include "db/db_insertq.h"
#include "bin_interface.h"
#include "net/trans.h"
#include "config.h"
#include "mem/rpm_mem.h"

#ifdef SHM_EXTRA_STATS
#include "mem/module_info.h"
#endif

#ifdef DEBUG_DMALLOC
#include <dmalloc.h>
#endif

/* hack to avoid alloca usage in the generated C file (needed for compiler
 with no built in alloca, like icc*/
#undef _ALLOCA_H

#undef MIN
#undef MAX

extern int yylex();
static void yyerror(char* s);
static void yyerrorf(char* fmt, ...);
static char* tmp;
static int i_tmp, rc;
static void* cmd_tmp;
static struct socket_id* lst_tmp;
static int rt;  /* Type of route block for find_export */
static str s_tmp;
static str tstr;
static struct net* net_tmp;
static pv_spec_t *spec;
static pv_elem_t *pvmodel;
static struct bl_rule *bl_head = 0;
static struct bl_rule *bl_tail = 0;

action_elem_t elems[MAX_ACTION_ELEMS];
static action_elem_t route_elems[MAX_ACTION_ELEMS];
action_elem_t *a_tmp;

static inline void warn(char* s);
static struct socket_id* mk_listen_id(char*, enum sip_protos, int);
static struct socket_id* set_listen_id_adv(struct socket_id *, char *, int);
static struct multi_str *new_string(char *s);
static int parse_ipnet(char *in, int len, struct net **ipnet);

extern int line;
extern int column;
extern int startcolumn;
extern char *finame;

struct listen_param {
	enum si_flags flags;
	int workers;
	struct socket_id *socket;
	char *tag;
	char *auto_scaling_profile;
} p_tmp;
static void fill_socket_id(struct listen_param *param, struct socket_id *s);

#ifndef SHM_EXTRA_STATS
struct multi_str{
	char *s;
	struct multi_str* next;
};
#else 
static struct multi_str *tmp_mod;
#endif

#define get_cfg_file_name \
	((finame) ? finame : cfg_file ? cfg_file : "default")



#define mk_action_(_res, _type, _no, _elems) \
	do { \
		_res = mk_action(_type, _no, _elems, line, get_cfg_file_name); \
	} while(0)
#define mk_action0(_res, _type, _p1_type, _p2_type, _p1, _p2) \
	do { \
		_res = mk_action(_type, 0, 0, line, get_cfg_file_name); \
	} while(0)
#define mk_action1(_res, _type, _p1_type, _p1) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		_res = mk_action(_type, 1, elems, line, get_cfg_file_name); \
	} while(0)
#define	mk_action2(_res, _type, _p1_type, _p2_type, _p1, _p2) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		elems[1].type = _p2_type; \
		elems[1].u.data = _p2; \
		_res = mk_action(_type, 2, elems, line, get_cfg_file_name); \
	} while(0)
#define mk_action3(_res, _type, _p1_type, _p2_type, _p3_type, _p1, _p2, _p3) \
	do { \
		elems[0].type = _p1_type; \
		elems[0].u.data = _p1; \
		elems[1].type = _p2_type; \
		elems[1].u.data = _p2; \
		elems[2].type = _p3_type; \
		elems[2].u.data = _p3; \
		_res = mk_action(_type, 3, elems, line, get_cfg_file_name); \
	} while(0)

extern int cfg_parse_only_routes;
#define IFOR(_instr) \
	if (cfg_parse_only_routes==1) {_instr;break;}


#line 213 "cfg.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_CFG_TAB_H_INCLUDED
# define YY_YY_CFG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FORWARD = 258,
    SEND = 259,
    DROP = 260,
    ASSERT = 261,
    EXIT = 262,
    RETURN = 263,
    LOG_TOK = 264,
    ERROR = 265,
    ROUTE = 266,
    ROUTE_FAILURE = 267,
    ROUTE_ONREPLY = 268,
    ROUTE_BRANCH = 269,
    ROUTE_ERROR = 270,
    ROUTE_LOCAL = 271,
    ROUTE_STARTUP = 272,
    ROUTE_TIMER = 273,
    ROUTE_EVENT = 274,
    SET_HOST = 275,
    SET_HOSTPORT = 276,
    PREFIX = 277,
    STRIP = 278,
    STRIP_TAIL = 279,
    APPEND_BRANCH = 280,
    REMOVE_BRANCH = 281,
    PV_PRINTF = 282,
    SET_USER = 283,
    SET_USERPASS = 284,
    SET_PORT = 285,
    SET_URI = 286,
    REVERT_URI = 287,
    SET_DSTURI = 288,
    RESET_DSTURI = 289,
    ISDSTURISET = 290,
    FORCE_RPORT = 291,
    FORCE_LOCAL_RPORT = 292,
    FORCE_TCP_ALIAS = 293,
    IF = 294,
    ELSE = 295,
    SWITCH = 296,
    CASE = 297,
    DEFAULT = 298,
    SBREAK = 299,
    WHILE = 300,
    FOR = 301,
    IN = 302,
    SET_ADV_ADDRESS = 303,
    SET_ADV_PORT = 304,
    FORCE_SEND_SOCKET = 305,
    SERIALIZE_BRANCHES = 306,
    NEXT_BRANCHES = 307,
    USE_BLACKLIST = 308,
    UNUSE_BLACKLIST = 309,
    SETFLAG = 310,
    RESETFLAG = 311,
    ISFLAGSET = 312,
    SETBFLAG = 313,
    RESETBFLAG = 314,
    ISBFLAGSET = 315,
    METHOD = 316,
    PROTO = 317,
    AF = 318,
    IS_MYSELF = 319,
    MSGLEN = 320,
    NULLV = 321,
    CACHE_STORE = 322,
    CACHE_FETCH = 323,
    CACHE_COUNTER_FETCH = 324,
    CACHE_REMOVE = 325,
    CACHE_ADD = 326,
    CACHE_SUB = 327,
    CACHE_RAW_QUERY = 328,
    XDBG = 329,
    XLOG = 330,
    XLOG_BUF_SIZE = 331,
    XLOG_FORCE_COLOR = 332,
    XLOG_PRINT_LEVEL = 333,
    XLOG_LEVEL = 334,
    PV_PRINT_BUF_SIZE = 335,
    RAISE_EVENT = 336,
    SUBSCRIBE_EVENT = 337,
    CONSTRUCT_URI = 338,
    GET_TIMESTAMP = 339,
    SCRIPT_TRACE = 340,
    FORK = 341,
    DEBUG_MODE = 342,
    DEBUG = 343,
    ENABLE_ASSERTS = 344,
    ABORT_ON_ASSERT = 345,
    LOGLEVEL = 346,
    LOGSTDERROR = 347,
    LOGFACILITY = 348,
    LOGNAME = 349,
    AVP_ALIASES = 350,
    LISTEN = 351,
    MEMGROUP = 352,
    ALIAS = 353,
    AUTO_ALIASES = 354,
    TAG = 355,
    DNS = 356,
    REV_DNS = 357,
    DNS_TRY_IPV6 = 358,
    DNS_TRY_NAPTR = 359,
    DNS_RETR_TIME = 360,
    DNS_RETR_NO = 361,
    DNS_SERVERS_NO = 362,
    DNS_USE_SEARCH = 363,
    MAX_WHILE_LOOPS = 364,
    CHILDREN = 365,
    UDP_WORKERS = 366,
    CHECK_VIA = 367,
    SHM_HASH_SPLIT_PERCENTAGE = 368,
    SHM_SECONDARY_HASH_SIZE = 369,
    MEM_WARMING_ENABLED = 370,
    MEM_WARMING_PATTERN_FILE = 371,
    MEM_WARMING_PERCENTAGE = 372,
    RPM_MEM_FILE = 373,
    RPM_MEM_SIZE = 374,
    MEMLOG = 375,
    MEMDUMP = 376,
    EXECMSGTHRESHOLD = 377,
    EXECDNSTHRESHOLD = 378,
    TCPTHRESHOLD = 379,
    EVENT_SHM_THRESHOLD = 380,
    EVENT_PKG_THRESHOLD = 381,
    QUERYBUFFERSIZE = 382,
    QUERYFLUSHTIME = 383,
    SIP_WARNING = 384,
    SERVER_SIGNATURE = 385,
    SERVER_HEADER = 386,
    USER_AGENT_HEADER = 387,
    LOADMODULE = 388,
    MPATH = 389,
    MODPARAM = 390,
    MAXBUFFER = 391,
    CHROOT = 392,
    WDIR = 393,
    MHOMED = 394,
    POLL_METHOD = 395,
    TCP_ACCEPT_ALIASES = 396,
    TCP_CHILDREN = 397,
    TCP_WORKERS = 398,
    TCP_CONNECT_TIMEOUT = 399,
    TCP_CON_LIFETIME = 400,
    TCP_LISTEN_BACKLOG = 401,
    TCP_MAX_CONNECTIONS = 402,
    TCP_NO_NEW_CONN_BFLAG = 403,
    TCP_NO_NEW_CONN_RPLFLAG = 404,
    TCP_KEEPALIVE = 405,
    TCP_KEEPCOUNT = 406,
    TCP_KEEPIDLE = 407,
    TCP_KEEPINTERVAL = 408,
    TCP_MAX_MSG_TIME = 409,
    ADVERTISED_ADDRESS = 410,
    ADVERTISED_PORT = 411,
    DISABLE_CORE = 412,
    OPEN_FD_LIMIT = 413,
    MCAST_LOOPBACK = 414,
    MCAST_TTL = 415,
    TOS = 416,
    DISABLE_DNS_FAILOVER = 417,
    DISABLE_DNS_BLACKLIST = 418,
    DST_BLACKLIST = 419,
    DISABLE_STATELESS_FWD = 420,
    DB_VERSION_TABLE = 421,
    DB_DEFAULT_URL = 422,
    DB_MAX_ASYNC_CONNECTIONS = 423,
    DISABLE_503_TRANSLATION = 424,
    SYNC_TOKEN = 425,
    ASYNC_TOKEN = 426,
    LAUNCH_TOKEN = 427,
    AUTO_SCALING_PROFILE = 428,
    AUTO_SCALING_CYCLE = 429,
    TIMER_WORKERS = 430,
    EQUAL = 431,
    EQUAL_T = 432,
    GT = 433,
    LT = 434,
    GTE = 435,
    LTE = 436,
    DIFF = 437,
    MATCH = 438,
    NOTMATCH = 439,
    COLONEQ = 440,
    PLUSEQ = 441,
    MINUSEQ = 442,
    SLASHEQ = 443,
    MULTEQ = 444,
    MODULOEQ = 445,
    BANDEQ = 446,
    BOREQ = 447,
    BXOREQ = 448,
    OR = 449,
    AND = 450,
    BOR = 451,
    BAND = 452,
    BXOR = 453,
    BLSHIFT = 454,
    BRSHIFT = 455,
    PLUS = 456,
    MINUS = 457,
    SLASH = 458,
    MULT = 459,
    MODULO = 460,
    NOT = 461,
    BNOT = 462,
    NUMBER = 463,
    ZERO = 464,
    ID = 465,
    STRING = 466,
    SCRIPTVAR = 467,
    IPV6ADDR = 468,
    IPV4ADDR = 469,
    IPNET = 470,
    COMMA = 471,
    SEMICOLON = 472,
    RPAREN = 473,
    LPAREN = 474,
    LBRACE = 475,
    RBRACE = 476,
    LBRACK = 477,
    RBRACK = 478,
    AS = 479,
    USE_CHILDREN = 480,
    USE_WORKERS = 481,
    USE_AUTO_SCALING_PROFILE = 482,
    MAX = 483,
    MIN = 484,
    DOT = 485,
    CR = 486,
    COLON = 487,
    ANY = 488,
    ANYCAST = 489,
    SCRIPTVARERR = 490,
    SCALE_UP_TO = 491,
    SCALE_DOWN_TO = 492,
    ON = 493,
    CYCLES = 494,
    CYCLES_WITHIN = 495,
    PERCENTAGE = 496
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 223 "cfg.y"

	long intval;
	unsigned long uval;
	char* strval;
	struct expr* expr;
	struct action* action;
	struct net* ipnet;
	struct ip_addr* ipaddr;
	struct socket_id* sockid;
	struct listen_param* listen_param;
	struct _pv_spec *specval;
	struct multi_str* multistr;

#line 521 "cfg.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CFG_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  208
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4901

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  242
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  589
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1261

#define YYUNDEFTOK  2
#define YYMAXUTOK   496


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   521,   521,   524,   525,   526,   529,   530,   531,   531,
     532,   532,   533,   533,   534,   534,   535,   535,   536,   536,
     537,   537,   538,   538,   539,   539,   541,   544,   559,   568,
     583,   584,   587,   588,   602,   607,   617,   618,   621,   622,
     623,   627,   629,   631,   636,   642,   644,   648,   650,   652,
     654,   658,   661,   662,   665,   667,   669,   675,   678,   683,
     686,   689,   692,   697,   698,   701,   702,   704,   704,   709,
     709,   716,   717,   719,   720,   723,   731,   742,   743,   744,
     748,   756,   764,   770,   778,   780,   782,   786,   787,   788,
     789,   790,   794,   796,   800,   801,   807,   808,   809,   810,
     811,   812,   813,   814,   815,   816,   817,   818,   819,   820,
     821,   822,   823,   824,   825,   826,   827,   828,   829,   830,
     834,   835,   836,   840,   841,   844,   848,   849,   850,   858,
     866,   874,   882,   890,   898,   906,   914,   922,   930,   933,
     934,   937,   938,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   948,   958,   959,   973,   974,   975,   976,   977,
     978,   979,   980,   981,   982,   983,   984,   985,   986,   987,
     988,   998,  1008,  1009,  1012,  1013,  1018,  1019,  1022,  1026,
    1027,  1030,  1031,  1034,  1035,  1038,  1039,  1042,  1043,  1052,
    1059,  1060,  1067,  1069,  1072,  1073,  1076,  1077,  1084,  1085,
    1092,  1093,  1100,  1101,  1103,  1104,  1108,  1109,  1112,  1113,
    1115,  1116,  1118,  1120,  1122,  1123,  1124,  1125,  1127,  1128,
    1135,  1138,  1182,  1183,  1188,  1190,  1192,  1193,  1199,  1201,
    1215,  1217,  1220,  1221,  1224,  1225,  1232,  1233,  1240,  1241,
    1245,  1273,  1274,  1276,  1277,  1280,  1281,  1284,  1285,  1295,
    1297,  1299,  1300,  1302,  1303,  1305,  1308,  1310,  1313,  1314,
    1317,  1319,  1322,  1325,  1329,  1330,  1336,  1342,  1346,  1347,
    1350,  1366,  1382,  1383,  1386,  1392,  1402,  1412,  1423,  1426,
    1435,  1440,  1448,  1464,  1467,  1473,  1476,  1484,  1490,  1493,
    1499,  1502,  1510,  1513,  1521,  1524,  1532,  1535,  1547,  1550,
    1556,  1561,  1562,  1563,  1564,  1565,  1566,  1569,  1570,  1573,
    1574,  1575,  1576,  1578,  1579,  1582,  1583,  1586,  1587,  1588,
    1591,  1607,  1612,  1613,  1614,  1616,  1621,  1624,  1627,  1630,
    1633,  1639,  1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,
    1648,  1652,  1653,  1654,  1655,  1656,  1657,  1660,  1663,  1666,
    1669,  1672,  1675,  1678,  1681,  1684,  1687,  1690,  1693,  1706,
    1719,  1741,  1742,  1743,  1744,  1745,  1748,  1749,  1750,  1753,
    1754,  1755,  1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,
    1768,  1776,  1786,  1794,  1812,  1821,  1822,  1824,  1825,  1828,
    1837,  1846,  1854,  1862,  1871,  1880,  1888,  1899,  1905,  1913,
    1918,  1928,  1935,  1942,  1952,  1957,  1964,  1974,  1979,  1986,
    1998,  2003,  2008,  2013,  2018,  2028,  2038,  2048,  2060,  2078,
    2109,  2113,  2119,  2125,  2132,  2133,  2136,  2142,  2148,  2149,
    2151,  2154,  2155,  2156,  2157,  2158,  2164,  2170,  2176,  2182,
    2185,  2191,  2192,  2194,  2197,  2199,  2200,  2202,  2204,  2205,
    2207,  2209,  2210,  2214,  2218,  2221,  2224,  2225,  2229,  2233,
    2237,  2241,  2242,  2246,  2250,  2254,  2258,  2259,  2265,  2266,
    2268,  2276,  2298,  2299,  2301,  2303,  2304,  2307,  2309,  2310,
    2312,  2314,  2315,  2318,  2320,  2321,  2323,  2336,  2338,  2340,
    2342,  2344,  2346,  2369,  2384,  2386,  2387,  2389,  2391,  2392,
    2394,  2396,  2397,  2399,  2401,  2402,  2404,  2406,  2407,  2409,
    2410,  2411,  2413,  2414,  2416,  2418,  2419,  2420,  2421,  2423,
    2424,  2426,  2428,  2432,  2435,  2438,  2441,  2445,  2447,  2448,
    2461,  2466,  2468,  2469,  2473,  2476,  2477,  2481,  2486,  2489,
    2490,  2493,  2496,  2497,  2501,  2504,  2505,  2509,  2512,  2513,
    2522,  2534,  2547,  2554,  2563,  2572,  2583,  2594,  2607,  2620,
    2631,  2642,  2655,  2668,  2677,  2684,  2707,  2743,  2745,  2748,
    2750,  2752,  2754,  2756,  2758,  2760,  2762,  2764,  2767,  2769,
    2772,  2786,  2792,  2794,  2802,  2810,  2816,  2822,  2826,  2829
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FORWARD", "SEND", "DROP", "ASSERT",
  "EXIT", "RETURN", "LOG_TOK", "ERROR", "ROUTE", "ROUTE_FAILURE",
  "ROUTE_ONREPLY", "ROUTE_BRANCH", "ROUTE_ERROR", "ROUTE_LOCAL",
  "ROUTE_STARTUP", "ROUTE_TIMER", "ROUTE_EVENT", "SET_HOST",
  "SET_HOSTPORT", "PREFIX", "STRIP", "STRIP_TAIL", "APPEND_BRANCH",
  "REMOVE_BRANCH", "PV_PRINTF", "SET_USER", "SET_USERPASS", "SET_PORT",
  "SET_URI", "REVERT_URI", "SET_DSTURI", "RESET_DSTURI", "ISDSTURISET",
  "FORCE_RPORT", "FORCE_LOCAL_RPORT", "FORCE_TCP_ALIAS", "IF", "ELSE",
  "SWITCH", "CASE", "DEFAULT", "SBREAK", "WHILE", "FOR", "IN",
  "SET_ADV_ADDRESS", "SET_ADV_PORT", "FORCE_SEND_SOCKET",
  "SERIALIZE_BRANCHES", "NEXT_BRANCHES", "USE_BLACKLIST",
  "UNUSE_BLACKLIST", "SETFLAG", "RESETFLAG", "ISFLAGSET", "SETBFLAG",
  "RESETBFLAG", "ISBFLAGSET", "METHOD", "PROTO", "AF", "IS_MYSELF",
  "MSGLEN", "NULLV", "CACHE_STORE", "CACHE_FETCH", "CACHE_COUNTER_FETCH",
  "CACHE_REMOVE", "CACHE_ADD", "CACHE_SUB", "CACHE_RAW_QUERY", "XDBG",
  "XLOG", "XLOG_BUF_SIZE", "XLOG_FORCE_COLOR", "XLOG_PRINT_LEVEL",
  "XLOG_LEVEL", "PV_PRINT_BUF_SIZE", "RAISE_EVENT", "SUBSCRIBE_EVENT",
  "CONSTRUCT_URI", "GET_TIMESTAMP", "SCRIPT_TRACE", "FORK", "DEBUG_MODE",
  "DEBUG", "ENABLE_ASSERTS", "ABORT_ON_ASSERT", "LOGLEVEL", "LOGSTDERROR",
  "LOGFACILITY", "LOGNAME", "AVP_ALIASES", "LISTEN", "MEMGROUP", "ALIAS",
  "AUTO_ALIASES", "TAG", "DNS", "REV_DNS", "DNS_TRY_IPV6", "DNS_TRY_NAPTR",
  "DNS_RETR_TIME", "DNS_RETR_NO", "DNS_SERVERS_NO", "DNS_USE_SEARCH",
  "MAX_WHILE_LOOPS", "CHILDREN", "UDP_WORKERS", "CHECK_VIA",
  "SHM_HASH_SPLIT_PERCENTAGE", "SHM_SECONDARY_HASH_SIZE",
  "MEM_WARMING_ENABLED", "MEM_WARMING_PATTERN_FILE",
  "MEM_WARMING_PERCENTAGE", "RPM_MEM_FILE", "RPM_MEM_SIZE", "MEMLOG",
  "MEMDUMP", "EXECMSGTHRESHOLD", "EXECDNSTHRESHOLD", "TCPTHRESHOLD",
  "EVENT_SHM_THRESHOLD", "EVENT_PKG_THRESHOLD", "QUERYBUFFERSIZE",
  "QUERYFLUSHTIME", "SIP_WARNING", "SERVER_SIGNATURE", "SERVER_HEADER",
  "USER_AGENT_HEADER", "LOADMODULE", "MPATH", "MODPARAM", "MAXBUFFER",
  "CHROOT", "WDIR", "MHOMED", "POLL_METHOD", "TCP_ACCEPT_ALIASES",
  "TCP_CHILDREN", "TCP_WORKERS", "TCP_CONNECT_TIMEOUT", "TCP_CON_LIFETIME",
  "TCP_LISTEN_BACKLOG", "TCP_MAX_CONNECTIONS", "TCP_NO_NEW_CONN_BFLAG",
  "TCP_NO_NEW_CONN_RPLFLAG", "TCP_KEEPALIVE", "TCP_KEEPCOUNT",
  "TCP_KEEPIDLE", "TCP_KEEPINTERVAL", "TCP_MAX_MSG_TIME",
  "ADVERTISED_ADDRESS", "ADVERTISED_PORT", "DISABLE_CORE", "OPEN_FD_LIMIT",
  "MCAST_LOOPBACK", "MCAST_TTL", "TOS", "DISABLE_DNS_FAILOVER",
  "DISABLE_DNS_BLACKLIST", "DST_BLACKLIST", "DISABLE_STATELESS_FWD",
  "DB_VERSION_TABLE", "DB_DEFAULT_URL", "DB_MAX_ASYNC_CONNECTIONS",
  "DISABLE_503_TRANSLATION", "SYNC_TOKEN", "ASYNC_TOKEN", "LAUNCH_TOKEN",
  "AUTO_SCALING_PROFILE", "AUTO_SCALING_CYCLE", "TIMER_WORKERS", "EQUAL",
  "EQUAL_T", "GT", "LT", "GTE", "LTE", "DIFF", "MATCH", "NOTMATCH",
  "COLONEQ", "PLUSEQ", "MINUSEQ", "SLASHEQ", "MULTEQ", "MODULOEQ",
  "BANDEQ", "BOREQ", "BXOREQ", "OR", "AND", "BOR", "BAND", "BXOR",
  "BLSHIFT", "BRSHIFT", "PLUS", "MINUS", "SLASH", "MULT", "MODULO", "NOT",
  "BNOT", "NUMBER", "ZERO", "ID", "STRING", "SCRIPTVAR", "IPV6ADDR",
  "IPV4ADDR", "IPNET", "COMMA", "SEMICOLON", "RPAREN", "LPAREN", "LBRACE",
  "RBRACE", "LBRACK", "RBRACK", "AS", "USE_CHILDREN", "USE_WORKERS",
  "USE_AUTO_SCALING_PROFILE", "MAX", "MIN", "DOT", "CR", "COLON", "ANY",
  "ANYCAST", "SCRIPTVARERR", "SCALE_UP_TO", "SCALE_DOWN_TO", "ON",
  "CYCLES", "CYCLES_WITHIN", "PERCENTAGE", "$accept", "cfg", "statements",
  "statement", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", "listen_id", "host_sep", "host", "proto", "port", "snumber",
  "phostport", "panyhostport", "alias_def", "id_lst", "listen_id_def",
  "listen_def_param", "listen_def_params", "listen_def", "$@10", "$@11",
  "any_proto", "multi_string", "blst_elem", "blst_elem_list",
  "auto_scale_profile_def", "assign_stm", "module_stm", "ip", "ipv4",
  "ipv6addr", "ipv6", "ipnet", "folded_string", "route_name", "route_stm",
  "failure_route_stm", "onreply_route_stm", "branch_route_stm",
  "error_route_stm", "local_route_stm", "startup_route_stm",
  "timer_route_stm", "event_route_stm", "exp", "equalop", "compop",
  "matchop", "intop", "strop", "script_var", "exp_elem", "exp_cond",
  "assignop", "assignexp", "assign_cmd", "exp_stm", "stm", "actions",
  "action", "if_cmd", "while_cmd", "foreach_cmd", "switch_cmd",
  "switch_stm", "case_stms", "case_stm", "default_stm",
  "module_func_param", "route_param", "async_func", "cmd", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496
};
# endif

#define YYPACT_NINF (-984)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-398)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    4670,  -104,   -83,   -52,   -22,   -16,   -12,     6,    32,    41,
     298,   301,   359,   377,   393,   425,   450,   478,   533,   559,
     561,   563,    48,    62,    63,    73,   435,   436,   570,   584,
     618,   633,   637,   651,   665,   675,   676,   680,   681,   688,
     697,   703,   721,   725,   726,   727,   728,   729,   730,   782,
     785,   786,   170,   787,    21,   789,   790,   791,   802,   803,
     804,   816,   818,   819,   820,   821,   823,   844,   851,   865,
     866,   867,   869,   870,   880,   881,   882,   883,   884,   891,
     901,   472,   491,   902,   903,   904,   905,   906,   907,   908,
     929,   931,  -984,   213,  4501,  -984,   207,   211,   597,   650,
     657,   669,   795,   679,   815,  -984,  -984,  -984,   174,   221,
     232,   235,   311,   485,   336,   406,   337,   349,   406,   350,
      42,   182,   155,   897,    33,   351,   352,   354,  -984,   918,
    -984,   919,  -984,   920,  -984,   922,  -984,   923,  -984,   933,
     355,   396,   397,   398,   401,   408,   412,   183,   426,   185,
     437,   231,   233,   441,   443,   448,   461,   465,   467,   468,
     469,   470,   189,   190,  -984,  -984,   192,  -984,   898,   471,
     149,   169,   474,   180,   487,   488,   492,   493,   494,   495,
     496,   214,    47,   497,   498,   499,   502,   507,    50,   509,
     510,   511,   512,   513,   215,  -984,   934,  -984,   935,   943,
     936,   193,   194,   514,   515,   122,   517,   937,  -984,  -104,
    -984,    68,  -984,    52,  -984,    69,  -984,    55,  -984,    22,
    -984,    83,  -984,    85,  -984,    72,  -984,    76,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,   946,   947,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  1111,  -984,
     924,   434,   612,  -984,   925,  -984,   926,  -984,  -984,  -984,
     948,   927,  -984,  -152,   928,  -984,   658,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   938,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,   950,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,   940,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,   930,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,   932,  -984,  -984,  -984,
     942,  -984,  4351,   429,  -984,   429,  -984,  4351,   429,  -984,
     429,  -984,  4351,  -984,  4351,  -984,  4351,  -984,   429,  -984,
     429,  -984,  -984,  -984,   419,   636,   636,   195,   941,   452,
    -984,   173,   953,   452,  -984,   960,   961,   963,   951,   966,
     965,    34,    94,   957,   958,   959,   962,    96,    97,   101,
     103,   104,   105,   107,   110,   964,   967,   968,   111,   112,
     115,   121,   969,   124,   970,   972,   974,   975,   976,  3191,
     977,  3191,   979,   125,   126,   129,   130,   135,   138,   139,
     142,   143,   145,   147,   148,   150,   981,   983,   984,   985,
     986,   987,   988,   989,   990,   991,   992,   993,   994,   995,
     997,   998,   999,   152,  -984,  -984,  -984,   784,   982,  1065,
    -984,  -984,  -984,  -984,  -984,   116,  -984,  -984,  -984,   956,
     996,  1284,  1000,  1001,  1369,  1588,  1673,  1004,  1002,   952,
    1003,  1011,   452,  1014,  1018,  1017,  -984,   636,  -984,  -984,
    -984,   971,  -984,  -984,  1006,  -984,  -984,  -984,  1012,  -984,
    -127,  1005,  -984,  -984,   128,  -984,   196,  1013,  3191,  1015,
    -147,  -984,   176,  -984,   197,  -984,   178,  -984,   199,  -984,
     200,  -984,   201,  -984,   519,  -984,   520,   -42,   316,  -145,
    -984,   203,  -984,   204,  -984,   205,  -984,   206,  1016,  -984,
     208,  1021,  1022,  1023,  1024,   167,  3191,  3191,  3494,  3713,
    -984,  3411,   755,  -984,  -984,  -984,  -984,  -984,  -984,  -150,
    3411,  -150,  -984,    86,  -984,   184,  -984,   218,  -984,   521,
    -984,    99,  -984,   209,  -984,   210,  -984,  -101,  -984,   -45,
    -984,   -30,  -984,     4,  -984,    18,  -984,   346,  1019,  1033,
    1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  -150,   -56,  1046,  1046,  -984,    19,  1114,  1119,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  3713,  -984,  -984,
    -984,  -984,  -984,  -984,  1009,  1045,  -984,  1047,  1048,  -984,
    -984,  -984,  1049,  1050,  -151,    17,  -984,  1026,  -984,  -984,
    -984,  -984,  -984,  -984,    37,   391,  1052,  -142,  -984,    88,
    1051,  1054,  1055,  -984,  1056,   373,  -984,   372,  -984,  -984,
    1058,  1060,  1061,  1062,  1053,  1063,  1067,  1066,   403,  1078,
    1079,  1080,  1081,  1083,  1084,  1085,  1106,  1108,  1109,   409,
    -984,  1110,  1113,  1129,  1130,  1131,  1132,  1142,  1143,  1144,
    1145,  1146,  1153,  -984,  1163,  1164,  -984,  -984,  -984,  -984,
    1165,  1166,  -984,  -984,  -135,  -984,  1892,  3713,  -984,  3713,
    -984,   772,  -984,   380,  -984,  3191,  3191,  3796,  1192,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   476,   320,
    -984,   406,   338,  1167,  -984,  1213,  1168,  1169,  1170,  1191,
    1193,  1194,  1195,  1198,   508,  1212,  -984,  1214,  1216,  1217,
    1227,  1228,  1229,  1230,  1231,  1239,  1240,   527,  1241,   531,
    1242,   548,  1243,   592,  1215,  1246,  1247,  1248,  1249,  1250,
    1251,   315,   376,   420,   404,   607,  1252,  1253,  1254,  1255,
    -984,   154,  1256,   608,  1257,  -984,   335,  -984,  -984,  -984,
     617,  -984,  -984,   724,  4351,  4351,  4351,  4351,  1124,  4351,
    -984,  -984,  -984,  -984,  -984,    43,  -984,  -984,  1258,  1259,
    -142,  -984,  -984,  1262,  -984,  -127,  -984,  1057,  -984,  -984,
    -984,  1263,  -984,  1268,  -984,  -984,  -984,  -984,  1269,  -984,
    1270,  -984,   642,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  1271,  -984,  -984,  -984,  1272,  1273,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,   712,  3713,  3713,  3713,  3713,
    3713,  3713,  3713,  3713,  3713,  3713,  -984,  -984,  -984,  -984,
    1977,  4015,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  1265,
    -150,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  1278,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,   445,  -984,  -984,   484,  -984,  -984,   506,  -984,
    -984,  1276,  -984,  1277,  1279,  1280,  1281,  1282,  1286,  1287,
    -984,  -984,  -984,  -984,  1288,  -984,  -984,  -150,  -984,  1289,
    1291,  -150,  1292,  -984,    57,   429,   429,  -984,  -984,  -984,
    -984,  -984,   363,  -984,  2196,  2281,  2500,  2585,  1275,  2804,
    -984,  -984,  -984,  -984,  1290,   326,  -984,  1218,  1293,  1294,
    1295,  1296,  -984,  -984,  -984,  -984,   624,  1297,  1298,  1299,
    -984,   529,   529,   529,   529,   529,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  1219,  1300,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1309,  1312,  1313,  1314,  1315,  1316,  1318,   629,
     424,   439,   649,   660,  1319,  1320,   667,  1321,  -984,   670,
    1324,  1325,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  4351,
    -984,   326,  1328,  1301,  -984,  -984,  -984,  -984,   647,  -984,
    -984,  -984,  -984,   673,  1283,    38,  -984,  4015,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  1326,  -150,  -150,  -984,
     317,   360,  1334,  -984,  -984,  -984,  -150,  -984,  1323,  -984,
    1335,  -984,  1336,  -984,  -984,  -984,  -984,  -984,  2889,  1332,
    -151,  -164,  -984,  -984,  -984,  -984,  1031,  1317,  -984,  1322,
    -984,  -984,  -984,   671,  1333,  1337,  1340,  1341,  1342,  1343,
    1344,  1345,  1346,  1349,  1348,  -984,  -151,  1351,  1029,  1352,
    4098,  4268,  4351,   378,  -984,  -984,  -984,  1353,  1360,  1361,
    1362,  -984,  -984,  -984,  1339,  -984,  1355,  1363,  1364,  1236,
    1356,   747,  1358,   980,  3108,  1359,  1365,   674,   677,   678,
     682,  1366,  1367,  1370,  1338,  1372,  -984,  1368,  -984,  1383,
    -984,  -984,  -150,  -984,  -150,  -984,  -150,  -984,  -150,  -984,
    1373,  1384,  -984,  1379,  1390,  -984,  -984,  1385,  1387,  1388,
    1389,  1414,  -984,  1331,  1393,  -984,  -984,  -984,  -984,  -150,
    1443,  1347,  1413,  1424,  1461,  -984,  1396,  1441,  -984,  1411,
    -984
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
     106,     0,   108,     0,   110,     0,   112,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,   263,     0,   267,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,     0,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     5,
       3,     0,     9,     0,    11,     0,    13,     0,    15,     0,
      17,     0,    19,     0,    21,     0,    23,     0,    25,   214,
     211,   215,   212,   216,   213,   218,   217,   210,   209,    85,
      92,    91,     0,     0,    38,    84,    88,    87,    90,    89,
      86,    94,    93,    96,    95,    98,    97,   220,     0,    35,
       0,    66,    65,   219,     0,   224,    32,    28,   271,   270,
       0,     0,    47,    29,     0,    51,    52,   223,    27,   268,
     272,   269,   226,   225,   100,    99,   102,   101,   103,   105,
     107,   109,   111,   113,   116,   115,   120,   119,   123,   121,
     127,   126,   129,   128,   131,   130,   133,   132,   135,   134,
     137,   136,   139,   138,   141,   140,   143,   142,   145,   144,
     147,   146,   149,   148,   151,   150,   153,   152,   155,   154,
     157,   156,   159,   158,   161,   160,   204,   203,   206,   205,
     208,   207,   243,   242,     0,   118,   117,   164,   163,   162,
     167,   166,   165,   169,   168,   172,   170,   171,   174,   173,
     176,   175,   179,   177,   181,   180,   183,   182,   185,   184,
     187,   186,   190,   188,   189,   192,   191,   194,   193,   198,
     197,   200,   199,   202,   201,   196,   195,   228,    32,   227,
     230,   229,   232,   231,   234,   233,   236,   235,   238,   237,
     241,   239,   240,   244,   246,     0,   249,   251,   250,   253,
     252,   255,   254,   257,   256,   259,     0,   258,   261,   260,
     124,   283,     0,     0,   285,     0,   288,     0,     0,   290,
       0,   292,     0,   294,     0,   296,     0,   298,     0,   300,
       0,    39,    40,    44,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,   432,     0,   434,   438,     0,     0,     0,
       0,     0,     0,     0,     0,   489,     0,     0,     0,     0,
       0,     0,   510,     0,   515,   517,   519,   521,   524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,   378,   321,     0,     0,     0,
     370,   373,   374,   375,   376,     0,   279,   278,   280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
      41,     0,     0,     0,     0,     0,    57,    63,    70,    68,
     222,    73,   221,   273,    48,    34,    33,   122,     0,   178,
       0,     0,   125,   424,     0,   428,     0,     0,     0,     0,
       0,   441,     0,   468,     0,   472,     0,   475,     0,   495,
       0,   478,     0,   484,     0,   481,     0,     0,     0,     0,
     501,     0,   504,     0,   498,     0,   507,     0,     0,   512,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     324,     0,   325,   306,   322,   363,   323,   362,   361,     0,
       0,     0,   528,     0,   532,     0,   535,     0,   539,     0,
     542,     0,   545,     0,   548,     0,   445,     0,   448,     0,
     451,     0,   456,     0,   461,     0,   466,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   568,     0,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,     0,   377,   371,
     281,   369,   379,   372,     0,     0,   286,     0,     0,   291,
     293,   295,     0,     0,     0,     0,    61,    54,    60,    58,
      59,    62,    64,    74,     0,     0,     0,     0,    78,     0,
       0,     0,     0,   423,     0,     0,   431,     0,   433,   437,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     488,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   509,     0,     0,   514,   516,   518,   520,
       0,     0,   523,   303,     0,   365,     0,     0,   342,     0,
     341,   343,   344,     0,   345,     0,     0,     0,   380,   366,
     307,   309,   310,   311,   312,   308,   313,   314,   315,   316,
     319,     0,     0,     0,   382,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     582,     0,     0,     0,     0,   399,   401,   565,   404,   407,
       0,   359,   360,   358,     0,     0,     0,     0,     0,     0,
      36,    37,    46,    43,    42,     0,    50,    49,     0,     0,
       0,    71,    72,     0,    79,     0,   248,     0,   425,   422,
     429,     0,   426,     0,   435,   436,   442,   439,     0,   469,
       0,   473,     0,   470,   476,   474,   496,   494,   479,   477,
     485,   483,   482,   480,     0,   487,   490,   491,     0,     0,
     502,   500,   505,   503,   499,   497,   508,   506,   513,   511,
     525,   522,   304,   364,   356,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   305,   302,   301,   368,
       0,     0,   329,   274,   275,   330,   328,   327,   326,     0,
       0,   527,   526,   531,   529,   530,   534,   533,   538,     0,
     536,   541,   544,   543,   547,   546,   443,   444,   446,   447,
     449,   450,     0,   454,   455,     0,   459,   460,     0,   464,
     465,     0,   588,     0,     0,     0,     0,     0,     0,     0,
     276,   569,   277,   570,     0,   571,   572,     0,   575,     0,
       0,     0,     0,   421,     0,     0,     0,   587,   567,   402,
     405,   408,   403,   566,     0,     0,     0,     0,     0,     0,
      56,    55,   265,   266,     0,     0,    77,     0,     0,     0,
       0,     0,   412,   410,   411,   413,     0,     0,     0,     0,
     357,   352,   351,   353,   354,   355,   346,   347,   349,   348,
     350,   367,   381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   418,     0,
       0,     0,   400,   406,   409,   282,   284,   287,   289,     0,
     299,     0,     0,     0,   427,   430,   440,   467,     0,   471,
     486,   492,   493,     0,     0,   386,   388,     0,   537,   452,
     453,   457,   458,   462,   463,   589,     0,     0,     0,   552,
       0,     0,     0,   564,   573,   574,     0,   576,     0,   578,
       0,   581,     0,   583,   420,   419,   585,   586,     0,     0,
       0,     0,   417,   414,   415,   416,     0,     0,   384,     0,
     387,   385,   383,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,    83,     0,
     396,   392,   398,     0,   549,   553,   554,     0,     0,     0,
       0,   563,   577,   579,     0,   584,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   394,     0,   390,     0,
     550,   551,     0,   555,     0,   556,     0,   559,     0,   560,
       0,     0,    75,     0,     0,   393,   389,     0,     0,     0,
       0,     0,    76,     0,     0,   557,   558,   561,   562,     0,
       0,     0,     0,     0,     0,   580,     0,     0,    81,     0,
      80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -984,  -984,  -984,  1416,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -182,  -984,  -984,  -121,  -686,  -115,  -120,
    -984,  -984,  1232,  -984,  -984,  -400,  -984,  -984,  -984,   771,
    1092,   668,  -984,  -984,  -984,  -984,  -787,  -984,  1394,  -984,
    -983,  -657,  -398,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -479,  -984,  -984,  -984,  -984,  -984,  -484,  -984,
    -475,  -984,  -658,  -450,  -984,  -626,  -419,  -520,  -444,  -984,
    -984,  -984,  -984,  -984,   539,  -984,   652,  -984,  1064,  -458
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   272,   452,   273,   274,   872,   780,   275,
     262,   276,   277,   708,   557,   558,   263,   446,   445,   883,
     562,   718,   719,   417,   105,   106,   278,   279,   280,   281,
     955,   842,   539,   212,   214,   216,   218,   220,   222,   224,
     226,   228,   621,   798,   799,   800,   801,   802,   527,   623,
     782,   687,   783,   528,   626,   788,   529,   530,   531,   532,
     533,   534,  1114,  1115,  1116,  1161,   860,  1046,   852,   535
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     245,   260,   261,   250,   804,   622,   389,   622,   541,   691,
     844,   954,   630,   544,   624,   545,   624,   546,   873,   874,
     854,   691,   167,   431,   691,   691,   691,   540,   877,   863,
     542,   628,   543,   628,   265,   573,   317,   319,   876,   625,
     547,   625,   548,   253,  1030,   627,   559,   627,   375,   128,
     450,   387,  1102,   424,   242,   243,   429,   870,  1087,   785,
     786,   244,   524,   130,   132,   524,   753,   524,   259,   421,
     426,   729,   107,   437,   134,  1178,  1179,   439,   451,   716,
    1113,  1159,   871,   932,   433,   526,   435,   806,   526,   884,
     526,   881,   717,   108,   622,   575,   731,   581,   583,   727,
     815,   789,   585,   624,   587,   589,   591,   821,   593,   822,
     789,   595,   600,   602,   752,   754,   604,   692,  1149,   934,
     628,   935,   606,   415,   109,   609,   632,   634,   625,   721,
     636,   638,   622,   622,   627,   781,   640,   773,   774,   642,
     644,   624,   624,   646,   648,   803,   650,   805,   652,   654,
     347,   656,   849,   675,   110,  1013,   257,   712,   628,   628,
     111,   784,   850,   823,   112,   824,   625,   625,   770,   749,
     350,   164,   627,   627,   565,   229,   750,   732,   825,   737,
     826,   355,   113,   255,   308,   808,   312,   848,   738,  1031,
     338,   340,   859,   342,   407,   409,   560,   724,   735,   776,
     739,   741,   743,   781,   755,   757,   759,   761,   114,   764,
     817,   819,   827,   208,   828,   372,   400,   115,   211,   811,
     242,   243,   231,   213,   129,   870,   829,   244,   830,   784,
     855,   524,   316,   233,   318,   856,   235,   857,   131,   133,
     168,   258,   432,   266,   267,   870,   268,   269,   954,   135,
     871,   870,   254,   574,   526,   270,   691,   376,   242,   243,
     388,   267,   550,   268,   269,   244,   271,   564,   855,   524,
     871,   550,   270,   856,   425,  1088,   871,   430,  1051,  1052,
    1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,   422,   427,
     423,   428,   526,   781,   438,   781,   388,   267,   440,   268,
     269,   622,   622,   434,   885,   436,   947,   948,   270,   886,
     624,   624,   237,   576,   954,   582,   584,   816,   958,   784,
     586,   784,   588,   590,   592,  1062,   594,   628,   628,   596,
     601,   603,   416,   693,   605,   625,   625,   240,   246,   722,
     607,   627,   627,   610,   633,   635,   723,  1081,   637,   639,
     248,   251,   282,   284,   641,   286,   294,   643,   645,   348,
     349,   647,   649,   258,   651,   259,   653,   655,   950,   657,
     707,   676,  1021,  1014,   620,   771,   620,   242,   243,   351,
     352,   165,   230,   -30,   244,   772,   536,   733,   537,   538,
     356,   357,   809,   256,   309,   810,   313,   296,   298,   300,
     339,   341,   302,   343,   408,   410,   561,   725,   736,   304,
     740,   742,   744,   306,   756,   758,   760,   762,  1045,   765,
     818,   820,   373,   401,   374,   402,   258,   310,   259,   232,
     691,   789,   242,   243,   242,   243,   136,   138,   314,   244,
     234,   244,   320,   236,   322,  1024,  1025,  1026,  1027,   324,
    1029,   807,   781,   781,   781,   781,   781,   781,   781,   781,
     781,   781,   326,   620,  1177,   730,   328,   734,   330,   332,
     334,   336,   345,   195,   116,   353,  1064,   117,   784,   784,
     784,   784,   784,   784,   784,   784,   784,   784,   358,   360,
    1196,  1162,   197,   362,   364,   366,   368,   370,   377,   379,
     381,   620,   620,   383,   691,   691,   691,   691,   385,   691,
     390,   392,   394,   396,   398,   411,   413,   812,   418,   238,
     745,   747,   813,  1082,   751,  1166,  1000,  1085,   524,   524,
     859,  -318,  -318,  1001,   -69,   118,   242,   243,  1094,   268,
     269,   953,   952,   244,   241,   247,  1019,   524,   270,   957,
     524,   526,   526,   119,   831,  -318,   832,   249,   252,   283,
     285,   858,   287,   295,   242,   243,   785,   786,  1168,   120,
     526,   244,   524,   526,  1092,   524,   936,   937,   938,   939,
     940,   941,   942,   943,   944,   945,  1205,  1002,   893,   891,
     524,   892,   242,   243,  1003,   526,   882,   789,   526,   244,
     879,   121,   878,   946,   297,   299,   301,   242,   243,   303,
     215,   137,   139,   526,   244,  1002,   305,  1090,  1091,   902,
     307,   903,  1006,   549,  1155,   914,   122,   915,   691,   388,
     267,  1000,   268,   269,   311,  1000,  1004,   536,  1005,   537,
     538,   270,  1134,  1164,  1165,   315,  1167,  1169,   196,   321,
    1002,   323,  1171,  1066,   123,  1067,   325,  1135,   -69,   -69,
     -69,   -69,   388,   267,   217,   268,   269,   198,   -69,   327,
     620,   620,   219,   329,   270,   331,   333,   335,   337,   346,
    1148,   691,   354,   691,   691,   221,   956,  -317,  -317,   268,
     269,   953,  1068,   239,  1069,   359,   361,   225,   270,  1206,
     363,   365,   367,   369,   371,   378,   380,   382,  1042,   124,
     384,  -317,   -67,  1152,  1070,   386,  1071,   391,   393,   395,
     397,   399,   412,   414,   969,   419,   970,   746,   748,   814,
     941,   942,   943,   944,   945,   125,   551,   126,  1237,   127,
    1238,  1020,  1239,   982,  1240,   983,   140,   985,   689,   986,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   882,
     141,  1201,  1203,  1204,   988,  1252,   989,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,  1044,   490,  -395,
    -395,  1217,   491,   492,   142,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   991,   143,
     992,   506,   223,   144,   507,   508,   509,   510,   511,   512,
     513,   514,   515,  1007,  1016,  1008,  1017,   145,   516,   517,
     518,   519,   520,  1022,   227,  1023,   -67,   -67,   -67,   -67,
    1108,   146,  1109,   242,   243,  1132,   -67,  1133,   242,   243,
     244,   147,   148,  1043,   524,   244,   149,   150,  1153,   524,
     552,   553,   554,   555,   151,  1136,   258,  1137,   266,   267,
     556,   268,   269,   152,   242,   243,  1138,   526,  1139,   153,
     270,   244,   526,  1142,  1156,  1143,  1022,  1183,  1145,  1184,
    1222,   271,  1223,  1224,  1226,  1225,  1227,   154,  1228,   858,
    1229,   155,   156,   157,   158,   159,   160,  1093,   936,   937,
     938,   939,   940,   941,   942,   943,   944,   945,   521,   522,
     936,   937,   938,   939,   940,   941,   942,   943,   944,   945,
    1050,   677,   790,   791,   792,   793,   794,   795,   796,   797,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   790,
     791,   792,   793,   794,   795,   796,   797,   523,   161,   524,
     677,   162,   163,   166,   525,   169,   170,   171,  -395,   678,
     679,   680,   681,   682,   683,   684,   685,   686,   172,   173,
     174,   689,   526,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   175,  1154,   176,   177,   178,   179,  1157,   180,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     181,   490,  -391,  -391,  1219,   491,   492,   182,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   183,   184,   185,   506,   186,   187,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   188,   189,   190,   191,
     192,   516,   517,   518,   519,   520,   689,   193,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   194,   199,   200,
     201,   202,   203,   204,   205,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   206,   490,   207,   264,   344,
     491,   492,   443,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   288,   289,   290,   506,
     291,   292,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   293,   403,   404,   406,   420,   516,   517,   518,   519,
     520,   521,   522,   405,   441,   442,   444,   447,   -35,   449,
     453,   268,   458,   566,   563,   455,   456,   457,   459,   460,
     567,   570,   568,   569,   571,   572,   577,   578,   579,   694,
     861,   580,   561,   597,   704,   862,   598,   599,   608,   611,
     523,   612,   524,   613,   614,   615,   629,   525,   631,   688,
     658,  -391,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   526,   672,   673,   674,   695,
     702,   706,   709,   697,   698,   703,   710,   711,   715,   864,
     833,   726,   951,   728,   763,   705,   521,   522,   714,   766,
     767,   768,   769,   720,   834,   835,   836,   837,   838,   839,
     840,   841,   843,   845,   846,   847,   851,   868,   875,   887,
     960,  1113,  1037,  1180,  1103,   865,  1198,   866,   867,   898,
     869,   880,   888,   889,   890,   523,   894,   524,   895,   896,
     897,   899,   525,   900,   901,   689,   690,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   904,   905,   906,   907,
     526,   908,   909,   910,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   911,   490,   912,   913,   916,   491,
     492,   917,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   918,   919,  1028,   506,   920,
     921,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     922,   923,   924,   925,   926,   516,   517,   518,   519,   520,
     689,   927,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   928,   929,   930,   931,   959,   961,   962,   963,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   964,
     490,   965,   966,   967,   491,   492,   968,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     971,   993,   972,   506,   973,   974,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   975,   976,   977,   978,   979,
     516,   517,   518,   519,   520,   521,   522,   980,   981,   984,
     987,   990,   994,   995,   996,   997,   998,   999,  1009,  1010,
    1011,  1012,  1015,  1215,  1038,  1018,  1032,  1033,  1035,  1039,
    1040,  1041,  1047,  1048,  1049,  1063,  1065,  1072,  1073,  1253,
    1074,  1075,  1076,  1077,   523,  1099,   524,  1078,  1079,  1080,
    1083,   525,  1084,  1086,  1158,   696,  1101,  1257,   454,  1151,
     210,  1104,  1105,  1106,  1107,  1110,  1111,  1112,  1117,   526,
    1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,
    1128,  1172,  1130,  1129,  1131,  1140,  1250,  1163,  1141,  1144,
     521,   522,  1146,  1147,  1150,  1170,  1173,  1174,  1176,  1181,
    1211,  1185,  1254,  1036,  1182,  1186,  1187,  1188,  1189,  1190,
    1199,  1207,  1191,  1192,  1193,  1194,  1195,  1197,  1208,  1209,
    1210,  1212,  1214,  1216,  1213,  1218,  1233,  1220,  1231,   523,
    1234,   524,  1230,  1221,  1241,  1235,   525,  1243,  1232,   689,
     699,   461,   462,   463,   464,   465,   466,   467,   468,   469,
    1236,  1251,  1242,  1245,   526,  1246,  1247,  1248,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,  1244,   490,
    1249,  1255,  1256,   491,   492,  1258,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,  1259,
    1260,  1034,   506,   713,  1160,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   448,     0,  1089,     0,     0,   516,
     517,   518,   519,   520,   689,     0,   461,   462,   463,   464,
     465,   466,   467,   468,   469,     0,     0,     0,     0,     0,
       0,     0,     0,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,     0,   490,     0,     0,     0,   491,   492,
       0,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,     0,     0,     0,   506,   853,     0,
     507,   508,   509,   510,   511,   512,   513,   514,   515,     0,
       0,     0,     0,     0,   516,   517,   518,   519,   520,   521,
     522,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,     0,
     524,     0,     0,     0,     0,   525,     0,     0,     0,   700,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   526,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   521,   522,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   523,     0,   524,     0,     0,     0,     0,
     525,     0,     0,   689,   701,   461,   462,   463,   464,   465,
     466,   467,   468,   469,     0,     0,     0,     0,   526,     0,
       0,     0,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,     0,   490,     0,     0,     0,   491,   492,     0,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,     0,     0,     0,   506,     0,     0,   507,
     508,   509,   510,   511,   512,   513,   514,   515,     0,     0,
       0,     0,     0,   516,   517,   518,   519,   520,   689,     0,
     461,   462,   463,   464,   465,   466,   467,   468,   469,     0,
       0,     0,     0,     0,     0,     0,     0,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     0,   490,     0,
       0,     0,   491,   492,     0,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,     0,     0,
       0,   506,     0,     0,   507,   508,   509,   510,   511,   512,
     513,   514,   515,     0,     0,     0,     0,     0,   516,   517,
     518,   519,   520,   521,   522,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   523,     0,   524,     0,     0,     0,     0,   525,
       0,     0,     0,   933,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   521,   522,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   523,     0,   524,
       0,     0,     0,     0,   525,     0,     0,   689,  1061,   461,
     462,   463,   464,   465,   466,   467,   468,   469,     0,     0,
       0,     0,   526,     0,     0,     0,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,   490,     0,     0,
       0,   491,   492,     0,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,     0,     0,     0,
     506,     0,     0,   507,   508,   509,   510,   511,   512,   513,
     514,   515,     0,     0,     0,     0,     0,   516,   517,   518,
     519,   520,   689,     0,   461,   462,   463,   464,   465,   466,
     467,   468,   469,     0,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,   490,     0,     0,     0,   491,   492,     0,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,     0,     0,     0,   506,     0,     0,   507,   508,
     509,   510,   511,   512,   513,   514,   515,     0,     0,     0,
       0,     0,   516,   517,   518,   519,   520,   521,   522,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,     0,   524,     0,
       0,     0,     0,   525,     0,     0,     0,  1095,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   526,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   521,   522,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   523,     0,   524,     0,     0,     0,     0,   525,     0,
       0,   689,  1096,   461,   462,   463,   464,   465,   466,   467,
     468,   469,     0,     0,     0,     0,   526,     0,     0,     0,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
       0,   490,     0,     0,     0,   491,   492,     0,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,     0,     0,     0,   506,     0,     0,   507,   508,   509,
     510,   511,   512,   513,   514,   515,     0,     0,     0,     0,
       0,   516,   517,   518,   519,   520,   689,     0,   461,   462,
     463,   464,   465,   466,   467,   468,   469,     0,     0,     0,
       0,     0,     0,     0,     0,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,   490,     0,     0,     0,
     491,   492,     0,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,     0,     0,     0,   506,
       0,     0,   507,   508,   509,   510,   511,   512,   513,   514,
     515,     0,     0,     0,     0,     0,   516,   517,   518,   519,
     520,   521,   522,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     523,     0,   524,     0,     0,     0,     0,   525,     0,     0,
       0,  1097,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   526,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   521,   522,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   523,     0,   524,     0,     0,
       0,     0,   525,     0,     0,   689,  1098,   461,   462,   463,
     464,   465,   466,   467,   468,   469,     0,     0,     0,     0,
     526,     0,     0,     0,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,   490,     0,     0,     0,   491,
     492,     0,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,     0,     0,     0,   506,     0,
       0,   507,   508,   509,   510,   511,   512,   513,   514,   515,
       0,     0,     0,     0,     0,   516,   517,   518,   519,   520,
     689,     0,   461,   462,   463,   464,   465,   466,   467,   468,
     469,     0,     0,     0,     0,     0,     0,     0,     0,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,     0,
     490,     0,     0,     0,   491,   492,     0,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
       0,     0,     0,   506,     0,     0,   507,   508,   509,   510,
     511,   512,   513,   514,   515,     0,     0,     0,     0,     0,
     516,   517,   518,   519,   520,   521,   522,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   523,     0,   524,     0,     0,     0,
       0,   525,     0,     0,     0,  1100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   526,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     521,   522,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   523,
       0,   524,     0,     0,     0,     0,   525,     0,     0,   689,
    1175,   461,   462,   463,   464,   465,   466,   467,   468,   469,
       0,     0,     0,     0,   526,     0,     0,     0,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,   490,
       0,     0,     0,   491,   492,     0,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,     0,
       0,     0,   506,     0,     0,   507,   508,   509,   510,   511,
     512,   513,   514,   515,     0,     0,     0,     0,     0,   516,
     517,   518,   519,   520,   461,   462,   463,   464,   465,   466,
     467,   468,   469,     0,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,     0,     0,     0,     0,     0,     0,     0,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,     0,     0,     0,   506,     0,     0,   507,   508,
     509,   510,   511,   512,   513,   514,   515,     0,     0,     0,
       0,     0,   516,   517,   518,   519,   520,     0,     0,   521,
     522,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,     0,
     524,     0,     0,     0,     0,   525,     0,     0,     0,  -397,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   526,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   521,   522,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   242,   243,     0,     0,     0,   616,     0,   244,
       0,   523,     0,   524,     0,     0,     0,     0,     0,     0,
     617,   618,     0,   619,   461,   462,   463,   464,   465,   466,
     467,   468,   469,     0,     0,     0,   526,     0,     0,     0,
       0,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,   490,     0,     0,     0,   491,   492,     0,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,     0,     0,     0,   506,     0,     0,   507,   508,
     509,   510,   511,   512,   513,   514,   515,     0,     0,     0,
       0,     0,   516,   517,   518,   519,   520,   461,   462,   463,
     464,   465,   466,   467,   468,   469,     0,     0,     0,     0,
       0,     0,     0,     0,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,     0,   490,     0,     0,     0,   491,
     492,     0,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,     0,     0,     0,   506,     0,
       0,   507,   508,   509,   510,   511,   512,   513,   514,   515,
       0,     0,     0,     0,     0,   516,   517,   518,   519,   520,
       0,     0,   521,   522,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   785,   786,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   523,     0,   524,     0,     0,     0,     0,   525,     0,
       0,   787,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   521,   522,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   523,     0,   524,     0,     0,     0,
       0,   525,     0,     0,     0,   775,   461,   462,   463,   464,
     465,   466,   467,   468,   469,     0,     0,     0,     0,   526,
       0,     0,     0,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,     0,     0,     0,   506,     0,     0,
     507,   508,   509,   510,   511,   512,   513,   514,   515,     0,
       0,     0,     0,     0,   516,   517,   518,   519,   520,   461,
     462,   463,   464,   465,   466,   467,   468,   469,     0,     0,
       0,     0,     0,     0,     0,     0,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,     0,   490,     0,     0,
       0,   491,   492,     0,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,     0,     0,     0,
     506,     0,     0,   507,   508,   509,   510,   511,   512,   513,
     514,   515,     0,     0,     0,     0,     0,   516,   517,   518,
     519,   520,     0,     0,   521,   522,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,   243,     0,     0,     0,     0,
     777,   244,     0,   523,   778,   524,     0,     0,     0,     0,
       0,     0,   779,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   526,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   521,   522,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,     0,   524,     0,
       0,     0,     0,   525,     0,     0,     0,   949,   461,   462,
     463,   464,   465,   466,   467,   468,   469,     0,     0,     0,
       0,   526,     0,     0,     0,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,     0,   490,     0,     0,     0,
     491,   492,     0,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,     0,     0,     0,   506,
       0,     0,   507,   508,   509,   510,   511,   512,   513,   514,
     515,     0,     0,     0,     0,     0,   516,   517,   518,   519,
     520,   461,   462,   463,   464,   465,   466,   467,   468,   469,
       0,     0,     0,     0,     0,     0,     0,     0,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,     0,   490,
       0,     0,  1200,   491,   492,     0,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,     0,
       0,     0,   506,     0,     0,   507,   508,   509,   510,   511,
     512,   513,   514,   515,     0,     0,     0,     0,     0,   516,
     517,   518,   519,   520,     0,     0,   521,   522,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   523,     0,   524,     0,     0,
       0,     0,   525,     0,     0,   787,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     526,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   521,
     522,   461,   462,   463,   464,   465,   466,   467,   468,   469,
       0,     0,     0,     0,     0,     0,     0,     0,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   523,   490,
     524,     0,  1202,   491,   492,   525,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,     0,
       0,     0,   506,   526,     0,   507,   508,   509,   510,   511,
     512,   513,   514,   515,     0,     0,     0,     0,     0,   516,
     517,   518,   519,   520,   461,   462,   463,   464,   465,   466,
     467,   468,   469,     0,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,     0,   490,     0,     0,     0,   491,   492,     0,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,     0,     0,     0,   506,     0,     0,   507,   508,
     509,   510,   511,   512,   513,   514,   515,     0,     0,     0,
       0,     0,   516,   517,   518,   519,   520,     0,     0,   521,
     522,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,     0,
     524,     0,     0,     0,     0,   525,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -2,   209,   526,     0,     0,     0,     0,     0,     0,
       0,     0,    -8,   -10,   -12,   -14,   -16,   -18,   -20,   -22,
     -24,     0,   521,   522,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   523,     0,   524,     0,     0,     0,     0,   525,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     0,     0,     0,     0,   526,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     1,     0,     0,    89,    90,    91,     0,     0,     0,
       0,    -8,   -10,   -12,   -14,   -16,   -18,   -20,   -22,   -24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92
};

static const yytype_int16 yycheck[] =
{
     115,   122,   122,   118,   630,   489,   188,   491,   427,   529,
     667,   798,   491,   432,   489,   434,   491,   436,     1,   705,
       1,   541,     1,     1,   544,   545,   546,   425,   714,   687,
     428,   489,   430,   491,     1,     1,   151,   152,     1,   489,
     438,   491,   440,     1,     1,   489,   446,   491,     1,     1,
     202,     1,  1035,     1,   201,   202,     1,   208,     1,   194,
     195,   208,   212,     1,     1,   212,   211,   212,   210,     1,
       1,   218,   176,     1,     1,   239,   240,     1,   230,   206,
      42,    43,   233,   218,     1,   235,     1,     1,   235,     1,
     235,   233,   219,   176,   578,     1,   580,     1,     1,   578,
       1,   621,     1,   578,     1,     1,     1,   208,     1,   210,
     630,     1,     1,     1,   598,   599,     1,     1,  1101,   777,
     578,   779,     1,     1,   176,     1,     1,     1,   578,     1,
       1,     1,   616,   617,   578,   619,     1,   616,   617,     1,
       1,   616,   617,     1,     1,   629,     1,   631,     1,     1,
       1,     1,   208,     1,   176,     1,     1,   557,   616,   617,
     176,   619,   218,   208,   176,   210,   616,   617,     1,   211,
       1,     1,   616,   617,     1,     1,   218,     1,   208,     1,
     210,     1,   176,     1,     1,     1,     1,   671,   586,   875,
       1,     1,   676,     1,     1,     1,     1,     1,     1,   618,
       1,     1,     1,   687,     1,     1,     1,     1,   176,     1,
       1,     1,   208,     0,   210,     1,     1,   176,    11,     1,
     201,   202,     1,    12,   176,   208,   208,   208,   210,   687,
     211,   212,     1,     1,     1,   216,     1,   218,   176,   176,
     219,   208,   220,   210,   211,   208,   213,   214,  1035,   176,
     233,   208,   210,   219,   235,   222,   776,   210,   201,   202,
     210,   211,   444,   213,   214,   208,   233,   449,   211,   212,
     233,   453,   222,   216,   222,   218,   233,   222,   936,   937,
     938,   939,   940,   941,   942,   943,   944,   945,   220,   220,
     222,   222,   235,   777,   222,   779,   210,   211,   222,   213,
     214,   785,   786,   220,   216,   220,   785,   786,   222,   221,
     785,   786,     1,   219,  1101,   219,   219,   218,   802,   777,
     219,   779,   219,   219,   219,   951,   219,   785,   786,   219,
     219,   219,   210,   217,   219,   785,   786,     1,     1,   211,
     219,   785,   786,   219,   219,   219,   218,  1004,   219,   219,
       1,     1,     1,     1,   219,     1,     1,   219,   219,   210,
     211,   219,   219,   208,   219,   210,   219,   219,   787,   219,
     552,   219,   856,   219,   489,   208,   491,   201,   202,   210,
     211,   211,   208,   210,   208,   218,   208,   211,   210,   211,
     210,   211,   208,   211,   211,   211,   211,     1,     1,     1,
     211,   211,     1,   211,   211,   211,   211,   211,   211,     1,
     211,   211,   211,     1,   211,   211,   211,   211,   902,   211,
     211,   211,   208,   208,   210,   210,   208,     1,   210,   208,
     950,   951,   201,   202,   201,   202,     1,     1,     1,   208,
     208,   208,     1,   208,     1,   864,   865,   866,   867,     1,
     869,   633,   936,   937,   938,   939,   940,   941,   942,   943,
     944,   945,     1,   578,  1150,   580,     1,   582,     1,     1,
       1,     1,     1,     1,   176,     1,   960,   176,   936,   937,
     938,   939,   940,   941,   942,   943,   944,   945,     1,     1,
    1176,  1117,     1,     1,     1,     1,     1,     1,     1,     1,
       1,   616,   617,     1,  1024,  1025,  1026,  1027,     1,  1029,
       1,     1,     1,     1,     1,     1,     1,   637,     1,   208,
       1,     1,     1,  1007,   208,   208,   211,  1011,   212,   212,
    1014,   211,   212,   218,   100,   176,   201,   202,  1022,   213,
     214,   215,    66,   208,   208,   208,   211,   212,   222,   211,
     212,   235,   235,   176,   208,   235,   210,   208,   208,   208,
     208,   676,   208,   208,   201,   202,   194,   195,   208,   176,
     235,   208,   212,   235,   211,   212,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   208,   211,   216,   216,
     212,   218,   201,   202,   218,   235,   717,  1117,   235,   208,
     715,   176,   211,   223,   208,   208,   208,   201,   202,   208,
      13,   176,   176,   235,   208,   211,   208,  1015,  1016,   216,
     208,   218,   218,   204,  1108,   216,   176,   218,  1148,   210,
     211,   211,   213,   214,   208,   211,   216,   208,   218,   210,
     211,   222,   218,  1127,  1128,   208,  1130,  1131,   176,   208,
     211,   208,  1136,   208,   176,   210,   208,   218,   224,   225,
     226,   227,   210,   211,    14,   213,   214,   176,   234,   208,
     785,   786,    15,   208,   222,   208,   208,   208,   208,   208,
    1099,  1201,   208,  1203,  1204,    16,   801,   211,   212,   213,
     214,   215,   208,   208,   210,   208,   208,    18,   222,  1183,
     208,   208,   208,   208,   208,   208,   208,   208,    66,   176,
     208,   235,   100,    66,   208,   208,   210,   208,   208,   208,
     208,   208,   208,   208,   216,   208,   218,   208,   208,   208,
     201,   202,   203,   204,   205,   176,   100,   176,  1222,   176,
    1224,   856,  1226,   216,  1228,   218,   176,   216,     1,   218,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   880,
     176,  1180,  1181,  1182,   216,  1249,   218,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   902,    41,    42,
      43,    44,    45,    46,   176,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,   216,   176,
     218,    64,    17,   176,    67,    68,    69,    70,    71,    72,
      73,    74,    75,   216,   216,   218,   218,   176,    81,    82,
      83,    84,    85,   216,    19,   218,   224,   225,   226,   227,
     216,   176,   218,   201,   202,   216,   234,   218,   201,   202,
     208,   176,   176,   211,   212,   208,   176,   176,   211,   212,
     224,   225,   226,   227,   176,   216,   208,   218,   210,   211,
     234,   213,   214,   176,   201,   202,   216,   235,   218,   176,
     222,   208,   235,   216,   211,   218,   216,   216,   218,   218,
     216,   233,   218,   216,   216,   218,   218,   176,   216,  1014,
     218,   176,   176,   176,   176,   176,   176,  1022,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   171,   172,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     218,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   177,
     178,   179,   180,   181,   182,   183,   184,   210,   176,   212,
     176,   176,   176,   176,   217,   176,   176,   176,   221,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   176,   176,
     176,     1,   235,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   176,  1108,   176,   176,   176,   176,  1113,   176,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     176,    41,    42,    43,    44,    45,    46,   176,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,   176,   176,   176,    64,   176,   176,    67,    68,    69,
      70,    71,    72,    73,    74,    75,   176,   176,   176,   176,
     176,    81,    82,    83,    84,    85,     1,   176,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   176,   176,   176,
     176,   176,   176,   176,   176,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,   176,    41,   176,   211,   211,
      45,    46,     1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,   208,   208,   208,    64,
     208,   208,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   208,   208,   208,   208,   208,    81,    82,    83,    84,
      85,   171,   172,   210,   208,   208,   232,   232,   232,   232,
     232,   213,   232,   210,   223,   227,   216,   227,   236,   227,
     210,   220,   211,   210,   208,   210,   219,   219,   219,   223,
      66,   219,   211,   219,   232,    66,   219,   219,   219,   219,
     210,   219,   212,   219,   219,   219,   219,   217,   219,   217,
     219,   221,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   235,   219,   219,   219,   223,
     216,   210,   208,   223,   223,   223,   208,   210,   216,   220,
     211,   218,    40,   218,   218,   232,   171,   172,   232,   218,
     218,   218,   218,   238,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   210,   208,   232,   208,
      47,    42,   205,   232,    46,   220,   237,   220,   220,   216,
     220,   219,   218,   218,   218,   210,   218,   212,   218,   218,
     218,   218,   217,   216,   218,     1,   221,     3,     4,     5,
       6,     7,     8,     9,    10,    11,   218,   218,   218,   218,
     235,   218,   218,   218,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,   218,    41,   218,   218,   218,    45,
      46,   218,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,   216,   216,   223,    64,   218,
     218,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     218,   218,   218,   218,   218,    81,    82,    83,    84,    85,
       1,   218,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   218,   218,   218,   218,   218,   218,   218,   218,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,   218,
      41,   218,   218,   218,    45,    46,   218,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
     218,   216,   218,    64,   218,   218,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   218,   218,   218,   218,   218,
      81,    82,    83,    84,    85,   171,   172,   218,   218,   218,
     218,   218,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   237,   211,   218,   218,   218,   216,   211,
     211,   211,   211,   211,   211,   220,   208,   211,   211,    46,
     211,   211,   211,   211,   210,   220,   212,   211,   211,   211,
     211,   217,   211,   211,   221,   221,   216,    46,   276,   208,
      94,   218,   218,   218,   218,   218,   218,   218,   218,   235,
     218,   218,   218,   218,   218,   218,   218,   218,   216,   216,
     216,   208,   216,   218,   216,   216,   205,   211,   218,   218,
     171,   172,   218,   218,   216,   211,   211,   211,   216,   232,
     211,   218,   205,   885,   232,   218,   216,   216,   216,   216,
     208,   208,   218,   218,   218,   216,   218,   216,   208,   208,
     208,   216,   208,   217,   211,   217,   238,   218,   211,   210,
     208,   212,   216,   218,   211,   217,   217,   208,   218,     1,
     221,     3,     4,     5,     6,     7,     8,     9,    10,    11,
     217,   208,   218,   218,   235,   218,   218,   218,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   238,    41,
     216,   218,   208,    45,    46,   239,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,   208,
     239,   880,    64,   561,  1115,    67,    68,    69,    70,    71,
      72,    73,    74,    75,   270,    -1,  1014,    -1,    -1,    81,
      82,    83,    84,    85,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    -1,    -1,    -1,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    64,   674,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
     212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   210,    -1,   212,    -1,    -1,    -1,    -1,
     217,    -1,    -1,     1,   221,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    64,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    -1,
      -1,    -1,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,   212,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,     1,   221,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,   235,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    -1,    -1,
      -1,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    64,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,   212,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,    -1,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,     1,   221,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    64,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210,    -1,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,    -1,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,     1,   221,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    64,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    -1,    -1,    -1,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,    -1,   212,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
      -1,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,     1,
     221,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    64,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    64,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
     212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,   202,    -1,    -1,    -1,   206,    -1,   208,
      -1,   210,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,    -1,   222,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    64,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    64,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,    -1,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,    -1,   212,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    64,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    -1,    -1,
      -1,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    -1,    -1,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,    -1,
     207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,   212,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,   221,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    64,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    64,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    -1,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,    -1,   212,    -1,    -1,
      -1,    -1,   217,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   210,    41,
     212,    -1,    44,    45,    46,   217,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    64,   235,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    64,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
     212,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,    -1,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,   235,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     1,    -1,    -1,   173,   174,   175,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,   173,   174,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     1,    76,    77,    78,    79,    80,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    96,    97,    98,    99,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   173,
     174,   175,   231,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   276,   277,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,     1,   176,
       1,   176,     1,   176,     1,   176,     1,   176,     1,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,     1,   211,   176,     1,   219,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,     1,   176,     1,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,     0,     1,
     245,    11,   285,    12,   286,    13,   287,    14,   288,    15,
     289,    16,   290,    17,   291,    18,   292,    19,   293,     1,
     208,     1,   208,     1,   208,     1,   208,     1,   208,   208,
       1,   208,   201,   202,   208,   260,     1,   208,     1,   208,
     260,     1,   208,     1,   210,     1,   211,     1,   208,   210,
     258,   261,   262,   268,   211,     1,   210,   211,   213,   214,
     222,   233,   255,   257,   258,   261,   263,   264,   278,   279,
     280,   281,     1,   208,     1,   208,     1,   208,   208,   208,
     208,   208,   208,   208,     1,   208,     1,   208,     1,   208,
       1,   208,     1,   208,     1,   208,     1,   208,     1,   211,
       1,   208,     1,   211,     1,   208,     1,   260,     1,   260,
       1,   208,     1,   208,     1,   208,     1,   208,     1,   208,
       1,   208,     1,   208,     1,   208,     1,   208,     1,   211,
       1,   211,     1,   211,   211,     1,   208,     1,   210,   211,
       1,   210,   211,     1,   208,     1,   210,   211,     1,   208,
       1,   208,     1,   208,     1,   208,     1,   208,     1,   208,
       1,   208,     1,   208,   210,     1,   210,     1,   208,     1,
     208,     1,   208,     1,   208,     1,   208,     1,   210,   255,
       1,   208,     1,   208,     1,   208,     1,   208,     1,   208,
       1,   208,   210,   208,   208,   210,   208,     1,   211,     1,
     211,     1,   208,     1,   208,     1,   210,   275,     1,   208,
     208,     1,   220,   222,     1,   222,     1,   220,   222,     1,
     222,     1,   220,     1,   220,     1,   220,     1,   222,     1,
     222,   208,   208,     1,   232,   270,   269,   232,   280,   232,
     202,   230,   256,   232,   264,   227,   216,   227,   232,   236,
     227,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      41,    45,    46,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    64,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    81,    82,    83,    84,
      85,   171,   172,   210,   212,   217,   235,   300,   305,   308,
     309,   310,   311,   312,   313,   321,   208,   210,   211,   284,
     284,   308,   284,   284,   308,   308,   308,   284,   284,   204,
     255,   100,   224,   225,   226,   227,   234,   266,   267,   267,
       1,   211,   272,   223,   255,     1,   210,   210,   211,   210,
     220,   208,   210,     1,   219,     1,   219,   219,   219,   219,
     219,     1,   219,     1,   219,     1,   219,     1,   219,     1,
     219,     1,   219,     1,   219,     1,   219,   219,   219,   219,
       1,   219,     1,   219,     1,   219,     1,   219,   219,     1,
     219,   219,   219,   219,   219,   219,   206,   219,   220,   222,
     260,   294,   300,   301,   302,   305,   306,   310,   321,   219,
     294,   219,     1,   219,     1,   219,     1,   219,     1,   219,
       1,   219,     1,   219,     1,   219,     1,   219,     1,   219,
       1,   219,     1,   219,     1,   219,     1,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,     1,   219,   176,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   303,   217,     1,
     221,   309,     1,   217,   223,   223,   221,   223,   223,   221,
     221,   221,   216,   223,   232,   232,   210,   255,   265,   208,
     208,   210,   267,   272,   232,   216,   206,   219,   273,   274,
     238,     1,   211,   218,     1,   211,   218,   294,   218,   218,
     260,   300,     1,   211,   260,     1,   211,     1,   284,     1,
     211,     1,   211,     1,   211,     1,   208,     1,   208,   211,
     218,   208,   300,   211,   300,     1,   211,     1,   211,     1,
     211,     1,   211,   218,     1,   211,   218,   218,   218,   218,
       1,   208,   218,   294,   294,   221,   308,   207,   211,   219,
     260,   300,   302,   304,   321,   194,   195,   220,   307,   309,
     177,   178,   179,   180,   181,   182,   183,   184,   295,   296,
     297,   298,   299,   300,   307,   300,     1,   255,     1,   208,
     211,     1,   261,     1,   208,     1,   218,     1,   211,     1,
     211,   208,   210,   208,   210,   208,   210,   208,   210,   208,
     210,   208,   210,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   283,   211,   283,   211,   211,   211,   300,   208,
     218,   210,   320,   320,     1,   211,   216,   218,   260,   300,
     318,    66,    66,   304,   220,   220,   220,   220,   208,   220,
     208,   233,   259,     1,   259,   232,     1,   259,   211,   260,
     219,   233,   258,   271,     1,   216,   221,   208,   218,   218,
     218,   216,   218,   216,   218,   218,   218,   218,   216,   218,
     216,   218,   216,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   216,   218,   218,   218,   216,   216,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   221,   304,   304,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   223,   294,   294,   221,
     308,    40,    66,   215,   278,   282,   260,   211,   300,   218,
      47,   218,   218,   218,   218,   218,   218,   218,   218,   216,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   216,   218,   218,   216,   218,   218,   216,   218,
     218,   216,   218,   216,   216,   216,   216,   216,   216,   216,
     211,   218,   211,   218,   216,   218,   218,   216,   218,   216,
     216,   216,   216,     1,   219,   216,   216,   218,   218,   211,
     260,   300,   216,   218,   308,   308,   308,   308,   223,   308,
       1,   259,   218,   218,   271,   216,   273,   205,   211,   211,
     211,   211,    66,   211,   260,   300,   319,   211,   211,   211,
     218,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   221,   307,   220,   300,   208,   208,   210,   208,   210,
     208,   210,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   283,   300,   211,   211,   300,   211,     1,   218,   318,
     284,   284,   211,   260,   300,   221,   221,   221,   221,   220,
     221,   216,   282,    46,   218,   218,   218,   218,   216,   218,
     218,   218,   218,    42,   314,   315,   316,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   216,   216,   216,   218,
     216,   216,   216,   218,   218,   218,   216,   218,   216,   218,
     216,   218,   216,   218,   218,   218,   218,   218,   308,   282,
     216,   208,    66,   211,   260,   300,   211,   260,   221,    43,
     316,   317,   307,   211,   300,   300,   208,   300,   208,   300,
     211,   300,   208,   211,   211,   221,   216,   259,   239,   240,
     232,   232,   232,   216,   218,   218,   218,   216,   216,   216,
     216,   218,   218,   218,   216,   218,   259,   216,   237,   208,
      44,   308,    44,   308,   308,   208,   300,   208,   208,   208,
     208,   211,   216,   211,   208,   237,   217,    44,   217,    44,
     218,   218,   216,   218,   216,   218,   216,   218,   216,   218,
     216,   211,   218,   238,   208,   217,   217,   300,   300,   300,
     300,   211,   218,   208,   238,   218,   218,   218,   218,   216,
     205,   208,   300,    46,   205,   218,   208,    46,   239,   208,
     239
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   242,   243,   244,   244,   244,   245,   245,   246,   245,
     247,   245,   248,   245,   249,   245,   250,   245,   251,   245,
     252,   245,   253,   245,   254,   245,   245,   255,   255,   255,
     256,   256,   257,   257,   257,   258,   259,   259,   260,   260,
     260,   261,   261,   261,   261,   262,   262,   263,   263,   263,
     263,   263,   264,   264,   265,   265,   265,   266,   266,   266,
     266,   266,   266,   267,   267,   268,   268,   269,   268,   270,
     268,   271,   271,   272,   272,   273,   273,   274,   274,   274,
     275,   275,   275,   275,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   277,   277,   277,   277,   277,   278,   278,
     279,   280,   281,   281,   282,   282,   283,   283,   284,   284,
     284,   285,   285,   285,   286,   286,   287,   287,   287,   288,
     288,   289,   289,   290,   290,   291,   291,   292,   292,   293,
     293,   294,   294,   294,   294,   294,   294,   295,   295,   296,
     296,   296,   296,   297,   297,   298,   298,   299,   299,   299,
     300,   300,   301,   301,   301,   301,   302,   302,   302,   302,
     302,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   305,   305,
     305,   306,   306,   306,   306,   306,   307,   307,   307,   308,
     308,   308,   309,   309,   309,   309,   309,   309,   309,   309,
     310,   310,   311,   312,   313,   314,   314,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   317,   317,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     319,   319,   319,   319,   319,   319,   319,   319,   320,   320,
     320,   320,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     2,
       2,     3,     5,     5,     2,     3,     5,     1,     3,     5,
       5,     1,     1,     2,     1,     3,     3,     1,     2,     2,
       2,     2,     2,     1,     2,     1,     1,     0,     3,     0,
       3,     1,     1,     1,     2,     9,    10,     3,     1,     2,
      18,    17,    10,     9,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     5,     3,     3,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     2,     7,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     8,     8,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     1,
       1,     4,     7,     2,     7,     2,     4,     7,     2,     7,
       2,     4,     2,     4,     2,     4,     2,     9,     2,     7,
       2,     3,     3,     2,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     1,     1,     1,     3,     2,     1,     3,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     2,     1,     2,
       3,     5,     3,     7,     7,     2,     1,     2,     1,     6,
       5,     4,     3,     6,     5,     4,     3,     3,     2,     1,
       3,     1,     2,     2,     1,     2,     3,     1,     2,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     4,
       4,     2,     4,     3,     2,     4,     4,     6,     2,     4,
       6,     3,     1,     3,     1,     4,     4,     3,     1,     4,
       6,     2,     4,     4,     4,     2,     4,     4,     2,     4,
       4,     2,     6,     6,     4,     4,     2,     6,     6,     4,
       4,     2,     6,     6,     4,     4,     2,     6,     2,     4,
       4,     6,     2,     4,     4,     2,     4,     4,     2,     4,
       4,     2,     4,     4,     2,     4,     6,     4,     3,     1,
       4,     4,     6,     6,     4,     2,     4,     4,     2,     4,
       4,     2,     4,     4,     2,     4,     4,     2,     4,     3,
       1,     4,     2,     4,     3,     1,     3,     1,     3,     1,
       3,     1,     4,     3,     1,     4,     4,     4,     2,     4,
       4,     4,     2,     4,     4,     2,     4,     6,     4,     2,
       3,     4,     2,     4,     4,     2,     4,     4,     2,     8,
      10,    10,     6,     8,     8,    10,    10,    12,    12,    10,
      10,    12,    12,     8,     6,     3,     4,     4,     2,     4,
       4,     4,     4,     6,     6,     4,     6,     8,     6,     8,
      14,     6,     3,     6,     8,     6,     6,     4,     4,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 3:
#line 524 "cfg.y"
                                     {}
#line 3341 "cfg.tab.c"
    break;

  case 4:
#line 525 "cfg.y"
                            {}
#line 3347 "cfg.tab.c"
    break;

  case 5:
#line 526 "cfg.y"
                                   { yyerror(""); YYABORT;}
#line 3353 "cfg.tab.c"
    break;

  case 8:
#line 531 "cfg.y"
                  {rt=REQUEST_ROUTE;}
#line 3359 "cfg.tab.c"
    break;

  case 10:
#line 532 "cfg.y"
                  {rt=FAILURE_ROUTE;}
#line 3365 "cfg.tab.c"
    break;

  case 12:
#line 533 "cfg.y"
                  {rt=ONREPLY_ROUTE;}
#line 3371 "cfg.tab.c"
    break;

  case 14:
#line 534 "cfg.y"
                  {rt=BRANCH_ROUTE;}
#line 3377 "cfg.tab.c"
    break;

  case 16:
#line 535 "cfg.y"
                  {rt=ERROR_ROUTE;}
#line 3383 "cfg.tab.c"
    break;

  case 18:
#line 536 "cfg.y"
                  {rt=LOCAL_ROUTE;}
#line 3389 "cfg.tab.c"
    break;

  case 20:
#line 537 "cfg.y"
                  {rt=STARTUP_ROUTE;}
#line 3395 "cfg.tab.c"
    break;

  case 22:
#line 538 "cfg.y"
                  {rt=TIMER_ROUTE;}
#line 3401 "cfg.tab.c"
    break;

  case 24:
#line 539 "cfg.y"
                  {rt=EVENT_ROUTE;}
#line 3407 "cfg.tab.c"
    break;

  case 27:
#line 544 "cfg.y"
                                        {
							tmp=ip_addr2a((yyvsp[0].ipaddr));
							if(tmp==0){
								LM_CRIT("cfg. parser: bad ip address.\n");
								(yyval.strval)=0;
							}else{
								(yyval.strval)=pkg_malloc(strlen(tmp)+1);
								if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
									YYABORT;
								}else{
									memcpy((yyval.strval), tmp, strlen(tmp)+1);
								}
							}
						}
#line 3427 "cfg.tab.c"
    break;

  case 28:
#line 559 "cfg.y"
                                        {
							(yyval.strval)=pkg_malloc(strlen((yyvsp[0].strval))+1);
							if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
									YYABORT;
							}else{
									memcpy((yyval.strval), (yyvsp[0].strval), strlen((yyvsp[0].strval))+1);
							}
						}
#line 3441 "cfg.tab.c"
    break;

  case 29:
#line 568 "cfg.y"
                                        {
							if ((yyvsp[0].strval)==0) {
								(yyval.strval) = 0;
							} else {
								(yyval.strval)=pkg_malloc(strlen((yyvsp[0].strval))+1);
								if ((yyval.strval)==0){
									LM_CRIT("cfg. parser: out of memory.\n");
									YYABORT;
								}else{
									memcpy((yyval.strval), (yyvsp[0].strval), strlen((yyvsp[0].strval))+1);
								}
							}
						}
#line 3459 "cfg.tab.c"
    break;

  case 30:
#line 583 "cfg.y"
                    {(yyval.strval)=".";}
#line 3465 "cfg.tab.c"
    break;

  case 31:
#line 584 "cfg.y"
                              {(yyval.strval)="-"; }
#line 3471 "cfg.tab.c"
    break;

  case 32:
#line 587 "cfg.y"
                                        { (yyval.strval)=(yyvsp[0].strval); }
#line 3477 "cfg.tab.c"
    break;

  case 33:
#line 588 "cfg.y"
                                { IFOR();
						(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
						if ((yyval.strval)==0){
							LM_CRIT("cfg. parser: memory allocation"
										" failure while parsing host\n");
							YYABORT;
						}else{
							memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
							(yyval.strval)[strlen((yyvsp[-2].strval))]=*(yyvsp[-1].strval);
							memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
							(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
						}
						pkg_free((yyvsp[-2].strval)); pkg_free((yyvsp[0].strval));
					}
#line 3496 "cfg.tab.c"
    break;

  case 34:
#line 602 "cfg.y"
                         { (yyval.strval)=0; pkg_free((yyvsp[-2].strval));
					yyerror("invalid hostname (use quotes if hostname "
						"has config keywords)"); }
#line 3504 "cfg.tab.c"
    break;

  case 35:
#line 607 "cfg.y"
           {
		if (parse_proto((unsigned char *)(yyvsp[0].strval), strlen((yyvsp[0].strval)), &i_tmp) < 0) {
			yyerrorf("cannot handle protocol <%s>\n", (yyvsp[0].strval));
			YYABORT;
		}
		pkg_free((yyvsp[0].strval));
		(yyval.intval) = i_tmp;
	 }
#line 3517 "cfg.tab.c"
    break;

  case 36:
#line 617 "cfg.y"
                        { (yyval.intval)=(yyvsp[0].intval); }
#line 3523 "cfg.tab.c"
    break;

  case 37:
#line 618 "cfg.y"
                                { (yyval.intval)=0; }
#line 3529 "cfg.tab.c"
    break;

  case 38:
#line 621 "cfg.y"
                        { (yyval.intval)=(yyvsp[0].intval); }
#line 3535 "cfg.tab.c"
    break;

  case 39:
#line 622 "cfg.y"
                                { (yyval.intval)=(yyvsp[0].intval); }
#line 3541 "cfg.tab.c"
    break;

  case 40:
#line 623 "cfg.y"
                                { (yyval.intval)=-(yyvsp[0].intval); }
#line 3547 "cfg.tab.c"
    break;

  case 41:
#line 627 "cfg.y"
                                        {
				(yyval.sockid)=mk_listen_id((yyvsp[0].strval), (yyvsp[-2].intval), 0); }
#line 3554 "cfg.tab.c"
    break;

  case 42:
#line 629 "cfg.y"
                                                                {
				(yyval.sockid)=mk_listen_id((yyvsp[-2].strval), (yyvsp[-4].intval), (yyvsp[0].intval));}
#line 3561 "cfg.tab.c"
    break;

  case 43:
#line 631 "cfg.y"
                                                            {
				(yyval.sockid)=0;
				yyerror("port number expected");
				YYABORT;
				}
#line 3571 "cfg.tab.c"
    break;

  case 44:
#line 636 "cfg.y"
                                       { (yyval.sockid)=0;
				yyerror("protocol expected");
				YYABORT;
			}
#line 3580 "cfg.tab.c"
    break;

  case 45:
#line 642 "cfg.y"
                                                        { IFOR();
				(yyval.sockid)=mk_listen_id(0, (yyvsp[-2].intval), 0); }
#line 3587 "cfg.tab.c"
    break;

  case 46:
#line 644 "cfg.y"
                                                        { IFOR();
				(yyval.sockid)=mk_listen_id(0, (yyvsp[-4].intval), (yyvsp[0].intval)); }
#line 3594 "cfg.tab.c"
    break;

  case 47:
#line 648 "cfg.y"
                                                                        { IFOR(pkg_free((yyvsp[0].strval)));
				(yyval.sockid)=mk_listen_id((yyvsp[0].strval), PROTO_NONE, 0); }
#line 3601 "cfg.tab.c"
    break;

  case 48:
#line 650 "cfg.y"
                                                                        { IFOR(pkg_free((yyvsp[0].strval)));
		 		(yyval.sockid)=mk_listen_id((yyvsp[0].strval), PROTO_NONE, 0); }
#line 3608 "cfg.tab.c"
    break;

  case 49:
#line 652 "cfg.y"
                                                        { IFOR(pkg_free((yyvsp[-2].strval)));
		 		(yyval.sockid)=mk_listen_id((yyvsp[-2].strval), PROTO_NONE, (yyvsp[0].intval)); }
#line 3615 "cfg.tab.c"
    break;

  case 50:
#line 654 "cfg.y"
                                                        {
				(yyval.sockid)=0;
				yyerror(" port number expected");
				}
#line 3624 "cfg.tab.c"
    break;

  case 51:
#line 658 "cfg.y"
                             {IFOR(pkg_free((yyvsp[0].sockid)->name);pkg_free((yyvsp[0].sockid)))}
#line 3630 "cfg.tab.c"
    break;

  case 52:
#line 661 "cfg.y"
                                        { IFOR();  (yyval.sockid)=(yyvsp[0].sockid) ; }
#line 3636 "cfg.tab.c"
    break;

  case 53:
#line 662 "cfg.y"
                                        { IFOR(); (yyval.sockid)=(yyvsp[-1].sockid); (yyval.sockid)->next=(yyvsp[0].sockid); }
#line 3642 "cfg.tab.c"
    break;

  case 54:
#line 665 "cfg.y"
                                                                { IFOR(pkg_free((yyvsp[0].strval)));
					(yyval.sockid)=mk_listen_id((yyvsp[0].strval), PROTO_NONE, 0); }
#line 3649 "cfg.tab.c"
    break;

  case 55:
#line 667 "cfg.y"
                                                                { IFOR(pkg_free((yyvsp[-2].strval)));
			 		(yyval.sockid)=mk_listen_id((yyvsp[-2].strval), PROTO_NONE, (yyvsp[0].intval)); }
#line 3656 "cfg.tab.c"
    break;

  case 56:
#line 669 "cfg.y"
                                                      {
					(yyval.sockid)=0;
					yyerror(" port number expected");
					}
#line 3665 "cfg.tab.c"
    break;

  case 57:
#line 675 "cfg.y"
                          { IFOR();
					p_tmp.flags |= SI_IS_ANYCAST;
					}
#line 3673 "cfg.tab.c"
    break;

  case 58:
#line 678 "cfg.y"
                                                      { IFOR();
					warn("'USE_CHILDREN' syntax is deprecated, use "
						"'USE_WORKERS' instead");
					p_tmp.workers=(yyvsp[0].intval);
					}
#line 3683 "cfg.tab.c"
    break;

  case 59:
#line 683 "cfg.y"
                                                     { IFOR();
					p_tmp.workers=(yyvsp[0].intval);
					}
#line 3691 "cfg.tab.c"
    break;

  case 60:
#line 686 "cfg.y"
                                                   { IFOR();
					p_tmp.socket = (yyvsp[0].sockid);
					}
#line 3699 "cfg.tab.c"
    break;

  case 61:
#line 689 "cfg.y"
                                         { IFOR();
					p_tmp.tag = (yyvsp[0].strval);
					}
#line 3707 "cfg.tab.c"
    break;

  case 62:
#line 692 "cfg.y"
                                                              { IFOR();
					p_tmp.auto_scaling_profile=(yyvsp[0].strval);
					}
#line 3715 "cfg.tab.c"
    break;

  case 65:
#line 701 "cfg.y"
                                                { (yyval.sockid)=(yyvsp[0].sockid); }
#line 3721 "cfg.tab.c"
    break;

  case 66:
#line 702 "cfg.y"
                                                                {IFOR(pkg_free((yyvsp[0].sockid)->name);pkg_free((yyvsp[0].sockid)));
				(yyval.sockid)=(yyvsp[0].sockid); }
#line 3728 "cfg.tab.c"
    break;

  case 67:
#line 704 "cfg.y"
                                       { IFOR();
					memset(&p_tmp, 0, sizeof(p_tmp));
				}
#line 3736 "cfg.tab.c"
    break;

  case 68:
#line 706 "cfg.y"
                                                        { IFOR();
					(yyval.sockid)=(yyvsp[-2].sockid); fill_socket_id(&p_tmp, (yyval.sockid));
				}
#line 3744 "cfg.tab.c"
    break;

  case 69:
#line 709 "cfg.y"
                                    { IFOR(pkg_free((yyvsp[0].sockid)->name);pkg_free((yyvsp[0].sockid)));
					memset(&p_tmp, 0, sizeof(p_tmp));
				}
#line 3752 "cfg.tab.c"
    break;

  case 70:
#line 711 "cfg.y"
                                                        { IFOR();
					(yyval.sockid)=(yyvsp[-2].sockid); fill_socket_id(&p_tmp, (yyval.sockid));
				}
#line 3760 "cfg.tab.c"
    break;

  case 71:
#line 716 "cfg.y"
                        { (yyval.intval)=PROTO_NONE; }
#line 3766 "cfg.tab.c"
    break;

  case 72:
#line 717 "cfg.y"
                                { (yyval.intval)=(yyvsp[0].intval); }
#line 3772 "cfg.tab.c"
    break;

  case 73:
#line 719 "cfg.y"
                       {  IFOR(); (yyval.multistr)=new_string((yyvsp[0].strval)); }
#line 3778 "cfg.tab.c"
    break;

  case 74:
#line 720 "cfg.y"
                                      { IFOR(); (yyval.multistr)=new_string((yyvsp[-1].strval)); (yyval.multistr)->next=(yyvsp[0].multistr); }
#line 3784 "cfg.tab.c"
    break;

  case 75:
#line 723 "cfg.y"
                                                                        {
				IFOR(pkg_free((yyvsp[-5].ipnet)));
				s_tmp.s=(yyvsp[-1].strval);
				s_tmp.len=strlen((yyvsp[-1].strval));
				if (add_rule_to_list(&bl_head,&bl_tail,(yyvsp[-5].ipnet),&s_tmp,(yyvsp[-3].intval),(yyvsp[-7].intval),0)) {
					yyerror("failed to add backlist element\n");YYABORT;
				}
			}
#line 3797 "cfg.tab.c"
    break;

  case 76:
#line 731 "cfg.y"
                                                                                    {
				IFOR(pkg_free((yyvsp[-5].ipnet)));
				s_tmp.s=(yyvsp[-1].strval);
				s_tmp.len=strlen((yyvsp[-1].strval));
				if (add_rule_to_list(&bl_head,&bl_tail,(yyvsp[-5].ipnet),&s_tmp,
				(yyvsp[-3].intval),(yyvsp[-7].intval),BLR_APPLY_CONTRARY)) {
					yyerror("failed to add backlist element\n");YYABORT;
				}
			}
#line 3811 "cfg.tab.c"
    break;

  case 77:
#line 742 "cfg.y"
                                               {}
#line 3817 "cfg.tab.c"
    break;

  case 78:
#line 743 "cfg.y"
                            {}
#line 3823 "cfg.tab.c"
    break;

  case 79:
#line 744 "cfg.y"
                                       { yyerror("bad black list element");}
#line 3829 "cfg.tab.c"
    break;

  case 80:
#line 751 "cfg.y"
                                              { IFOR();
			if (create_auto_scaling_profile((yyvsp[-17].strval),(yyvsp[-15].intval),(yyvsp[-13].intval),(yyvsp[-10].intval),(yyvsp[-8].intval),
			(yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-1].intval),10*(yyvsp[-1].intval))<0)
				yyerror("failed to create auto scaling profile");
		 }
#line 3839 "cfg.tab.c"
    break;

  case 81:
#line 759 "cfg.y"
                                              { IFOR();
			if (create_auto_scaling_profile((yyvsp[-16].strval),(yyvsp[-14].intval),(yyvsp[-12].intval),(yyvsp[-9].intval),(yyvsp[-9].intval),
			(yyvsp[-6].intval), (yyvsp[-4].intval), (yyvsp[-1].intval), 10*(yyvsp[-1].intval))<0)
				yyerror("failed to create auto scaling profile");
		 }
#line 3849 "cfg.tab.c"
    break;

  case 82:
#line 765 "cfg.y"
                                                            { IFOR();
			if (create_auto_scaling_profile((yyvsp[-9].strval),(yyvsp[-7].intval),(yyvsp[-5].intval),(yyvsp[-2].intval),(yyvsp[0].intval),
			0, 0, 0, 0)<0)
				yyerror("failed to create auto scaling profile");
		}
#line 3859 "cfg.tab.c"
    break;

  case 83:
#line 771 "cfg.y"
                                              { IFOR();
			if (create_auto_scaling_profile((yyvsp[-8].strval),(yyvsp[-6].intval),(yyvsp[-4].intval),(yyvsp[-1].intval),(yyvsp[-1].intval),
			0, 0, 0, 0)<0)
				yyerror("failed to create auto scaling profile");
		}
#line 3869 "cfg.tab.c"
    break;

  case 84:
#line 779 "cfg.y"
                        { yyerror("\'debug\' is deprecated, use \'log_level\' instead\n");}
#line 3875 "cfg.tab.c"
    break;

  case 85:
#line 781 "cfg.y"
                        {yyerror("fork is deprecated, use debug_mode\n");}
#line 3881 "cfg.tab.c"
    break;

  case 86:
#line 782 "cfg.y"
                                         { IFOR();
			/* in debug mode, force logging to DEBUG level*/
			*log_level = debug_mode?L_DBG:(yyvsp[0].intval);
			}
#line 3890 "cfg.tab.c"
    break;

  case 87:
#line 786 "cfg.y"
                                               { IFOR(); enable_asserts=(yyvsp[0].intval); }
#line 3896 "cfg.tab.c"
    break;

  case 88:
#line 787 "cfg.y"
                                              { yyerror("boolean value expected"); }
#line 3902 "cfg.tab.c"
    break;

  case 89:
#line 788 "cfg.y"
                                                { IFOR(); abort_on_assert=(yyvsp[0].intval); }
#line 3908 "cfg.tab.c"
    break;

  case 90:
#line 789 "cfg.y"
                                               { yyerror("boolean value expected"); }
#line 3914 "cfg.tab.c"
    break;

  case 91:
#line 790 "cfg.y"
                                           { IFOR();
			debug_mode=(yyvsp[0].intval);
			if (debug_mode) { *log_level = L_DBG;log_stderr=1;}
			}
#line 3923 "cfg.tab.c"
    break;

  case 92:
#line 795 "cfg.y"
                        { yyerror("boolean value expected for debug_mode"); }
#line 3929 "cfg.tab.c"
    break;

  case 93:
#line 799 "cfg.y"
                        { IFOR(); if (!config_check && !debug_mode) log_stderr=(yyvsp[0].intval); }
#line 3935 "cfg.tab.c"
    break;

  case 94:
#line 800 "cfg.y"
                                          { yyerror("boolean value expected"); }
#line 3941 "cfg.tab.c"
    break;

  case 95:
#line 801 "cfg.y"
                                       { IFOR();
			if ( (i_tmp=str2facility((yyvsp[0].strval)))==-1)
				yyerror("bad facility (see syslog(3) man page)");
			if (!config_check)
				log_facility=i_tmp;
			}
#line 3952 "cfg.tab.c"
    break;

  case 96:
#line 807 "cfg.y"
                                          { yyerror("ID expected"); }
#line 3958 "cfg.tab.c"
    break;

  case 97:
#line 808 "cfg.y"
                                       { IFOR(); log_name=(yyvsp[0].strval); }
#line 3964 "cfg.tab.c"
    break;

  case 98:
#line 809 "cfg.y"
                                      { yyerror("string value expected"); }
#line 3970 "cfg.tab.c"
    break;

  case 99:
#line 810 "cfg.y"
                                     { IFOR(); received_dns|= ((yyvsp[0].intval))?DO_DNS:0; }
#line 3976 "cfg.tab.c"
    break;

  case 100:
#line 811 "cfg.y"
                                  { yyerror("boolean value expected"); }
#line 3982 "cfg.tab.c"
    break;

  case 101:
#line 812 "cfg.y"
                                       { IFOR(); received_dns|= ((yyvsp[0].intval))?DO_REV_DNS:0; }
#line 3988 "cfg.tab.c"
    break;

  case 102:
#line 813 "cfg.y"
                                      { yyerror("boolean value expected"); }
#line 3994 "cfg.tab.c"
    break;

  case 103:
#line 814 "cfg.y"
                                              { IFOR(); dns_try_ipv6=(yyvsp[0].intval); }
#line 4000 "cfg.tab.c"
    break;

  case 104:
#line 815 "cfg.y"
                                     { yyerror("boolean value expected"); }
#line 4006 "cfg.tab.c"
    break;

  case 105:
#line 816 "cfg.y"
                                               { IFOR(); dns_try_naptr=(yyvsp[0].intval); }
#line 4012 "cfg.tab.c"
    break;

  case 106:
#line 817 "cfg.y"
                                      { yyerror("boolean value expected"); }
#line 4018 "cfg.tab.c"
    break;

  case 107:
#line 818 "cfg.y"
                                               { IFOR(); dns_retr_time=(yyvsp[0].intval); }
#line 4024 "cfg.tab.c"
    break;

  case 108:
#line 819 "cfg.y"
                                      { yyerror("number expected"); }
#line 4030 "cfg.tab.c"
    break;

  case 109:
#line 820 "cfg.y"
                                             { IFOR(); dns_retr_no=(yyvsp[0].intval); }
#line 4036 "cfg.tab.c"
    break;

  case 110:
#line 821 "cfg.y"
                                    { yyerror("number expected"); }
#line 4042 "cfg.tab.c"
    break;

  case 111:
#line 822 "cfg.y"
                                                { IFOR(); dns_servers_no=(yyvsp[0].intval); }
#line 4048 "cfg.tab.c"
    break;

  case 112:
#line 823 "cfg.y"
                                       { yyerror("number expected"); }
#line 4054 "cfg.tab.c"
    break;

  case 113:
#line 824 "cfg.y"
                                                { IFOR(); dns_search_list=(yyvsp[0].intval); }
#line 4060 "cfg.tab.c"
    break;

  case 114:
#line 825 "cfg.y"
                                       { yyerror("boolean value expected"); }
#line 4066 "cfg.tab.c"
    break;

  case 115:
#line 826 "cfg.y"
                                               { IFOR(); max_while_loops=(yyvsp[0].intval); }
#line 4072 "cfg.tab.c"
    break;

  case 116:
#line 827 "cfg.y"
                                              { yyerror("number expected"); }
#line 4078 "cfg.tab.c"
    break;

  case 117:
#line 828 "cfg.y"
                                         { IFOR(); maxbuffer=(yyvsp[0].intval); }
#line 4084 "cfg.tab.c"
    break;

  case 118:
#line 829 "cfg.y"
                                        { yyerror("number expected"); }
#line 4090 "cfg.tab.c"
    break;

  case 119:
#line 830 "cfg.y"
                                        { IFOR();
			warn("'children' option is deprecated, "
				"use 'udp_workers' instead");
			udp_workers_no=(yyvsp[0].intval); }
#line 4099 "cfg.tab.c"
    break;

  case 120:
#line 834 "cfg.y"
                                       { yyerror("number expected"); }
#line 4105 "cfg.tab.c"
    break;

  case 121:
#line 835 "cfg.y"
                                           { IFOR(); udp_workers_no=(yyvsp[0].intval); }
#line 4111 "cfg.tab.c"
    break;

  case 122:
#line 836 "cfg.y"
                                                                       { IFOR();
				udp_workers_no=(yyvsp[-2].intval);
				udp_auto_scaling_profile=(yyvsp[0].strval);
		}
#line 4120 "cfg.tab.c"
    break;

  case 123:
#line 840 "cfg.y"
                                          { yyerror("number expected"); }
#line 4126 "cfg.tab.c"
    break;

  case 124:
#line 841 "cfg.y"
                                             { IFOR();
				timer_workers_no=(yyvsp[0].intval);
		}
#line 4134 "cfg.tab.c"
    break;

  case 125:
#line 844 "cfg.y"
                                                                         { IFOR();
				timer_workers_no=(yyvsp[-2].intval);
				timer_auto_scaling_profile=(yyvsp[0].strval);
		}
#line 4143 "cfg.tab.c"
    break;

  case 126:
#line 848 "cfg.y"
                                         { check_via=(yyvsp[0].intval); }
#line 4149 "cfg.tab.c"
    break;

  case 127:
#line 849 "cfg.y"
                                        { yyerror("boolean value expected"); }
#line 4155 "cfg.tab.c"
    break;

  case 128:
#line 850 "cfg.y"
                                                         { IFOR();
			#ifdef HP_MALLOC
			shm_hash_split_percentage=(yyvsp[0].intval);
			#else
			LM_ERR("Cannot set parameter; Please recompile with support "
				"for HP_MALLOC\n");
			#endif
			}
#line 4168 "cfg.tab.c"
    break;

  case 129:
#line 858 "cfg.y"
                                                        {
			#ifdef HP_MALLOC
			yyerror("number expected");
			#else
			LM_ERR("Cannot set parameter; Please recompile with support "
				"for HP_MALLOC\n");
			#endif
				}
#line 4181 "cfg.tab.c"
    break;

  case 130:
#line 866 "cfg.y"
                                                       { IFOR();
			#ifdef HP_MALLOC
			shm_secondary_hash_size=(yyvsp[0].intval);
			#else
			LM_ERR("Cannot set parameter; Please recompile with support"
				" for HP_MALLOC\n");
			#endif
			}
#line 4194 "cfg.tab.c"
    break;

  case 131:
#line 874 "cfg.y"
                                                      {
			#ifdef HP_MALLOC
			yyerror("number expected");
			#else
			LM_ERR("Cannot set parameter; Please recompile with support "
				"for HP_MALLOC\n");
			#endif
			}
#line 4207 "cfg.tab.c"
    break;

  case 132:
#line 882 "cfg.y"
                                                   { IFOR();
			#ifdef HP_MALLOC
			mem_warming_enabled = (yyvsp[0].intval);
			#else
			LM_ERR("Cannot set parameter; Please recompile with support"
				" for HP_MALLOC\n");
			#endif
			}
#line 4220 "cfg.tab.c"
    break;

  case 133:
#line 890 "cfg.y"
                                                  {
			#ifdef HP_MALLOC
			yyerror("number expected");
			#else
			LM_ERR("Cannot set parameter; Please recompile with support "
				"for HP_MALLOC\n");
			#endif
			}
#line 4233 "cfg.tab.c"
    break;

  case 134:
#line 898 "cfg.y"
                                                        { IFOR();
			#ifdef HP_MALLOC
			mem_warming_pattern_file = (yyvsp[0].strval);
			#else
			LM_ERR("Cannot set parameter; Please recompile with "
				"support for HP_MALLOC\n");
			#endif
			}
#line 4246 "cfg.tab.c"
    break;

  case 135:
#line 906 "cfg.y"
                                                       {
			#ifdef HP_MALLOC
			yyerror("string expected");
			#else
			LM_ERR("Cannot set parameter; Please recompile with support "
				"for HP_MALLOC\n");
			#endif
			}
#line 4259 "cfg.tab.c"
    break;

  case 136:
#line 914 "cfg.y"
                                                      { IFOR();
			#ifdef HP_MALLOC
			mem_warming_percentage = (yyvsp[0].intval);
			#else
			LM_ERR("Cannot set parameter; Please recompile with "
				"support for HP_MALLOC\n");
			#endif
			}
#line 4272 "cfg.tab.c"
    break;

  case 137:
#line 922 "cfg.y"
                                                     {
			#ifdef HP_MALLOC
			yyerror("number expected");
			#else
			LM_ERR("Cannot set parameter; Please recompile with support "
				"for HP_MALLOC\n");
			#endif
			}
#line 4285 "cfg.tab.c"
    break;

  case 138:
#line 930 "cfg.y"
                                            { IFOR();
			rpm_mem_file = (yyvsp[0].strval);
			}
#line 4293 "cfg.tab.c"
    break;

  case 139:
#line 933 "cfg.y"
                                           { yyerror("string value expected"); }
#line 4299 "cfg.tab.c"
    break;

  case 140:
#line 934 "cfg.y"
                                            { IFOR();
			rpm_mem_size = (yyvsp[0].intval) * 1024 * 1024;
			}
#line 4307 "cfg.tab.c"
    break;

  case 141:
#line 937 "cfg.y"
                                           { yyerror("int value expected"); }
#line 4313 "cfg.tab.c"
    break;

  case 142:
#line 938 "cfg.y"
                                       { IFOR(); memlog=(yyvsp[0].intval); memdump=(yyvsp[0].intval); }
#line 4319 "cfg.tab.c"
    break;

  case 143:
#line 939 "cfg.y"
                                     { yyerror("int value expected"); }
#line 4325 "cfg.tab.c"
    break;

  case 144:
#line 940 "cfg.y"
                                        { IFOR(); memdump=(yyvsp[0].intval); }
#line 4331 "cfg.tab.c"
    break;

  case 145:
#line 941 "cfg.y"
                                      { yyerror("int value expected"); }
#line 4337 "cfg.tab.c"
    break;

  case 146:
#line 942 "cfg.y"
                                                {  IFOR();execmsgthreshold=(yyvsp[0].intval); }
#line 4343 "cfg.tab.c"
    break;

  case 147:
#line 943 "cfg.y"
                                               { yyerror("int value expected"); }
#line 4349 "cfg.tab.c"
    break;

  case 148:
#line 944 "cfg.y"
                                                { IFOR(); execdnsthreshold=(yyvsp[0].intval); }
#line 4355 "cfg.tab.c"
    break;

  case 149:
#line 945 "cfg.y"
                                               { yyerror("int value expected"); }
#line 4361 "cfg.tab.c"
    break;

  case 150:
#line 946 "cfg.y"
                                            { IFOR(); tcpthreshold=(yyvsp[0].intval); }
#line 4367 "cfg.tab.c"
    break;

  case 151:
#line 947 "cfg.y"
                                           { yyerror("int value expected"); }
#line 4373 "cfg.tab.c"
    break;

  case 152:
#line 948 "cfg.y"
                                                   { IFOR();
			#ifdef STATISTICS
			if ((yyvsp[0].intval) < 0 || (yyvsp[0].intval) > 100)
				yyerror("SHM threshold has to be a percentage between"
					" 0 and 100");
			event_shm_threshold=(yyvsp[0].intval);
			#else
			yyerror("statistics support not compiled in");
			#endif /* STATISTICS */
			}
#line 4388 "cfg.tab.c"
    break;

  case 153:
#line 958 "cfg.y"
                                                  { yyerror("int value expected"); }
#line 4394 "cfg.tab.c"
    break;

  case 154:
#line 959 "cfg.y"
                                                   { IFOR();
			#ifdef PKG_MALLOC
			#ifdef STATISTICS
			if ((yyvsp[0].intval) < 0 || (yyvsp[0].intval) > 100)
				yyerror("PKG threshold has to be a percentage between "
					"0 and 100");
			event_pkg_threshold=(yyvsp[0].intval);
			#else
			yyerror("statistics support not compiled in");
			#endif
			#else
			yyerror("pkg_malloc support not compiled in");
			#endif
			}
#line 4413 "cfg.tab.c"
    break;

  case 155:
#line 973 "cfg.y"
                                                  { yyerror("int value expected"); }
#line 4419 "cfg.tab.c"
    break;

  case 156:
#line 974 "cfg.y"
                                               { IFOR(); query_buffer_size=(yyvsp[0].intval); }
#line 4425 "cfg.tab.c"
    break;

  case 157:
#line 975 "cfg.y"
                                              { yyerror("int value expected"); }
#line 4431 "cfg.tab.c"
    break;

  case 158:
#line 976 "cfg.y"
                                              { IFOR(); query_flush_time=(yyvsp[0].intval); }
#line 4437 "cfg.tab.c"
    break;

  case 159:
#line 977 "cfg.y"
                                             { yyerror("int value expected"); }
#line 4443 "cfg.tab.c"
    break;

  case 160:
#line 978 "cfg.y"
                                           { IFOR(); sip_warning=(yyvsp[0].intval); }
#line 4449 "cfg.tab.c"
    break;

  case 161:
#line 979 "cfg.y"
                                          { yyerror("boolean value expected"); }
#line 4455 "cfg.tab.c"
    break;

  case 162:
#line 980 "cfg.y"
                                          { IFOR(); chroot_dir=(yyvsp[0].strval); }
#line 4461 "cfg.tab.c"
    break;

  case 163:
#line 981 "cfg.y"
                                          { IFOR(); chroot_dir=(yyvsp[0].strval); }
#line 4467 "cfg.tab.c"
    break;

  case 164:
#line 982 "cfg.y"
                                          { yyerror("string value expected"); }
#line 4473 "cfg.tab.c"
    break;

  case 165:
#line 983 "cfg.y"
                                        { IFOR(); working_dir=(yyvsp[0].strval); }
#line 4479 "cfg.tab.c"
    break;

  case 166:
#line 984 "cfg.y"
                                        { IFOR(); working_dir=(yyvsp[0].strval); }
#line 4485 "cfg.tab.c"
    break;

  case 167:
#line 985 "cfg.y"
                                        { yyerror("string value expected"); }
#line 4491 "cfg.tab.c"
    break;

  case 168:
#line 986 "cfg.y"
                                      { IFOR(); mhomed=(yyvsp[0].intval); }
#line 4497 "cfg.tab.c"
    break;

  case 169:
#line 987 "cfg.y"
                                     { yyerror("boolean value expected"); }
#line 4503 "cfg.tab.c"
    break;

  case 170:
#line 988 "cfg.y"
                                       { IFOR();
									io_poll_method=get_poll_type((yyvsp[0].strval));
									if (io_poll_method==POLL_NONE){
										LM_CRIT("bad poll method name:"
											" %s\n, try one of %s.\n",
											(yyvsp[0].strval), poll_support);
										yyerror("bad poll_method "
											"value");
									}
								}
#line 4518 "cfg.tab.c"
    break;

  case 171:
#line 998 "cfg.y"
                                           { IFOR();
									io_poll_method=get_poll_type((yyvsp[0].strval));
									if (io_poll_method==POLL_NONE){
										LM_CRIT("bad poll method name:"
											" %s\n, try one of %s.\n",
											(yyvsp[0].strval), poll_support);
										yyerror("bad poll_method "
											"value");
									}
									}
#line 4533 "cfg.tab.c"
    break;

  case 172:
#line 1008 "cfg.y"
                                          { yyerror("poll method name expected"); }
#line 4539 "cfg.tab.c"
    break;

  case 173:
#line 1009 "cfg.y"
                                                  { IFOR();
				tcp_accept_aliases=(yyvsp[0].intval);
		}
#line 4547 "cfg.tab.c"
    break;

  case 174:
#line 1012 "cfg.y"
                                                 { yyerror("boolean value expected"); }
#line 4553 "cfg.tab.c"
    break;

  case 175:
#line 1013 "cfg.y"
                                            { IFOR();
				warn("'tcp_children' option is deprecated, "
					"use 'tcp_workers' instead");
				tcp_workers_no=(yyvsp[0].intval);
		}
#line 4563 "cfg.tab.c"
    break;

  case 176:
#line 1018 "cfg.y"
                                           { yyerror("number expected"); }
#line 4569 "cfg.tab.c"
    break;

  case 177:
#line 1019 "cfg.y"
                                           { IFOR();
				tcp_workers_no=(yyvsp[0].intval);
		}
#line 4577 "cfg.tab.c"
    break;

  case 178:
#line 1022 "cfg.y"
                                                                      { IFOR();
				tcp_workers_no=(yyvsp[-2].intval);
				tcp_auto_scaling_profile=(yyvsp[0].strval);
		}
#line 4586 "cfg.tab.c"
    break;

  case 179:
#line 1026 "cfg.y"
                                          { yyerror("number expected"); }
#line 4592 "cfg.tab.c"
    break;

  case 180:
#line 1027 "cfg.y"
                                                   { IFOR();
				tcp_connect_timeout=(yyvsp[0].intval);
		}
#line 4600 "cfg.tab.c"
    break;

  case 181:
#line 1030 "cfg.y"
                                                  { yyerror("number expected"); }
#line 4606 "cfg.tab.c"
    break;

  case 182:
#line 1031 "cfg.y"
                                                { IFOR();
				tcp_con_lifetime=(yyvsp[0].intval);
		}
#line 4614 "cfg.tab.c"
    break;

  case 183:
#line 1034 "cfg.y"
                                               { yyerror("number expected"); }
#line 4620 "cfg.tab.c"
    break;

  case 184:
#line 1035 "cfg.y"
                                                  { IFOR();
				tcp_listen_backlog=(yyvsp[0].intval);
		}
#line 4628 "cfg.tab.c"
    break;

  case 185:
#line 1038 "cfg.y"
                                                 { yyerror("number expected"); }
#line 4634 "cfg.tab.c"
    break;

  case 186:
#line 1039 "cfg.y"
                                                   { IFOR();
				tcp_max_connections=(yyvsp[0].intval);
		}
#line 4642 "cfg.tab.c"
    break;

  case 187:
#line 1042 "cfg.y"
                                                  { yyerror("number expected"); }
#line 4648 "cfg.tab.c"
    break;

  case 188:
#line 1043 "cfg.y"
                                                     { IFOR();
				tmp = NULL;
				fix_flag_name(tmp, (yyvsp[0].intval));
				tcp_no_new_conn_bflag =
					get_flag_id_by_name(FLAG_TYPE_BRANCH, tmp);
				if (!flag_in_range( (flag_t)tcp_no_new_conn_bflag ) )
					yyerror("invalid TCP no_new_conn Branch Flag");
				flag_idx2mask( &tcp_no_new_conn_bflag );
		}
#line 4662 "cfg.tab.c"
    break;

  case 189:
#line 1052 "cfg.y"
                                                 { IFOR();
				tcp_no_new_conn_bflag =
					get_flag_id_by_name(FLAG_TYPE_BRANCH, (yyvsp[0].strval));
				if (!flag_in_range( (flag_t)tcp_no_new_conn_bflag ) )
					yyerror("invalid TCP no_new_conn Branch Flag");
				flag_idx2mask( &tcp_no_new_conn_bflag );
		}
#line 4674 "cfg.tab.c"
    break;

  case 190:
#line 1059 "cfg.y"
                                                    { yyerror("number value expected"); }
#line 4680 "cfg.tab.c"
    break;

  case 191:
#line 1060 "cfg.y"
                                                   { IFOR();
				tcp_no_new_conn_rplflag =
					get_flag_id_by_name(FLAG_TYPE_MSG, (yyvsp[0].strval));
				if (!flag_in_range( (flag_t)tcp_no_new_conn_rplflag ) )
					yyerror("invalid TCP no_new_conn RePLy Flag");
				flag_idx2mask( &tcp_no_new_conn_rplflag );
		}
#line 4692 "cfg.tab.c"
    break;

  case 192:
#line 1067 "cfg.y"
                                                      { yyerror("number value expected"); }
#line 4698 "cfg.tab.c"
    break;

  case 193:
#line 1069 "cfg.y"
                                             { IFOR();
				tcp_keepalive=(yyvsp[0].intval);
		}
#line 4706 "cfg.tab.c"
    break;

  case 194:
#line 1072 "cfg.y"
                                            { yyerror("boolean value expected"); }
#line 4712 "cfg.tab.c"
    break;

  case 195:
#line 1073 "cfg.y"
                                                { IFOR();
				tcp_max_msg_time=(yyvsp[0].intval);
		}
#line 4720 "cfg.tab.c"
    break;

  case 196:
#line 1076 "cfg.y"
                                               { yyerror("boolean value expected"); }
#line 4726 "cfg.tab.c"
    break;

  case 197:
#line 1077 "cfg.y"
                                                        { IFOR();
			#ifndef HAVE_TCP_KEEPCNT
				warn("cannot be enabled TCP_KEEPCOUNT (no OS support)");
			#else
				tcp_keepcount=(yyvsp[0].intval);
			#endif
		}
#line 4738 "cfg.tab.c"
    break;

  case 198:
#line 1084 "cfg.y"
                                            { yyerror("int value expected"); }
#line 4744 "cfg.tab.c"
    break;

  case 199:
#line 1085 "cfg.y"
                                                        { IFOR();
			#ifndef HAVE_TCP_KEEPIDLE
				warn("cannot be enabled TCP_KEEPIDLE (no OS support)");
			#else
				tcp_keepidle=(yyvsp[0].intval);
			#endif
		}
#line 4756 "cfg.tab.c"
    break;

  case 200:
#line 1092 "cfg.y"
                                           { yyerror("int value expected"); }
#line 4762 "cfg.tab.c"
    break;

  case 201:
#line 1093 "cfg.y"
                                                { IFOR();
			#ifndef HAVE_TCP_KEEPINTVL
				warn("cannot be enabled TCP_KEEPINTERVAL (no OS support)");
			#else
				tcp_keepinterval=(yyvsp[0].intval);
			 #endif
		}
#line 4774 "cfg.tab.c"
    break;

  case 202:
#line 1100 "cfg.y"
                                               { yyerror("int value expected"); }
#line 4780 "cfg.tab.c"
    break;

  case 203:
#line 1101 "cfg.y"
                                                { IFOR();
							server_signature=(yyvsp[0].intval); }
#line 4787 "cfg.tab.c"
    break;

  case 204:
#line 1103 "cfg.y"
                                               { yyerror("boolean value expected"); }
#line 4793 "cfg.tab.c"
    break;

  case 205:
#line 1104 "cfg.y"
                                             { IFOR();
							server_header.s=(yyvsp[0].strval);
							server_header.len=strlen((yyvsp[0].strval));
							}
#line 4802 "cfg.tab.c"
    break;

  case 206:
#line 1108 "cfg.y"
                                            { yyerror("string value expected"); }
#line 4808 "cfg.tab.c"
    break;

  case 207:
#line 1109 "cfg.y"
                                                 { user_agent_header.s=(yyvsp[0].strval);
									user_agent_header.len=strlen((yyvsp[0].strval));
									}
#line 4816 "cfg.tab.c"
    break;

  case 208:
#line 1112 "cfg.y"
                                                { yyerror("string value expected"); }
#line 4822 "cfg.tab.c"
    break;

  case 209:
#line 1113 "cfg.y"
                                                 { IFOR();
							pv_print_buf_size = (yyvsp[0].intval); }
#line 4829 "cfg.tab.c"
    break;

  case 210:
#line 1115 "cfg.y"
                                                { yyerror("number expected"); }
#line 4835 "cfg.tab.c"
    break;

  case 211:
#line 1116 "cfg.y"
                                             { IFOR();
							xlog_buf_size = (yyvsp[0].intval); }
#line 4842 "cfg.tab.c"
    break;

  case 212:
#line 1118 "cfg.y"
                                                { IFOR();
							xlog_force_color = (yyvsp[0].intval); }
#line 4849 "cfg.tab.c"
    break;

  case 213:
#line 1120 "cfg.y"
                                                { IFOR();
							xlog_print_level = (yyvsp[0].intval); }
#line 4856 "cfg.tab.c"
    break;

  case 214:
#line 1122 "cfg.y"
                                            { yyerror("number expected"); }
#line 4862 "cfg.tab.c"
    break;

  case 215:
#line 1123 "cfg.y"
                                               { yyerror("boolean value expected"); }
#line 4868 "cfg.tab.c"
    break;

  case 216:
#line 1124 "cfg.y"
                                               { yyerror("number expected"); }
#line 4874 "cfg.tab.c"
    break;

  case 217:
#line 1125 "cfg.y"
                                          { IFOR();
							*xlog_level = (yyvsp[0].intval); }
#line 4881 "cfg.tab.c"
    break;

  case 218:
#line 1127 "cfg.y"
                                         { yyerror("number expected"); }
#line 4887 "cfg.tab.c"
    break;

  case 219:
#line 1128 "cfg.y"
                                          { IFOR();
							if (add_listener((yyvsp[0].sockid))!=0){
								LM_CRIT("cfg. parser: failed"
										" to add listen address\n");
								break;
							}
						}
#line 4899 "cfg.tab.c"
    break;

  case 220:
#line 1135 "cfg.y"
                                      { yyerror("ip address or hostname "
						"expected (use quotes if the hostname includes"
						" config keywords)"); }
#line 4907 "cfg.tab.c"
    break;

  case 221:
#line 1138 "cfg.y"
                                                           { IFOR();
							/* convert STIRNG ($3) to an ID */
							/* update the memstats type for each module */
							#ifndef SHM_EXTRA_STATS
								LM_CRIT("SHM_EXTRA_STATS not defined");
								YYABORT;
							#else

							#ifdef SHM_SHOW_DEFAULT_GROUP
							if(strcmp((yyvsp[-2].strval), "default") == 0){
								LM_CRIT("default group  name is not allowed");
								YYABORT;
							}
							#endif

							for(tmp_mod = mod_names; tmp_mod; tmp_mod=tmp_mod->next){
								if(strcmp((yyvsp[-2].strval), tmp_mod->s) == 0){
									LM_CRIT("The same mem-group name is used twice: [%s] [%s]\n", (yyvsp[-2].strval), tmp_mod->s);
									YYABORT;
								}
							}

							tmp_mod = pkg_malloc(sizeof(struct multi_str));
							if(!tmp_mod){
								LM_CRIT("out of pkg memory");
								YYABORT;
							}

							tmp_mod->s = (yyvsp[-2].strval);
							tmp_mod->next = mod_names;
							mod_names = tmp_mod;
							for (tmp_mod = (yyvsp[0].multistr); tmp_mod; tmp_mod = tmp_mod->next){
								if(set_mem_idx(tmp_mod->s, mem_free_idx)){
									YYABORT;
								}
							}

							mem_free_idx++;	

							if(alloc_group_stat()){
								YYABORT;
							}
							#endif
						}
#line 4956 "cfg.tab.c"
    break;

  case 222:
#line 1182 "cfg.y"
                                                    { yyerror("invalid or no module specified"); }
#line 4962 "cfg.tab.c"
    break;

  case 223:
#line 1183 "cfg.y"
                                      { IFOR();
							for(lst_tmp=(yyvsp[0].sockid); lst_tmp; lst_tmp=lst_tmp->next)
								add_alias(lst_tmp->name, strlen(lst_tmp->name),
											lst_tmp->port, lst_tmp->proto);
							  }
#line 4972 "cfg.tab.c"
    break;

  case 224:
#line 1188 "cfg.y"
                                      { yyerror("hostname expected (use quotes"
							" if the hostname includes config keywords)"); }
#line 4979 "cfg.tab.c"
    break;

  case 225:
#line 1190 "cfg.y"
                                            { IFOR();
								auto_aliases=(yyvsp[0].intval); }
#line 4986 "cfg.tab.c"
    break;

  case 226:
#line 1192 "cfg.y"
                                            { yyerror("number  expected"); }
#line 4992 "cfg.tab.c"
    break;

  case 227:
#line 1193 "cfg.y"
                                                     { IFOR(pkg_free((yyvsp[0].strval)));
								if ((yyvsp[0].strval)) {
									default_global_address.s=(yyvsp[0].strval);
									default_global_address.len=strlen((yyvsp[0].strval));
								}
								}
#line 5003 "cfg.tab.c"
    break;

  case 228:
#line 1199 "cfg.y"
                                                 {yyerror("ip address or hostname "
												"expected"); }
#line 5010 "cfg.tab.c"
    break;

  case 229:
#line 1201 "cfg.y"
                                               { IFOR();
								tmp = int2str((yyvsp[0].intval), &i_tmp);
								if (i_tmp > default_global_port.len)
									default_global_port.s =
									pkg_realloc(default_global_port.s, i_tmp);
								if (!default_global_port.s) {
									LM_CRIT("cfg. parser: out of memory.\n");
									YYABORT;
								} else {
									default_global_port.len = i_tmp;
									memcpy(default_global_port.s, tmp,
											default_global_port.len);
								}
								}
#line 5029 "cfg.tab.c"
    break;

  case 230:
#line 1215 "cfg.y"
                                             {yyerror("ip address or hostname "
												"expected"); }
#line 5036 "cfg.tab.c"
    break;

  case 231:
#line 1217 "cfg.y"
                                            { IFOR();
										disable_core_dump=(yyvsp[0].intval);
									}
#line 5044 "cfg.tab.c"
    break;

  case 232:
#line 1220 "cfg.y"
                                           { yyerror("boolean value expected"); }
#line 5050 "cfg.tab.c"
    break;

  case 233:
#line 1221 "cfg.y"
                                             { IFOR();
										open_files_limit=(yyvsp[0].intval);
									}
#line 5058 "cfg.tab.c"
    break;

  case 234:
#line 1224 "cfg.y"
                                            { yyerror("number expected"); }
#line 5064 "cfg.tab.c"
    break;

  case 235:
#line 1225 "cfg.y"
                                              { IFOR();
								#ifdef USE_MCAST
										mcast_loopback=(yyvsp[0].intval);
								#else
									warn("no multicast support compiled in");
								#endif
		  }
#line 5076 "cfg.tab.c"
    break;

  case 236:
#line 1232 "cfg.y"
                                             { yyerror("boolean value expected"); }
#line 5082 "cfg.tab.c"
    break;

  case 237:
#line 1233 "cfg.y"
                                         { IFOR();
								#ifdef USE_MCAST
										mcast_ttl=(yyvsp[0].intval);
								#else
									warn("no multicast support compiled in");
								#endif
		  }
#line 5094 "cfg.tab.c"
    break;

  case 238:
#line 1240 "cfg.y"
                                        { yyerror("number expected as tos"); }
#line 5100 "cfg.tab.c"
    break;

  case 239:
#line 1241 "cfg.y"
                                   { IFOR(); tos = (yyvsp[0].intval);
							if (tos<=0)
								yyerror("invalid tos value");
		 }
#line 5109 "cfg.tab.c"
    break;

  case 240:
#line 1245 "cfg.y"
                               { IFOR();
							if (strcasecmp((yyvsp[0].strval),"IPTOS_LOWDELAY")) {
								tos=IPTOS_LOWDELAY;
							} else if (strcasecmp((yyvsp[0].strval),"IPTOS_THROUGHPUT")) {
								tos=IPTOS_THROUGHPUT;
							} else if (strcasecmp((yyvsp[0].strval),"IPTOS_RELIABILITY")) {
								tos=IPTOS_RELIABILITY;
#if defined(IPTOS_MINCOST)
							} else if (strcasecmp((yyvsp[0].strval),"IPTOS_MINCOST")) {
								tos=IPTOS_MINCOST;
#endif
#if defined(IPTOS_LOWCOST)
							} else if (strcasecmp((yyvsp[0].strval),"IPTOS_LOWCOST")) {
								tos=IPTOS_LOWCOST;
#endif
							} else {
								yyerror("invalid tos value - allowed: "
									"IPTOS_LOWDELAY,IPTOS_THROUGHPUT,"
									"IPTOS_RELIABILITY"
#if defined(IPTOS_LOWCOST)
									",IPTOS_LOWCOST"
#endif
#if defined(IPTOS_MINCOST)
									",IPTOS_MINCOST"
#endif
									"\n");
							}
		 }
#line 5142 "cfg.tab.c"
    break;

  case 241:
#line 1273 "cfg.y"
                                  { yyerror("number expected"); }
#line 5148 "cfg.tab.c"
    break;

  case 242:
#line 1274 "cfg.y"
                                     {IFOR();
				set_mpath((yyvsp[0].strval)); }
#line 5155 "cfg.tab.c"
    break;

  case 243:
#line 1276 "cfg.y"
                                     { yyerror("string value expected"); }
#line 5161 "cfg.tab.c"
    break;

  case 244:
#line 1277 "cfg.y"
                                                    { IFOR();
										disable_dns_failover=(yyvsp[0].intval);
									}
#line 5169 "cfg.tab.c"
    break;

  case 245:
#line 1280 "cfg.y"
                                             { yyerror("boolean value expected"); }
#line 5175 "cfg.tab.c"
    break;

  case 246:
#line 1281 "cfg.y"
                                                     { IFOR();
										disable_dns_blacklist=(yyvsp[0].intval);
									}
#line 5183 "cfg.tab.c"
    break;

  case 247:
#line 1284 "cfg.y"
                                              { yyerror("boolean value expected"); }
#line 5189 "cfg.tab.c"
    break;

  case 248:
#line 1285 "cfg.y"
                                                                            { IFOR();
				s_tmp.s = (yyvsp[-4].strval);
				s_tmp.len = strlen((yyvsp[-4].strval));
				if (create_bl_head( BL_CORE_ID, BL_READONLY_LIST,
				    bl_head, bl_tail, &s_tmp)==0) {
					yyerror("failed to create blacklist\n");
					YYABORT;
				}
				bl_head = bl_tail = NULL;
				}
#line 5204 "cfg.tab.c"
    break;

  case 249:
#line 1295 "cfg.y"
                                                     { IFOR();
				sl_fwd_disabled=(yyvsp[0].intval); }
#line 5211 "cfg.tab.c"
    break;

  case 250:
#line 1297 "cfg.y"
                                                { IFOR();
				db_version_table=(yyvsp[0].strval); }
#line 5218 "cfg.tab.c"
    break;

  case 251:
#line 1299 "cfg.y"
                                               { yyerror("string value expected"); }
#line 5224 "cfg.tab.c"
    break;

  case 252:
#line 1300 "cfg.y"
                                              { IFOR();
				db_default_url=(yyvsp[0].strval); }
#line 5231 "cfg.tab.c"
    break;

  case 253:
#line 1302 "cfg.y"
                                             { yyerror("string value expected"); }
#line 5237 "cfg.tab.c"
    break;

  case 254:
#line 1303 "cfg.y"
                                                        { IFOR();
				db_max_async_connections=(yyvsp[0].intval); }
#line 5244 "cfg.tab.c"
    break;

  case 255:
#line 1305 "cfg.y"
                                                       {
				yyerror("integer value expected");
				}
#line 5252 "cfg.tab.c"
    break;

  case 256:
#line 1308 "cfg.y"
                                                       { IFOR();
				disable_503_translation=(yyvsp[0].intval); }
#line 5259 "cfg.tab.c"
    break;

  case 257:
#line 1310 "cfg.y"
                                                      {
				yyerror("integer value expected");
				}
#line 5267 "cfg.tab.c"
    break;

  case 258:
#line 1313 "cfg.y"
                                                                    {}
#line 5273 "cfg.tab.c"
    break;

  case 259:
#line 1314 "cfg.y"
                                                   {
				yyerror("bad auto-scaling profile definition");
				}
#line 5281 "cfg.tab.c"
    break;

  case 260:
#line 1317 "cfg.y"
                                                  { IFOR();
				auto_scaling_cycle=(yyvsp[0].intval); }
#line 5288 "cfg.tab.c"
    break;

  case 261:
#line 1319 "cfg.y"
                                                 {
				yyerror("integer value expected");
				}
#line 5296 "cfg.tab.c"
    break;

  case 262:
#line 1322 "cfg.y"
                              { yyerror("unknown config variable"); }
#line 5302 "cfg.tab.c"
    break;

  case 263:
#line 1325 "cfg.y"
                                        { IFOR();
			if (load_module((yyvsp[0].strval)) < 0)
				yyerrorf("failed to load module %s\n", (yyvsp[0].strval));
		}
#line 5311 "cfg.tab.c"
    break;

  case 264:
#line 1329 "cfg.y"
                                        { yyerror("string expected");  }
#line 5317 "cfg.tab.c"
    break;

  case 265:
#line 1330 "cfg.y"
                                                                          { IFOR();
				if (set_mod_param_regex((yyvsp[-5].strval), (yyvsp[-3].strval), STR_PARAM, (yyvsp[-1].strval)) != 0) {
					yyerrorf("Parameter <%s> not found in module <%s> - "
						"can't set", (yyvsp[-3].strval), (yyvsp[-5].strval));
				}
			}
#line 5328 "cfg.tab.c"
    break;

  case 266:
#line 1336 "cfg.y"
                                                                           { IFOR();
				if (set_mod_param_regex((yyvsp[-5].strval), (yyvsp[-3].strval), INT_PARAM, (void*)(yyvsp[-1].intval)) != 0) {
					yyerrorf("Parameter <%s> not found in module <%s> - "
						"can't set", (yyvsp[-3].strval), (yyvsp[-5].strval));
				}
			}
#line 5339 "cfg.tab.c"
    break;

  case 267:
#line 1342 "cfg.y"
                                 { yyerror("Invalid arguments"); }
#line 5345 "cfg.tab.c"
    break;

  case 268:
#line 1346 "cfg.y"
                       { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 5351 "cfg.tab.c"
    break;

  case 269:
#line 1347 "cfg.y"
                       { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 5357 "cfg.tab.c"
    break;

  case 270:
#line 1350 "cfg.y"
                 {
					(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
					if ((yyval.ipaddr)==0){
						LM_CRIT("ERROR: cfg. parser: out of memory.\n");
						YYABORT;
					}else{
						memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
						(yyval.ipaddr)->af=AF_INET;
						(yyval.ipaddr)->len=16;
						if (inet_pton(AF_INET, (yyvsp[0].strval), (yyval.ipaddr)->u.addr)<=0){
							yyerror("bad ipv4 address");
						}
					}
				}
#line 5376 "cfg.tab.c"
    break;

  case 271:
#line 1366 "cfg.y"
                         {
					(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
					if ((yyval.ipaddr)==0){
						LM_CRIT("ERROR: cfg. parser: out of memory.\n");
						YYABORT;
					}else{
						memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
						(yyval.ipaddr)->af=AF_INET6;
						(yyval.ipaddr)->len=16;
						if (inet_pton(AF_INET6, (yyvsp[0].strval), (yyval.ipaddr)->u.addr)<=0){
							yyerror("bad ipv6 address");
						}
					}
				}
#line 5395 "cfg.tab.c"
    break;

  case 272:
#line 1382 "cfg.y"
                 { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 5401 "cfg.tab.c"
    break;

  case 273:
#line 1383 "cfg.y"
                                 {(yyval.ipaddr)=(yyvsp[-1].ipaddr); }
#line 5407 "cfg.tab.c"
    break;

  case 274:
#line 1386 "cfg.y"
                {
				if (parse_ipnet((yyvsp[0].strval), strlen((yyvsp[0].strval)), &net_tmp) < 0)
					yyerror("unable to parse ip and/or netmask\n");

				(yyval.ipnet) = net_tmp;
			}
#line 5418 "cfg.tab.c"
    break;

  case 275:
#line 1392 "cfg.y"
                        {
				(yyval.ipnet)=mk_net_bitlen((yyvsp[0].ipaddr), (yyvsp[0].ipaddr)->len*8);
				pkg_free((yyvsp[0].ipaddr));
			}
#line 5427 "cfg.tab.c"
    break;

  case 276:
#line 1402 "cfg.y"
                              {
				(yyval.strval) = pkg_malloc( strlen((yyvsp[-1].strval)) + strlen((yyvsp[0].strval)) + 1);
				if ((yyval.strval)==0){
					yyerror("cfg. parser: out of memory");
					YYABORT;
				} else {
					strcpy((yyval.strval),(yyvsp[-1].strval)); strcat((yyval.strval),(yyvsp[0].strval));
					pkg_free((yyvsp[-1].strval)); pkg_free((yyvsp[0].strval));
				}
			}
#line 5442 "cfg.tab.c"
    break;

  case 277:
#line 1412 "cfg.y"
                                       {
				(yyval.strval) = pkg_malloc( strlen((yyvsp[-1].strval)) + strlen((yyvsp[0].strval)) + 1);
				if ((yyval.strval)==0){
					LM_CRIT("ERROR: cfg. parser: out of memory.\n");
					YYABORT;
				} else {
					strcpy((yyval.strval),(yyvsp[-1].strval)); strcat((yyval.strval),(yyvsp[0].strval));
					pkg_free((yyvsp[-1].strval)); pkg_free((yyvsp[0].strval));
				}
			}
#line 5457 "cfg.tab.c"
    break;

  case 278:
#line 1423 "cfg.y"
                {
				(yyval.strval) = (yyvsp[0].strval);
				}
#line 5465 "cfg.tab.c"
    break;

  case 279:
#line 1426 "cfg.y"
                         {
				tmp=int2str((yyvsp[0].intval), &i_tmp);
				if (((yyval.strval)=pkg_malloc(i_tmp+1))==0) {
					yyerror("cfg. parser: out of memory.\n");
					YYABORT;
				}
				memcpy( (yyval.strval), tmp, i_tmp);
				(yyval.strval)[i_tmp] = 0;
				}
#line 5479 "cfg.tab.c"
    break;

  case 280:
#line 1435 "cfg.y"
                        {
				(yyval.strval) = (yyvsp[0].strval);
		}
#line 5487 "cfg.tab.c"
    break;

  case 281:
#line 1440 "cfg.y"
                                        {
						if (sroutes->request[DEFAULT_RT].a!=0) {
							yyerror("overwriting default "
								"request routing table");
							YYABORT;
						}
						push((yyvsp[-1].action), &sroutes->request[DEFAULT_RT].a);
					}
#line 5500 "cfg.tab.c"
    break;

  case 282:
#line 1448 "cfg.y"
                                                                       {
						if ( strtol((yyvsp[-4].strval),&tmp,10)==0 && *tmp==0) {
							/* route[0] detected */
							if (sroutes->request[DEFAULT_RT].a!=0) {
								yyerror("overwriting(2) default "
									"request routing table");
								YYABORT;
							}
							push((yyvsp[-1].action), &sroutes->request[DEFAULT_RT].a);
						} else {
							i_tmp = get_script_route_idx( (yyvsp[-4].strval),
								sroutes->request, RT_NO,1);
							if (i_tmp==-1) YYABORT;
							push((yyvsp[-1].action), &sroutes->request[i_tmp].a);
						}
					}
#line 5521 "cfg.tab.c"
    break;

  case 283:
#line 1464 "cfg.y"
                              { yyerror("invalid  route  statement"); }
#line 5527 "cfg.tab.c"
    break;

  case 284:
#line 1467 "cfg.y"
                                                                                {
						i_tmp = get_script_route_idx( (yyvsp[-4].strval), sroutes->failure,
							FAILURE_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[-1].action), &sroutes->failure[i_tmp].a);
					}
#line 5538 "cfg.tab.c"
    break;

  case 285:
#line 1473 "cfg.y"
                                      { yyerror("invalid failure_route statement"); }
#line 5544 "cfg.tab.c"
    break;

  case 286:
#line 1476 "cfg.y"
                                                       {
						if (sroutes->onreply[DEFAULT_RT].a!=0) {
							yyerror("overwriting default "
								"onreply routing table");
							YYABORT;
						}
						push((yyvsp[-1].action), &sroutes->onreply[DEFAULT_RT].a);
					}
#line 5557 "cfg.tab.c"
    break;

  case 287:
#line 1484 "cfg.y"
                                                                               {
						i_tmp = get_script_route_idx( (yyvsp[-4].strval), sroutes->onreply,
							ONREPLY_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[-1].action), &sroutes->onreply[i_tmp].a);
					}
#line 5568 "cfg.tab.c"
    break;

  case 288:
#line 1490 "cfg.y"
                                      { yyerror("invalid onreply_route statement"); }
#line 5574 "cfg.tab.c"
    break;

  case 289:
#line 1493 "cfg.y"
                                                                              {
						i_tmp = get_script_route_idx( (yyvsp[-4].strval), sroutes->branch,
							BRANCH_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[-1].action), &sroutes->branch[i_tmp].a);
					}
#line 5585 "cfg.tab.c"
    break;

  case 290:
#line 1499 "cfg.y"
                                     { yyerror("invalid branch_route statement"); }
#line 5591 "cfg.tab.c"
    break;

  case 291:
#line 1502 "cfg.y"
                                                    {
						if (sroutes->error.a!=0) {
							yyerror("overwriting default "
								"error routing table");
							YYABORT;
						}
						push((yyvsp[-1].action), &sroutes->error.a);
					}
#line 5604 "cfg.tab.c"
    break;

  case 292:
#line 1510 "cfg.y"
                                    { yyerror("invalid error_route statement"); }
#line 5610 "cfg.tab.c"
    break;

  case 293:
#line 1513 "cfg.y"
                                                    {
						if (sroutes->local.a!=0) {
							yyerror("re-definition of local "
								"route detected");
							YYABORT;
						}
						push((yyvsp[-1].action), &sroutes->local.a);
					}
#line 5623 "cfg.tab.c"
    break;

  case 294:
#line 1521 "cfg.y"
                                    { yyerror("invalid local_route statement"); }
#line 5629 "cfg.tab.c"
    break;

  case 295:
#line 1524 "cfg.y"
                                                        {
						if (sroutes->startup.a!=0) {
							yyerror("re-definition of startup "
								"route detected");
							YYABORT;
						}
						push((yyvsp[-1].action), &sroutes->startup.a);
					}
#line 5642 "cfg.tab.c"
    break;

  case 296:
#line 1532 "cfg.y"
                                      { yyerror("invalid startup_route statement"); }
#line 5648 "cfg.tab.c"
    break;

  case 297:
#line 1535 "cfg.y"
                                                                                          {
						i_tmp = 0;
						while(sroutes->timer[i_tmp].a!=0 && i_tmp<TIMER_RT_NO){
							i_tmp++;
						}
						if(i_tmp == TIMER_RT_NO) {
							yyerror("Too many timer routes defined\n");
							YYABORT;
						}
						sroutes->timer[i_tmp].interval = (yyvsp[-4].intval);
						push((yyvsp[-1].action), &sroutes->timer[i_tmp].a);
					}
#line 5665 "cfg.tab.c"
    break;

  case 298:
#line 1547 "cfg.y"
                                    { yyerror("invalid timer_route statement"); }
#line 5671 "cfg.tab.c"
    break;

  case 299:
#line 1550 "cfg.y"
                                                                            {
						i_tmp = get_script_route_idx((yyvsp[-4].strval), sroutes->event,
								EVENT_RT_NO,1);
						if (i_tmp==-1) YYABORT;
						push((yyvsp[-1].action), &sroutes->event[i_tmp].a);
					}
#line 5682 "cfg.tab.c"
    break;

  case 300:
#line 1556 "cfg.y"
                                    { yyerror("invalid timer_route statement"); }
#line 5688 "cfg.tab.c"
    break;

  case 301:
#line 1561 "cfg.y"
                        { (yyval.expr)=mk_exp(AND_OP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5694 "cfg.tab.c"
    break;

  case 302:
#line 1562 "cfg.y"
                                { (yyval.expr)=mk_exp(OR_OP, (yyvsp[-2].expr), (yyvsp[0].expr));  }
#line 5700 "cfg.tab.c"
    break;

  case 303:
#line 1563 "cfg.y"
                                        { (yyval.expr)=mk_exp(NOT_OP, (yyvsp[0].expr), 0);  }
#line 5706 "cfg.tab.c"
    break;

  case 304:
#line 1564 "cfg.y"
                                { (yyval.expr)=mk_exp(EVAL_OP, (yyvsp[-1].expr), 0); }
#line 5712 "cfg.tab.c"
    break;

  case 305:
#line 1565 "cfg.y"
                                  { (yyval.expr)=(yyvsp[-1].expr); }
#line 5718 "cfg.tab.c"
    break;

  case 306:
#line 1566 "cfg.y"
                                        { (yyval.expr)=(yyvsp[0].expr); }
#line 5724 "cfg.tab.c"
    break;

  case 307:
#line 1569 "cfg.y"
                          {(yyval.intval)=EQUAL_OP; }
#line 5730 "cfg.tab.c"
    break;

  case 308:
#line 1570 "cfg.y"
                                {(yyval.intval)=DIFF_OP; }
#line 5736 "cfg.tab.c"
    break;

  case 309:
#line 1573 "cfg.y"
                {(yyval.intval)=GT_OP; }
#line 5742 "cfg.tab.c"
    break;

  case 310:
#line 1574 "cfg.y"
                        {(yyval.intval)=LT_OP; }
#line 5748 "cfg.tab.c"
    break;

  case 311:
#line 1575 "cfg.y"
                        {(yyval.intval)=GTE_OP; }
#line 5754 "cfg.tab.c"
    break;

  case 312:
#line 1576 "cfg.y"
                        {(yyval.intval)=LTE_OP; }
#line 5760 "cfg.tab.c"
    break;

  case 313:
#line 1578 "cfg.y"
                {(yyval.intval)=MATCH_OP; }
#line 5766 "cfg.tab.c"
    break;

  case 314:
#line 1579 "cfg.y"
                                {(yyval.intval)=NOTMATCH_OP; }
#line 5772 "cfg.tab.c"
    break;

  case 315:
#line 1582 "cfg.y"
                {(yyval.intval)=(yyvsp[0].intval); }
#line 5778 "cfg.tab.c"
    break;

  case 316:
#line 1583 "cfg.y"
                        {(yyval.intval)=(yyvsp[0].intval); }
#line 5784 "cfg.tab.c"
    break;

  case 317:
#line 1586 "cfg.y"
                {(yyval.intval)=(yyvsp[0].intval); }
#line 5790 "cfg.tab.c"
    break;

  case 318:
#line 1587 "cfg.y"
                     {(yyval.intval)=(yyvsp[0].intval); }
#line 5796 "cfg.tab.c"
    break;

  case 319:
#line 1588 "cfg.y"
                                {(yyval.intval)=(yyvsp[0].intval); }
#line 5802 "cfg.tab.c"
    break;

  case 320:
#line 1591 "cfg.y"
                                {
				spec = (pv_spec_t*)pkg_malloc(sizeof(pv_spec_t));
				if (spec==NULL){
					yyerror("no more pkg memory\n");
					YYABORT;
				}
				memset(spec, 0, sizeof(pv_spec_t));
				tstr.s = (yyvsp[0].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_spec(&tstr, spec)==NULL)
				{
					yyerror("unknown script variable");
				}

				(yyval.specval) = spec;
			}
#line 5823 "cfg.tab.c"
    break;

  case 321:
#line 1607 "cfg.y"
                               {
			(yyval.specval)=0; yyerror("invalid script variable name");
		}
#line 5831 "cfg.tab.c"
    break;

  case 322:
#line 1612 "cfg.y"
                                {(yyval.expr)=(yyvsp[0].expr); }
#line 5837 "cfg.tab.c"
    break;

  case 323:
#line 1613 "cfg.y"
                                        {(yyval.expr)=mk_elem( NO_OP, ACTION_O, 0, ACTIONS_ST, (yyvsp[0].action) ); }
#line 5843 "cfg.tab.c"
    break;

  case 324:
#line 1614 "cfg.y"
                                        {(yyval.expr)=mk_elem( NO_OP, NUMBER_O, 0, NUMBER_ST,
											(void*)(yyvsp[0].intval) ); }
#line 5850 "cfg.tab.c"
    break;

  case 325:
#line 1616 "cfg.y"
                                {
				(yyval.expr)=mk_elem(NO_OP, SCRIPTVAR_O,0,SCRIPTVAR_ST,(void*)(yyvsp[0].specval));
			}
#line 5858 "cfg.tab.c"
    break;

  case 326:
#line 1621 "cfg.y"
                                      {
				(yyval.expr)=mk_elem( (yyvsp[-1].intval), SCRIPTVAR_O,(void*)(yyvsp[-2].specval),SCRIPTVAR_ST,(void*)(yyvsp[0].specval));
			}
#line 5866 "cfg.tab.c"
    break;

  case 327:
#line 1624 "cfg.y"
                                          {
				(yyval.expr)=mk_elem( (yyvsp[-1].intval), SCRIPTVAR_O,(void*)(yyvsp[-2].specval),STR_ST,(yyvsp[0].strval));
			}
#line 5874 "cfg.tab.c"
    break;

  case 328:
#line 1627 "cfg.y"
                                           {
				(yyval.expr)=mk_elem( (yyvsp[-1].intval), SCRIPTVAR_O,(void*)(yyvsp[-2].specval),NUMBER_ST,(void *)(yyvsp[0].intval));
			}
#line 5882 "cfg.tab.c"
    break;

  case 329:
#line 1630 "cfg.y"
                                                {
				(yyval.expr)=mk_elem( (yyvsp[-1].intval), SCRIPTVAR_O,(void*)(yyvsp[-2].specval), NULLV_ST, 0);
			}
#line 5890 "cfg.tab.c"
    break;

  case 330:
#line 1633 "cfg.y"
                                           {
				(yyval.expr)=mk_elem((yyvsp[-1].intval), SCRIPTVAR_O, (void*)(yyvsp[-2].specval), NET_ST, (yyvsp[0].ipnet));
			}
#line 5898 "cfg.tab.c"
    break;

  case 331:
#line 1639 "cfg.y"
              { (yyval.intval) = EQ_T; }
#line 5904 "cfg.tab.c"
    break;

  case 332:
#line 1640 "cfg.y"
                  { (yyval.intval) = COLONEQ_T; }
#line 5910 "cfg.tab.c"
    break;

  case 333:
#line 1641 "cfg.y"
                 { (yyval.intval) = PLUSEQ_T; }
#line 5916 "cfg.tab.c"
    break;

  case 334:
#line 1642 "cfg.y"
                  { (yyval.intval) = MINUSEQ_T;}
#line 5922 "cfg.tab.c"
    break;

  case 335:
#line 1643 "cfg.y"
                  { (yyval.intval) = DIVEQ_T; }
#line 5928 "cfg.tab.c"
    break;

  case 336:
#line 1644 "cfg.y"
                 { (yyval.intval) = MULTEQ_T; }
#line 5934 "cfg.tab.c"
    break;

  case 337:
#line 1645 "cfg.y"
                   { (yyval.intval) = MODULOEQ_T; }
#line 5940 "cfg.tab.c"
    break;

  case 338:
#line 1646 "cfg.y"
                 { (yyval.intval) = BANDEQ_T; }
#line 5946 "cfg.tab.c"
    break;

  case 339:
#line 1647 "cfg.y"
                { (yyval.intval) = BOREQ_T; }
#line 5952 "cfg.tab.c"
    break;

  case 340:
#line 1648 "cfg.y"
                 { (yyval.intval) = BXOREQ_T; }
#line 5958 "cfg.tab.c"
    break;

  case 341:
#line 1652 "cfg.y"
                { (yyval.expr) = mk_elem(VALUE_OP, NUMBERV_O, (void*)(yyvsp[0].intval), 0, 0); }
#line 5964 "cfg.tab.c"
    break;

  case 342:
#line 1653 "cfg.y"
                 { (yyval.expr) = mk_elem(VALUE_OP, STRINGV_O, (yyvsp[0].strval), 0, 0); }
#line 5970 "cfg.tab.c"
    break;

  case 343:
#line 1654 "cfg.y"
                     { (yyval.expr) = mk_elem(VALUE_OP, SCRIPTVAR_O, (yyvsp[0].specval), 0, 0); }
#line 5976 "cfg.tab.c"
    break;

  case 344:
#line 1655 "cfg.y"
                   { (yyval.expr)= (yyvsp[0].expr); }
#line 5982 "cfg.tab.c"
    break;

  case 345:
#line 1656 "cfg.y"
              { (yyval.expr)=mk_elem( NO_OP, ACTION_O, 0, ACTIONS_ST, (yyvsp[0].action) ); }
#line 5988 "cfg.tab.c"
    break;

  case 346:
#line 1657 "cfg.y"
                                   {
				(yyval.expr) = mk_elem(PLUS_OP, EXPR_O, (yyvsp[-2].expr), EXPR_ST, (yyvsp[0].expr));
			}
#line 5996 "cfg.tab.c"
    break;

  case 347:
#line 1660 "cfg.y"
                                    {
				(yyval.expr) = mk_elem(MINUS_OP, EXPR_O, (yyvsp[-2].expr), EXPR_ST, (yyvsp[0].expr));
			}
#line 6004 "cfg.tab.c"
    break;

  case 348:
#line 1663 "cfg.y"
                                   {
				(yyval.expr) = mk_elem(MULT_OP, EXPR_O, (yyvsp[-2].expr), EXPR_ST, (yyvsp[0].expr));
			}
#line 6012 "cfg.tab.c"
    break;

  case 349:
#line 1666 "cfg.y"
                                    {
				(yyval.expr) = mk_elem(DIV_OP, EXPR_O, (yyvsp[-2].expr), EXPR_ST, (yyvsp[0].expr));
			}
#line 6020 "cfg.tab.c"
    break;

  case 350:
#line 1669 "cfg.y"
                                     {
				(yyval.expr) = mk_elem(MODULO_OP, EXPR_O, (yyvsp[-2].expr), EXPR_ST, (yyvsp[0].expr));
			}
#line 6028 "cfg.tab.c"
    break;

  case 351:
#line 1672 "cfg.y"
                                   {
				(yyval.expr) = mk_elem(BAND_OP, EXPR_O, (yyvsp[-2].expr), EXPR_ST, (yyvsp[0].expr));
			}
#line 6036 "cfg.tab.c"
    break;

  case 352:
#line 1675 "cfg.y"
                                  {
				(yyval.expr) = mk_elem(BOR_OP, EXPR_O, (yyvsp[-2].expr), EXPR_ST, (yyvsp[0].expr));
			}
#line 6044 "cfg.tab.c"
    break;

  case 353:
#line 1678 "cfg.y"
                                   {
				(yyval.expr) = mk_elem(BXOR_OP, EXPR_O, (yyvsp[-2].expr), EXPR_ST, (yyvsp[0].expr));
			}
#line 6052 "cfg.tab.c"
    break;

  case 354:
#line 1681 "cfg.y"
                                      {
				(yyval.expr) = mk_elem(BLSHIFT_OP, EXPR_O, (yyvsp[-2].expr), EXPR_ST, (yyvsp[0].expr));
			}
#line 6060 "cfg.tab.c"
    break;

  case 355:
#line 1684 "cfg.y"
                                      {
				(yyval.expr) = mk_elem(BRSHIFT_OP, EXPR_O, (yyvsp[-2].expr), EXPR_ST, (yyvsp[0].expr));
			}
#line 6068 "cfg.tab.c"
    break;

  case 356:
#line 1687 "cfg.y"
                         {
				(yyval.expr) = mk_elem(BNOT_OP, EXPR_O, (yyvsp[0].expr), 0, 0);
			}
#line 6076 "cfg.tab.c"
    break;

  case 357:
#line 1690 "cfg.y"
                                  { (yyval.expr) = (yyvsp[-1].expr); }
#line 6082 "cfg.tab.c"
    break;

  case 358:
#line 1693 "cfg.y"
                                          {
			if(!pv_is_w((yyvsp[-2].specval)))
				yyerror("invalid left operand in assignment");
			if((yyvsp[-2].specval)->trans!=0)
				yyerror("transformations not accepted in left side "
					"of assignment");

			mk_action2( (yyval.action), (yyvsp[-1].intval),
					SCRIPTVAR_ST,
					EXPR_ST,
					(yyvsp[-2].specval),
					(yyvsp[0].expr));
		}
#line 6100 "cfg.tab.c"
    break;

  case 359:
#line 1706 "cfg.y"
                                  {
			if(!pv_is_w((yyvsp[-2].specval)))
				yyerror("invalid left operand in assignment");
			if((yyvsp[-2].specval)->trans!=0)
				yyerror("transformations not accepted in left side "
					"of assignment");

			mk_action2( (yyval.action), EQ_T,
					SCRIPTVAR_ST,
					NULLV_ST,
					(yyvsp[-2].specval),
					0);
		}
#line 6118 "cfg.tab.c"
    break;

  case 360:
#line 1719 "cfg.y"
                                    {
			if(!pv_is_w((yyvsp[-2].specval)))
				yyerror("invalid left operand in assignment");
			/* not all can get NULL with := */
			switch((yyvsp[-2].specval)->type) {
				case PVT_AVP:
				break;
				default:
					yyerror("invalid left operand in NULL assignment");
			}
			if((yyvsp[-2].specval)->trans!=0)
				yyerror("transformations not accepted in left side "
					"of assignment");

			mk_action2( (yyval.action), COLONEQ_T,
					SCRIPTVAR_ST,
					NULLV_ST,
					(yyvsp[-2].specval),
					0);
		}
#line 6143 "cfg.tab.c"
    break;

  case 361:
#line 1741 "cfg.y"
                                                                { (yyval.action)=(yyvsp[0].action); }
#line 6149 "cfg.tab.c"
    break;

  case 362:
#line 1742 "cfg.y"
                                                                { (yyval.action)=(yyvsp[0].action); }
#line 6155 "cfg.tab.c"
    break;

  case 363:
#line 1743 "cfg.y"
                                                                { (yyval.action)=(yyvsp[0].action); }
#line 6161 "cfg.tab.c"
    break;

  case 364:
#line 1744 "cfg.y"
                                                { (yyval.action)=(yyvsp[-1].action); }
#line 6167 "cfg.tab.c"
    break;

  case 365:
#line 1745 "cfg.y"
                                                        { (yyval.action)=0; }
#line 6173 "cfg.tab.c"
    break;

  case 366:
#line 1748 "cfg.y"
                                                        { (yyval.action)=(yyvsp[0].action); }
#line 6179 "cfg.tab.c"
    break;

  case 367:
#line 1749 "cfg.y"
                                                { (yyval.action)=(yyvsp[-1].action); }
#line 6185 "cfg.tab.c"
    break;

  case 368:
#line 1750 "cfg.y"
                                                        { (yyval.action)=0; }
#line 6191 "cfg.tab.c"
    break;

  case 369:
#line 1753 "cfg.y"
                                {(yyval.action)=append_action((yyvsp[-1].action), (yyvsp[0].action)); }
#line 6197 "cfg.tab.c"
    break;

  case 370:
#line 1754 "cfg.y"
                                                {(yyval.action)=(yyvsp[0].action);}
#line 6203 "cfg.tab.c"
    break;

  case 371:
#line 1755 "cfg.y"
                                { (yyval.action)=0; yyerror("bad command!)"); }
#line 6209 "cfg.tab.c"
    break;

  case 372:
#line 1758 "cfg.y"
                              {(yyval.action)=(yyvsp[-1].action);}
#line 6215 "cfg.tab.c"
    break;

  case 373:
#line 1759 "cfg.y"
                         {(yyval.action)=(yyvsp[0].action);}
#line 6221 "cfg.tab.c"
    break;

  case 374:
#line 1760 "cfg.y"
                            { (yyval.action)=(yyvsp[0].action);}
#line 6227 "cfg.tab.c"
    break;

  case 375:
#line 1761 "cfg.y"
                              { (yyval.action)=(yyvsp[0].action);}
#line 6233 "cfg.tab.c"
    break;

  case 376:
#line 1762 "cfg.y"
                             {(yyval.action)=(yyvsp[0].action);}
#line 6239 "cfg.tab.c"
    break;

  case 377:
#line 1763 "cfg.y"
                                       {(yyval.action)=(yyvsp[-1].action);}
#line 6245 "cfg.tab.c"
    break;

  case 378:
#line 1764 "cfg.y"
                                              {(yyval.action)=0;}
#line 6251 "cfg.tab.c"
    break;

  case 379:
#line 1765 "cfg.y"
                            { (yyval.action)=0; yyerror("bad command: missing ';'?"); }
#line 6257 "cfg.tab.c"
    break;

  case 380:
#line 1768 "cfg.y"
                                                        { mk_action3( (yyval.action), IF_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 NOSUBTYPE,
													 (yyvsp[-1].expr),
													 (yyvsp[0].action),
													 0);
									}
#line 6270 "cfg.tab.c"
    break;

  case 381:
#line 1776 "cfg.y"
                                                { mk_action3( (yyval.action), IF_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 ACTIONS_ST,
													 (yyvsp[-3].expr),
													 (yyvsp[-2].action),
													 (yyvsp[0].action));
									}
#line 6283 "cfg.tab.c"
    break;

  case 382:
#line 1786 "cfg.y"
                                                                { mk_action2( (yyval.action), WHILE_T,
													 EXPR_ST,
													 ACTIONS_ST,
													 (yyvsp[-1].expr),
													 (yyvsp[0].action));
									}
#line 6294 "cfg.tab.c"
    break;

  case 383:
#line 1794 "cfg.y"
                                                               {
					if ((yyvsp[-4].specval)->type != PVT_SCRIPTVAR &&
					    (yyvsp[-4].specval)->type != PVT_AVP &&
						pv_type((yyvsp[-4].specval)->type) != PVT_JSON) {
						yyerror("\nfor-each statement: only \"var\", \"avp\" "
					            "and \"json\" iterators are supported!");
					}

					mk_action3( (yyval.action), FOR_EACH_T,
					            SCRIPTVAR_ST,
					            SCRIPTVAR_ST,
					            ACTIONS_ST,
					            (yyvsp[-4].specval),
					            (yyvsp[-2].specval),
					            (yyvsp[0].action));
					}
#line 6315 "cfg.tab.c"
    break;

  case 384:
#line 1812 "cfg.y"
                                                                                        {
											mk_action2( (yyval.action), SWITCH_T,
														SCRIPTVAR_ST,
														ACTIONS_ST,
														(yyvsp[-4].specval),
														(yyvsp[-1].action));
									}
#line 6327 "cfg.tab.c"
    break;

  case 385:
#line 1821 "cfg.y"
                                  { (yyval.action)=append_action((yyvsp[-1].action), (yyvsp[0].action)); }
#line 6333 "cfg.tab.c"
    break;

  case 386:
#line 1822 "cfg.y"
                                                { (yyval.action)=(yyvsp[0].action); }
#line 6339 "cfg.tab.c"
    break;

  case 387:
#line 1824 "cfg.y"
                                        {(yyval.action)=append_action((yyvsp[-1].action), (yyvsp[0].action)); }
#line 6345 "cfg.tab.c"
    break;

  case 388:
#line 1825 "cfg.y"
                                                {(yyval.action)=(yyvsp[0].action);}
#line 6351 "cfg.tab.c"
    break;

  case 389:
#line 1829 "cfg.y"
                                                                                { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[-4].intval),
													(yyvsp[-2].action),
													(void*)1);
											}
#line 6364 "cfg.tab.c"
    break;

  case 390:
#line 1838 "cfg.y"
                                                                                { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[-3].intval),
													0,
													(void*)1);
											}
#line 6377 "cfg.tab.c"
    break;

  case 391:
#line 1846 "cfg.y"
                                             { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[-2].intval),
													(yyvsp[0].action),
													(void*)0);
									}
#line 6390 "cfg.tab.c"
    break;

  case 392:
#line 1854 "cfg.y"
                                     { mk_action3( (yyval.action), CASE_T,
													NUMBER_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[-1].intval),
													0,
													(void*)0);
							}
#line 6403 "cfg.tab.c"
    break;

  case 393:
#line 1863 "cfg.y"
                                                                                { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[-4].strval),
													(yyvsp[-2].action),
													(void*)1);
											}
#line 6416 "cfg.tab.c"
    break;

  case 394:
#line 1872 "cfg.y"
                                                                                { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[-3].strval),
													0,
													(void*)1);
											}
#line 6429 "cfg.tab.c"
    break;

  case 395:
#line 1880 "cfg.y"
                                            { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[-2].strval),
													(yyvsp[0].action),
													(void*)0);
									}
#line 6442 "cfg.tab.c"
    break;

  case 396:
#line 1888 "cfg.y"
                                    { mk_action3( (yyval.action), CASE_T,
													STR_ST,
													ACTIONS_ST,
													NUMBER_ST,
													(void*)(yyvsp[-1].strval),
													0,
													(void*)0);
							}
#line 6455 "cfg.tab.c"
    break;

  case 397:
#line 1899 "cfg.y"
                                   { mk_action2( (yyval.action), DEFAULT_T,
													ACTIONS_ST,
													0,
													(yyvsp[0].action),
													0);
									}
#line 6466 "cfg.tab.c"
    break;

  case 398:
#line 1905 "cfg.y"
                                { mk_action2( (yyval.action), DEFAULT_T,
													ACTIONS_ST,
													0,
													0,
													0);
									}
#line 6477 "cfg.tab.c"
    break;

  case 399:
#line 1913 "cfg.y"
                          {
										elems[1].type = STR_ST;
										elems[1].u.data = (yyvsp[0].strval);
										(yyval.intval)=1;
										}
#line 6487 "cfg.tab.c"
    break;

  case 400:
#line 1918 "cfg.y"
                                                 {
										if ((yyvsp[-2].intval)+1>=MAX_ACTION_ELEMS) {
											yyerror("too many arguments "
												"in function\n");
											(yyval.intval)=0;
										}
										elems[(yyvsp[-2].intval)+1].type = STR_ST;
										elems[(yyvsp[-2].intval)+1].u.data = (yyvsp[0].strval);
										(yyval.intval)=(yyvsp[-2].intval)+1;
										}
#line 6502 "cfg.tab.c"
    break;

  case 401:
#line 1928 "cfg.y"
                        {
										elems[1].type = NULLV_ST;
										elems[1].u.data = NULL;
										elems[2].type = NULLV_ST;
										elems[2].u.data = NULL;
										(yyval.intval)=2;
										}
#line 6514 "cfg.tab.c"
    break;

  case 402:
#line 1935 "cfg.y"
                               {
										elems[1].type = NULLV_ST;
										elems[1].u.data = NULL;
										elems[2].type = STR_ST;
										elems[2].u.data = (yyvsp[0].strval);
										(yyval.intval)=2;
										}
#line 6526 "cfg.tab.c"
    break;

  case 403:
#line 1942 "cfg.y"
                                          {
										if ((yyvsp[-1].intval)+1>=MAX_ACTION_ELEMS) {
											yyerror("too many arguments "
												"in function\n");
											(yyval.intval)=0;
										}
										elems[(yyvsp[-1].intval)+1].type = NULLV_ST;
										elems[(yyvsp[-1].intval)+1].u.data = NULL;
										(yyval.intval)=(yyvsp[-1].intval)+1;
										}
#line 6541 "cfg.tab.c"
    break;

  case 404:
#line 1952 "cfg.y"
                          {
										elems[1].type = NUMBER_ST;
										elems[1].u.number = (yyvsp[0].intval);
										(yyval.intval)=1;
										}
#line 6551 "cfg.tab.c"
    break;

  case 405:
#line 1957 "cfg.y"
                                {
										elems[1].type = NULLV_ST;
										elems[1].u.data = NULL;
										elems[2].type = NUMBER_ST;
										elems[2].u.number = (yyvsp[0].intval);
										(yyval.intval)=2;
										}
#line 6563 "cfg.tab.c"
    break;

  case 406:
#line 1964 "cfg.y"
                                                  {
										if ((yyvsp[-2].intval)+1>=MAX_ACTION_ELEMS) {
											yyerror("too many arguments "
												"in function\n");
											(yyval.intval)=0;
										}
										elems[(yyvsp[-2].intval)+1].type = NUMBER_ST;
										elems[(yyvsp[-2].intval)+1].u.number = (yyvsp[0].intval);
										(yyval.intval)=(yyvsp[-2].intval)+1;
										}
#line 6578 "cfg.tab.c"
    break;

  case 407:
#line 1974 "cfg.y"
                             {
										elems[1].type = SCRIPTVAR_ST;
										elems[1].u.data = (yyvsp[0].specval);
										(yyval.intval)=1;
										}
#line 6588 "cfg.tab.c"
    break;

  case 408:
#line 1979 "cfg.y"
                                   {
										elems[1].type = NULLV_ST;
										elems[1].u.data = NULL;
										elems[2].type = SCRIPTVAR_ST;
										elems[2].u.data = (yyvsp[0].specval);
										(yyval.intval)=2;
										}
#line 6600 "cfg.tab.c"
    break;

  case 409:
#line 1986 "cfg.y"
                                                     {
										if ((yyvsp[-2].intval)+1>=MAX_ACTION_ELEMS) {
											yyerror("too many arguments "
												"in function\n");
											(yyval.intval)=0;
										}
										elems[(yyvsp[-2].intval)+1].type = SCRIPTVAR_ST;
										elems[(yyvsp[-2].intval)+1].u.data = (yyvsp[0].specval);
										(yyval.intval)=(yyvsp[-2].intval)+1;
										}
#line 6615 "cfg.tab.c"
    break;

  case 410:
#line 1998 "cfg.y"
                    {
						route_elems[0].type = STRING_ST;
						route_elems[0].u.string = (yyvsp[0].strval);
						(yyval.intval)=1;
			}
#line 6625 "cfg.tab.c"
    break;

  case 411:
#line 2003 "cfg.y"
                          {
						route_elems[0].type = NUMBER_ST;
						route_elems[0].u.number = (long)(yyvsp[0].intval);
						(yyval.intval)=1;
			}
#line 6635 "cfg.tab.c"
    break;

  case 412:
#line 2008 "cfg.y"
                        {
						route_elems[0].type = NULLV_ST;
						route_elems[0].u.data = 0;
						(yyval.intval)=1;
			}
#line 6645 "cfg.tab.c"
    break;

  case 413:
#line 2013 "cfg.y"
                             {
						route_elems[0].type = SCRIPTVAR_ST;
						route_elems[0].u.data = (yyvsp[0].specval);
						(yyval.intval)=1;
			}
#line 6655 "cfg.tab.c"
    break;

  case 414:
#line 2018 "cfg.y"
                                           {
						if ((yyvsp[-2].intval)>=MAX_ACTION_ELEMS) {
							yyerror("too many arguments in function\n");
							(yyval.intval)=-1;
						} else {
							route_elems[(yyvsp[-2].intval)].type = STRING_ST;
							route_elems[(yyvsp[-2].intval)].u.data = (yyvsp[0].strval);
							(yyval.intval)=(yyvsp[-2].intval)+1;
						}
			}
#line 6670 "cfg.tab.c"
    break;

  case 415:
#line 2028 "cfg.y"
                                            {
						if ((yyvsp[-2].intval)>=MAX_ACTION_ELEMS) {
							yyerror("too many arguments in function\n");
							(yyval.intval)=-1;
						} else {
							route_elems[(yyvsp[-2].intval)].type = NUMBER_ST;
							route_elems[(yyvsp[-2].intval)].u.data = (void*)(long)(yyvsp[0].intval);
							(yyval.intval)=(yyvsp[-2].intval)+1;
						}
			}
#line 6685 "cfg.tab.c"
    break;

  case 416:
#line 2038 "cfg.y"
                                               {
						if ((yyvsp[-2].intval)+1>=MAX_ACTION_ELEMS) {
							yyerror("too many arguments in function\n");
							(yyval.intval)=-1;
						} else {
							route_elems[(yyvsp[-2].intval)].type = SCRIPTVAR_ST;
							route_elems[(yyvsp[-2].intval)].u.data = (yyvsp[0].specval);
							(yyval.intval)=(yyvsp[-2].intval)+1;
						}
			}
#line 6700 "cfg.tab.c"
    break;

  case 417:
#line 2048 "cfg.y"
                                          {
						if ((yyvsp[-2].intval)+1>=MAX_ACTION_ELEMS) {
							yyerror("too many arguments in function\n");
							(yyval.intval)=-1;
						} else {
							route_elems[(yyvsp[-2].intval)].type = NULLV_ST;
							route_elems[(yyvsp[-2].intval)].u.data = 0;
							(yyval.intval)=(yyvsp[-2].intval)+1;
						}
			}
#line 6715 "cfg.tab.c"
    break;

  case 418:
#line 2060 "cfg.y"
                             {
				cmd_tmp=(void*)find_acmd_export_t((yyvsp[-2].strval));
				if (cmd_tmp==0){
					yyerrorf("unknown async command <%s>, "
						"missing loadmodule?", (yyvsp[-2].strval));
					(yyval.action)=0;
				}else{
					if (check_acmd_call_params(cmd_tmp,elems,0)<0) {
						yyerrorf("too few parameters "
							"for command <%s>\n", (yyvsp[-2].strval));
						(yyval.action)=0;
					} else {
						elems[0].type = ACMD_ST;
						elems[0].u.data = cmd_tmp;
						mk_action_((yyval.action), AMODULE_T, 1, elems);
					}
				}
			}
#line 6738 "cfg.tab.c"
    break;

  case 419:
#line 2078 "cfg.y"
                                                             {
				cmd_tmp=(void*)find_acmd_export_t((yyvsp[-3].strval));
				if (cmd_tmp==0){
					yyerrorf("unknown async command <%s>, "
						"missing loadmodule?", (yyvsp[-3].strval));
					(yyval.action)=0;
				}else{
					rc = check_acmd_call_params(cmd_tmp,elems,(yyvsp[-1].intval));
					switch (rc) {
					case -1:
						yyerrorf("too few parameters "
							"for async command <%s>\n", (yyvsp[-3].strval));
						(yyval.action)=0;
						break;
					case -2:
						yyerrorf("too many parameters "
							"for async command <%s>\n", (yyvsp[-3].strval));
						(yyval.action)=0;
						break;
					case -3:
						yyerrorf("mandatory parameter "
							" omitted for async command <%s>\n", (yyvsp[-3].strval));
						(yyval.action)=0;
						break;
					default:
						elems[0].type = ACMD_ST;
						elems[0].u.data = cmd_tmp;
						mk_action_((yyval.action), AMODULE_T, (yyvsp[-1].intval)+1, elems);
					}
				}
			}
#line 6774 "cfg.tab.c"
    break;

  case 420:
#line 2109 "cfg.y"
                                                 {
				(yyval.action)=0;
				yyerrorf("bad arguments for command <%s>", (yyvsp[-3].strval));
			}
#line 6783 "cfg.tab.c"
    break;

  case 421:
#line 2113 "cfg.y"
                                   {
				(yyval.action)=0;
				yyerrorf("bare word <%s> found, command calls need '()'", (yyvsp[-1].strval));
			}
#line 6792 "cfg.tab.c"
    break;

  case 422:
#line 2119 "cfg.y"
                                        { mk_action2( (yyval.action), FORWARD_T,
											STRING_ST,
											0,
											(yyvsp[-1].strval),
											0);
										}
#line 6803 "cfg.tab.c"
    break;

  case 423:
#line 2125 "cfg.y"
                                        {
										mk_action2( (yyval.action), FORWARD_T,
											0,
											0,
											0,
											0);
										}
#line 6815 "cfg.tab.c"
    break;

  case 424:
#line 2132 "cfg.y"
                                { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 6821 "cfg.tab.c"
    break;

  case 425:
#line 2133 "cfg.y"
                                              { (yyval.action)=0; yyerror("bad forward "
										"argument"); }
#line 6828 "cfg.tab.c"
    break;

  case 426:
#line 2136 "cfg.y"
                                            { mk_action2( (yyval.action), SEND_T,
											STRING_ST,
											0,
											(yyvsp[-1].strval),
											0);
										}
#line 6839 "cfg.tab.c"
    break;

  case 427:
#line 2142 "cfg.y"
                                                         { mk_action2( (yyval.action), SEND_T,
											STRING_ST,
											STRING_ST,
											(yyvsp[-3].strval),
											(yyvsp[-1].strval));
										}
#line 6850 "cfg.tab.c"
    break;

  case 428:
#line 2148 "cfg.y"
                             { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 6856 "cfg.tab.c"
    break;

  case 429:
#line 2149 "cfg.y"
                                           { (yyval.action)=0; yyerror("bad send"
													"argument"); }
#line 6863 "cfg.tab.c"
    break;

  case 430:
#line 2151 "cfg.y"
                                                         {
			mk_action2( (yyval.action), ASSERT_T, EXPR_ST, STRING_ST, (yyvsp[-3].expr), (yyvsp[-1].strval));
			}
#line 6871 "cfg.tab.c"
    break;

  case 431:
#line 2154 "cfg.y"
                                        {mk_action2( (yyval.action), DROP_T,0, 0, 0, 0); }
#line 6877 "cfg.tab.c"
    break;

  case 432:
#line 2155 "cfg.y"
                                                        {mk_action2( (yyval.action), DROP_T,0, 0, 0, 0); }
#line 6883 "cfg.tab.c"
    break;

  case 433:
#line 2156 "cfg.y"
                                        {mk_action2( (yyval.action), EXIT_T,0, 0, 0, 0); }
#line 6889 "cfg.tab.c"
    break;

  case 434:
#line 2157 "cfg.y"
                                                        {mk_action2( (yyval.action), EXIT_T,0, 0, 0, 0); }
#line 6895 "cfg.tab.c"
    break;

  case 435:
#line 2158 "cfg.y"
                                                {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST,
																0,
																(void*)(yyvsp[-1].intval),
																0);
												}
#line 6906 "cfg.tab.c"
    break;

  case 436:
#line 2164 "cfg.y"
                                                        {mk_action2( (yyval.action), RETURN_T,
																SCRIPTVAR_ST,
																0,
																(void*)(yyvsp[-1].specval),
																0);
												}
#line 6917 "cfg.tab.c"
    break;

  case 437:
#line 2170 "cfg.y"
                                        {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST,
																0,
																(void*)1,
																0);
												}
#line 6928 "cfg.tab.c"
    break;

  case 438:
#line 2176 "cfg.y"
                                                        {mk_action2( (yyval.action), RETURN_T,
																NUMBER_ST,
																0,
																(void*)1,
																0);
												}
#line 6939 "cfg.tab.c"
    break;

  case 439:
#line 2182 "cfg.y"
                                                {mk_action2( (yyval.action), LOG_T, NUMBER_ST,
													STRING_ST,(void*)4,(yyvsp[-1].strval));
									}
#line 6947 "cfg.tab.c"
    break;

  case 440:
#line 2185 "cfg.y"
                                                                {mk_action2( (yyval.action), LOG_T,
																NUMBER_ST,
																STRING_ST,
																(void*)(yyvsp[-3].intval),
																(yyvsp[-1].strval));
												}
#line 6958 "cfg.tab.c"
    break;

  case 441:
#line 2191 "cfg.y"
                                { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 6964 "cfg.tab.c"
    break;

  case 442:
#line 2192 "cfg.y"
                                              { (yyval.action)=0; yyerror("bad log"
									"argument"); }
#line 6971 "cfg.tab.c"
    break;

  case 443:
#line 2194 "cfg.y"
                                               {
			mk_action2((yyval.action), SETFLAG_T, NUMBER_ST, 0, (void *)(yyvsp[-1].intval), 0 );
			}
#line 6979 "cfg.tab.c"
    break;

  case 444:
#line 2197 "cfg.y"
                                           {mk_action2((yyval.action), SETFLAG_T, STR_ST, 0,
													(void *)(yyvsp[-1].strval), 0 ); }
#line 6986 "cfg.tab.c"
    break;

  case 445:
#line 2199 "cfg.y"
                                { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 6992 "cfg.tab.c"
    break;

  case 446:
#line 2200 "cfg.y"
                                                 {mk_action2( (yyval.action), RESETFLAG_T,
										NUMBER_ST, 0, (void *)(yyvsp[-1].intval), 0 ); }
#line 6999 "cfg.tab.c"
    break;

  case 447:
#line 2202 "cfg.y"
                                             {mk_action2( (yyval.action), RESETFLAG_T,
										STR_ST, 0, (void *)(yyvsp[-1].strval), 0 ); }
#line 7006 "cfg.tab.c"
    break;

  case 448:
#line 2204 "cfg.y"
                                  { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 7012 "cfg.tab.c"
    break;

  case 449:
#line 2205 "cfg.y"
                                                 {mk_action2( (yyval.action), ISFLAGSET_T,
										NUMBER_ST, 0, (void *)(yyvsp[-1].intval), 0 ); }
#line 7019 "cfg.tab.c"
    break;

  case 450:
#line 2207 "cfg.y"
                                             {mk_action2( (yyval.action), ISFLAGSET_T,
										STR_ST, 0, (void *)(yyvsp[-1].strval), 0 ); }
#line 7026 "cfg.tab.c"
    break;

  case 451:
#line 2209 "cfg.y"
                                  { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 7032 "cfg.tab.c"
    break;

  case 452:
#line 2210 "cfg.y"
                                                             {mk_action2( (yyval.action),
													SETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[-3].intval), (void *)(yyvsp[-1].intval) ); }
#line 7041 "cfg.tab.c"
    break;

  case 453:
#line 2214 "cfg.y"
                                                         {mk_action2( (yyval.action),
													SETBFLAG_T,
													NUMBER_ST, STR_ST,
													(void *)(yyvsp[-3].intval), (void *)(yyvsp[-1].strval) ); }
#line 7050 "cfg.tab.c"
    break;

  case 454:
#line 2218 "cfg.y"
                                                {mk_action2( (yyval.action), SETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[-1].intval) ); }
#line 7058 "cfg.tab.c"
    break;

  case 455:
#line 2221 "cfg.y"
                                            {mk_action2( (yyval.action), SETBFLAG_T,
													NUMBER_ST, STR_ST,
													0, (void *)(yyvsp[-1].strval) ); }
#line 7066 "cfg.tab.c"
    break;

  case 456:
#line 2224 "cfg.y"
                                 { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 7072 "cfg.tab.c"
    break;

  case 457:
#line 2225 "cfg.y"
                                                               {mk_action2( (yyval.action),
													RESETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[-3].intval), (void *)(yyvsp[-1].intval) ); }
#line 7081 "cfg.tab.c"
    break;

  case 458:
#line 2229 "cfg.y"
                                                           {mk_action2( (yyval.action),
													RESETBFLAG_T,
													NUMBER_ST, STR_ST,
													(void *)(yyvsp[-3].intval), (void *)(yyvsp[-1].strval) ); }
#line 7090 "cfg.tab.c"
    break;

  case 459:
#line 2233 "cfg.y"
                                                  {mk_action2( (yyval.action),
													RESETBFLAG_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[-1].intval) ); }
#line 7099 "cfg.tab.c"
    break;

  case 460:
#line 2237 "cfg.y"
                                              {mk_action2( (yyval.action),
													RESETBFLAG_T,
													NUMBER_ST, STR_ST,
													0, (void *)(yyvsp[-1].strval) ); }
#line 7108 "cfg.tab.c"
    break;

  case 461:
#line 2241 "cfg.y"
                                   { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 7114 "cfg.tab.c"
    break;

  case 462:
#line 2242 "cfg.y"
                                                               {mk_action2( (yyval.action),
													ISBFLAGSET_T,
													NUMBER_ST, NUMBER_ST,
													(void *)(yyvsp[-3].intval), (void *)(yyvsp[-1].intval) ); }
#line 7123 "cfg.tab.c"
    break;

  case 463:
#line 2246 "cfg.y"
                                                           {mk_action2( (yyval.action),
													ISBFLAGSET_T,
													NUMBER_ST, STR_ST,
													(void *)(yyvsp[-3].intval), (void *)(yyvsp[-1].strval) ); }
#line 7132 "cfg.tab.c"
    break;

  case 464:
#line 2250 "cfg.y"
                                                  {mk_action2( (yyval.action),
													ISBFLAGSET_T,
													NUMBER_ST, NUMBER_ST,
													0, (void *)(yyvsp[-1].intval) ); }
#line 7141 "cfg.tab.c"
    break;

  case 465:
#line 2254 "cfg.y"
                                              {mk_action2( (yyval.action),
													ISBFLAGSET_T,
													NUMBER_ST, STR_ST,
													0, (void *)(yyvsp[-1].strval) ); }
#line 7150 "cfg.tab.c"
    break;

  case 466:
#line 2258 "cfg.y"
                                   { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 7156 "cfg.tab.c"
    break;

  case 467:
#line 2259 "cfg.y"
                                                          {mk_action2( (yyval.action), ERROR_T,
																STRING_ST,
																STRING_ST,
																(yyvsp[-3].strval),
																(yyvsp[-1].strval));
												  }
#line 7167 "cfg.tab.c"
    break;

  case 468:
#line 2265 "cfg.y"
                              { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7173 "cfg.tab.c"
    break;

  case 469:
#line 2266 "cfg.y"
                                            { (yyval.action)=0; yyerror("bad error"
														"argument"); }
#line 7180 "cfg.tab.c"
    break;

  case 470:
#line 2268 "cfg.y"
                                                        {
						i_tmp = get_script_route_idx( (yyvsp[-1].strval), sroutes->request,
							RT_NO, 0);
						if (i_tmp==-1) yyerror("too many script routes");
						mk_action2( (yyval.action), ROUTE_T, NUMBER_ST,
							0, (void*)(long)i_tmp, 0);
					}
#line 7192 "cfg.tab.c"
    break;

  case 471:
#line 2276 "cfg.y"
                                                                        {
						i_tmp = get_script_route_idx( (yyvsp[-3].strval), sroutes->request,
							RT_NO, 0);
						if (i_tmp==-1) yyerror("too many script routes");
						if ((yyvsp[-1].intval) <= 0) yyerror("too many route parameters");

						/* duplicate the list */
						a_tmp = pkg_malloc((yyvsp[-1].intval) * sizeof(action_elem_t));
						if (!a_tmp) {
							yyerror("no more pkg memory");
							YYABORT;
						}
						memcpy(a_tmp, route_elems, (yyvsp[-1].intval)*sizeof(action_elem_t));

						mk_action3( (yyval.action), ROUTE_T, NUMBER_ST,	/* route idx */
							NUMBER_ST,					/* number of params */
							SCRIPTVAR_ELEM_ST,			/* parameters */
							(void*)(long)i_tmp,
							(void*)(long)(yyvsp[-1].intval),
							(void*)a_tmp);
					}
#line 7218 "cfg.tab.c"
    break;

  case 472:
#line 2298 "cfg.y"
                              { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7224 "cfg.tab.c"
    break;

  case 473:
#line 2299 "cfg.y"
                                            { (yyval.action)=0; yyerror("bad route"
						"argument"); }
#line 7231 "cfg.tab.c"
    break;

  case 474:
#line 2301 "cfg.y"
                                                { mk_action2( (yyval.action), SET_HOST_T, STR_ST,
														0, (yyvsp[-1].strval), 0); }
#line 7238 "cfg.tab.c"
    break;

  case 475:
#line 2303 "cfg.y"
                                 { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7244 "cfg.tab.c"
    break;

  case 476:
#line 2304 "cfg.y"
                                               { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
#line 7251 "cfg.tab.c"
    break;

  case 477:
#line 2307 "cfg.y"
                                              { mk_action2( (yyval.action), PREFIX_T, STR_ST,
														0, (yyvsp[-1].strval), 0); }
#line 7258 "cfg.tab.c"
    break;

  case 478:
#line 2309 "cfg.y"
                               { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7264 "cfg.tab.c"
    break;

  case 479:
#line 2310 "cfg.y"
                                             { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
#line 7271 "cfg.tab.c"
    break;

  case 480:
#line 2312 "cfg.y"
                                                  { mk_action2( (yyval.action), STRIP_TAIL_T,
									NUMBER_ST, 0, (void *) (yyvsp[-1].intval), 0); }
#line 7278 "cfg.tab.c"
    break;

  case 481:
#line 2314 "cfg.y"
                                   { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7284 "cfg.tab.c"
    break;

  case 482:
#line 2315 "cfg.y"
                                                 { (yyval.action)=0; yyerror("bad argument, "
														"number expected"); }
#line 7291 "cfg.tab.c"
    break;

  case 483:
#line 2318 "cfg.y"
                                             { mk_action2( (yyval.action), STRIP_T, NUMBER_ST,
														0, (void *) (yyvsp[-1].intval), 0); }
#line 7298 "cfg.tab.c"
    break;

  case 484:
#line 2320 "cfg.y"
                              { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7304 "cfg.tab.c"
    break;

  case 485:
#line 2321 "cfg.y"
                                            { (yyval.action)=0; yyerror("bad argument, "
														"number expected"); }
#line 7311 "cfg.tab.c"
    break;

  case 486:
#line 2323 "cfg.y"
                                                                  {
			{
				qvalue_t q;

				rc = str2q(&q, (yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
				if (rc < 0)
					yyerrorf("bad qvalue (%.*s): %s",
							 strlen((yyvsp[-1].strval)), (yyvsp[-1].strval), qverr2str(rc));

				mk_action2( (yyval.action), APPEND_BRANCH_T, STR_ST, NUMBER_ST, (yyvsp[-3].strval),
						(void *)(long)q);
			}
		}
#line 7329 "cfg.tab.c"
    break;

  case 487:
#line 2336 "cfg.y"
                                                     { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, (yyvsp[-1].strval), (void *)Q_UNSPECIFIED) ; }
#line 7336 "cfg.tab.c"
    break;

  case 488:
#line 2338 "cfg.y"
                                              { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, 0, (void *)Q_UNSPECIFIED) ; }
#line 7343 "cfg.tab.c"
    break;

  case 489:
#line 2340 "cfg.y"
                                { mk_action2( (yyval.action), APPEND_BRANCH_T,
						STR_ST, NUMBER_ST, 0, (void *)Q_UNSPECIFIED ) ; }
#line 7350 "cfg.tab.c"
    break;

  case 490:
#line 2342 "cfg.y"
                                                     {
						mk_action1((yyval.action), REMOVE_BRANCH_T, NUMBER_ST, (void*)(yyvsp[-1].intval));}
#line 7357 "cfg.tab.c"
    break;

  case 491:
#line 2344 "cfg.y"
                                                         {
						mk_action1( (yyval.action), REMOVE_BRANCH_T, SCRIPTVAR_ST, (yyvsp[-1].specval));}
#line 7364 "cfg.tab.c"
    break;

  case 492:
#line 2346 "cfg.y"
                                                              {
				spec = (pv_spec_t*)pkg_malloc(sizeof(pv_spec_t));
				memset(spec, 0, sizeof(pv_spec_t));
				tstr.s = (yyvsp[-3].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_spec(&tstr, spec)==NULL)
				{
					yyerror("unknown script variable in first parameter");
				}
				if(!pv_is_w(spec))
					yyerror("read-only script variable in first parameter");

				pvmodel = 0;
				tstr.s = (yyvsp[-1].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
				{
					yyerror("error in second parameter");
				}

				mk_action2( (yyval.action), PV_PRINTF_T,
						SCRIPTVAR_ST, SCRIPTVAR_ELEM_ST, spec, pvmodel) ;
			}
#line 7392 "cfg.tab.c"
    break;

  case 493:
#line 2369 "cfg.y"
                                                                  {
				if(!pv_is_w((yyvsp[-3].specval)))
					yyerror("read-only script variable in first parameter");
				pvmodel = 0;
				tstr.s = (yyvsp[-1].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
				{
					yyerror("error in second parameter");
				}

				mk_action2( (yyval.action), PV_PRINTF_T,
						SCRIPTVAR_ST, SCRIPTVAR_ELEM_ST, (yyvsp[-3].specval), pvmodel) ;
			}
#line 7411 "cfg.tab.c"
    break;

  case 494:
#line 2384 "cfg.y"
                                                    { mk_action2( (yyval.action), SET_HOSTPORT_T,
														STR_ST, 0, (yyvsp[-1].strval), 0); }
#line 7418 "cfg.tab.c"
    break;

  case 495:
#line 2386 "cfg.y"
                                     { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7424 "cfg.tab.c"
    break;

  case 496:
#line 2387 "cfg.y"
                                                   { (yyval.action)=0; yyerror("bad argument,"
												" string expected"); }
#line 7431 "cfg.tab.c"
    break;

  case 497:
#line 2389 "cfg.y"
                                                { mk_action2( (yyval.action), SET_PORT_T, STR_ST,
														0, (yyvsp[-1].strval), 0); }
#line 7438 "cfg.tab.c"
    break;

  case 498:
#line 2391 "cfg.y"
                                 { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7444 "cfg.tab.c"
    break;

  case 499:
#line 2392 "cfg.y"
                                               { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
#line 7451 "cfg.tab.c"
    break;

  case 500:
#line 2394 "cfg.y"
                                                { mk_action2( (yyval.action), SET_USER_T,
														STR_ST, 0, (yyvsp[-1].strval), 0); }
#line 7458 "cfg.tab.c"
    break;

  case 501:
#line 2396 "cfg.y"
                                 { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7464 "cfg.tab.c"
    break;

  case 502:
#line 2397 "cfg.y"
                                               { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
#line 7471 "cfg.tab.c"
    break;

  case 503:
#line 2399 "cfg.y"
                                                    { mk_action2( (yyval.action), SET_USERPASS_T,
														STR_ST, 0, (yyvsp[-1].strval), 0); }
#line 7478 "cfg.tab.c"
    break;

  case 504:
#line 2401 "cfg.y"
                                     { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7484 "cfg.tab.c"
    break;

  case 505:
#line 2402 "cfg.y"
                                                   { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
#line 7491 "cfg.tab.c"
    break;

  case 506:
#line 2404 "cfg.y"
                                               { mk_action2( (yyval.action), SET_URI_T, STR_ST,
														0, (yyvsp[-1].strval), 0); }
#line 7498 "cfg.tab.c"
    break;

  case 507:
#line 2406 "cfg.y"
                                { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7504 "cfg.tab.c"
    break;

  case 508:
#line 2407 "cfg.y"
                                              { (yyval.action)=0; yyerror("bad argument, "
										"string expected"); }
#line 7511 "cfg.tab.c"
    break;

  case 509:
#line 2409 "cfg.y"
                                           { mk_action2( (yyval.action), REVERT_URI_T, 0,0,0,0); }
#line 7517 "cfg.tab.c"
    break;

  case 510:
#line 2410 "cfg.y"
                             { mk_action2( (yyval.action), REVERT_URI_T, 0,0,0,0); }
#line 7523 "cfg.tab.c"
    break;

  case 511:
#line 2411 "cfg.y"
                                                  { mk_action2( (yyval.action), SET_DSTURI_T,
													STR_ST, 0, (yyvsp[-1].strval), 0); }
#line 7530 "cfg.tab.c"
    break;

  case 512:
#line 2413 "cfg.y"
                                   { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7536 "cfg.tab.c"
    break;

  case 513:
#line 2414 "cfg.y"
                                                 { (yyval.action)=0; yyerror("bad argument, "
										"string expected"); }
#line 7543 "cfg.tab.c"
    break;

  case 514:
#line 2416 "cfg.y"
                                             { mk_action2( (yyval.action), RESET_DSTURI_T,
															0,0,0,0); }
#line 7550 "cfg.tab.c"
    break;

  case 515:
#line 2418 "cfg.y"
                               { mk_action2( (yyval.action), RESET_DSTURI_T, 0,0,0,0); }
#line 7556 "cfg.tab.c"
    break;

  case 516:
#line 2419 "cfg.y"
                                            { mk_action2( (yyval.action), ISDSTURISET_T, 0,0,0,0);}
#line 7562 "cfg.tab.c"
    break;

  case 517:
#line 2420 "cfg.y"
                              { mk_action2( (yyval.action), ISDSTURISET_T, 0,0,0,0); }
#line 7568 "cfg.tab.c"
    break;

  case 518:
#line 2421 "cfg.y"
                                                { mk_action2( (yyval.action), FORCE_RPORT_T,
															0, 0, 0, 0); }
#line 7575 "cfg.tab.c"
    break;

  case 519:
#line 2423 "cfg.y"
                                        { mk_action2( (yyval.action), FORCE_RPORT_T,0, 0, 0, 0); }
#line 7581 "cfg.tab.c"
    break;

  case 520:
#line 2424 "cfg.y"
                                                        {
					mk_action2( (yyval.action), FORCE_LOCAL_RPORT_T,0, 0, 0, 0); }
#line 7588 "cfg.tab.c"
    break;

  case 521:
#line 2426 "cfg.y"
                                                                {
					mk_action2( (yyval.action), FORCE_LOCAL_RPORT_T,0, 0, 0, 0); }
#line 7595 "cfg.tab.c"
    break;

  case 522:
#line 2428 "cfg.y"
                                                        {
				mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,NUMBER_ST, 0,
					(void*)(yyvsp[-1].intval), 0);
		}
#line 7604 "cfg.tab.c"
    break;

  case 523:
#line 2432 "cfg.y"
                                                {
				mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,0, 0, 0, 0);
		}
#line 7612 "cfg.tab.c"
    break;

  case 524:
#line 2435 "cfg.y"
                                                                {
				mk_action2( (yyval.action), FORCE_TCP_ALIAS_T,0, 0, 0, 0);
		}
#line 7620 "cfg.tab.c"
    break;

  case 525:
#line 2438 "cfg.y"
                                                        {(yyval.action)=0;
					yyerror("bad argument, number expected");
					}
#line 7628 "cfg.tab.c"
    break;

  case 526:
#line 2441 "cfg.y"
                                                          {
								mk_action2( (yyval.action), SET_ADV_ADDR_T, STR_ST,
											0, (yyvsp[-1].strval), 0);
								}
#line 7637 "cfg.tab.c"
    break;

  case 527:
#line 2445 "cfg.y"
                                                      { (yyval.action)=0; yyerror("bad argument, "
														"string expected"); }
#line 7644 "cfg.tab.c"
    break;

  case 528:
#line 2447 "cfg.y"
                                        {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7650 "cfg.tab.c"
    break;

  case 529:
#line 2448 "cfg.y"
                                                    {
								tstr.s = int2str((yyvsp[-1].intval), &tstr.len);
								if (!(tmp = pkg_malloc(tstr.len + 1))) {
										LM_CRIT("out of pkg memory\n");
										(yyval.action) = 0;
										YYABORT;
								} else {
									memcpy(tmp, tstr.s, tstr.len);
									tmp[tstr.len] = '\0';
									mk_action2((yyval.action), SET_ADV_PORT_T, STR_ST,
											   0, tmp, 0);
								}
								            }
#line 7668 "cfg.tab.c"
    break;

  case 530:
#line 2461 "cfg.y"
                                                    {
								mk_action2((yyval.action), SET_ADV_PORT_T,
										   STR_ST, NOSUBTYPE,
										   (yyvsp[-1].strval), NULL);
								}
#line 7678 "cfg.tab.c"
    break;

  case 531:
#line 2466 "cfg.y"
                                                   { (yyval.action)=0; yyerror("bad argument "
						"(string or integer expected)"); }
#line 7685 "cfg.tab.c"
    break;

  case 532:
#line 2468 "cfg.y"
                                      {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7691 "cfg.tab.c"
    break;

  case 533:
#line 2469 "cfg.y"
                                                            {
								mk_action2( (yyval.action), FORCE_SEND_SOCKET_T,
									SOCKID_ST, 0, (yyvsp[-1].sockid), 0);
								}
#line 7700 "cfg.tab.c"
    break;

  case 534:
#line 2473 "cfg.y"
                                                        { (yyval.action)=0; yyerror("bad argument,"
								" proto:host[:port] expected");
								}
#line 7708 "cfg.tab.c"
    break;

  case 535:
#line 2476 "cfg.y"
                                          {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7714 "cfg.tab.c"
    break;

  case 536:
#line 2477 "cfg.y"
                                                          {
								mk_action1( (yyval.action), SERIALIZE_BRANCHES_T,
									NUMBER_ST, (void*)(long)(yyvsp[-1].intval));
								}
#line 7723 "cfg.tab.c"
    break;

  case 537:
#line 2481 "cfg.y"
                                                                       {
								mk_action2( (yyval.action), SERIALIZE_BRANCHES_T,
									NUMBER_ST, NUMBER_ST,
									(void*)(long)(yyvsp[-3].intval), (void*)(long)(yyvsp[-1].intval));
								}
#line 7733 "cfg.tab.c"
    break;

  case 538:
#line 2486 "cfg.y"
                                                         {(yyval.action)=0; yyerror("bad argument,"
								" number expected");
								}
#line 7741 "cfg.tab.c"
    break;

  case 539:
#line 2489 "cfg.y"
                                           {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7747 "cfg.tab.c"
    break;

  case 540:
#line 2490 "cfg.y"
                                              {
								mk_action2( (yyval.action), NEXT_BRANCHES_T, 0, 0, 0, 0);
								}
#line 7755 "cfg.tab.c"
    break;

  case 541:
#line 2493 "cfg.y"
                                                    {(yyval.action)=0; yyerror("no argument is"
								" expected");
								}
#line 7763 "cfg.tab.c"
    break;

  case 542:
#line 2496 "cfg.y"
                                      {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7769 "cfg.tab.c"
    break;

  case 543:
#line 2497 "cfg.y"
                                                     {
								mk_action2( (yyval.action), USE_BLACKLIST_T,
									STRING_ST, 0, (yyvsp[-1].strval), 0);
								}
#line 7778 "cfg.tab.c"
    break;

  case 544:
#line 2501 "cfg.y"
                                                    {(yyval.action)=0; yyerror("bad argument,"
								" string expected");
								}
#line 7786 "cfg.tab.c"
    break;

  case 545:
#line 2504 "cfg.y"
                                      {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7792 "cfg.tab.c"
    break;

  case 546:
#line 2505 "cfg.y"
                                                       {
								mk_action2( (yyval.action), UNUSE_BLACKLIST_T,
									STRING_ST, 0, (yyvsp[-1].strval), 0);
								}
#line 7801 "cfg.tab.c"
    break;

  case 547:
#line 2509 "cfg.y"
                                                      {(yyval.action)=0; yyerror("bad argument,"
								" string expected");
								}
#line 7809 "cfg.tab.c"
    break;

  case 548:
#line 2512 "cfg.y"
                                        {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 7815 "cfg.tab.c"
    break;

  case 549:
#line 2513 "cfg.y"
                                                                             {
									mk_action3( (yyval.action), CACHE_STORE_T,
													STR_ST,
													STR_ST,
													STR_ST,
													(yyvsp[-5].strval),
													(yyvsp[-3].strval),
													(yyvsp[-1].strval));
							}
#line 7829 "cfg.tab.c"
    break;

  case 550:
#line 2523 "cfg.y"
                                                                       {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-7].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-5].strval);
								elems[2].type = STR_ST;
								elems[2].u.data = (yyvsp[-3].strval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[-1].intval);
								mk_action_((yyval.action), CACHE_STORE_T, 4, elems);
							}
#line 7845 "cfg.tab.c"
    break;

  case 551:
#line 2535 "cfg.y"
                                                                       {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-7].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-5].strval);
								elems[2].type = STR_ST;
								elems[2].u.data = (yyvsp[-3].strval);
								elems[3].type = SCRIPTVAR_ST;
								elems[3].u.data = (yyvsp[-1].specval);
								mk_action_((yyval.action), CACHE_STORE_T, 4, elems);
							}
#line 7861 "cfg.tab.c"
    break;

  case 552:
#line 2547 "cfg.y"
                                                                 {
									mk_action2( (yyval.action), CACHE_REMOVE_T,
													STR_ST,
													STR_ST,
													(yyvsp[-3].strval),
													(yyvsp[-1].strval));
							}
#line 7873 "cfg.tab.c"
    break;

  case 553:
#line 2554 "cfg.y"
                                                                                 {
									mk_action3( (yyval.action), CACHE_FETCH_T,
													STR_ST,
													STR_ST,
													SCRIPTVAR_ST,
													(yyvsp[-5].strval),
													(yyvsp[-3].strval),
													(yyvsp[-1].specval));
							}
#line 7887 "cfg.tab.c"
    break;

  case 554:
#line 2563 "cfg.y"
                                                                                         {
									mk_action3( (yyval.action), CACHE_COUNTER_FETCH_T,
													STR_ST,
													STR_ST,
													SCRIPTVAR_ST,
													(yyvsp[-5].strval),
													(yyvsp[-3].strval),
													(yyvsp[-1].specval));
							}
#line 7901 "cfg.tab.c"
    break;

  case 555:
#line 2572 "cfg.y"
                                                                                        {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-7].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-5].strval);
								elems[2].type = NUMBER_ST;
								elems[2].u.number = (yyvsp[-3].intval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[-1].intval);
								mk_action_((yyval.action), CACHE_ADD_T, 4, elems);
							}
#line 7917 "cfg.tab.c"
    break;

  case 556:
#line 2583 "cfg.y"
                                                                                            {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-7].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-5].strval);
								elems[2].type = SCRIPTVAR_ST;
								elems[2].u.data = (yyvsp[-3].specval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[-1].intval);
								mk_action_((yyval.action), CACHE_ADD_T, 4, elems);
							}
#line 7933 "cfg.tab.c"
    break;

  case 557:
#line 2594 "cfg.y"
                                                                                                         {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-9].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-7].strval);
								elems[2].type = NUMBER_ST;
								elems[2].u.number = (yyvsp[-5].intval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[-3].intval);
								elems[4].type = SCRIPTVAR_ST;
								elems[4].u.data = (yyvsp[-1].specval);
								mk_action_((yyval.action), CACHE_ADD_T, 5, elems);
							}
#line 7951 "cfg.tab.c"
    break;

  case 558:
#line 2607 "cfg.y"
                                                                                                             {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-9].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-7].strval);
								elems[2].type = SCRIPTVAR_ST;
								elems[2].u.data = (yyvsp[-5].specval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[-3].intval);
								elems[4].type = SCRIPTVAR_ST;
								elems[4].u.data = (yyvsp[-1].specval);
								mk_action_((yyval.action), CACHE_ADD_T, 5, elems);
							}
#line 7969 "cfg.tab.c"
    break;

  case 559:
#line 2620 "cfg.y"
                                                                                        {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-7].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-5].strval);
								elems[2].type = NUMBER_ST;
								elems[2].u.number = (yyvsp[-3].intval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[-1].intval);
								mk_action_((yyval.action), CACHE_SUB_T, 4, elems);
							}
#line 7985 "cfg.tab.c"
    break;

  case 560:
#line 2631 "cfg.y"
                                                                                            {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-7].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-5].strval);
								elems[2].type = SCRIPTVAR_ST;
								elems[2].u.data = (yyvsp[-3].specval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[-1].intval);
								mk_action_((yyval.action), CACHE_SUB_T, 4, elems);
							}
#line 8001 "cfg.tab.c"
    break;

  case 561:
#line 2642 "cfg.y"
                                                                                                         {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-9].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-7].strval);
								elems[2].type = NUMBER_ST;
								elems[2].u.number = (yyvsp[-5].intval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[-3].intval);
								elems[4].type = SCRIPTVAR_ST;
								elems[4].u.data = (yyvsp[-1].specval);
								mk_action_((yyval.action), CACHE_SUB_T, 5, elems);
							}
#line 8019 "cfg.tab.c"
    break;

  case 562:
#line 2655 "cfg.y"
                                                                                                             {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-9].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-7].strval);
								elems[2].type = SCRIPTVAR_ST;
								elems[2].u.data = (yyvsp[-5].specval);
								elems[3].type = NUMBER_ST;
								elems[3].u.number = (yyvsp[-3].intval);
								elems[4].type = SCRIPTVAR_ST;
								elems[4].u.data = (yyvsp[-1].specval);
								mk_action_((yyval.action), CACHE_SUB_T, 5, elems);
							}
#line 8037 "cfg.tab.c"
    break;

  case 563:
#line 2668 "cfg.y"
                                                                                 {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-5].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-3].strval);
								elems[2].type = STR_ST;
								elems[2].u.data = (yyvsp[-1].strval);
								mk_action_((yyval.action), CACHE_RAW_QUERY_T, 3, elems);
							}
#line 8051 "cfg.tab.c"
    break;

  case 564:
#line 2677 "cfg.y"
                                                                    {
								elems[0].type = STR_ST;
								elems[0].u.data = (yyvsp[-3].strval);
								elems[1].type = STR_ST;
								elems[1].u.data = (yyvsp[-1].strval);
								mk_action_((yyval.action), CACHE_RAW_QUERY_T, 2, elems);
							}
#line 8063 "cfg.tab.c"
    break;

  case 565:
#line 2684 "cfg.y"
                                        {
								cmd_tmp=(void*)find_cmd_export_t((yyvsp[-2].strval), rt);
								if (cmd_tmp==0){
									if (find_cmd_export_t((yyvsp[-2].strval), 0)) {
										yyerrorf("Command <%s> cannot be "
											"used in the block\n", (yyvsp[-2].strval));
									} else {
										yyerrorf("unknown command <%s>, "
											"missing loadmodule?", (yyvsp[-2].strval));
									}
									(yyval.action)=0;
								}else{
									if (check_cmd_call_params(cmd_tmp,elems,0)<0) {
										yyerrorf("too few parameters "
											"for command <%s>\n", (yyvsp[-2].strval));
										(yyval.action)=0;
									} else {
										elems[0].type = CMD_ST;
										elems[0].u.data = cmd_tmp;
										mk_action_((yyval.action), MODULE_T, 1, elems);
									}
								}
							}
#line 8091 "cfg.tab.c"
    break;

  case 566:
#line 2707 "cfg.y"
                                                        {
								cmd_tmp=(void*)find_cmd_export_t((yyvsp[-3].strval), rt);
								if (cmd_tmp==0){
									if (find_cmd_export_t((yyvsp[-3].strval), 0)) {
										yyerrorf("Command <%s> cannot be "
											"used in the block\n", (yyvsp[-3].strval));
									} else {
										yyerrorf("unknown command <%s>, "
											"missing loadmodule?", (yyvsp[-3].strval));
									}
									(yyval.action)=0;
								}else{
									rc = check_cmd_call_params(cmd_tmp,elems,(yyvsp[-1].intval));
									switch (rc) {
									case -1:
										yyerrorf("too few parameters "
											"for command <%s>\n", (yyvsp[-3].strval));
										(yyval.action)=0;
										break;
									case -2:
										yyerrorf("too many parameters "
											"for command <%s>\n", (yyvsp[-3].strval));
										(yyval.action)=0;
										break;
									case -3:
										yyerrorf("mandatory parameter "
											"omitted for command <%s>\n", (yyvsp[-3].strval));
										(yyval.action)=0;
										break;
									default:
										elems[0].type = CMD_ST;
										elems[0].u.data = cmd_tmp;
										mk_action_((yyval.action), MODULE_T, (yyvsp[-1].intval)+1, elems);
									}
								}
							}
#line 8132 "cfg.tab.c"
    break;

  case 567:
#line 2743 "cfg.y"
                                         { (yyval.action)=0; yyerrorf("bad arguments for "
												"command <%s>", (yyvsp[-3].strval)); }
#line 8139 "cfg.tab.c"
    break;

  case 568:
#line 2745 "cfg.y"
                           { (yyval.action)=0;
			yyerrorf("bare word <%s> found, command calls need '()'", (yyvsp[-1].strval));
			}
#line 8147 "cfg.tab.c"
    break;

  case 569:
#line 2748 "cfg.y"
                                            {
				mk_action1((yyval.action), XDBG_T, STR_ST, (yyvsp[-1].strval));	}
#line 8154 "cfg.tab.c"
    break;

  case 570:
#line 2750 "cfg.y"
                                                   {
				mk_action1((yyval.action), XDBG_T, STR_ST, (yyvsp[-1].strval));	}
#line 8161 "cfg.tab.c"
    break;

  case 571:
#line 2752 "cfg.y"
                                            {
				mk_action1((yyval.action), XLOG_T, STR_ST, (yyvsp[-1].strval)); }
#line 8168 "cfg.tab.c"
    break;

  case 572:
#line 2754 "cfg.y"
                                                   {
				mk_action1((yyval.action), XLOG_T, STR_ST, (yyvsp[-1].strval)); }
#line 8175 "cfg.tab.c"
    break;

  case 573:
#line 2756 "cfg.y"
                                                         {
				mk_action2((yyval.action), XLOG_T, STR_ST, STR_ST, (yyvsp[-3].strval), (yyvsp[-1].strval)); }
#line 8182 "cfg.tab.c"
    break;

  case 574:
#line 2758 "cfg.y"
                                                                {
				mk_action2((yyval.action), XLOG_T, STR_ST, STR_ST, (yyvsp[-3].strval), (yyvsp[-1].strval)); }
#line 8189 "cfg.tab.c"
    break;

  case 575:
#line 2760 "cfg.y"
                                                   {
				mk_action1((yyval.action), RAISE_EVENT_T, STR_ST, (yyvsp[-1].strval)); }
#line 8196 "cfg.tab.c"
    break;

  case 576:
#line 2762 "cfg.y"
                                                                    {
				mk_action2((yyval.action), RAISE_EVENT_T, STR_ST, SCRIPTVAR_ST, (yyvsp[-3].strval), (yyvsp[-1].specval)); }
#line 8203 "cfg.tab.c"
    break;

  case 577:
#line 2764 "cfg.y"
                                                                                     {
				mk_action3((yyval.action), RAISE_EVENT_T, STR_ST, SCRIPTVAR_ST,
					SCRIPTVAR_ST, (yyvsp[-5].strval), (yyvsp[-3].specval), (yyvsp[-1].specval)); }
#line 8211 "cfg.tab.c"
    break;

  case 578:
#line 2767 "cfg.y"
                                                                    {
				mk_action2((yyval.action), SUBSCRIBE_EVENT_T, STR_ST, STR_ST, (yyvsp[-3].strval), (yyvsp[-1].strval)); }
#line 8218 "cfg.tab.c"
    break;

  case 579:
#line 2769 "cfg.y"
                                                                                 {
				mk_action3((yyval.action), SUBSCRIBE_EVENT_T, STR_ST, STR_ST,
					NUMBER_ST, (yyvsp[-5].strval), (yyvsp[-3].strval), (void*)(long)(yyvsp[-1].intval)); }
#line 8226 "cfg.tab.c"
    break;

  case 580:
#line 2772 "cfg.y"
                                                                                                                          {
				elems[0].type = STR_ST;
				elems[0].u.data = (yyvsp[-11].strval);
				elems[1].type = STR_ST;
				elems[1].u.data = (yyvsp[-9].strval);
				elems[2].type = STR_ST;
				elems[2].u.data = (yyvsp[-7].strval);
				elems[3].type = STR_ST;
				elems[3].u.data = (yyvsp[-5].strval);
				elems[4].type = STR_ST;
				elems[4].u.data = (yyvsp[-3].strval);
				elems[5].type = SCRIPTVAR_ST;
				elems[5].u.data = (yyvsp[-1].specval);
				mk_action_((yyval.action), CONSTRUCT_URI_T,6,elems); }
#line 8245 "cfg.tab.c"
    break;

  case 581:
#line 2786 "cfg.y"
                                                                          {
				elems[0].type = SCRIPTVAR_ST;
				elems[0].u.data = (yyvsp[-3].specval);
				elems[1].type = SCRIPTVAR_ST;
				elems[1].u.data = (yyvsp[-1].specval);
				mk_action_((yyval.action), GET_TIMESTAMP_T,2,elems); }
#line 8256 "cfg.tab.c"
    break;

  case 582:
#line 2792 "cfg.y"
                                             {
				mk_action2((yyval.action), SCRIPT_TRACE_T, 0, 0, 0, 0); }
#line 8263 "cfg.tab.c"
    break;

  case 583:
#line 2794 "cfg.y"
                                                                 {
				pvmodel = 0;
				tstr.s = (yyvsp[-1].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
					yyerror("error in second parameter");
				mk_action2((yyval.action), SCRIPT_TRACE_T, NUMBER_ST,
						   SCRIPTVAR_ELEM_ST, (void *)(yyvsp[-3].intval), pvmodel); }
#line 8276 "cfg.tab.c"
    break;

  case 584:
#line 2802 "cfg.y"
                                                                              {
				pvmodel = 0;
				tstr.s = (yyvsp[-3].strval);
				tstr.len = strlen(tstr.s);
				if(pv_parse_format(&tstr, &pvmodel)<0)
					yyerror("error in second parameter");
				mk_action3((yyval.action), SCRIPT_TRACE_T, NUMBER_ST,
						SCRIPTVAR_ELEM_ST, STR_ST, (void *)(yyvsp[-5].intval), pvmodel, (yyvsp[-1].strval)); }
#line 8289 "cfg.tab.c"
    break;

  case 585:
#line 2810 "cfg.y"
                                                                        {
				i_tmp = get_script_route_idx( (yyvsp[-1].strval), sroutes->request, RT_NO, 0);
				if (i_tmp==-1) yyerror("too many script routes");
				mk_action2((yyval.action), ASYNC_T, ACTIONS_ST, NUMBER_ST,
						(yyvsp[-3].action), (void*)(long)i_tmp);
				}
#line 8300 "cfg.tab.c"
    break;

  case 586:
#line 2816 "cfg.y"
                                                                         {
				i_tmp = get_script_route_idx( (yyvsp[-1].strval), sroutes->request, RT_NO, 0);
				if (i_tmp==-1) yyerror("too many script routes");
				mk_action2((yyval.action), LAUNCH_T, ACTIONS_ST, NUMBER_ST,
						(yyvsp[-3].action), (void*)(long)i_tmp);
				}
#line 8311 "cfg.tab.c"
    break;

  case 587:
#line 2822 "cfg.y"
                                                        {
				mk_action2((yyval.action), LAUNCH_T, ACTIONS_ST, NUMBER_ST,
						(yyvsp[-1].action), (void*)(long)-1);
				}
#line 8320 "cfg.tab.c"
    break;

  case 588:
#line 2826 "cfg.y"
                                                 {
				mk_action2((yyval.action), IS_MYSELF_T, STR_ST, 0, (yyvsp[-1].strval), 0);
				}
#line 8328 "cfg.tab.c"
    break;

  case 589:
#line 2829 "cfg.y"
                                                              {
				mk_action2((yyval.action), IS_MYSELF_T, STR_ST, STR_ST, (yyvsp[-3].strval), (yyvsp[-1].strval));
				}
#line 8336 "cfg.tab.c"
    break;


#line 8340 "cfg.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2835 "cfg.y"


static inline void ALLOW_UNUSED warn(char* s)
{
	LM_WARN("warning in config file %s, line %d, column %d-%d: %s\n",
			get_cfg_file_name, line, startcolumn, column, s);
}

static void yyerror(char* s)
{
	cfg_dump_backtrace();
	LM_CRIT("parse error in %s:%d:%d-%d: %s\n",
			get_cfg_file_name, line, startcolumn, column, s);
	cfg_dump_context(get_cfg_file_name, line, startcolumn, column);
	cfg_errors++;
}

#define ERROR_MAXLEN 1024
static void yyerrorf(char *fmt, ...)
{
	char *tmp = pkg_malloc(ERROR_MAXLEN);
	va_list ap;
	va_start(ap, fmt);

	vsnprintf(tmp, ERROR_MAXLEN, fmt, ap);
	yyerror(tmp);

	pkg_free(tmp);
	va_end(ap);
}


static struct socket_id* mk_listen_id(char* host, enum sip_protos proto,
																	int port)
{
	struct socket_id* l;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0){
		LM_CRIT("cfg. parser: out of memory.\n");
	}else{
		memset(l, 0, sizeof(*l));
		l->name     = host;
		l->proto    = proto;
		l->port     = port;
	}

	return l;
}

static void fill_socket_id(struct listen_param *param, struct socket_id *s)
{
	s->flags |= param->flags;
	s->workers = param->workers;
	s->auto_scaling_profile = param->auto_scaling_profile;
	if (param->socket)
		set_listen_id_adv(s, param->socket->name, param->socket->port);
	s->tag = param->tag;
}

static struct multi_str *new_string(char *s)
{
	struct multi_str *ms = pkg_malloc(sizeof(struct multi_str));
	if (!ms) {
		LM_CRIT("cfg. parser: out of memory.\n");
	}else{
		ms->s    = s;
		ms->next = NULL;
	}
	return ms;
}

static struct socket_id* set_listen_id_adv(struct socket_id* sock,
											char *adv_name,
											int adv_port)
{
	sock->adv_name=adv_name;
	sock->adv_port=adv_port;
	return sock;
}

static int parse_ipnet(char *in, int len, struct net **ipnet)
{
	char *p = NULL;
	str ip_s, mask_s;
	struct ip_addr *ip = NULL, *mask = NULL, *ip_tmp;
	int af;
	unsigned int bitlen;

	p = q_memchr(in, '.', len);
	if (p)
		af = AF_INET;
	else if (q_memchr(in, ':', len)) {
		af = AF_INET6;
	} else {
		LM_ERR("Not an IP");
		return -1;
	}

	p = q_memchr(in, '/', len);
	if (!p) {
		LM_ERR("No netmask\n");
		return -1;
	}
	ip_s.s = in;
	ip_s.len = p - in;

	mask_s.s = p + 1;
	mask_s.len = len - ip_s.len - 1;
	if (!mask_s.s || mask_s.len == 0) {
		LM_ERR("Empty netmask\n");
		return -1;
	}

	ip_tmp = (af == AF_INET) ? str2ip(&ip_s) : str2ip6(&ip_s);
	if (!ip_tmp) {
		LM_ERR("Invalid IP\n");
		return -1;
	}
	ip = pkg_malloc(sizeof *ip);
	if (!ip) {
		LM_CRIT("No more pkg memory\n");
		return -1;
	}
	memcpy(ip, ip_tmp, sizeof *ip);

	p = (af == AF_INET) ? q_memchr(p, '.', len-(p-in)+1) : q_memchr(p, ':', len-(p-in)+1);
	if (p) {
		ip_tmp = (af == AF_INET) ? str2ip(&mask_s) : str2ip6(&mask_s);
		if (!ip_tmp) {
			LM_ERR("Invalid netmask\n");
			return -1;
		}
		mask = pkg_malloc(sizeof *mask);
		if (!mask) {
			LM_CRIT("No more pkg memory\n");
			return -1;
		}
		memcpy(mask, ip_tmp, sizeof *mask);

		*ipnet = mk_net(ip, mask);
	} else {
		if (str2int(&mask_s, &bitlen) < 0) {
			LM_ERR("Invalid netmask bitlen\n");
			return -1;
		}

		*ipnet = mk_net_bitlen(ip, bitlen);
	}

	pkg_free(ip);
	pkg_free(mask);

	if (*ipnet == NULL)
			return -1;

	return 0;
}
