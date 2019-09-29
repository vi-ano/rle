#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *my_itoa(int num, char *str)
{
	if(str == NULL) {
	    return NULL;
	}
	sprintf(str, "%d", num);
	return str;
}

char* compress(char* string, int num, char* output)
{
	int i = 1;
	int counter;
	int out_num = 0;
	char substr[6];
	int flag=1;
	int j;

	while (string[i] != '\n') {
		counter = 1;

		if (string[i] == string[i-1] & flag == 1)
			counter+=1;
		else if (string[i] != string[i-1] & flag == 0) {
			counter+=1;
			output[out_num++] = string[i-1];
		}

		if (string[i] != string[i-1] & flag == 1) {
			flag=0;
			output[out_num++] = string[i-1];
			my_itoa(counter, substr);
			for(j=0; j<strlen(substr);j++)
				output[out_num++]=substr[j];
		}

		else if (string[i] == string [i-1] & flag == 0) {
			flag=1;
                        if (counter > 1)
				counter=0-counter;
			my_itoa(counter, substr);
			for(j=0; j<strlen(substr);j++)
				output[out_num++]=substr[j];
		}
		i++;
	}

	return output;
}

int main(int argc, char* argv[])
{
	char string[100];
	char output[100];

	scanf("%s",string);
	printf("%s\n", string);
	printf("return\n");
	printf("%s", compress(string,100, output));
	return 0;


}
