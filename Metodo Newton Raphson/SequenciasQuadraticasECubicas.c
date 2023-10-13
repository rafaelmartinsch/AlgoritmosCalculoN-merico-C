#include<stdio.h>
#include<math.h>

void main(){
	
	int i,exp;
	double erro, erro2;
	
	for(i=1;;i++){
		exp=pow(2,i)-1;
		erro = pow(0.5,exp);
		
		exp=(pow(3,i)-1)/2;
		erro2 = pow(0.5,exp);
		
		printf("%d - %e - %e\n",i,erro, erro2);
		if(erro==0)
			return;
	}
	
}