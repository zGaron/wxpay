<?php

use WXPay\Credential\App as AppCredential;
use WXPay\Credential\Jsapi as JsapiCredential;

$config = new \WXPay\Config(array(
    'app_id'      => 'wx9682fc7c2ab8xxxx',
    'mch_id'      => '126356xxxx',
    'app_key'     => 'bdc9a212a1d74b793eea977fd7f7xxxx',
    'client_cert' => dirname(__FILE__) . '/apiclient_cert.pem',
    'client_key'  => dirname(__FILE__) . '/apiclient_key.pem',
));

$createOrderResult = json_decode(file_get_contents(__DIR__ . "/json/aco.json"), JSON_OBJECT_AS_ARRAY);
$appCredential = AppCredential::make($createOrderResult['prepay_id'])
    ->signWith($config)
    ->fire();
echo "APP 支付凭证：" . PHP_EOL;
echo json_encode($appCredential, JSON_UNESCAPED_UNICODE|JSON_PRETTY_PRINT) . PHP_EOL;

$jsapiCredential = JsapiCredential::make($createOrderResult['prepay_id'])
    ->signWith($config)
    ->fire();
echo "JSAPI 支付凭证：" . PHP_EOL;
echo json_encode($jsapiCredential, JSON_UNESCAPED_UNICODE|JSON_PRETTY_PRINT) . PHP_EOL;


//var_dump($credential);