#include <stdio.h>


#define QTDE_PONTOS 3
// Posicao que deseja avaliar o polinomio
#define POSICAO_AVALIADA 2.1


int main (){
    
    /*
    *   Pontos são os pares de coord_x e coord_y
    *   onde a posicao i em coord_x e coord_y é um ponto(coord_x[i],coord_y[i])
    */
    
    double coord_x[QTDE_PONTOS] = {1,2,3};
    double coord_y[QTDE_PONTOS] = {1,4,9};


    float resultado = 0;

    for(int k=0;k<QTDE_PONTOS;k++){
        double termo=coord_y[k];

        for(int i=0;i<QTDE_PONTOS;i++){
            if(i!=k){
                termo *= (POSICAO_AVALIADA-coord_x[i])/(coord_x[k]-coord_x[i]);
            }
        }
        resultado += termo;
        
    }
    printf("valor de x= %f eh = %.6f\n",POSICAO_AVALIADA,resultado);


    return 0;
}