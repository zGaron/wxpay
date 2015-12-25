
extern zend_class_entry *wxpay_config_ce;

ZEPHIR_INIT_CLASS(WXPay_Config);

PHP_METHOD(WXPay_Config, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_config___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wxpay_config_method_entry) {
	PHP_ME(WXPay_Config, __construct, arginfo_wxpay_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
