cmake_minimum_required(VERSION 3.6)
project(fakepractice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    async_he.py
    async_wget.py
    coroutine.py
    createfile.py
    d.py
    dt.py
    dtest.py
    egg.c
    fork.py
    guitest.py
    math.py
    metaclass.py
    mtp.py
    oop.py
    orm.py
    poolp.py
    queue.py
    readfile.py
    README.md
    sig_num.c
    slice.py
    sort.py
    subp.py
    t_master.py
    t_worker.py
    test.cpp
    tlocal.py
    usecollection.py
    usedatetime.py)

add_executable(fakepractice ${SOURCE_FILES})