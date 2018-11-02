#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	
	FILE *fp;
	
	
	fp = fopen("h1.txt","r");
	char sin[150];
	
	while(!feof(fp)){
		fgets(sin, 150, fp);
		 puts(sin);
		
		}
	
	fclose(fp);
	
	
return 0;

}
