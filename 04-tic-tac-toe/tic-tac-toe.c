#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializar (char jogodavelha[3][3]);
void imprime (char jogodavelha[3][3]);
int vencedor (char a[3][3], int modo, int cont, char j1, char j2);
void umjogador (char jogodavelha[3][3]);
void doisjogadores (char jogodavelha[3][3]);

int main (){
	char op,jogodavelha[3][3];
	while(1){
		fflush(stdin);
		inicializar (jogodavelha);
		imprime(jogodavelha);
		printf("Escolha o modo de jogo:\n");
		printf("  1. Um Jogador\n");
		printf("  2. Dois Jogadores\n");
		printf("  0. Sair\n");
		printf("Opcao: ");
		scanf("%c",&op);
		switch(op){
			case '0':
				exit(1);
				break;
			case '1':
				system("cls");
				umjogador(jogodavelha);
				break;
			case '2':
				system("cls");
				doisjogadores(jogodavelha);
				break;
			default:
				printf("Opcao Invalida!\n");
				system("pause");
				system("cls");
				break;
		}
	}
}

void inicializar (char jogodavelha[3][3]){
	int x, y;
	for (x=0; x<3; x++){
		for(y=0; y<3; y++){
			jogodavelha[x][y]='-';
		}
	}
}

void imprime (char jogodavelha[3][3]){
	int x, y;
	printf("\tJOGO DA VELHA\n\n");
	printf("X- Horizontal\nY- Vertical\n\n   1 2 3\n");
	for (x=0; x<3; x++){
		printf("%d |",x+1);
		for (y=0; y<3; y++){
			printf ("%c|", jogodavelha[x][y]);
		}
		printf ("\n");
	}
	printf ("\n");
}

int vencedor (char jogodavelha[3][3], int modo, int cont, char j1, char j2){
	if(cont<9){
		if(((jogodavelha[0][0]==jogodavelha[1][0])&&(jogodavelha[1][0]==jogodavelha[2][0]))||((jogodavelha[0][0]==jogodavelha[0][1])&&(jogodavelha[0][1]==jogodavelha[0][2]))){
			if(jogodavelha[0][0]==j1){
				printf("Fim de jogo! Parabens jogador UM, voce venceu!\n\n");
				system("pause");
				system("cls");
				return 1;
			}
			if(jogodavelha[0][0]==j2){
				if(modo == 1){
					printf("Fim de jogo! Parabens jogador DOIS, voce venceu!\n\n");
				}
				if(modo == 2){
					printf("Fim de jogo! Infelizmente o COMPUTADOR foi o vitorioso e voce perdeu!\n\n");
				}
				system("pause");
				system("cls");
				return 1;
			}
		}
		if(((jogodavelha[2][2]==jogodavelha[2][1])&&(jogodavelha[2][1]==jogodavelha[2][0]))||((jogodavelha[2][2]==jogodavelha[1][2])&&(jogodavelha[1][2]==jogodavelha[0][2]))){
			if(jogodavelha[2][2]==j1){
				printf("Fim de jogo! Parabens jogador UM, voce venceu!\n\n");
				system("pause");
				system("cls");
				return 1;
			}
			if(jogodavelha[2][2]==j2){
				if(modo == 1){
					printf("Fim de jogo! Parabens jogador DOIS, voce venceu!\n\n");
				}
				if(modo == 2){
					printf("Fim de jogo! Infelizmente o COMPUTADOR foi o vitorioso e voce perdeu!\n\n");
				}
				system("pause");
				system("cls");
				return 1;
			}
		}
		if(((jogodavelha[1][1]==jogodavelha[0][1])&&(jogodavelha[1][1]==jogodavelha[2][1]))||((jogodavelha[1][1]==jogodavelha[1][0])&&(jogodavelha[1][1]==jogodavelha[1][2]))){
			if(jogodavelha[1][1]==j1){
				printf("Fim de jogo! Parabens jogador UM, voce venceu!\n\n");
				system("pause");
				system("cls");
				return 1;
			}
			if(jogodavelha[1][1]==j2){
				if(modo == 1){
					printf("Fim de jogo! Parabens jogador DOIS, voce venceu!\n\n");
				}
				if(modo == 2){
					printf("Fim de jogo! Infelizmente o COMPUTADOR foi o vitorioso e voce perdeu!\n\n");
				}
				system("pause");
				system("cls");
				return 1;
			}
		}
		if(((jogodavelha[1][1]==jogodavelha[0][0])&&(jogodavelha[1][1]==jogodavelha[2][2]))||((jogodavelha[1][1]==jogodavelha[2][0])&&(jogodavelha[1][1]==jogodavelha[0][2]))){
			if(jogodavelha[1][1]==j1){
				printf("Fim de jogo! Parabens jogador UM, voce venceu!\n\n");
				system("pause");
				system("cls");
				return 1;
			}
			if(jogodavelha[1][1]==j2){
				if(modo == 1){
					printf("Fim de jogo! Parabens jogador DOIS, voce venceu!\n\n");
				}
				if(modo == 2){
					printf("Fim de jogo! Infelizmente o COMPUTADOR foi o vitorioso e voce perdeu!\n\n");
				}
				system("pause");
				system("cls");
				return 1;
			}
		}
	}
	else{
		printf("Fim de jogo! Empate entre os jogadores!\n\n");
		system("pause");
		system("cls");
	}
	return 0;
}

