#include <stdio.h>
#include <math.h>

#define X0 1
#define X1 -1
#define ERRO  0.01

float calcFunction(float x);
float iteracao(float a,float b);

int main (){
    
    float x_prox,x_atual,x_anterior;
    x_atual=X1;
    x_anterior=X0;
    
    x_prox= iteracao(x_atual,x_anterior);
    
    while (fabs(calcFunction(x_prox))>ERRO){
        x_anterior=x_atual;
        x_atual=x_prox;
        x_prox= iteracao(x_atual,x_anterior);
    
    }
    printf("valor para x foi x= %f e f(%f)=%f\n",x_prox,x_prox,calcFunction(x_prox));

    return 0;
}

float calcFunction(float x){   
    return exp(x)+2*x;
} 

float iteracao(float x_atual, float x_anterior){
    float f_atual, f_anterior;
    f_atual=calcFunction(x_atual);
    f_anterior=calcFunction(x_anterior);

    return x_atual - ((f_atual*(x_atual-x_anterior))/(f_atual-f_anterior));   
}