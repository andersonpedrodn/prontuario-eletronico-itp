#include <stdio.h>
#include <string.h>
void cadastrarPacientes();
void listarPacientes();
void exibirMenu();
void exibirDetalhePaciente();

#define maxPacientes 50

char nomes[maxPacientes][100];
int idades[maxPacientes];
char sintomas[maxPacientes][500];
int totalPacientes = 0;

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

void exibirMenu()
{
    printf("\n---> PROTUARIO ELETRONICO <---\n");
    printf("1. Cadastrar NOVO paciente\n");
    printf("2. Listar pacientes\n");
    printf("3. Ver detalhes de um paciente\n");
    printf("0. Sair\n");
    printf("----------------------------------------");
}