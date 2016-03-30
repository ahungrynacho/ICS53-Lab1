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
	LN* head = new LN(); //trailer node
	
	while (getline(infile, line)) {
		std::string* info = new std::string[4]; // [ name, address, phone ]
		
		//int infoPos = 0;
		//int iStart = 0;
		//while (line[iStart] != '\0') {
			//int i = iStart;
			//std::string temp;
			//for (; line[i] != '\n' || line[i] != '\t'; ++i) {
				//temp += line[i];
			//}

			//info[infoPos] = temp;
			//infoPos++;
			//iStart = i;
		//}
		//head = new LN(info[0], info[1], info[2], head);
	}
	head = new LN("Brian Huynh", "64224 Arroyo Dr", "4087122447", head);
	head = new LN("John Doe", "12345 Durham Dr", "4089294404", head);
	infile.close();
	return head;
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
	remove(infoList, 1);
	print(infoList);
	write(infoList);
	return 0;
}
