#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca que cuida das variaveis do tipo string
#include <sys/stat.h> // biblioteca que fornecera a possibilidade de criar diretorios
#include <windows.h> // biblioteca usada para mudar o tamanho dos frames na tela
#include <sys/types.h> // biblioteca para definicoes de tipos de dados, como o 'DIR' e o 'struct dirent' na funcao listaCPF
#include <dirent.h> // biblioteca usada para funcoes e estruturas de dados para manipulacao de diretorios como o 'opendir' e 'readdir'
#include <conio.h> // biblioteca usada para fornecer entrada/saida do console, usada no comando getch

int ESC() //function de saida com ESC
{
    printf("Pressione qualquer tecla para continuar. . .\n");
    printf("Pressione a tecla 'ESC' para voltar.\n\n");
    
    if (getch() == 27) // Le o caractere pressionado. 27 � o c�digo ASCII para a tecla "ESC"
	{
		system ("cls");
    	return 1; // Retorna 1 para indicar que o usu�rio deseja voltar ao menu caso pressione a tecla "ESC"
    } else {
    	system ("cls");
        return 0; // Se outra tecla for pressionada, sai da function
    }
}

void listaCPF() // function de listagem dos cpfs do sistema
{
    const char DIRREGS[] = "Alunos registrados"; // array que define o nome do nosso diretorio
    DIR *dir; // passa o valor de DIRREGS para o ponteiro dir, para nao haver conflito de tipos no codigo
    
    struct dirent *nav; // estrutura usada para a navegacao entre diretorios, recebe o ponteiro nav
	
	printf("\t-------------------------\n"); // linha meramente divisoria
	printf("\tRegistros do Sistema:\n\n");
	
    if ((dir = opendir(DIRREGS)) != NULL) // abre o diretorio se ele for diferente de NULL
    {
        while ((nav = readdir(dir)) != NULL) // navega no diretorio e le ele, ate ele ser NULL
        {
            if (strcmp(nav->d_name, ".") != 0 && strcmp(nav->d_name, "..") != 0)
            {
                printf("\t CPF: %s\n\n", nav->d_name); // imprime na tela todos os arquivos listados no diretorio
            }
        }
        closedir(dir); // fecha o diretorio
    }
    else // se o diretorio for NULL
    {
        printf("Erro ao abrir o diret�rio.\n"); 
    }
    
    printf("\t-------------------------"); // Linha meramente divisoria
}


