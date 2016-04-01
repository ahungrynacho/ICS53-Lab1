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
	//~ LN* tail = malloc(sizeof(LN));
	//~ head->next = tail;
	//~ tail->next = NULL;
	//~ LN* front = head;
	
	char line[1023];
	FILE* fp = fopen(file, "r");
	while (fgets(line, 1023, fp) != NULL) { //NULL == EOF
		char* infoList[4]; //[name, address, phone]
		int tokenPos = 0;
		char* token = strtok(line, "\t"); 
		
		while (token != NULL) {
			infoList[tokenPos] = token;
			tokenPos++;
			token = strtok(NULL, "\t");
		}
		
		LN* newNode = malloc(sizeof(LN));
		newNode->name = infoList[0];
		newNode->address = infoList[1];
		newNode->phone = infoList[2];

		newNode->next = head;
		head = newNode;
		//~ head = head->next = newNode;
		//~ newNode->next = tail;
		//~ printf("%s\t%s\t%s", head->name, head->address, head->phone);
	}
	//printf("%s\t%s\t%s", front->next->name, front->next->address, front->next->phone);
	//printf("%s\t%s\t%s", head->name, head->address, head->phone);
	//front = front->next;
	//printf("%s\t%s\t%s", front->name, front->address, front->phone);


	return head;
	
}

void write(LN* node, const char* file) {
}

void remove_node(LN* node, int id) {
}

void print(LN* node) {
	int count = 1;
	while (node->next != NULL) {
		printf("%i %s\t%s\t%s", count, node->name, node->address, node->phone);
		node = node->next;
		count++;
	}
}

void delete_list(LN* node) {
}

int main(){
	LN* database = read("record.txt");
	print(database);
	//~ char* str1 = "abc";
	//~ str1 = "123";
	//~ puts(str1);
	return 0;
}

