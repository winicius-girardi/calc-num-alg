#include <stdio.h>
#include <math.h>


#define LINHAS 3
#define COLUNAS 4


int main (){

    float matriz[LINHAS][COLUNAS]={{1,2,3,4},{2,3,4,5},{3,2,-5,6}},razao_pivo,pivo;


    for(int i=0;i<LINHAS;i++){

        if(matriz[i][i]==0){
            printf("Pivo é igual a zero!, Altere a ordem das linhas\n");
            return 0;
        }

        pivo=matriz[i][i];

        for(int j=0;j<COLUNAS;j++){
            matriz[i][j]/=pivo;
        }

        for(int j=0;j<LINHAS;j++){
            if(j!=i){
                razao_pivo=matriz[j][i];
                for(int k=0;k<COLUNAS;k++){
                    matriz[j][k]-=razao_pivo*matriz[i][k]; 
                }
            }
        }


    }



    printf("Matriz escalonada:\n");
    for (int i=0;i<LINHAS;i++){
        for(int k=0;k<COLUNAS;k++){
            printf("%f\t",matriz[i][k]);
        }
        printf("\n");
    }


    printf("Solucoes do sistema:\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("x%d = %0.2f\n", i+1, matriz[i][LINHAS]);
    }
    


    return 0;
}