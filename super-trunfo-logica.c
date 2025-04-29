#include <stdio.h>
#include <string.h>

int main()
{
  char estado1, estado2;
  char codigo1[4], codigo2[4];
  char nomeCidade1[50], nomeCidade2[50];
  int populacao1, populacao2;
  float area1, area2;
  float pib1, pib2;
  int pontosTuristicos1, pontosTuristicos2;
  int atributo1, atributo2;
  float densidadePopulacional1, densidadePopulacional2;
  float pibPerCapta1, pibPerCapta2;
  float valorA1_carta1, valorA1_carta2;
  float valorA2_carta1, valorA2_carta2;
  float somaCarta1, somaCarta2;

  // Cadastro das cartas
  printf("Digite os dados da primeira carta:\n");
  printf("Estado (A-H): ");
  scanf(" %c", &estado1);
  printf("Código da Carta: ");
  scanf(" %s", codigo1);
  printf("Nome da Cidade: ");
  getchar();
  fgets(nomeCidade1, 50, stdin);
  nomeCidade1[strcspn(nomeCidade1, "\n")] = 0;
  printf("População: ");
  scanf("%d", &populacao1);
  printf("Área (em km²): ");
  scanf("%f", &area1);
  printf("PIB (em bilhões de reais): ");
  scanf("%f", &pib1);
  printf("Número de Pontos Turísticos: ");
  scanf("%d", &pontosTuristicos1);

  printf("\nDigite os dados da segunda carta:\n");
  printf("Estado (A-H): ");
  scanf(" %c", &estado2);
  printf("\nCódigo da Carta: ");
  scanf(" %s", codigo2);
  printf("\nNome da Cidade: ");
  getchar();
  fgets(nomeCidade2, 50, stdin);
  nomeCidade2[strcspn(nomeCidade2, "\n")] = 0;
  printf("População: ");
  scanf("%d", &populacao2);
  printf("Área (em km²): ");
  scanf("%f", &area2);
  printf("PIB (em bilhões de reais): ");
  scanf("%f", &pib2);
  printf("Número de Pontos Turísticos: ");
  scanf("%d", &pontosTuristicos2);

  // Cálculo dos atributos derivados
  densidadePopulacional1 = populacao1 / area1;
  densidadePopulacional2 = populacao2 / area2;
  pibPerCapta1 = pib1 / populacao1;
  pibPerCapta2 = pib2 / populacao2;

  // Exibição do menu de atributos
  printf("\nEscolha o primeiro atributo para comparação:\n");
  printf("1 - População\n");
  printf("2 - Área\n");
  printf("3 - PIB\n");
  printf("4 - Número de Pontos Turísticos\n");
  printf("5 - Densidade Populacional\n");
  printf("6 - PIB per Capita\n");
  printf("Opção: ");
  scanf("%d", &atributo1);

  // Verificação de escolha válida
  if (atributo1 < 1 || atributo1 > 6)
  {
    printf("Opção inválida!\n");
    return 1;
  }

  // Menu dinâmico para o segundo atributo
  printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
  for (int i = 1; i <= 6; i++)
  {
    if (i != atributo1)
    {
      switch (i)
      {
      case 1:
        printf("1 - População\n");
        break;
      case 2:
        printf("2 - Área\n");
        break;
      case 3:
        printf("3 - PIB\n");
        break;
      case 4:
        printf("4 - Número de Pontos Turísticos\n");
        break;
      case 5:
        printf("5 - Densidade Populacional\n");
        break;
      case 6:
        printf("6 - PIB per Capita\n");
        break;
      }
    }
  }
  printf("Opção: ");
  scanf("%d", &atributo2);

  if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1)
  {
    printf("Opção inválida!\n");
    return 1;
  }

  // Atribuição dos valores dos atributos escolhidos
  switch (atributo1)
  {
  case 1:
    valorA1_carta1 = populacao1;
    valorA1_carta2 = populacao2;
    break;
  case 2:
    valorA1_carta1 = area1;
    valorA1_carta2 = area2;
    break;
  case 3:
    valorA1_carta1 = pib1;
    valorA1_carta2 = pib2;
    break;
  case 4:
    valorA1_carta1 = pontosTuristicos1;
    valorA1_carta2 = pontosTuristicos2;
    break;
  case 5:
    valorA1_carta1 = densidadePopulacional1;
    valorA1_carta2 = densidadePopulacional2;
    break;
  case 6:
    valorA1_carta1 = pibPerCapta1;
    valorA1_carta2 = pibPerCapta2;
    break;
  default:
    printf("Erro ao escolher o primeiro atributo!\n");
    return 1;
  }

  switch (atributo2)
  {
  case 1:
    valorA2_carta1 = populacao1;
    valorA2_carta2 = populacao2;
    break;
  case 2:
    valorA2_carta1 = area1;
    valorA2_carta2 = area2;
    break;
  case 3:
    valorA2_carta1 = pib1;
    valorA2_carta2 = pib2;
    break;
  case 4:
    valorA2_carta1 = pontosTuristicos1;
    valorA2_carta2 = pontosTuristicos2;
    break;
  case 5:
    valorA2_carta1 = densidadePopulacional1;
    valorA2_carta2 = densidadePopulacional2;
    break;
  case 6:
    valorA2_carta1 = pibPerCapta1;
    valorA2_carta2 = pibPerCapta2;
    break;
  default:
    printf("Erro ao escolher o segundo atributo!\n");
    return 1;
  }

  // Exibição dos valores
  printf("\nComparação entre:\n%s (Carta 1) x %s (Carta 2)\n", nomeCidade1, nomeCidade2);

  printf("\nAtributo 1:\n");
  printf("%s: %.2f\n", nomeCidade1, valorA1_carta1);
  printf("%s: %.2f\n", nomeCidade2, valorA1_carta2);

  printf("\nAtributo 2:\n");
  printf("%s: %.2f\n", nomeCidade1, valorA2_carta1);
  printf("%s: %.2f\n", nomeCidade2, valorA2_carta2);

  // Ajuste de comparação para densidade populacional (menor é melhor)
  float comparacao1 = (atributo1 == 5) ? -valorA1_carta1 : valorA1_carta1;
  float comparacao2 = (atributo1 == 5) ? -valorA1_carta2 : valorA1_carta2;

  float comparacao3 = (atributo2 == 5) ? -valorA2_carta1 : valorA2_carta1;
  float comparacao4 = (atributo2 == 5) ? -valorA2_carta2 : valorA2_carta2;

  // Soma para decisão final
  somaCarta1 = comparacao1 + comparacao3;
  somaCarta2 = comparacao2 + comparacao4;

  printf("\nSoma dos valores:\n");
  printf("%s: %.2f\n", nomeCidade1, somaCarta1);
  printf("%s: %.2f\n", nomeCidade2, somaCarta2);

  if (somaCarta1 > somaCarta2)
  {
    printf("\nResultado: %s é a vencedora!\n", nomeCidade1);
  }
  else if (somaCarta2 > somaCarta1)
  {
    printf("\nResultado: %s é a vencedora!\n", nomeCidade2);
  }
  else
  {
    printf("\nResultado: Empate!\n");
  }

  return 0;
}
