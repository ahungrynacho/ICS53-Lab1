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
	LN* tail = head->next = malloc(sizeof(LN));
	LN* front = head;
	tail->next = NULL;
	
	char line[100][1024]; //MAX CAP: 100 entries of 1024 char long
	int iEntry = 0;
	FILE* fp = fopen(file, "r");
	while (fgets(line[iEntry], 1024, fp) != NULL) { //NULL == EOF
		
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
		printf("%i %s\t%s\t%s", count, node->name, node->address, node->phone);
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

char* user_input(char* info) {
	char* infoList[4];
	char* token = strtok(info, " ");
	
	int i = 0;
	while (token != NULL) {
		infoList[i] = token;
		token = strtok(NULL, " ");
		++i;
	}
	return *infoList;
}



int main(){
	LN* database = NULL;
	char response[100][1024];
	printf("Please enter one of the commands:\n1) read <file_name.txt>\n2) write <file_name.txt>\n3) print\n4) delete <ID_number>\n5) quit\n");
	
	int resCount = 0;
	while (resCount < 100) {
		fgets(response[resCount], 1024, stdin);

		//~ if (strcmp(response[resCount], "quit\n") == 0)
			//~ printf("okay");
		char* command[4];
		char* token = strtok(response[resCount], " ");
		
		int i = 0;
		while (token != NULL) {
			command[i] = strtok(token, "\n");
			token = strtok(NULL, " ");
			++i;
		}
		printf("%s-%s", command[0], command[1]);

		if (strcmp(command[0], "quit") == 0)
			break;
		//~ else if (strcmp(command[0], "read") == 0)
			//~ printf("%s", command[1]); 
			//~ database = read(command[1]); //command[1] contains /n
		//~ else if (strcmp(command[0], "write\n") == 0)
			//~ write(database, command[1]);
		//~ else if (strcmp(command[0], "delete\n") == 0) {
			//~ int i = *command[1] - '0';
			//~ remove_node(database, i);
		//~ }
		//~ else if (strcmp(command[0], "print\n") == 0)
			//~ print(database);
		++resCount;	
	}
	delete_list(database);
	
	//~ LN* database = read("record.txt");
	//~ remove_node(database->next, 2);
	//~ print(database->next);
	//~ write(database->next, "new_record.txt");
	//~ delete_list(database);
	//~ char* str1 = "abc";
	//~ str1 = "123";
	//~ puts(str1);
	return 0;
}

