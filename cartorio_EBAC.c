#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca que cuida da string

int registro() // função registrar os usuários
{
    // início criação usuário
    setlocale(LC_ALL, "Portuguese");
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // responsável por copiar os valores das strings
    
    FILE *file; // cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // cria o arquivo
    fprintf(file, cpf); // salva o valor da variável
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // atuaaliza um arquivo já existente
    fprintf(file, ",");
    
    printf("Digite um nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    printf("Digite um sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fprintf(file, sobrenome);
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fprintf(file, cargo);
    fclose(file);
    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL)
    {
        printf("Seu arquivo não foi localizado");
    }
    
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário:  ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system("pause");
    
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (remove(cpf) == 0) {
        printf("O usuário foi deletado com sucesso\n");
    }
    else {
        printf("O usuário não se encontra no sistema\n");
    }
    system("pause");
}

int main()
{
    int opcao = 0;
    int x = 1;
    for (x = 1; x == 1;)
    {
        system("cls");
        setlocale(LC_ALL, "Portuguese");
        
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n"); 
        
        scanf("%d", &opcao);
    
        system("cls");
        
        switch(opcao) {
            case 1:
                registro();
                break;
            
            case 2:
                consulta();
                break;
            
            case 3:
                deletar();
                break;

            case 4:
                printf("Saindo do sistema...\n");
                x = 0; 
                break;
            
            default:
                printf("Você digitou um número inválido\n");
                system("pause");
                break;
        }
    }
    
    return 0; 
}

	
	

	

