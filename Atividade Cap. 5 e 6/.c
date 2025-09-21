Atividades Práticas de Laboratório – Capítulos 5 e 6 
Livro: Conceitos de Linguagens de Programação – Robert W. Sebesta (11ª Edição) 
■ Capítulo 5 – Nomes, Vinculações e Escopos 
Atividade 1 – Escopo Estático x Escopo Dinâmico 
Objetivo: Compreender a diferença entre escopo estático e dinâmico. 
Passos: 
• Implemente em Python um código com funções aninhadas: - Uma variável global `x = 10`. - Uma função `f()` que imprime o valor de `x`. - Uma função `g()` que define `x = 20` e chama `f()`. - Execute `g()` e observe o resultado. 
• Implemente um exemplo semelhante em JavaScript e compare os resultados.
Código em Python:
x = 10
def f():
    print(x)
def g():
    x = 20
    f()
g()








Código em JavaScript:


var x = 10;
function f() {
    console.log(x);
}
function g() {
    var x = 20;
    f();
}
g();
Atividade 2 – Tempo de Vida das Variáveis 
Objetivo: Analisar a diferença entre variáveis estáticas e automáticas. 
Passos: 
• Em C, crie uma função `contador()` com duas variáveis locais: - `int a = 0;` (automática) - `static int b = 0;` (estática) 
• A cada chamada de `contador()`, incremente ambas e imprima os valores. • Chame `contador()` três vezes seguidas. 
#include <stdio.h>
void contador() {
    int a = 0;          
    static int b = 0; 
    a++;  
    b++;  

    printf("a: %d, b: %d\n", a, b);  
} 
int main() {
    contador();  // Chamada 1
    contador();  // Chamada 2
    contador();  // Chamada 3
    return 0;
}

■ Capítulo 6 – Tipos de Dados 
Atividade 3 – Declaração de Tipos e Coerção 
Objetivo: Explorar tipagem estática e dinâmica, além de conversão de tipos. Passos: 
• Em Java, declare uma variável `int num = 10;` e tente atribuir uma string a ela. Observe o resultado. 
• Em Python, crie `num = 10` e depois faça `num = 'dez'`.
• Em ambas as linguagens, tente somar `num + 5` e observe o comportamento. 

public class Main {
    public static void main(String[] args) {
        int num = 10;
        // Tentar atribuir uma string a uma variável int
        // num = "dez"; // Isso gera erro de compilação: incompatibilidade de tipos
        
        // Tentando somar num com 5
        System.out.println(num + 5); // Resultado: 15
    }
}

Python:
num = 10
num = 'dez'  # Isso é permitido em Python, pois a tipagem é dinâmica

# Tentando somar num com 5
print(num + 5)  # Erro: TypeError, não é possível somar string e inteiro













Atividade 4 – Trabalhando com Arrays e Registros (Structs) 
Objetivo: Compreender a diferença entre tipos homogêneos (arrays) e heterogêneos (structs/objetos). 
Passos: 
• Em C: Crie um array de 5 inteiros e inicialize com valores de sua escolha. 
• Ainda em C: Crie uma struct `Livro` com campos: `titulo`, `autor`, `anoPublicacao` e inicialize um objeto. 
• Em Java: Crie uma classe `Livro` com atributos semelhantes, crie uma `ArrayList` e adicione 3 objetos. 
• Imprima apenas os títulos dos livros adicionados. 

#include <stdio.h>
int main() {
    int numeros[5] = {10, 20, 30, 40, 50};
    
    for (int i = 0; i < 5; i++) {
        printf("Numero: %d\n", numeros[i]);
    }
    return 0;
}

#include <stdio.h>

struct Livro {
    char titulo[50];
    char autor[50];
    int anoPublicacao;
};

int main() {
    struct Livro livro1 = {"O Alquimista", "Paulo Coelho", 1988};
    
    printf("Titulo do Livro: %s\n", livro1.titulo);

    return 0;
}

import java.util.ArrayList;

class Livro {
    String titulo;
    String autor;
    int anoPublicacao;

    Livro(String titulo, String autor, int anoPublicacao) {
        this.titulo = titulo;
        this.autor = autor;
        this.anoPublicacao = anoPublicacao;
    }
}

public class Main {
    public static void main(String[] args) {
        ArrayList<Livro> livros = new ArrayList<>();
        
        livros.add(new Livro("O Alquimista", "Paulo Coelho", 1988));
        livros.add(new Livro("1984", "George Orwell", 1949));
        livros.add(new Livro("Dom Casmurro", "Machado de Assis", 1899));
        
        for (Livro livro : livros) {
            System.out.println("Titulo do Livro: " + livro.titulo);
        }
    }
}
