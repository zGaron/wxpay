namespace WXPay;

class Config extends Option {

    public app_id;

    public mch_id;

    public app_key;

    public rootca;

    public client_cert;

    public client_key;

    public function __construct(array! options = null)
    {
		var key, value;

		for key, value in options {
		    if this->offsetExists(key) {
			    this->offsetSet(key, value);
		    }
		}
    }
}