int registro() // Fun��o de cadastro
{	
	//inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	const char DIRREGS[] = "Alunos registrados"; // constante DIRREGS que armazena o nome do diretorio que vai ser criado, no caso o que esta entre " ".
	//final da cria��o de variaveis/strings
	
	while (1)
	{
		system("cls"); // limpa a tela
		
		printf("\t--- Registro de Nomes ---\n\n"); // mensagem na tela
		
		if (ESC()) // chama a function ESC
		{
	        return 0; // Volta ao menu principal
	    }
	 
	    printf("\t--- Registro de Nomes ---\n\n"); // mensagem na tela
	    
		printf("Digite o CPF a ser cadastrado: "); // pergunta direcionada ao usuario
		scanf("%s",cpf); // armazena a resposta na string cpf com o %s
	
		strcpy(arquivo, cpf); // Copia os valores das strings (o nome do arquivo vai ser o valor de cpf)
		
		FILE *file; // cria o arquivo (comando FILE do sistema entrando em contato com nosso file)
		mkdir(DIRREGS); // cria uma pasta com o nome alunos registrados
		
		sprintf(arquivo, "%s/%s", DIRREGS, cpf); // cria o caminho para nosso diretorio
		
			file = fopen(arquivo, "w"); // cria o arquivo (o "w" significa que esta sendo escrito, write o valor da variavel no arquivo), nomeia ele
			fprintf(file,"%s\n",cpf); // salva o valor da variavel no arquivo, no caso cpf."%s\n" serve para pular uma linha na escrita dentro do file
			fclose(file); // fecha o arquivo
			
		printf("Digite o Nome que deseja cadastrar:  "); // pergunta direcionada ao usuario
		scanf("%s", nome); // armazena a resposta na string nome
		
			file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informa��o nele "a"
			fprintf(file,"%s\n",nome); // salva o valor da variavel no arquivo, no caso nome."%s\n" serve para pular uma linha na escrita dentro do file
			fclose(file); // fecha o arquivo
			
		printf("Digite o Sobrenome que deseja cadastrar:  "); // pergunta direcionada ao usuario
		scanf("%s", sobrenome); // armazena a resposta na string sobrenome
		
			file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informa��o nele "a"
			fprintf(file,"%s\n",sobrenome); // salva o valor da variavel no arquivo, no caso sobrenome."%s\n" serve para pular uma linha na escrita dentro do file
			fclose(file); // fecha o arquivo
		
		printf("Digite o Cargo que deseja cadastrar:  "); // pergunta direcionada ao usuario
		scanf("%s", cargo); // armazena a resposta na string cargo
		
			file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informa��o nele "a"
			fprintf(file,"%s",cargo); // salva o valor da variavel no arquivo, no caso cargo."%s\n" serve para pular uma linha na escrita dentro do file
			fclose(file);// fecha o arquivo
		
		printf("\n- Suas informa��es foram salvas com sucesso! -\n\n");
		
		printf("\n  Pressione ESC para sair");
		printf("\n  Pressione qualquer tecla para continuar. . .");
		
		if (getch() == 27)
		{
			break;
		}else
		{
			continue;
		}
			
		system("pause");
	}
}

int consulta() // Fun��o de consulta
{
	//inicio da cria��o de variaveis/strings
	char cpf[40]; // indicando a variavel cpf que foi usada em registroo
	//final da cria��o de variaveis/strings
	
	while(1)
	{
		system ("cls"); // limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // reconhece o uso de acentos na digita��o
		
		printf("\t--- Consulta de Nomes ---\n\n");
		
		if (ESC()) // chama a function ESC
		{
	        return 0; // Volta ao menu principal
	    }
		
		printf("\t--- Consulta de Nomes ---\n\n");
		
		listaCPF();
		
		printf("\n\nDigite o cpf a ser consultado:  "); // pergunta direcionada ao usuario
		scanf("%s",cpf); // armazena a resposta na string cpf 
	
			// citando as strings do diretorio para o consulta
			char arquivo[40]; // variavel que armazena o nome do nosso arquivo, que � igual o cpf
			const char DIRREGS[] = "Alunos registrados"; // constante que define o nome do nosso diretorio
		
			FILE *file; // comando FILE do sistema entrando em contato com nosso file
			sprintf(arquivo, "%s/%s", DIRREGS, cpf); // mostra o caminho para o arquivo
			file = fopen(arquivo,"r"); // procura um arquivo com o mesmo valor da string (arquivo = cpf) e l� ela "r", read
	
		if (file != NULL) // se o arquivo existir, faca isso
		{
			while (1) // abre o arquivo e executa o loop e mostra todas as linhas do arquivo
			{
				char line [40]; // linha que vai trazer as informa��es do arquivo para tela. Tem o mesmo tamanho do arquivo
				
				system("cls");
			
				printf("\nEssas s�o as informa��es do usu�rio:\n\n");
			
				printf("\t CPF: %s\n", fgets(line, 40, file)); // mostra na tela o cpf do usuario pesquisado
		        printf("\t Nome: %s\n", fgets(line, 40, file)); // mostra na tela o nome do usuario pesquisado
		        printf("\t Sobrenome: %s\n", fgets(line, 40, file)); // mostra na tela o sobrenome do usuario pesquisado
		        printf("\t Cargo: %s\n", fgets(line, 40, file)); // mostra na tela o cargo do usuario pesquisado
		        
		        break; // sai do loop
			}
		}
		else // caso o arquivo nao exista, faca isso
		{
			system("cls");
			printf("ERRO Arquivo n�o localizado\n\n");
		}
		
		fclose(file); // fecha o arquivo
		
		printf("\n  Pressione ESC para sair");
		printf("\n  Pressione qualquer tecla para continuar. . .");
		
		if (getch() == 27) 
		{
			break;
		}
		else
		{
			continue;
		}
	
	   	system("pause");
	}
}

