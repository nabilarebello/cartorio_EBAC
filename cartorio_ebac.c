#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings = conjunto de variáveis

int cadastro() // Função responsável por cadastrar os usuários no sistema
{
	printf("DIGITE AS INFORMAÇÕES ABAIXO PARA CADASTRAR \n\n"); //Inclusão de titulo para ficar visualmente melhor
	
	//início criaçõo de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criaçõo de variáveis/strings
	
	printf("CPF: "); //coletando informação do cadastro
	scanf("%s",cpf); //varíavel que irá salvar as informações (%s refere a string)
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores da string
	
	FILE *file; //criar arquivo
	file = fopen(arquivo, "w"); //criar arquivo "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //comando para abrir arquivo e atualizar "a" significa atualizar
	fprintf(file,","); //salva os dados com delimitador ","
	fclose(file); //fecha o arquivo
	
	printf("Nome: ");
	scanf("%s",nome); //varíavel que irá salvar as informações de nome
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Sobrenome: ");
	scanf("%s",sobrenome); //varíavel que irá salvar as informações de sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Cargo: ");
	scanf("%s",cargo); //varíavel que irá salvar as informações de cargo
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausa para o usuário
	
}

int consulta() // Função responsável por consultar os usuários no sistema
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
		printf("\n CPF não localizado! \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //variável responsável por trazer as informações de forma separada
	{
		
		token = strtok(conteudo, ",");
		printf("Informações cadastradas para o CPF: %s\n\n", token);
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n\n", token);
			
	}
	
	system("pause");
	
}

int deletar() // Função responsável por deletar os usuários no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do cadastro que deseja deletar: ");
	scanf("%s",cpf);
	
	FILE *file; //acessar a função "FILE" na biblioteca e acesse o parametro "file"=arquivo
	file = fopen(cpf,"r"); //"r" leia o arquivo
	fclose(file);
	
	if(file == NULL) // se o arquivo for igual a nulo
	{
		
		printf("\nCPF não cadastrado!\n\n");
		system("pause");
		
	 } 
	 
	 remove(cpf); //função que irá deletar o registro
	 
	 if(file != NULL) // se o arquivo for deletado
	{
		
		printf("\nCadastro deletado com sucesso!\n\n");
		system("pause");
		
	 } 
	 
}

int main()
{
	int opcao=0; //definindo varíaveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{

		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("*****  Cartório da EBAC  *****\n\n"); //início do menu
		printf("Selecione a opção desejada no MENU abaixo:\n\n");
		printf("\t1 - Cadastrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao);
	
		system("cls"); //responsável por limpar a tela
	
		switch(opcao) //início da seleção de opções
		{
			case 1:
			cadastro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Até logo!");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}
	}
}
