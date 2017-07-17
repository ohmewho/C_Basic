#include <stdio.h>
#include <string.h>
#define N 200

int main(){
	char astr[N];
	int iter, len = 0, start = 0, first = 1, lcount = 0;
	
	gets(astr);
	
//	puts(astr);
	
	for(iter = 0; iter < strlen(astr); iter++){
		if(astr[iter] != '.') len++;
		else break;	 	
	}
	
	for(iter = 0; iter < len; iter++){
		if(!start) {
			if(astr[iter] != ' ') {
				start = !start;
				lcount++;	
			}
		}
		else{//单词已经开始计数 
			if(astr[iter] != ' ') lcount++;
			
			else {
				if(first) first = !first;
				else printf(" ");
				printf("%d", lcount);
				lcount = 0;
				start = !start;
			}
			
			
		}
	}
	
	if(start && len > 0){
		if(first) first = !first;
		else printf(" ");
		printf("%d", lcount);
	}
	

	
	
//	
//	printf("%d\n", ++*p);
		
	
	return 0;
}

