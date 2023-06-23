#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca que cuida das variaveis do tipo string

int registro() // Fun��o de cadastro
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/strings
	
	printf("\t--- Registro de Nomes ---\n\n"); // mensagem na tela 
	
	printf("Digite o CPF a ser cadastrado: "); // pergunta direcionada ao usuario
	scanf("%s",cpf); // armazena a resposta na string cpf com o %s
	
	strcpy(arquivo, cpf); // Copia os valores das strings (o nome do arquivo vai ser o valor de cpf)
	
	FILE *file; // cria o arquivo (comando FILE do sistema entrando em contato com nosso file)
	file = fopen(arquivo, "w"); // cria o arquivo (o "w" significa que esta sendo escrito, write o valor da variavel no arquivo)
	fprintf(file,cpf); // salva o valor da variavel no arquivo, no caso cpf
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informa��o nele "a"
	fprintf(file,", "); // escreve dentro do arquivo o que estiver entre " "
	fclose(file); // fecha o arquivo
	
	printf("Digite o Nome que deseja cadastrar:  "); // pergunta direcionada ao usuario
	scanf("%s", nome); // armazena a resposta na string nome
	
	file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informa��o nele "a"
	fprintf(file,nome); // salva o valor da variavel no arquivo, no caso nome
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informa��o nele "a"
	fprintf(file,", "); // inserindo outra virgula
	fclose(file); // fecha o arquivo
	
	printf("Digite o Sobrenome que deseja cadastrar:  "); // pergunta direcionada ao usuario
	scanf("%s", sobrenome); // armazena a resposta na string sobrenome
	
	file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informa��o nele "a"
	fprintf(file,sobrenome); // salva o valor da variavel no arquivo, no caso sobrenome
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informa��o nele "a"
	fprintf(file,", "); // inserindo outra virgula
	fclose(file); // fecha o arquivo
	
	printf("Digite o Cargo que deseja cadastrar:  "); // pergunta direcionada ao usuario
	scanf("%s", cargo); // armazena a resposta na string cargo
	
	file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informa��o nele "a"
	fprintf(file,cargo); // salva o valor da variavel no arquivo, no caso cargo
	fclose(file);// fecha o arquivo
	
	printf("\n\n- Suas informa��es foram salvas com sucesso! -\n\n");
	
	system("pause");
}

int consulta() // Fun��o de consulta
{
	//inicio da cria��o de variaveis/strings
	char cpf[40]; // indicando a variavel cpf que foi usada em registro
	char conteudo[200]; // variavel que vai coletar o conteudo do arquivo e mostr� lo
	//final da cria��o de variaveis/strings
	
	setlocale(LC_ALL, "Portuguese"); // reconhece o uso de acentos na digita��o
		
	printf("\t--- Consulta de Nomes ---\n\n"); // mensagem na tela
	
	printf("Digite o cpf a ser consultado:  "); // pergunta direcionada ao usuario
	scanf("%s",cpf); // armazena a resposta na string cpf 
	
	FILE *file; // comando FILE do sistema entrando em contato com nosso file
	file = fopen(cpf,"r"); // procura um arquivo com o mesmo valor da string e l� ela "r", read
	
	if (file == NULL) // valida��o se caso n�o for encontrado um arquivo com o valor da string
	{
		printf("Arquivo n�o localizado.\n\n"); // mensagem direcionada ao usuario indicando que o valor digitado n�o existe
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Salva 200 variaveis que estiverem dentro do arquivo para a string conteudo, e para de quando for NULL a quantia de variaveis dentro
	{
		printf("\nEssas s�o as informa��es do usu�rio:  "); // mensagem ao usuario
		printf("%s", conteudo); // mostra ao usuario os valores salvos na string conteudo, o que estiver no arquivo consultado
		printf("\n\n");
	}
	
   	system("pause");
}

int deletar() // fun��o para deletar
{		
	char cpf[40]; // indicando a variavel cpf que foi usada em registro
	
	printf("\t--- Deletar Nomes ---\n\n"); // mensagem na tela
	printf("Digite o CPF do Usu�rio que deseja deletar:  \n"); // pergunta direcionada ao usuario
 	scanf("%s", cpf); // armazena a resposta na string cpf
 	
 	remove(cpf); // fun��o adicionada pelas bibliotecas que apagar o valor de determinada variavel, no caso a string cpf
 	
 	FILE *file; // comando FILE do sistema entrando em contato com nosso file
 	file = fopen(cpf, "r"); // procura um arquivo com o mesmo valor da string e l� ela "r", read
 	
 	if (file == NULL) // valida��o se caso n�o for encontrado um arquivo com o valor da string
 	{
 		printf("O usu�rio n�o se encontra no sistema.\n\n"); // mensagem direcionada ao usuario indicando que o valor digitado n�o existe
 		system("pause"); 
	}
}

int main() //fun��o principal que define o menu do projeto
{
	int opcao=0; //variavel de escolha no menu
	int laco=1; //variavel de looping do for
	
	for (laco=1;laco=1;) //la�o de repeti��o do menu "enquanto laco for 1 fa�a ate laco for 1"
	{ 
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //define que a linguagem � o portugues, de acordo com a biblioteca
	
		printf("\tCart�rio dos alunos EBAC \n\n"); // mensagens ao usuario
		printf("--- Escolha a op��o desejada no menu: --- \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n\n");
		printf("\tOp��o: ");	
	
		scanf("%d", &opcao); //armazenamento da escolha do usu�rio na variavel opcao
	
		system("cls"); // limpa a tela
		
		switch(opcao) //analise da escolha do usuario, para tomar uma decis�o
		{
			
		case 1: //caso o usuario tenha escolhido 1
		registro(); // chamada de fun��es
   		break;
   		
   		case 2: //caso o usuario tenha escolhido 2
   		consulta(); // chamada de fun��es
   		break;
   		
   		case 3: //caso o usuario tenha escolhido 3
   	
   		deletar(); // chamada de fun��es
   		break;
   		
   		default: //caso o usuario tenha escolhido qualquer coisa diferente das apresentadas
   		printf("Escolha invalida\n");
   		system("pause"); //pausa a execu��o do programa at� uma intera��o
   		break;
   		
    	} //fim da sele��o
    }
}
