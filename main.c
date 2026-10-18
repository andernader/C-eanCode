#include <stdio.h>

int main(void){
    int ean_code[14] = {0};
    int check_ean1 = 0, check_ean2 = 0, check_ean3 = 0;

    printf("Enter the 12 digits of the EAN code: ");

    for(int i = 1; i <= 12; i++)
        scanf("%1d", &ean_code[i]);

    for(int i = 2; i <= 12; i+=2)
        check_ean1 += ean_code[i];

    for(int i = 1; i <= 11; i+=2)
        check_ean2 += ean_code[i];

    check_ean3 = check_ean1 * 3 + check_ean2 - 1;
    check_ean3 %= 10;
    check_ean3 = 9 - check_ean3;

    ean_code[13] = check_ean3;

    printf("The check code is: %d\n", ean_code[13]);
    printf("The complete EAN code is: ");
    for(int i = 1; i <= 13; i++){
        printf("%d", ean_code[i]);
        if(i == 1 || i == 7)
            printf(" ");
    }
    printf("\n");

    return 0;
}