void umjogador (char jogodavelha[3][3]){
	int teste, teste2, i, vez = 0, x, y;
	char j1,pc;
	imprime(jogodavelha);
	
	while(teste!=1){
		printf("Jogador UM, escolha X ou O: ");
		fflush(stdin);
		scanf("%c",&j1);
		if(j1=='x'||j1=='X'){
			printf("O COMPUTADOR sera O.\n\n");
			j1='x';
			pc='o';
		}
		if(j1=='o'||j1=='O'){
			printf("O COMPUTADOR sera X.\n\n");
			j1='o';
			pc='x';
		}
		if((j1=='x'&&pc=='o')||(j1=='o'&&pc=='x'))
			teste=1;
		else{
			teste=0;
			printf("Invalido. Insira novamente!\n\n");
		}
	}
	system("pause");
	system("cls");
	for (i=0; i<9; i++){
		imprime(jogodavelha);
		if(vencedor(jogodavelha,2,i,j1,pc) == 1)
			break;
		teste2 = 0;
		if(vez == 0){
			printf ("Jogador UM, digite as coordenadas (X e Y) onde deseja inserir:\n");
			printf("X: ");
			fflush(stdin);
			scanf ("%d", &x);
			printf("Y: ");
			fflush(stdin);
			scanf ("%d", &y);
			if((x<1||x>3)||(y<1||y>3)){
				printf("Posicao invalida! Insira novamente!\n");
				i--;
			}
			else{
				if (jogodavelha[y-1][x-1] == '-'){
					jogodavelha[y-1][x-1] = j1;
					teste2 = 1;
				}else{
					printf ("Posicao ocupada! Insira novamente!\n");
					i--;
				}
			}
		}
		if(vez == 1){
				printf ("Vez do COMPUTADOR.\n");
				while(teste2!=2){
				srand((unsigned)time(NULL));
				x= rand() %4;
				y= rand() %4;
					if (jogodavelha[y-1][x-1] == '-'){
						jogodavelha[y-1][x-1] = pc;
						teste2 = 2;
					}
			}
		}
		if(teste2 == 1)
			vez = 1;
		if(teste2 == 2)
			vez = 0;
		system("pause");
		system("cls");
		
	}
	if(i == 9){
		imprime(jogodavelha);
		vencedor(jogodavelha,2,i,j1,pc);
	}
}

void doisjogadores (char jogodavelha[3][3]){
	int teste, i, vez = 0, x, y;
	char j1,j2;
	imprime(jogodavelha);
	while(teste!=1){
		printf("Jogador UM, escolha X ou O: ");
		fflush(stdin);
		scanf("%c",&j1);
		if(j1=='x'||j1=='X'){
			printf("Jogador DOIS, voce sera O\n\n");
			j1='x';
			j2='o';
		}
		if(j1=='o'||j1=='O'){
			printf("Jogador DOIS, voce sera X\n\n");
			j1='o';
			j2='x';
		}
		if((j1=='x'&&j2=='o')||(j1=='o'&&j2=='x'))
			teste=1;
		else{
			teste=0;
			printf("Invalido. Insira novamente\n\n");
		}
	}
	system("pause");
	system("cls");
	for (i=0; i<9; i++){
		imprime(jogodavelha);
		if(vencedor(jogodavelha,1,i,j1,j2) == 1)
			break;
		if(vez == 0){
			printf ("Jogador UM, digite as coordenadas (X e Y) onde deseja inserir:\n");
		}
		if(vez == 1){
			printf ("Jogador DOIS, digite as coordenadas (X e Y) onde deseja inserir:\n");
		}
		printf("X: ");
		fflush(stdin);
		scanf ("%d", &x);
		printf("Y: ");
		fflush(stdin);
		scanf ("%d", &y);
		if((x<1||x>3)||(y<1||y>3)){
			printf("Posicao invalida! Insira novamente!\n");
			i--;
			system("pause");
		}
		else{
			if (jogodavelha[y-1][x-1] == '-'){
				if(vez == 0){
					jogodavelha[y-1][x-1] = j1;
					vez = 1;
				}else{
					jogodavelha[y-1][x-1] = j2;
					vez = 0;
				}
			}else{
				printf ("Posicao ocupada! Insira novamente!\n");
				i--;
				system("pause");
			}
		}
		system("cls");
	}
	if(i == 9){
		imprime(jogodavelha);
		vencedor(jogodavelha,1,i,j1,j2);
	}
}