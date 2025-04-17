#include <stdio.h>                // Biblioteca para entrada e saída
#include <string.h>               // Biblioteca para manipulação de strings
#include <locale.h>               // Biblioteca para suporte a localização (acentos)
#include <ctype.h>                // Biblioteca para funções de caractere, como tolower()
#include <unistd.h>              // Biblioteca para usar sleep() e usleep()

// Códigos de cor ANSI para deixar o texto colorido no terminal
#define RESET     "\033[0m"
#define VERMELHO  "\033[1;31m"
#define VERDE     "\033[1;32m"
#define AZUL      "\033[1;34m"
#define ROSA      "\033[1;95m"
#define tam 50                    // Tamanho máximo do nome

int main() {
    setlocale(LC_ALL, ".UTF-8"); // Habilita suporte a caracteres especiais

    int menu, amor, amor2, amor3;               // Variáveis de escolha do menu e decisões do jogo
    char nome[tam];                             // Armazena o nome digitado pelo jogador
    char nome_lower[tam];                       // Armazena o nome convertido para letras minúsculas
    int finais = 0;                             // Contador de finais únicos vistos
    char jogar_novamente;                       // Variável para decidir se o jogador quer jogar novamente
    int finais_vistos[8] = {0};                 // Array para rastrear quais finais já foram vistos

    while (1) {                                  // Loop principal do jogo
        printf("\n1-Play\n");                    // Opção de jogar
        printf("2-Exit\n");                      // Opção de sair
        scanf("%d", &menu);                      // Leitura da opção
        while (getchar() != '\n');              // Limpa o buffer do teclado

        switch(menu){
        case 1:
            do {
                printf("Esse é um mini jogo para a pessoa que eu mais");
                printf(VERMELHO " AMO NO MUNDO 🥰\n" RESET);          // Mensagem com cor
                printf("Para começar, digite seu nome:\n");

                fgets(nome, sizeof(nome), stdin);                     // Lê o nome do jogador
                nome[strcspn(nome, "\n")] = 0;                       // Remove o '\n' final

                strcpy(nome_lower, nome);                             // Copia o nome original para outra variável
                for (int i = 0; nome_lower[i]; i++) {
                    nome_lower[i] = tolower(nome_lower[i]);          // Converte para minúsculo
                }

                if (                                                   // Verifica se o nome é da Bea
                    strcmp(nome_lower, "bea") == 0 ||
                    strcmp(nome_lower, "beatriz") == 0 ||
                    strcmp(nome_lower, "beatriz esmy") == 0
                ) {
                    printf(ROSA "\n╔════════════════════════════════════╗\n");
                    printf("    💖 VOCÊ DESBLOQUEOU O FINAL 💖    \n");
                    printf("         🌸🌸 VERDADEIRO 🌸🌸          \n");
                    printf("╚════════════════════════════════════╝\n\n" RESET);
                    printf(ROSA "Pedro te dá um abraço apertado e diz: 'Eu sabia que era você!'\n");
                    printf("Vocês vivem felizes para sempre...\n" RESET);
                    usleep(1000000);

                    if (!finais_vistos[6]) {
                        finais_vistos[6] = 1;
                        finais++;
                    }
                } else if (                                           // Verifica se é o Pedro (nome proibido)
                    strcmp(nome_lower, "pedro") == 0 ||
                    strcmp(nome_lower, "pedro lucas") == 0
                ) {
                    printf(VERMELHO "\n>>> ERRO: CONFLITO DE IDENTIDADE\n" RESET);
                    sleep(1);
                    printf(VERMELHO ">>> PEDRO DETECTADO...\n" RESET);
                    sleep(1);
                    printf(VERMELHO "\nSÓ PODE EXISTIR UM PEDROOOO!!! 🔥👹🔥\n" RESET);
                    sleep(1);
                    for (int i = 0; i < 5; i++) {
                        printf("\033[5;31m#####@!#@%%!@$$%%¨&***###~~~#####\033[0m\n");
                        usleep(150000);                               // Pausa animada
                    }
                    printf(VERMELHO "\n>>>>> AUTO-EXCLUSÃO INICIADA...\n" RESET);
                    sleep(1);
                    printf("Adeus, impostor...\n");
                    usleep(500000);
                    if (!finais_vistos[7]) {
                        finais_vistos[7] = 1;
                        finais++;
                    }
                } else {
                    printf(AZUL "Prazer, %s!\n" RESET, nome);            // Diálogo genérico
                    printf("Você gostaria de sair comigo?\n");

                    printf(VERDE "1 - Sim seu lindo 💅\n" RESET);       // Opções de resposta
                    printf(VERDE "2 - Sim 😳\n" RESET);
                    printf(VERMELHO "3 - Não 🙄\n" RESET);

                    char entrada[10];
                    fgets(entrada, sizeof(entrada), stdin);           // Lê resposta
                    if (sscanf(entrada, "%d", &amor) != 1) amor = -1;

                    switch (amor) {
                        case 1:
                            printf("Você está se achando muito!\n");
                            printf(ROSA "1 - O amor da sua vida 💘\n" RESET);
                            printf(ROSA "2 - A Bea 😇\n" RESET);
                            fgets(entrada, sizeof(entrada), stdin);
                            if (sscanf(entrada, "%d", &amor2) != 1) amor2 = -1;

                            switch (amor2) {
                                case 1:
                                    printf(VERMELHO "Não gostei de você 😤 (Pedro pega uma AK-47 e mata você)\nFim brutal 💀\n" RESET);
                                    usleep(1000000);
                                    if (!finais_vistos[0]) { finais_vistos[0] = 1; finais++; }
                                    break;
                                case 2:
                                    printf("Me diga o nome do gatinho dela 🐱\n");
                                    printf(AZUL "1 - Lucas 🐾\n" RESET);
                                    printf(AZUL "2 - Fofo 💍\n" RESET);
                                    fgets(entrada, sizeof(entrada), stdin);
                                    if (sscanf(entrada, "%d", &amor3) != 1) amor3 = -1;

                                    if (amor3 == 1) {
                                        printf(VERMELHO "Você está certo, mas não gostei da resposta 😾 (Pedro pega uma bazuca de gatinhos e mata você)\nFim tonto 🤪\n" RESET);
                                        usleep(1000000);
                                        if (!finais_vistos[1]) { finais_vistos[1] = 1; finais++; }
                                    } else if (amor3 == 2) {
                                        printf(VERDE "\nÉ você mesmo!! 😍\nFinal feliz 🌈\n" RESET);
                                        printf(VERDE "\nVocês casam, têm 2 filhos, 1 cachorro, 2 gatos e uma cacatua\n" RESET);
                                        usleep(1000000);
                                        if (!finais_vistos[2]) { finais_vistos[2] = 1; finais++; }
                                    } else {
                                        printf(VERMELHO "Final secreto: resposta estranha 🔀\n" RESET);
                                        usleep(1000000);
                                        if (!finais_vistos[3]) { finais_vistos[3] = 1; finais++; }
                                    }
                                    break;
                                default:
                                    printf(VERMELHO "Final secreto: sou burro 🙈\n" RESET);
                                    usleep(1000000);
                                    if (!finais_vistos[3]) { finais_vistos[3] = 1; finais++; }
                                    break;
                            }
                            break;
                        case 2:
                            printf(VERMELHO "Você é bem sem graça, né %s (Pedro pega uma espada samurai e corta você ao meio)\nFinal sem graça 💤\n" RESET, nome);
                            usleep(1000000);
                            if (!finais_vistos[4]) { finais_vistos[4] = 1; finais++; }
                            break;
                        case 3:
                            printf(AZUL "Nossa, vai tomar no %s (Pedro vira as costas e vai embora)\nFinal pacifista ☮️\n" RESET, nome);
                            usleep(1000000);
                            if (!finais_vistos[5]) { finais_vistos[5] = 1; finais++; }
                            break;
                        default:
                            printf(VERMELHO "Final secreto: sou burro 🤔\n" RESET);
                            usleep(1000000);
                            if (!finais_vistos[3]) { finais_vistos[3] = 1; finais++; }
                            break;
                    }
                }

                printf(AZUL "\nVocê concluiu %d/8 finais únicos! 🏆\n" RESET, finais);
                printf("Deseja jogar novamente? (s/n): ");
                scanf(" %c", &jogar_novamente);                         // Lê decisão de jogar de novo
                getchar();                                             // Limpa o '\n' final

                printf("\n\n");

            } while (jogar_novamente == 's' || jogar_novamente == 'S');

            if (finais == 8) {                                         // Final secreto se todos os finais foram vistos
                printf(ROSA "\nSe você desbloqueou TODOS os finais, você com certeza é a BEAAAA! 😍\n");
                printf("Final secreto desbloqueado... 💖\n\n");
                usleep(1000000);
                // Coração em ASCII
                printf(ROSA "      *****       *****\n");
                printf("   *********** ***********\n");
                printf("  ***************************\n");
                printf(" *****************************\n");
                printf(" *****************************\n");
                printf("  ***************************\n");
                printf("   *************************\n");
                printf("     *********************\n");
                printf("       *****************\n");
                printf("         *************\n");
                printf("           *********\n");
                printf("             *****\n");
                printf("              ***\n");
                printf("               *\n" RESET);
            } else {
                printf(VERMELHO "%s, VOCÊ NÃO É A BEAAAA 😭\n" RESET, nome);
            }
            break;

        case 2:
            return 0;                                               // Sai do programa

        default:
            printf(VERMELHO "Opção inválida! Tente novamente.\n" RESET); // Mensagem de erro
            break;
        }
    }

    return 0;                                                       // Fim do programa
}
