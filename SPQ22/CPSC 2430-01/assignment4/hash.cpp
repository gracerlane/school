#include <iostream>
#include <vector>
using namespace std;
class seperateChaining{
	private:
		int tableSize;
		vector<vector<int>> v;
	public:
		// constructor
		seperateChaining(int m){
			v = vector<vector<int>>(m);
			this->tableSize = m;
		}
		// hash function
		int getIndex(int key){
				return key%tableSize;
		}
		// add a key to hash table
		void add(int key){
				v[getIndex(key)].push_back(key);
		}
		// delete a key from hash table
		void deleteKey(int key){
			// get index first
			int i = getIndex(key);
			// traverse ith list(vector) to search 
			for(int j = 0; j< v[i].size(); j++){
				// if found, delete
				if(v[i][j] == key){
					v[i].erase(v[i].begin() + j);
					cout << key << " key: " << key << " is deleted!" << endl;
					return;
				}
			}
			cout << "No key: " << key << " in hash table!";
		}

		// Display the contents
		void display(){
			cout << "Hash Table" << endl;
			for(int i = 0; i < v.size(); i++) {
				cout << i;
				for (int j = 0; j < v[i].size(); j++)
					cout << " -> " << v[i][j];
				cout << endl;
			}
		}
};
 
int main()
{
	// Define some keys here
	vector<int> keys= {4371, 1323, 6173, 4199, 4344, 9679, 1989};

	// Construct a hash table with separate chaining as collision resolving technique
	// the table size is 10
	seperateChaining SC_hashTable(10);

	// add keys to hash table
	for (int i = 0; i < 6; i++)
			SC_hashTable.add(keys[i]);

	// display hash table
	SC_hashTable.display();

	// Removing one key
	// remove an existing key
	cout << "Removing 4344 from Hash: " << endl;
	SC_hashTable.deleteKey(4344);
	SC_hashTable.display();

	// remove a non-existing key
	cout << "Removing 1234 from Hash: " << endl;
	SC_hashTable.deleteKey(1234);
	//SC_hashTable.display();
	
	return 0;
}
