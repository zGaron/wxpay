
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


ZEPHIR_INIT_CLASS(WXPay_Api_Micropay_ShortUrl) {

	ZEPHIR_REGISTER_CLASS_EX(WXPay\\Api\\Micropay, ShortUrl, wxpay, api_micropay_shorturl, wxpay_api_ce, NULL, 0);

	zend_declare_property_string(wxpay_api_micropay_shorturl_ce, SL("api_url"), "https://api.mch.weixin.qq.com/tools/shorturl", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_bool(wxpay_api_micropay_shorturl_ce, SL("is_secure_pay"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

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
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_9&index=8
	 */
	zend_declare_property_null(wxpay_api_micropay_shorturl_ce, SL("appid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 商户号 String(32)
	 *
	 * @var string mch_id 1900000109
	 *
	 * <summary>
	 * 微信支付分配的商户号
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_9&index=8
	 */
	zend_declare_property_null(wxpay_api_micropay_shorturl_ce, SL("mch_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * URL链接 String(512、
	 *
	 * @var string(512、 long_url weixin：//wxpay/bizpayurl?sign=XXXXX&amp;appid=XXXXX&amp;mch_id=XXXXX&amp;product_id=XXXXXX&amp;time_stamp=XXXXXX&amp;nonce_str=XXXXX
	 *
	 * <summary>
	 * 需要转换的URL，签名用原串，传输需URLencode
	 * 
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_9&index=8
	 */
	zend_declare_property_null(wxpay_api_micropay_shorturl_ce, SL("long_url"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_9&index=8
	 */
	zend_declare_property_null(wxpay_api_micropay_shorturl_ce, SL("nonce_str"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 签名 String(32)
	 *
	 * @var string sign C380BEC2BFD727A4B6845133519F3AD6
	 *
	 * <summary>
	 * 签名，详见签名生成算法
	 * </summary>
	 *
	 * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_9&index=8
	 */
	zend_declare_property_null(wxpay_api_micropay_shorturl_ce, SL("sign"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wxpay_api_micropay_shorturl_ce, SL("_either_groups"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_micropay_shorturl_ce, SL("_required_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(wxpay_api_micropay_shorturl_ce, SL("_optional_properties"), ZEND_ACC_PUBLIC TSRMLS_CC);

	wxpay_api_micropay_shorturl_ce->create_object = zephir_init_properties_WXPay_Api_Micropay_ShortUrl;
	return SUCCESS;

}

static zend_object_value zephir_init_properties_WXPay_Api_Micropay_ShortUrl(zend_class_entry *class_type TSRMLS_DC) {

		zval *_3$$4, *_6$$5;
	zval *_0, *_2, *_5, *_8, *_1$$3, *_4$$4 = NULL, *_7$$5 = NULL, *_9$$6;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_optional_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_optional_properties"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_required_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			zephir_create_array(_3$$4, 5, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4$$4);
			ZVAL_STRING(_4$$4, "appid", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "mch_id", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "long_url", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "nonce_str", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "sign", 1);
			zephir_array_fast_append(_3$$4, _4$$4);
			zephir_update_property_this(this_ptr, SL("_required_properties"), _3$$4 TSRMLS_CC);
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_make_exclude_properties"), PH_NOISY_CC);
		if (Z_TYPE_P(_5) == IS_NULL) {
			ZEPHIR_INIT_VAR(_6$$5);
			zephir_create_array(_6$$5, 4, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_7$$5);
			ZVAL_STRING(_7$$5, "appid", 1);
			zephir_array_fast_append(_6$$5, _7$$5);
			ZEPHIR_INIT_NVAR(_7$$5);
			ZVAL_STRING(_7$$5, "mch_id", 1);
			zephir_array_fast_append(_6$$5, _7$$5);
			ZEPHIR_INIT_NVAR(_7$$5);
			ZVAL_STRING(_7$$5, "trade_type", 1);
			zephir_array_fast_append(_6$$5, _7$$5);
			ZEPHIR_INIT_NVAR(_7$$5);
			ZVAL_STRING(_7$$5, "sign", 1);
			zephir_array_fast_append(_6$$5, _7$$5);
			zephir_update_property_this(this_ptr, SL("_make_exclude_properties"), _6$$5 TSRMLS_CC);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_either_groups"), PH_NOISY_CC);
		if (Z_TYPE_P(_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(_9$$6);
			array_init(_9$$6);
			zephir_update_property_this(this_ptr, SL("_either_groups"), _9$$6 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

