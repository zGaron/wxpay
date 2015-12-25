
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
#include "ext/spl/spl_iterators.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * WXPay\Option
 *
 * 接口参数结构体
 */
ZEPHIR_INIT_CLASS(WXPay_Option) {

	ZEPHIR_REGISTER_CLASS(WXPay, Option, wxpay, option, wxpay_option_method_entry, 0);

	zend_class_implements(wxpay_option_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(wxpay_option_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * WXPay\Option constructor
 */
PHP_METHOD(WXPay_Option, __construct) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arrayParameter_param = NULL, *key = NULL, *value = NULL, **_2;
	zval *arrayParameter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrayParameter_param);

	if (!arrayParameter_param) {
		ZEPHIR_INIT_VAR(arrayParameter);
		array_init(arrayParameter);
	} else {
	arrayParameter = arrayParameter_param;
	}


	zephir_is_iterable(arrayParameter, &_1, &_0, 0, 0, "wxpay/option.zep", 21);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_3, 0, key, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Allows to check whether an attribute is defined using the array-syntax
 *
 *<code>
 * var_dump(isset($option['database']));
 *</code>
 */
PHP_METHOD(WXPay_Option, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 1, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	RETURN_MM_BOOL(zephir_isset_property_zval(this_ptr, index TSRMLS_CC));

}

/**
 * Gets an attribute from the options, if the attribute isn't defined returns null
 * If the value is exactly null or is not defined the default value will be used instead
 *
 *<code>
 * echo $option->get('controllersDir', '../app/controllers/');
 *</code>
 */
PHP_METHOD(WXPay_Option, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *defaultValue = NULL, *_0 = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index, &defaultValue);

	ZEPHIR_SEPARATE_PARAM(index);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 1, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	if (zephir_isset_property_zval(this_ptr, index TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1$$3);
		zephir_read_property_zval(&_1$$3, this_ptr, index, PH_NOISY_CC);
		RETURN_CCTOR(_1$$3);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Gets an attribute using the array-syntax
 *
 *<code>
 * print_r($option['database']);
 *</code>
 */
PHP_METHOD(WXPay_Option, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 1, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, index, PH_NOISY_CC);
	RETURN_CCTOR(_1);

}

/**
 * Sets an attribute using the array-syntax
 *
 *<code>
 * $option['database'] = array('type' => 'Sqlite');
 *</code>
 */
PHP_METHOD(WXPay_Option, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *value, *_0 = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 1, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, wxpay_option_ce);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 2, value);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, index, _1$$3 TSRMLS_CC);
	} else {
		zephir_update_property_zval_zval(this_ptr, index, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Unsets an attribute using the array-syntax
 *
 *<code>
 * unset($option['database']);
 *</code>
 */
PHP_METHOD(WXPay_Option, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 1, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	zephir_update_property_zval_zval(this_ptr, index, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Merges a options into the current one
 *
 *<code>
 * $option = new \WXPay\Option(array('database' => array('host' => 'localhost')));
 * $globalOption->merge($option);
 *</code>
 */
PHP_METHOD(WXPay_Option, merge) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *option;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_merge", NULL, 3, option);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Converts recursively the object to an array
 *
 *<code>
 *	print_r($option->toArray());
 *</code>
 */
PHP_METHOD(WXPay_Option, toArray) {

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *arrayParameter = NULL, *_0 = NULL, **_3, *_4$$5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(arrayParameter);
	array_init(arrayParameter);
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 4, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "wxpay/option.zep", 139);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(value) == IS_OBJECT) {
			if ((zephir_method_exists_ex(value, SS("toarray") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&_4$$5, value, "toarray", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&arrayParameter, key, &_4$$5, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&arrayParameter, key, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_zval(&arrayParameter, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(arrayParameter);

}

/**
 * Returns the count of properties set in the option
 *
 *<code>
 * print count($option);
 *</code>
 *
 * or
 *
 *<code>
 * print $option->count();
 *</code>
 */
PHP_METHOD(WXPay_Option, count) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 4, this_ptr);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Restores the state of a WXPay\Option object
 */
PHP_METHOD(WXPay_Option, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;


	object_init_ex(return_value, wxpay_option_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 2, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Helper method for merge options (forwarding nested option instance)
 *
 * @param Option option
 * @param Option instance = null
 *
 * @return Option merged option
 */
PHP_METHOD(WXPay_Option, _merge) {

	zend_bool _4$$5, _5$$6;
	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *option, *instance = NULL, *key = NULL, *value = NULL, *number = NULL, *localObject = NULL, *_0 = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &option, &instance);

	if (!instance) {
		ZEPHIR_CPY_WRT(instance, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(instance);
	}


	if (Z_TYPE_P(instance) != IS_OBJECT) {
		ZEPHIR_CPY_WRT(instance, this_ptr);
	}
	ZEPHIR_CALL_METHOD(&number, instance, "count", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 4, option);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "wxpay/option.zep", 204);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_OBS_NVAR(localObject);
		if (zephir_fetch_property_zval(&localObject, instance, key, PH_SILENT_CC)) {
			_4$$5 = Z_TYPE_P(localObject) == IS_OBJECT;
			if (_4$$5) {
				_4$$5 = Z_TYPE_P(value) == IS_OBJECT;
			}
			if (_4$$5) {
				_5$$6 = zephir_instance_of_ev(localObject, wxpay_option_ce TSRMLS_CC);
				if (_5$$6) {
					_5$$6 = zephir_instance_of_ev(value, wxpay_option_ce TSRMLS_CC);
				}
				if (_5$$6) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_merge", &_6, 3, value, localObject);
					zephir_check_call_status();
					continue;
				}
			}
		}
		if (Z_TYPE_P(key) == IS_LONG) {
			ZEPHIR_CALL_FUNCTION(&key, "strval", &_7, 1, number);
			zephir_check_call_status();
			ZEPHIR_SEPARATE(number);
			zephir_increment(number);
		}
		zephir_update_property_zval_zval(instance, key, value TSRMLS_CC);
	}
	RETVAL_ZVAL(instance, 1, 0);
	RETURN_MM();

}

