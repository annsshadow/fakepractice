<? php
/**
* [mytest_forbidfile]
* Author：shadowwen
* Date：2016-09-08 13:20
*/
public function mytest_forbidfile()
{
    $request = Request::instance();

    if ($request->isAjax())
    {
        /*ajax: receive params, exec client, log, return*/
        /*get params and not NULL*/
        $params = $request->param();
        $mytestname = (!empty($params['username']))?$params['username']:'NULL';
        $origin_url = (!empty($params['url']))?$params['url']:'NULL';
        $reason = (!empty($params['reason']))?$params['reason']:'NULL';
        $option = (!empty($params['option']))?$params['option']:'NULL';

        if($mytestname == 'NULL' || $origin_url == 'NULL' || $reason == 'NULL' || $option == 'NULL')
            return 'mytestname or url or reason or option is NULL';

        //echo 'origin_url:',$origin_url,'<br />';
        /*get appid*/
        $appid_pattern = "/-[0-9]\d*/";
        preg_match($appid_pattern, $origin_url, $appid_before);
        //echo 'appid_before:',$appid_before[0],'<br />';
        $appid_after = str_replace("-", "/", $appid_before[0]);
        //echo 'appid_after:',$appid_after,'<br />';
        $appid = str_replace("/","",$appid_after);
        //echo 'appid:',$appid,'<br />';

        /*get bucket*/
        $bucket_pattern = "/\/\w+/";
        preg_match($bucket_pattern, $origin_url, $bucket_after);
        //echo 'bucket_after:',$bucket_after[0],'<br />';
        $bucket = str_replace("/","",$bucket_after[0]);
        //echo 'bucket:',$bucket,'<br />';

        /*init log*/
        $optime = date ( "Y-m-d h:i:s", time () );
        $comment = 'init_comm';
        $log_data = [
                        'mytestname' => $mytestname,
                        'appid' => $appid,
                        'bucket' => $bucket,
                        'reason' => $reason,
                        'optime' => $optime,
                        'comment' => $comment
                    ];

        /*judge white_list_mytest name with flag code*/
        switch ($option) {
          case '1':
              $flag='mytest3forbid';
              break;
          case '2':
              $flag='mytest4forbid';
              break;
          case '3':
              $flag='mytest4unforbid';
              break;
          default:
              return '[ERROR] wrong option value';
              break;
        }
        $mytest_exist = Db::table ( 'white_list_mytest' )->where (['mytestname'  => $mytestname,'flag' => $flag])->select ();

        if (! empty ( $mytest_exist ))
        {
            /*get file*/
            $file_pattern = "/com\/.*$/";
            preg_match($file_pattern, $origin_url, $file_before);
            //echo 'file_before:',$file_before[0],'<br />';
            $file_after = str_replace("com", "", $file_before[0]);
            //echo 'file_after:',$file_after,'<br />';
            $file_urldecode = urldecode($file_after);
            //echo 'file_urldecode:',$file_urldecode,'<br />';
            $file = str_replace("/","",$file_urldecode);
            //echo 'file:',$file,'<br />';

            /*get the whole mytest_forbidfile params string*/
            $query = $appid_after.$bucket_after[0].$file_urldecode;
            //echo 'query:',$query,'<br />';

            $op_rev_1 = 'op_rev_1_init';
            $ex_rev_1 = 'ex_rev_1_init';
            $op_rev_2 = 'op_rev_2_init';
            $ex_rev_2 = 'ex_rev_2_init';
            $change_result = 'change_result_init';
            switch ($option) {
              case '1':
                /*mytest-forbidfile*/
                $log_data['comment'] = 'mytest3_forbidfile';
                $client = "/opt/www/mytestopt/mytest_forbidfile $query";
                exec ( $client, $op_rev_1,$ex_rev_1);
                $change_result = $op_rev_1.'<br /> ex_rev_1:'.$ex_rev_1;
                break;
              case '2':
                /*mytest-forbidfile*/
                $log_data['comment'] = 'mytest4_forbidfile';
                $op_1 = "/opt/www/mytestopt/client_mytest4_forbidfile /opt/www/mytestopt/svr.conf om $query 1";
                exec ( $op_1, $op_rev_1,$ex_rev_1);
                $op_2 = "/opt/www/mytestopt/client_mytest4_forbidfile /opt/www/mytestopt/svr.conf oq $query";
                exec($op_2,$op_rev_2,$ex_rev_2);
                $change_result = $op_rev_1.'<br /> forbid value:'.$op_rev_2.'<br /> ex_rev_1:'.$ex_rev_1.'<br /> ex_rev_2:'.$ex_rev_2;
                break;
              case '3':
                /*mytest-forbidfile*/
                $log_data['comment'] = 'mytest4_unforbidfile';
                $op_1 = "/opt/www/mytestopt/client_mytest4_forbidfile /opt/www/mytestopt/svr.conf om $query 0";
                exec ( $op_1, $op_rev_1,$ex_rev_1);
                $op_2 = "/opt/www/mytestopt/client_mytest4_forbidfile /opt/www/mytestopt/svr.conf oq $query";
                exec($op_2,$op_rev_2,$ex_rev_2);
                $change_result = $op_rev_1.'<br /> forbid value:'.$op_rev_2.'<br /> ex_rev_1:'.$ex_rev_1.'<br /> ex_rev_2:'.$ex_rev_2;
                break;
              default:
                $log_data['comment'] = 'wrong option';
                $change_result = '[ERROR] wrong option value';
                break;
            }
            Db::table ( 'mytest_tools_log' )->insertGetId ( $log_data );
            return $change_result;
        }
        else
        {
            /*have no permit, take wrong log, return wrong code*/
            $log_data['reason'] = 'mytestforbid:access denied';
            Db::table ( 'mytest_tools_log' )->insertGetId ( $log_data );
            return "[ERROR] $mytestname Have no permit to access mytest_forbidfile";
        }
    }
    else
    {
        /*sync: take user info and show the page*/
        $this->assign('username', $this->userRow);
        return $this->fetch();
    }
}
