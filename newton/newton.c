#include <stdio.h>
#include <math.h>

#define X_INICIAL 1
#define ERRO  0.01

float calcFunction(float x);
float calc_Dev_Function(float x);
float iteracao(float a);

int main (){
    
    float x_proximo,x_atual;
    x_atual=X_INICIAL;
    x_proximo= iteracao(x_atual);
    
    while (fabs(calcFunction(x_proximo))>ERRO){
        x_atual=x_proximo;
        x_proximo=iteracao(x_atual);
    }
    printf("valor para x foi x= %f e f(%f)=%f\n",x_proximo,x_proximo,calcFunction(x_proximo));

    return 0;
}

float calcFunction(float x){   
    return exp(x)+2*x;
}
float calc_Dev_Function(float x){
    return exp(x) +2;
}


float iteracao(float x_atual){
    float f_atual, f_derivada_atual;
    f_atual=calcFunction(x_atual);
    f_derivada_atual=calc_Dev_Function(x_atual);

    return x_atual - (f_atual/f_derivada_atual);   
}