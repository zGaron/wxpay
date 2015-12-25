<?php

namespace WXPay\Api\Jsapi;


class QueryRefund extends \WXPay\Api
{

    protected $api_url = "https://api.mch.weixin.qq.com/pay/refundquery";


    protected $is_secure_pay = false;

    /**
     * 公众账号ID String(32)
     *
     * @var string appid wx8888888888888888
     * <summary>
     * 微信分配的公众账号ID（企业号corpid即为此appId）
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/jsapi.php?chapter=9_5
     */
    protected $appid;

    /**
     * 商户号 String(32)
     *
     * @var string mch_id 1900000109
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/jsapi.php?chapter=9_5
     */
    protected $mch_id;

    /**
     * 设备号 String(32)
     *
     * @var string device_info 013467007045764
     * <summary>
     * 商户自定义的终端设备号，如门店编号、设备的ID等
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/jsapi.php?chapter=9_5
     */
    protected $device_info;

    /**
     * 随机字符串 String(32)
     *
     * @var string nonce_str 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
     * <summary>
     * 随机字符串，不长于32位。推荐随机数生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/jsapi.php?chapter=9_5
     */
    protected $nonce_str;

    /**
     * 签名 String(32)
     *
     * @var string sign C380BEC2BFD727A4B6845133519F3AD6
     * <summary>
     * 签名，详见签名生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/jsapi.php?chapter=9_5
     */
    protected $sign;

    /**
     * 微信订单号 String(28)
     *
     * @var string transaction_id 1217752501201407033233368018
     * <summary>
     * 微信订单号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/jsapi.php?chapter=9_5
     */
    protected $transaction_id;

    /**
     * 商户订单号 String(32)
     *
     * @var string out_trade_no 1217752501201407033233368018
     * <summary>
     * 商户系统内部的订单号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/jsapi.php?chapter=9_5
     */
    protected $out_trade_no;

    /**
     * 商户退款单号 String(32)
     *
     * @var string out_refund_no 1217752501201407033233368018
     * <summary>
     * 商户侧传给微信的退款单号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/jsapi.php?chapter=9_5
     */
    protected $out_refund_no;

    /**
     * 微信退款单号 String(28)
     *
     * @var string refund_id 1217752501201407033233368018
     * <summary>
     * 微信生成的退款单号，在申请退款接口有返回
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/jsapi.php?chapter=9_5
     */
    protected $refund_id;


    protected $_either_groups = array("transaction_id", "out_trade_no", "out_refund_no", "refund_id");


    protected $_required_properties = array("appid", "mch_id", "nonce_str", "sign", "transaction_id", "out_trade_no", "out_refund_no", "refund_id");


    protected $_optional_properties = array("device_info");


}
