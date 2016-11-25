<?php

//定义请求接口，获取数据
function get_all_data($cgi_url)
{
    $curl = curl_init();

    curl_setopt($curl, CURLOPT_URL, $cgi_url);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($curl, CURLOPT_HEADER, 0);
    curl_setopt($curl, CURLOPT_TIMEOUT, 0);

    $output_json = curl_exec($curl);
    $output_arr = json_decode($output_json, true);
    return $output_arr;
}

$url_1 = 'http://172.27.208.75/cgi-bin/hy_cdn/hy_overview_v4.py?beg_date=';
$beg_date = '2016-10-26';
$url_2 = '&end_date=';
$end_date = '2016-10-26';
$url_3 = '&ns=&mfactor=';
$mfactor = '60';
$url_4 = '&handle=sum&key=';
$area = 'xxxx_cos4';
$url_5 = '_[';
$bucket = 'bucket-test';
$url_6 = '-';
$appid = '11111111111';
$url_7 = '.test';
$bucketarea = 'test-jm';
$url_8 = '.mytest.com_';
$fluxtype = 'cdn';
$url_9 = ']_total_flux_out';

$final_url = sprintf("http://172.27.208.75/cgi-bin/hy_cdn/hy_overview_v4.py?beg_date=%s&end_date=%s&ns=&mfactor=%s&handle=sum&key=%s_[%s-%s.test%s.mytest.com_%s]_total_flux_out", $beg_date, $end_date, $mfactor, $area, $bucket, $appid, $bucketarea, $fluxtype);

$pull_data = get_all_data($final_url);
foreach ($pull_data['data'][0]['data'] as $pkey => $prow) {
    $flux = ($prow[1] < 0) ? 0 : $prow[1];
    $second = (int)($prow[0] / 1000);
    $date = date('Y-m-d', $second);
    $insert_sql = "INSERT INTO cos4_flux(bucket,appid,second,date,fluxtype,area,flux) VALUES ('$bucket',$appid,$second,'$date','$fluxtype','$area',$flux) ON DUPLICATE KEY UPDATE flux=$flux";
    echo $insert_sql, '<br />';
}