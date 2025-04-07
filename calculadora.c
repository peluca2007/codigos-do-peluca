#include <stdio.h>
#include <string.h> // Para usar strcmp()

int main() {
    float A, B, resultado; // Variáveis para armazenar os números e o resultado
    int opcao;             // Variável para armazenar a opção escolhida
    char sair[10];         // Variável para armazenar se o usuário quer sair

    while (1) { // Loop principal que só termina se o usuário digitar "/exit"
        // Exibe as opções para o usuário
        printf("\nEscolha uma operacao:\n");
        printf("1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n");
        printf("Ou digite /exit para sair\n");

        // Lê a entrada como string para permitir comparar com "/exit"
        scanf("%s", sair);

        // Verifica se o usuário quer sair
        if (strcmp(sair, "/exit") == 0) {
            printf("Encerrando o programa. Até mais!\n");
            break;
        }

        // Converte a string para número (com sscanf) e valida a opção
        if (sscanf(sair, "%d", &opcao) != 1 || opcao < 1 || opcao > 4) {
            printf("\033[1;31mErro: Escolha uma opcao entre 1 e 4 ou digite /exit!\033[0m\n");
            continue;
        }

        // Solicita o primeiro número
        printf("Digite um valor: ");
        if (scanf("%f", &A) != 1) {
            printf("\033[1;31mErro: Digite um numero valido!\033[0m\n");
            continue;
        }

        // Solicita o segundo número
        printf("Digite outro valor: ");
        if (scanf("%f", &B) != 1) {
            printf("\033[1;31mErro: Digite um numero valido!\033[0m\n");
            continue;
        }

        // Realiza a operação com base na opção escolhida
        switch (opcao) {
            case 1: // Soma
                resultado = A + B;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 2: // Subtração
                resultado = A - B;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 3: // Multiplicação
                resultado = A * B;
                printf("Resultado: %.2f\n", resultado);
                break;
            case 4: // Divisão
                if (B == 0) {
                    printf("\033[1;31mErro: Divisao por zero nao permitida!\033[0m\n");
                    continue;
                } else {
                    resultado = A / B;
                    printf("Resultado: %.2f\n", resultado);
                }
                break;
        }
        // Após mostrar o resultado, o loop recomeça automaticamente
    }

    return 0;
}
