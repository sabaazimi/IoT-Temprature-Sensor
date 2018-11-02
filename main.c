#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
	char add1[21] = "/sys/bus/w1/devices/";
	char add2[10] = "/w1_slave";
	
	char str[100]="";
	//FILE *fp;
	
	if (argc !=2)
	{
		fprintf(stderr, "usage: %s text \n", argv[0]);
		exit(1);
		}
		
	//p = argv[1];
		
		 strcat(str,add1);
		 strcat(str,argv[1]); 
		 strcat(str,add2);
		 printf("%s\n",str);

	
//fp = fopen(str,"r");

//~ if (fp == NULL)
//~ {
	//~ printf("ERROR file");
	//~ }
	
	return 0;
}

