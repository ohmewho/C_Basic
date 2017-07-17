#include <stdio.h>	


int main(int argc, char* argv[]){
	char ach;
	int length = 0, printflag = 0;
	ach = getchar();
	while(ach != '.'){

		if( ach != ' '){
			length++;
		}
		
		else {
			if(length != 0) {
				if(!printflag) {
					printflag = 1;
				}
				else printf(" ");
				printf("%d", length);
				length = 0;
			}
			
		}
		 
		ach = getchar();

	}
	if(length != 0) {
		if(printflag){
			printf(" ");
		}
		printf("%d", length);
	}
	return 0;
}



