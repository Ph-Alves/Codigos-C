#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// vari�veis
char senha[20], nomeCliente[10][50], nomePet[10][50], telefone[10][30], banhoSelecionado[10][50], diaConsulta[10][50], usuarioConsulta[10][50], medicoConsulta[10][50];

int i, escolha, qntdUsuarios, escolhaBanho[10], escolhaDiaConsulta[10], escolhaUsuarioConsulta[10], escolhaMedico[10], escolhaPetBanho[10];

//fun��o LimpaTela
void LimparTela() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

// Fun��o cadastro
void paulo() {
	LimparTela();
	printf("------ CADASTRO ------\n\n");
	printf("Digite o nome do cliente: ");
	fflush(stdin);
	fgets(nomeCliente[i], 50, stdin);
	printf("Digite o nome do pet: ");
	fflush(stdin);
	fgets(nomePet[i], 50, stdin);
	printf("Digite seu Telefone: ");
	fflush(stdin);
	fgets(telefone[i], 50, stdin);
	qntdUsuarios++;
}

// c�digo principal
int main(void) {
	setlocale(LC_ALL, "Portuguese");

	// login de senha
	while (strcmp(senha, "patinha") != 0) {
		printf("Digite sua senha: ");
		scanf("%s", senha);
	}

	i = 1;

	// Menu
	while (strcmp(senha, "patinha") != 1) {
		LimparTela();
		printf("\nSuper_Petshop_Paulo_ES\n\n");
		printf("== Cadastro ==\n\n");
		printf("1 - Cadastrar Cliente\n");
		printf("2 - Agendamento\n");
		printf("3 - Consulta\n");
		printf("4 - Imprimir relat�rio geral\n");
		printf("5 - Sair\n");
		printf("Digite a op��o que voc� quer acessar: ");
		scanf("%i", &escolha);

		//Condi��o para caso o usu�rio escolha errado
		if(escolha > 5 || escolha < 1) {
			printf("Escolha inv�lida!!");
			getch();
			escolha = 0;
		}

		// Op��es do Menu
		switch (escolha) {

			// Cadastro
			case 1:
				while (escolha == 1) {
					LimparTela();
					paulo();
					escolha = 0;
					i++;
					break;
				}

			// Agendamento
			case 2:
				while (escolha == 2) {
					LimparTela();
					printf("------ AGENDAMENTO ------\n\n");
					for(i=1; i<=qntdUsuarios; i++){
					printf("%i - %i\n", i, nomePet[i]);
					}
					printf("Escolha Pet que receber� o banho: ");
					scanf("%i", &escolhaPetBanho[i]);
					printf("1- Banho\n");
					printf("2- Tosa\n");
					printf("3- Banho e Tosa\n");
					printf("Escolha uma op��o: ");
					scanf("%i", &escolhaBanho[i]);
					switch (escolhaBanho[i]) {
						case 1:
							strcpy(banhoSelecionado[i], "Banho");
							break;
						case 2:
							strcpy(banhoSelecionado[i], "Tosa");
							break;
						case 3:
							strcpy(banhoSelecionado[i], "Banho e Tosa");
							break;
						default:
							printf("Escolha inv�lida!");
							getch();
							escolhaBanho[i] = 0;
					}
					escolha = 0;
					i++;
				}
				break;

			// Consulta
			case 3:
				while (escolha == 3) {
					LimparTela();
					printf("------ CONSULTA ------\n\n");
					printf("1- Segunda-Feira\n");
					printf("2- Quinta-Feira\n");
					printf("Escolha um dia para a consulta: ");
					scanf("%i", &escolhaDiaConsulta[i]);
					switch(escolhaDiaConsulta[i]) {
						case 1:
							strcpy(diaConsulta[i], "Segunda-Feira");
							break;
						case 2:
							strcpy(diaConsulta[i], "Quinta-Feira");
							break;
						default:
							printf("Escolha inv�lida!");
							getch();
							escolhaDiaConsulta[i] = 0;
					}

					LimparTela();
					printf("Clientes: \n\n");
					for(i=1; i<=10; i++) {
						printf("%i- %s\n", i, nomeCliente[i]);
					}
					printf("Escolha o usu�rio a que participar� da consulta: ");
					scanf("%i", &escolhaUsuarioConsulta[i]);
					switch(escolhaUsuarioConsulta[i]) {
						case 1:
							i = escolhaUsuarioConsulta[i];
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 2:
							i = escolhaUsuarioConsulta[i];
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 3:
							i = escolhaUsuarioConsulta[i];
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 4:
							i = escolhaUsuarioConsulta[i];
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 5:
							i = escolhaUsuarioConsulta[i];
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 6:
							i = escolhaUsuarioConsulta[i];
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 7:
							i = escolhaUsuarioConsulta[i];
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						default:
							printf("Escolha inv�lida!");
							getch();
							escolhaUsuarioConsulta[i] = 0;
					}

					LimparTela();
					printf("1- Dr.Fabiano\n");
					printf("2- Dr.Paulo\n");
					printf("Escolha um m�dico para o atendimento: ");
					scanf("%i", &escolhaMedico[i]);
					switch(escolhaMedico[i]) {
						case 1:
							strcpy(medicoConsulta[i], "Dr.Fabiano");
							break;
						case 2:
							strcpy(medicoConsulta[i], "Dr.Paulo");
							break;
						default:
							printf("Escolha Inv�lida!!");
							getch();
							escolhaMedico[i] = 0;
					}
					escolha = 0;
					i++;
				}
				break;

			// Imprimir relat�rio geral
			case 4:
				while (escolha == 4) {
					for(i=1; i<=qntdUsuarios; i++) {
						LimparTela();
						printf("------ RELAT�RIO GERAL ------\n\n");
						printf("Nome do cliente: %s\n", nomeCliente[i]);
						printf("Nome do Pet: %s\n", nomePet[i]);
						if(banhoSelecionado[i] != NULL) {
							printf("Existe Agendamento marcado para este usu�rio!\n");
							printf("Agendamento do banho: %s\n", banhoSelecionado[i]);
						} else {
							printf("Agendamento do banho: N�o foi agendado.\n");
						}
						if (diaConsulta[i] != NULL) {
							printf("Consulta: Existe consulta marcada no nome deste usu�rio!\n");
							printf("Dia da Consulta: %s\n", diaConsulta[i]);
							printf("M�dico Respons�vel: %s\n", medicoConsulta[i]);
						} else {
							printf("Consulta: N�o existe consulta marcada!\n");
						}
						getch();
					}
				}
				escolha = 0;
				break;

			//Sair
			case 5:
				LimparTela();
				printf("Volte sempre ao Super_Petshop_PauloHenrique_ES!!!");
				return 0;
				break;
		}
	}


	return 0;
}

