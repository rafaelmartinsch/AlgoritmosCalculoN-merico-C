#include<stdio.h>

int main(){

	int n,i,j;
	double P;
	
	printf("P que deseja aproximar:\n");
	scanf("%lf",&P);
	printf("Quantidades de pontos:\n");
	scanf("%d",&n);
	
	double X[n], Y[n];
	double Q[n][n];
	
	printf("Pontos Xn:\n");
	for(i=0;i<n;i++){
		scanf("%lf",&X[i]);
	}
	
	printf("Pontos f(Xn):\n");
	for(i=0;i<n;i++){
		scanf("%lf",&Y[i]);
	}
	
	for(i=0;i<n;i++){
			Q[i][0]=Y[i];
		}
	
	for(i=1;i<n;i++){
		for(j=1;j<=i;j++){
			Q[i][j]=(( (P-X[i-j])*Q[i][j-1] )-( (P-X[i])*Q[i-1][j-1] ))/(X[i]-X[i-j]);
		}
	}
	
	
	printf("\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			printf("%2.7lf   ", Q[i][j]);
		}
		printf("\n");
	}
	
	

return 0;
}