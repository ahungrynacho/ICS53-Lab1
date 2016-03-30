#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// does dynamic allocation need to be supported?
//struct Person {
	//char* name = calloc(100, sizeof(char));
	//char* addr = calloc(100, sizeof(char));
	//char* phone = calloc(100, sizeof(char));
//};

//struct Record {
	//int total = 0;
	//Person* person = calloc(10, sizeof(Person));
//}

typedef struct ListNode{
	struct ListNode* next;
	int id;
	char* str;
} LN;

char* read(const char* file_name) {
	FILE* infile = fopen(file_name, "r");
	static char fileArray[512];
	fread(fileArray, sizeof(fileArray), 1, infile);
	
	const char delim[2] = "\n";
	char* line;
	line = strtok(fileArray, delim);
	
	LN* node = NULL;
	node = malloc(sizeof(LN));
	node->id = 0;
	node->next = NULL;

	//okay
	//new commit
	fclose(infile);
	return fileArray;
}

void write() {
}

int main(){
	char* fileArray = read("record.txt");
	//int i;
	
	//for (i = 0; fileArray[i] != '\0'; ++i) {
		//putchar(fileArray[i]);
	//}
	
	return 0;
}

