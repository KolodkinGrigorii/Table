#include <iostream>
#include "table.h"
using namespace std;
int main() {
	Table<string, string> t;
	t.insert("first", "abc");
	t.insert("second", "cba");
	cout << t << endl;
	t.remove("second");
	cout << t;
	cout << t["first"];
}