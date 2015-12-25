namespace WXPay\Api\Micropay;

use WXPay\Api;

class QueryOrder extends Api
{

    public api_url = "https://api.mch.weixin.qq.com/pay/orderquery";

    public is_secure_pay = false;

    /**
     * 公众账号ID String(32)
     *
     * @var string appid wxd678efh567hg6787
     *
     * <summary>
     * 微信分配的公众账号ID（企业号corpid即为此appId）
     * 
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_2
     */
    protected appid;
    /**
     * 商户号 String(32)
     *
     * @var string mch_id 1230000109
     *
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_2
     */
    protected mch_id;
    /**
     * 微信订单号 String(32)
     *
     * @var string transaction_id 1009660380201506130728806387
     *
     * <summary>
     * 微信的订单号，优先使用
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_2
     */
    protected transaction_id;
    /**
     * 商户订单号 String(32)
     *
     * @var string out_trade_no 20150806125346
     *
     * <summary>
     * 商户系统内部的订单号，当没提供transaction_id时需要传这个。
     * 
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_2
     */
    protected out_trade_no;
    /**
     * 随机字符串 String(32)
     *
     * @var string nonce_str C380BEC2BFD727A4B6845133519F3AD6
     *
     * <summary>
     * 随机字符串，不长于32位。推荐随机数生成算法
     * 
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_2
     */
    protected nonce_str;
    /**
     * 签名 String(32)
     *
     * @var string sign 5K8264ILTKCH16CQ2502SI8ZNMTM67VS
     *
     * <summary>
     * 签名，详见签名生成算法
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_2
     */
    protected sign;

    public _either_groups = [
        "transaction_id",
        "out_trade_no"
    ];

    public _required_properties = [
        "appid",
        "mch_id",
        "transaction_id",
        "out_trade_no",
        "nonce_str",
        "sign"
    ];

    public _optional_properties = [
    ];

}