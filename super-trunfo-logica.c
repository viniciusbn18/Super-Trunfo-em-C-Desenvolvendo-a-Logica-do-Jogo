#include <stdio.h>
#include <string.h>

int main()
{
  // Declaração das variáveis
  char estado1, estado2;
  char codigo1[4], codigo2[4];
  char nomeCidade1[50], nomeCidade2[50];
  int populacao1, populacao2;
  float area1, area2;
  float pib1, pib2;
  int pontosTuristicos1, pontosTuristicos2;

  // Leitura dos dados da primeira carta
  printf("Digite os dados da primeira carta:\n");
  printf("Estado (A-H): ");
  scanf(" %c", &estado1);
  printf("Código da Carta: ");
  scanf(" %s", codigo1);
  printf("Nome da Cidade: \n");
  getchar();                                   // Limpa o buffer do teclado
  fgets(nomeCidade1, 50, stdin);               // fgets para ler strings com espaços
  nomeCidade1[strcspn(nomeCidade1, "\n")] = 0; // Remove o \n do final da string

  printf("População: ");
  scanf(" %d", &populacao1);
  printf("Área (em km²): ");
  scanf(" %f", &area1);
  printf("PIB (em bilhões de reais): ");
  scanf(" %f", &pib1);
  printf("Número de Pontos Turísticos: ");
  scanf(" %d", &pontosTuristicos1);

  // Leitura dos dados da segunda carta
  printf("\nDigite os dados da segunda carta:\n");
  printf("Estado (A-H): ");
  scanf(" %c", &estado2);
  printf("Código da Carta: ");
  scanf(" %s", codigo2);
  printf("Nome da Cidade: ");
  getchar();                                   // Limpa o buffer do teclado
  fgets(nomeCidade2, 50, stdin);               // fgets para ler strings com espaços
  nomeCidade2[strcspn(nomeCidade2, "\n")] = 0; // Remove o \n do final da string

  printf("População: ");
  scanf(" %d", &populacao2);
  printf("Área (em km²): ");
  scanf(" %f", &area2);
  printf("PIB (em bilhões de reais): ");
  scanf(" %f", &pib2);
  printf("Número de Pontos Turísticos: ");
  scanf(" %d", &pontosTuristicos2);

  // Armazenando em variáveis
  float densidadePopulacional1 = populacao1 / area1;
  float densidadePopulacional2 = populacao2 / area2;

  float pibPerCapta1 = pib1 / populacao1;
  float pibPerCapta2 = pib2 / populacao2;

  printf("Critério de comparação utilizado: Densidade Populacional\n");
  if (densidadePopulacional1 < densidadePopulacional2)
  {
    printf("Carta 1: %s", nomeCidade1);
    printf("\n");
    printf("Densidade Populacional: %f", densidadePopulacional1);
    printf("\n");
    printf("Carta 2: %s", nomeCidade2);
    printf("\n");
    printf("Densidade Populacional: %f", densidadePopulacional2);
    printf("\n");
    printf("Resultado: Carta 1 é a vencedora!\n");
  }
  else
  {
    printf("Carta 1: %s", nomeCidade1);
    printf("Densidade Populacional: %f", densidadePopulacional1);
    printf("\n");
    printf("Carta 2: %s", nomeCidade2);
    printf("Densidade Populacional: %f", densidadePopulacional2);
    printf("A carta 2 é a vencedora!");
  }

  return 0; // Retorna 0 para o sistema operacional
}