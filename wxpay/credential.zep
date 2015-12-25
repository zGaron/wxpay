namespace WXPay;

abstract class Credential extends Option {

    abstract public function signWith(<\WXPay\Config> config);

    abstract public function fire();
}