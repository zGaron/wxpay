
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(WXPay_Credential_Jsapi) {

	ZEPHIR_REGISTER_CLASS_EX(WXPay\\Credential, Jsapi, wxpay, credential_jsapi, wxpay_credential_ce, wxpay_credential_jsapi_method_entry, 0);

	zend_declare_property_null(wxpay_credential_jsapi_ce, SL("appId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(wxpay_credential_jsapi_ce, SL("signType"), "MD5", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_jsapi_ce, SL("package"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_jsapi_ce, SL("nonceStr"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_jsapi_ce, SL("timeStamp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_jsapi_ce, SL("paySign"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_jsapi_ce, SL("_required_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_jsapi_ce, SL("_optional_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	wxpay_credential_jsapi_ce->create_object = zephir_init_properties_WXPay_Credential_Jsapi;
	return SUCCESS;

}

PHP_METHOD(WXPay_Credential_Jsapi, make) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *prepay_id_param = NULL, *newObj = NULL, *_0$$3;
	zval *prepay_id = NULL, *_2, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prepay_id_param);

	if (unlikely(Z_TYPE_P(prepay_id_param) != IS_STRING && Z_TYPE_P(prepay_id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prepay_id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(prepay_id_param) == IS_STRING)) {
		zephir_get_strval(prepay_id, prepay_id_param);
	} else {
		ZEPHIR_INIT_VAR(prepay_id);
		ZVAL_EMPTY_STRING(prepay_id);
	}


	if (ZEPHIR_IS_EMPTY(prepay_id)) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SS(_1$$3, "Jsapi:make", ": Field {prepay_id} cannot be empty!");
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 6, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "wxpay/credential/jsapi.zep", 31 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(newObj);
	object_init_ex(newObj, wxpay_credential_jsapi_ce);
	ZEPHIR_CALL_METHOD(NULL, newObj, "__construct", NULL, 2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "prepay_id=", prepay_id);
	zephir_update_property_zval(newObj, SL("package"), _2 TSRMLS_CC);
	RETURN_CCTOR(newObj);

}

PHP_METHOD(WXPay_Credential_Jsapi, signWith) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zval *config, *_0, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, config, SL("app_id"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("appId"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 24);
	ZEPHIR_CALL_CE_STATIC(&_1, wxpay_library_util_ce, "genrandomstring", &_2, 5, _3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("nonceStr"), _1 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	zephir_time(_3);
	zephir_update_property_this(this_ptr, SL("timeStamp"), _3 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property(&_6, config, SL("app_key"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_4, wxpay_library_util_ce, "make_sign", &_5, 7, this_ptr, _6);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("paySign"), _4 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(WXPay_Credential_Jsapi, fire) {

	HashTable *_2;
	HashPosition _1;
	zval *field = NULL, *objVal = NULL, *_0, **_3, *_4;
	zval *responseStruct;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(responseStruct);
	array_init(responseStruct);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "wxpay/credential/jsapi.zep", 57);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(field, _3);
		ZEPHIR_OBS_NVAR(objVal);
		if (zephir_fetch_property_zval(&objVal, this_ptr, field, PH_SILENT_CC)) {
			zephir_array_update_zval(&responseStruct, field, &objVal, PH_COPY | PH_SEPARATE);
		}
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("paySign"), PH_NOISY_CC);
	zephir_array_update_string(&responseStruct, SL("paySign"), &_4, PH_COPY | PH_SEPARATE);
	RETURN_CTOR(responseStruct);

}

static zend_object_value zephir_init_properties_WXPay_Credential_Jsapi(zend_class_entry *class_type TSRMLS_DC) {

		zval *_3$$4;
	zval *_0, *_2, *_1$$3, *_4$$4 = NULL;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_optional_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_optional_properties"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			zephir_create_array(_3$$4, 5, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4$$4);
			ZVAL_STRING(_4$$4, "appId", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "signType", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "package", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "nonceStr", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "timeStamp", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			zephir_update_property_this(this_ptr, SL("_required_properties"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

