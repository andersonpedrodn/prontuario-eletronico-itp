# 📐 Projeto: Prontuário Eletrônico de Pacientes

## 📄 Descrição 

Este projeto é um sistema simples de gerenciamento de pacientes via linha de comando (CLI), desenvolvido em C como parte da avaliação da Unidade 1 da disciplina de Introdução a Técnicas de Programação do curso BTI do IMD/UFRN. O programa armazena os dados em memória enquanto está em execução.

## ⚙ Funcionalidades 

**Cadastro de pacientes:** Permite cadastrar pacientes no sistema, salvando nome, idade e sintomas.
**Listagem de pacientes:** Permite verificar quais pacientes foram cadastradas no sistema.
**Visualização detalhada:** Permite ao usuário selecionar um paciente da lista para ver todas as suas informações, incluindo os sintomas.


## Como executar

### Pré-requisitos
- É necessário ter um compilador C, nesse projeto foi usado o compilador GCC.

### Passos
1.  Navegue até o diretório do código-fonte com o terminal:
    ```bash
    cd projeto/src/
    ```
2.  Compile o programa utilizando o GCC:
    ```bash
    gcc -o prontuario main.c
    ```
3.  Execute o programa compilado:
    ```bash
    ./prontuario
    ```

## Tecnologias Utilizadas 
**Linguagem:** C
**Compilador:** GCC