#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 1000

// mwget [file] [file_name] [start_range]

char buffer1[CAPACITY];
char buffer2[CAPACITY];
int buffer3;

void arg0();

void arg2(char file[], char file_name[]);

void arg3(char file[], char file_name[], int start_range);

void fileio(char file[], char file_name[], int start_range);

int main(int argc, char* argv[])
{
	switch (argc)
	{
		case 3:
			strcpy(buffer1, argv[1]);
			strcpy(buffer2, argv[2]);
			
			arg2(buffer1, buffer2);
			break;
		
		case 4:
			strcpy(buffer1, argv[1]);
			strcpy(buffer2, argv[2]);
			sscanf(argv[3], "%d", &buffer3);
			
			arg3(buffer1, buffer2, buffer3);
			break;
		
		default:		
			arg0();
			break;
	}
	return(0);
}


void fileio(char file[], char file_name[], int start_range)
{
	char* input_array[CAPACITY];
	char* output_array[CAPACITY];
	
	FILE* pfile = fopen(file, "r+");
	
	int i;
	for (i  = 0; i < CAPACITY; i++)
	{
		input_array[i] = malloc(sizeof(char*) * CAPACITY);
		output_array[i] = malloc(sizeof(char*) * CAPACITY);
	}
	
	int iterator = 0;
	do
	{
		fscanf(pfile, "%s", input_array[iterator++]);
	}
	while(!(feof(pfile)));
	
	rewind(pfile);
	
	for (i = 0; i < iterator; i++)
	{
		sprintf(output_array[i], "wget -O %s%d %s", file_name, start_range++, input_array[i]);
		fprintf(pfile, "%s\n", output_array[i]);
	}
	
	for (i = 0; i < CAPACITY; i++)
	{
		input_array[i] = NULL;
		free(input_array[i]);
		
		output_array[i]  = NULL;
		free(output_array[i]);
	}
	
	fclose(pfile);
}

void arg0()
{
	printf("\nmwget: Mass wget tool. Transforms links in a [.sh] file to embedded wget commands with sequential file naming.");
	printf("\n\nusage: mwget [(.sh) file] [file name] [file number{start range}]\n\n");
}

void arg2(char file[], char file_name[])
{
	fileio(file, file_name, 1);
}

void arg3(char file[], char file_name[], int start_range)
{
	fileio(file, file_name, start_range);
}