int deletar() // fun��o para deletar
{	
	//inicio da cria��o de variaveis/strings
	char cpf[40]; // indicando a variavel cpf que foi usada em registro
	int menu=3; // variavel responsavel por armazenar a escolha se o usuario quer voltar ao menu ou nao
	//final da cria��o de variaveis/strings
	
	while(1)
	{	
		system ("cls"); // limpa a tela
		
		printf("\t--- Deletar Nomes ---\n\n"); // mensagem na tela
		
		if (ESC()) // chama a function ESC
		{
	        return 0; // Volta ao menu principal
	    }
	    
		printf("\t--- Deletar Nomes ---\n\n"); // mensagem na tela
		
		listaCPF();
		
		printf("\n\nDigite o CPF do Usu�rio que deseja deletar:  \n"); // pergunta direcionada ao usuario
	 	scanf("%s", cpf); // armazena a resposta na string cpf
	 	
	 		// citando as strings do diretorio para o consulta
			char arquivo[40];
			const char DIRREGS[] = "Alunos registrados";
		
			FILE *file; // comando FILE do sistema entrando em contato com nosso file
			sprintf(arquivo, "%s/%s", DIRREGS, cpf); // mostra o caminho para o arquivo
		 	file = fopen(arquivo, "r"); // procura um arquivo com o mesmo valor da string (arquivo = cpf) e l� ela "r", read
	 	
	 	if (file == NULL) // se o arquivo n�o existir
		{
			system ("cls");
	        printf("\nO usu�rio n�o se encontra no sistema.\n\n");
	    } 
		else // caso exista
		{
	        fclose(file); // fecha o arquivo
	        remove(arquivo); // apaga o arquivo
	        printf("\nUsu�rio deletado com sucesso!\n\n");
		}
		
		printf("\n  Pressione ESC para sair");
		printf("\n  Pressione qualquer tecla para continuar. . .");
		
		if (getch() == 27) 
		{
			break;
		}
		else
		{
			continue;
		}
	
		system("pause");
	}
}

int menu() //funcao principal que define o menu do projeto
{
	int opcao=0; //variavel de escolha no menu
	int laco=1; //variavel de looping do for no menu
	
	for (laco=1;laco=1;) //laco de repeticao do menu "enquanto laco for 1 faca ate laco for 1"
	{ 
		system("cls"); //limpa a tela

		printf("\tCart�rio dos alunos EBAC \n\n"); // mensagens ao usuario
		printf("--- Escolha a op��o desejada no menu: --- \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t0 - Sair da conta\n\n\n");
		printf("\tOp��o: ");
				
		scanf("%d", &opcao); //armazenamento da escolha do usuario na variavel opcao

		system("cls"); // limpa a tela

		switch(opcao) //analise da escolha do usuario, para tomar uma decis?o
		{

		case 1: //caso o usuario tenha escolhido 1
		registro(); // chamada de funcoes
	   	break;

		case 2: //caso o usuario tenha escolhido 2
		consulta(); // chamada de funcoes
	   	break;

	   	case 3: //caso o usuario tenha escolhido 3
	   	deletar(); // chamada de funcoes
	   	break;

	  	case 0: //caso o usuario tenha escolhido 0
	   	printf("\nSaindo...\n\n");
	  	system("pause");
	   	return 0; // volta para a tela de login
	   	break;

	   	default: // caso o usuario tenha escolhido qualquer coisa diferente das opcoes apresentadas
	   	printf("Escolha invalida\n");
	   	system("pause"); //pausa a execucao do programa ate uma interacao
	   	break;

    	} //fim da selecao
   	} // fim do for menu	
} // fim do menu
 
 
// constantes que definem o tamanho maximo para informacoes pedidas.
#define MAX_LOGIN 20 // login corresponde ao tamanho do username e password
#define MAX_EMAIL 40
#define MAX_TELL 20
 
 typedef struct { // estrutura que junta as variaveis declaradas em uma unica "entidade", facilitando a manipulcao dos dados no codigo. typedef pois simplifica a declaracao das variveis
    char username[MAX_LOGIN]; // membro da struct. (recebem como parametro as constantes do define, o que indica que seu tamanho maximo e 20)
    char email[MAX_EMAIL]; // membro da struct.
    char  tell[MAX_TELL]; // membro da struct.
    char password[MAX_LOGIN]; // membro da struct.
} Usuario; // nome dado a struct, quando quisermos citar os membros basta apenas mencionar o nome da struct, no caso Usuario

