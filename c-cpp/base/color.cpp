#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

void setColor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    //������֮��������Ч
    SetConsoleTextAttribute(hCon, color);
};

int main()
{
    //������ɫ��~~
    for(int i = 0; i <= 255; i++)
    {
        setColor(i);
        printf("%d\n", i);
        system("pause");
    }
    return 0;
}

