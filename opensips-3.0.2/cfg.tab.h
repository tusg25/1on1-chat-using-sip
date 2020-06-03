/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 313 "cfg.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CFG_TAB_H_INCLUDED  */
