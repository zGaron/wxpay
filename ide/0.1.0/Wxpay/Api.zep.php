<?php

namespace WXPay;


class Api extends \WXPay\Option
{

    protected $api_url = "";


    protected $is_secure_pay = false;


    protected $_required_properties = array();


    protected $_optional_properties = array();


    protected $_either_groups = array();


    protected $_config;


    protected $_make_exclude_properties = array("appid", "mch_id", "trade_type", "sign");


    protected $sign;


    protected $debug = false;


    /**
     * @param array $config 
     * @return \WXPay\Api 
     */
    public static function make($config) {}

    /**
     * @param mixed $config 
     * @return \WXPay\Api 
     */
    public function signWith(\WXPay\Config $config = null) {}

    /**
     * @param bool $debug 
     * @return \WXPay\Api 
     */
    public function setDebug($debug = true) {}

    /**
     * @return string 
     */
    public function dump() {}

    /**
     * @return array 
     */
    public function fire() {}

}
