#include <stdio.h>
#include <string.h>
void cadastrarPacientes();
void listarPacientes();
void exibirMenu();
void exibirDetalhePaciente();
void buscarPacientePorNome();
void verificacaoDuplicidade();

#define maxPacientes 50 
#define n_questoes 9 // Numero de questoes do PHQ-9

char nomes[maxPacientes][100];
int idades[maxPacientes];
char sintomas[maxPacientes][500];
int totalPacientes = 0;
int phq9_respostas[maxPacientes][n_questoes]; // Matriz para armazenar respostas do PHQ-9

int main()
{
    int opcoes;

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

    return 0;
}

void cadastrarPacientes()
{
    if (totalPacientes < maxPacientes)
    {
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

        totalPacientes++;
        printf("\n PACIENTE CADASTRADO COM SUCESSO! \n");
    }
    else
    {
        printf("\n Limite máximo de paciente atingidos!\n");
    }
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
        printf("--------------------------------------------");
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