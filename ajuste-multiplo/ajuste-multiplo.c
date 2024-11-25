#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define M 5

void transpor_matriz(double *a, double *resultado, int linhas, int colunas);
void multiplicar_matrizes(double *a, double *b, double *resultado, int linhas_a, int colunas_a, int colunas_b);
int eliminacao_gauss(double *a, double *b, double *x, int n);

int main() {
    double X[M][N] = {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5},
        {4, 5, 6},
        {5, 6, 7}
    };

    double Y[M] = {5, 7, 9, 11, 13};

    double Xt[N][M], XtX[N][N], XtY[N];
    double coeficientes[N];

    transpor_matriz((double *)X, (double *)Xt, M, N);
    multiplicar_matrizes((double *)Xt, (double *)X, (double *)XtX, N, M, N);
    multiplicar_matrizes((double *)Xt, (double *)Y, (double *)XtY, N, M, 1);
    eliminacao_gauss((double *)XtX, XtY, coeficientes, N);

    printf("Coeficientes do ajuste linear múltiplo:\n");
    for (int i = 0; i < N; i++) {
        printf("a[%d] = %lf\n", i, coeficientes[i]);
    }

    return 0;
}
void multiplicar_matrizes(double *a, double *b, double *resultado, int linhas_a, int colunas_a, int colunas_b) {
    for (int i = 0; i < linhas_a; i++) {
        for (int j = 0; j < colunas_b; j++) {
            resultado[i * colunas_b + j] = 0;
            for (int k = 0; k < colunas_a; k++) {
                resultado[i * colunas_b + j] += a[i * colunas_a + k] * b[k * colunas_b + j];
            }
        }
    }
}

void transpor_matriz(double *a, double *resultado, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[j * linhas + i] = a[i * colunas + j];
        }
    }
}

int eliminacao_gauss(double *a, double *b, double *x, int n) {
    for (int i = 0; i < n; i++) {
        int linha_maxima = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(a[j * n + i]) > fabs(a[linha_maxima * n + i])) {
                linha_maxima = j;
            }
        }

        if (i != linha_maxima) {
            for (int j = 0; j < n; j++) {
                double temp = a[i * n + j];
                a[i * n + j] = a[linha_maxima * n + j];
                a[linha_maxima * n + j] = temp;
            }
            double temp = b[i];
            b[i] = b[linha_maxima];
            b[linha_maxima] = temp;
        }

        for (int j = i + 1; j < n; j++) {
            double fator = a[j * n + i] / a[i * n + i];
            for (int k = i; k < n; k++) {
                a[j * n + k] -= fator * a[i * n + k];
            }
            b[j] -= fator * b[i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i * n + j] * x[j];
        }
        x[i] /= a[i * n + i];
    }

    return 0;
}
