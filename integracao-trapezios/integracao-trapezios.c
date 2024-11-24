#include <stdio.h>

// Colocar os limites em fornato double "numero.numero" aka 0.0 1.1 etc
#define LIMITE_INFERIOR 0.0
#define LIMITE_SUPERIOR 1.0
#define QTDE_INTERVALOS 10

double funcao(double x);


int main(){

    double h = (LIMITE_SUPERIOR - LIMITE_INFERIOR)/QTDE_INTERVALOS;
    h=(LIMITE_SUPERIOR - LIMITE_INFERIOR)/QTDE_INTERVALOS;
    double soma= 0.5*(funcao(LIMITE_SUPERIOR) + funcao(LIMITE_SUPERIOR));
    for(int i = 1; i < QTDE_INTERVALOS; i++){
        soma += funcao(LIMITE_INFERIOR + i*h);
    }
    soma*=h;    
    printf("Resultado: %lf\n",soma);

    return 0;
}

// Colocar no return a funcao a ser integrada. Se f(x) = x^2, return x*x...
double funcao(double x){
    return x*x;
}