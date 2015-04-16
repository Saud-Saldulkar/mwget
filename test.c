#include <stdio.h>
#include <string.h>

void fileio(char file_name[], int start_range)
{
	char* line_var[1000];
	char* temp_var[1000];
	
	FILE* pfile = fopen(file_name, "r");
	
	int iterator = 0;
	while(!(feof(pfile))) 
	{
		fscanf(pfile, "%s", line_var[iterator]);
		printf("%s\n", line_var[iterator++]);
	}
	
	// int i;
	// for (i = 0; i <= iterator; i++)
	// {
		// sprintf(temp_var[i], "wget -O %s%d %s", file_name, i, line_var[i]);
		// printf("%s\n", temp_var[i]);
	// }
	
	fclose(pfile);
}


int main()
{
	fileio("list.txt", 1);
	
	return(0);
}



// sprintf(temp_var, "wget -O %s%d %s", file_name, file_no, line_var);
// test(line_var, temp_var, file_name, 34);
// printf("%s\n", temp_var);