#include <stdio.h>


//y' =f(t,y)
//y(0)=0.5
#define T_INICIAL 0.0
#define Y_INICIAL 0.5
#define H 0.2 
#define T_FINAL 1.9

double funcao(double x,double y);


int main(){

    double t = T_INICIAL;
    double y = Y_INICIAL;
    
    printf("Condicoes iniciais: t: %lf y: %lf\n",t,y);

    while(t < T_FINAL){
        y += H*funcao(t,y);
        t+=H;
        printf("t: %lf y: %lf\n",t,y);
    }



    return 0;
}

// Colocar no return a funcao a ser integrada. Se f(x) = x^2, return x*x...
double funcao(double t,double y){
    return y+t*t+1; // Colocar a funcao aqui exemplo:  dy/dt=y+t*t +1;
}