<?php
use \Wxpay\Api\App\CreateOrder as AppCreateOrder;
use \Wxpay\Api\App\QueryOrder as AppQueryOrder;
use \Wxpay\Api\App\CloseOrder as AppCloseOrder;

$config = new \Wxpay\Config(array(
    'app_id'      => 'wx9682fc7c2ab854ef',
    'mch_id'      => '1263567101',
    'app_key'     => 'bdc9a212a1d74b793eea977fd7f7b299',
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
);

try {

	$createOrderResult = AppCreateOrder::make($payment)
			->signWith($config)
			->fire();
	echo "统一下单接口返回：" . PHP_EOL;
	echo json_encode($createOrderResult, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT) . PHP_EOL;

	$queryOrderResult = AppQueryOrder::make(array('out_trade_no' => $out_trade_no))
			->signWith($config)
			->fire();
	echo "订单查询返回：" . PHP_EOL;
	echo json_encode($queryOrderResult, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT) . PHP_EOL;

	$closeOrderResult = AppCloseOrder::make(array('out_trade_no' => $out_trade_no))
			->signWith($config)
			->fire();
	echo "关闭订单返回：" . PHP_EOL;
	echo json_encode($closeOrderResult, JSON_UNESCAPED_UNICODE | JSON_PRETTY_PRINT) . PHP_EOL;

} catch(Exception $e) {

	echo $e->getMessage() . PHP_EOL;
}
