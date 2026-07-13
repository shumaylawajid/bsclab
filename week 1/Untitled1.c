#include<stdio.h>
#include<string.h>
int is_vowel(char ch)
{ return( ch == 'a'|| ch == 'A'||
          ch == 'e'|| ch == 'E'||
          ch == 'i'|| ch == 'I'||
          ch == 'o'|| ch == 'O'||
          ch == 'u'|| ch == 'U');
}
void remove_vowels(char str[]){
	int i = 0;
	int j = 0;
	while (str[i] != '\0'){
		if (is_vowel(str[i])== 0)
   {
    	str[j] = str[i];
    	j++;
}
    i++;	
	   }
	str[j] = '\0';
}
int main(){
	char input[256];
	size_t len;
	printf("===Vowel Remover Array Tool===\n");
	printf("type 'exit' to quit.\n\n");
	while(1){
		printf("Enter a string: ");
		if (fgets(input, sizeof(input), stdin) == NULL){
			break;
		}
	len = strlen(input);
	if(len > 0 && input[len -1] == '\n'){
		input[len - 1] = '\0';
	}
	if (strcmp(input, "exit") == 0){
		printf("exiting. Goodbye!\n");
		break;
	}
	printf("before : %s\n", input);
	remove_vowels(input);
	printf("After  : %s\n", input);	
	printf("------------\n");
	}
	return 0;
}
