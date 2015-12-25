
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


ZEPHIR_INIT_CLASS(WXPay_Api_Transfer_CreateOrder) {

	ZEPHIR_REGISTER_CLASS_EX(WXPay\\Api\\Transfer, CreateOrder, wxpay, api_transfer_createorder, wxpay_api_ce, NULL, 0);

	zend_declare_property_string(wxpay_api_transfer_createorder_ce, SL("api_url"), "https://api.mch.weixin.qq.com/mmpaymkttransfers/promotion/transfers", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_bool(wxpay_api_transfer_createorder_ce, SL("is_secure_pay"), 1, ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * 公众账号appid wx8888888888888888
	 *
	 * @var wx8888888888888888 mch_appid String
	 *
	 * <summary>
	 * 微信分配的公众账号ID（企业号corpid即为此appId）
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("mch_appid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商户号 1900000109
	 *
	 * @var 1900000109 mchid String(32)
	 *
	 * <summary>
	 * 微信支付分配的商户号
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("mchid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 设备号 013467007045764
	 *
	 * @var 013467007045764 device_info String(32)
	 *
	 * <summary>
	 * 微信支付分配的终端设备号
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("device_info"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 随机字符串 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
	 *
	 * @var 5k8264iltkch16cq2502si8znmtm67vs nonce_str String(32)
	 *
	 * <summary>
	 * 随机字符串，不长于32位
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("nonce_str"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 签名 C380BEC2BFD727A4B6845133519F3AD6
	 *
	 * @var c380bec2bfd727a4b6845133519f3ad6 sign String(32)
	 *
	 * <summary>
	 * 签名，详见签名算法
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("sign"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商户订单号 10000098201411111234567890
	 *
	 * @var 10000098201411111234567890 partner_trade_no String
	 *
	 * <summary>
	 * 商户订单号，需保持唯一性
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("partner_trade_no"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 用户openid oxTWIuGaIt6gTKsQRLau2M0yL16E
	 *
	 * @var oxtwiugait6gtksqrlau2m0yl16e openid String
	 *
	 * <summary>
	 * 商户appid下，某用户的openid
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("openid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 校验用户姓名选项 OPTION_CHECK
	 *
	 * @var option_check check_name String
	 *
	 * <summary>
	 * NO_CHECK：不校验真实姓名 
	 FORCE_CHECK：强校验真实姓名
	 * （未实名认证的用户会校验失败，无法转账） 
	 OPTION_CHECK：针对
	 * 已实名认证的用户才校验真实姓名（未实名认证用户不校验，可以转账成功）
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("check_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 收款用户姓名 马花花
	 *
	 * @var 马花花 re_user_name String
	 *
	 * <summary>
	 * 收款用户真实姓名。 
	 如果check_name设置为FORCE_CHECK
	 * 或OPTION_CHECK，则必填用户真实姓名
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("re_user_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 金额 10099
	 *
	 * @var 10099 amount int
	 *
	 * <summary>
	 * 企业付款金额，单位为分
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("amount"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 企业付款描述信息 理赔
	 *
	 * @var 理赔 desc String
	 *
	 * <summary>
	 * 企业付款操作说明信息。必填。
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("desc"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Ip地址 192.168.0.1
	 *
	 * @var 192.168.0.1 spbill_create_ip String(32)
	 *
	 * <summary>
	 * 调用接口的机器Ip地址
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
	 */
	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("spbill_create_ip"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("_either_groups"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("_required_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_transfer_createorder_ce, SL("_optional_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	wxpay_api_transfer_createorder_ce->create_object = zephir_init_properties_WXPay_Api_Transfer_CreateOrder;
	return SUCCESS;

}

static zend_object_value zephir_init_properties_WXPay_Api_Transfer_CreateOrder(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3, *_4$$4, *_7$$5;
	zval *_0, *_3, *_6, *_9, *_2$$3 = NULL, *_5$$4 = NULL, *_8$$5 = NULL, *_10$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_optional_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_2$$3);
			ZVAL_STRING(_2$$3, "re_user_name", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "device_info", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			zephir_update_property_this(this_ptr, SL("_optional_properties"), _1$$3 TSRMLS_CC);
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_NULL) {
			ZEPHIR_INIT_VAR(_4$$4);
			zephir_create_array(_4$$4, 10, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5$$4);
			ZVAL_STRING(_5$$4, "mch_appid", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "mchid", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "nonce_str", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "sign", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "partner_trade_no", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "openid", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "check_name", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "amount", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "desc", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "spbill_create_ip", 1);
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
			array_init(_10$$6);
			zephir_update_property_this(this_ptr, SL("_either_groups"), _10$$6 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

