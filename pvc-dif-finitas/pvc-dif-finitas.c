#include <stdio.h>
#include <math.h>


#define A 0.0
#define B 1.0
#define ALPHA 1.0
#define BETA 0.0
#define N 10
#define H ((B-A)/N)

#define M_PI		3.14159265358979323846

double funcao(double x);


int main(){

    double x[N+1],y[N+1];

    for(int i=0;i<=N;i++){
        x[i]=A+i*H;
    }

    y[0]=ALPHA;
    y[N]=BETA;

    for(int i=1;i<N;i++){
        y[i]=(funcao(x[i])*H*H+y[i-1]+y[i+1])/2;
    }

    for(int i=0;i<=N;i++){
        printf("x[%d]=%f y[%d]=%f\n",i,x[i],i,y[i]);
    }



    return 0;
}

double funcao(double x){
    return -sin(M_PI*x);// f(X)=-sin(pi*x) 
}