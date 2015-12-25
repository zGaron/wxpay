<?php

namespace WXPay\Api\Transfer;


class CreateOrder extends \WXPay\Api
{

    protected $api_url = "https://api.mch.weixin.qq.com/mmpaymkttransfers/promotion/transfers";


    protected $is_secure_pay = true;

    /**
     * 公众账号appid wx8888888888888888
     *
     * @var wx8888888888888888 mch_appid String
     * <summary>
     * 微信分配的公众账号ID（企业号corpid即为此appId）
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $mch_appid;

    /**
     * 商户号 1900000109
     *
     * @var 1900000109 mchid String(32)
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $mchid;

    /**
     * 设备号 013467007045764
     *
     * @var 013467007045764 device_info String(32)
     * <summary>
     * 微信支付分配的终端设备号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $device_info;

    /**
     * 随机字符串 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
     *
     * @var 5k8264iltkch16cq2502si8znmtm67vs nonce_str String(32)
     * <summary>
     * 随机字符串，不长于32位
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $nonce_str;

    /**
     * 签名 C380BEC2BFD727A4B6845133519F3AD6
     *
     * @var c380bec2bfd727a4b6845133519f3ad6 sign String(32)
     * <summary>
     * 签名，详见签名算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $sign;

    /**
     * 商户订单号 10000098201411111234567890
     *
     * @var 10000098201411111234567890 partner_trade_no String
     * <summary>
     * 商户订单号，需保持唯一性
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $partner_trade_no;

    /**
     * 用户openid oxTWIuGaIt6gTKsQRLau2M0yL16E
     *
     * @var oxtwiugait6gtksqrlau2m0yl16e openid String
     * <summary>
     * 商户appid下，某用户的openid
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $openid;

    /**
     * 校验用户姓名选项 OPTION_CHECK
     *
     * @var option_check check_name String
     * <summary>
     * NO_CHECK：不校验真实姓名
     * FORCE_CHECK：强校验真实姓名
     * （未实名认证的用户会校验失败，无法转账）
     * OPTION_CHECK：针对
     * 已实名认证的用户才校验真实姓名（未实名认证用户不校验，可以转账成功）
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $check_name;

    /**
     * 收款用户姓名 马花花
     *
     * @var 马花花 re_user_name String
     * <summary>
     * 收款用户真实姓名。
     * 如果check_name设置为FORCE_CHECK
     * 或OPTION_CHECK，则必填用户真实姓名
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $re_user_name;

    /**
     * 金额 10099
     *
     * @var 10099 amount int
     * <summary>
     * 企业付款金额，单位为分
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $amount;

    /**
     * 企业付款描述信息 理赔
     *
     * @var 理赔 desc String
     * <summary>
     * 企业付款操作说明信息。必填。
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $desc;

    /**
     * Ip地址 192.168.0.1
     *
     * @var 192.168.0.1 spbill_create_ip String(32)
     * <summary>
     * 调用接口的机器Ip地址
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/mch_pay.php?chapter=14_2
     */
    protected $spbill_create_ip;


    protected $_either_groups = array();


    protected $_required_properties = array("mch_appid", "mchid", "nonce_str", "sign", "partner_trade_no", "openid", "check_name", "amount", "desc", "spbill_create_ip");


    protected $_optional_properties = array("re_user_name", "device_info");


}
