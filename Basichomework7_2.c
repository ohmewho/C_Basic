#include <stdio.h>
#include <string.h>
#define N 100

int main(){
	char astr[N], gpsid[7], utc[7], str[N], status;
	int checksum, csum, idcheck, iter, hh, mm, ss, d_utc;
	gets(astr);	

	while(strcmp(astr, "END")){
		
		sscanf(astr,"$%[^,],%[^.].%*[^,],%c,%*s", gpsid, utc, &status);
		idcheck = strcmp(gpsid, "GPRMC");
//		printf("gpsid: %s\nutc: %s\n%c\n", gpsid, utc, status);
	
		if(!idcheck && status == 'A'){
			
			sscanf(astr,"$%[^*]*%x", str, &csum);
//			printf("csum is %d\n", csum);
			for(iter = 0; iter < strlen(str); iter++){
				if(iter == 0) checksum = str[iter];	
				else checksum ^= str[iter];
			}
			checksum %= 65536;
//			printf("checksum is %d\n",checksum);
//			printf("%d\n", checksum == csum);
			if(checksum == csum){
				sscanf(utc, "%d", &d_utc);
				hh = (d_utc / 10000 + 8) % 24;
				mm = d_utc % 10000 / 100;
				ss = d_utc % 100;		
			}
		}
				
		gets(astr);	
		
	}	
	printf(/*"Beijing time: "*/"%02d:%02d:%02d\n", hh, mm, ss);	
	
	return 0;
}