int criarUser(Usuario *user) // funcao usada para a cria��o do usuario. Tem como parametro um ponteiro, o qual atribui a user os valores da struct, incluindo assim seus membros dentro da funcao por meio do user
{ 
	char userfile[160]; // string que vamos salvar as informa��es do usuario no sistema, e a nossa primare key
	const char DIRUSER[] = "Usuarios do sistema"; // constante DIRUSER que armazena o nome do diretorio que vai ser criada, no caso o que esta entre " ".
		
	system ("cls");
	
	setlocale(LC_ALL, "Portuguese"); //define que a linguagem e o portugues, de acordo com a biblioteca
	
	printf("\tCriar novo usu�rio\n\n");
	
	if (ESC()) // chama a function ESC
	{
        return 0; // Volta ao menu principal
    }
    
	printf("\tCriar novo usu�rio\n\n");
	
	while(1) // looping de valida��o dos caracteres digitados. Caso ele ache algo que n�o atende as condicoes, reinicia o loop. 1 pois e verdadeiro, logo um loop infinito
	{
	    printf("Digite um nome de usu�rio: "); // citando a constante pois e usada para mostrar os caracteres
	    scanf("%s", user->username); // atribui a username, que e membro de User(que tem como ponteiro user. esta atrib). E um ponteiro portanto esta sendo usado "->"
	    
	    	if (strlen(user->username) >MAX_LOGIN) // strlen verifica o tamanho de uma string, esta verificando se o que digitamos respeita a constante
			{
				printf("\nERRO. Nome de usu�rio muito grande (m�ximo %d caracteres).\n\n", MAX_LOGIN);
				system("pause");
				continue; // reinicia o loop
			}
			
		break; // caso nao seja posto nenhuma inconformidade, o loop � quebrado e o codigo da sequencia
	}
	while(1)
	{
		printf("Digite uma senha: ");
	    scanf("%s", user->password);
	    		
	    	if (strlen(user->password) >MAX_LOGIN) // strlen verifica o tamanho de uma string, esta verificando se o que digitamos respeita a constante
			{
				printf("\nERRO. Senha muito grande (m�ximo %d caracteres).\n\n", MAX_LOGIN);
				system("pause");
				continue; // reinicia o loop
			}
			
		break;
	}
	while(1)
	{
		printf("Digite seu email: ");
		scanf("%s", user->email);
		
			if (strlen(user->email) >MAX_EMAIL) // strlen verifica o tamanho de uma string, esta verificando se o que digitamos respeita a constante
			{
				printf("\nERRO. Email muito grande (m�ximo %d caracteres).\n\n", MAX_EMAIL);
				system("pause");
				continue; // reinicia o loop
			}
			
		break;
	}
	while(1)
	{
		printf("Digite seu telefone de contato: ");
		scanf("%s", user->tell);
		
			if (strlen(user->tell) >MAX_TELL) // strlen verifica o tamanho de uma string, esta verificando se o que digitamos respeita a constante
			{
				printf("\nERRO. Telefone muito grande (m�ximo %d caracteres).\n\n", MAX_TELL);
				system("pause");
				continue; // reinicia o loop
			}

		break;
	}


	// inicio do registro dos dados no sistema
	
		strcpy (userfile, user->username); // copia o valor do nome do usuario e atribui a userfile, para assim nomear o doc, mesmo processo do registro
	
		FILE *file; // (comando FILE que serve para manipulacao de arquivos, tem o ponteiro file)
		mkdir(DIRUSER); // cria uma pasta com nome de usuarios do sistema
	
		sprintf(userfile, "%s/%s", DIRUSER, user->username); // cria um caminho completo para o arquivo, colocando com a primare key, dentro da pasta do DIRUSER. "%s/%s" cita o diretorio no sistema.

			file = fopen(userfile, "w"); // cria o arquivo e nomeia com o valor de userfile, o qual tem os valores de username
			fprintf(file, "%s\n", user->username); // escreve dentro do arquivo os valores de userfile, o "%s\n" serve para pular uma linha na escrita dentro do file
			fclose(file); // fecha o arquivo
		
			file = fopen(userfile, "a");
    		fprintf(file, "%s\n", user->password);
    		fclose(file);
    		
    		file = fopen(userfile, "a");
			fprintf(file, "%s\n", user->email);
			fclose(file);
	
			file = fopen(userfile, "a");
			fprintf(file, "%s\n", user->tell);
			fclose(file);			
		

    printf("\nUsu�rio criado com sucesso!\n\n");
	system("pause");
    
} // fim cadastro

