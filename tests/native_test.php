<?php
use \Wxpay\Api\Native\CreateOrder as Native1CreateOrder;
use \Wxpay\Api\Native\QueryOrder as Native1QueryOrder;
use \Wxpay\Api\Native\CloseOrder as Native1CloseOrder;

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
		'body'             => '测试商品',
		'detail'           => '当里个当，当里个当',
		'total_fee'        => '1',
		'notify_url'       => 'http://www.silversnet.com/wxpay/notify',
		'spbill_create_ip' => '127.0.0.1',
		'product_id' 	   => '12580',
);

try {

	$createOrderResult = Native1CreateOrder::make($payment)
			->signWith($config)
			->fire();
	echo "NATIVE接口：模式一：" . PHP_EOL;
	echo json_encode($createOrderResult, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT) . PHP_EOL;

	$createOrderResult = Native1CreateOrder::make($payment)
			->signWith($config)
			->useMode(2)
			->fire();
	echo "NATIVE接口：模式二：" . PHP_EOL;
	echo json_encode($createOrderResult, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT) . PHP_EOL;


	$queryOrderResult = Native1QueryOrder::make(array('out_trade_no' => $out_trade_no))
			->signWith($config)
			->fire();
	echo "订单查询返回：" . PHP_EOL;
	echo json_encode($queryOrderResult, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT) . PHP_EOL;

	$closeOrderResult = Native1CloseOrder::make(array('out_trade_no' => $out_trade_no))
			->signWith($config)
			->fire();
	echo "关闭订单返回：" . PHP_EOL;
	echo json_encode($closeOrderResult, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT) . PHP_EOL;

} catch(Exception $e) {

	echo $e->getMessage() . PHP_EOL;
}
