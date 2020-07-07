#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct Eletrodomestico
{
	char Nome[50];
	float Potencia;
	float TempoLigado;
	float ConsumoTotal;
	float PrecoIndividual;
	int Ligado;
	time_t HoraLigado;
	time_t HoraDesligado;
}Eletrodomestico;

int Menu();

void CadastrarkWh(float *precokWh);

void CadastrarEletrodomestico(Eletrodomestico x[],int cont);

int ExcluirEletrodomestico(Eletrodomestico x[], int cont);

void LigarEletrodomestico(Eletrodomestico x[],int cont);

void DesligarEletrodomestico(Eletrodomestico x[],int cont);

void ListarEletrodomesticos(Eletrodomestico x[], int cont);

void GerarFatura(float precokw, Eletrodomestico x[],int cont);

int main(){
	int pos = 0;
	float preco;
	char opcao;
	Eletrodomestico Eletro[MAX];
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t\t-Sistema de Consumo Elétrico-\n"); /*		Tela Inicial	*/
	for(;opcao!='0';)
	{
		fflush(stdin);
		opcao = Menu();
		switch(opcao)
		{
			case '1' : 	/*	Cadastrar preço do KW	*/
				CadastrarkWh(&preco);
				break;
			case '2' :		/*	Cadastrar eletrodoméstico	*/
				CadastrarEletrodomestico(Eletro,pos);
				pos++;
				break;
			case '3' : /*	Apagar eletrodoméstico	*/
				pos = ExcluirEletrodomestico(Eletro, pos);
				break;
			case '4' : 	/*	Ligar eletrodoméstico	*/
				LigarEletrodomestico(Eletro, pos);
				break;
			case '5' : 	/*	Desligar eletrodoméstico	*/
				DesligarEletrodomestico(Eletro, pos);
				break;
			case '6' :	/*	Listar eletrodomésticos		*/
				ListarEletrodomesticos(Eletro, pos);
				break;
			case '7' : 	/*	Gerar Fatura	*/
				GerarFatura(preco, Eletro, pos);
				break;
			case '0' : 	/*	Sair	*/
				break;
			default :
				system("cls");
				printf("Codigo invalido!\n\n");
				break;
		}
	}
	return 0;
}

int Menu()
{
	char op;
	printf("\tMenu\n");
	printf("1. Cadastrar preço do kW\n");
	printf("2. Cadastrar eletrodoméstico\n");
	printf("3. Excluir eletrodoméstico\n");
	printf("4. Ligar eletrodoméstico\n");
	printf("5. Desligar eletrodoméstico\n");
	printf("6. Listar eletrodomésticos\n");
	printf("7. Gerar fatura\n");
	printf("0. Sair \n\n");
	printf("Digite a opção desejada: ");
	gets(&op);
	return op;
}

void CadastrarkWh(float *precokWh)
{
	printf("Digite o preço do kWh: ");
	scanf("%f",&*precokWh);
	system("cls");
	printf("Preço cadastrado com sucesso\n\n");
}

void CadastrarEletrodomestico(Eletrodomestico x[],int cont)
{
	printf("Digite o nome do eletrodoméstico: ");
	scanf("%s",x[cont].Nome);
	fflush(stdin);
	printf("Digite a potencia do eletrodoméstico: ");
	scanf("%f",&x[cont].Potencia);
	x[cont].Ligado=0; 
	system("cls");
	printf("Cadastro realizado com sucesso!\n\n");
}

