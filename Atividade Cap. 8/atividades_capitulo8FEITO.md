# Atividades para Casa – Capítulo 8

## Atividade 1 – Reescrevendo código sem `goto`
Você recebeu o seguinte pseudocódigo, escrito de forma semelhante ao estilo das primeiras versões do Fortran, utilizando `goto`:


for i in range(1, 11):
    print(i)





**Tarefas:**
1. Reescreva o código acima utilizando um laço de repetição pré-teste (`while`) em uma linguagem de sua escolha (C, Java, Python, etc.).
2. Reescreva novamente utilizando um laço de repetição controlado por contador (`for`).
3. Compare os três códigos (original com `goto`, versão com `while` e versão com `for`) e escreva um pequeno parágrafo discutindo qual forma é mais legível e por quê.

---

## Atividade 2 – Seleção múltipla em diferentes linguagens
Muitos programas oferecem menus interativos. Suponha que você precisa implementar um menu com as seguintes opções:

1. Calcular o quadrado de um número.
2. Calcular o fatorial de um número.
3. Sair do programa.


while True:
    print("Escolha uma opção:")
    print("1. Calcular o quadrado de um número")
    print("2. Calcular o fatorial de um número")
    print("3. Sair")
    option = int(input("Digite sua opção: "))
    
    if option == 1:
        num = int(input("Digite um número: "))
        print(f"Quadrado de {num} é {num * num}")
    elif option == 2:
        num = int(input("Digite um número: "))
        fatorial = 1
        for i in range(1, num + 1):
            fatorial *= i
        print(f"Fatorial de {num} é {fatorial}")
    elif option == 3:
        print("Saindo...")
        break
    else:
        print("Opção inválida!")


**Tarefas:**
1. Implemente esse menu em **C** utilizando `switch/case`.
2. Implemente o mesmo menu em **Python**, utilizando apenas `if/elif/else`.
3. Execute os dois programas e compare as soluções em relação à clareza e quantidade de código.
4. Escreva um comentário final destacando em qual linguagem foi mais simples de implementar e justificar o motivo.

#include <stdio.h>

int main() {
    int option, num;
    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Calcular o quadrado de um número\n");
        printf("2. Calcular o fatorial de um número\n");
        printf("3. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Digite um número: ");
                scanf("%d", &num);
                printf("Quadrado de %d é %d\n", num, num * num);
                break;
            case 2:
                printf("Digite um número: ");
                scanf("%d", &num);
                int fatorial = 1;
                for (int i = 1; i <= num; i++) {
                    fatorial *= i;
                }
                printf("Fatorial de %d é %d\n", num, fatorial);
                break;
            case 3:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
    return 0;
}


## Atividade 3 – Explorando alternativas ao `goto`
Historicamente, o `goto` foi usado para resolver diferentes tipos de desvio. Hoje, a maioria das linguagens fornece alternativas como `break`, `continue` e `return`.

**Tarefas:**
1. Escreva um programa que percorra uma lista de números inteiros e:
   - Pare imediatamente a execução ao encontrar o número 0 (`break`).
   - Pule os números negativos sem processá-los (`continue`).
   - Retorne o dobro do primeiro número par encontrado (`return`).
2. Comente sobre como seria a implementação desse mesmo programa utilizando apenas `goto` e rótulos, destacando as vantagens da abordagem moderna.


def process_numbers(numbers):
    for num in numbers:
        if num == 0:
            print("Encontrado 0, encerrando a execução.")
            break
        elif num < 0:
            continue
        elif num % 2 == 0:
            return num * 2

# Teste com a lista de números
numbers = [5, -3, 7, 8, 0, 10]
result = process_numbers(numbers)
if result:
    print(f"Resultado: {result}")


R: Usar o goto em vez de break, continue e return tornaria o código muito mais difícil de entender. Isso porque seria necessário criar vários rótulos, como skip_negative, found_zero, even_number_found, para saltar entre diferentes partes do código. Isso quebraria o fluxo do programa, tornando-o mais propenso a erros e tornando a manutenção mais difícil.

Por outro lado, a abordagem moderna com break, continue e return deixa o código muito mais limpo e claro, sem saltos inesperados. Essas estruturas tornam o fluxo de controle bem definido, o que facilita a leitura e a compreensão do código, ao mesmo tempo que elimina a necessidade de usar rótulos e manipular o fluxo manualmente.