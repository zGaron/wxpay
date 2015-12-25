<?php

namespace WXPay\Api\Native;


class CloseOrder extends \WXPay\Api
{

    protected $api_url = "https://api.mch.weixin.qq.com/pay/closeorder ";


    protected $is_secure_pay = false;

    /**
     * 公众账号ID String(32)
     *
     * @var string appid wx8888888888888888
     * <summary>
     * 微信分配的公众账号ID（企业号corpid即为此appId）
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_3
     */
    protected $appid;

    /**
     * 商户号 String(32)
     *
     * @var string mch_id 1900000109
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_3
     */
    protected $mch_id;

    /**
     * 商户订单号 String(32)
     *
     * @var string out_trade_no 1217752501201407033233368018
     * <summary>
     * 商户系统内部的订单号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_3
     */
    protected $out_trade_no;

    /**
     * 随机字符串 String(32)
     *
     * @var string nonce_str 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
     * <summary>
     * 商户系统内部的订单号,32个字符内、可包含字母,&nbsp;其他说明见安全规范
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_3
     */
    protected $nonce_str;

    /**
     * 签名 String(32)
     *
     * @var string sign C380BEC2BFD727A4B6845133519F3AD6
     * <summary>
     * 签名，详见签名生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_3
     */
    protected $sign;


    protected $_either_groups = array();


    protected $_required_properties = array("appid", "mch_id", "out_trade_no", "nonce_str", "sign");


    protected $_optional_properties = array();


}
