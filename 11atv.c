#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

    char p1[6], p2[6], p3[6], p4[6], p5[6]; // Perguntas
    printf("Telefonou para a vitima?\n");
    gets(p1);
    printf("Esteve no local do crime?\n");
    gets(p2);
    printf("Mora perto da vitima?\n");
    gets(p3);
    printf("Devia para a vitima?\n");
    gets(p4);
    printf("Ja trabalhou com a vitima?\n");
    gets(p5);

    char t[6] = "True";

    int pp1, pp2, pp3, pp4, pp5, ppr; // Pontos das Perguntas

    if(strcmp (t, p1)) // Comparação de strings
    {
      pp1 = 0;
    }
    else
    {
      pp1 = 1;
    }
    if(strcmp (t, p2))
    {
      pp2 = 0;
    }
    else
    {
      pp2 = 1;
    }
    if(strcmp (t, p3))
    {
      pp3 = 0;
    }
    else
    {
      pp3 = 1;
    }
    if(strcmp (t, p4))
    {
      pp4 = 0;
    }
    else
    {
      pp4 = 1;
    }
    if(strcmp (t, p5))
    {
      pp5 = 0;
    }
    else
    {
      pp5 = 1;
    }

    ppr = pp1 + pp2 + pp3 +pp4 + pp5;

    if (ppr <2){

      printf("Inocente\n");

    }
    if (ppr >=2 && ppr <3){

      printf("Suspeita\n");

    }
    if (ppr >=3 && ppr <=4){

      printf("Cumplice\n");

    }
    if (ppr >=5){

      printf("Assassino\n");

    }

return 0;
}
