<?php

namespace WXPay\Api\App;


class CreateRefund extends \WXPay\Api
{

    protected $api_url = "https://api.mch.weixin.qq.com/secapi/pay/refund";


    protected $is_secure_pay = true;

    /**
     * 公众账号ID String(32)
     *
     * @var string appid wx8888888888888888
     * <summary>
     * 微信分配的公众账号ID（企业号corpid即为此appId）
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $appid;

    /**
     * 商户号 String(32)
     *
     * @var string mch_id 1900000109
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $mch_id;

    /**
     * 设备号 String(32)
     *
     * @var string device_info 013467007045764
     * <summary>
     * 终端设备号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $device_info;

    /**
     * 随机字符串 String(32)
     *
     * @var string nonce_str 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
     * <summary>
     * 随机字符串，不长于32位。推荐随机数生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $nonce_str;

    /**
     * 签名 String(32)
     *
     * @var string sign C380BEC2BFD727A4B6845133519F3AD6
     * <summary>
     * 签名，详见签名生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $sign;

    /**
     * 微信订单号 String(28)
     *
     * @var string transaction_id 1217752501201407033233368018
     * <summary>
     * 微信生成的订单号，在支付通知中有返回
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $transaction_id;

    /**
     * 商户订单号 String(32)
     *
     * @var string out_trade_no 1217752501201407033233368018
     * <summary>
     * 商户侧传给微信的订单号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $out_trade_no;

    /**
     * 商户退款单号 String(32)
     *
     * @var string out_refund_no 1217752501201407033233368018
     * <summary>
     * 商户系统内部的退款单号，商户系统内部唯一，同一退款单号多次请求只退一笔
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $out_refund_no;

    /**
     * 总金额 Int
     *
     * @var int total_fee 100
     * <summary>
     * 订单总金额，单位为分，只能为整数，详见支付金额
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $total_fee;

    /**
     * 退款金额 Int
     *
     * @var int refund_fee 100
     * <summary>
     * 退款总金额，订单总金额，单位为分，只能为整数，详见支付金额
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $refund_fee;

    /**
     * 货币种类 String(8)
     *
     * @var string refund_fee_type CNY
     * <summary>
     * 货币类型，符合ISO&nbsp;4217标准的三位字母代码，默认人民币：CNY，其他值列表详见货币类型
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $refund_fee_type;

    /**
     * 操作员 String(32)
     *
     * @var string op_user_id 1900000109
     * <summary>
     * 操作员帐号,&nbsp;默认为商户号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/app.php?chapter=9_4&index=6
     */
    protected $op_user_id;


    protected $_either_groups = array("transaction_id", "out_trade_no");


    protected $_required_properties = array("appid", "mch_id", "nonce_str", "sign", "transaction_id", "out_trade_no", "out_refund_no", "total_fee", "refund_fee", "op_user_id");


    protected $_optional_properties = array("device_info", "refund_fee_type");


}
