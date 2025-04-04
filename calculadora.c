#include <stdio.h>

int main() {
    float A, B, resultado;
    int opcao;

    printf("Escolha uma operacao:\n");
    printf("1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n");
    if (scanf("%d", &opcao) != 1) {
        printf("Erro: Digite um número válido!\n");
        return 1;
    }

    printf("Digite um valor: ");
    if (scanf("%f", &A) != 1) {
        printf("Erro: Digite um número válido!\n");
        return 1;
    }

    printf("Digite outro valor: ");
    if (scanf("%f", &B) != 1) {
        printf("Erro: Digite um número válido!\n");
        return 1;
    }

    switch (opcao) {
        case 1:
            resultado = A + B;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 2:
            resultado = A - B;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 3:
            resultado = A * B;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 4:
            if (B == 0) {
                printf("Erro: Divisao por zero nao permitida!\n");
            } else {
                resultado = A / B;
                printf("Resultado: %.2f\n", resultado);
            }
            break;
        default:
            printf("Opcao invalida! Tenta de novo, sua safada.\n");
            break;
    }

    return 0;
}

