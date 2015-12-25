
extern zend_class_entry *wxpay_credential_app_ce;

ZEPHIR_INIT_CLASS(WXPay_Credential_App);

PHP_METHOD(WXPay_Credential_App, make);
PHP_METHOD(WXPay_Credential_App, signWith);
PHP_METHOD(WXPay_Credential_App, fire);
static zend_object_value zephir_init_properties_WXPay_Credential_App(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_credential_app_make, 0, 0, 1)
	ZEND_ARG_INFO(0, prepay_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_credential_app_signwith, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, WXPay\\Config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wxpay_credential_app_method_entry) {
	PHP_ME(WXPay_Credential_App, make, arginfo_wxpay_credential_app_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(WXPay_Credential_App, signWith, arginfo_wxpay_credential_app_signwith, ZEND_ACC_PUBLIC)
	PHP_ME(WXPay_Credential_App, fire, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
