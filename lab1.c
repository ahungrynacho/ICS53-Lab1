#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode{
	
	char* name;
	char* address;
	char* phone;
	struct ListNode* next;
} LN;

LN* read(const char* file){
	LN* head = malloc(sizeof(LN));
	LN* tail = malloc(sizeof(LN));
	LN* front = malloc(sizeof(LN));
	
	char line[1023];
	FILE* fp = fopen(file, "r");
	while (fgets(line, 1023, fp) != NULL) { //NULL == EOF
		char* info = malloc
		char* token = strtok(line, "\t");
		while (token != NULL) {
			printf("%s", token);
			token = strtok(NULL, "\t");
		}
	}
	return head;
	
}

void write(LN* node, const char* file) {
}

//~ void remove(LN* node, int id) {
//~ }

void deleteList(LN* node) {
}

int main(){
	read("record.txt");
	//~ char* str1 = "abc";
	//~ str1 = "123";
	//~ puts(str1);
	return 0;
}

