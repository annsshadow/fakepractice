#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

void setColor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    //对设置之后的输出有效
    SetConsoleTextAttribute(hCon, color);
};

int main()
{
    //测试颜色啊~~
    for(int i = 0; i <= 255; i++)
    {
        setColor(i);
        printf("%d\n", i);
        system("pause");
    }
    return 0;
}

