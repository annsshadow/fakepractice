#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# 
import time
import calendar
import datetime


# time模块中的三种时间形式
print("time stamp:", time.time())               # 时间戳
print("local time:", time.localtime())          # struct_time类型的本地时间
print("utc time:", time.gmtime())               # struct_time类型的utc时间

# time模块中，三种时间形式之间的转换
time_stamp = time.time()                        # 时间戳
local_time = time.localtime(time_stamp)         # 时间戳转struct_time类型的本地时间
utc_time = time.gmtime(time_stamp)              # 时间戳转struct_time类型的utc时间

time_stamp_1 = time.mktime(local_time)          # struct_time类型的本地时间转时间戳
time_stamp_2 = calendar.timegm(utc_time)        # struct_time类型的utc时间转时间戳
print(time_stamp, time_stamp_1, time_stamp_2)


# time模块中，三种时间形式和字符串之间的转换
print(time.ctime(time_stamp))           # 时间戳转字符串(本地时间字符串)

print(time.asctime(local_time))         # struct_time类型的本地时间转字符串
print(time.asctime(utc_time))           # struct_time类型的utc时间转字符串

print(time.strftime("%Y-%m-%d, %H:%M:%S, %w", local_time))      # struct_time类型的本地时间转字符串：自定义格式
print(time.strftime("%Y-%m-%d, %H:%M:%S, %w", utc_time))        # struct_time类型的utc时间转字符串：自定义格式

struct_time = time.strptime("2016-11-15, 15:32:12, 2", "%Y-%m-%d, %H:%M:%S, %w")       # 字符串转struct_time类型


# datetime模块中datetime类的用法
a_datetime_local = datetime.datetime.now()                      # 获取datetime.datetime类型的本地时间
a_datetime_utc = datetime.datetime.utcnow()                     # 获取datetime.datetime类型的utc时间

print(a_datetime_local.strftime("%Y-%m-%d, %H:%M:%S, %w"))      # datetime.datetime类型转字符串
print(a_datetime_utc.strftime("%Y-%m-%d, %H:%M:%S, %w"))        # datetime.datetime类型转字符串

a_datetime = datetime.datetime.strptime("2016-11-15, 15:32:12, 2", "%Y-%m-%d, %H:%M:%S, %w")    # 字符串转datetime.datetime格式


# datetime.datetime类和时间戳、struct_time类型之间的转换
time_stamp = a_datetime_local.timestamp()                           # datetime类型转时间戳
print(time_stamp)

a_datetime_local = datetime.datetime.fromtimestamp(time.time())     # 时间戳转datetime.datetime类型的本地时间
a_datetime_utc = datetime.datetime.utcfromtimestamp(time.time())    # 时间戳转datetime.datetime类型的utc时间
print(a_datetime_local, a_datetime_utc)

print(a_datetime_local.timetuple())                 # datetime类型转struct_time类型
print(a_datetime_utc.utctimetuple())                # datetime类型转struct_time类型

# 获取当前datetime:
now = datetime.now()
print('now =', now)
print('type(now) =', type(now))

# 用指定日期时间创建datetime:
dt = datetime(2015, 4, 19, 12, 20)
print('dt =', dt)

# 把datetime转换为timestamp:
print('datetime -> timestamp:', dt.timestamp())

# 把timestamp转换为datetime:
t = dt.timestamp()
print('timestamp -> datetime:', datetime.fromtimestamp(t))
print('timestamp -> datetime as UTC+0:', datetime.utcfromtimestamp(t))

# 从str读取datetime:
cday = datetime.strptime('2015-6-1 18:19:59', '%Y-%m-%d %H:%M:%S')
print('strptime:', cday)

# 把datetime格式化输出:
print('strftime:', cday.strftime('%a, %b %d %H:%M'))

# 对日期进行加减:
print('current datetime =', cday)
print('current + 10 hours =', cday + timedelta(hours=10))
print('current - 1 day =', cday - timedelta(days=1))
print('current + 2.5 days =', cday + timedelta(days=2, hours=12))

# 把时间从UTC+0时区转换为UTC+8:
utc_dt = datetime.utcnow().replace(tzinfo=timezone.utc)
utc8_dt = utc_dt.astimezone(timezone(timedelta(hours=8)))
print('UTC+0:00 now =', utc_dt)
print('UTC+8:00 now =', utc8_dt)