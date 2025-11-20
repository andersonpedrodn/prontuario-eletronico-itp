#include <stdio.h>
#include <string.h>
#include <stdlib.h> //Importação da biblioteca stdlib.h para uso do alocamento dinâmico     

void cadastrarPacientes();
void listarPacientes();
void exibirMenu();
void exibirDetalhePaciente();
void buscarPacientePorNome();
void verificacaoDuplicidade();


#define n_questoes 9 

char **nomes;
int *idades;
char **sintomas;
int **phq9_respostas; // Matriz para armazenar respostas do PHQ-9

int totalPacientes = 0;
int capacidadeAtual = 2;


int main()
{
    int opcoes;
    
    // Alocação dinâmica inicial das estruturas de dados
    nomes = (char**) malloc(capacidadeAtual * sizeof(char*));
    idades = (int*) malloc(capacidadeAtual * sizeof(int));
    sintomas = (char**) malloc(capacidadeAtual * sizeof(char*));
    phq9_respostas = (int**) malloc(capacidadeAtual * sizeof(int*));

    // Verificação de erro na alocação
    if (nomes == NULL || idades == NULL || sintomas == NULL || phq9_respostas == NULL) { 
        printf("Erro de alocacao de memoria!\n");
        return 1; // Sai do programa com codigo de erro
    }

    do
    {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcoes);
        getchar();

        switch (opcoes)
        {
        case 1:
            cadastrarPacientes();
            break;
        case 2:
            listarPacientes();
            break;
        case 3:
            exibirDetalhePaciente();
            break;
        case 4:
            buscarPacientePorNome();
            break;
        case 5:
            verificacaoDuplicidade();
            break;
        case 0:
            printf("\n-> Saindo do sistema... Ate mais! \n");
            break;
        default:
            printf("\n Opcao invalida! Tente novamente. \n");
        }

    } while (opcoes != 0);

    printf("\n Liberando memoria alocada...\n");
    // Liberacao da memoria alocada dinamicamente
    for (int i = 0; i < totalPacientes; i++)
    {
        free(nomes[i]);
        free(sintomas[i]);
        free(phq9_respostas[i]);
    }
    free(nomes);
    free(idades);
    free(sintomas);
    free(phq9_respostas);

    return 0;
}

void cadastrarPacientes()
{
    // Verifica se é necessário aumentar a capacidade dos arrays
    if (totalPacientes >= capacidadeAtual)
    {
        printf("\n[Sistema] Capacidade esgotada (%d). Expandindo memoria...\n", capacidadeAtual);
        int novaCapacidade = capacidadeAtual * 2; // Dobra a capacidade

        nomes = (char**) realloc(nomes, novaCapacidade * sizeof(char*));
        idades = (int*) realloc(idades, novaCapacidade * sizeof(int));
        sintomas = (char**) realloc(sintomas, novaCapacidade * sizeof(char*));
        phq9_respostas = (int**) realloc(phq9_respostas, novaCapacidade * sizeof(int*));

        if (nomes == NULL || idades == NULL || sintomas == NULL || phq9_respostas == NULL) {
            printf("Erro ao expandir memoria!\n");
            return; // Sai da função em caso de erro
        }

        capacidadeAtual = novaCapacidade;
        printf("[Sistema] Memoria expandida para %d pacientes.\n", capacidadeAtual);
    }
        nomes[totalPacientes] = (char*) malloc(100 * sizeof(char));
        sintomas[totalPacientes] = (char*) malloc(500 * sizeof(char));  
        phq9_respostas[totalPacientes] = (int*) malloc(n_questoes * sizeof(int));

        printf("\n--- Cadastro de Novo Paciente ---\n");
        printf("Novo Paciente: ");
        fgets(nomes[totalPacientes], 100, stdin);
        nomes[totalPacientes][strcspn(nomes[totalPacientes], "\n")] = 0;

        printf("Idade do paciente: ");
        scanf("%d", &idades[totalPacientes]);
        getchar();

        printf("Sintomas iniciais: ");
        fgets(sintomas[totalPacientes], 500, stdin);
        sintomas[totalPacientes][strcspn(sintomas[totalPacientes], "\n")] = 0;

        printf("\n--- Questionario de Saúde PHQ-9: ---\n"); 
        printf("Nas ultimas 2 semanas, com que frequencia voce foi incomodado(a) por:"); 
        printf("Responda: (0 = Nunca), (1 - Varios dias), (2 - Mais da metade dos dias), (3 - Quase todos os dias)\n "); 
        int j; // Variavel para iterar sobre as questoes

        char* perguntas_phq9[n_questoes] = {
            "1. Pouco interesse ou prazer em fazer as coisas?",
            "2. Sentir-se para baixo, deprimido ou sem esperancas?",
            "3. Dificuldade para dormir ou dormir demais?",
            "4. Sentir-se cansado ou com pouca energia?",
            "5. Falta de apetite ou comer demais?",
            "6. Sentir-se mal consigo mesmo(a) ou que voce e um fracasso?",
            "7. Dificuldade de concentrar-se em coisas, como ler o jornal ou ver televisao?",
            "8. Movimentar-se ou falar tao devagar que outras pessoas poderiam notar? Ou o contrario - estar agitado(a) ou inquieto(a)?",
            "9. Pensamentos de que voce estaria melhor morto(a) ou de se ferir de alguma forma?"
        };

        for (j = 0; j < n_questoes; j++) {
            int resposta;
            do {
                printf("%s ", perguntas_phq9[j]);
                scanf("%d", &resposta);
                if (resposta < 0 || resposta > 3) {
                    printf("Resposta invalida. Por favor, responda com 0, 1, 2 ou 3.\n");
                }
            } while (resposta < 0 || resposta > 3);
            phq9_respostas[totalPacientes][j] = resposta;
        }


        totalPacientes++;
        printf("\n PACIENTE CADASTRADO COM SUCESSO! \n");
    
}