int login(Usuario *user) // funcao de login
{
	// variaveis requeridas ara fazer o login no sistema
    char username[MAX_LOGIN];
    char password[MAX_LOGIN];
	
	system ("cls");
	
	setlocale(LC_ALL, "Portuguese"); //define que a linguagem e o portugues, de acordo com a biblioteca
	
    printf("\tLogin\n\n");
    
    if (ESC()) // chama a function ESC
	{
        return 1; // Volta ao menu principal
    }
    
    printf("\tLogin\n\n");

    printf("Nome de usu�rio: ");
    scanf("%s", username); // armazena o nome do usuario
    
    printf("Senha: ");
    scanf("%s", password); // armazena a senha do usuario

	// declaracao das variaveis de arquivo e diretorio do cadastro
    char userfile[160];
    const char DIRUSER[] = "Usuarios do sistema";

    sprintf(userfile, "%s/%s", DIRUSER, username); // monta o caminho completo para o arquivo
    FILE *file = fopen(userfile, "r"); // abre o arquivo userfile criado em cadastro no modo leitura "r"

    if (file) 
	{
        char line[MAX_LOGIN]; // variavel para armazenar cada linha lida

        // le a primeira linha do arquivo (username)
        fgets(line, sizeof(line), file); // fgets: armazena em line, a quantidade de caracteres do tamanho de line, o conteudo de file. o tamanho � o MAX_LOGIN, mencionado pela expressao sizeof(line), que diz basicamento "o tamanho de ( )"

        // apos armazenar, remove a quebra de linha "\n" do final da string
        line[strcspn(line, "\n")] = '\0'; // strcsp ta percorrendo line ate achar o \n e anulando ele

        // Verifica se o nome de usuario e valido com uma comparacao
        if (strcmp(line, username) != 0) // compara o line sem o \n com o que digitamos, e se for diferente de zero, retorna invalido
		{
			printf("Falha no Login!\n"); // caso invalido
            printf("Nome de usu�rio inv�lido!\n"); 
            fclose(file); // fecha o arquvo lido
            system("pause");
            return 1;
        }

        // le a segunda linha do arquivo (password)
        fgets(line, sizeof(line), file);
        
        // apos armazenar, remove a quebra de linha "\n" do final da string
        line[strcspn(line, "\n")] = '\0'; 

        // verifica se a senha e valida com uma comparacao
        if (strcmp(line, password) != 0) 
		{
			printf("Falha no Login!\n"); // caso invalido
            printf("Senha inv�lida!\n");
            fclose(file); // fecha o arquvo lido
            system("pause");
            return 1;
        }

        printf("Login bem-sucedido!\n"); // caso as comparacoes tenham sido iguais aos caracteres digitados
        printf("Bem-vindo, %s!\n", username); // mostra o valor de username, que e membro de user, e esta usando seus valores
        fclose(file); // fecha o arquivo lido
        system("pause");
        return 0;
    } 
	else // caso nao ache um arquivo com nenhuma das informacoes digitadas
	{
        printf("Usu�rio n�o encontrado!\n");
        system("pause");
        return 1;
    }
}

