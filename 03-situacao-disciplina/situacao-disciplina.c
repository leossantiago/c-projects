#include<stdio.h>
int main(){
	int horas, credito, n;
	while(1){
	inicio:
	printf("Digite a quantidade de horas da disciplina:\n");
	scanf("%d",&horas);
	credito = horas/15;
	switch(credito){
		case 1: n = 2;
		break;
		case 2: n = 2;
		break;
		case 3: n = 2;
		break;
		case 4: n = 3;
		break;
		case 6: n = 4;
		break; 
		default: printf("Credito invalido\n");
		         goto inicio;
		break;
	}
	float notas[n], media,mediaEF, soma = 0, EF;
	for(int i = 0;i<n;i++){
		printf("Digite suas notas\n");
		scanf("%f",&notas[i]);
		soma = soma + notas[i];
		printf("Soma = %.1f\n",soma);
	}
	media = soma/n;
	printf("Sua media e': %.1f\n",media);
	if(media <4) printf("Reprovado\n");
	if(media>4 && media < 7){
		printf("Nota do Exame Final:\n");
		scanf("%f", &EF);
		mediaEF = (media+EF)/2;
		if(mediaEF <6){
          printf("Media do EF: %.1f\n",mediaEF);
		  printf("Reprovado\n");
		}
		else {
          printf("Media do EF: %.1f\n",mediaEF);
		  printf("Aprovado\n");
		}	
	}
	if(media>=7 && media<=10) printf("Aprovado\n");
	}
}