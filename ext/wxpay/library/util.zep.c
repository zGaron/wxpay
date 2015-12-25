
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(WXPay_Library_Util) {

	ZEPHIR_REGISTER_CLASS(WXPay\\Library, Util, wxpay, library_util, wxpay_library_util_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(WXPay_Library_Util, make_sign) {

	HashTable *_4;
	HashPosition _3;
	zval *mergedArray = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *_9;
	zval *apiObject, *key_param = NULL, *v = NULL, *signBody = NULL, *_0, *_1, *_2 = NULL, **_5, *_10, *_13, *_6$$3 = NULL, *_7$$4 = NULL, *_8$$4 = NULL, *_11$$5, *_12$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &apiObject, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_INIT_VAR(mergedArray);
	array_init(mergedArray);
	ZEPHIR_INIT_VAR(signBody);
	ZVAL_STRING(signBody, "", 1);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, apiObject, SL("_required_properties"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, apiObject, SL("_optional_properties"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "array_merge", NULL, 8, mergedArray, _0, _1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(mergedArray, _2);
	ZEPHIR_MAKE_REF(mergedArray);
	ZEPHIR_CALL_FUNCTION(NULL, "sort", NULL, 12, mergedArray);
	ZEPHIR_UNREF(mergedArray);
	zephir_check_call_status();
	zephir_is_iterable(mergedArray, &_4, &_3, 0, 0, "wxpay/library/util.zep", 17);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(v, _5);
		ZEPHIR_OBS_NVAR(_6$$3);
		zephir_read_property_zval(&_6$$3, apiObject, v, PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(_6$$3))) {
			ZEPHIR_OBS_NVAR(_7$$4);
			zephir_read_property_zval(&_7$$4, apiObject, v, PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_8$$4);
			ZEPHIR_CONCAT_VSVS(_8$$4, v, "=", _7$$4, "&");
			zephir_concat_self(&signBody, _8$$4 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_SV(_9, "key=", key);
	zephir_concat_self(&signBody, _9 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property(&_10, apiObject, SL("debug"), PH_NOISY_CC);
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_VAR(_11$$5);
		ZEPHIR_GET_CONSTANT(_11$$5, "PHP_EOL");
		ZEPHIR_INIT_VAR(_12$$5);
		ZEPHIR_CONCAT_VV(_12$$5, signBody, _11$$5);
		zend_print_zval(_12$$5, 0);
	}
	ZEPHIR_INIT_VAR(_13);
	zephir_md5(_13, signBody);
	zephir_fast_strtoupper(return_value, _13);
	RETURN_MM();

}

PHP_METHOD(WXPay_Library_Util, genRandomString) {

	zval *template = NULL;
	zval *length_param = NULL, *_0 = NULL, _1, _2;
	int length, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length_param);

	if (!length_param) {
		length = 24;
	} else {
		length = zephir_get_intval(length_param);
	}


	ZEPHIR_INIT_VAR(template);
	ZVAL_STRING(template, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 1);
	if (length > 62) {
		length = 62;
	}
	ZEPHIR_CALL_FUNCTION(&_0, "str_shuffle", NULL, 14, template);
	zephir_check_call_status();
	zephir_get_strval(template, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, length);
	zephir_substr(return_value, template, 0 , zephir_get_intval(&_2), 0);
	RETURN_MM();

}

/**
 * 转换 xml 字符串为 数组格式.
 *
 * @param string $xml
 *
 * @return array
 */
PHP_METHOD(WXPay_Library_Util, convertXmlToArray) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *xml_param = NULL, *xmlObj = NULL, *resp_array = NULL, *properties = NULL, *vk = NULL, *dom = NULL, **_2, *_3$$3 = NULL;
	zval *xml = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &xml_param);

	zephir_get_strval(xml, xml_param);


	ZEPHIR_CALL_FUNCTION(&xmlObj, "simplexml_load_string", NULL, 15, xml);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(resp_array);
	array_init(resp_array);
	ZEPHIR_CALL_FUNCTION(&properties, "get_object_vars", NULL, 4, xmlObj);
	zephir_check_call_status();
	zephir_is_iterable(properties, &_1, &_0, 0, 0, "wxpay/library/util.zep", 55);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(vk, _1, _0);
		ZEPHIR_GET_HVALUE(dom, _2);
		ZEPHIR_INIT_NVAR(_3$$3);
		zephir_fast_trim(_3$$3, dom, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		zephir_array_update_zval(&resp_array, vk, &_3$$3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(resp_array);

}

/**
 * 将数组转换为 xml 格式(字符串)
 *
 * @param array $arr
 *
 * @return string
 */
PHP_METHOD(WXPay_Library_Util, convertArrayToXml) {

	zend_bool _3$$3;
	HashTable *_1;
	HashPosition _0;
	zval *xml;
	zval *arr_param = NULL, *k = NULL, *v = NULL, **_2, *_4$$4 = NULL;
	zval *arr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arr_param);

	arr = arr_param;


	ZEPHIR_INIT_VAR(xml);
	ZVAL_STRING(xml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<xml>\n", 1);
	zephir_is_iterable(arr, &_1, &_0, 0, 0, "wxpay/library/util.zep", 75);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		_3$$3 = !(ZEPHIR_IS_EMPTY(v));
		if (_3$$3) {
			_3$$3 = !(Z_TYPE_P(v) == IS_ARRAY);
		}
		if (_3$$3) {
			ZEPHIR_INIT_LNVAR(_4$$4);
			ZEPHIR_CONCAT_SVSVSVS(_4$$4, "    <", k, "><![CDATA[", v, "]]></", k, ">\n");
			zephir_concat_self(&xml, _4$$4 TSRMLS_CC);
		}
	}
	zephir_concat_self_str(&xml, "</xml>", sizeof("</xml>")-1 TSRMLS_CC);
	RETURN_CTOR(xml);

}

/**
 * 获取客户端IP地址
 *
 * @return string
 */
PHP_METHOD(WXPay_Library_Util, getRealIp) {

	zend_bool _3, _7, _11, _14, _16;
	zval *_SERVER, *ip = NULL, _0 = zval_used_for_init, *_1 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_12 = NULL, *_13 = NULL, *_15, *_17, *_18 = NULL, _19$$3, _20$$4, _21$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "HTTP_CLIENT_IP", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "getenv", &_2, 16, &_0);
	zephir_check_call_status();
	_3 = zephir_is_true(_1);
	if (_3) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "HTTP_CLIENT_IP", 0);
		ZEPHIR_CALL_FUNCTION(&_4, "getenv", &_2, 16, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "unknown", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "strcasecmp", NULL, 17, _4, &_0);
		zephir_check_call_status();
		_3 = zephir_is_true(_5);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "HTTP_X_FORWARDED_FOR", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "getenv", &_2, 16, &_0);
	zephir_check_call_status();
	_7 = zephir_is_true(_6);
	if (_7) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "HTTP_X_FORWARDED_FOR", 0);
		ZEPHIR_CALL_FUNCTION(&_8, "getenv", &_2, 16, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "unknown", 0);
		ZEPHIR_CALL_FUNCTION(&_9, "strcasecmp", NULL, 17, _8, &_0);
		zephir_check_call_status();
		_7 = zephir_is_true(_9);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "REMOTE_ADDR", 0);
	ZEPHIR_CALL_FUNCTION(&_10, "getenv", &_2, 16, &_0);
	zephir_check_call_status();
	_11 = zephir_is_true(_10);
	if (_11) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "REMOTE_ADDR", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "getenv", &_2, 16, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "unknown", 0);
		ZEPHIR_CALL_FUNCTION(&_13, "strcasecmp", NULL, 17, _12, &_0);
		zephir_check_call_status();
		_11 = zephir_is_true(_13);
	}
	_14 = zephir_array_isset_string(_SERVER, SS("REMOTE_ADDR"));
	if (_14) {
		zephir_array_fetch_string(&_15, _SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "wxpay/library/util.zep", 98 TSRMLS_CC);
		_14 = zephir_is_true(_15);
	}
	_16 = _14;
	if (_16) {
		zephir_array_fetch_string(&_17, _SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "wxpay/library/util.zep", 98 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "unknown", 0);
		ZEPHIR_CALL_FUNCTION(&_18, "strcasecmp", NULL, 17, _17, &_0);
		zephir_check_call_status();
		_16 = zephir_is_true(_18);
	}
	if (_3) {
		ZEPHIR_SINIT_VAR(_19$$3);
		ZVAL_STRING(&_19$$3, "HTTP_CLIENT_IP", 0);
		ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, 16, &_19$$3);
		zephir_check_call_status();
	} else if (_7) {
		ZEPHIR_SINIT_VAR(_20$$4);
		ZVAL_STRING(&_20$$4, "HTTP_X_FORWARDED_FOR", 0);
		ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, 16, &_20$$4);
		zephir_check_call_status();
	} else if (_11) {
		ZEPHIR_SINIT_VAR(_21$$5);
		ZVAL_STRING(&_21$$5, "REMOTE_ADDR", 0);
		ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, 16, &_21$$5);
		zephir_check_call_status();
	} else if (_16) {
		ZEPHIR_OBS_NVAR(ip);
		zephir_array_fetch_string(&ip, _SERVER, SL("REMOTE_ADDR"), PH_NOISY, "wxpay/library/util.zep", 99 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(ip);
		ZVAL_STRING(ip, "unknown", 1);
	}
	RETURN_CCTOR(ip);

}

