#include <iostream>
#include "table.h"
using namespace std;
int main() {
	Table<string, string> t;
	int count = 0;
	t.insert("first", "abc");
	t.insert("second", "cba");
	t.insert("third", "bca");
	for (auto it = t.find("second"); it != t.end(); it++) {
		count++;
	}
	cout << count;
}
