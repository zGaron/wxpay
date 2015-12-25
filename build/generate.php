#!/usr/bin/env php
<?php

define("API_PATH", dirname(dirname(__FILE__)) . "/wxpay/api/");

require "simple_html_dom.php";

$base_uri = 'https://pay.weixin.qq.com/wiki/doc/api';

$map = array(
    'app'      => array(
        'createOrder' => '/app.php?chapter=9_1',
        'queryOrder'  => '/app.php?chapter=9_2&index=4',
        'closeOrder'  => '/app.php?chapter=9_3&index=5',

        'createRefund' => '/app.php?chapter=9_4&index=6',
        'queryRefund'  => '/app.php?chapter=9_5&index=7',
    ),
    'jsapi'    => array(
        'createOrder' => '/jsapi.php?chapter=9_1',
        'queryOrder'  => '/jsapi.php?chapter=9_2',
        'closeOrder'  => '/jsapi.php?chapter=9_3',

        'createRefund' => '/jsapi.php?chapter=9_4',
        'queryRefund'  => '/jsapi.php?chapter=9_5',
    ),
    'native'   => array(
        'createOrder' => '/native.php?chapter=9_1',
        'queryOrder'  => '/native.php?chapter=9_2',
        'closeOrder'  => '/native.php?chapter=9_3',

        'createRefund' => '/native.php?chapter=9_4',
        'queryRefund'  => '/native.php?chapter=9_5',

        'shorturl' => '/native.php?chapter=9_9',
    ),
    'micropay' => array(
        'createOrder' => '/micropay.php?chapter=9_10&index=1',
        'queryOrder'  => '/micropay.php?chapter=9_2',
        'closeOrder'  => '/micropay.php?chapter=9_11&index=3',

        'createRefund' => '/micropay.php?chapter=9_4',
        'queryRefund'  => '/micropay.php?chapter=9_5',

        'shortUrl'         => '/micropay.php?chapter=9_9&index=8',
        'autocodeToOpenId' => '/micropay.php?chapter=9_13&index=9',
    ),
    'mch_pay' => array(
        'createOrder' => '/mch_pay.php?chapter=14_2',
        'queryOrder'  => '/mch_pay.php?chapter=14_3',
    ),
);

$group = $argv[1];

if (!isset($map[$group])) {
    $groups = array_keys($map);
    echo "Supported trade types：\n";
    foreach ($groups as $g) {
        echo "\t{$g}\n";
    }
    exit;
}


$pages = $map[$group];

foreach ($pages as $class => $uri) {
    $docUrl = $base_uri . $uri;
    $class_name = ucfirst($class);
    $shd = get_shd($docUrl);
    $table = $shd->find("div[class=table-wrp]>table", 0);

    $api_url = $shd->find("div.content[0]>div.content-bd[0]>div.data-box", 1);
    if(!$api_url) {
        $api_url = $shd->find("div.content-bd[0]>p.mb10", 0)->plaintext;
    } else {
        $api_url = $api_url->find("p", 0)->plaintext;
    }
    $tmp = explode('https://', $api_url);
    $api_url = 'https://' . $tmp[1];

    if (stripos($api_url, 'secapi') > 0) {
        $isSecPay = TRUE;
    } else {
        $isSecPay = FALSE;
    }

    $trs = $table->find("tr");

    $columns = array();
    $either_groups = array();
    $tmp_either_groups = array();
    $required_properties = array();
    $optional_properties = array();

    foreach ($trs as $idx => $tr) {
        if ($idx == 0) continue;

        $colunms_name = trim($tr->find("td", 1)->plaintext);

        if(!$tr->find("td", 5)) {
            $columns[$colunms_name] = array(
                'name'    => $colunms_name,
                'desc'    => trim($tr->find("td", 0)->plaintext),
                'type'    => trim($tr->find("td", 2)->plaintext),
                'example' => trim($tr->find("td", 3)->plaintext),
                'detail'  => trim($tr->find("td", 4)->plaintext),
            );

            $notRequired = !$last_required;
            if ($notRequired && stripos($columns[$colunms_name]['detail'], "type=" . strtoupper($group) . "，此参数必传") <= 0) {
                $optional_properties[] = $colunms_name;
            } else {
                $required_properties[] = $colunms_name;
            }

            if(!in_array($last_columns_name, $tmp_either_groups)) {
                $tmp_either_groups[] = $last_columns_name;
            }
            $tmp_either_groups[] = $colunms_name;
        } else {
            if(count($tmp_either_groups) > 0) {
                $either_groups[] = $tmp_either_groups;
                $tmp_either_groups = [];
            }
            $columns[$colunms_name] = array(
                'name'    => $colunms_name,
                'desc'    => trim($tr->find("td", 0)->plaintext),
                'type'    => trim($tr->find("td", 3)->plaintext),
                'example' => trim($tr->find("td", 4)->plaintext),
                'detail'  => trim($tr->find("td", 5)->plaintext),
            );
            $notRequired = $tr->find("td", 2)->plaintext == '否';
            if(stripos($tr->find("td", 2)->plaintext, '(') > 0) {
                $notRequired = $tr->find("td", 3)->plaintext == '否';
            }

            if ($notRequired && stripos($columns[$colunms_name]['detail'], "type=" . strtoupper($group) . "，此参数必传") <= 0) {
                $optional_properties[] = $colunms_name;
            } else {
                $required_properties[] = $colunms_name;
            }
        }

        $last_columns_name = $colunms_name;
        $last_required = !$notRequired;
    }
    if(count($either_groups) == 0 && count($tmp_either_groups) > 0){
        $either_groups[] = $tmp_either_groups;
    }

    ob_start();
    require "./api.templ";
    $gen = ob_get_clean();
    if (!is_dir(API_PATH . $group)) {
        mkdir(API_PATH . $group, 0755);
    }

    $zepFile = API_PATH . $group . DIRECTORY_SEPARATOR . strtolower($class_name) . ".zep";
    file_put_contents($zepFile, $gen);
    echo "generate api file: {$zepFile}" . PHP_EOL;
}


function get_shd($url)
{
    $hash = md5($url);
    $try_file = "./.cache/{$hash}.tmp";
    if (!file_exists($try_file)) {
        $c = file_get_contents($url);
        file_put_contents($try_file, $c);
    }

    return file_get_html($try_file);
}