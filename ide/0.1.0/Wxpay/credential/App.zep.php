<?php

namespace WXPay\Credential;


class App extends \WXPay\Credential
{

    protected $appid;


    protected $partnerid;


    protected $prepayid;


    protected $package = "Sign=WXPay";


    protected $noncestr;


    protected $timestamp;


    protected $sign;


    protected $_required_properties = array("appid", "partnerid", "prepayid", "package", "noncestr", "timestamp");


    protected $_optional_properties = array();


    /**
     * @param string $prepay_id 
     * @return \WXPay\Credential\App 
     */
    public static function make($prepay_id) {}

    /**
     * @param mixed $config 
     * @return \WXPay\Credential\App 
     */
    public function signWith(\WXPay\Config $config) {}

    /**
     * @return array 
     */
    public function fire() {}

}
