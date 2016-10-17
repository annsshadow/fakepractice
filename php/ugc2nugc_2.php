<? php

public function ugc2nugc()
{
    $request = Request::instance ();

    if ($request->isAjax ())
    {
        /*ajax: receive params, exec client, log, return*/
        /*get params and not NULL*/
        $params = $request->param();
        $mytestname = (!empty($params['username'])) ? $params['username'] : 'NULL';
        $appid = (!empty($params['appid'])) ? $params['appid'] : 'NULL';
        $bucket = (!empty($params['bucket'])) ? $params['bucket'] : 'NULL';
        $reason = (!empty($params['reason'])) ? $params['reason'] : 'NULL';

        if($mytestname == 'NULL' || $appid == 'NULL' || $reason == 'NULL' || $bucket == 'NULL')
            return 'mytestname or appid or bucket or reason is NULL';

        /*init log*/
        $optime = date ( "Y-m-d H:i:s", time () );
        $comment = 'ugc2nugc';
        $flag = 'ugc2nugc';
        $log_data = [
                        'mytestname' => $mytestname,
                        'appid' => $appid,
                        'bucket' => $bucket,
                        'reason' => $reason,
                        'optime' => $optime,
                        'comment' => $comment
                    ];

        /*judge white_list_mytest name with flag code*/
        $mytest_exist = Db::table ( 'white_list_mytest' )->where (['mytestname'  => $mytestname, 'flag' => $flag])->select ();
        if (! empty ( $mytest_exist ))
        {
            $client = "/opt/www/mytestopt/client 14 10.180.39.41 /$appid/$bucket/ \"\" 2 \"\" \"\" \"\" 0 0 \"\" 0 0 \"\" 0 \"\" attrfile \"\" 1024";
            exec ( $client, $op_rev_1, $ex_rev_1);
            $change_result = $op_rev_1.'<br /> ex_rev_1:'.$ex_rev_1;

            Db::table ( 'mytest_tools_log' )->insertGetId ( $log_data );
        }
        else
        {
            /*have no permit, take wrong log, return wrong code*/
            $log_data ['reason'] = 'ugc2nugc:access denied';
            $insert_id = Db::table ( 'mytest_tools_log' )->insertGetId ( $log_data );
            $change_result = "[ERROR] $mytestname Have no permit to access ugc2nugc";
        }
        return $change_result;
    }
    else
    {
        /*sync: take user info and show the page*/
        $this->assign ( 'username', $this->userRow [0] ['name'] );
        return $this->fetch ();
    }
}
