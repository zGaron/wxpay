namespace WXPay\Api\Micropay;

use WXPay\Api;

class AutocodeToOpenId extends Api
{

    public api_url = "https://api.mch.weixin.qq.com/tools/authcodetoopenid";

    public is_secure_pay = false;

    /**
     * 公众账号ID 是
     *
     * @var 是 appid String(32)
     *
     * <summary>
     * 微信分配的公众账号ID
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_13&index=9
     */
    protected appid;
    /**
     * 商户号 是
     *
     * @var 是 mch_id String(32)
     *
     * <summary>
     * 微信支付分配的商户号
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_13&index=9
     */
    protected mch_id;
    /**
     * 授权码 是
     *
     * @var 是 auth_code String(128)
     *
     * <summary>
     * 扫码支付授权码，设备读取用户微信中的条码或者二维码信息
     * 
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_13&index=9
     */
    protected auth_code;
    /**
     * 随机字符串 是
     *
     * @var 是 nonce_str String(32)
     *
     * <summary>
     * 随机字符串，不长于32位
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_13&index=9
     */
    protected nonce_str;
    /**
     * 签名 是
     *
     * @var 是 sign String(32)
     *
     * <summary>
     * 签名
     * </summary>
     *
     * @see https://pay.weixin.qq.com/wiki/doc/api/micropay.php?chapter=9_13&index=9
     */
    protected sign;

    public _either_groups = [
        "sign",
        "appid",
        "mch_id",
        "auth_code",
        "nonce_str",
        "sign"
    ];

    public _required_properties = [
        "appid",
        "mch_id",
        "auth_code",
        "nonce_str",
        "sign"
    ];

    public _optional_properties = [
    ];

}