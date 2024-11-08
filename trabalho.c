#include <stdio.h>

//Função que verifica se já existe um valor de id dentro da matriz
int validacao (int validador, float alunos_matriz[][5], int quantidade){

    for (int j = 0; j < quantidade; j++) { // Passa por toda matriz 

            if (alunos_matriz[j][0] == validador){// Passa por toda matriz no indice 0 aonde escolhi para armazenar no id e verifica se já existe aquele id
            return 1; // Se exite retorna 1 = True  
         }
    }
    return 0; //Se não existe retorna 0 = false
    }

// Função que vai realizar a captação e armazenamento do id
int armazenarID (float alunos_matriz[][5], int quantidade_alunos){ 
    
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

// Função que vai captar e armazenar a nota dos alunos
float amazenarNotas(float alunos_matriz[][5], int quantidade_alunos){ 

    for(int i = 0; i < quantidade_alunos; i++){
        for (int j=1; j<4; j++)// Esse loop é iniciado em 1 pois o index 0 já destinei ao id 
        {   
            // Logica usada : os dois loops vão passar por toda matriz menos pelo 0 de cada aluno, sendo (indice 1 - nota 1, indice 2 - nota 2, indice 3 - nota 3)
            printf("Digite a nota %d do aluno ID \"%0.f\" : \n",  j,alunos_matriz[i][0] );//Rede pro usuário entrar com o valor da nota
            scanf("%f", &alunos_matriz[i][j]);//Armazana na matriz o valor
        }
        printf("\n--------------------------------------------------\n");
    }
    
    
    
    
    
}

// Função que vai realizar o calculo da média do aluno idividualmente
float mediaAluno(float alunos_matriz[][5], int quantidade_alunos){
    
    
    for(int i = 0; i < quantidade_alunos; i++){// Loop que passa aluno por aluno
        float media_aluno=0;// Declaro a varialvel media do aluno
        for (int j=1; j<4; j++) // Loop que passa nos 3 indices de nota
        {
            media_aluno +=  alunos_matriz[i][j];// Armazeno a média do aluno somando do indice 1 ao 3 
        }
        media_aluno = media_aluno/3; // Divide por 3 para fazer a média
        alunos_matriz[i][4] = media_aluno; // Armazena no indice 4 de cada aluno sua média (Indice 4 destinado para média do aluno)
        printf("A media do aluno com ID \"%0.f\" eh : %.2f\n", alunos_matriz[i][0], media_aluno);// Imprime na tela o id do aluno e sua média
    
    }

}

// Função que realiza o calculo da média da turma e retorna ela para ser usado no programa posteriormente
float mediaTurma(float alunos_matriz[][5], int quantidade_alunos){

    // Calculo utilizado para media da turma
    float media_final, media_turma;
    float media_geral = quantidade_alunos*3;// Declaração da média geral inciando com o numero de alunos x3 pois são 3 notas

        // Loop para passar pelas notas de todos os alunos
        for(int i = 0; i < quantidade_alunos; i++){
            for (int j=1; j<4; j++)
            {
                media_turma +=  alunos_matriz[i][j]; //Armazena em media_turma as notas de todos os alunos
            }
     }
    
    media_final = media_turma / media_geral;// Finaliza o calculo para a média final dividindo media_tuma/media_geral
    printf("A media da turma eh : %.2f\n", media_final);// Imprime na tela

    return media_final;// Retorna a media_final 
}

// Função que realiza a verificação da maior média da turma individual
float obterMaiorValor(float alunos_matriz[][5], int quantidade_alunos){

    int id;// Declara um id local para que possamos armazenar qual id de aluno foi o de maior nota
    float maior = 0.0;// Começa maior com 0.0 para que possa passar todos os valores dentro que seja maior que 0

    //Loop que passa por todos os alunos no indice 4 que está armazenado sua média
    for(int i = 0; i < quantidade_alunos; i++){
        if(alunos_matriz[i][4] > maior){// Verifica se a média do aluno é maior que o valor da variavel maior
            maior = alunos_matriz[i][4];// Se for maior a média desse aluno passa a ser o valor da variavel maior
            id = alunos_matriz[i][0];// Armazena o ID do aluno com a maior media dentro da variavel local id
        }
    }

    printf("O Aluno com a maior media foi com ID \"%d\" com a nota %.2f !", id, maior);// Imprime o id e o maior 
}

// Função que realiza a verificação da menor média da turma individual
float obterMenorValor(float alunos_matriz[][5], int quantidade_alunos){

  //int menor = INT_MAX;
  float menor = 1000000.0;// Declara menor com um numero muito alto para que assim qualquer valor comparado seja menor
  int id;//id local 

  //Loop que passa por todos os alunos no indice 4 que está armazenado sua média
  for(int i = 0; i < quantidade_alunos; i++){
        if(alunos_matriz[i][4] < menor){// Verifica se a média do aluno é menor que o valor da variavel maior
            menor = alunos_matriz[i][4];//Se for menor a média desse aluno passa a ser o valor da variavel menor
            id = alunos_matriz[i][0];// Armazena o ID do aluno com a menor media dentro da variavel local id
        }
    }
    printf("\nO Aluno com a menor media foi com ID \"%d\" com a nota %.2f !", id, menor);// Imprime o id e o menor

}

// Função que vai comparar a media da turma com a media de individual de cada aluno e dizer se passou ou está abaixo da média
float relatorioMedias(float alunos_matriz[][5],float media_final, int quantidade_alunos){
    
    //Loop que passa por cada aluno (indice 4 q está armazenado a média)
    for(int i = 0; i<quantidade_alunos; i++){
        
        //Verifica se a media do aluno está maior ou igual a média da turma, dizendo se ele passou ou não
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
   float media_turma; // Criação da variavel media_turma

   //Verifica se quantida_alunos digitado é de 1 a 30
   if(quantidade_alunos<30 && quantidade_alunos>0){
        armazenarID(alunos,quantidade_alunos); //Executa a função armazenarID()

        amazenarNotas(alunos,quantidade_alunos); // Executa a função armaznarNotas()

        mediaAluno(alunos,quantidade_alunos);  // Executa a função mediaAluno()

        media_turma = mediaTurma(alunos,quantidade_alunos); // Atribui a media_turma o valor que será retornado pela função mediaTurma() após sua execução 

        obterMaiorValor(alunos,quantidade_alunos); // Executa a função obterMaiorValor()

        obterMenorValor(alunos,quantidade_alunos); // Executa a função obterMenorValor()
        
        relatorioMedias(alunos,media_turma,quantidade_alunos); // Executa a função relatório Medias()
   }else{
    printf("Valor de alunos invalido");
   }


   /*for (int i = 0; i < quantidade_alunos; i++){
   printf("%0.f", alunos[i][0]);}*/

   

}