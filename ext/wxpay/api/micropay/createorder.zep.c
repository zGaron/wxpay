
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


ZEPHIR_INIT_CLASS(WXPay_Api_Micropay_CreateOrder) {

	ZEPHIR_REGISTER_CLASS_EX(WXPay\\Api\\Micropay, CreateOrder, wxpay, api_micropay_createorder, wxpay_api_ce, NULL, 0);

	zend_declare_property_string(wxpay_api_micropay_createorder_ce, SL("api_url"), "https://api.mch.weixin.qq.com/pay/micropay", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_bool(wxpay_api_micropay_createorder_ce, SL("is_secure_pay"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * 公众账号ID 是
	 *
	 * @var 是 appid wx8888888888888888
	 *
	 * <summary>
	 * 微信分配的公众账号ID（企业号corpid即为此appId）
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("appid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商户号 是
	 *
	 * @var 是 mch_id 1900000109
	 *
	 * <summary>
	 * 微信支付分配的商户号
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("mch_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 设备号 否
	 *
	 * @var 否 device_info 013467007045764
	 *
	 * <summary>
	 * 终端设备号(商户自定义，如门店编号)
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("device_info"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 随机字符串 是
	 *
	 * @var 是 nonce_str 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
	 *
	 * <summary>
	 * 随机字符串，不长于32位。推荐随机数生成算法
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("nonce_str"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 签名 是
	 *
	 * @var 是 sign C380BEC2BFD727A4B6845133519F3AD6
	 *
	 * <summary>
	 * 签名，详见签名生成算法
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("sign"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商品描述 是
	 *
	 * @var 是 body Ipadmini16G白色
	 *
	 * <summary>
	 * 商品或支付单简要描述
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商品详情 否
	 *
	 * @var 否 detail Ipadmini16G白色
	 *
	 * <summary>
	 * 商品名称明细列表
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("detail"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 附加数据 否
	 *
	 * @var 否 attach 说明
	 *
	 * <summary>
	 * 附加数据，在查询API和支付通知中原样返回，该字段主要用于商户携带订单的自定义数据
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("attach"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商户订单号 是
	 *
	 * @var 是 out_trade_no 1217752501201407033233368018
	 *
	 * <summary>
	 * 商户系统内部的订单号,32个字符内、可包含字母,其他说明见商户订单号
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("out_trade_no"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 总金额 是
	 *
	 * @var 是 total_fee 888
	 *
	 * <summary>
	 * 订单总金额，单位为分，只能为整数，详见支付金额
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("total_fee"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 货币类型 否
	 *
	 * @var 否 fee_type CNY
	 *
	 * <summary>
	 * 符合ISO4217标准的三位字母代码，默认人民币：CNY，其他值列表详见货币类型
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("fee_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 终端IP 是
	 *
	 * @var 是 spbill_create_ip 8.8.8.8
	 *
	 * <summary>
	 * 调用微信支付API的机器IP
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("spbill_create_ip"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商品标记 否
	 *
	 * @var 否 goods_tag 
	 *
	 * <summary>
	 * 商品标记，代金券或立减优惠功能的参数，说明详见代金券或立减优惠
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("goods_tag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 指定支付方式 否
	 *
	 * @var 否 limit_pay no_credit
	 *
	 * <summary>
	 * no_credit--指定不能使用信用卡支付
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("limit_pay"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 授权码 是
	 *
	 * @var 是 auth_code 120061098828009406
	 *
	 * <summary>
	 * 扫码支付授权码，设备读取用户微信中的条码或者二维码信息
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
	 */
	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("auth_code"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("_either_groups"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("_required_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_micropay_createorder_ce, SL("_optional_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	wxpay_api_micropay_createorder_ce->create_object = zephir_init_properties_WXPay_Api_Micropay_CreateOrder;
	return SUCCESS;

}

static zend_object_value zephir_init_properties_WXPay_Api_Micropay_CreateOrder(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3, *_4$$4, *_7$$5;
	zval *_0, *_3, *_6, *_9, *_2$$3 = NULL, *_5$$4 = NULL, *_8$$5 = NULL, *_10$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_optional_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 6, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_2$$3);
			ZVAL_STRING(_2$$3, "device_info", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "detail", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "attach", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "fee_type", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "goods_tag", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "limit_pay", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			zephir_update_property_this(this_ptr, SL("_optional_properties"), _1$$3 TSRMLS_CC);
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_NULL) {
			ZEPHIR_INIT_VAR(_4$$4);
			zephir_create_array(_4$$4, 9, 0 TSRMLS_CC);
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
			ZVAL_STRING(_5$$4, "body", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "out_trade_no", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "total_fee", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "spbill_create_ip", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "auth_code", 1);
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

