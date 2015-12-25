<?php

namespace WXPay\Api\Transfer;


class QueryOrder extends \WXPay\Api
{

    protected $api_url = "https://api.mch.weixin.qq.com/mmpaymkttransfers/gettransferinfo ";


    protected $is_secure_pay = true;

    /**
     * 随机字符串 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
     *
     * @var 5k8264iltkch16cq2502si8znmtm67vs nonce_str String(32)
     * <summary>
     * 随机字符串，不长于32位
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_3
     */
    protected $nonce_str;

    /**
     * 签名 C380BEC2BFD727A4B6845133519F3AD6
     *
     * @var c380bec2bfd727a4b6845133519f3ad6 sign String(32)
     * <summary>
     * 生成签名方式查看3.2.1节
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_3
     */
    protected $sign;

    /**
     * 商户订单号 10000098201411111234567890
     *
     * @var 10000098201411111234567890 partner_trade_no String(28)
     * <summary>
     * 商户调用企业付款API时使用的商户订单号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_3
     */
    protected $partner_trade_no;

    /**
     * 商户号 10000098
     *
     * @var 10000098 mch_id String(32)
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_3
     */
    protected $mch_id;

    /**
     * Appid wxe062425f740d30d8
     *
     * @var wxe062425f740d30d8 appid String(32)
     * <summary>
     * 商户号的appid
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_3
     */
    protected $appid;


    protected $_either_groups = array();


    protected $_required_properties = array("nonce_str", "sign", "partner_trade_no", "mch_id", "appid");


    protected $_optional_properties = array();


}
