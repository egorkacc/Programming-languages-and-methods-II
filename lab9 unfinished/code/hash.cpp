#include <iostream>
#include <string>
#include <list>

using namespace std;

class HashTable
{
	private:
		int capacity;
		list<int> *table;
	
	public:
		HashTable(int c);
		void insertItem(int key, int data);
		
		int hashFunction(int key) {
			return(key%capacity);
		}
		
		void displayHash();
};

HashTable::HashTable(int c) {
	
	int size = c;
	this->capacity = size;
	table = new list<int>[capacity];
}

void HashTable::insertItem(int key, int data) {
	
	int index = hashFunction(key);
	table[index].push_back(data);
}

void HashTable::displayHash() {
	for(int i = 0; i < capacity; i++) {
		cout << "table[" << hashFunction(i) << "]";
		
		for(auto x : table[i])
			cout << " --> " << x;
			
		cout << endl;
	}
}
