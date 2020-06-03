/*
 * modules/plug-in structures declarations
 *
 * Copyright (C) 2001-2003 FhG Fokus
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * History:
 * --------
 *  2003-03-10  changed module exports interface: added struct cmd_export
 *               and param_export (andrei)
 *  2003-03-16  Added flags field to cmd_export_ (janakj)
 *  2003-04-05  s/reply_route/failure_route, onreply_route introduced (jiri)
 *  2004-03-12  extra flag USE_FUNC_PARAM added to modparam type -
 *              instead of copying the param value, a func is called (bogdan)
 *  2004-09-19  switched to version.h for the module versions checks (andrei)
 *  2004-12-03  changed param_func_t to (modparam_t, void*), killed
 *               param_func_param_t   (andrei)
 *  2006-03-02  added find_cmd_export_t(), killed find_exportp() (bogdan)
 *  2006-11-28  added module_loaded() (Jeffrey Magder - SOMA Networks)
 */

/*!
 * \file
 * \brief modules/plug-in structures declarations
 */


#ifndef sr_module_h
#define sr_module_h

#include <dlfcn.h>

#include "parser/msg_parser.h" /* for sip_msg */
#include "statistics.h"
#include "mi/mi.h"
#include "pvar.h"
#include "version.h"
#include "route.h"
#include "async.h"
#include "transformations.h"

#include "sr_module_deps.h"

typedef  struct module_exports* (*module_register)();
typedef int (*load_function)(void);
typedef  int (*cmd_function)(struct sip_msg*, void*, void*, void*, void*,
			void*, void*, void *, void *);
typedef  int (*acmd_function)(struct sip_msg*, async_ctx *ctx,
			void*, void*, void*, void*, void*, void*, void *, void *);
typedef  int (*fixup_function)(void** param);
typedef  int (*free_fixup_function)(void** param);
typedef  int (*response_function)(struct sip_msg*);
typedef void (*destroy_function)();
typedef int (*preinit_function)(void);
typedef int (*init_function)(void);
typedef int (*child_init_function)(int rank);
typedef int (*reload_confirm_function)(void);


#define STR_PARAM        (1U<<0)  /* String parameter type */
#define INT_PARAM        (1U<<1)  /* Integer parameter type */
#define USE_FUNC_PARAM   (1U<<(8*sizeof(int)-1))
#define PARAM_TYPE_MASK(_x)   ((_x)&(~USE_FUNC_PARAM))

typedef unsigned int modparam_t;

typedef int (*param_func_t)( modparam_t type, void* val);

typedef void (*mod_proc)(int no);

typedef int (*mod_proc_wrapper)();

/* Macros - used as rank in child_init function */
#define PROC_MAIN      0  /* Main opensips process */
#define PROC_TIMER    -1  /* Timer attendant process */
#define PROC_MODULE   -2  /* Extra process requested by modules */
#define PROC_TCP_MAIN -4  /* TCP main process */

#define DEFAULT_DLFLAGS	0 /* value that signals to module loader to
							use default dlopen flags in opensips */
#ifndef RTLD_NOW
/* for openbsd */
#define RTLD_NOW DL_LAZY
#endif

#define OPENSIPS_DLFLAGS	RTLD_NOW

#define MODULE_VERSION \
	OPENSIPS_FULL_VERSION, \
	OPENSIPS_COMPILE_FLAGS


#define PROC_FLAG_INITCHILD  (1<<0)
#define PROC_FLAG_HAS_IPC    (1<<1)

#define MAX_CMD_PARAMS (MAX_ACTION_ELEMS-1)


/* parameter type flags */
#define CMD_PARAM_INT        (1<<0)  /* integer parameter */
#define CMD_PARAM_STR        (1<<1)  /* string parameter */
#define CMD_PARAM_VAR        (1<<2)  /* PV spec parameter */
#define CMD_PARAM_REGEX      (1<<3)  /* regexp string parameter */

#define CMD_PARAM_OPT        (1<<4)  /* optional parameter */
#define CMD_PARAM_FIX_NULL   (1<<5)  /* run fixup even if optional parameter is omitted */
#define CMD_PARAM_NO_EXPAND  (1<<6)  /* TMPHACK: do not pv-expand strings */
#define CMD_PARAM_STATIC	 (1<<7)  /* don't accept variables or formatted string */

struct cmd_param {
	int flags;              /* parameter flags */
	fixup_function fixup;   /* pointer to the function called to "fix" the
							   parameter */
	free_fixup_function
				free_fixup; /* pointer to the function called to free the
							   "fixed" parameter */
};

struct cmd_export_ {
	char* name;                 /* null terminated command name */
	cmd_function function;      /* pointer to the corresponding function */
	struct cmd_param
		params[MAX_CMD_PARAMS+1]; /* array of parameters */
	int flags;                  /* Function flags */
};


