#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int response;
    int attempts =3;
    int num;
    int min = 1;
    int max = 10;

    srand(time(NULL));
    num = rand() % (max - min + 1) + min;

    printf("Adivinhe o numero de 1 a 10\n");

        for(int i = 1; i <= attempts; i++){
            printf("Essa eh a sua %d tentativa\n", i);
            scanf("%d",&response);


        if(response == num){

            printf("Voce acertou!\n");
            exit(0);


        } else if(response < num){

            printf("O valor eh maior que o digitado!\n");


        } else if (response > num){

            printf("O valor eh menor que o digitado!\n");


        } 

        }

    printf("Suas tentativas acabaram\n\nO numero correto era %d", num);

}