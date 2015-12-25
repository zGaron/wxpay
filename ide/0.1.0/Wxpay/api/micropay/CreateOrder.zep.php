<?php

namespace WXPay\Api\Micropay;


class CreateOrder extends \WXPay\Api
{

    protected $api_url = "https://api.mch.weixin.qq.com/pay/micropay";


    protected $is_secure_pay = false;

    /**
     * 公众账号ID 是
     *
     * @var 是 appid wx8888888888888888
     * <summary>
     * 微信分配的公众账号ID（企业号corpid即为此appId）
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $appid;

    /**
     * 商户号 是
     *
     * @var 是 mch_id 1900000109
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $mch_id;

    /**
     * 设备号 否
     *
     * @var 否 device_info 013467007045764
     * <summary>
     * 终端设备号(商户自定义，如门店编号)
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $device_info;

    /**
     * 随机字符串 是
     *
     * @var 是 nonce_str 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
     * <summary>
     * 随机字符串，不长于32位。推荐随机数生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $nonce_str;

    /**
     * 签名 是
     *
     * @var 是 sign C380BEC2BFD727A4B6845133519F3AD6
     * <summary>
     * 签名，详见签名生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $sign;

    /**
     * 商品描述 是
     *
     * @var 是 body Ipadmini16G白色
     * <summary>
     * 商品或支付单简要描述
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $body;

    /**
     * 商品详情 否
     *
     * @var 否 detail Ipadmini16G白色
     * <summary>
     * 商品名称明细列表
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $detail;

    /**
     * 附加数据 否
     *
     * @var 否 attach 说明
     * <summary>
     * 附加数据，在查询API和支付通知中原样返回，该字段主要用于商户携带订单的自定义数据
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $attach;

    /**
     * 商户订单号 是
     *
     * @var 是 out_trade_no 1217752501201407033233368018
     * <summary>
     * 商户系统内部的订单号,32个字符内、可包含字母,其他说明见商户订单号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $out_trade_no;

    /**
     * 总金额 是
     *
     * @var 是 total_fee 888
     * <summary>
     * 订单总金额，单位为分，只能为整数，详见支付金额
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $total_fee;

    /**
     * 货币类型 否
     *
     * @var 否 fee_type CNY
     * <summary>
     * 符合ISO4217标准的三位字母代码，默认人民币：CNY，其他值列表详见货币类型
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $fee_type;

    /**
     * 终端IP 是
     *
     * @var 是 spbill_create_ip 8.8.8.8
     * <summary>
     * 调用微信支付API的机器IP
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $spbill_create_ip;

    /**
     * 商品标记 否
     *
     * @var 否 goods_tag
     * <summary>
     * 商品标记，代金券或立减优惠功能的参数，说明详见代金券或立减优惠
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $goods_tag;

    /**
     * 指定支付方式 否
     *
     * @var 否 limit_pay no_credit
     * <summary>
     * no_credit--指定不能使用信用卡支付
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $limit_pay;

    /**
     * 授权码 是
     *
     * @var 是 auth_code 120061098828009406
     * <summary>
     * 扫码支付授权码，设备读取用户微信中的条码或者二维码信息
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_10&index=1
     */
    protected $auth_code;


    protected $_either_groups = array();


    protected $_required_properties = array("appid", "mch_id", "nonce_str", "sign", "body", "out_trade_no", "total_fee", "spbill_create_ip", "auth_code");


    protected $_optional_properties = array("device_info", "detail", "attach", "fee_type", "goods_tag", "limit_pay");


}
