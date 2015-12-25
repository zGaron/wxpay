<?php

namespace WXPay\Credential;


class Native1 extends \WXPay\Credential
{

    protected $appid;


    protected $mch_id;


    protected $time_stamp;


    protected $nonce_str;


    protected $product_id;


    protected $sign;


    /**
     * @param mixed $config 
     * @return \WXPay\Credential\Native1 
     */
    public function signWith(\WXPay\Config $config) {}

    /**
     * @return string 
     */
    public function fire() {}

}
