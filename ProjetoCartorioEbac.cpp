#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca que cuida das variaveis do tipo string
#include <sys/stat.h> // biblioteca que fornecera a possibilidade de criar diretorios
#include <windows.h> // biblioteca usada para mudar o tamanho dos frames na tela

int registro() // Função de cadastro
{
	//inicio da criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int menu=3; // variavel responsavel por armazenar a escolha se o usuario quer voltar ao menu ou nao
	const char DIRREGS[] = "Alunos registrados"; // constante DIRREGS que armazena o nome do diretorio que vai ser criado, no caso o que esta entre " ".
	//final da criação de variaveis/strings
	
	system("cls"); // limpa a tela
	
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
	
		file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informação nele "a"
		fprintf(file,"%s\n",nome); // salva o valor da variavel no arquivo, no caso nome."%s\n" serve para pular uma linha na escrita dentro do file
		fclose(file); // fecha o arquivo
		
	printf("Digite o Sobrenome que deseja cadastrar:  "); // pergunta direcionada ao usuario
	scanf("%s", sobrenome); // armazena a resposta na string sobrenome
	
		file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informação nele "a"
		fprintf(file,"%s\n",sobrenome); // salva o valor da variavel no arquivo, no caso sobrenome."%s\n" serve para pular uma linha na escrita dentro do file
		fclose(file); // fecha o arquivo
	
	printf("Digite o Cargo que deseja cadastrar:  "); // pergunta direcionada ao usuario
	scanf("%s", cargo); // armazena a resposta na string cargo
	
		file = fopen(arquivo, "a"); // abre o arquivo e atualiza uma informação nele "a"
		fprintf(file,"%s",cargo); // salva o valor da variavel no arquivo, no caso cargo."%s\n" serve para pular uma linha na escrita dentro do file
		fclose(file);// fecha o arquivo
	
	printf("\n- Suas informações foram salvas com sucesso! -\n\n");
	
	printf("\nDeseja cadastrar mais usuários?\n\n"); // caso o usuario queira cadastrar mais usuarios ou voltar ao menu
	printf("\t1 - Sim\n");
	printf("\t2 - Não\n");
	scanf("%d", &menu); // atribui a escolha a variavel menu
	
	switch(menu)
	{
		case 1:
		registro(); // volta novamente ao registro
		break;
		
		case 2:
		return 0; // retorna ao menu
		break;
		
		default:
		printf("\nescolha inválida\n"); // caso o usuario tenha escolhido qualquer coisa diferente das opcoes apresentadas
		break;
	}
	
	system("pause");
}

