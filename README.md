# Introdução a Técnicas de Programação  - Unidade 1 
Aluno: Anderson Pedro do Nascimento 
Matrícula: 20250052933
Período: 2025.2

## 📁 Estrutura do Projeto

- 'projeto/': Projeto principal da unidade (Prontuário Eletrônico)
- 'lista': Contém as listas de exercícios, organizadas em subpastas por semana.
- 'README.md': Arquivo de apresentação geral do projeto.

## 🚀 Projeto: Prontuário Eletrônico de Pacientes
**Descrição**: Sistema interativo de linha de comando, desenvolvido em C, para o gerenciamento de informações básicas de pacientes. O programa permite ao usuário cadastrar novos pacientes (incluindo nome, idade e sintomas), listar todos os pacientes cadastrados e visualizar os detalhes completos de um paciente específico. Todos os dados são mantidos em memória durante a execução do programa.
**Repositório**: [https://github.com/andersonpedrodn/prontuario-eletronico-itp] 
**Vídeo de apresentação**: [https://youtu.be/-nppav30AH4] 

### Funcionalidades Implementadas:
- Cadastro de novos pacientes, com leitura de nome, idade e sintomas.
- Listagem de todos os pacientes cadastrados em memória.
- Visualização dos detalhes completos de um paciente específico, selecionado por ID.
- Menu interativo e contínuo com tratamento de entradas inválidas.

## Conceitos da **unidade 1**:
- **Estruturas condicionais:** `switch-case` para o controle do menu principal e `if-else` para validações de dados (limites, IDs inválidos, etc.).
- **Estruturas de repetição:** `do-while` para o loop principal do programa e `for` para a iteração e listagem dos pacientes.
- **Vetores:** Utilização de vetores paralelos (`nomes`, `idades`, `sintomas`) para simular um banco de dados em memória.
- **Funções:** O código foi modularizado em 5 funções (`main`, `exibirMenu`, `cadastrarPaciente`, `listarPacientes`, `verDetalhesPaciente`) com responsabilidades únicas para maior organização.

## 📚 Listas de Exercícios

O diretório `listas/` contém as soluções desenvolvidas. O status atual da resolução é o seguinte:
### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC
- ✅ Problema 2: Conversão de temperatura
- ✅ Problema 3: Cálculo de juros compostos
- ✅ Problema 4: Operações aritméticas básicas
### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC
- ✅ Problema 2: Calculadora de energia elétrica
- ✅ Problema 3: Sistema de notas
- ✅ Problema 4: Pedra, papel, tesoura
- ✅ Problema 5: Calculadora de desconto progressivo
- ✅ Problema 6: Diagnóstico médico simples
- ✅ Problema 7: Sistema de equações do 2º grau
- ✅ Problema 8: Validador de triângulos
### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha
- ❌ Problema 2: Homem Aranha
- ❌ Problema 3: Números colegas
- ❌ Problema 4: Jogo de dardos
### Semana 4B - Análise e Padrões:
- ❌ Questões 1-11: Pendentes
### Semana 5 - Funções (Parte 1):
- ✅ Problema 1: Horários das rondas
- ✅ Problema 2: Primos triplos
- ❌ Problema 3: Pousando a sonda espacial
### Semana 6 - Vetores:
- ✅ Problema 1: MEC - Correção ENEM
- ✅ Problema 2: Álbum de figurinhas
- ✅ Problema 3: A construção da ponte
- ❌ Problema 4: Em busca do tesouro perdido

## 🎯 Principais Aprendizados
O principal aprendizado foi a aplicação prática de conceitos para criar um programa estruturado. A depuração de bugs reais, como o manuseio do buffer do teclado (`getchar`) e a gestão do estado com variáveis de controle (`totalPacientes`), foi uma experiência fundamental. O projeto também solidificou a importância da modularização de código com funções para a criação de software legível e de fácil manutenção.

## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows 
- **Compilador**: GCC
- **Editor**: Visual Studio Code