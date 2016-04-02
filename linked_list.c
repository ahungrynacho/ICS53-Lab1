#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode{
	char* value;
	struct ListNode* next;
} LN;


LN* create_list(char* str[]) {
	LN* head = malloc(sizeof(LN));
	LN* tail = head->next = malloc(sizeof(LN));
	LN* front = head;
	tail->next = NULL;
	
	for (int i = 0; i < 3; ++i) {
		LN* newNode = malloc(sizeof(LN));
		newNode->value = str[i];
		newNode->next = tail;
		head = head->next = newNode;
	}
	return front;
}

void print(LN* node) {
	while (node->next != NULL) {
		printf("%s ", node->value);
		node = node->next;
	}
		
}

int main(){
	char* str[3] = {"abc", "def", "ghi", "GHI"}};
	
	LN* data = create_list(str);
	print(data->next);
	return 0;
}
