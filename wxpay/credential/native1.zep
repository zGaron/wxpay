namespace WXPay\Credential;

use WXPay\Credential;

class Native1 extends Credential {

    protected appid;

    protected mch_id;

    protected time_stamp;

    protected nonce_str;

    protected product_id;

    protected sign;

    public function signWith(<\WXPay\Config> config) -> <\WXPay\Credential\Native1>
    {

    }

    public function fire() -> string!
    {

    }
}