#include <stdio.h>
#include <math.h>

#define A 1
#define B -1
#define ERRO  0.01

float calcFunction(float x);
void iteracao(float f_a, float f_b, float a, float b);

int main (){
    float f_a, f_b;
    f_a=calcFunction(A);
    f_b=calcFunction(B);
    if(f_a*f_b<0)
        iteracao(f_a,f_b,A,B);
    else
        printf("intervalo A e B informados pode não possuir raiz\n");


    return 0;
}

float calcFunction(float x){   
    return exp(x)+2*x;
}

void iteracao(float f_a,float f_b,float a,float b){
    float c,f_c;
    c= (a+b)/2;
    f_c=calcFunction(c); 
    if(sqrt(f_c*f_c)<ERRO){
        printf("raiz é aproximadamente x= %f onde f(%f)=%f\n",c,c,f_c);
        return;}
    if (f_c<0){
        if(f_a<0)
            iteracao(f_c,f_b,c,b);
        else
            iteracao(f_a,f_c,a,c);
    }
    else{
        if(f_a>0)
            iteracao(f_c,f_b,c,b);
        else
            iteracao(f_a,f_c,a,c);
    }
    


}