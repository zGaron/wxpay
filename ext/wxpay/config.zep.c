
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/hash.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(WXPay_Config) {

	ZEPHIR_REGISTER_CLASS_EX(WXPay, Config, wxpay, config, wxpay_option_ce, wxpay_config_method_entry, 0);

	zend_declare_property_null(wxpay_config_ce, SL("app_id"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_config_ce, SL("mch_id"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_config_ce, SL("app_key"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_config_ce, SL("rootca"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_config_ce, SL("client_cert"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_config_ce, SL("client_key"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(WXPay_Config, __construct) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *key = NULL, *value = NULL, **_2, *_3$$3 = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
	options = options_param;
	}


	zephir_is_iterable(options, &_1, &_0, 0, 0, "wxpay/config.zep", 26);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "offsetexists", &_4, 0, key);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_5, 0, key, value);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

