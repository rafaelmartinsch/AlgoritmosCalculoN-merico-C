#include<stdio.h>

int main(){

	int n,i,j;
	double P;
	
	printf("P que deseja aproximar:\n");
	scanf("%lf",&P);
	printf("Quantidades de pontos:\n");
	scanf("%d",&n);
	
	double X[n];
	double F[n][n];
	
	printf("Pontos Xn:\n");
	for(i=0;i<n;i++){
		scanf("%lf",&X[i]);
	}
	
	printf("Pontos f(Xn):\n");	
	for(i=0;i<n;i++){
			scanf("%lf",&F[i][0]);
	}
	
	for(i=1;i<n;i++){
		for(j=1;j<=i;j++){
			F[i][j]=( F[i][j-1]-F[i-1][j-1] )/(X[i]-X[i-j]);
		}
	}
	
	
	printf("\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			printf("%.8f   ", F[i][j]);
		}
		printf("\n");
	}
	
	

return 0;
}