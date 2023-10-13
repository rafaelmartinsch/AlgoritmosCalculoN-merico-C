#include<stdio.h>
#include <math.h>

double f(double x);

void main(){
	
	double a, b;
	double TOL;//tolerancia
	int N;//iterações
	
	double p, FA, FP;
	int i;
	
	printf("Insira o intervalo:\n a: ");
	scanf("%lf",&a);
	printf(" b: ");
	scanf("%lf",&b);
	
	printf("Tolerancia: ");
	scanf("%lf",&TOL);
	printf("Numero de Iteracoes: ");
	scanf("%d",&N);

	FA = f(a);
	
	for(i=1;i<=N;i++){
		p=a+(b-a)/2;
		FP = f(p);
		printf("\n n%d | a:%lf | b:%lf | p:%lf | f(p):%lf",i,a,b,p,FP);
		
		if(FP==0 || ((b-a)/2)<TOL){
			printf("\n\nSucesso!");
			return;
		}
		FA = f(a);
		if(FA * FP <0)
			b=p;
		else
			a=p;
		
	}
	printf("\n\nfalhou!");
}

double f(double x){
	
	return pow(x,3)-x-1;
	
}