testEnding()
{
    int test = 1;
    char *p = (char *)&test;
    return (*p);
}

testEnding()
{
    union
    {
        int test;
        char byte;
    } ending;
    ending.test = 1;
    return ending.byte;
}
