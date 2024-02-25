#include <iostream>
#include "table.h"
using namespace std;
int main() {
	Table<int, int> t;
	t.insert(1, 3);
	t.insert(5, 4);
	t.insert(4, 3);
	Table<int, int> t2;
	t2 = t;
	cout << t2;
	cout << t;
}
