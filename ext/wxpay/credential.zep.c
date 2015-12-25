
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(WXPay_Credential) {

	ZEPHIR_REGISTER_CLASS_EX(WXPay, Credential, wxpay, credential, wxpay_option_ce, wxpay_credential_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(WXPay_Credential, signWith) {

}

PHP_METHOD(WXPay_Credential, fire) {

}

