#include <stdio.h>

int validacao (int validador, float alunos_matriz[][5], int quantidade){

    for (int j = 0; j < quantidade; j++) {

            if (alunos_matriz[j][0] == validador) {
            return 1;  
         }
    }
    return 0;
    }

int armazenarID (float alunos_matriz[][5], int quantidade_alunos){ // Função que vai realizar a captação e armazenamento do id
    
    // Loop para que armazenara o ID
    for (int i = 0; i < quantidade_alunos;i++) { 
        int id; // Variável para armazenar o ID 
        printf("Adicione o Id para o aluno %d: ", i + 1); // Entrada do usuário com o ID
        scanf("%d", &id); // Armazena o ID


        if (!validacao(id, alunos_matriz,i)) { // Se o ID não existe (ID == 0), armazena o ID
        alunos_matriz[i][0] = id; // Armazena o ID na posição 0 na matriz alunos
        }
        else{
            printf("\nEsse Id ja existe, por favor escolha outro\n");
            i--; //Se o ID existe ele não permite que o primeiro for prossiga 
        }
}
}

float amazenarNotas(float alunos_matriz[][5], int quantidade_alunos){

    for(int i = 0; i < quantidade_alunos; i++){
        for (int j=1; j<4; j++)
        {
            printf("Digite a nota %d do aluno ID \"%0.f\" : \n",  j,alunos_matriz[i][0] );
            scanf("%f", &alunos_matriz[i][j]);
        }
        printf("\n--------------------------------------------------\n");
    }
    
    
    
    
    
}

float mediaAluno(float alunos_matriz[][5], int quantidade_alunos){
    
    
    for(int i = 0; i < quantidade_alunos; i++){
        float media_aluno=0;
        for (int j=1; j<4; j++)
        {
            media_aluno +=  alunos_matriz[i][j];
        }
    media_aluno = media_aluno/3;
    alunos_matriz[i][4] = media_aluno;
    printf("A media do aluno com ID \"%0.f\" eh : %.2f\n", alunos_matriz[i][0], media_aluno);
    
    }

}

float mediaTurma(float alunos_matriz[][5], int quantidade_alunos){

    float media_final;
    float media_turma;
    float media_geral = quantidade_alunos*3;


         for(int i = 0; i < quantidade_alunos; i++){
        

        for (int j=1; j<4; j++)
        {
            media_turma +=  alunos_matriz[i][j];
        }
     }
    
    media_final = media_turma / media_geral;
    printf("A media da turma eh : %.2f\n", media_final);

    return media_final;
}

float obterMaiorValor(float alunos_matriz[][5], int quantidade_alunos){

    int id;
    float maior = 0.0;

    for(int i = 0; i < quantidade_alunos; i++){
        if(alunos_matriz[i][4] > maior){
            maior = alunos_matriz[i][4];
            id = alunos_matriz[i][0];
        }
    }

    printf("O Aluno com a maior media foi com ID \"%d\" com a nota %.2f !", id, maior);
}

float obterMenorValor(float alunos_matriz[][5], int quantidade_alunos){

  //int menor = INT_MAX;
  float menor = 1000000.0;
  int id;
  for(int i = 0; i < quantidade_alunos; i++){
        if(alunos_matriz[i][4] < menor){
            menor = alunos_matriz[i][4];
            id = alunos_matriz[i][0];
        }
    }
    printf("\nO Aluno com a menor media foi com ID \"%d\" com a nota %.2f !", id, menor);  

}

float relatorioMedias(float alunos_matriz[][5],float media_final, int quantidade_alunos){
    
    for(int i = 0; i<quantidade_alunos; i++){
        
        if(alunos_matriz[i][4]>=media_final){
            printf("\nAluno com o ID %0.f Passou!", alunos_matriz[i][0]);
        }else{
            printf("\nAluno com o ID %0.f Esta abaixo da media geral e ficou com %.2f !", alunos_matriz[i][0], alunos_matriz[i][4]);
        }
        
    }
}

int main()
{

   int quantidade_alunos; //Variável para armezenar quantidade de alunos
   printf("Coloque a quantidade de alunos, sendo no maximo 30: "); //Entrada do usuário com a quantidade de alunos
   scanf("%d", &quantidade_alunos); //Armazenamento da quantidade de alunos na váriavel 
   float alunos[quantidade_alunos][5]; //Criação da váriavel alunos que vai armazenar a quantidade de alunos(que pode variar) e os ids e notas
   float media_turma;

   if(quantidade_alunos<30 && quantidade_alunos>=0){
        armazenarID(alunos,quantidade_alunos); //Chama a função armazenarID

        amazenarNotas(alunos,quantidade_alunos);

        mediaAluno(alunos,quantidade_alunos);

        media_turma = mediaTurma(alunos,quantidade_alunos);

        obterMaiorValor(alunos,quantidade_alunos);

        obterMenorValor(alunos,quantidade_alunos);
        
        relatorioMedias(alunos,media_turma,quantidade_alunos);
   }else{
    printf("Valor de alunos invalido");
   }


   /*for (int i = 0; i < quantidade_alunos; i++){
   printf("%0.f", alunos[i][0]);}*/

   

}