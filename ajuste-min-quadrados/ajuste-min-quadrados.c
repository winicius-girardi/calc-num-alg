#include <stdio.h>


#define QTDE_PONTOS 3


int main (){
    
    /*
    *   Pontos são os pares de coord_x e coord_y
    *   onde a posicao i em coord_x e coord_y é um ponto(coord_x[i],coord_y[i])
    */
    double coord_x[QTDE_PONTOS] = {1,2,3};
    double coord_y[QTDE_PONTOS] = {1,4,9};
    
    double a,b;
    double somatorio_x, somatorio_y, somatorio_x2, somatorio_xy;
    for(int i = 0; i < QTDE_PONTOS; i++){
        somatorio_x += coord_x[i];
        somatorio_y += coord_y[i];
        somatorio_x2 += coord_x[i]*coord_x[i];
        somatorio_xy += coord_x[i]*coord_y[i];
    }

    a = (QTDE_PONTOS*somatorio_xy - somatorio_x*somatorio_y)/(QTDE_PONTOS*somatorio_x2 - somatorio_x*somatorio_x);
    b = (somatorio_y - a*somatorio_x)/QTDE_PONTOS;

    printf("y= %fx + %f\n",a,b);


    return 0;
}