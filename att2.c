#include <stdio.h>


int main()
{
    int num1, num2, soma, sub, mult, res;

    float div;

    num1 = 20;
    num2 = 5;


    soma = num1 + num2;
    sub = num1 - num2;
    mult = num1 * num2;
    div = num1 / num2;
    res = num1 % num2;

    printf("\nAdicao: %d \n", soma);
    printf("\nSubtracao: %d \n", sub);
    printf("\nMultiplicacao: %d \n", mult);
    printf("\nDivisao: %.2f \n", div);
    printf("\nResto: %d \n", res);

}