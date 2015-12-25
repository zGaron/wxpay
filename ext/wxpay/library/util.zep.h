
extern zend_class_entry *wxpay_library_util_ce;

ZEPHIR_INIT_CLASS(WXPay_Library_Util);

PHP_METHOD(WXPay_Library_Util, make_sign);
PHP_METHOD(WXPay_Library_Util, genRandomString);
PHP_METHOD(WXPay_Library_Util, convertXmlToArray);
PHP_METHOD(WXPay_Library_Util, convertArrayToXml);
PHP_METHOD(WXPay_Library_Util, getRealIp);
PHP_METHOD(WXPay_Library_Util, callWeChatApi);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_library_util_make_sign, 0, 0, 2)
	ZEND_ARG_INFO(0, apiObject)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_library_util_genrandomstring, 0, 0, 0)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_library_util_convertxmltoarray, 0, 0, 1)
	ZEND_ARG_INFO(0, xml)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_library_util_convertarraytoxml, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wxpay_library_util_callwechatapi, 0, 0, 2)
	ZEND_ARG_INFO(0, apiUri)
	ZEND_ARG_INFO(0, xml)
	ZEND_ARG_INFO(0, cert)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, rootca)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wxpay_library_util_method_entry) {
	PHP_ME(WXPay_Library_Util, make_sign, arginfo_wxpay_library_util_make_sign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(WXPay_Library_Util, genRandomString, arginfo_wxpay_library_util_genrandomstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(WXPay_Library_Util, convertXmlToArray, arginfo_wxpay_library_util_convertxmltoarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(WXPay_Library_Util, convertArrayToXml, arginfo_wxpay_library_util_convertarraytoxml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(WXPay_Library_Util, getRealIp, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(WXPay_Library_Util, callWeChatApi, arginfo_wxpay_library_util_callwechatapi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
