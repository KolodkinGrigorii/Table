#include <iostream>
#include "table.h"
using namespace std;
int main() {
	SortTable<string, int> st;
	st.insert("cba", 3);
	st.insert("bbc", 1);
	st.insert("bca", 2);
	cout << st;
}
