
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(WXPay_Api_Micropay_QueryRefund) {

	ZEPHIR_REGISTER_CLASS_EX(WXPay\\Api\\Micropay, QueryRefund, wxpay, api_micropay_queryrefund, wxpay_api_ce, NULL, 0);

	zend_declare_property_string(wxpay_api_micropay_queryrefund_ce, SL("api_url"), "https://api.mch.weixin.qq.com/pay/refundquery", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_bool(wxpay_api_micropay_queryrefund_ce, SL("is_secure_pay"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * 公众账号ID String(32)
	 *
	 * @var string appid wx8888888888888888
	 *
	 * <summary>
	 * 微信分配的公众账号ID（企业号corpid即为此appId）
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_5
	 */
	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("appid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商户号 String(32)
	 *
	 * @var string mch_id 1900000109
	 *
	 * <summary>
	 * 微信支付分配的商户号
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_5
	 */
	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("mch_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 设备号 String(32)
	 *
	 * @var string device_info 013467007045764
	 *
	 * <summary>
	 * 商户自定义的终端设备号，如门店编号、设备的ID等
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_5
	 */
	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("device_info"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 随机字符串 String(32)
	 *
	 * @var string nonce_str 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
	 *
	 * <summary>
	 * 随机字符串，不长于32位。推荐随机数生成算法
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_5
	 */
	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("nonce_str"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 签名 String(32)
	 *
	 * @var string sign C380BEC2BFD727A4B6845133519F3AD6
	 *
	 * <summary>
	 * 签名，详见签名生成算法
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_5
	 */
	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("sign"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 微信订单号 String(28)
	 *
	 * @var string transaction_id 1217752501201407033233368018
	 *
	 * <summary>
	 * 微信订单号
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_5
	 */
	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("transaction_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商户订单号 String(32)
	 *
	 * @var string out_trade_no 1217752501201407033233368018
	 *
	 * <summary>
	 * 商户系统内部的订单号
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_5
	 */
	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("out_trade_no"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商户退款单号 String(32)
	 *
	 * @var string out_refund_no 1217752501201407033233368018
	 *
	 * <summary>
	 * 商户侧传给微信的退款单号
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_5
	 */
	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("out_refund_no"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 微信退款单号 String(28)
	 *
	 * @var string refund_id 1217752501201407033233368018
	 *
	 * <summary>
	 * 微信生成的退款单号，在申请退款接口有返回
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_5
	 */
	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("refund_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("_either_groups"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("_required_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_micropay_queryrefund_ce, SL("_optional_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	wxpay_api_micropay_queryrefund_ce->create_object = zephir_init_properties_WXPay_Api_Micropay_QueryRefund;
	return SUCCESS;

}

static zend_object_value zephir_init_properties_WXPay_Api_Micropay_QueryRefund(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3, *_4$$4, *_7$$5, *_10$$6;
	zval *_0, *_3, *_6, *_9, *_2$$3, *_5$$4 = NULL, *_8$$5 = NULL, *_11$$6 = NULL;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_optional_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_2$$3);
			ZVAL_STRING(_2$$3, "device_info", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			zephir_update_property_this(this_ptr, SL("_optional_properties"), _1$$3 TSRMLS_CC);
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_NULL) {
			ZEPHIR_INIT_VAR(_4$$4);
			zephir_create_array(_4$$4, 8, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5$$4);
			ZVAL_STRING(_5$$4, "appid", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "mch_id", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "nonce_str", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "sign", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "transaction_id", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "out_trade_no", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "out_refund_no", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "refund_id", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			zephir_update_property_this(this_ptr, SL("_required_properties"), _4$$4 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_make_exclude_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$5);
			zephir_create_array(_7$$5, 4, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_8$$5);
			ZVAL_STRING(_8$$5, "appid", 1);
			zephir_array_fast_append(_7$$5, _8$$5);
			ZEPHIR_INIT_NVAR(_8$$5);
			ZVAL_STRING(_8$$5, "mch_id", 1);
			zephir_array_fast_append(_7$$5, _8$$5);
			ZEPHIR_INIT_NVAR(_8$$5);
			ZVAL_STRING(_8$$5, "trade_type", 1);
			zephir_array_fast_append(_7$$5, _8$$5);
			ZEPHIR_INIT_NVAR(_8$$5);
			ZVAL_STRING(_8$$5, "sign", 1);
			zephir_array_fast_append(_7$$5, _8$$5);
			zephir_update_property_this(this_ptr, SL("_make_exclude_properties"), _7$$5 TSRMLS_CC);
		}
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_either_groups"), PH_NOISY_CC);
		if (Z_TYPE_P(_9) == IS_NULL) {
			ZEPHIR_INIT_VAR(_10$$6);
			zephir_create_array(_10$$6, 4, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_11$$6);
			ZVAL_STRING(_11$$6, "transaction_id", 1);
			zephir_array_fast_append(_10$$6, _11$$6);
			ZEPHIR_INIT_NVAR(_11$$6);
			ZVAL_STRING(_11$$6, "out_trade_no", 1);
			zephir_array_fast_append(_10$$6, _11$$6);
			ZEPHIR_INIT_NVAR(_11$$6);
			ZVAL_STRING(_11$$6, "out_refund_no", 1);
			zephir_array_fast_append(_10$$6, _11$$6);
			ZEPHIR_INIT_NVAR(_11$$6);
			ZVAL_STRING(_11$$6, "refund_id", 1);
			zephir_array_fast_append(_10$$6, _11$$6);
			zephir_update_property_this(this_ptr, SL("_either_groups"), _10$$6 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

