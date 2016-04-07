#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PEOPLE 1024
#define MAX_INPUTS 128
#define STR_SIZE 80

typedef struct ListNode{
	char* name;
	char* address;
	char* phone;
	struct ListNode* next;
} LN;

LN* read(const char* file){
	LN* head = malloc(sizeof(LN));
	LN* tail = head->next = malloc(sizeof(LN));
	LN* front = head;
	tail->next = NULL;
	
	char line[MAX_PEOPLE][STR_SIZE]; //MAX CAP: 100 entries of 1024 char long
	int iEntry = 0;
	FILE* fp = fopen(file, "r");
	while (fgets(line[iEntry], STR_SIZE, fp) != NULL) { //NULL == EOF
		
		int tokenPos = 0;
		char* token = strtok(line[iEntry], "\t"); 
		char* infoList[4]; //[name, address, phone]
		while (token != NULL) {
			infoList[tokenPos] = token;
			tokenPos++;
			token = strtok(NULL, "\t");
		}
		
		LN* newNode = malloc(sizeof(LN));
		newNode->name = infoList[0];
		newNode->address = infoList[1];
		newNode->phone = infoList[2];
		newNode->next = tail;
		
		head = head->next = newNode;
		iEntry++;
	}

	return front;
	
}

void write(LN* node, const char* file) {
	FILE* fp = fopen(file, "w");
	
	while (node->next != NULL) {
		fprintf(fp, "%s\t%s\t%s", node->name, node->address, node->phone);
		node = node->next;
	}
	fclose(fp);
}

void remove_node(LN* node, int id) {
	int count = 1;
	while (count != id) {
		if (id < 1 || node->next == NULL) {
			printf("ID Out of Bounds\n");
			return;
		}
		node = node->next;
		++count;
	}
	LN* toDelete = node->next;
	node->name = toDelete->name;
	node->address = toDelete->address;
	node->phone = toDelete->phone;
	node->next = toDelete->next;
	free(toDelete);	
}

void print(LN* node) {
	int count = 1;
	while (node->next != NULL) {
		printf("%i\t%s\t%s\t%s", count, node->name, node->address, node->phone);
		node = node->next;
		count++;
	}
}

void delete_list(LN* node) {
	while (node != NULL) {
		LN* toDelete = node;
		node = node->next;
		free(toDelete);
	}
}

char* trim(char* str) {
	int i = strlen(str) - 1;
	if ((i > 0) && (str[i] == '\n'))
		str[i] = '\0';
	return str;
}


int main(){
	LN* database = NULL;
	char response[MAX_INPUTS][STR_SIZE];
	
	int resCount = 0;
	while (resCount < MAX_INPUTS) {
		fgets(response[resCount], STR_SIZE, stdin);

		char* command[4];
		char* token = strtok(response[resCount], " \t");
		
		int i = 0;
		while (token != NULL) {
			//~ command[i] = strtok(token, "\n");
			command[i] = trim(token);
			token = strtok(NULL, " \t");
			++i;
		}

		if (strcmp(command[0], "quit") == 0) {
			delete_list(database);
			break;
		}
		else if (strcmp(command[0], "read") == 0) {
			if (fopen(command[1], "r") != NULL)
				database = read(command[1]);
		}
		else if (strcmp(command[0], "write") == 0) {
			if (database != NULL)
				write(database->next, command[1]);
		}
				
		else if (strcmp(command[0], "delete") == 0) {
			if (database != NULL) {
				int i = *command[1] - '0';
				remove_node(database->next, i);
			}
		}
		else if (strcmp(command[0], "print") == 0)
			if (database != NULL)
				print(database->next);
		++resCount;	
	}
	return 0;
}

