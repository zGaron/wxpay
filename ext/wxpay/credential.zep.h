
extern zend_class_entry *wxpay_credential_ce;

ZEPHIR_INIT_CLASS(WXPay_Credential);

PHP_METHOD(WXPay_Credential, signWith);
PHP_METHOD(WXPay_Credential, fire);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_credential_signwith, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, WXPay\\Config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wxpay_credential_method_entry) {
	PHP_ME(WXPay_Credential, signWith, arginfo_wxpay_credential_signwith, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Credential, fire, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
