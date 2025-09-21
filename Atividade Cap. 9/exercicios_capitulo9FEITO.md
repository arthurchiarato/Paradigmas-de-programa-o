# Exercícios – Capítulo 9: Subprogramas

## Exercício 1 – Passagem de Parâmetros por Valor e por Referência
Considere o seguinte pseudocódigo de uma função que tenta dobrar o valor de um número:

```text
procedure dobrar(x)
    x := x * 2
end
```

1. Implemente esse subprograma em **C** duas vezes:
   - A primeira versão recebendo o parâmetro **por valor**.
   - A segunda versão recebendo o parâmetro **por referência** (usando ponteiros).

**valor**
#include <stdio.h>

void dobrar_por_valor(int x) {
    x = x * 2;
    printf("Dentro da função (por valor): %d\n", x);
}

int main() {
    int num = 10;
    printf("Antes da função (por valor): %d\n", num);
    dobrar_por_valor(num);
    printf("Após a função (por valor): %d\n", num);
    return 0;
}

**referencia**
#include <stdio.h>

void dobrar_por_referencia(int *x) {
    *x = *x * 2;
    printf("Dentro da função (por referência): %d\n", *x);
}

int main() {
    int num = 10;
    printf("Antes da função (por referência): %d\n", num);
    dobrar_por_referencia(&num);
    printf("Após a função (por referência): %d\n", num);
    return 0;
}


2. Escreva um programa principal que:
   - Crie uma variável inteira com valor inicial 10.
   - Chame a função `dobrar` por valor e exiba o resultado.
   - Chame a função `dobrar` por referência e exiba o resultado.


package main

import (
    "fmt"
    "time"
)

func escrever(texto string) {
    for i := 0; i < 5; i++ {
        fmt.Println(texto, i)
        time.Sleep(time.Millisecond * 500) // Pausa de 500ms
    }
}

func main() {
    go escrever("Corrotina")  // executa em paralelo
    escrever("Função normal") // executa no fluxo principal
}


**Questões:**
- Qual a diferença observada entre as duas versões?
**R:** Na versão por valor, o valor da variável dentro da função é alterado, mas essa alteração não reflete na variável original do programa principal, pois a função recebe uma cópia do valor. Portanto, quando a função termina, a variável do programa principal permanece inalterada. Na versão por referência, a função modifica o valor da variável original, pois ela recebe o endereço de memória da variável, e qualquer modificação feita no valor dentro da função afeta diretamente a variável no programa principal.

- Por que o valor da variável só se altera na versão por referência?
**R:** Na passagem por valor, o que é passado para a função é uma cópia da variável, o que significa que qualquer alteração feita na cópia não afeta a variável original. Na passagem por referência, a função recebe o endereço de memória da variável original, e qualquer alteração feita na variável através desse endereço afeta diretamente a variável no programa principal.

- Relacione essa diferença com as estratégias de passagem de parâmetros discutidas no Capítulo 9.
**R:** A passagem por valor é útil quando você não deseja que a função modifique o valor da variável original, proporcionando um maior controle sobre os dados. A passagem por referência é útil quando você quer que a função modifique a variável original, permitindo uma maior flexibilidade, especialmente em casos onde você precisa manipular grandes estruturas de dados ou quando se deseja economizar memória ao passar grandes objetos sem copiá-los.
---

## Exercício 2 – Corrotinas em GoLang (primeiro contato)
As **corrotinas** permitem a execução concorrente de rotinas dentro de um programa. Em Go, isso é feito com a palavra-chave `go`.

1. Crie um arquivo chamado `main.go`.
2. Implemente o seguinte programa simples:

```go
package main

import (
    "fmt"
    "time"
)

func escrever(texto string) {
    for i := 0; i < 5; i++ {
        fmt.Println(texto, i)
        time.Sleep(time.Millisecond * 500)
    }
}

func main() {
    go escrever("Corrotina")  // executa em paralelo
    escrever("Função normal") // executa no fluxo principal
}
```

3. Compile e execute o programa com:
   ```bash
   go run main.go
   ```

**Questões:**
- O que acontece com a ordem das mensagens exibidas?
**R:**As mensagens da função normal ("Função normal") e da corrotina ("Corrotina") se intercalam. Isso ocorre porque a corrotina é executada em paralelo, e o tempo de execução de ambas as funções não é sequencial. A função principal (função normal) e a corrotina estão competindo por tempo de execução, fazendo com que as mensagens de ambas apareçam alternadamente.

Por que as mensagens da corrotina e da função normal se intercalam?

- Por que as mensagens da corrotina e da função normal se intercalam?
**R:**As mensagens se intercalam porque, no Go, a palavra-chave go cria uma corrotina, que executa a função de forma concorrente (em paralelo) com o restante do código. Isso significa que a função principal continua sendo executada enquanto a corrotina também está em execução. Como ambas as funções fazem chamadas ao fmt.Println e há uma pequena pausa (time.Sleep) dentro de ambas, o tempo de execução delas se sobrepõe, fazendo com que as saídas sejam misturadas.


- Relacione esse comportamento com a definição de **corrotinas** estudada no Capítulo 9.
**R:** Corrotinas são rotinas que podem ser executadas de maneira concorrente, mas de forma cooperativa. Em Go, a palavra-chave go cria uma corrotina, que permite a execução paralela de funções. As corrotinas são úteis para tarefas que podem ser executadas simultaneamente, como no caso de tarefas de I/O, redes ou outras operações que não bloqueiem o restante do programa. No caso deste exemplo, o uso de corrotinas permite que a função escrever seja executada em paralelo à função principal, causando a intercalagem das mensagens.