/**
 * 使用商户的cert,key调用 wechat-api.
 *
 * @param $apiUri
 * @param $postXml
 * @param $cert
 * @param $key
 *
 * @return array
 * @throws SystemException
 */
PHP_METHOD(WXPay_Library_Util, callWeChatApi) {

	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *apiUri_param = NULL, *xml_param = NULL, *cert_param = NULL, *key_param = NULL, *rootca_param = NULL, *data = NULL, *error_no = NULL, *error_msg = NULL, *ch = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, _3$$3 = zval_used_for_init, _4$$3 = zval_used_for_init, *_6$$5, *_7$$5;
	zval *apiUri = NULL, *xml = NULL, *cert = NULL, *key = NULL, *rootca = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &apiUri_param, &xml_param, &cert_param, &key_param, &rootca_param);

	if (unlikely(Z_TYPE_P(apiUri_param) != IS_STRING && Z_TYPE_P(apiUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'apiUri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(apiUri_param) == IS_STRING)) {
		zephir_get_strval(apiUri, apiUri_param);
	} else {
		ZEPHIR_INIT_VAR(apiUri);
		ZVAL_EMPTY_STRING(apiUri);
	}
	if (unlikely(Z_TYPE_P(xml_param) != IS_STRING && Z_TYPE_P(xml_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'xml' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(xml_param) == IS_STRING)) {
		zephir_get_strval(xml, xml_param);
	} else {
		ZEPHIR_INIT_VAR(xml);
		ZVAL_EMPTY_STRING(xml);
	}
	if (!cert_param) {
		ZEPHIR_INIT_VAR(cert);
		ZVAL_EMPTY_STRING(cert);
	} else {
	if (unlikely(Z_TYPE_P(cert_param) != IS_STRING && Z_TYPE_P(cert_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cert' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(cert_param) == IS_STRING)) {
		zephir_get_strval(cert, cert_param);
	} else {
		ZEPHIR_INIT_VAR(cert);
		ZVAL_EMPTY_STRING(cert);
	}
	}
	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	}
	if (!rootca_param) {
		ZEPHIR_INIT_VAR(rootca);
		ZVAL_EMPTY_STRING(rootca);
	} else {
	if (unlikely(Z_TYPE_P(rootca_param) != IS_STRING && Z_TYPE_P(rootca_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rootca' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(rootca_param) == IS_STRING)) {
		zephir_get_strval(rootca, rootca_param);
	} else {
		ZEPHIR_INIT_VAR(rootca);
		ZVAL_EMPTY_STRING(rootca);
	}
	}


	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 18);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 13);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 30);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_0, apiUri);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 64);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 81);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 42);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_0, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 113);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_0, &_1);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(cert))) {
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 10086);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_STRING(&_4$$3, "PEM", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_LONG(&_3$$3, 10025);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_3$$3, cert);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_LONG(&_3$$3, 10088);
		ZEPHIR_SINIT_NVAR(_4$$3);
		ZVAL_STRING(&_4$$3, "PEM", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_LONG(&_3$$3, 10087);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_3$$3, key);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_LONG(&_3$$3, 10065);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_3$$3, rootca);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 47);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 19, ch, &_0, xml);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&data, "curl_exec", NULL, 20, ch);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(data))) {
		ZEPHIR_CALL_FUNCTION(NULL, "curl_close", &_5, 21, ch);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_SELF("convertxmltoarray", NULL, 0, data);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_FUNCTION(&error_no, "curl_errno", NULL, 22, ch);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&error_msg, "curl_error", NULL, 23, ch);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "curl_close", &_5, 21, ch);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$5);
		object_init_ex(_6$$5, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_7$$5);
		ZEPHIR_CONCAT_SVSV(_7$$5, "：Curl 出错 (", error_no, ")!  ", error_msg);
		ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", NULL, 6, _7$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$5, "wxpay/library/util.zep", 156 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

