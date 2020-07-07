#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define g 10
#define pi 3.14159265359

void titulo();
void menu();
void menu2();
void LancamentoVertical();
void LancamentoInclinado();
void Processamento(float h0, float v0, float an, int TAG);
void Resultado(float h0, float v0, float an, float t, float x, float hM, int FLAG);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char op;
	while(1)
	{
		titulo();
		menu();
		printf("Digite a opção desejada: ");
		scanf("%c",&op);
		switch(op)
		{
			case '1' :
				printf("\nOpção escolhida: Realizar simulação.\n\n");
				fflush(stdin);
				system("PAUSE");
				menu2();
				break;
			case '2' :
				printf("\nEncerrando o sistema.\n\n");
				fflush(stdin);
				system("PAUSE");
				exit(1);
				break;
			default :
				printf("\nOpção inválida.\n\n");
				fflush(stdin);
				system("PAUSE");
				break;
		}
	}
	return 0;
};

void titulo()
{
	system("CLS");
	printf("		Simulador de Lançamento de Projéteis\n\n");
};

void menu()
{
	printf("   Escolha uma opção:\n\n");
	printf("1. Realizar simulação \n");
	printf("2. Encerrar o sistema \n\n");
};

void menu2()
{
	char op;
	do
	{
		titulo();
		printf("   Escolha uma função: \n\n");
		printf("1. Lançamento vertical \n");
		printf("2. Lançamento com inclinação \n");
		printf("3. Cancelar \n\n");
		printf("Digite a opção desejada: ");
		scanf("%c",&op);
		switch(op){
			case '1' :
				printf("\nOpção escolhida: Lançamento Vertical.\n\n");
				fflush(stdin);
				system("PAUSE");
				LancamentoVertical();
				fflush(stdin);			
				break;
			case '2' :
				printf("\nOpção escolhida: Lançamento Inclinado.\n\n");
				fflush(stdin);
				system("PAUSE");
				LancamentoInclinado();
				break;
			case '3' :
				printf("\nAbortando operações. Voltando para o menu inicial.\n\n");
				fflush(stdin);
				system("PAUSE");
				break;
			default :
				printf("\nOpcao inválida.\n\n");
				fflush(stdin);
				system("PAUSE");
				break;
		}
	}while(op != '1' && op != '2' && op != '3');
};

void LancamentoVertical()
{
	int ok = 0;
	float h0, v0;
	setlocale(LC_ALL, "Portuguese");
	do
	{
		titulo();
		printf("- - - Lançamento Vertical - - -\n\n");
		printf("Digite a altura inicial: ");
		scanf("%f",&h0);
		printf("Digite a Velocidade inicial: ");
		scanf("%f",&v0);
		if(h0 >= 0)
		{
			if((h0 == 0 && v0 > 0) || h0 != 0)
			{
				ok = 1;
				printf("\nInformações aceitas. Seguindo para processamento.\n\n");
				system("PAUSE");
				Processamento(h0, v0, 90, 1);
			}
			else
			{
				printf("\nInformações incoerentes. Tente novamente.\n\n");
				system("PAUSE");
			}
		}
		else
			{
				printf("\nInformações incoerentes. Tente novamente.\n\n");
				system("PAUSE");
			}
	}
	while(ok == 0);
};

void LancamentoInclinado()
{
	int ok = 0;
	float v0, an;
	setlocale(LC_ALL, "Portuguese");
	do
	{
		titulo();
		fflush(stdin);
		printf("- - - Lançamento Inclinado - - -\n\n");
		printf("Digite a Velocidade inicial (M/S): ");
		scanf("%f",&v0);
		printf("Digite o ângulo (0 a 90 graus) formado com a horizontal: ");
		scanf("%f",&an);
		if((v0 > 0) && (an >= 0 && an <= 90))
		{
			ok = 1;
			printf("\nInformações aceitas. Seguindo para processamento.\n\n");
			system("PAUSE");
			Processamento(0, v0, an, 2);
		}
		else
		{
			printf("\nInformações incoerentes. Tente novamente.\n\n");
			system("PAUSE");
		}
	}
	while(ok == 0);
};

void Processamento(float h0, float v0, float an, int FLAG){
	if( FLAG == 1) //Lançamento Vertical.
	{
		float t, vF, hM;
		if(h0 == 0)
		{//Lançamento + Queda.
			t = v0/g; //Tempo de subida = Tempo de descida.
			hM = pow(v0,2)/(2*g); //Altura máxima.
			vF = v0; //A partícula atingirá o solo com a mesma velocidade inicial.
		}
		else 
		{
			if(h0 > 0 && v0 > 0)
			{//Lançamento + Queda. h0 > 0
				hM = (pow(v0,2)/(2*g))+h0; //Altura Máxima.
				t = sqrt((2*hM)/g); //Tempo de queda.
				vF = g*t; //Velocidade final (solo).
			}
			else
			{//Queda
				hM = h0; //Altura máxima já é a atual. Não há lançamento
				vF = (-1)*sqrt(pow(v0,2)+2*g*hM); //Velocidade final (solo)
				t = (v0-vF)/g; //Tempo de queda.
			}
		}
		printf("\nInformações processadas. Seguindo para resultados.\n\n");
		system("PAUSE");
		Resultado(h0, v0, an, t, vF, hM, 1);
	}
	if( FLAG == 2) 
	{//Lançamento Inclinado.
		float t, hM, alc;
		
	 	t = 2*(v0*sin((pi*an)/180))/g; //Tempo de Movimento
	 	hM = (pow(v0*sin((pi*an)/180),2))/(2*g); //Altura máxima
		alc = (pow(v0,2)*sin(2*(pi*an)/180))/g; //Alcance
		printf("\nInformações processadas. Seguindo para resultados.\n\n");
		system("PAUSE");
		Resultado(0, v0, an, t, alc, hM, 2);
	}
}

