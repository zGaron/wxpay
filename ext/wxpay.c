
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "wxpay.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *wxpay_option_ce;
zend_class_entry *wxpay_api_ce;
zend_class_entry *wxpay_credential_ce;
zend_class_entry *wxpay_api_app_closeorder_ce;
zend_class_entry *wxpay_api_app_createorder_ce;
zend_class_entry *wxpay_api_app_createrefund_ce;
zend_class_entry *wxpay_api_app_queryorder_ce;
zend_class_entry *wxpay_api_app_queryrefund_ce;
zend_class_entry *wxpay_api_jsapi_closeorder_ce;
zend_class_entry *wxpay_api_jsapi_createorder_ce;
zend_class_entry *wxpay_api_jsapi_createrefund_ce;
zend_class_entry *wxpay_api_jsapi_queryorder_ce;
zend_class_entry *wxpay_api_jsapi_queryrefund_ce;
zend_class_entry *wxpay_api_micropay_autocodetoopenid_ce;
zend_class_entry *wxpay_api_micropay_closeorder_ce;
zend_class_entry *wxpay_api_micropay_createorder_ce;
zend_class_entry *wxpay_api_micropay_createrefund_ce;
zend_class_entry *wxpay_api_micropay_queryorder_ce;
zend_class_entry *wxpay_api_micropay_queryrefund_ce;
zend_class_entry *wxpay_api_micropay_shorturl_ce;
zend_class_entry *wxpay_api_native_closeorder_ce;
zend_class_entry *wxpay_api_native_createorder_ce;
zend_class_entry *wxpay_api_native_createrefund_ce;
zend_class_entry *wxpay_api_native_queryorder_ce;
zend_class_entry *wxpay_api_native_queryrefund_ce;
zend_class_entry *wxpay_api_native_shorturl_ce;
zend_class_entry *wxpay_api_transfer_createorder_ce;
zend_class_entry *wxpay_api_transfer_queryorder_ce;
zend_class_entry *wxpay_api_wap_createorder_ce;
zend_class_entry *wxpay_config_ce;
zend_class_entry *wxpay_credential_app_ce;
zend_class_entry *wxpay_credential_jsapi_ce;
zend_class_entry *wxpay_credential_native1_ce;
zend_class_entry *wxpay_library_util_ce;

ZEND_DECLARE_MODULE_GLOBALS(wxpay)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(wxpay)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(WXPay_Option);
	ZEPHIR_INIT(WXPay_Api);
	ZEPHIR_INIT(WXPay_Credential);
	ZEPHIR_INIT(WXPay_Api_App_CloseOrder);
	ZEPHIR_INIT(WXPay_Api_App_CreateOrder);
	ZEPHIR_INIT(WXPay_Api_App_CreateRefund);
	ZEPHIR_INIT(WXPay_Api_App_QueryOrder);
	ZEPHIR_INIT(WXPay_Api_App_QueryRefund);
	ZEPHIR_INIT(WXPay_Api_Jsapi_CloseOrder);
	ZEPHIR_INIT(WXPay_Api_Jsapi_CreateOrder);
	ZEPHIR_INIT(WXPay_Api_Jsapi_CreateRefund);
	ZEPHIR_INIT(WXPay_Api_Jsapi_QueryOrder);
	ZEPHIR_INIT(WXPay_Api_Jsapi_QueryRefund);
	ZEPHIR_INIT(WXPay_Api_Micropay_AutocodeToOpenId);
	ZEPHIR_INIT(WXPay_Api_Micropay_CloseOrder);
	ZEPHIR_INIT(WXPay_Api_Micropay_CreateOrder);
	ZEPHIR_INIT(WXPay_Api_Micropay_CreateRefund);
	ZEPHIR_INIT(WXPay_Api_Micropay_QueryOrder);
	ZEPHIR_INIT(WXPay_Api_Micropay_QueryRefund);
	ZEPHIR_INIT(WXPay_Api_Micropay_ShortUrl);
	ZEPHIR_INIT(WXPay_Api_Native_CloseOrder);
	ZEPHIR_INIT(WXPay_Api_Native_CreateOrder);
	ZEPHIR_INIT(WXPay_Api_Native_CreateRefund);
	ZEPHIR_INIT(WXPay_Api_Native_QueryOrder);
	ZEPHIR_INIT(WXPay_Api_Native_QueryRefund);
	ZEPHIR_INIT(WXPay_Api_Native_Shorturl);
	ZEPHIR_INIT(WXPay_Api_Transfer_CreateOrder);
	ZEPHIR_INIT(WXPay_Api_Transfer_QueryOrder);
	ZEPHIR_INIT(WXPay_Api_Wap_CreateOrder);
	ZEPHIR_INIT(WXPay_Config);
	ZEPHIR_INIT(WXPay_Credential_App);
	ZEPHIR_INIT(WXPay_Credential_Jsapi);
	ZEPHIR_INIT(WXPay_Credential_Native1);
	ZEPHIR_INIT(WXPay_Library_Util);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(wxpay)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_wxpay_globals *wxpay_globals TSRMLS_DC)
{
	wxpay_globals->initialized = 0;

	/* Memory options */
	wxpay_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	wxpay_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	wxpay_globals->cache_enabled = 1;

	/* Recursive Lock */
	wxpay_globals->recursive_lock = 0;

	/* Static cache */
	memset(wxpay_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(wxpay)
{

	zend_wxpay_globals *wxpay_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(wxpay_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(wxpay_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(wxpay)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(wxpay)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_WXPAY_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_WXPAY_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_WXPAY_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_WXPAY_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_WXPAY_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(wxpay)
{
	php_zephir_init_globals(wxpay_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(wxpay)
{

}


zend_function_entry php_wxpay_functions[] = {
ZEND_FE_END

};

zend_module_entry wxpay_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_WXPAY_EXTNAME,
	php_wxpay_functions,
	PHP_MINIT(wxpay),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(wxpay),
#else
	NULL,
#endif
	PHP_RINIT(wxpay),
	PHP_RSHUTDOWN(wxpay),
	PHP_MINFO(wxpay),
	PHP_WXPAY_VERSION,
	ZEND_MODULE_GLOBALS(wxpay),
	PHP_GINIT(wxpay),
	PHP_GSHUTDOWN(wxpay),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_WXPAY
ZEND_GET_MODULE(wxpay)
#endif
