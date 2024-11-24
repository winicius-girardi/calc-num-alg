#include <stdio.h>
#include <math.h>


#define ORDEM 3
#define TOLERANCIA 0.0001
#define MAX_ITERACOES 100


int main (){

    float MATRIZ_COEFICIENTES[ORDEM][ORDEM] = {{10,2,1},{1,5,1},{2,3,10}};
    float VETOR_INICIAL[ORDEM] = {0,0,0};
    float VETOR_CONSTANTES[ORDEM] = {7,-8,6};

    int iteracao=1;
    float erro; 
    
    
    do{
        erro = 0;

        for(int i=0; i<ORDEM; i++){
            float soma = 0;
            for(int j=0;j<ORDEM;j++){
                if(i!=j){
                    soma += MATRIZ_COEFICIENTES[i][j]*VETOR_INICIAL[j];
                }
            }
            float novo_valor = (VETOR_CONSTANTES[i] - soma)/MATRIZ_COEFICIENTES[i][i];
            if(fabs(novo_valor-VETOR_INICIAL[i])>erro){
                erro = fabs(novo_valor-VETOR_INICIAL[i]);
            }
            VETOR_INICIAL[i] = novo_valor;
        }
        
        printf("Iteracao %d\n",iteracao);
        for(int i=0; i<ORDEM; i++){
            printf("X%d = %.6f\n",i+1,VETOR_INICIAL[i]);
        }
        iteracao++;

    }while(erro>TOLERANCIA && iteracao<MAX_ITERACOES);
    




    if(erro<=TOLERANCIA){
        printf("Convergiu em %d iteracoes\n",iteracao-1);
    }
    else{
        printf("Nao convergiu\n");
    }


    return 0;
}