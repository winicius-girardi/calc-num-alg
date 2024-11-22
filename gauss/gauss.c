#include <stdio.h>
#include <math.h>


#define LINHAS 3
#define COLUNAS 3


int main (){

        float matriz[LINHAS][COLUNAS]={{1,2,3},{2,3,4},{3,2,-5}},pivo,razao_pivo;
        int linha_op=0,coluna_op=0;    

        for(int i=0;i<COLUNAS;i++){
            for(int k=0;k<LINHAS;k++){
                if(k==i)
                    continue;
                razao_pivo=matriz[k][i]/matriz[i][i];
                
                for(int j=0;j<=COLUNAS;j++){
                    matriz[k][j]-=razao_pivo*matriz[i][j];
                }
            }
        }


        for (int i=0;i<LINHAS;i++){
            for(int k=0;k<COLUNAS;k++){
                printf("%f\t",matriz[i][k]);
            }
            printf("\n");
        }


    return 0;
}
/*#include <stdio.h>

#define N 3  // Tamanho da matriz (número de equações)

// Função para realizar a eliminação de Gauss
void gaussElimination(float matrix[N][N+1]) {
    int i, j, k;
    float ratio;

    // Etapa de Eliminação para a matriz triangular superior
    for (i = 0; i < N; i++) {
        // Tornar o pivô igual a 1 e zerar os elementos abaixo dele
        for (j = i + 1; j < N; j++) {
            ratio = matrix[j][i] / matrix[i][i];
            
            // Subtrai a linha i multiplicada pelo ratio da linha j
            for (k = 0; k <= N; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }

    // Etapa de substituição reversa para obter as soluções
    float solution[N];
    solution[N-1] = matrix[N-1][N] / matrix[N-1][N-1];  // A última solução

    // Substituição reversa
    for (i = N - 2; i >= 0; i--) {
        solution[i] = matrix[i][N];  // Inicializa com o termo independente
        for (j = i + 1; j < N; j++) {
            solution[i] -= matrix[i][j] * solution[j];  // Subtrai os valores das variáveis já resolvidas
        }
        solution[i] /= matrix[i][i];  // Divide pelo coeficiente da variável
    }

    // Exibe a solução
    printf("Solução do sistema:\n");
    for (i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }
}

int main() {
    // Sistema de equações representado pela matriz aumentada
    // A última coluna da matriz é o vetor de constantes
    float matrix[N][N+1] = {
        {1, 2, 3, 9},
        {2, 3, 1, 8},
        {3, 1, 2, 7}
    };

    // Chama a função para resolver o sistema usando eliminação de Gauss
    gaussElimination(matrix);

    return 0;
}
*/