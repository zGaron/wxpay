<?php

namespace WXPay\Library;


class Util
{

    /**
     * @param mixed $apiObject 
     * @param string $key 
     * @return string 
     */
    public static function make_sign($apiObject, $key) {}

    /**
     * @param int $length 
     * @return string 
     */
    public static function genRandomString($length = 24) {}

    /**
     * 转换 xml 字符串为 数组格式.
     *
     * @param string $xml 
     * @param string $$xml 
     * @return array 
     */
    public static function convertXmlToArray($xml) {}

    /**
     * 将数组转换为 xml 格式(字符串)
     *
     * @param array $arr 
     * @param array $$arr 
     * @return string 
     */
    public static function convertArrayToXml($arr) {}

    /**
     * 获取客户端IP地址
     *
     * @return string 
     */
    public static function getRealIp() {}

    /**
     * 使用商户的cert,key调用 wechat-api.
     *
     * @throws SystemException
     * @param string $apiUri 
     * @param string $xml 
     * @param string $cert 
     * @param string $key 
     * @param string $rootca 
     * @param $key  
     * @return array 
     */
    public static function callWeChatApi($apiUri, $xml, $cert = null, $key = null, $rootca = null) {}

}
