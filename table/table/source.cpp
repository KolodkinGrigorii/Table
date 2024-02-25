#include <iostream>
#include "table.h"
using namespace std;
int main() {
	SortTable<string, int> st;
	st.insert("cba", 3);
	st.insert("bbc", 1);
	st.insert("bca", 2);
	st.remove("bbc");
	cout << st;
	Table<int, int> t;
	t.insert(1, 3);
	t.insert(5, 4);
	t.insert(4, 3);
	cout << t.end()->second;
	cout << t;
}
