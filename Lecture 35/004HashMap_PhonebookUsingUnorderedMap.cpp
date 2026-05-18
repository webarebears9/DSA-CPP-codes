/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {

	map<string, vector<string>> phoneMap;

	cout << phoneMap.size() << endl;

	phoneMap["Kartik"].push_back("1234");
	phoneMap["Kartik"].push_back("5678");
	phoneMap["Kartik"].push_back("9876");

	phoneMap["Tulika"].push_back("0000");
	phoneMap["Tulika"].push_back("1111");

	for (pair<string, vector<string>> p : phoneMap) {
		string name = p.first;
		vector<string> nums = p.second;
		cout << name << " : ";
		for (string num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto [name, nums] : phoneMap) {
		cout << name << " : ";
		for (string num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}