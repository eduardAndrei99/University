#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

ifstream in("input_file.txt");
ofstream out("input_file_huffman.txt");

int freq[255];
map<char, string> mp;

struct node {
	char data;
	int frecventa;
	node* stanga;
	node* dreapta;
	node(char data, int frecventa) {
		this->data = data;
		this->frecventa = frecventa;
		this->stanga = nullptr;
		this->dreapta = nullptr;
	}
};

struct Comp {
	bool operator()(const node* left, const node* right) {
		return left->frecventa > right->frecventa;
	}
};

priority_queue<node*, vector<node*>, Comp> p_queue; //priority queue

/*
 * Functie ce imi citeste stringul din fisier
 * Returneaza stringul citit
 */
string readFromFile() {
	string rez;
	string read;
	while (!in.eof()) {
		getline(in, read);
		rez += read;
	}
	return rez;
}

/*
 * Functie ce imi pune in vectorul de frecventa aparitiile din string
 */
void frecventa(const string& str, int frecv[]) {
	for (int i = 0; i < 256; i++) {
		frecv[i] = 0;
	}
	for (const auto& elem : str) {
		frecv[int(elem)] ++;
	}
}

/*
 * Printez fiecare cod al caracterelor
 */
void printCodes(node* root, string str) {
	if (!root) {
		return;
	}

	if (root->data != '$') {
		cout << root->data << " " << str << "\n";
		mp[root->data] = str;
	}

	printCodes(root->stanga, str + '0');
	printCodes(root->dreapta, str + '1');
}

/*
 * Hufi !
 */
void makeHuffman(const string& str, priority_queue<node*, vector<node*>, Comp> pq) {

	frecventa(str, freq);
	for (int i = 0; i < 256; i++) {
		if (freq[i]) {
			pq.push(new node(char(i), freq[i]));
		}
	}

	while (pq.size() != 1) {
		auto left = pq.top();
		pq.pop();
		auto right = pq.top();
		pq.pop();
		auto top = new node('$', left->frecventa + right->frecventa);
		top->stanga = left;
		top->dreapta = right;
		pq.push(top);
	}
	
	printCodes(pq.top(), "");
}


int main() {

	string toRead = readFromFile();
	//std::cout << toRead;
	//std::cin.get();
	makeHuffman(toRead, p_queue);
	for (auto& ch : toRead) {
		out << mp[ch];
	}
	std::cin.get();

	return 0;
}