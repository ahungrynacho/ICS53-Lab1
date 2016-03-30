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
		delete [] info;
	}

	infile.close();
	return front; //return the pointer to the header node
}

void write(LN* node, const char* file) {
	std::ofstream outfile;
	outfile.open(file);
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

void deleteList(LN* node) {
	while (node != NULL) {
		LN* toDelete = node;
		node = node->next;
		delete toDelete;
	}
}

int main() {

	std::cout << "Please enter one of the commands:\n1) read <file_name.txt>\n2) write <file_name.txt>\n3) print\n4) delete <ID_number>\n5) quit" << std::endl;
	
	std::string input;
	std::string* command = new std::string[4];
	LN* database = NULL;

	//~ while (true) {
		//~ std::cin >> input;
		//~ int commandPos = 0;
		//~ for (int i = 0; input[i] != '\0'; ++i) {
			//~ if (input[i] == ' ')
				//~ ++commandPos;
			//~ else
				//~ command[commandPos] += input[i];
		//~ }
		//~ std::cout << command[0] << std::endl;
		//~ if (command[0] == "quit") {
			//~ std::cout << "Program Exiting" << std::endl;
			//~ break;
		//~ }
		//~ else if (command[0] == "read") {
			//~ //std::string file = command.substr(command.find(" "));
			//~ database = read(command[1])->next;
		//~ }
		//~ else if (command[0] == "write")
			//~ write(database, command[1]);
		//~ else if (command[0] == "print")
			//~ print(database);
		//~ else if (command[0] == "delete")
			//~ remove(database, command[1]);

	//~ }
	LN* infoList = read("record.txt");
	print(infoList->next);
	
	std::cout << '\n';
	remove(infoList->next, 3);
	print(infoList->next);
	write(infoList->next, "output.txt");
	deleteList(infoList);
	return 0;
}
