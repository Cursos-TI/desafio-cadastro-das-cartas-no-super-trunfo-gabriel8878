#include <stdio.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4

// Estrutura para armazenar informações da cidade
typedef struct {
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

void cadastrarCidades(Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            // Gerar código da cidade
            sprintf(cidades[i][j].codigo, "%c%02d", estados[i], j + 1);
            
            printf("Cadastro da cidade %s\n", cidades[i][j].codigo);
            printf("Nome da Cidade: ");
            scanf(" %[^"]s", cidades[i][j].nome);
            printf("População: ");
            scanf("%d", &cidades[i][j].populacao);
            printf("Área (km²): ");
            scanf("%f", &cidades[i][j].area);
            printf("PIB (em bilhões de reais): ");
            scanf("%f", &cidades[i][j].pib);
            printf("Número de pontos turísticos: ");
            scanf("%d", &cidades[i][j].pontos_turisticos);
            printf("--------------------------------\n");
        }
    }
}

void exibirCidades(Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    printf("\n=== Cidades Cadastradas ===\n");
    int carta = 1;
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            float densidade = cidades[i][j].area > 0 ? cidades[i][j].populacao / cidades[i][j].area : 0;
            float pib_per_capita = cidades[i][j].populacao > 0 ? (cidades[i][j].pib * 1000000000) / cidades[i][j].populacao : 0;
            
            printf("Carta %d:\n\n", carta++);
            printf("Estado: %c\n\n", cidades[i][j].codigo[0]);
            printf("Código: %s\n\n", cidades[i][j].codigo);
            printf("Nome da Cidade: %s\n\n", cidades[i][j].nome);
            printf("População: %d\n\n", cidades[i][j].populacao);
            printf("Área: %.2f km²\n\n", cidades[i][j].area);
            printf("PIB: %.2f bilhões de reais\n\n", cidades[i][j].pib);
            printf("Número de Pontos Turísticos: %d\n\n", cidades[i][j].pontos_turisticos);
            printf("Densidade Populacional: %.2f hab/km²\n\n", densidade);
            printf("PIB per Capita: %.2f reais\n\n", pib_per_capita);
            printf("--------------------------------\n");
        }
    }
}

int main() {
    Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO];
    
    printf("=== Cadastro de Cidades para o Super Trunfo ===\n");
    cadastrarCidades(cidades);
    
    exibirCidades(cidades);
    
    return 0;
}
