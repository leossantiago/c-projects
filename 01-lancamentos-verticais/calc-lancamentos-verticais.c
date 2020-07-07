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
		printf("Digite a op��o desejada: ");
		scanf("%c",&op);
		switch(op)
		{
			case '1' :
				printf("\nOp��o escolhida: Realizar simula��o.\n\n");
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
				printf("\nOp��o inv�lida.\n\n");
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
	printf("		Simulador de Lan�amento de Proj�teis\n\n");
};

void menu()
{
	printf("   Escolha uma op��o:\n\n");
	printf("1. Realizar simula��o \n");
	printf("2. Encerrar o sistema \n\n");
};

void menu2()
{
	char op;
	do
	{
		titulo();
		printf("   Escolha uma fun��o: \n\n");
		printf("1. Lan�amento vertical \n");
		printf("2. Lan�amento com inclina��o \n");
		printf("3. Cancelar \n\n");
		printf("Digite a op��o desejada: ");
		scanf("%c",&op);
		switch(op){
			case '1' :
				printf("\nOp��o escolhida: Lan�amento Vertical.\n\n");
				fflush(stdin);
				system("PAUSE");
				LancamentoVertical();
				fflush(stdin);			
				break;
			case '2' :
				printf("\nOp��o escolhida: Lan�amento Inclinado.\n\n");
				fflush(stdin);
				system("PAUSE");
				LancamentoInclinado();
				break;
			case '3' :
				printf("\nAbortando opera��es. Voltando para o menu inicial.\n\n");
				fflush(stdin);
				system("PAUSE");
				break;
			default :
				printf("\nOpcao inv�lida.\n\n");
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
		printf("- - - Lan�amento Vertical - - -\n\n");
		printf("Digite a altura inicial: ");
		scanf("%f",&h0);
		printf("Digite a Velocidade inicial: ");
		scanf("%f",&v0);
		if(h0 >= 0)
		{
			if((h0 == 0 && v0 > 0) || h0 != 0)
			{
				ok = 1;
				printf("\nInforma��es aceitas. Seguindo para processamento.\n\n");
				system("PAUSE");
				Processamento(h0, v0, 90, 1);
			}
			else
			{
				printf("\nInforma��es incoerentes. Tente novamente.\n\n");
				system("PAUSE");
			}
		}
		else
			{
				printf("\nInforma��es incoerentes. Tente novamente.\n\n");
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
		printf("- - - Lan�amento Inclinado - - -\n\n");
		printf("Digite a Velocidade inicial (M/S): ");
		scanf("%f",&v0);
		printf("Digite o �ngulo (0 a 90 graus) formado com a horizontal: ");
		scanf("%f",&an);
		if((v0 > 0) && (an >= 0 && an <= 90))
		{
			ok = 1;
			printf("\nInforma��es aceitas. Seguindo para processamento.\n\n");
			system("PAUSE");
			Processamento(0, v0, an, 2);
		}
		else
		{
			printf("\nInforma��es incoerentes. Tente novamente.\n\n");
			system("PAUSE");
		}
	}
	while(ok == 0);
};

void Processamento(float h0, float v0, float an, int FLAG){
	if( FLAG == 1) //Lan�amento Vertical.
	{
		float t, vF, hM;
		if(h0 == 0)
		{//Lan�amento + Queda.
			t = v0/g; //Tempo de subida = Tempo de descida.
			hM = pow(v0,2)/(2*g); //Altura m�xima.
			vF = v0; //A part�cula atingir� o solo com a mesma velocidade inicial.
		}
		else 
		{
			if(h0 > 0 && v0 > 0)
			{//Lan�amento + Queda. h0 > 0
				hM = (pow(v0,2)/(2*g))+h0; //Altura M�xima.
				t = sqrt((2*hM)/g); //Tempo de queda.
				vF = g*t; //Velocidade final (solo).
			}
			else
			{//Queda
				hM = h0; //Altura m�xima j� � a atual. N�o h� lan�amento
				vF = (-1)*sqrt(pow(v0,2)+2*g*hM); //Velocidade final (solo)
				t = (v0-vF)/g; //Tempo de queda.
			}
		}
		printf("\nInforma��es processadas. Seguindo para resultados.\n\n");
		system("PAUSE");
		Resultado(h0, v0, an, t, vF, hM, 1);
	}
	if( FLAG == 2) 
	{//Lan�amento Inclinado.
		float t, hM, alc;
		
	 	t = 2*(v0*sin((pi*an)/180))/g; //Tempo de Movimento
	 	hM = (pow(v0*sin((pi*an)/180),2))/(2*g); //Altura m�xima
		alc = (pow(v0,2)*sin(2*(pi*an)/180))/g; //Alcance
		printf("\nInforma��es processadas. Seguindo para resultados.\n\n");
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
		printf("- - - Lan�amento Vertical - - -\n\n");
		printf("Valores inseridos:\nAltura inicial: %fm\nVelocidade inicial: %fm/s\n\n", h0, v0);
		printf("Resultados obtidos:\nTempo de queda: %fs *\nVelocidade Final: %fm/s\n", t, x);
		if(v0 > 0)
			printf("Altura m�xima: %fm\n\n", hM);
		printf("* Nas situa��es onde h0 > 0 e v0 > 0 (indicando um lan�amento), o inicio e o fim do movimento se d�o em");
		printf(" alturas diferentes. Para fins de c�lculo, ser� considerado apenas o Tempo de Queda.\n\n");
	}
	if(FLAG == 2)
	{
		printf("- - - Lan�amento Inclinado - - -\n\n");
		printf("Valores inseridos:\nAltura inicial: %fm\nVelocidade inicial: %fm/s\nAngulo com a horizontal: %f�\n\n", h0, v0, an);
		printf("Resultados obtidos:\nTempo de Movimento: %fs\nAltura m�xima: %fm\nAlcance: %fm\n\n", t, hM, x);
	}
	system("PAUSE");
	
	printf("\nDeseja realizar simula��o com algum valor de T(tempo)?\n");
	printf("Digite 1 para SIM, e 2 para N�O.\n");
	do
	{
		printf("Op��o: ");
		scanf("%d",&q);
		if(q != 1 && q != 2)
		{
			printf("\nOp��o inv�lida. Tente novamente.\n\n");
		}
	}
	while(q != 1 && q != 2);
	
	if(q == 1)
	{
		do
		{
			printf("\nIniciando processo de simula��o.\n\n");
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
				printf("\n- - - Lan�amento Vertical - - -\n\n");
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
				printf("Simula��o realizada.\nResultados obtidos para T = %fs :\n\nVy = %fm/s *\n\n", tt, vy);
				printf("*Lan�amento vertical. Simula��o considerando apenas o tempo de queda.\n\n");
				system("PAUSE");
			}
			if(FLAG == 2)
			{//Obliquo
				printf("\n- - - Lan�amento Inclinado - - -\n\n");
				vy = v0*sin(pi*an/180)-g*tt;
				v = sqrt(pow(vy,2)+pow(v0*(cos(pi*an/180)),2));
				printf("Simula��o realizada.\nResultados obtidos para T = %fs :\n\nVy = %fm/s\n|V| = %fm/s\n\n", tt, vy, v);
				system("PAUSE");
			}
			printf("\nDeseja realizar uma simula��o com outro valor de T(tempo)?\n");
			printf("Digite 1 para SIM, e 2 para N�O.\n");
			do
			{
				printf("Op��o: ");
				scanf("%d",&q2);
				if(q2 != 1 && q2 != 2)
				{
					printf("\nOp��o inv�lida. Tente novamente.\n\n");
				}
			}
			while(q != 1 && q != 2);
		}
		while(q2 == 0 || q2 != 2);
		printf("\nOpera��es finalizadas. Voltando para o menu inicial.\n\n");
		system("PAUSE");
	}
	
	if(q == 2)
	{
		printf("\nVoc� escolheu n�o realizar uma simula��o. Voltando para o menu inicial.\n\n");
		system("PAUSE");
	}	
}