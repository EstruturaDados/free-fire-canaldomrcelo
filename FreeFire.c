#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura do item
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MOCHILA DO SOBREVIVENTE – NIVEL NOVATO =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa buffer do Enter

        switch(opcao) {
            case 1: {
                if (total >= MAX_ITENS) {
                    printf("\n⚠️ Mochila cheia! Não é possível adicionar mais itens.\n");
                    break;
                }

                printf("\nNome do item: ");
                fgets(mochila[total].nome, 50, stdin);
                mochila[total].nome[strcspn(mochila[total].nome, "\n")] = '\0';

                printf("Tipo do item: ");
                fgets(mochila[total].tipo, 30, stdin);
                mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = '\0';

                printf("Quantidade: ");
                scanf("%d", &mochila[total].quantidade);
                getchar();

                total++;
                printf("\n✔️ Item adicionado com sucesso!\n");
                break;
            }

            case 2: {
                if (total == 0) {
                    printf("\n⚠️ Não há itens para remover.\n");
                    break;
                }

                char nomeRemover[50];
                printf("\nDigite o nome do item a remover: ");
                fgets(nomeRemover, 50, stdin);
                nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                int encontrado = 0;
                for (int i = 0; i < total; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        encontrado = 1;
                        for (int j = i; j < total - 1; j++) {
                            mochila[j] = mochila[j + 1];
                        }
                        total--;
                        printf("\n✔️ Item removido com sucesso!\n");
                        break;
                    }
                }

                if (!encontrado) {
                    printf("\n❌ Item não encontrado.\n");
                }
                break;
            }

            case 3: {
                if (total == 0) {
                    printf("\n📭 Mochila vazia.\n");
                } else {
                    printf("\n===== ITENS DA MOCHILA =====\n");
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("---------------------------------------------\n");
                    for (int i = 0; i < total; i++) {
                        printf("%-20s %-15s %-10d\n",
                            mochila[i].nome,
                            mochila[i].tipo,
                            mochila[i].quantidade);
                    }
                }
                break;
            }

            case 4:
                printf("\n🏁 Saindo do sistema...\n");
                break;

            default:
                printf("\n⚠️ Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