struct acmd_export_ {
	char* name;                 /* null terminated command name */
	acmd_function function;     /* pointer to the corresponding function */
	struct cmd_param
		params[MAX_CMD_PARAMS+1]; /* array of parameters */
};


struct param_export_ {
	char* name;             /*!< null terminated param. name */
	modparam_t type;        /*!< param. type */
	void* param_pointer;    /*!< pointer to the param. memory location */
};


struct proc_export_ {
	char *name;
	mod_proc_wrapper pre_fork_function;
	mod_proc_wrapper post_fork_function;
	mod_proc function;
	unsigned int no;
	unsigned int flags;
};

typedef struct dep_export_ {
	module_dependency_t md[MAX_MOD_DEPS];
	modparam_dependency_t mpd[];
} dep_export_t;

typedef struct cmd_export_  cmd_export_t;
typedef struct acmd_export_ acmd_export_t;
typedef struct proc_export_ proc_export_t;


struct sr_module{
	char* path;
	void* handle;
	int init_done;
	struct module_exports* exports;

	/* a list of module dependencies */
	struct sr_module_dep *sr_deps;

	struct sr_module* next;
};


struct module_exports{
	char* name;                     /*!< null terminated module name */
	enum module_type type;
	char *version;                  /*!< module version */
	char *compile_flags;            /*!< compile flags used on the module */
	unsigned int dlflags;           /*!< flags for dlopen */

	load_function load_f;           /*!< function called immediately after a
	                                   module was loaded by dlopen */

	dep_export_t *deps;             /*!< module and modparam dependencies */


	cmd_export_t* cmds;             /*!< null terminated array of the exported
	                                   commands */
	acmd_export_t* acmds;           /*!< null terminated array of the exported
	                                   async commands */
	param_export_t* params;         /*!< null terminated array of the exported
	                                   module parameters */

	stat_export_t* stats;           /*!< null terminated array of the exported
	                                   module statistics */

	mi_export_t* mi_cmds;           /*!< null terminated array of the exported
	                                   MI functions */

	pv_export_t* items;             /*!< null terminated array of the exported
	                                   module items (pseudo-variables) */

	trans_export_t* trans;          /*!< null terminated array of the exported
	                                   module transformations */

	proc_export_t* procs;           /*!< null terminated array of the additional
	                                   processes reqired by the module */

	preinit_function preinit_f;     /*!< Pre-Initialization function */
	init_function init_f;           /*!< Initialization function */
	response_function response_f;   /*!< function used for responses,
	                                   returns yes or no; can be null */
	destroy_function destroy_f;     /*!< function called when the module should
	                                   be "destroyed", e.g: on opensips exit */
	child_init_function init_child_f;/*!< function called by all processes
	                                    after the fork */
	reload_confirm_function reload_ack_f;/*!< function called during a script
	                                    reload in order to confirm if the 
	                                    module agrees with the new script */
};

void set_mpath(const char *new_mpath);

struct sr_module* modules; /*!< global module list*/

int register_builtin_modules();
int register_module(struct module_exports*, char*,  void*);
int load_module(char* name);
cmd_export_t* find_cmd_export_t(char* name, int flags);
acmd_export_t* find_acmd_export_t(char* name);
int check_cmd_call_params(cmd_export_t *cmd, action_elem_t *elems, int no_params);
int check_acmd_call_params(acmd_export_t *acmd, action_elem_t *elems, int no_params);
cmd_function find_export(char* name, int flags);
cmd_function find_mod_export(char* mod, char* name, int flags);
void destroy_modules();
int init_child(int rank);
int init_modules(void);
int init_modules_deps(void);

/*! \brief
 * Find a parameter with given type and return it's
 * address in memory
 * If there is no such parameter, NULL is returned
 */
void* find_param_export(char* mod, char* name, modparam_t type);

/* modules function prototypes:
 * struct module_exports* mod_register(); (type module_register)
 * int   foo_cmd(struct sip_msg* msg, char* param);
 *  - returns >0 if ok , <0 on error, 0 to stop processing (==DROP)
 * int   response_f(struct sip_msg* msg)
 *  - returns >0 if ok, 0 to drop message
 */

/*! \brief Check if module is loaded
 * \return Returns 1 if the module with name 'name' is loaded, and zero otherwise. */
int module_loaded(char *name);

/*! \brief Gets a specific module
 * \return Returns the module if the module with name 'name' is loaded, and
 * NULL otherwise */

/*! \brief Counts the additional the number of processes requested by modules */
int count_module_procs(int flags);

/*! \brief Forks and starts the additional processes required by modules */
int start_module_procs(void);

/*! \brief Runs the reload validation function from all modules */
int modules_validate_reload(void);

#endif