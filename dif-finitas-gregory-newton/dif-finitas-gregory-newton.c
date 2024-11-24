#include <stdio.h>


#define QTDE_PONTOS 3
// Posicao que deseja avaliar o polinomio
#define POSICAO_AVALIADA 2.1


double fatorial(int n);



int main (){
    
    /*
    *   Pontos são os pares de coord_x e coord_y
    *   onde a posicao i em coord_x e coord_y é um ponto(coord_x[i],coord_y[i])
    *   -----------------------------------------------------------------------
    *   Intervalos entre os pontos em x tem que ser iguais
    */
    double coord_x[QTDE_PONTOS] = {1,2,3};
    double coord_y[QTDE_PONTOS] = {1,4,9};
    double TABELA[QTDE_PONTOS][QTDE_PONTOS];
    double h = coord_x[1]-coord_x[0];
    double p = (POSICAO_AVALIADA-coord_x[0])/h;
    double resultado = coord_y[0];


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

    double termo = 1;

    for(int i=1;i<QTDE_PONTOS;i++){
        termo *= (p-i+1)/i;
        resultado +=(termo/fatorial(i))*TABELA[0][i];
    }


    printf("valor de x= %f eh = %.6f\n",POSICAO_AVALIADA,resultado);


    return 0;
}



double fatorial(int n){
    if(n==0){
        return 1;
    }
    return n*fatorial(n-1);
}
