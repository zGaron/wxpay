<?php

namespace WXPay\Api\Native;


class Shorturl extends \WXPay\Api
{

    protected $api_url = "https://api.mch.weixin.qq.com/tools/shorturl";


    protected $is_secure_pay = false;

    /**
     * 公众账号ID String(32)
     *
     * @var string appid wx8888888888888888
     * <summary>
     * 微信分配的公众账号ID（企业号corpid即为此appId）
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_9
     */
    protected $appid;

    /**
     * 商户号 String(32)
     *
     * @var string mch_id 1900000109
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_9
     */
    protected $mch_id;

    /**
     * URL链接 String(512、
     *
     * @var string(512、 long_url weixin：//wxpay/bizpayurl?sign=XXXXX&amp;appid=XXXXX&amp;mch_id=XXXXX&amp;product_id=XXXXXX&amp;time_stamp=XXXXXX&amp;nonce_str=XXXXX
     * <summary>
     * 需要转换的URL，签名用原串，传输需URLencode
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_9
     */
    protected $long_url;

    /**
     * 随机字符串 String(32)
     *
     * @var string nonce_str 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
     * <summary>
     * 随机字符串，不长于32位。推荐随机数生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_9
     */
    protected $nonce_str;

    /**
     * 签名 String(32)
     *
     * @var string sign C380BEC2BFD727A4B6845133519F3AD6
     * <summary>
     * 签名，详见签名生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_9
     */
    protected $sign;


    protected $_either_groups = array();


    protected $_required_properties = array("appid", "mch_id", "long_url", "nonce_str", "sign");


    protected $_optional_properties = array();


}
