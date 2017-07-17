#include <stdio.h>

int main(){
	
	char ch;
	int printflag , len = 0, first = 1;
	
	scanf("%c", &ch);
	while(ch == ' '){
		scanf("%c", &ch);
	}
	if(ch != '.'){
		do{		
			if(ch != ' '){
				len++;
				if(!printflag) printflag = 1;
			}
			else {
				if(printflag){
					if(first) first = 0;
					else printf(" ");
					printf("%d", len);
					len = 0;
					printflag = 0;	
				}
			}			
			scanf("%c", &ch);
			if(ch == '.') {
				
				if(printflag){
					if(first) first = 0;
					else printf(" ");
					printf("%d", len);	
				}
			}		
		}while(ch != '.');
	}	
		
	
	return 0;
}
