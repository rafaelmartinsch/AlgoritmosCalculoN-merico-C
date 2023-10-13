/*
 ============================================================================
 Name        : AprocimacaoStirling.c
 Author      : Rafael Martins Chimenes
 Version     : _
 Copyright   : Open Source
 Description : Considerando uma entrada n que seja 1>=n<=10 o programa retorna
 	 	 	   o fatorial de n(n!), a aproximação stirling de n(Sn),
 	 	 	   o erro absoluto e erro relativo entre os valore de n! e Sn.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Stirling(double n);
double Fatorial(double n);

int main(void) {
	double n=0;
	double Sn;
	double Nfat;
	double EA;
	double ER;

	do{
		puts("Entre com um valo para n que esteja entre 1 a 10:"); /* prints !!!Hello World!!! */
		scanf("%lf",&n);
	}while(n>10 && n<1);
	printf("\n\n");

	Sn = Stirling(n);
	Nfat = Fatorial(n);

	printf("n:%.lf\n",n);
	printf("n!:%.lf\n",Nfat);
	printf("Sn:%lf\n",Sn);

	//erro Absoluto
	if(Nfat>Sn)
		EA=Nfat-Sn;
	else
		EA=Sn-Nfat;
	//erro Relativo
	ER=EA/Sn;

	printf("EA:%lf\n",EA);
	printf("ER:%lf\n",ER);

	return EXIT_SUCCESS;
}

double Stirling(double n){

	return sqrt(2*M_PI*n)*pow((n/M_E),n);
}

double  Fatorial(double n){
	if(n==1)
		return 1;
	else
		return n * Fatorial(n-1);
}
