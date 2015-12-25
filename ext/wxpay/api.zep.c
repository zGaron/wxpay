
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/variables.h"


ZEPHIR_INIT_CLASS(WXPay_Api) {

	ZEPHIR_REGISTER_CLASS_EX(WXPay, Api, wxpay, api, wxpay_option_ce, wxpay_api_method_entry, 0);

	zend_declare_property_string(wxpay_api_ce, SL("api_url"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_bool(wxpay_api_ce, SL("is_secure_pay"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_ce, SL("_required_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_ce, SL("_optional_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_ce, SL("_either_groups"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_api_ce, SL("_make_exclude_properties"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_api_ce, SL("sign"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(wxpay_api_ce, SL("debug"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	wxpay_api_ce->create_object = zephir_init_properties_WXPay_Api;
	return SUCCESS;

}

PHP_METHOD(WXPay_Api, make) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, *api = NULL, *class_name = NULL, *_0 = NULL;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	zephir_get_arrval(config, config_param);


	ZEPHIR_INIT_VAR(class_name);
	zephir_get_called_class(class_name TSRMLS_CC);
	ZEPHIR_INIT_VAR(api);
	zephir_fetch_safe_class(_0, class_name);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(api, _1);
	if (zephir_has_constructor(api TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, api, "__construct", NULL, 0, config);
		zephir_check_call_status();
	}
	RETURN_CCTOR(api);

}

PHP_METHOD(WXPay_Api, signWith) {

	HashTable *_7, *_12$$6;
	HashPosition _6, _11$$6;
	zend_bool group_through = 0, _0, _18$$5, _20$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_28 = NULL;
	zval *config = NULL, *field = NULL, *item = NULL, *messages = NULL, *_1, *_5, **_8, *_25, *_26, *_27 = NULL, *_29, *_2$$4 = NULL, *_4$$4, *_9$$5, *_17$$5, *_19$$5, *_21$$5 = NULL, *_10$$6, **_13$$6, *_14$$7 = NULL, *_15$$9 = NULL, *_16$$9, *_22$$13, *_23$$13, *_24$$13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config);

	if (!config) {
		config = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(config, wxpay_config_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Invalid \\WXPay\\Config!", "wxpay/api.zep", 39);
		return;
	}
	_0 = !((0 == 0));
	if (!(_0)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property(&_1, this_ptr, SL("nonce_str"), PH_NOISY_CC);
		_0 = ZEPHIR_IS_EMPTY(_1);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_LONG(_4$$4, 24);
		ZEPHIR_CALL_CE_STATIC(&_2$$4, wxpay_library_util_ce, "genrandomstring", &_3, 5, _4$$4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("nonce_str"), _2$$4 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(messages);
	array_init(messages);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
	zephir_is_iterable(_5, &_7, &_6, 0, 0, "wxpay/api.zep", 77);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HVALUE(field, _8);
		_9$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_either_groups"), PH_NOISY_CC);
		if (zephir_fast_in_array(field, _9$$5 TSRMLS_CC)) {
			group_through = 0;
			_10$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_either_groups"), PH_NOISY_CC);
			zephir_is_iterable(_10$$6, &_12$$6, &_11$$6, 0, 0, "wxpay/api.zep", 57);
			for (
			  ; zephir_hash_get_current_data_ex(_12$$6, (void**) &_13$$6, &_11$$6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_12$$6, &_11$$6)
			) {
				ZEPHIR_GET_HVALUE(item, _13$$6);
				ZEPHIR_OBS_NVAR(_14$$7);
				zephir_read_property_zval(&_14$$7, this_ptr, item, PH_NOISY_CC);
				if (!(ZEPHIR_IS_EMPTY(_14$$7))) {
					group_through = 1;
				}
			}
			if (!(group_through)) {
				ZEPHIR_INIT_NVAR(_15$$9);
				_16$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_either_groups"), PH_NOISY_CC);
				zephir_fast_join_str(_15$$9, SL(", "), _16$$9 TSRMLS_CC);
				zephir_array_append(&messages, _15$$9, PH_SEPARATE, "wxpay/api.zep", 59);
			} else {
				continue;
			}
		}
		_17$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_make_exclude_properties"), PH_NOISY_CC);
		_18$$5 = !(zephir_fast_in_array(field, _17$$5 TSRMLS_CC));
		if (_18$$5) {
			_18$$5 = !(zephir_isset_property_zval(this_ptr, field TSRMLS_CC));
		}
		if (_18$$5) {
			zephir_array_append(&messages, field, PH_SEPARATE, "wxpay/api.zep", 68);
		}
		_19$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_make_exclude_properties"), PH_NOISY_CC);
		_20$$5 = !(zephir_fast_in_array(field, _19$$5 TSRMLS_CC));
		if (_20$$5) {
			ZEPHIR_OBS_NVAR(_21$$5);
			zephir_read_property_zval(&_21$$5, this_ptr, field, PH_NOISY_CC);
			_20$$5 = ZEPHIR_IS_EMPTY(_21$$5);
		}
		if (_20$$5) {
			zephir_array_append(&messages, field, PH_SEPARATE, "wxpay/api.zep", 73);
		}
	}
	if (zephir_fast_count_int(messages TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_22$$13);
		object_init_ex(_22$$13, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_23$$13);
		zephir_fast_join_str(_23$$13, SL(", "), messages TSRMLS_CC);
		ZEPHIR_INIT_VAR(_24$$13);
		ZEPHIR_CONCAT_SVS(_24$$13, "Must provide those fields: {", _23$$13, "}");
		ZEPHIR_CALL_METHOD(NULL, _22$$13, "__construct", NULL, 6, _24$$13);
		zephir_check_call_status();
		zephir_throw_exception_debug(_22$$13, "wxpay/api.zep", 78 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(_25);
	zephir_read_property(&_25, config, SL("app_id"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("appid"), _25 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_26);
	zephir_read_property(&_26, config, SL("mch_id"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("mch_id"), _26 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_29);
	zephir_read_property(&_29, config, SL("app_key"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_27, wxpay_library_util_ce, "make_sign", &_28, 7, this_ptr, _29);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("sign"), _27 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_config"), config TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(WXPay_Api, setDebug) {

	zval *debug_param = NULL;
	zend_bool debug;

	zephir_fetch_params(0, 0, 1, &debug_param);

	if (!debug_param) {
		debug = 1;
	} else {
		debug = zephir_get_boolval(debug_param);
	}


	if (debug == 1) {
		if (debug) {
			zephir_update_property_this(this_ptr, SL("debug"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("debug"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_THISW();

}

PHP_METHOD(WXPay_Api, dump) {

	HashTable *_4;
	HashPosition _3;
	zval *property = NULL, *xml = NULL, *_0, *_1, *_2 = NULL, **_5, *_9, *_6$$3 = NULL, *_7$$4 = NULL;
	zval *parameters, *mergedArray = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);
	ZEPHIR_INIT_VAR(mergedArray);
	array_init(mergedArray);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_optional_properties"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "array_merge", NULL, 8, mergedArray, _0, _1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(mergedArray, _2);
	zephir_is_iterable(mergedArray, &_4, &_3, 0, 0, "wxpay/api.zep", 108);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(property, _5);
		ZEPHIR_OBS_NVAR(_6$$3);
		zephir_read_property_zval(&_6$$3, this_ptr, property, PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(_6$$3))) {
			ZEPHIR_OBS_NVAR(_7$$4);
			zephir_read_property_zval(&_7$$4, this_ptr, property, PH_NOISY_CC);
			zephir_array_update_zval(&parameters, property, &_7$$4, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_MAKE_REF(parameters);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 9, parameters);
	ZEPHIR_UNREF(parameters);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&xml, wxpay_library_util_ce, "convertarraytoxml", &_8, 10, parameters);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_GET_CONSTANT(_9, "PHP_EOL");
	ZEPHIR_CONCAT_VV(return_value, xml, _9);
	RETURN_MM();

}

PHP_METHOD(WXPay_Api, fire) {

	HashTable *_4;
	HashPosition _3;
	zval *responseArray = NULL, *property = NULL, *xml = NULL, *_0, *_1, *_2 = NULL, **_5, *_9, *_11, *_21, *_6$$3 = NULL, *_7$$4 = NULL, *_10$$5, *_13$$6, *_14$$6, *_15$$6, *_16$$6, *_17$$6, *_18$$6, *_19$$6, *_20$$7, *_22$$8, *_23$$8 = NULL, *_24$$8;
	zval *parameters, *mergedArray = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(parameters);
	array_init(parameters);
	ZEPHIR_INIT_VAR(mergedArray);
	array_init(mergedArray);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_optional_properties"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "array_merge", NULL, 8, mergedArray, _0, _1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(mergedArray, _2);
	zephir_is_iterable(mergedArray, &_4, &_3, 0, 0, "wxpay/api.zep", 126);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(property, _5);
		ZEPHIR_OBS_NVAR(_6$$3);
		zephir_read_property_zval(&_6$$3, this_ptr, property, PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(_6$$3))) {
			ZEPHIR_OBS_NVAR(_7$$4);
			zephir_read_property_zval(&_7$$4, this_ptr, property, PH_NOISY_CC);
			zephir_array_update_zval(&parameters, property, &_7$$4, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_MAKE_REF(parameters);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 9, parameters);
	ZEPHIR_UNREF(parameters);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&xml, wxpay_library_util_ce, "convertarraytoxml", &_8, 10, parameters);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("debug"), PH_NOISY_CC);
	if (zephir_is_true(_9)) {
		php_printf("%s", "send xml:");
		zend_print_zval(xml, 0);
		ZEPHIR_INIT_VAR(_10$$5);
		ZEPHIR_GET_CONSTANT(_10$$5, "PHP_EOL");
		zend_print_zval(_10$$5, 0);
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("is_secure_pay"), PH_NOISY_CC);
	if (zephir_is_true(_11)) {
		_13$$6 = zephir_fetch_nproperty_this(this_ptr, SL("api_url"), PH_NOISY_CC);
		_14$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_config"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_15$$6);
		zephir_read_property(&_15$$6, _14$$6, SL("client_cert"), PH_NOISY_CC);
		_16$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_config"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_17$$6);
		zephir_read_property(&_17$$6, _16$$6, SL("client_key"), PH_NOISY_CC);
		_18$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_config"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_19$$6);
		zephir_read_property(&_19$$6, _18$$6, SL("rootca"), PH_NOISY_CC);
		ZEPHIR_CALL_CE_STATIC(&responseArray, wxpay_library_util_ce, "callwechatapi", &_12, 11, _13$$6, xml, _15$$6, _17$$6, _19$$6);
		zephir_check_call_status();
	} else {
		_20$$7 = zephir_fetch_nproperty_this(this_ptr, SL("api_url"), PH_NOISY_CC);
		ZEPHIR_CALL_CE_STATIC(&responseArray, wxpay_library_util_ce, "callwechatapi", &_12, 11, _20$$7, xml);
		zephir_check_call_status();
	}
	_21 = zephir_fetch_nproperty_this(this_ptr, SL("debug"), PH_NOISY_CC);
	if (zephir_is_true(_21)) {
		php_printf("%s", "raw response: ");
		ZEPHIR_INIT_VAR(_22$$8);
		ZEPHIR_GET_CONSTANT(_22$$8, "PHP_EOL");
		zend_print_zval(_22$$8, 0);
		ZEPHIR_INIT_VAR(_23$$8);
		ZEPHIR_INIT_NVAR(_23$$8);
		zephir_var_export_ex(_23$$8, &responseArray TSRMLS_CC);
		zend_print_zval(_23$$8, 0);
		ZEPHIR_INIT_VAR(_24$$8);
		ZEPHIR_GET_CONSTANT(_24$$8, "PHP_EOL");
		zend_print_zval(_24$$8, 0);
	}
	RETURN_CCTOR(responseArray);

}

static zend_object_value zephir_init_properties_WXPay_Api(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0, *_3, *_5, *_7, *_2$$3 = NULL, *_4$$4, *_6$$5, *_8$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_make_exclude_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 4, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_2$$3);
			ZVAL_STRING(_2$$3, "appid", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "mch_id", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "trade_type", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "sign", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			zephir_update_property_this(this_ptr, SL("_make_exclude_properties"), _1$$3 TSRMLS_CC);
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_either_groups"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_NULL) {
			ZEPHIR_INIT_VAR(_4$$4);
			array_init(_4$$4);
			zephir_update_property_this(this_ptr, SL("_either_groups"), _4$$4 TSRMLS_CC);
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_optional_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_5) == IS_NULL) {
			ZEPHIR_INIT_VAR(_6$$5);
			array_init(_6$$5);
			zephir_update_property_this(this_ptr, SL("_optional_properties"), _6$$5 TSRMLS_CC);
		}
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_7) == IS_NULL) {
			ZEPHIR_INIT_VAR(_8$$6);
			array_init(_8$$6);
			zephir_update_property_this(this_ptr, SL("_required_properties"), _8$$6 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

