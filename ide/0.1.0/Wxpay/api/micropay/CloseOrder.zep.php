<?php

namespace WXPay\Api\Micropay;


class CloseOrder extends \WXPay\Api
{

    protected $api_url = "https://api.mch.weixin.qq.com/secapi/pay/reverse";


    protected $is_secure_pay = true;

    /**
     * 公众账号ID 是
     *
     * @var 是 appid wx8888888888888888
     * <summary>
     * 微信分配的公众账号ID（企业号corpid即为此appId）
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_11&index=3
     */
    protected $appid;

    /**
     * 商户号 是
     *
     * @var 是 mch_id 1900000109
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_11&index=3
     */
    protected $mch_id;

    /**
     * 微信订单号 否
     *
     * @var 否 transaction_id 1217752501201407033233368018
     * <summary>
     * 微信的订单号，优先使用
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_11&index=3
     */
    protected $transaction_id;

    /**
     * 商户订单号 是
     *
     * @var 是 out_trade_no 1217752501201407033233368018
     * <summary>
     * 商户系统内部的订单号,transaction_id、out_trade_no二选一，如果同时存在优先级：tr
     * ansaction_id> out_trade_no
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_11&index=3
     */
    protected $out_trade_no;

    /**
     * 随机字符串 是
     *
     * @var 是 nonce_str 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
     * <summary>
     * 随机字符串，不长于32位。推荐随机数生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_11&index=3
     */
    protected $nonce_str;

    /**
     * 签名 是
     *
     * @var 是 sign C380BEC2BFD727A4B6845133519F3AD6
     * <summary>
     * 签名，详见签名生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_11&index=3
     */
    protected $sign;


    protected $_either_groups = array();


    protected $_required_properties = array("appid", "mch_id", "out_trade_no", "nonce_str", "sign");


    protected $_optional_properties = array("transaction_id");


}
