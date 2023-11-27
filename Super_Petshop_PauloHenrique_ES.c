#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variáveis
char senha[20], nomeCliente[10][50], nomePet[10][50], telefone[10][30], banhoSelecionado[10][50], diaConsulta[10][50], usuarioConsulta[10][50], medicoConsulta[10][50], petBanho[10][50];

int i, escolha, qntdUsuarios, escolhaBanho, escolhaDiaConsulta, escolhaUsuarioConsulta, escolhaMedico, escolhaPetBanho;

//função LimpaTela
void LimparTela() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

// Função cadastro
void paulo() {
	LimparTela();
	printf("\nSuper_Petshop_Paulo_ES\n\n");
	printf("====== CADASTRO ======\n\n");
	printf("Digite o nome do cliente: ");
	fflush(stdin);
	fgets(nomeCliente[i], 50, stdin);
	printf("Digite o nome do pet: ");
	fflush(stdin);
	fgets(nomePet[i], 50, stdin);
	printf("Digite seu Telefone: ");
	fflush(stdin);
	fgets(telefone[i], 50, stdin);
}

// código principal
int main(void) {
	setlocale(LC_ALL, "Portuguese");
	
	int *pQntdUsuarios;
	pQntdUsuarios = &qntdUsuarios;
	

	// login de senha
	while (strcmp(senha, "patinha") != 0) {
		printf("Digite sua senha: ");
		fflush(stdin);
		gets(senha);
	}

	i = 1;

	// Menu
	while (strcmp(senha, "patinha") != 1) {
		LimparTela();
		printf("\nSuper_Petshop_Paulo_ES\n\n");
		printf("====== Cadastro ======\n\n");
		printf("1 - Cadastrar Cliente\n");
		printf("2 - Agendamento\n");
		printf("3 - Consulta\n");
		printf("4 - Imprimir relatório geral\n");
		printf("5 - Sair\n");
		printf("Digite a opção que você quer acessar: ");
		scanf("%i", &escolha);

		//Condição para caso o usuário escolha errado
		if(escolha > 5 || escolha < 0) {
			printf("Escolha inválida!!");
			getchar();
			escolha = 0;
		}

		// Opções do Menu
		switch (escolha) {

			// Cadastro
			case 1:
				while (escolha == 1) {
					LimparTela();
					paulo();
					*pQntdUsuarios = *pQntdUsuarios + 1;
					i++;
					break;
				}
				escolha = 0;
				break;

			// Agendamento
			case 2:
				while (escolha == 2) {
					LimparTela();
					printf("\nSuper_Petshop_Paulo_ES\n\n");
					printf("====== AGENDAMENTO ======\n\n");
					for(i=1; i<= *pQntdUsuarios; i++){
						printf("%i - %s\n", i, nomePet[i]);
					}
					printf("\nEscolha Pet que receberá o banho: ");
					scanf("%i", &escolhaPetBanho);
					switch (escolhaPetBanho){
						case 1:
							i = escolhaPetBanho;
							strcpy(petBanho[i], nomePet[i]);
							break;
						case 2:
							i = escolhaPetBanho;
							strcpy(petBanho[i], nomePet[i]);
							break;
						case 3:
							i = escolhaPetBanho;
							strcpy(petBanho[i], nomePet[i]);
							break;
						case 4:
							i = escolhaPetBanho;
							strcpy(petBanho[i], nomePet[i]);
							break;
						case 5:
							i = escolhaPetBanho;
							strcpy(petBanho[i], nomePet[i]);
							break;
						case 6:
							i = escolhaPetBanho;
							strcpy(petBanho[i], nomePet[i]);
							break;
						case 7:
							i = escolhaPetBanho;
							strcpy(petBanho[i], nomePet[i]);
							break;
						case 8:
							i = escolhaPetBanho;
							strcpy(petBanho[i], nomePet[i]);
							break;
						case 9:
							i = escolhaPetBanho;
							strcpy(petBanho[i], nomePet[i]);
							break;
						case 10:
							i = escolhaPetBanho;
							strcpy(petBanho[i], nomePet[i]);
							break;
					}
					if (escolhaPetBanho < 1 || escolhaPetBanho > *pQntdUsuarios){
						printf("Escolha Inválida!\n");
						printf("Você será redirecionado para o menu em 5 segundos...\n");
						sleep(5);
						escolha = 0;
						break;
					}
					
					LimparTela();
					printf("\nSuper_Petshop_Paulo_ES\n\n");
					printf("\n=== BANHOS ===\n\n");
					printf("1- Banho\n");
					printf("2- Tosa\n");
					printf("3- Banho e Tosa\n");
					printf("\nEscolha uma opção: ");
					scanf("%i", &escolhaBanho);
					switch (escolhaBanho) {
						case 1:
							strcpy(banhoSelecionado[i], "Banho");
							break;
						case 2:
							strcpy(banhoSelecionado[i], "Tosa");
							break;
						case 3:
							strcpy(banhoSelecionado[i], "Banho e Tosa");
							break;
					}
					if (escolhaBanho < 1 || escolhaBanho > 3){
						printf("Escolha Inválida!\n");
						printf("Você será redirecionado para o menu em 5 segundos...\n");
						sleep(5);
						escolha = 0;
						break;
					}
					i++;
					escolha = 0;
				}
				escolha = 0;
				break;

			// Consulta
			case 3:
				while (escolha == 3) {
					LimparTela();
					printf("\nSuper_Petshop_Paulo_ES\n\n");
					printf("====== CONSULTA ======\n\n");
					printf("=== CLIENTES ===\n\n");
					for(i=1; i<= *pQntdUsuarios; i++) {
						printf("%i- %s\n", i, nomeCliente[i]);
					}
					printf("Escolha o usuário que participará da consulta: ");
					scanf("%i", &escolhaUsuarioConsulta);
					switch(escolhaUsuarioConsulta) {
						case 1:
							i = escolhaUsuarioConsulta;
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 2:
							i = escolhaUsuarioConsulta;
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 3:
							i = escolhaUsuarioConsulta;
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 4:
							i = escolhaUsuarioConsulta;
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 5:
							i = escolhaUsuarioConsulta;
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 6:
							i = escolhaUsuarioConsulta;
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 7:
							i = escolhaUsuarioConsulta;
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 8:
							i = escolhaUsuarioConsulta;
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 9:
							i = escolhaUsuarioConsulta;
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
						case 10:
							i = escolhaUsuarioConsulta;
							strcpy(usuarioConsulta[i], nomeCliente[i]);
							break;
					}
					if (escolhaUsuarioConsulta < 1 || escolhaUsuarioConsulta > *pQntdUsuarios){
						printf("Escolha Inválida!\n");
						printf("Você será redirecionado para o menu em 5 segundos...\n");
						sleep(5);
						escolha = 0;
						break;
					}
					
					LimparTela();
					printf("\nSuper_Petshop_Paulo_ES\n\n");
					printf("\n=== DIAS DA CONSULTA ===\n\n");
					printf("1- Segunda-Feira\n");
					printf("2- Quinta-Feira\n");
					printf("\nEscolha um dia para a consulta: ");
					scanf("%i", &escolhaDiaConsulta);
					switch(escolhaDiaConsulta) {
						case 1:
							strcpy(diaConsulta[i], "Segunda-Feira");
							break;
						case 2:
							strcpy(diaConsulta[i], "Quinta-Feira");
							break;
					}
					if (escolhaDiaConsulta < 1 || escolhaDiaConsulta > 2){
						printf("Escolha Inválida!\n");
						printf("Você será redirecionado para o menu em 5 segundos...\n");
						sleep(5);
						escolha = 0;
						break;
					}
					
					LimparTela();
					printf("\nSuper_Petshop_Paulo_ES\n\n");
					printf("\n=== MÉDICOS ===\n\n");
					printf("1- Dr.Fabiano\n");
					printf("2- Dr.Paulo\n");
					printf("Escolha um médico para o atendimento: ");
					scanf("%i", &escolhaMedico);
					switch(escolhaMedico) {
						case 1:
							strcpy(medicoConsulta[i], "Dr.Fabiano");
							break;
						case 2:
							strcpy(medicoConsulta[i], "Dr.Paulo");
							break;
					}
					if (escolhaMedico < 1 || escolhaMedico > 2){
						printf("Escolha Inválida!\n");
						printf("Você será redirecionado para o menu em 5 segundos...\n");
						sleep(5);
						escolha = 0;
						break;
					}
					
					escolha = 0;
					i++;
				}
				escolha = 0;
				break;

			// Imprimir relatório geral
			case 4:
				while (escolha == 4) {
					for(i=1; i<= *pQntdUsuarios; i++) {
						LimparTela();
						printf("\nSuper_Petshop_Paulo_ES\n\n");
						printf("====== RELATÓRIO GERAL ======\n\n");
						printf("Nome do cliente: %s\n", nomeCliente[i]);
						printf("Nome do Pet: %s\n", nomePet[i]);
						printf("Número do cliente: %s\n\n", telefone[i]);
						if(escolhaPetBanho != 0) {
							printf("=== AGENDAMENTO DO BANHO ===\n\n");
							printf("= Existe Banho marcado para este usuário! =\n\n");
							printf("Nome do Pet Selecionado: %s\n", petBanho[i]);
							printf("Agendamento do banho: %s\n\n", banhoSelecionado[i]);
						} else {
							printf("=== AGENDAMENTO DO BANHO ===\n\n");
							printf("= Agendamento do banho: Não foi agendado. =\n\n");
						}
						if (escolhaUsuarioConsulta != 0) {
							printf("=== AGENDAMENTO DA CONSULTA ===\n\n");
							printf("= Consulta: Existe consulta marcada no nome deste usuário! =\n\n");
							printf("Paciente que será atendido: %s\n", usuarioConsulta[i]);
							printf("Dia da Consulta: %s\n\n", diaConsulta[i]);
							printf("Médico Responsável: %s\n\n", medicoConsulta[i]);
						} else {
							printf("=== AGENDAMENTO DA CONSULTA ===\n\n");
							printf("Consulta: Não existe consulta marcada!\n\n");
						}
						getch();
					}
					escolha = 0;
				}
				escolha = 0;
				break;

			//Sair
			case 5:
				LimparTela();
				printf("Volte sempre ao Super_Petshop_PauloHenrique_ES!!!\n\n");
				return 0;
				break;
		}
	}


	return 0;
}

