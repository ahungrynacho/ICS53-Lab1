#include <stdio.h>
#include <string.h>

//struct Person {
	//char* name = calloc(100, sizeof(char));
	//char* addr = calloc(100, sizeof(char));
	//char* phone = calloc(100, sizeof(char));
//};

//struct Record {
	//int total = 0;
	//Person* person = calloc(10, sizeof(Person));
//}

void read(const char* file_name) {
	FILE* infile = fopen(file_name, "r");
	int c;
	while ((c = getc(infile)) != EOF) {
		putchar(c);
	}
	fclose(infile);
}

void write() {
}

int main(){
	read("record.txt");
	return 0;
}
