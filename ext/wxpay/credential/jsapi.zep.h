
extern zend_class_entry *wxpay_credential_jsapi_ce;

ZEPHIR_INIT_CLASS(WXPay_Credential_Jsapi);

PHP_METHOD(WXPay_Credential_Jsapi, make);
PHP_METHOD(WXPay_Credential_Jsapi, signWith);
PHP_METHOD(WXPay_Credential_Jsapi, fire);
static zend_object_value zephir_init_properties_WXPay_Credential_Jsapi(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_credential_jsapi_make, 0, 0, 1)
	ZEND_ARG_INFO(0, prepay_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_credential_jsapi_signwith, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, WXPay\\Config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wxpay_credential_jsapi_method_entry) {
	PHP_ME(WXPay_Credential_Jsapi, make, arginfo_wxpay_credential_jsapi_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(WXPay_Credential_Jsapi, signWith, arginfo_wxpay_credential_jsapi_signwith, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Credential_Jsapi, fire, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
