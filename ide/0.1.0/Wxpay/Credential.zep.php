<?php

namespace WXPay;


abstract class Credential extends \WXPay\Option
{

    /**
     * @param mixed $config 
     */
    abstract public function signWith(\WXPay\Config $config);


    abstract public function fire();

}
