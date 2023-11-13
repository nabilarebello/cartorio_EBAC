#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings = conjunto de vari�veis

int cadastro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	printf("DIGITE AS INFORMA��ES ABAIXO PARA CADASTRAR \n\n"); //Inclus�o de titulo para ficar visualmente melhor
	
	//in�cio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/strings
	
	printf("CPF: "); //coletando informa��o do cadastro
	scanf("%s",cpf); //var�avel que ir� salvar as informa��es (%s refere a string)
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores da string
	
	FILE *file; //criar arquivo
	file = fopen(arquivo, "w"); //criar arquivo "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //comando para abrir arquivo e atualizar "a" significa atualizar
	fprintf(file,","); //salva os dados com delimitador ","
	fclose(file); //fecha o arquivo
	
	printf("Nome: ");
	scanf("%s",nome); //var�avel que ir� salvar as informa��es de nome
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Sobrenome: ");
	scanf("%s",sobrenome); //var�avel que ir� salvar as informa��es de sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Cargo: ");
	scanf("%s",cargo); //var�avel que ir� salvar as informa��es de cargo
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausa para o usu�rio
	
}

int consulta() // Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF que seja consultar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //comando para abrir arquivo e ler "r"
	
	if(file == NULL) // se o resultado for nulo, retornar mensagem abaixo
	{
		printf("\n CPF n�o localizado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //vari�vel respons�vel por trazer as informa��es de forma separada
	{
		
		token = strtok(conteudo, ",");
		printf("Informa��es cadastradas para o CPF: %s\n\n", token);
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n\n", token);
			
	}
	
	system("pause");
	
}

int deletar() // Fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do cadastro que deseja deletar: ");
	scanf("%s",cpf);
	
	FILE *file; //acessar a fun��o "FILE" na biblioteca e acesse o parametro "file"=arquivo
	file = fopen(cpf,"r"); //"r" leia o arquivo
	fclose(file);
	
	if(file == NULL) // se o arquivo for igual a nulo
	{
		
		printf("\nCPF n�o cadastrado!\n\n");
		system("pause");
		
	 } 
	 
	 remove(cpf); //fun��o que ir� deletar o registro
	 
	 if(file != NULL) // se o arquivo for deletado
	{
		
		printf("\nCadastro deletado com sucesso!\n\n");
		system("pause");
		
	 } 
	 
}

int main()
{
	int opcao=0; //definindo var�aveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{

		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("*****  Cart�rio da EBAC  *****\n\n"); //in�cio do menu
		printf("Selecione a op��o desejada no MENU abaixo:\n\n");
		printf("\t1 - Cadastrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao);
	
		system("cls"); //respons�vel por limpar a tela
	
		switch(opcao) //in�cio da sele��o de op��es
		{
			case 1:
			cadastro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("At� logo!");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}
	}
}
