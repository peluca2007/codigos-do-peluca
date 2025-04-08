#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> // para tolower

int main() {
    setlocale(LC_ALL, "Portuguese");

    int amor, amor2, amor3;
    char nome[30];
    char nome_lower[30];
    int finais = 0;
    char jogar_novamente;

    int finais_vistos[8] = {0};  // agora com espaço pro final verdadeiro também

    do {
        printf("Esse é um mini jogo para a pessoa que eu mais\a");
        printf("\033[1;31m AMOO NO MUNDO\033[0m\n\a");
        printf("Para começar, digite seu nome:\n\a");
        fgets(nome, sizeof(nome), stdin);  
        nome[strcspn(nome, "\n")] = 0;  

        // Copia e transforma o nome em minúsculas para comparar
        strcpy(nome_lower, nome);
        for (int i = 0; nome_lower[i]; i++) {
            nome_lower[i] = tolower(nome_lower[i]);
        }

        // Verifica se é o nome verdadeiro
        if (
            strcmp(nome_lower, "bea") == 0 ||
            strcmp(nome_lower, "beatriz") == 0 ||
            strcmp(nome_lower, "beatriz esmy") == 0
        ) {
            printf("\033[1;32mVOCÊ DESBLOQUEOU O FINAL VERDADEIRO!!!\033[0m\n\a");
            printf("Pedro te dá um abraço apertado e diz: 'Eu sabia que era você!'\n\a");
            printf("Vocês vivem felizes para sempre em uma cabana com Wi-Fi, muitos gatinhos(incluindo o Lucas) e filmes da Disney e filmes ruins de comédias.\n\a");
            printf("\033[1;35mFinal verdadeiro\033[0m\n\a");
            if (!finais_vistos[7]) {
                finais_vistos[7] = 1;
                finais++;
            }
        } else {
            printf("Prazer, %s!\n\a", nome);
            printf("Meu nome é Pedro, mas você já sabe disso bakaaa\n\a");
            printf("Você gostaria de sair comigo?\n\a");
            printf("1 - Sim seu lindo\n2 - Sim\n3 - Não\n\a");
            scanf("%d", &amor);

            switch (amor) {
                case 1:
                    printf("Você está se achando muito, quem você acha que é pra falar assim comigo?\n\a");
                    printf("1 - O amor da sua vida\n2 - A Bea\n\a");
                    scanf("%d", &amor2);

                    switch (amor2) {
                        case 1:
                            printf("Não gostei de você (Pedro pega uma AK-47 e mata você)\n\a");
                            printf("Fim brutal.\n\a\a");
                            if (!finais_vistos[0]) {
                                finais_vistos[0] = 1;
                                finais++;
                            }
                            break;
                        case 2:
                            printf("Me prova que você é a Bea (ele fala bravo)\n\a");
                            printf("Me fale o nome do gatinho dela\n\a");
                            printf("1 - Lucas\n2 - Fofo\n\a");
                            scanf("%d", &amor3);

                            switch (amor3) {
                                case 1:
                                    printf("Você está certo, porém não gostei da resposta (ele pega uma bazuca de gatinhos e mata você)\n\a");
                                    printf("Fim tonto.\n\a");
                                    if (!finais_vistos[1]) {
                                        finais_vistos[1] = 1;
                                        finais++;
                                    }
                                    break;
                                case 2:
                                    printf("Nossa, você está certa, você é a Bea mesmo! Te amooooo (ele te dá vários beijos)\n\a");
                                    printf("(Vocês ficam juntos para sempre)\n\a");
                                    printf("(Vocês têm 2 filhos, 2 gatos, 1 cachorro e uma cacatua)\n\a");
                                    printf("\033[1;31mFinal feliz\033[0m\n\a");
                                    if (!finais_vistos[2]) {
                                        finais_vistos[2] = 1;
                                        finais++;
                                    }
                                    break;
                                default:
                                    printf("Final secreto: sou burro\n\a");
                                    if (!finais_vistos[3]) {
                                        finais_vistos[3] = 1;
                                        finais++;
                                    }
                                    break;
                            }
                            break;
                        default:
                            printf("Final secreto: sou burro\n\a");
                            if (!finais_vistos[3]) {
                                finais_vistos[3] = 1;
                                finais++;
                            }
                            break;
                    }
                    break;

                case 2:
                    printf("Nossa que sem empolgação (Pedro pega uma espada samurai e mata você)\n\a");
                    printf("Final sem graça\a\n");
                    if (!finais_vistos[4]) {
                        finais_vistos[4] = 1;
                        finais++;
                    }
                    break;

                case 3:
                    printf("Vai tomar no cu (ele vira as costas e vai embora)\n\a");
                    printf("Final pacifista\n");
                    if (!finais_vistos[5]) {
                        finais_vistos[5] = 1;
                        finais++;
                    }
                    break;

                default:
                    printf("Final secreto: sou burro\n\a");
                    if (!finais_vistos[6]) {
                        finais_vistos[6] = 1;
                        finais++;
                    }
                    break;
            }
        }

        printf("\n\033[1;34mVocê concluiu %d/8 finais únicos!\033[0m\n\a", finais);
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %s", &jogar_novamente);

        printf("\n\n");

        getchar(); // limpa o buffer pra evitar bug com fgets na próxima vez

    } while (jogar_novamente == 's' || jogar_novamente == 'S');

    printf("\033[1;31m %s VOCÊ NÂO É A BEAAAA\033[0m\n\a", nome);
    return 0;
}


















