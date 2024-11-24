#include <stdio.h>
#include <math.h>


#define LINHAS 3
#define COLUNAS 4


int main (){

        float matriz[LINHAS][COLUNAS]={{1,2,3,4},{2,3,4,5},{3,2,-5,6}},razao_pivo;

        for(int i=0;i<COLUNAS;i++){
            for(int k=i+1;k<LINHAS;k++){
                if(matriz[i][i]==0){
                    printf("Pivo é igual a zero!, Altere a ordem das linhas\n");
                    return 0;
                }
                razao_pivo=matriz[k][i]/matriz[i][i];
                
                for(int j=0;j<=COLUNAS;j++){
                    matriz[k][j]-=razao_pivo*matriz[i][j];
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


        for (int i=LINHAS-1;i>=0;i--){
        
            for(int k=i+1;k<LINHAS;k++){
                matriz[i][LINHAS]-=matriz[i][k]*matriz[k][LINHAS];
        
            }
            matriz[i][LINHAS]/=matriz[i][i];
        }
        printf("Solucoes do sistema:\n");
        for (int i = 0; i < LINHAS; i++) {
            printf("x%d = %0.2f\n", i+1, matriz[i][LINHAS]);
        }
        


    return 0;
}