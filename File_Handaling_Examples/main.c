/*
	Author   : Rohit Singh
	Purpose : To implement File Handling.
*/
#include <stdio.h>

int main(int argc, char **argv)
{
	// This is a file pointer.
	FILE *fp;
	char ch;
	
	// Example of write something into a file.
	
	// char * fopen(char *,char mode);     This will open file in write mode.
	fp = fopen("file.txt","w+");
	
	// We check if the file is open or not. If not then fp == NULL.
	if(fp)
	{
		// int fprintf(FILE *,char *, arg1,arg2,........argn);
		fprintf(fp,"Hello this is an Example of File \nThis is new line.\n");
		// void fclose(FILE *);           This will close the file.
		fclose(fp);
	}
	
	// Initialise file pointer after work is done.
	fp = NULL;       // NULL is equivalent to 0 and it is used to initialise any pointer.
	
	// Example of read a file and print it's content.
	fp = fopen("file.txt","r");
	if(fp)
	{
		// EOF is the last character of a file and it's value is  equivalent to -1.
		while(ch != EOF)
		{
			// char fgetc(char *stream);
			ch = fgetc(fp);
			printf("%c",ch);
		}
		fclose(fp);
	}
	
	
	// Example of reverse printing content of any file.
	fp = NULL;
	int i = 0,cnt = 0;
	fp = fopen("file.txt","r");  // Open in read mode.
	if(fp)
	{
		/* 
			 void fseek(char *stream,int offset( where to go), int POSITION);         
			  
			 position are as follows : 
			 SEEK_SET = 0
			 SEEK_CUR = 1
			 SEEK_END = 2
		*/
		fseek(fp,0,SEEK_END);
		
		// long int ftell(char *stream);
		cnt = ftell(fp); // This will return the current position of the cursor.
		while(i <= cnt + 1)
		{
			ch = fgetc(fp);
			printf("%c",ch);
			fseek(fp,-i,SEEK_END);
			i++;
		}
		printf("\n");
		fclose(fp);
	}
	return 0;
}
/*
	Some of the file functions : -
	 fprintf();
	 fscanf();
	 fgets();
	 fputs();
	 fgetc();
	 fputc();
	 fseek();
	 ftell();
	 fread();
	 fwrite();
*/