<?php
use \Wxpay\Api\Jsapi\CreateOrder as JsapiCreateOrder;
use \Wxpay\Api\Jsapi\QueryOrder as JsapiQueryOrder;
use \Wxpay\Api\Jsapi\CloseOrder as JsapiCloseOrder;


$config = new \Wxpay\Config(array(
    'app_id'      => 'wx6b2462e0d8f3e2ca',
    'mch_id'      => '1255521701',
    'app_key'     => '150t1234567890123456789012345678',
    'rootca'      => dirname(__FILE__) . '/rootca.pem',
    'client_cert' => dirname(__FILE__) . '/apiclient_cert.pem',
    'client_key'  => dirname(__FILE__) . '/apiclient_key.pem',
));

$out_trade_no = $config->mch_id . time();
$payment = array(
		'out_trade_no'     => $out_trade_no,
		'body'             => '测试测试',
		'total_fee'        => '1',
		'notify_url'       => 'http://www.silversnet.com/wxpay/notify',
		'spbill_create_ip' => '127.0.0.1',
		'openid'		   => 'oxt3jsn0lXzUFPWSYQmOyNlWe7U8',
        // 'debug'            => true
);

try {

	$createOrderResult = JsapiCreateOrder::make($payment)
			->signWith($config)
			->fire();
	echo "统一下单接口返回：" . PHP_EOL;
	echo json_encode($createOrderResult, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT) . PHP_EOL;


	$queryOrderResult = JsapiQueryOrder::make(array('out_trade_no' => $out_trade_no))
			->signWith($config)
			->fire();
	echo "订单查询返回：" . PHP_EOL;
	echo json_encode($queryOrderResult, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT) . PHP_EOL;


	$closeOrderResult = JsapiCloseOrder::make(array('out_trade_no' => $out_trade_no))
			->signWith($config)
			->fire();
	echo "关闭订单返回：" . PHP_EOL;
	echo json_encode($closeOrderResult, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT) . PHP_EOL;

} catch(Exception $e) {

	echo $e->getMessage() . PHP_EOL;
}
