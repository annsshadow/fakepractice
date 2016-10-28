#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main()
{
    unsigned short int k;

    while(1)
    {
        _sleep(100);

        if(_kbhit())
        {
            k = _getch();

            if(0 == k)
                k = _getch() << 8;

            _cprintf("key:0x%04x pressed\r\n", k);
        }
    }
    system("pause");
    return 0;
}
