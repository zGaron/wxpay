
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_WXPAY_H
#define PHP_WXPAY_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_WXPAY_NAME        "wxpay"
#define PHP_WXPAY_VERSION     "0.1.0"
#define PHP_WXPAY_EXTNAME     "wxpay"
#define PHP_WXPAY_AUTHOR      ""
#define PHP_WXPAY_ZEPVERSION  "0.9.1a-dev"
#define PHP_WXPAY_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(wxpay)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(wxpay)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(wxpay)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(wxpay_globals_id, zend_wxpay_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (wxpay_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_wxpay_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(wxpay_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(wxpay_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def wxpay_globals
#define zend_zephir_globals_def zend_wxpay_globals

extern zend_module_entry wxpay_module_entry;
#define phpext_wxpay_ptr &wxpay_module_entry

#endif
