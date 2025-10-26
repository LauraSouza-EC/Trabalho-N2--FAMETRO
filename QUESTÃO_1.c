#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
} Data;

typedef struct {
    char nome[41];
    char telefone[16];
    char celular[16];
    char email[41];
    Data aniversario;
} Contato;

//nó da lista encadeada, recebe um contato e um ponteiro para o próximo nó
struct elemento {
    Contato info; //variável do tipo contato
    struct elemento* prox; //ponteiro para o próximo elemento da lista
};
typedef struct elemento Elemento;

//inicializa a agenda como uma lista vazia
Elemento* cria_agenda() {
    return NULL;
}

//função para inserir um novo contato no final da lista, se a lista estiver vazia, o novo contato se torna o primeiro elemento
//se não, percorre a lista até o final e insere o novo contato lá
Elemento* insere_contato(Elemento* agenda, Contato novo) {
    Elemento* novo_elem = (Elemento*)malloc(sizeof(Elemento)); //aloca memória para o novo elemento
    novo_elem->info = novo; //atribui os dados do novo contato ao novo elemento
    novo_elem->prox = NULL; //o próximo elemento é NULL, pois será inserido no final da lista

    if (agenda == NULL) return novo_elem; //se a agenda estiver vazia, retorna o novo elemento como o primeiro da lista

    Elemento* atual = agenda; //ponteiro para percorrer a lista
    while (atual->prox != NULL) //enquanto elemento atual diferente de NULL, avança para o próximo elemento
    atual = atual->prox; //elemento atual recebe o próximo elemento

    atual->prox = novo_elem; //o próximo elemento do atual agora é o novo elemento
    return agenda; //retorna a agenda atualizada
}

//função para listar todos os contatos na agenda, se a agenda estiver vazia, informa que está vazia
void lista_contatos(Elemento* agenda) {
    if (agenda == NULL) {
        printf("Agenda vazia.\n");
        return;
    }

    Elemento* atual = agenda; //atual é variável auxiliar para percorrer a lista
    while (atual != NULL) { //enquanto atual diferente de NULL, imprime os dados do contato
        printf("\nNome: %s\nTelefone: %s\nCelular: %s\nEmail: %s\nAniversario (dd/mm): %02d/%02d\n",
               atual->info.nome, atual->info.telefone, atual->info.celular,
               atual->info.email, atual->info.aniversario.dia, atual->info.aniversario.mes);
        atual = atual->prox; //avança para o próximo elemento
    }
}

Elemento* busca_contato(Elemento* agenda, char nome[]) {
    Elemento* atual = agenda;
    while (atual != NULL) {
        if (strcmp(atual->info.nome, nome) == 0)
            return atual; //contato encontrado
        atual = atual->prox; 
    }
    return NULL; //contato não encontrado
}

Elemento* remove_contato(Elemento* agenda, char nome[]) {
    Elemento* atual = agenda;
    Elemento* anterior = NULL;

    while (atual != NULL && strcmp(atual->info.nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Contato não encontrado.\n");
        return agenda;
    }

    if (anterior == NULL)
        agenda = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    printf("Contato removido com sucesso.\n");
    return agenda;
}

void atualiza_contato(Elemento* agenda, char nome[]) {
    Elemento* contato = busca_contato(agenda, nome);
    if (contato == NULL) {
        printf("Contato não encontrado.\n");
        return;
    }

    printf("Digite os novos dados:\n");
    printf("Nome: "); fgets(contato->info.nome, 41, stdin); contato->info.nome[strcspn(contato->info.nome, "\n")] = 0;
    printf("Telefone: "); fgets(contato->info.telefone, 16, stdin); contato->info.telefone[strcspn(contato->info.telefone, "\n")] = 0;
    printf("Celular: "); fgets(contato->info.celular, 16, stdin); contato->info.celular[strcspn(contato->info.celular, "\n")] = 0;
    printf("Email: "); fgets(contato->info.email, 41, stdin); contato->info.email[strcspn(contato->info.email, "\n")] = 0;
    printf("Dia do aniversario: "); scanf("%d", &contato->info.aniversario.dia);
    printf("Mes do aniversario: "); scanf("%d", &contato->info.aniversario.mes);
    getchar(); // limpar buffer
}

Elemento* remove_duplicados(Elemento* agenda) {
    Elemento* atual = agenda;

    while (atual != NULL) {
        Elemento* anterior = atual;
        Elemento* comparador = atual->prox;

        while (comparador != NULL) {
            if (strcmp(atual->info.nome, comparador->info.nome) == 0) {
                // Duplicado encontrado, remover
                anterior->prox = comparador->prox;
                free(comparador);
                comparador = anterior->prox;
            } else {
                anterior = comparador;
                comparador = comparador->prox;
            }
        }

        atual = atual->prox;
    }

    printf("Contatos duplicados removidos com sucesso.\n");
    return agenda;
}

int main() {
    Elemento* agenda = cria_agenda();
    int opcao;
    char nome[41];

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Editar Contato\n");
        printf("5. Remover Contato\n");
        printf("6. Sair\n");
        printf("7. Remover Contatos Duplicados\n");
        printf("Escolha uma opçao: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1: {
                Contato novo;
                printf("Nome: "); fgets(novo.nome, 41, stdin); novo.nome[strcspn(novo.nome, "\n")] = 0;
                printf("Telefone: "); fgets(novo.telefone, 16, stdin); novo.telefone[strcspn(novo.telefone, "\n")] = 0;
                printf("Celular: "); fgets(novo.celular, 16, stdin); novo.celular[strcspn(novo.celular, "\n")] = 0;
                printf("Email: "); fgets(novo.email, 41, stdin); novo.email[strcspn(novo.email, "\n")] = 0;
                printf("Dia do aniversário: "); scanf("%d", &novo.aniversario.dia);
                printf("Mês do aniversário(DD/MM): "); scanf("%d", &novo.aniversario.mes);
                getchar(); // limpar buffer
                agenda = insere_contato(agenda, novo);
                break;
            }
            case 2:
                lista_contatos(agenda);
                break;
            case 3:
                printf("Digite o nome do contato: ");
                fgets(nome, 41, stdin); nome[strcspn(nome, "\n")] = 0;
                Elemento* encontrado = busca_contato(agenda, nome); 
                if (encontrado)
                    printf("Contato encontrado: %s\n", encontrado->info.nome);
                else
                    printf("Contato não encontrado.\n");
                break;
            case 4:
                printf("Digite o nome do contato a editar: ");
                fgets(nome, 41, stdin); nome[strcspn(nome, "\n")] = 0;
                atualiza_contato(agenda, nome);
                break;
            case 5:
                printf("Digite o nome do contato a remover: ");
                fgets(nome, 41, stdin); nome[strcspn(nome, "\n")] = 0;
                agenda = remove_contato(agenda, nome);
                break;
            case 6:
                printf("Encerrando...\n");
                break;
            case 7:
                agenda = remove_duplicados(agenda);
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 6);

    return 0;
}