#include <stdio.h>

char change(char *code[][10], int nob, int num)
{

    int i, t, k;
    for(i = 1000, t = 0; t < nob; t++, i /= 10)
    {
        k = (num % i) / (i / 10);

        printf("%s", code[2 - t][k]);
    }
    printf("\n");
    return 0;

}

int main()
{
    char *code[][10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                        "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XCC",
                        "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
                       };

    int num, nob = 3;
    printf("Please input a Arabic number.\n");
    scanf("%d", &num);
    printf("The homologous Roman characters are:", num);
    change(code, nob, num);

    return 0;
}
