

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
	//char fl[];
	char *p;
	//int i = 0;
	if (argc !=2)
	{
		fprintf(stderr, "usage: %s text \n", argv[0]);
		exit(1);
		
		
		}
		
	p = argv[1];
	/*while(*p)
	{
		
		fl[i] = *p;
		//printf("%c", fl);
		p++;
		i++;
		
		}*/
	printf("\n");
	printf("%s\n", p);
	
	return 0;
}

