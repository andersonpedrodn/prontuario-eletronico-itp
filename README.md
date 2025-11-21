# Introdução a Técnicas de Programação  - Unidades 1 e 2 
Aluno: Anderson Pedro do Nascimento 
Matrícula: 20250052933
Período: 2025.2

<img width="1207" height="332" alt="Captura de tela 2025-11-21 083553" src="https://github.com/user-attachments/assets/a5df051d-809c-4300-9121-7f2ac2681a60" />


## 📁 Estrutura do Projeto

- `projeto/`: Código-fonte do projeto "Prontuário Eletrônico de Pacientes".
- `listas/`: Soluções das listas de exercícios (Semana 2 a Semana 10).
- `relatorios/`: Relatórios técnicos das Unidades 1 e 2.
- `videos/`: Links para os vídeos de demonstração.
- `README.md`: Este arquivo.

## 🚀 Projeto: Prontuário Eletrônico de Pacientes (Versão 2.0)
**Descrição**: Sistema interativo de linha de comando, desenvolvido em C, para o gerenciamento de informações básicas de pacientes. O programa permite ao usuário cadastrar novos pacientes (incluindo nome, idade e sintomas), listar todos os pacientes cadastrados e visualizar os detalhes completos de um paciente específico. Todos os dados são mantidos em memória durante a execução do programa.
**Repositório**: [https://github.com/andersonpedrodn/prontuario-eletronico-itp] 


### 🎥 Demonstração
- **Vídeo Unidade 1:** [https://youtu.be/-nppav30AH4] 
- **Vídeo Unidade 2:** [https://youtu.be/_09GL1MS_wo] 

### Funcionalidades Implementadas:
- **Novos pacientes:**Cadastro de novos pacientes, com leitura de nome, idade e sintomas.
- **Listagem:** Listagem de todos os pacientes cadastrados em memória.
- **Visualização:** Visualização dos detalhes completos de um paciente específico, selecionado por ID.
- **Menu:**Menu interativo e contínuo com tratamento de entradas inválidas.
- **Cadastro Ilimitado (Alocação Dinâmica):** O sistema gerencia a memória automaticamente (`malloc`/`realloc`), expandindo a capacidade conforme novos pacientes são cadastrados, sem limites fixos.
- **Busca por Nome (Strings):** Permite localizar pacientes rapidamente digitando parte do nome, utilizando manipulação de strings (`strstr`).
- **Inventário de Saúde Mental (Matrizes):** Implementação do questionário PHQ-9, onde as respostas são armazenadas e processadas utilizando matrizes dinâmicas.
- **Verificação de Duplicidade (Loops Aninhados):** Algoritmo que percorre a base de dados para identificar e alertar sobre cadastros com nomes idênticos.
- **Gestão de Memória Segura:** Implementação rigorosa de `free()` para garantir que toda a memória alocada seja liberada ao encerrar o programa, evitando *memory leaks*.

## Conceitos da **unidade 1**:
- **Estruturas condicionais:** `switch-case` para o controle do menu principal e `if-else` para validações de dados (limites, IDs inválidos, etc.).
- **Estruturas de repetição:** `do-while` para o loop principal do programa e `for` para a iteração e listagem dos pacientes.
- **Vetores:** Utilização de vetores paralelos (`nomes`, `idades`, `sintomas`) para simular um banco de dados em memória.
- **Funções:** O código foi modularizado em 5 funções (`main`, `exibirMenu`, `cadastrarPaciente`, `listarPacientes`, `verDetalhesPaciente`) com responsabilidades únicas para maior organização.

## Conceitos da **Unidade 2**:
- **Ponteiros e Alocação Dinâmica:** Substituição de vetores estáticos por ponteiros (`char **`, `int *`). Uso de `malloc` para alocação inicial, `realloc` para expansão automática da capacidade de armazenamento e `free` para liberação de memória (prevenção de *memory leaks*).
- **Matrizes Dinâmicas:** Implementação de estruturas bidimensionais alocadas dinamicamente (`int **phq9_respostas`) para armazenar as respostas do questionário de saúde mental.
- **Manipulação de Strings:** Utilização avançada da biblioteca `string.h`, aplicando a função `strstr` para implementar um sistema de busca parcial por nome.
- **Estruturas de Repetição Aninhadas:** Aplicação de laços `for` aninhados (um dentro do outro) para realizar a verificação de duplicidade de registros na base de dados.

## 📚 Listas de Exercícios

O diretório `listas/` contém as soluções desenvolvidas. O status atual da resolução é o seguinte:
### Semana 2 - Variáveis, Tipos e Operadores:
    ✅ Problema 1: Calculadora de IMC
    ✅ Problema 2: Conversão de temperatura
    ✅ Problema 3: Cálculo de juros compostos
    ✅ Problema 4: Operações aritméticas básicas
### Semana 3 - Condicionais:
    ✅ Problema 1: Classificação de IMC
    ✅ Problema 2: Calculadora de energia elétrica
    ✅ Problema 3: Sistema de notas
    ✅ Problema 4: Pedra, papel, tesoura
    ✅ Problema 5: Calculadora de desconto progressivo
    ✅ Problema 6: Diagnóstico médico simples
    ✅ Problema 7: Sistema de equações do 2º grau
    ✅ Problema 8: Validador de triângulos
### Semana 4A - Repetições:
    ✅ Problema 1: Dobrar folha
    ❌ Problema 2: Homem Aranha
    ❌ Problema 3: Números colegas
    ❌ Problema 4: Jogo de dardos
### Semana 4B - Análise e Padrões:
    ❌ Questões 1-11: Pendentes
### Semana 5 - Funções (Parte 1):
    ✅ Problema 1: Horários das rondas
    ✅ Problema 2: Primos triplos
    ❌ Problema 3: Pousando a sonda espacial
### Semana 6 - Vetores:
    ✅ Problema 1: MEC - Correção ENEM
    ✅ Problema 2: Álbum de figurinhas
    ✅ Problema 3: A construção da ponte
    ❌ Problema 4: Em busca do tesouro perdido
### Semana 7 - Strings:
    ✅ Problema 1: Campo minado 1D
    ✅ Problema 2: Detecção de placas
    ✅ Problema 3: OpenMeet
### Semana 8 - Repeticoes aninhadas:
    ✅ Problema 1: Estou com sorte (ou não)
    ❌ Problema 2: Os dias mais chuvosos
    ❌ Problema 3: Esse sim é piloto
### Semana 9 - Matrizes:
    ✅ Problema 1: Campo Agrícola
    ❌ Problema 2: Sugestão de amigos
    ❌ Problema 3: Campeonato de empates
    ❌ Problema 4: Uma pechincha
### Semana 10 - Ponteiros:
    ✅ Problema 1: Soma de Vetores 
    ❌ Problema 2: Ocorrências no vetor 
    ❌ Problema 3: Sopa de letrinhas 



## 🎯 Principais Aprendizados
O principal aprendizado foi a aplicação prática de conceitos para criar um programa estruturado. A depuração de bugs reais, como o manuseio do buffer do teclado (`getchar`) e a gestão do estado com variáveis de controle (`totalPacientes`), foi uma experiência fundamental. O projeto também solidificou a importância da modularização de código com funções para a criação de software legível e de fácil manutenção.

## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows 
- **Compilador**: GCC
- **Editor**: Visual Studio Code

## 🔌 Versão Embarcada (BitDogLab / Raspberry Pi Pico)

![placaBitDogLab](https://github.com/user-attachments/assets/c7de0803-fc93-4e2b-ae14-8133c5064b27)


Além da versão padrão para PC, este repositório possui uma **branch experimental** dedicada a sistemas embarcados.

- **Branch:** `versao-bitdoglab`
- **Hardware:** Placa de desenvolvimento BitDogLab (Raspberry Pi Pico / RP2040).
- **Objetivo:** Adaptar o sistema de prontuário para funcionar em modo "Quiosque" (apenas leitura), utilizando o **Display OLED** da placa para visualizar os pacientes e os botões/joystick para navegação.
- **Como acessar:**
  ```bash
  git checkout versao-bitdoglab

![bitdoglabfoto](https://github.com/user-attachments/assets/a98aaf89-6517-4116-bfa9-b7a43dc64f80)



### <img width="512" height="512" alt="image" src="https://github.com/user-attachments/assets/9845a354-c840-4d59-93b1-b1a2b955e96f" />




![Vídeo do WhatsApp de 2025-11-21 à(s) 12 29 22_1c4689cf](https://github.com/user-attachments/assets/e97a87f9-a082-4955-bd45-d5f63da64557)



  