int consulta() // Função de consulta
{
	//inicio da criação de variaveis/strings
	char cpf[40]; // indicando a variavel cpf que foi usada em registro
	char conteudo[200]; // variavel que vai coletar o conteudo do arquivo e mostra lo
	int menu=3; // variavel responsavel por armazenar a escolha se o usuario quer voltar ao menu ou nao
	//final da criação de variaveis/strings
	
	system ("cls"); // limpa a tela
	
	setlocale(LC_ALL, "Portuguese"); // reconhece o uso de acentos na digitação
		
	printf("\t--- Consulta de Nomes ---\n\n"); // mensagem na tela
	
	printf("Digite o cpf a ser consultado:  "); // pergunta direcionada ao usuario
	scanf("%s",cpf); // armazena a resposta na string cpf 
	printf("\nEssas são as informações do usuário:\n");
	
		// citando as strings do diretorio para o consulta
		char arquivo[40];
		const char DIRREGS[] = "Alunos registrados";
	
		FILE *file; // comando FILE do sistema entrando em contato com nosso file
		sprintf(arquivo, "%s/%s", DIRREGS, cpf); // mostra o caminho para o arquivo
		file = fopen(arquivo,"r"); // procura um arquivo com o mesmo valor da string (arquivo = cpf) e lê ela "r", read
	
	if (file == NULL) // validação se caso não for encontrado um arquivo com o valor da string
	{
		printf("\n\tArquivo não localizado.\n"); // mensagem direcionada ao usuario indicando que o valor digitado não existe
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Salva 200 variaveis que estiverem dentro do arquivo para a string conteudo, e para de quando for NULL a quantia de variaveis dentro
	{
		printf("\n\t| "); // mensagem ao usuario, entrega as informações
		printf("%s", conteudo); // mostra ao usuario os valores salvos na string conteudo, o que estiver no arquivo consultado
		printf("\n\n");
	}
	
	fclose(file); // fecha o arquivo
	
	printf("\nDeseja consultar mais usuários?\n\n"); // caso o usuario queira consultar mais usuarios ou voltar ao menu
	printf("\t1 - Sim\n");
	printf("\t2 - Não\n");
	scanf("%d", &menu); // atribui a escolha a variavel menu
	
	switch(menu)
	{
		case 1:
		consulta(); // volta novamente ao registro
		break;
		
		case 2:
		return 0; // retorna ao menu
		break;
		
		default:
		printf("\nescolha inválida\n"); // caso o usuario tenha escolhido qualquer coisa diferente das opcoes apresentadas
		break;
	}
	
   	system("pause");
}

int deletar() // função para deletar
{	
	//inicio da criação de variaveis/strings
	char cpf[40]; // indicando a variavel cpf que foi usada em registro
	int menu=3; // variavel responsavel por armazenar a escolha se o usuario quer voltar ao menu ou nao
	//final da criação de variaveis/strings
	
	system ("cls"); // limpa a tela
	
	printf("\t--- Deletar Nomes ---\n\n"); // mensagem na tela
	printf("Digite o CPF do Usuário que deseja deletar:  \n"); // pergunta direcionada ao usuario
 	scanf("%s", cpf); // armazena a resposta na string cpf
 	
 		// citando as strings do diretorio para o consulta
		char arquivo[40];
		const char DIRREGS[] = "Alunos registrados";
	
		FILE *file; // comando FILE do sistema entrando em contato com nosso file
		sprintf(arquivo, "%s/%s", DIRREGS, cpf); // mostra o caminho para o arquivo
	 	file = fopen(arquivo, "r"); // procura um arquivo com o mesmo valor da string (arquivo = cpf) e lê ela "r", read
 	
 	if (file == NULL) // se o arquivo não existir
	{
        printf("\nO usuário não se encontra no sistema.\n\n");
    } 
	else // caso exista
	{
        fclose(file); // fecha o arquivo
        remove(arquivo); // apaga o arquivo
        printf("\nUsuário deletado com sucesso!\n\n");
	}
	
	printf("\nDeseja deletar mais usuários?\n\n");  // caso o usuario queira deletar mais usuarios ou voltar ao menu
	printf("\t1 - Sim\n");
	printf("\t2 - Não\n");
	scanf("%d", &menu); // atribui a escolha a variavel menu
	
	switch(menu)
	{
		case 1:
		deletar(); // volta novamente ao registro
		break;
		
		case 2:
		return 0; // retorna ao menu
		break;
		
		default:
		printf("\nescolha inválida\n"); // caso o usuario tenha escolhido qualquer coisa diferente das opcoes apresentadas
		break;
	}
	
	system("pause");
}

int menu() //funcao principal que define o menu do projeto
{
	int opcao=0; //variavel de escolha no menu
	int laco=1; //variavel de looping do for no menu
	int loop; // variavel de looping do for na tentativa da senha
	char senha[ ]="a"; // string da senha de login
	
	system("cls");

	for (loop=0;loop<3;loop++) // loop exectara 3 vezes, dando 3 tentativas para o usuario acertar a senha
	{	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //define que a linguagem ? o portugues, de acordo com a biblioteca

		printf("\tCartório dos alunos EBAC \n\n");
		printf("\tLogin ADMIN\n\n");
		printf("\tDigite a senha:  ");
		scanf("%s", senha); // armazena a responta na variavel senha
			
		if (strcmp (senha, "admin") !=0) // comparacao da string senha com "admin", caso seja diferente de verdadeiro, é invalida 
		{	
			system("cls");	
			printf("\n\tSenha inválida, tente novamente.\n\n");
			system("pause");
			system("cls");
		}
			
			else // caso outra coisa (seja verdadeira) entramos no sistema 
			{
				for (laco=1;laco=1;) //laco de repeticao do menu "enquanto laco for 1 faca ate laco for 1"
				{ 
					system("cls"); //limpa a tela

					printf("\tCartório dos alunos EBAC \n\n"); // mensagens ao usuario
					printf("--- Escolha a opção desejada no menu: --- \n\n");
					printf("\t1 - Registrar Nomes\n");
					printf("\t2 - Consultar Nomes\n");
					printf("\t3 - Deletar Nomes\n");
					printf("\t0 - Sair da conta\n\n\n");
					printf("\tOpção: ");	

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
   			} // fim do else senha
	} // fim do for senha
	
			printf("\n\nNumero máximo de tentativas atingido!\n\n");
			system("pause");
			return 0;
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

int criarUser(Usuario *user) // funcao usada para a criação do usuario. Tem como parametro um ponteiro, o qual atribui a user os valores da struct, incluindo assim seus membros dentro da funcao por meio do user
{ 
	char userfile[160]; // string que vamos salvar as informações do usuario no sistema, e a nossa primare key
	const char DIRUSER[] = "Usuarios do sistema"; // constante DIRUSER que armazena o nome do diretorio que vai ser criada, no caso o que esta entre " ".
		
	system ("cls");
	
	setlocale(LC_ALL, "Portuguese"); //define que a linguagem e o portugues, de acordo com a biblioteca
	
	printf("\tCriar novo usuário\n\n");
	
	while(1) // looping de validação dos caracteres digitados. Caso ele ache algo que não atende as condicoes, reinicia o loop. 1 pois e verdadeiro, logo um loop infinito
	{
	    printf("Digite um nome de usuário: "); // citando a constante pois e usada para mostrar os caracteres
	    scanf("%s", user->username); // atribui a username, que e membro de User(que tem como ponteiro user. esta atrib). E um ponteiro portanto esta sendo usado "->"
	    
	    	if (strlen(user->username) >MAX_LOGIN) // strlen verifica o tamanho de uma string, esta verificando se o que digitamos respeita a constante
			{
				printf("\nERRO. Nome de usuário muito grande (máximo %d caracteres).\n\n", MAX_LOGIN);
				system("pause");
				continue; // reinicia o loop
			}
			
		break; // caso nao seja posto nenhuma inconformidade, o loop é quebrado e o codigo da sequencia
	}
	while(1)
	{
		printf("Digite uma senha: ");
	    scanf("%s", user->password);
	    		
	    	if (strlen(user->password) >MAX_LOGIN) // strlen verifica o tamanho de uma string, esta verificando se o que digitamos respeita a constante
			{
				printf("\nERRO. Senha muito grande (máximo %d caracteres).\n\n", MAX_LOGIN);
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
				printf("\nERRO. Email muito grande (máximo %d caracteres).\n\n", MAX_EMAIL);
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
				printf("\nERRO. Telefone muito grande (máximo %d caracteres).\n\n", MAX_TELL);
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
		

    printf("\nUsuário criado com sucesso!\n\n");
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

    printf("Nome de usuário: ");
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
        fgets(line, sizeof(line), file); // fgets: armazena em line, a quantidade de caracteres do tamanho de line, o conteudo de file. o tamanho é o MAX_LOGIN, mencionado pela expressao sizeof(line), que diz basicamento "o tamanho de ( )"

        // apos armazenar, remove a quebra de linha "\n" do final da string
        line[strcspn(line, "\n")] = '\0'; // strcsp ta percorrendo line ate achar o \n e anulando ele

        // Verifica se o nome de usuario e valido com uma comparacao
        if (strcmp(line, username) != 0) // compara o line sem o \n com o que digitamos, e se for diferente de zero, retorna invalido
		{
			printf("Falha no Login!\n"); // caso invalido
            printf("Nome de usuário inválido!\n"); 
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
            printf("Senha inválida!\n");
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
        printf("Usuário não encontrado!\n");
        system("pause");
        return 1;
    }
}

int main() {
	
	// O código obtém as informações da fonte atual, modifica a largura e altura e define a nova fonte no console.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    fontInfo.dwFontSize.X = 14; // Definicao da largura da fonte
    fontInfo.dwFontSize.Y = 24; // Definicao da altura da fonte 

    // Coloca o novo tamanho da fonte
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
	
    Usuario user; // declaracao de Usuario user para atalhos das outras funcoes
    int opcao2; // variavel da escolha

while(1) // loop
{
	system("cls");

	setlocale(LC_ALL, "Portuguese"); //define que a linguagem ? o portugues, de acordo com a biblioteca
	
    printf("\tBem-vindo ao Cartório EBAC\n\n");

    printf("1. Cadastrar-se\n");
    printf("2. Fazer login\n");
    printf("3. Sair\n");

    printf("\nEscolha uma opção: ");
    scanf("%d", &opcao2); // atribui a escolha do usuario a opcao2

    switch (opcao2) { // analisa a variavel opcao2 e toma uma decisao
    
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
            printf("Opção inválida.\n"); // caso escolha algo diferente, resulta em invalido
            system("pause");
            break;
    }
  }
}

