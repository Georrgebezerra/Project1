#include <stdio.h>
#include <string.h>
#define MAX_HABILIDADES 10
#define MAX_NOME 50
#define MAX_VAGAS 5

struct Vaga {
    char titulo[MAX_NOME];
    char habilidades[MAX_HABILIDADES][MAX_NOME];
    int num_habilidades;
};

struct Curriculo {
    char habilidades[MAX_HABILIDADES][MAX_NOME];
    int num_habilidades;
};

void adicionarVaga(struct Vaga *vaga, int id) {
    printf("\n=== Adicionar Vaga %d ===\n", id + 1);
    printf("Titulo da vaga: ");
    scanf(" %[^\n]s", vaga->titulo);
    vaga->num_habilidades = 0;
    printf("Digite as habilidades requeridas (max %d, 'fim' para encerrar):\n", MAX_HABILIDADES);
    while (vaga->num_habilidades < MAX_HABILIDADES) {
        printf("Habilidade %d: ", vaga->num_habilidades + 1);
        scanf(" %[^\n]s", vaga->habilidades[vaga->num_habilidades]);
        if (strcmp(vaga->habilidades[vaga->num_habilidades], "fim") == 0) break;
        vaga->num_habilidades++;
    }
}

void adicionarCurriculo(struct Curriculo *curriculo) {
    printf("\n=== Adicionar Curriculo ===\n");
    curriculo->num_habilidades = 0;
    printf("Digite suas habilidades (max %d, 'fim' para encerrar):\n", MAX_HABILIDADES);
    while (curriculo->num_habilidades < MAX_HABILIDADES) {
        printf("Habilidade %d: ", curriculo->num_habilidades + 1);
        scanf(" %[^\n]s", curriculo->habilidades[curriculo->num_habilidades]);
        if (strcmp(curriculo->habilidades[curriculo->num_habilidades], "fim") == 0) break;
        curriculo->num_habilidades++;
    }
}

float calcularMatch(struct Curriculo *curriculo, struct Vaga *vaga) {
    int habilidades_correspondentes = 0;
    for (int i = 0; i < curriculo->num_habilidades; i++) {
        for (int j = 0; j < vaga->num_habilidades; j++) {
            if (strcmp(curriculo->habilidades[i], vaga->habilidades[j]) == 0) {
                habilidades_correspondentes++;
            }
        }
    }
    return (float)habilidades_correspondentes / vaga->num_habilidades * 100;
}

void exibirMatches(struct Curriculo curriculo, struct Vaga vagas[], int num_vagas) {
    printf("\nMatches para seu perfil:\n");
    for (int j = 0; j < num_vagas; j++) {
        float match = calcularMatch(&curriculo, &vagas[j]);
        printf("Vaga: %s - Compatibilidade: %.2f%%\n", vagas[j].titulo, match);
    }
}

int main() {
    struct Vaga vagas[MAX_VAGAS];
    struct Curriculo curriculo;
    int num_vagas = 0;
    int op;

    do {
        printf("\n=== Sistema de Match CV-Vagas ===\n");
        printf("1 - Adicionar Vaga\n");
        printf("2 - Adicionar Curriculo\n");
        printf("3 - Exibir Matches\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                if (num_vagas < MAX_VAGAS) {
                    adicionarVaga(&vagas[num_vagas], num_vagas);
                    num_vagas++;
                } else {
                    printf("Limite de vagas atingido!\n");
                }
                break;
            case 2:
                adicionarCurriculo(&curriculo);
                break;
            case 3:
                if (num_vagas > 0) {
                    exibirMatches(curriculo, vagas, num_vagas);
                } else {
                    printf("Nao ha vagas cadastradas!\n");
                }
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 4);

    return 0;
}

//by: gg_Dev
