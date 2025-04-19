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
  int escolha;

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

  printf("\nEscolha o atributo para comparação:\n");
  printf("1 - População\n");
  printf("2 - Área\n");
  printf("3 - PIB\n");
  printf("4 - Pontos Turísticos\n");
  printf("5 - Densidade Populacional\n");
  printf("Digite sua escolha (1-5): ");
  scanf(" %d", &escolha);

  switch (escolha)
  {
  case 1:
    printf("Atributo: População\n");
    printf("%s: %d habitantes\n", nomeCidade1, populacao1);
    printf("%s: %d habitantes\n", nomeCidade2, populacao2);
    if (populacao1 > populacao2)
      printf("Resultado: %s venceu!\n", nomeCidade1);
    else if (populacao2 > populacao1)
      printf("Resultado: %s venceu!\n", nomeCidade2);
    else
      printf("Resultado: Empate!\n");
    break;

  case 2:
    printf("Atributo: Área\n");
    printf("%s: %.2f km²\n", nomeCidade1, area1);
    printf("%s: %.2f km²\n", nomeCidade2, area2);
    if (area1 > area2)
      printf("Resultado: %s venceu!\n", nomeCidade1);
    else if (area2 > area1)
      printf("Resultado: %s venceu!\n", nomeCidade2);
    else
      printf("Resultado: Empate!\n");
    break;
  case 3:
    printf("Atributo: PIB\n");
    printf("%s: R$ %.2f bilhões\n", nomeCidade1, pib1);
    printf("%s: R$ %.2f bilhões\n", nomeCidade2, pib2);
    if (pib1 > pib2)
      printf("Resultado: %s venceu!\n", nomeCidade1);
    else if (pib2 > pib1)
      printf("Resultado: %s venceu!\n", nomeCidade2);
    else
      printf("Resultado: Empate!\n");
    break;

  case 4:
    printf("Atributo: Pontos Turísticos\n");
    printf("%s: %d pontos\n", nomeCidade1, pontosTuristicos1);
    printf("%s: %d pontos\n", nomeCidade2, pontosTuristicos2);
    if (pontosTuristicos1 > pontosTuristicos2)
      printf("Resultado: %s venceu!\n", nomeCidade1);
    else if (pontosTuristicos2 > pontosTuristicos1)
      printf("Resultado: %s venceu!\n", nomeCidade2);
    else
      printf("Resultado: Empate!\n");
    break;

  case 5:
    printf("Atributo: Densidade Populacional\n");
    printf("%s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
    printf("%s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
    if (densidadePopulacional1 < densidadePopulacional2)
      printf("Resultado: %s venceu (menor densidade)!\n", nomeCidade1);
    else if (densidadePopulacional2 < densidadePopulacional1)
      printf("Resultado: %s venceu (menor densidade)!\n", nomeCidade2);
    else
      printf("Resultado: Empate!\n");
    break;

  default:
    printf("Opção inválida. Por favor, reinicie o programa e escolha uma opção de 1 a 5.\n");
    break;
  }

  return 0; // Retorna 0 para o sistema operacional
}