#include <stdio.h>


int main() {
    int prime, num, i, j, sum=0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if (num < 1) {
        printf("Nao possui numeros primos\n");
    } else {
        printf("Numeros primos entre 1 e %d:\n", num);
        for (i = 2; i <= num; i++) {
            prime = 1; 
            for (j = 2; j <= i / 2; j++) {
                if (i % j == 0) { 
                    prime = 0;
                    break;
                }
            }
            if (prime) {
                printf("%d ", i);
                sum=sum+i;
            }
        }
        printf("\n a soma dos numeros primos eh %d", sum);
    }
    /*
    int prime, num, i = 2, j, sum = 0;

    
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

   
    if (num < 1) {
        printf("Nao possui numeros primos\n");
    } else {
        printf("Numeros primos entre 1 e %d:\n", num);
       
        while (i <= num) {
            prime = 1;  
            j = 2; 
            while (j <= i / 2) {
                if (i % j == 0) { 
                    prime = 0;
                    break;
                }
                j++;
            }
            if (prime) {
                printf("%d ", i);
                sum=sum+i;
            }
            i++;
        }
        printf("\n A soma dos numeros eh %d", sum);
    }*/
}


    