#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de caracteres especiais
#include <locale.h> // alocacao de texto por regiao
#include <string.h> // biblioteca responsavel por cuidar dos strings

void registro() //funcao responsavel por cadastrar os usuarios no sistema
{
    //inicio criacao de variaveis/strings (string:conjunto de variaveis) 
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criacao das variaveis

    printf("Digite o CPF a ser cadastrado: \n"); //coletando info dos usuarios
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); // responsavel por copiar os valores das strings

    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
    fprintf(file, "%s,", cpf);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    file = fopen(arquivo, "a");
    printf("Digite um nome a ser cadastrado: \n");
    scanf("%s", nome);
    fprintf(file, "%s,", nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    file = fopen(arquivo, "a");
    printf("Digite o Sobrenome a ser cadastrado: \n");
    scanf("%s", sobrenome);
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    file = fopen(arquivo, "a");
    printf("Digite o Cargo a ser cadastrado: \n");
    scanf("%s", cargo);
    fprintf(file, "%s\n", cargo);
    fclose(file);
}

void consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: \n");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Não foi possível localizar o arquivo.\n");
        return;
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\n Essas são as informações do usuário: \n");
        printf("%s", conteudo);
        printf("\n\n");
    }

    fclose(file);
}

void deletar()
{
    char cpf[40];
    printf("Digite o CPF a ser deletado: \n");
    scanf("%s", cpf);

    if (remove(cpf) == 0)
    {
        printf("Arquivo deletado com sucesso.\n");
    }
    else
    {
        printf("Erro ao deletar o arquivo.\n");
    }
}

int main()
{
    int opcao = 0;

    while (1)
    {
        system("clear");

        setlocale(LC_ALL, "Portuguese"); // define a linguagem

        printf("### Cartorio da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu:\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n");

        printf("Esse Software é de livre uso dos alunos\n");

        scanf("%d", &opcao);

        system("clear");

        switch (opcao)
        {
        case 1:
            printf("Você escolheu registro de nomes.\n");
            registro();
            break;

        case 2:
            printf("Você escolheu consultar nomes.\n");
            consulta();
            break;

        case 3:
            printf("Você escolheu deletar nomes.\n");
            deletar();
            break;

        case 4:
            printf("Saindo do programa.\n");
            return 0;

        default:
            printf("Essa opção não está disponível. Tente novamente.\n");
            break;
        }

        printf("\n");
        system("read -n 1 -s -r -p 'Pressione qualquer tecla para continuar...'"); // Aguarda uma tecla ser pressionada
    }

    return 0;
}
