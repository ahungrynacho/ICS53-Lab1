#include <iostream>
#include <fstream>
#include <string>

struct LN {
	LN() {}
	LN(const LN& ln) : name(ln.name), address(ln.address), phone(ln.phone) {}
	LN(std::string inName, std::string inAddress, std::string inPhone, LN* n = NULL)
	: name(inName), address(inAddress), phone(inPhone), next(n) {}
	
	std::string name;
	std::string address;
	std::string phone;
	LN* next = NULL;
};

LN* read(const char* file){
	std::string line;
	std::ifstream infile(file);
	// use a header-trailer link list to maintain the order of entries and easier to delete the last node
	LN* head = new LN();
	LN* tail = head->next = new LN();
	LN* front = head;
	
	while (getline(infile, line)) {
		std::string* info = new std::string[4]; // [ name, address, phone ]
		int infoPos = 0;
		for (int i = 0; line[i] != '\0'; ++i) {
			if (line[i] == '\t')
				++infoPos;
			else
				info[infoPos] += line[i];
		}
		head = head->next = new LN(info[0], info[1], info[2], tail);
	}

	infile.close();
	return front->next;
}

void write(LN* node) {
	std::ofstream outfile;
	outfile.open("output.txt");
	while (node->next != NULL) {
		outfile << " " << node->name << " \t" << node->address << " \t" << node->phone << std::endl;
		node = node->next;
	}
	outfile.close();
}

void print(LN* node) {
	int count = 1;
	while (node->next != NULL) {
		std::cout << count << " " << node->name << " \t" << node->address << " \t" << node->phone << std::endl;
		node = node->next;
		count++;
	}
}

void remove(LN* node, int id) {
	int count = 1;
	while (count != id) {
		if (id < 1 || node->next == NULL) {
			std::cout << "ID Out of Bounds" << std::endl;
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
	delete toDelete;
	
}

int main() {
	LN* infoList = read("record.txt");
	print(infoList);
	
	std::cout << '\n';
	remove(infoList, 3);
	print(infoList);
	write(infoList);
	return 0;
}
