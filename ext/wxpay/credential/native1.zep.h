
extern zend_class_entry *wxpay_credential_native1_ce;

ZEPHIR_INIT_CLASS(WXPay_Credential_Native1);

PHP_METHOD(WXPay_Credential_Native1, signWith);
PHP_METHOD(WXPay_Credential_Native1, fire);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_credential_native1_signwith, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, WXPay\\Config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wxpay_credential_native1_method_entry) {
	PHP_ME(WXPay_Credential_Native1, signWith, arginfo_wxpay_credential_native1_signwith, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Credential_Native1, fire, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
