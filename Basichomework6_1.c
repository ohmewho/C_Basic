#include <stdio.h> 
#define N 101

int main(){
	int iter, expon, coe, maxexpon = 0, first = 1, nonzero = 0;
	int coes[N] = {0};
//	for(iter = 0; iter < N; iter++){
//		printf("%d_", coes[iter]);
//		if((iter + 1) % 10 == 0) printf("\n");
//	}
	
	for(iter = 0; iter < 2; iter++){
		do{
			scanf("%d %d", &expon, &coe);
			if(maxexpon < expon) maxexpon = expon;
			coes[expon] += coe;
		}while(expon != 0);		
	}
	

	for(iter = maxexpon; iter >= 0; iter--){
		if(coes[iter]) {
			if(iter > 0) {
				if(!nonzero) nonzero = 1;
			}
			if(first) {
				if(coes[iter] == -1) printf("-");
				else if(coes[iter] != 1) printf("%d", coes[iter]);
				first = !first;
			}
			else {
				if(iter != 0){
					if(coes[iter] > 0){
						printf("+");
						if(coes[iter] != 1) printf("%d", coes[iter]);
					}
					else {
						if(coes[iter] == -1) printf("-");
						else printf("%d", coes[iter]);
					}	
				}
				else {
					if(coes[iter] > 0) printf("+");
					printf("%d", coes[iter]);
				}
			}
			if(iter > 0) printf("x");
			if(iter > 1) printf("%d", iter);	
		}
			
		
	}
	if(!nonzero) printf("%d", coes[0]);	
	return 0;
}
