namespace WXPay\Credential;

use WXPay\Credential;
use WXPay\Library\Util;

class App extends Credential {

    protected appid;

    protected partnerid;

    protected prepayid;

    protected package = "Sign=WXPay";

    protected noncestr;

    protected timestamp;

    protected sign;

    public _required_properties = [
        "appid", "partnerid", "prepayid", "package", "noncestr", "timestamp"
    ];

    public _optional_properties = [];

    public static function make(string! prepay_id) -> <\WXPay\Credential\App>
    {
        var newObj;

        if empty prepay_id {
            throw new \Exception(__METHOD__ . ": Field {prepay_id} cannot be empty!");
        }
        let newObj = new self,
            newObj->prepayid = prepay_id;
        return newObj;
    }


    public function signWith(<\WXPay\Config> config) -> <\WXPay\Credential\App>
    {
        let this->appid = config->app_id,
            this->partnerid = config->mch_id,
            this->noncestr = Util::genRandomString(24),
            this->timestamp = time(),
            this->sign = Util::make_sign(this, config->app_key);
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
        let responseStruct["sign"] = this->sign;
        return responseStruct;
    }

}