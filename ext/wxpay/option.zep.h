
extern zend_class_entry *wxpay_option_ce;

ZEPHIR_INIT_CLASS(WXPay_Option);

PHP_METHOD(WXPay_Option, __construct);
PHP_METHOD(WXPay_Option, offsetExists);
PHP_METHOD(WXPay_Option, get);
PHP_METHOD(WXPay_Option, offsetGet);
PHP_METHOD(WXPay_Option, offsetSet);
PHP_METHOD(WXPay_Option, offsetUnset);
PHP_METHOD(WXPay_Option, merge);
PHP_METHOD(WXPay_Option, toArray);
PHP_METHOD(WXPay_Option, count);
PHP_METHOD(WXPay_Option, __set_state);
PHP_METHOD(WXPay_Option, _merge);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_option___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrayParameter, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_option_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_option_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_option_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_option_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_option_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_option_merge, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, option, WXPay\\Option, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_option___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_option__merge, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, option, WXPay\\Option, 0)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wxpay_option_method_entry) {
	PHP_ME(WXPay_Option, __construct, arginfo_wxpay_option___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(WXPay_Option, offsetExists, arginfo_wxpay_option_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Option, get, arginfo_wxpay_option_get, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Option, offsetGet, arginfo_wxpay_option_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Option, offsetSet, arginfo_wxpay_option_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Option, offsetUnset, arginfo_wxpay_option_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Option, merge, arginfo_wxpay_option_merge, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Option, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Option, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Option, __set_state, arginfo_wxpay_option___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(WXPay_Option, _merge, arginfo_wxpay_option__merge, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_FE_END
};