void listarPacientes()
{
    printf("\n--- Lista de Pacientes Cadastrados ---\n");

    if (totalPacientes == 0)
    {
        printf("Nenhum paciente cadastrado. \n");
    }
    else
    {
        for (int i = 0; i < totalPacientes; i++)
        {
            printf("%d: %s, %d anos \n", i + 1, nomes[i], idades[i]);
        }
    }

    printf("----------------------------------------\n");
}

void exibirDetalhePaciente() {
    int id;

    printf("\n--- Ver detalhes de um paciente ---\n");
    if (totalPacientes == 0) {
        printf("Nenhum paciente cadastrado. \n");
        return;
    }
    printf("PACIENTE DISPONIVEIS: \n");
    listarPacientes();

    printf("Digite o numero do paciente para ver os detalhes: ");
    scanf("%d", &id);
    getchar();

    if (id > 0 && id <= totalPacientes) {
        int indice = id - 1;
        printf("\n--- DETALHES DO PACIENTE #%d ---\n", id);
        printf("Nome Completo: %s\n", nomes[indice]);
        printf("Idade: %d\n", idades[indice]);
        printf("Sintomas: %s\n", sintomas[indice]);
        printf("\nRespostas do Questionario PHQ-9:\n");
        int j;
        int totalScore = 0;
        for (j = 0; j < n_questoes; j++) {
            printf("Pergunta %d: %d\n", j + 1, phq9_respostas[indice][j]);
            totalScore += phq9_respostas[indice][j];
        }
        printf("--------------------------------------------");
        printf("\nScore Total do PHQ-9: %d\n", totalScore);

        if (totalScore >= 20) {
            printf("Recomenda-se procurar ajuda profissional imediatamente.\n");
        } else if (totalScore >= 15) {
            printf("Recomenda-se consultar um profissional de saude mental.\n");
        } else if (totalScore >= 10) {
            printf("Monitorar os sintomas e considerar buscar ajuda se persistirem.\n");
        } else if (totalScore >= 5) {
            printf("Ficar atento ao bem-estar emocional.\n");
        } else {
            printf("Nenhum indicativo significativo.\n");
        }
        printf("--------------------------------------------\n");
        
    }else{
        printf("Numero de paciente invalido...");
    }

}

void buscarPacientePorNome()
{
    char nomeBusca[100];
    int i, encontrado = 0; // Flag para indicar se encontrou algum paciente

    printf("\n--- Buscar Paciente por Nome ---\n");

    //  Verifica se há pacientes para buscar
    if (totalPacientes == 0)
    {
        printf("Nenhum paciente cadastrado. \n");
        return; // Sai da função se não houver pacientes
    }

    // Solicita o nome a ser buscado
    printf("Digite o nome do paciente para buscar: ");
    fgets(nomeBusca, 100, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0; // Remove a nova linha do final da string

    printf("\n Resultados da busca para '%s':\n", nomeBusca);

    // Percorre a lista de pacientes e verifica se o nome contém a substring buscada
    for (int i = 0; i < totalPacientes; i++)
    {
        if (strstr(nomes[i], nomeBusca) != NULL) //
        {
            printf("%d: %s, %d anos \n", i + 1, nomes[i], idades[i]);
            printf("   Sintomas: %s\n", sintomas[i]);
            printf("----------------------------------------\n");
            encontrado = 1;
        }
    }

    // Se nenhum paciente foi encontrado, informa ao usuário
    if (!encontrado)
    {
        printf("Nenhum paciente encontrado com esse nome.\n");
    }

    printf("----------------------------------------\n");
}

// Função para verificar nomes duplicados
void verificacaoDuplicidade() {
    int i, j;
    int duplicadosEncontrados = 0;

    printf("\n--- Verificacao de Pacientes Duplicados ---\n");

    //Validação de duplicidade de nomes
    if (totalPacientes < 2) {
        printf("Nao ha pacientes suficientes para verificar duplicidade.\n");
        return;
    }

    for (i = 0; i < totalPacientes - 1; i++) {
        for (j = i + 1; j < totalPacientes; j++) {
            if (strcmp(nomes[i], nomes[j]) == 0) {
                printf("Nome duplicado encontrado: %s (Indices: %d e %d)\n", nomes[i], i + 1, j + 1);
                duplicadosEncontrados = 1;
            }
        }
    }

    if (!duplicadosEncontrados) {
        printf("Nenhum nome duplicado encontrado.\n");
    }

    printf("----------------------------------------\n");
}

void exibirMenu()
{
    printf("\n---> PROTUARIO ELETRONICO <---\n");
    printf("1. Cadastrar NOVO paciente\n");
    printf("2. Listar pacientes\n");
    printf("3. Ver detalhes de um paciente\n");
    printf("4. Buscar paciente por nome\n");
    printf("5. Verificar nomes duplicados\n");
    printf("0. Sair\n");
    printf("----------------------------------------");
}