int ExcluirEletrodomestico(Eletrodomestico x[], int cont)
{
	int aux, aux2, aux3 = 0;
	char nome[50];
	printf ("Digite o nome do eletrodoméstico que deseja excluir: ");
	scanf ("%s", nome);
	for (aux = 0; aux <= cont; aux++)
	{
		if ((strcmp(nome,x[aux].Nome)) == 0)
		{
			aux3 = 1;
			for(aux2 = aux; aux2 <= cont; aux2++)
			{
				strcpy(x[aux2].Nome,x[aux2+1].Nome);
				x[aux2].Potencia = x[aux2+1].Potencia;
				x[aux2].TempoLigado = x[aux2+1].TempoLigado;
				x[aux2].ConsumoTotal = x[aux2+1].ConsumoTotal;
				x[aux2].PrecoIndividual = x[aux2+1].PrecoIndividual;
				x[aux2].Ligado = x[aux2+1].Ligado;
			}
			cont--;
			system("cls");
			printf("Eletrodomestico excluido com sucesso!\n\n");
			break;
		}
	}
	if(aux3 == 0) 
	{
	system("cls");
	printf("Impossivel excluir. Eletrodomestico não encontrado.\n\n");
	}
	return cont;
}

void LigarEletrodomestico(Eletrodomestico x[],int cont)
{
	int aux,aux2= 0;
	char Nome[50];
	printf("Digite o nome do eletrodoméstico a ser ligado: ");
	scanf("%s",Nome);
	for(aux=0;aux<cont;aux++){
		if(strcmp(x[aux].Nome,Nome)==0)
		{
			aux2= 1;
			break;
		}
	}
	if(aux2==1){
		if(x[aux].Ligado==0)
		{
			x[aux].HoraLigado= time(NULL);
			system("cls");
			printf("%s ligado(a) com sucesso!\n\n",x[aux].Nome);
			x[aux].Ligado= 1;
		}
		else
		{
			system("cls");
			printf("Erro! %s já está ligado(a)!\n\n",x[aux].Nome);
		}
	}
	else
	{
		system("cls");
		printf("Eletrodoméstico não encontrado!\n\n");
	}
}

void DesligarEletrodomestico(Eletrodomestico x[],int cont)
{
	int aux,aux2= 0;
	char Nome[50];
	printf("Digite o nome do eletrodoméstico a ser desligado: ");
	scanf("%s",Nome);
	for(aux=0;aux<cont;aux++)
	{
		if(strcmp(x[aux].Nome,Nome)==0)
		{
			aux2= 1;
			break;
		}
	}
	if(aux2==1)
	{
		if(x[aux].Ligado==1)
		{
			x[aux].HoraDesligado= time(NULL);
			x[aux].TempoLigado= x[aux].TempoLigado + difftime(x[aux].HoraDesligado,x[aux].HoraLigado);
			system("cls");
			printf("%s desligado(a) com sucesso!\n\n",x[aux].Nome);
			x[aux].Ligado= 0;
		}
		else
		{
			system("cls");
			printf("Erro! %s já está desligado(a)!\n\n",x[aux].Nome);
		}
	}
	else
	{
		system("cls");
		printf("Eletrodoméstico não encontrado!\n\n");
	}
}

void ListarEletrodomesticos(Eletrodomestico x[], int cont)
{
	int aux;
	system("cls");
	if(cont!=0)
	{
		for(aux=0;aux<cont;aux++)
		{
			printf("- %s -\nPotência: %.2f\nLigado %d (1- Sim 0- Nao)\n\n",x[aux].Nome,x[aux].Potencia,x[aux].Ligado);
		}
	}
	else
	{
		printf("Nenhum eletrodomestico cadastrado.\n\n");
	}
}

void GerarFatura(float precokw, Eletrodomestico x[], int cont)
{
	int aux;
	float precototal=0;
	system("cls");
	for(aux=0;aux<cont;aux++)
	{
		x[aux].ConsumoTotal= (x[aux].Potencia*(x[aux].TempoLigado/3600));
		x[aux].PrecoIndividual= (x[aux].ConsumoTotal*precokw);
		precototal = precototal+x[aux].PrecoIndividual;
		printf("%s - Tempo: %.0fs Consumo Total: %.2fkWh Preço Individual: R$%.2f\n",x[aux].Nome, x[aux].TempoLigado, x[aux].ConsumoTotal, x[aux].PrecoIndividual);
	}
	printf("Preço kWh: R$%.2f\nPreço total: R$%.2f\n\n",precokw,precototal);
}