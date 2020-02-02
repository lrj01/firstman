#include<stdio.h>
#include<string.h>
#define MAXLEN 101
int decrypt(char name[]);
int main()
{   
	char name[MAXLEN];
	printf("Enter name in NATO alphabet: \n");
	fgets(name, MAXLEN, stdin);
	
	int len=strlen(name);
	if(name[len-1]=='\n')
		name[len-1]='\0';
	
	decrypt(name);
    
	if(decrypt(name)==1)
		printf("Decrypted name: %s\n", name); 
	else
		printf("The given name cannot be decrypted.\n");


	return 0;
}
int decrypt(char name[])
{  
	char alphabet[26][MAXLEN] = {
	"ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO",
	"FOXTROT", "GOLF", "HOTEL", "INDIA", "JULIETT",
	"KILO", "LIMA", "MIKE", "NOVEMBER", "OSCAR",
	"PAPA", "QUEBEC", "ROMEO", "SIERRA", "TANGO",
	"UNIFORM", "VICTOR", "WHISKEY", "XRAY", "YANKEE",
	"ZULU"};
	char temp[MAXLEN];
	int i,j,count=0;
	
		for(i=0;i<strlen(name);i++)
		{ 

			int len=strlen(alphabet[name[i]-'A']);
	        for(j=0;j<len;j++)
			{  printf(" %d %d %c %c\n",j,len,name[i+j],alphabet[name[i]-'A'][j]);
				if(name[i+j]!=alphabet[name[i]-'A'][j])
				{  
				    return 0;
				}
				if(j==len)
					break;


			}
			temp[count++]=alphabet[name[i]-'A'][0];
			i=i+j-1;
		}
	
	
	temp[count]='\0';
	strcpy(name,temp);

	return 1;
}