void Resultado(float h0, float v0, float an, float t, float x, float hM, int FLAG)
{
	int q = 0, q2 = 0;
	float tt, vy, v;
	titulo();
	if(FLAG == 1)
	{
		printf("- - - Lançamento Vertical - - -\n\n");
		printf("Valores inseridos:\nAltura inicial: %fm\nVelocidade inicial: %fm/s\n\n", h0, v0);
		printf("Resultados obtidos:\nTempo de queda: %fs *\nVelocidade Final: %fm/s\n", t, x);
		if(v0 > 0)
			printf("Altura máxima: %fm\n\n", hM);
		printf("* Nas situações onde h0 > 0 e v0 > 0 (indicando um lançamento), o inicio e o fim do movimento se dão em");
		printf(" alturas diferentes. Para fins de cálculo, será considerado apenas o Tempo de Queda.\n\n");
	}
	if(FLAG == 2)
	{
		printf("- - - Lançamento Inclinado - - -\n\n");
		printf("Valores inseridos:\nAltura inicial: %fm\nVelocidade inicial: %fm/s\nAngulo com a horizontal: %f°\n\n", h0, v0, an);
		printf("Resultados obtidos:\nTempo de Movimento: %fs\nAltura máxima: %fm\nAlcance: %fm\n\n", t, hM, x);
	}
	system("PAUSE");
	
	printf("\nDeseja realizar simulação com algum valor de T(tempo)?\n");
	printf("Digite 1 para SIM, e 2 para NÂO.\n");
	do
	{
		printf("Opção: ");
		scanf("%d",&q);
		if(q != 1 && q != 2)
		{
			printf("\nOpção inválida. Tente novamente.\n\n");
		}
	}
	while(q != 1 && q != 2);
	
	if(q == 1)
	{
		do
		{
			printf("\nIniciando processo de simulação.\n\n");
			do
			{
				fflush(stdin);
				printf("Digite o valor de T [ 0 < T < %f ] -> USE VIRGULA PARA DECIMAL <- : ",t);
				scanf("%f",&tt);
				if(tt <= 0 || tt >= t)
				{
					printf("\nValor fora do intervalo ou PONTO utilizado. Tente novamente.\n\n");
				}
			}
			while(tt <= 0 || tt >= t);
			
			printf("\nValor aceito. Prosseguindo para resultados.\n\n");
			system("PAUSE");
			
			if(FLAG == 1)
			{//Vertical
				printf("\n- - - Lançamento Vertical - - -\n\n");
				if(h0 != 0 && v0 <= 0)
				{
					vy = v0 + g*tt*(-1);
				}
				else
				{
					if(v0 > 0)
					{
						vy = g*tt*(-1);
					}
				}
				printf("Simulação realizada.\nResultados obtidos para T = %fs :\n\nVy = %fm/s *\n\n", tt, vy);
				printf("*Lançamento vertical. Simulação considerando apenas o tempo de queda.\n\n");
				system("PAUSE");
			}
			if(FLAG == 2)
			{//Obliquo
				printf("\n- - - Lançamento Inclinado - - -\n\n");
				vy = v0*sin(pi*an/180)-g*tt;
				v = sqrt(pow(vy,2)+pow(v0*(cos(pi*an/180)),2));
				printf("Simulação realizada.\nResultados obtidos para T = %fs :\n\nVy = %fm/s\n|V| = %fm/s\n\n", tt, vy, v);
				system("PAUSE");
			}
			printf("\nDeseja realizar uma simulação com outro valor de T(tempo)?\n");
			printf("Digite 1 para SIM, e 2 para NÂO.\n");
			do
			{
				printf("Opção: ");
				scanf("%d",&q2);
				if(q2 != 1 && q2 != 2)
				{
					printf("\nOpção inválida. Tente novamente.\n\n");
				}
			}
			while(q != 1 && q != 2);
		}
		while(q2 == 0 || q2 != 2);
		printf("\nOperações finalizadas. Voltando para o menu inicial.\n\n");
		system("PAUSE");
	}
	
	if(q == 2)
	{
		printf("\nVocê escolheu não realizar uma simulação. Voltando para o menu inicial.\n\n");
		system("PAUSE");
	}	
}