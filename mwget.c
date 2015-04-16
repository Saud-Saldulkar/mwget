#include <stdio.h>

int capacity = 100;

void arg1()
{
	printf("\nmwget: Mass wget tool. Transforms links in a [.sh] file to embedded wget commands with sequential file naming.");
	printf("\n\nusage: mwget [(.sh) file] [file name] [file number{start range}]\n\n");
}

void arg2(char file_name[])
{
	
}

void arg3(char file_name[], char start_range[])
{
	
}

void fileio(char file_name[], int start_range)
{

}

int main(int argc, char* argv[])
{
	switch (argc)
	{
		case 2:
			arg2(argv[1]);
			break;
		
		case 3:
			arg3(argv[1], argv[2]);
			break;
		
		default:
		
			arg1();
			break;
	}
	return(0);
}