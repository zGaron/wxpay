<?php

namespace WXPay\Api\Native;


class CreateOrder extends \WXPay\Api
{

    const MODE_NATIVE_1 = 1;


    const MODE_NATIVE_2 = 2;


    protected $api_url = "https://api.mch.weixin.qq.com/pay/unifiedorder";


    protected $is_secure_pay = false;

    /**
     * 公众账号ID String(32)
     *
     * @var string appid wxd678efh567hg6787
     * <summary>
     * 微信分配的公众账号ID（企业号corpid即为此appId）
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $appid;

    /**
     * 商户号 String(32)
     *
     * @var string mch_id 1230000109
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $mch_id;

    /**
     * 设备号 String(32)
     *
     * @var string device_info 013467007045764
     * <summary>
     * 终端设备号(门店号或收银设备ID)，注意：PC网页或公众号内支付请传"WEB"
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $device_info;

    /**
     * 随机字符串 String(32)
     *
     * @var string nonce_str 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
     * <summary>
     * 随机字符串，不长于32位。推荐随机数生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $nonce_str;

    /**
     * 签名 String(32)
     *
     * @var string sign C380BEC2BFD727A4B6845133519F3AD6
     * <summary>
     * 签名，详见签名生成算法
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $sign;

    /**
     * 商品描述 String(128)
     *
     * @var string body Ipad&nbsp;mini&nbsp;&nbsp;16G&nbsp;&nbsp;白色
     * <summary>
     * 商品或支付单简要描述
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $body;

    /**
     * 商品详情 String(8192)
     *
     * @var string detail Ipad&nbsp;mini&nbsp;&nbsp;16G&nbsp;&nbsp;白色
     * <summary>
     * 商品名称明细列表
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $detail;

    /**
     * 附加数据 String(127)
     *
     * @var string attach 深圳分店
     * <summary>
     * 附加数据，在查询API和支付通知中原样返回，该字段主要用于商户携带订单的自定义数据
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $attach;

    /**
     * 商户订单号 String(32)
     *
     * @var string out_trade_no 20150806125346
     * <summary>
     * 商户系统内部的订单号,32个字符内、可包含字母,&nbsp;其他说明见商户订单号
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $out_trade_no;

    /**
     * 货币类型 String(16)
     *
     * @var string fee_type CNY
     * <summary>
     * 符合ISO&nbsp;4217标准的三位字母代码，默认人民币：CNY，其他值列表详见货币类型
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $fee_type;

    /**
     * 总金额 Int
     *
     * @var int total_fee 888
     * <summary>
     * 订单总金额，单位为分，详见支付金额
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $total_fee;

    /**
     * 终端IP String(16)
     *
     * @var string spbill_create_ip 123.12.12.123
     * <summary>
     * APP和网页支付提交用户端ip，Native支付填调用微信支付API的机器IP。
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $spbill_create_ip;

    /**
     * 交易起始时间 String(14)
     *
     * @var string time_start 20091225091010
     * <summary>
     * 订单生成时间，格式为yyyyMMddHHmmss，如2009年12月25日9点10分10秒表示为200912
     * 25091010。其他详见时间规则
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $time_start;

    /**
     * 交易结束时间 String(14)
     *
     * @var string time_expire 20091227091010
     * <summary>
     * 订单失效时间，格式为yyyyMMddHHmmss，如2009年12月27日9点10分10秒表示为200912
     * 27091010。其他详见时间规则注意：最短失效时间间隔必须大于5分钟
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $time_expire;

    /**
     * 商品标记 String(32)
     *
     * @var string goods_tag WXG
     * <summary>
     * 商品标记，代金券或立减优惠功能的参数，说明详见代金券或立减优惠
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $goods_tag;

    /**
     * 通知地址 String(256)
     *
     * @var string notify_url http://www.weixin.qq.com/wxpay/pay.php
     * <summary>
     * 接收微信支付异步通知回调地址，通知url必须为直接可访问的url，不能携带参数。
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $notify_url;

    /**
     * 交易类型 String(16)
     *
     * @var string trade_type JSAPI
     * <summary>
     * 取值如下：JSAPI，NATIVE，APP，详细说明见参数规定
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $trade_type = "NATIVE";

    /**
     * 商品ID String(32)
     *
     * @var string product_id 12235413214070356458058
     * <summary>
     * trade_type=NATIVE，此参数必传。此id为二维码中包含的商品ID，商户自行定义。
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $product_id;

    /**
     * 指定支付方式 String(32)
     *
     * @var string limit_pay no_credit
     * <summary>
     * no_credit--指定不能使用信用卡支付
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $limit_pay;

    /**
     * 用户标识 String(128)
     *
     * @var string openid oUpF8uMuAJO_M2pxb1Q9zNjWeS6o
     * <summary>
     * trade_type=JSAPI，此参数必传，用户在商户appid下的唯一标识。openid如何获取，可参考
     * 【获取openid】。企业号请使用【企业号OAuth2.0接口】获取企业号内成员userid，再调用【企业号
     * userid转openid接口】进行转换
     * </summary>
     * @see https://pay.weixin.qq.com/wiki/doc/api/native.php?chapter=9_1
     */
    protected $openid;


    protected $native_mode = 1;


    protected $_either_groups = array();


    protected $_required_properties = array("appid", "mch_id", "nonce_str", "sign", "body", "out_trade_no", "total_fee", "spbill_create_ip", "notify_url", "trade_type", "product_id");


    protected $_optional_properties = array("device_info", "detail", "attach", "fee_type", "time_start", "time_expire", "goods_tag", "limit_pay", "openid");


    /**
     * @param int $nativeMode 
     * @return \WXPay\Api\Native\CreateOrder 
     */
    public function useMode($nativeMode = 1) {}

    /**
     * @return string 
     */
    public function generateLink() {}


    public function fire() {}

    /**
     * @return array 
     */
    public function _fire() {}

}
