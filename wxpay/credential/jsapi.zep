namespace WXPay\Credential;

use WXPay\Credential;
use WXPay\Library\Util;

class Jsapi extends Credential {

    protected appId;

    protected signType = "MD5";

    protected package;

    protected nonceStr;

    protected timeStamp;

    protected paySign;

    public _required_properties = [
        "appId", "signType", "package", "nonceStr", "timeStamp"
    ];

    public _optional_properties = [];

    public static function make(string! prepay_id) -> <\WXPay\Credential\Jsapi>
    {
        var newObj;

        if empty prepay_id {
            throw new \Exception(__METHOD__ . ": Field {prepay_id} cannot be empty!");
        }
        let newObj = new self,
            newObj->package = "prepay_id=" . prepay_id;
        return newObj;
    }


    public function signWith(<\WXPay\Config> config) -> <\WXPay\Credential\Jsapi>
    {
        let this->appId = config->app_id,
            this->nonceStr = Util::genRandomString(24),
            this->timeStamp = time(),
            this->paySign = Util::make_sign(this, config->app_key);
        return this;
    }

    public function fire() -> array!
    {
        array responseStruct = [];
        var field, objVal;
        for field in this->_required_properties {
            if fetch objVal, this->{field} {
                let responseStruct[field] = objVal;
            }
        }
        let responseStruct["paySign"] = this->paySign;
        return responseStruct;
    }

}