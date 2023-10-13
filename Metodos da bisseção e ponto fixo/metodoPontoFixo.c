#include<stdio.h>
#include <math.h>

double g1(double x);
double g2(double x);
double g3(double x);
double g4(double x);

void main(){
	
	double p0;
	double TOL;//tolerancia
	int i,N;//iterações
	double p;
	
	printf("Aproximacao Inicial:\n p0: ");
	scanf("%lf",&p0);
	
	printf("Tolerancia: ");
	scanf("%lf",&TOL);
	
	printf("Numero de Iteracoes: ");
	scanf("%d",&N);
	
	for(i=1;i<=N;++i){
		
		p=g4(p0);
		
		printf("\n n%d | p:%lf ",i,p);
		
		if(fabs(p-p0)<TOL ){
			printf("\n\nSucesso!");
			return;
		}
		
		p0=p;
		
	}
	printf("\n\nfalhou!");
	
	
}

double g1(double x){
	
	return pow(x,3)-1;
}

double g2(double x){
	
	x= 1+x;
	return -cbrt(x);
}

double g3(double x){
	
	return -pow(x,3)+(2*x)+1;
}

double g4(double x){
	
	return sqrt((1/x)+1);
}