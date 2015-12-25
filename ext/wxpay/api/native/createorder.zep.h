
extern zend_class_entry *wxpay_api_native_createorder_ce;

ZEPHIR_INIT_CLASS(WXPay_Api_Native_CreateOrder);

PHP_METHOD(WXPay_Api_Native_CreateOrder, useMode);
PHP_METHOD(WXPay_Api_Native_CreateOrder, generateLink);
PHP_METHOD(WXPay_Api_Native_CreateOrder, fire);
PHP_METHOD(WXPay_Api_Native_CreateOrder, _fire);
static zend_object_value zephir_init_properties_WXPay_Api_Native_CreateOrder(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_api_native_createorder_usemode, 0, 0, 0)
	ZEND_ARG_INFO(0, nativeMode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wxpay_api_native_createorder_method_entry) {
	PHP_ME(WXPay_Api_Native_CreateOrder, useMode, arginfo_wxpay_api_native_createorder_usemode, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Api_Native_CreateOrder, generateLink, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Api_Native_CreateOrder, fire, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Api_Native_CreateOrder, _fire, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
