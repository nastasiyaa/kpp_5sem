#include <iostream>
#include <string>
using namespace std;

struct Node {
	Node* next;
	string info;
};

string inputStr(string  msg);
string change_text(string text, string nessesary_string);
string define_capital_str(string nessesary_string);

void print_list(Node* list);
void append(Node* list, string information);
Node* create_list_from_str(string text);

void main() {
	string text =  inputStr("Please, input your text:");
	string nessesary_string = inputStr("Please, input your nessesary string:");

	cout << "Result: "<<change_text(text, nessesary_string);

}

string inputStr(string msg) {
	cout << msg << " ";
	string inputStr;
	getline( cin, inputStr);
	return inputStr;
}

void print_list(Node* list) {
	Node* p = list;
	while (p) {
		cout << p->info << " ";
		p = p->next;
	}
}

void append(Node* list, string information) {
		Node* simple = list;
		while (simple->next)
			simple = simple->next;

		simple->next = new Node;
		simple = simple->next;
		simple->info = information;
		simple->next = NULL;
}

Node* create_list_from_str(string text) {
	Node* list = new Node;
	list->next = NULL;
	string word = "";
	for (int i = 0; i < text.length(); i++) {
		int j = i;
		while (text[j] != ' ' && text[j] != '.' && j < text.length()) {
			word += text[j];
			j++;
		}
		i = j;
		if (word != "")
			append(list, word);
		if (text[i] == '.')
			append(list, ".");
		word = "";
	}
	return list;
}

string change_text(string text, string nessesary_string) {

	Node* words_list = create_list_from_str(text);
	string changer_word = define_capital_str(nessesary_string);

	string result = "";

	while (words_list) {
		
		if (words_list->info != nessesary_string ) {
			result += words_list->info + " ";
		}
		else {
			result += changer_word + " ";
		}
		words_list = words_list->next;
	}

	return result;
}

string define_capital_str(string nessesary_string) {
	string capital_str = "";

	for (int i = 0; i < nessesary_string.length(); i++)
		if  (int(nessesary_string[i]) > 96 && int(nessesary_string[i]) < 123)
			capital_str += char(int(nessesary_string[i]) - 32);
	return capital_str;
}
