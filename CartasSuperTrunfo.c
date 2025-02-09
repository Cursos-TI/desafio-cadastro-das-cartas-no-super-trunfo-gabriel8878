#include <stdio.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4

// Estrutura para armazenar informações da cidade
typedef struct {
    char codigo[4];
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
            printf("População: ");
            scanf("%d", &cidades[i][j].populacao);
            printf("Área (km²): ");
            scanf("%f", &cidades[i][j].area);
            printf("PIB (em bilhões): ");
            scanf("%f", &cidades[i][j].pib);
            printf("Número de pontos turísticos: ");
            scanf("%d", &cidades[i][j].pontos_turisticos);
            printf("--------------------------------\n");
        }
    }
}

void exibirCidades(Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            printf("Código: %s\n", cidades[i][j].codigo);
            printf("População: %d\n", cidades[i][j].populacao);
            printf("Área: %.2f km²\n", cidades[i][j].area);
            printf("PIB: %.2f bilhões\n", cidades[i][j].pib);
            printf("Pontos turísticos: %d\n", cidades[i][j].pontos_turisticos);
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
