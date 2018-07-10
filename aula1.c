/*
- == Aula de Programação 1:

- O que é programação de Computadores? A programação de computadores é uma atividade que leva à representação dos passos necessários à resolução de um problema em linguagem de programação.
- O que é linguagem de programação? Uma linguagem desenvolvida para viabilizar a programação de computadores.
- O que é algoritimos? R: Conjuntos de instruções bem definidas que visam resolver um determinado problema; Um algoritmo tem FIM, isto é, ele precisa terminar.
- Algoritmo Inviável: Aquele que demanda muito tempo e poder computacional.
- Leva a galinha, volta; Leva a rapousa, volta com a galinha; Leva o milho e volta; Leva a galinha.
- Leva a galinha, volta; Leva o milho, volta com a galinha; Leva a raposa e volta; Leva a galinha.

- O que é compilador? O responsável por traduzir o Programa Fonte para a linguagem de máquina.

- = Autores Importantes
- Charles Babbage (Desenvolvedor do 1° Computador)
- Ada Augusta King (1ª Programadora)
- Maquina de Turing
- Dennis Ritchie (Criador da Linguagem C)

- = Linguagem Computacional:

1. Início
2. Ir G
3. Voltar <>
4. Ir R // Pode ser alterado por M
5. Voltar G
6. Ir M // Pode ser alterado por R
7. Voltar <>
8. Ir G
9. Fim

1. Início
2. Ir G
3. Voltar <>
4. Ir M // Pode ser alterado por R
5. Voltar G
6. Ir R // Pode ser alterado por M
7. Voltar <>
8. Ir G
9. Fim

*/

#include <stdio.h> // input/output; É a adição de uma biblioteca <stdio.h> que inclui os comandos printf(saída) e scanf(entrada);

void imprimir_2() {

    printf("Primeiro Programa em C com duas funções\n");

}

int main() { // Definição de uma função!

// == Função: Sintaxe na linguagem C
// <tipo de retorno><identificador>([lista de parâmetros])
// {
// [bloco de comandos]
// }

    printf("Primeiro Programa em C\n"); // Chamada de função: Eu uso!
    printf("by: Willy Tiengo\n");

    imprimir_2(); // Chama a função imprimir_2

return 0;
}
