//implement an algorithm to determine if a string has all unique characters.
//What if you cannot use additional data structures?

//?s: how large is the string?

//storing values into hashmap, check if inserted is already mapped.

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string string;
	
	while(cin >> string) {
		unordered_map<char, char> map;
		for(int i = 0; i < string.length(); ++i) {
			if(map.find(string[i]) == map.end()) {
				//map.insert(string[i],string[i]);
				map[string[i]] = string[i];
			}
			else {
				cout << "duplicate char: " << string[i] << endl;
			}
		}
	}
	return 0;
}

//time is O(n) on string length because both find and [] are constant time.
//memory is O(n)? I think on the length of string