#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, "CPF: ");
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //cadastrando nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //cadastrando sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //cadastrando cargo
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausa a tela
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:"); //pedindo conteudo a ser consultado dentro do arquivo criado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //lendo o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, arquivo n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //mostrando as informa��es do arquivo
		printf("\n\n");
	}
	
	fclose(file); //fechando o arquivo
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		fclose(file);
		printf("o usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}	
	
	else if(file != NULL)
	{
		fclose(file);
		printf("o usu�rio foi deletado com sucesso!.\n");
		system("pause");
		remove(cpf); //deletando o usuario 
	}
	
	
}


int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("\t CART�RIO DA EBAC \n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls");
		for(laco=1;laco=1;)
		{
	
			system("cls"); //respons�vel por limpar a tela
			
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf("\t CART�RIO DA EBAC \n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Resgistrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Digite uma op��o:"); //fim do menu

			scanf("%d", &opcao); //armazenando a escolha do usu�rio

			system("cls");

			switch(opcao) //inicio das op��es
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consultar();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0; //fecha o sistema
				break;
			
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			
			} //fim das op��es
		
		}
	
	}
	
	else
		printf("Senha incorreta!");
	
	
	
}
