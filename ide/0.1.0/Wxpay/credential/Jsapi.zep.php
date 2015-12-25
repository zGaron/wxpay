<?php

namespace WXPay\Credential;


class Jsapi extends \WXPay\Credential
{

    protected $appId;


    protected $signType = "MD5";


    protected $package;


    protected $nonceStr;


    protected $timeStamp;


    protected $paySign;


    protected $_required_properties = array("appId", "signType", "package", "nonceStr", "timeStamp");


    protected $_optional_properties = array();


    /**
     * @param string $prepay_id 
     * @return \WXPay\Credential\Jsapi 
     */
    public static function make($prepay_id) {}

    /**
     * @param mixed $config 
     * @return \WXPay\Credential\Jsapi 
     */
    public function signWith(\WXPay\Config $config) {}

    /**
     * @return array 
     */
    public function fire() {}

}
