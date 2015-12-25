
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


ZEPHIR_INIT_CLASS(WXPay_Api_Wap_CreateOrder) {

	ZEPHIR_REGISTER_CLASS_EX(WXPay\\Api\\Wap, CreateOrder, wxpay, api_wap_createorder, wxpay_api_ce, NULL, 0);

	zend_declare_property_string(wxpay_api_wap_createorder_ce, SL("api_url"), "https://api.mch.weixin.qq.com/pay/unifiedorder", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_bool(wxpay_api_wap_createorder_ce, SL("is_secure_pay"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * 公众账号ID String(32)
	 *
	 * @var string appid wxd678efh567hg6787
	 *
	 * <summary>
	 * 微信分配的公众账号ID（企业号corpid即为此appId）
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("appid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商户号 String(32)
	 *
	 * @var string mch_id 1230000109
	 *
	 * <summary>
	 * 微信支付分配的商户号
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("mch_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 设备号 String(32)
	 *
	 * @var string device_info 013467007045764
	 *
	 * <summary>
	 * 终端设备号(门店号或收银设备ID)，注意：PC网页或公众号内支付请传"WEB"
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("device_info"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("nonce_str"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 签名 String(32)
	 *
	 * @var string sign C380BEC2BFD727A4B6845133519F3AD6
	 *
	 * <summary>
	 * 签名，详见签名生成算法
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("sign"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商品描述 String(128)
	 *
	 * @var string body Ipad&nbsp;mini&nbsp;&nbsp;16G&nbsp;&nbsp;白色
	 *
	 * <summary>
	 * 商品或支付单简要描述
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("body"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商品详情 String(8192)
	 *
	 * @var string detail Ipad&nbsp;mini&nbsp;&nbsp;16G&nbsp;&nbsp;白色
	 *
	 * <summary>
	 * 商品名称明细列表
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("detail"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 附加数据 String(127)
	 *
	 * @var string attach 深圳分店
	 *
	 * <summary>
	 * 附加数据，在查询API和支付通知中原样返回，该字段主要用于商户携带订单的自定义数据
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("attach"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商户订单号 String(32)
	 *
	 * @var string out_trade_no 20150806125346
	 *
	 * <summary>
	 * 商户系统内部的订单号,32个字符内、可包含字母,&nbsp;其他说明见商户订单号
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("out_trade_no"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 货币类型 String(16)
	 *
	 * @var string fee_type CNY
	 *
	 * <summary>
	 * 符合ISO&nbsp;4217标准的三位字母代码，默认人民币：CNY，其他值列表详见货币类型
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("fee_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 总金额 Int
	 *
	 * @var int total_fee 888
	 *
	 * <summary>
	 * 订单总金额，单位为分，详见支付金额
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("total_fee"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 终端IP String(16)
	 *
	 * @var string spbill_create_ip 123.12.12.123
	 *
	 * <summary>
	 * APP和网页支付提交用户端ip，Native支付填调用微信支付API的机器IP。
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("spbill_create_ip"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 交易起始时间 String(14)
	 *
	 * @var string time_start 20091225091010
	 *
	 * <summary>
	 * 订单生成时间，格式为yyyyMMddHHmmss，如2009年12月25日9点10分10秒表示为200912
	 * 25091010。其他详见时间规则
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("time_start"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 交易结束时间 String(14)
	 *
	 * @var string time_expire 20091227091010
	 *
	 * <summary>
	 * 订单失效时间，格式为yyyyMMddHHmmss，如2009年12月27日9点10分10秒表示为200912
	 * 27091010。其他详见时间规则注意：最短失效时间间隔必须大于5分钟
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("time_expire"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商品标记 String(32)
	 *
	 * @var string goods_tag WXG
	 *
	 * <summary>
	 * 商品标记，代金券或立减优惠功能的参数，说明详见代金券或立减优惠
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("goods_tag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 通知地址 String(256)
	 *
	 * @var string notify_url http://www.weixin.qq.com/wxpay/pay.php
	 *
	 * <summary>
	 * 接收微信支付异步通知回调地址，通知url必须为直接可访问的url，不能携带参数。
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("notify_url"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 交易类型 String(16)
	 *
	 * @var string trade_type JSAPI
	 *
	 * <summary>
	 * 取值如下：JSAPI，NATIVE，APP，详细说明见参数规定
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_string(wxpay_api_wap_createorder_ce, SL("trade_type"), "WAP", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商品ID String(32)
	 *
	 * @var string product_id 12235413214070356458058
	 *
	 * <summary>
	 * trade_type=NATIVE，此参数必传。此id为二维码中包含的商品ID，商户自行定义。
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("product_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 指定支付方式 String(32)
	 *
	 * @var string limit_pay no_credit
	 *
	 * <summary>
	 * no_credit--指定不能使用信用卡支付
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("limit_pay"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 用户标识 String(128)
	 *
	 * @var string openid oUpF8uMuAJO_M2pxb1Q9zNjWeS6o
	 *
	 * <summary>
	 * trade_type=JSAPI，此参数必传，用户在商户appid下的唯一标识。openid如何获取，可参考
	 * 【获取openid】。企业号请使用【企业号OAuth2.0接口】获取企业号内成员userid，再调用【企业号
	 * userid转openid接口】进行转换
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
	 */
	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("openid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("_either_groups"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("_required_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_wap_createorder_ce, SL("_optional_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	wxpay_api_wap_createorder_ce->create_object = zephir_init_properties_WXPay_Api_Wap_CreateOrder;
	return SUCCESS;

}

static zend_object_value zephir_init_properties_WXPay_Api_Wap_CreateOrder(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3, *_4$$4, *_7$$5;
	zval *_0, *_3, *_6, *_9, *_2$$3 = NULL, *_5$$4 = NULL, *_8$$5 = NULL, *_10$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_optional_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 10, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_2$$3);
			ZVAL_STRING(_2$$3, "product_id", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
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
			ZVAL_STRING(_2$$3, "time_start", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "time_expire", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "goods_tag", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "limit_pay", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			ZEPHIR_INIT_NVAR(_2$$3);
			ZVAL_STRING(_2$$3, "openid", 1);
			zephir_array_fast_append(_1$$3, _2$$3);
			zephir_update_property_this(this_ptr, SL("_optional_properties"), _1$$3 TSRMLS_CC);
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_NULL) {
			ZEPHIR_INIT_VAR(_4$$4);
			zephir_create_array(_4$$4, 10, 0 TSRMLS_CC);
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
			ZVAL_STRING(_5$$4, "notify_url", 1);
			zephir_array_fast_append(_4$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_STRING(_5$$4, "trade_type", 1);
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

