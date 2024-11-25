#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double soma_potencias(double* x, int n, int grau) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += pow(x[i], grau);
    }
    return soma;
}

double soma_produtos(double* x, double* y, int n, int grau) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += pow(x[i], grau) * y[i];
    }
    return soma;
}

void resolver_sistema(double* matriz, double* resultados, int grau) {
    for (int i = 0; i < grau + 1; i++) {
        for (int j = i + 1; j < grau + 1; j++) {
            if (matriz[i * (grau + 1) + i] == 0) {
                printf("Erro: Divisão por zero!\n");
                exit(1);
            }
            double fator = matriz[j * (grau + 1) + i] / matriz[i * (grau + 1) + i];
            for (int k = 0; k < grau + 1; k++) {
                matriz[j * (grau + 1) + k] -= fator * matriz[i * (grau + 1) + k];
            }
            resultados[j] -= fator * resultados[i];
        }
    }

    for (int i = grau; i >= 0; i--) {
        for (int j = i + 1; j < grau + 1; j++) {
            resultados[i] -= matriz[i * (grau + 1) + j] * resultados[j];
        }
        resultados[i] /= matriz[i * (grau + 1) + i];
    }
}

int main() {
    //pares (x,y)
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {2, 4, 6, 8, 10};
    int n = sizeof(x) / sizeof(x[0]);
    int grau = 2;//grau do polinomio

    double* matriz = (double*)malloc((grau + 1) * (grau + 1) * sizeof(double));
    double* resultados = (double*)malloc((grau + 1) * sizeof(double));

    for (int i = 0; i <= grau; i++) {
        for (int j = 0; j <= grau; j++) {
            matriz[i * (grau + 1) + j] = soma_potencias(x, n, i + j);
        }
        resultados[i] = soma_produtos(x, y, n, i);
    }

    resolver_sistema(matriz, resultados, grau);

    printf("Coeficientes do polinômio:\n");
    for (int i = 0; i <= grau; i++) {
        printf("a%d = %lf\n", i, resultados[i]);
    }

    free(matriz);
    free(resultados);

    return 0;
}