int main() {
	
// O c�digo obt�m as informa��es da fonte atual, modifica a largura e altura e define a nova fonte no console.
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
CONSOLE_FONT_INFOEX fontInfo;
fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
fontInfo.dwFontSize.X = 14; // Definicao da largura da fonte
fontInfo.dwFontSize.Y = 24; // Definicao da altura da fonte 

// Coloca o novo tamanho da fonte
SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
	
	// declaracao variaveis
    Usuario user; // declaracao de Usuario user para atalhos das outras funcoes
    int loop; // variavel de looping do for na tentativa da senha
	char senha[ ]="a"; // string da senha de login
    int opcao2; // variavel da escolha
    
	for (loop=0;loop<3;loop++) // loop exectara 3 vezes, dando 3 tentativas para o usuario acertar a senha "admin"
	{	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //define que a linguagem ? o portugues, de acordo com a biblioteca

		printf("\tCart�rio dos alunos EBAC \n\n");
		printf("\tLogin ADMIN\n\n");
		printf("\tDigite a senha:  ");
		scanf("%s", senha); // armazena a responta na variavel senha
			
		if (strcmp (senha, "admin") !=0) // comparacao da string senha com "admin", caso seja diferente de verdadeiro, � invalida 
		{	
			system("cls");	
			printf("\n\tSenha inv�lida, tente novamente.\n\n");
			system("pause");
			system("cls");
		}
		
		else // caso outra coisa (seja verdadeira) entramos no sistema 
		{
			while(1) // loop
			{
				system("cls");
			
				setlocale(LC_ALL, "Portuguese"); //define que a linguagem ? o portugues, de acordo com a biblioteca
				
		    	printf("\tBem-vindo ao Cart�rio EBAC\n\n");
		
		    	printf("\t1. Cadastrar-se\n");
			    printf("\t2. Fazer login\n");
			    printf("\t3. Sair\n\n");
			
			    printf("\tEscolha uma op��o: ");
			    scanf("%d", &opcao2); // atribui a escolha do usuario a opcao2
			
			    switch (opcao2) // analisa a variavel opcao2 e toma uma decisao
				{ 
			    
			        case 1:
			            criarUser(&user); // leva ate a criacao de conta
			            break;
			            
			        case 2:
			            if (login (&user)== 0) { // leva a funcao login e faz a validacao de se caso o programa retorne 0, valor que login so retorna caso seja um login bem sucedido, o login no sistema tem exito
			                menu(); // leva ate o menu principal
			            } 
			            break;
			        case 3: //caso o usuario tenha escolhido 3
				   				printf("\nObrigado por usar o sistema!\n\n");
				   				return 0; // fecha o programa, retorna 0
				   				break;
			        default:
			        	system("cls");
			            printf("Op��o inv�lida.\n"); // caso escolha algo diferente, resulta em invalido
			            system("pause");
			            break;
		  		}
			}
		} // fim do else senha
	} // fim do loop de tentativas da senha

		printf("\n\nNumero m�ximo de tentativas atingido!\n\n"); // caso tenha atingido o maximo de tentativas
					system("pause");
					return 0;
					
} // fim da funcao main

