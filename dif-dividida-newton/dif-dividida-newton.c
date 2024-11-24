#include <stdio.h>


#define QTDE_PONTOS 3
// Posicao que deseja avaliar o polinomio
#define POSICAO_AVALIADA 3.5


int main (){
    
    /*
    *   Pontos são os pares de coord_x e coord_y
    *   onde a posicao i em coord_x e coord_y é um ponto(coord_x[i],coord_y[i])
    */
    double coord_x[QTDE_PONTOS] = {1,2,3};
    double coord_y[QTDE_PONTOS] = {1,4,9};
    double TABELA[QTDE_PONTOS][QTDE_PONTOS];

    for(int i=0;i<QTDE_PONTOS;i++){
        TABELA[i][0] = coord_y[i];
    }

    for(int j=1;j<QTDE_PONTOS;j++){
        for(int i=0;i<QTDE_PONTOS-j;i++){
            TABELA[i][j] = (TABELA[i+1][j-1]-TABELA[i][j-1])/(coord_x[i+j]-coord_x[i]);
        }
    }

    printf("Tabela de diferencas divididas\n");
    for(int i=0;i<QTDE_PONTOS;i++){
        for(int j=0;j<QTDE_PONTOS-i;j++){
            printf("%.6f ",TABELA[i][j]);
        }
        printf("\n");
    }

    double resultado = TABELA[0][0];
    double termo = 1;

    for(int i=1;i<QTDE_PONTOS;i++){
        termo *= (POSICAO_AVALIADA-coord_x[i-1]);
        resultado += TABELA[0][i]*termo;
    }








    printf("valor de x= %f eh = %.6f\n",POSICAO_AVALIADA,resultado);


    return 0;
}