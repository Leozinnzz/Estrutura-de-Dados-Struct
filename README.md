# 📚 Estrutura de Dados Structs

Este repositório contém códigos e exemplos práticos sobre o uso de **structs em C**, abordando desde conceitos básicos até aplicações mais avançadas.  
O objetivo é ajudar iniciantes (como eu no começo 🙂) a entender como organizar dados de forma estruturada dentro da linguagem C.

---

## 🚀 Sobre o Projeto

Aqui você encontrará exemplos de:

- Declaração de `struct`
- Atribuição de valores
- Vetores de structs
- `typedef` para simplificar o código
- Structs dentro de structs
- Funções que recebem e retornam structs
- Pequenos exercícios práticos

---

## 🧱 O que são Structs?

`struct` é um tipo de dado criado pelo programador que permite **agrupar variáveis diferentes em uma mesma estrutura**, facilitando organização, leitura e manutenção do código.

Exemplo simples:

```c
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};
