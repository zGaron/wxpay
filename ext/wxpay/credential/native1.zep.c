
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


ZEPHIR_INIT_CLASS(WXPay_Credential_Native1) {

	ZEPHIR_REGISTER_CLASS_EX(WXPay\\Credential, Native1, wxpay, credential_native1, wxpay_credential_ce, wxpay_credential_native1_method_entry, 0);

	zend_declare_property_null(wxpay_credential_native1_ce, SL("appid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_native1_ce, SL("mch_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_native1_ce, SL("time_stamp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_native1_ce, SL("nonce_str"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_native1_ce, SL("product_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_credential_native1_ce, SL("sign"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(WXPay_Credential_Native1, signWith) {

	zval *config;

	zephir_fetch_params(0, 1, 0, &config);




}

PHP_METHOD(WXPay_Credential_Native1, fire) {

	


}

