#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca que cuida da string

int registro(); // protótipo da função registrar
int consulta(); // protótipo da função consultar
int deletar();  // protótipo da função deletar
int login();    // protótipo da função login
void cadastrar_usuario(); // protótipo da função de cadastro de usuário

int main()
{
    int opcao = 0;
    int x = 1;

    while (1) {
        printf("Bem-vindo ao sistema! Escolha uma opção:\n");
        printf("1 - Login\n");
        printf("2 - Cadastrar novo usuário\n");
        printf("3 - Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                if (login() == 0) {
                    printf("Falha na autenticação. Tente novamente.\n");
                }
                break;
            case 2:
                cadastrar_usuario();
                break;
            case 3:
                printf("Saindo do sistema...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

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

void cadastrar_usuario()
{
    setlocale(LC_ALL, "Portuguese");

    char usuario[40];
    char senha[40];
    char confirma_senha[40];

    printf("### Cadastro de Novo Usuário ###\n\n");

    printf("Digite o nome de usuário: ");
    scanf("%s", usuario);

    printf("Digite a senha: ");
    scanf("%s", senha);

    printf("Confirme a senha: ");
    scanf("%s", confirma_senha);

    if (strcmp(senha, confirma_senha) != 0) {
        printf("As senhas não coincidem. Tente novamente.\n");
        return;
    }

    FILE *file;
    file = fopen("usuarios.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return;
    }

    fprintf(file, "%s,%s\n", usuario, senha);
    fclose(file);

    printf("Usuário cadastrado com sucesso!\n");
    system("pause");
}

int login()
{
    setlocale(LC_ALL, "Portuguese");

    char usuario[40];
    char senha[40];
    char linha[80];
    int autenticado = 0;

    printf("### Login no Sistema ###\n\n");

    printf("Digite o usuário: ");
    scanf("%s", usuario);

    printf("Digite a senha: ");
    scanf("%s", senha);

    FILE *file;
    file = fopen("usuarios.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return 0;
    }

    while (fgets(linha, sizeof(linha), file) != NULL) {
        char *user = strtok(linha, ",");
        char *pass = strtok(NULL, ",");

        // Removendo o \n do final da senha lida
        pass[strcspn(pass, "\n")] = 0;

        if (strcmp(usuario, user) == 0 && strcmp(senha, pass) == 0) {
            autenticado = 1;
            break;
        }
    }

    fclose(file);

    if (autenticado) {
        printf("Login bem-sucedido!\n");
        system("pause");
        return 1;
    } else {
        printf("Usuário ou senha incorretos!\n");
        return 0;
    }
}

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
    
    file = fopen(arquivo, "a"); // atualiza um arquivo já existente
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

	
	

	

