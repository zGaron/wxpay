
extern zend_class_entry *wxpay_api_ce;

ZEPHIR_INIT_CLASS(WXPay_Api);

PHP_METHOD(WXPay_Api, make);
PHP_METHOD(WXPay_Api, signWith);
PHP_METHOD(WXPay_Api, setDebug);
PHP_METHOD(WXPay_Api, dump);
PHP_METHOD(WXPay_Api, fire);
static zend_object_value zephir_init_properties_WXPay_Api(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_api_make, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_api_signwith, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, config, WXPay\\Config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_api_setdebug, 0, 0, 0)
	ZEND_ARG_INFO(0, debug)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wxpay_api_method_entry) {
	PHP_ME(WXPay_Api, make, arginfo_wxpay_api_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(WXPay_Api, signWith, arginfo_wxpay_api_signwith, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Api, setDebug, arginfo_wxpay_api_setdebug, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Api, dump, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Api, fire, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
