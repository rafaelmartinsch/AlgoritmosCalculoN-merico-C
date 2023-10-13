#include<stdio.h>
#include<math.h>

double f(double x){
	
	//return (pow(M_E,(6*x)))+(1.441*pow(M_E,(2*x)))-(2.079*pow(M_E,4*x))-(0.333);//ex a
	return (pow(M_E,(6*x))) + (3*pow((log(2)/log(M_E)),2)*pow(M_E,(2*x))) - ((log(8)/log(M_E))*pow(M_E,(4*x))) - pow((log(2)/log(M_E)),3);//ex b
}

double df(double x){

	//return (6*pow(M_E,(6*x)))-(8.316*pow(M_E,(4*x)))+(2.882*pow(M_E,2*x));//ex a
	return (6*pow(M_E,(6*x)))-(4*log(8)*pow(M_E,(4*x)))+(6*(pow(log(2),2))*pow(M_E,2*x));//ex b
}

double ddf(double x){

	//return (36*pow(M_E,(6*x)))-(33.264*pow(M_E,(4*x)))+(5.764*pow(M_E,2*x));//ex a
	return (36*pow(M_E,(6*x)))-(16*log(8)*pow(M_E,(4*x)))+(12*(pow(log(2),2))*pow(M_E,2*x));//ex b
}

void main(){
	
	double p0, p, E;//tolerancia
	int i,N;//iterações
	
	printf("Aproximacao Inicial:\n p0: ");
	scanf("%lf",&p0);
	
	printf("Tolerancia: ");
	scanf("%lf",&E);
	
	printf("Numero de Iteracoes: ");
	scanf("%d",&N);
	
	for(i=1;i<=N;++i){
		p = p0 - (f(p0)*df(p0))/pow(df(p0),2)-f(p0)*ddf(p0);
		//printf("\n n%d | pn:%lf | f(pn):%e ",i-1,p0,f(p0));
		printf("\n%lf",p0);
		if(fabs(p-p0)<E ){
			printf("\n\nSucesso, com %d",i-1);
			return;
		}
		p0=p;
	}
	
	printf("\n\nfalhou!");

}