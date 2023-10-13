#include<stdio.h>

int main(){
	
	int n,i,j;
	scanf("%d",&n);
	double x[n+1], y[n+1], h[n+1], alfa[n+1];
	double a[n+1],b[n+1],c[n+1],d[n+1];
	double l[n+1],z[n+1],u[n+1];
	for(i=0;i<=n;i++)
			scanf("%lf",&x[i]);
	for(i=0;i<=n;i++)
			scanf("%lf",&y[i]);
		
		
	
	for(j=0;j<n;j++){
		h[j]=x[j+1]-x[j];
		a[j]=y[j];
	}
	a[n]=y[n];
	
	for (i=1; i < n; i++){
         alfa[i] = (3.0/h[i])*(a[i+1] - a[i]) - (3.0/h[i-1])*(a[i] - a[i-1]);
     }

	
	l[0]=1.0; u[0]=0.0; z[0]=0.0;
	l[n]=1.0; z[n]=0.0; c[n]=0.0;
	
	
	for (i=1; i < n; i++){
         l[i] = 2.0*(x[i+1] - x[i-1]) - h[i-1]*u[i-1];
         u[i] = h[i]/l[i];
         z[i] = (alfa[i] - h[i-1]*z[i-1])/l[i];
     }

	
	//delta=z gama=u beta=l
	
	for (j=n-1; j >=0 ; j--){
         c[j] = z[j] - u[j]*c[j+1];
         b[j] = (a[j+1] - a[j])/h[j] - h[j]*(c[j+1] + 2.0*c[j])/3.0;
         d[j] = (c[j+1] - c[j])/(3*h[j]);
     }

	
	
	/***** SAIDAS *****/
	printf("\n\nx:\n");
	for(i=0;i<=n;i++)
			printf("%.8f  ", x[i]);
	printf("\n\ny:\n");
	for(i=0;i<=n;i++)
			printf("%.8f  ", y[i]);
	printf("\n\nh:\n");
	for(i=0;i<n;i++)
			printf("%.8f  ", h[i]);
	printf("\n\na:\n");
	for(i=0;i<=n;i++)
			printf("%.8f  ", a[i]);
		
	printf("\n\n-----------------------------------------------\n");
	printf("\n\nb:\n");
	for(i=0;i<n;i++)
			printf("%.10f  ", b[i]);
	printf("\n\nc:\n");
	for(i=0;i<n;i++)
			printf("%.10f  ", c[i]);
	printf("\n\nd:\n");
	for(i=0;i<n;i++)
			printf("%.10f  ", d[i]);

}