<?php
$n = 100000;
$fp = 2 / 10000;
$m = 1.44 * $n * log(1 / $fp, 2);
$k = log(2) * $m / $n;
echo '元素总量n: ', $n, '<br />';
echo '允许的错误率fp: ', $fp, '<br />';
echo 'bit数组长度m: ', $m, '<br />';
echo '哈希函数个数k: ', $k, '<br />';