#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ifttt.h"


void waitfor(time_t secs){
	
unsigned int retTime = time(0)+secs;
while(time(0) < retTime); 	
	
	
	}




int main(int argc, char **argv)
{
	char add1[21] = "/sys/bus/w1/devices/";
	char add2[10] = "/w1_slave";
	int ch;
	char temp[5];
	char str[100]="";
	char address[100];
	char data[100];
	float tmax=0,tmin=100,temp1=25;
	
	FILE *fp;
	
	strcat(str,add1);
		 strcat(str,argv[1]); 
		 strcat(str,add2);
		 //printf("%s\n",str);
		 sprintf(address,"%s",str);
	
	
	if (argc !=2)
	{
		fprintf(stderr, "usage: %s text \n", argv[0]);
		exit(1);
		}
		
	for(;;){
		
		 waitfor(1);
		 fp = fopen(address,"r");
		 //printf("file opened\n");
		 int i = 0;
		 while((ch=fgetc(fp))!=EOF)
		 {
			 data[i] =ch;
			i++;
					 }
		fclose(fp);
		//printf("the data is \n%s",data);
		strncpy(temp,strstr(data, "t=") +2 ,5);
		float tempC = strtof(temp,NULL);
		tempC=(tempC)/1000;
		//printf("\nthe temp in the file read is \n%2.3f\n", tempC);
		
		if(tempC>tmax)
		tmax=tempC;
		if(tempC<tmin)
		tmin=tempC;
		printf("temp is %2.3f \nmax is %2.3f\nmin is %2.3f\n\n\n",tempC, tmax, tmin);
		
		if(abs(temp1-tempC)>=1)
		{
			char tempCifttt[10]="",tmaxifttt[10]="",tminifttt[10]="";
			temp1=tempC;
			printf("trying to connect\n\n");
			gcvt(tempC,6,tempCifttt);
			gcvt(tmax,6,tmaxifttt);
			gcvt(tmin,6,tminifttt);
			ifttt("https://maker.ifttt.com/trigger/alarm_triggered/with/key/cOHWoBOVnz2E_7xPiNLBga", tempCifttt,tmaxifttt,tminifttt);
			
			}
			
		
		
	}
	
	return 0;
}

