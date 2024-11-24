#include <stdio.h>

// Colocar os limites em fornato double "numero.numero" aka 0.0 1.1 etc
#define LIMITE_INFERIOR 0.0
#define LIMITE_SUPERIOR 1.0
// DEVE SER PAR
#define INTERVALOS 10

double funcao(double x);


int main(){

    double h = (LIMITE_SUPERIOR - LIMITE_INFERIOR)/INTERVALOS;
    double soma = funcao(LIMITE_SUPERIOR) + funcao(LIMITE_INFERIOR);
    
    for(int i = 1; i < INTERVALOS; i++){
        if(i%2 == 0){
            soma += 2*funcao(LIMITE_INFERIOR + i*h);
        }else{
            soma += 4*funcao(LIMITE_INFERIOR + i*h);
        }
    }
    soma*=h/3;


    
    
    printf("Resultado: %lf\n",soma);

    return 0;
}

// Colocar no return a funcao a ser integrada. Se f(x) = x^2, return x*x...
double funcao(double x){
    return x*x+2;
}