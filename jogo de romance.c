#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <unistd.h> // Para usar sleep() e usleep()

// Códigos de cor ANSI para deixar o texto colorido no terminal
#define RESET     "\033[0m"
#define VERMELHO  "\033[1;31m"
#define VERDE     "\033[1;32m"
#define AZUL      "\033[1;34m"
#define ROSA      "\033[1;95m"
#define tam 50

int main() {
    setlocale(LC_ALL, ".UTF-8"); // Habilita suporte a caracteres especiais

    // Variáveis do jogo
    int menu, amor, amor2, amor3;
    char nome[tam];
    char nome_lower[tam];
    int finais = 0;
    char jogar_novamente;
    int finais_vistos[8] = {0};

    while (1) {
        // Exibe o menu inicial
        printf("\n1-Play\n");
        printf("2-Exit\n");
        scanf("%d", &menu);
        while (getchar() != '\n'); // Limpa o buffer

        switch(menu){
        case 1:
            do {
                // Entrada do nome
                printf("Esse é um mini jogo para a pessoa que eu mais");
                printf(VERMELHO " AMO NO MUNDO 🥰\n" RESET);
                printf("Para começar, digite seu nome:\n");

                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

                // Converte o nome para minúsculo
                strcpy(nome_lower, nome);
                for (int i = 0; nome_lower[i]; i++) {
                    nome_lower[i] = tolower(nome_lower[i]);
                }

                // Verifica se é a Bea para final verdadeiro
                if (
                    strcmp(nome_lower, "bea") == 0 ||
                    strcmp(nome_lower, "beatriz") == 0 ||
                    strcmp(nome_lower, "beatriz esmy") == 0
                ) {
                    // Final verdadeiro
                    printf(ROSA "\n╔════════════════════════════════════╗\n");
                    printf("    💖 VOCÊ DESBLOQUEOU O FINAL 💖    \n");
                    printf("         🌸🌸 VERDADEIRO 🌸🌸          \n");
                    printf("╚════════════════════════════════════╝\n\n" RESET);
                    printf(ROSA "Pedro te dá um abraço apertado e diz: 'Eu sabia que era você!'\n");
                    printf("Vocês vivem felizes para sempre...\n" RESET);

                    if (!finais_vistos[6]) {
                        finais_vistos[6] = 1;
                        finais++;
                    }
                } else if (
                    strcmp(nome_lower, "pedro") == 0 ||
                    strcmp(nome_lower, "pedro lucas") == 0
                ) {
                    // Final de identidade falsa
                    printf(VERMELHO "\n>>> ERRO: CONFLITO DE IDENTIDADE\n" RESET);
                    sleep(1);
                    printf(VERMELHO ">>> PEDRO DETECTADO...\n" RESET);
                    sleep(1);
                    printf(VERMELHO "\nSÓ PODE EXISTIR UM PEDROOOO!!! 🔥👹🔥\n" RESET);
                    sleep(1);
                   for (int i = 0; i < 5; i++) {
                   printf("\033[5;31m#####@!#@%%!@$$%%¨&***###~~~#####\033[0m\n");
                   usleep(150000);
                }
                    printf(VERMELHO "\n>>>>> AUTO-EXCLUSÃO INICIADA...\n" RESET);
                    sleep(1);
                    printf("Adeus, impostor...\n");
                     if (!finais_vistos[7]) {
                        finais_vistos[7] = 1;
                        finais++;
                    }
                    
                } else {
                    // Diálogo comum
                    printf(AZUL "Prazer, %s!\n" RESET, nome);
                    printf("Você gostaria de sair comigo?\n");

                    // Primeira escolha
                    printf(VERDE "1 - Sim seu lindo 💅\n" RESET);
                    printf(VERDE "2 - Sim 😳\n" RESET);
                    printf(VERMELHO "3 - Não 🙄\n" RESET);

                    char entrada[10];
                    fgets(entrada, sizeof(entrada), stdin);
                    if (sscanf(entrada, "%d", &amor) != 1) amor = -1;

                    switch (amor) {
                        case 1:
                            // Segunda escolha
                            printf("Você está se achando muito!\n");
                            printf(ROSA "1 - O amor da sua vida 💘\n" RESET);
                            printf(ROSA "2 - A Bea 😇\n" RESET);
                            fgets(entrada, sizeof(entrada), stdin);
                            if (sscanf(entrada, "%d", &amor2) != 1) amor2 = -1;

                            switch (amor2) {
                                case 1:
                                    printf(VERMELHO "Não gostei de você 😤(pedro pega uma ak-47 e mata você)nFim brutal 💀\n" RESET);
                                    if (!finais_vistos[0]) { finais_vistos[0] = 1; finais++; }
                                    break;
                                case 2:
                                    printf("Me diga o nome do gatinho dela 🐱\n");
                                    printf(AZUL "1 - Lucas 🐾\n" RESET);
                                    printf(AZUL "2 - Fofo 💍\n" RESET);
                                    fgets(entrada, sizeof(entrada), stdin);
                                    if (sscanf(entrada, "%d", &amor3) != 1) amor3 = -1;

                                    if (amor3 == 1) {
                                        printf(VERMELHO "Você está certo, mas não gostei da resposta 😾(pedro pega uma bazuca de gatinhos e mata Você)\nFim tonto 🤪\n" RESET);
                                        if (!finais_vistos[1]) { finais_vistos[1] = 1; finais++; }
                                    } else if (amor3 == 2) {
                                        printf(VERDE "\nÉ você mesmo!! 😍\nFinal feliz 🌈\n" RESET);
                                        printf(VERDE "\nvocês casam, vocês tiverem 2 filhos, 1 cachorro, 2 gatos e uma cacatua\n" RESET);
                                        
                                        
                                        if (!finais_vistos[2]) { finais_vistos[2] = 1; finais++; }
                                    } else {
                                        printf(VERMELHO "Final secreto: resposta estranha 🔀\n" RESET);
                                        if (!finais_vistos[3]) { finais_vistos[3] = 1; finais++; }
                                    }
                                    break;
                                default:
                                    printf(VERMELHO "Final secreto: sou burro 🙈\n" RESET);
                                    if (!finais_vistos[3]) { finais_vistos[3] = 1; finais++; }
                                    break;
                            }
                            break;
                        case 2:
                            printf(VERMELHO "Voçê é bem sem graça né %s (pedro pega uma espada samurai e corta Voçê ao meio)Final sem graça 💤\n" RESET);
                            if (!finais_vistos[4]) { finais_vistos[4] = 1; finais++; }
                            break;
                        case 3:
                            printf(AZUL "Nossa vai tomar no %s(pedro vira as costas e vai embora)\nFinal pacifista ☮️\n" RESET);
                            if (!finais_vistos[5]) { finais_vistos[5] = 1; finais++; }
                            break;
                        default:
                            printf(VERMELHO "Final secreto: sou burro 🤔\n" RESET);
                            if (!finais_vistos[3]) { finais_vistos[3] = 1; finais++; }
                            break;
                    }
                }

                // Mostrar progresso e repetir?
                printf(AZUL "\nVocê concluiu %d/8 finais únicos! 🏆\n" RESET, finais);
                printf("Deseja jogar novamente? (s/n): ");
                scanf(" %c", &jogar_novamente);
                getchar(); // limpa \n

                printf("\n\n");

            } while (jogar_novamente == 's' || jogar_novamente == 'S');

            // Final secreto especial se todos os finais foram desbloqueados
            if (finais == 8) {
                printf(ROSA "\nSe você desbloqueou TODOS os finais, você com certeza é a BEAAAA! 😍\n");
                printf("Final secreto desbloqueado... 💖\n\n");

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
            return 0;

        default:
            printf(VERMELHO "Opção inválida! Tente novamente.\n" RESET);
            break;
        }
    }

    return 0;
}
       
