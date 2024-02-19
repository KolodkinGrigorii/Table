#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <typename TypeKey, typename TypeData>
class Table {
private:
	vector<pair<TypeKey, TypeData>> ar;
public:
	auto insert(const TypeKey& key, const TypeData& data) {
		ar.push_back(make_pair(key, data));
		auto iter = ar.begin();
		for (auto it = ar.begin(); it != ar.end(); it++) {
			if (it->first == key) {
				iter = it;
			}
		}
		return iter;
	}
	auto find(const TypeKey& key) {
		auto iter = ar.begin();
		for (auto it = ar.begin(); it != ar.end(); it++) {
			if (it->first == key) {
				iter = it;
			}
		}
		return iter;
	}
	auto end() {
		auto iter = ar.end();
		return iter;
	}
	auto begin() {
		auto iter = ar.begin();
		return iter;
	}
	bool remove(const TypeKey& key) {
		for (auto it = ar.begin(); it != ar.end(); it++) {
			if (it->first == key) {
				ar.erase(it);
				return true;
			}
		}
		return false;
	}
	TypeData operator [] (const TypeKey& key) {
		for (auto it = ar.begin(); it != ar.end(); it++) {
			if (it->first == key) {
				return it->second;
			}
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const Table& v) {
		for (auto it = v.ar.begin(); it != v.ar.end(); it++) {
			cout << it->first << " " << it->second << endl;
		}
		return out;
	}
	void sort() {
		for (auto it = ar.begin(); it != ar.end(); it++) {
			for (auto it2 = ar.begin(); it2 != ar.end(); it2++) {
				if ((it->first) < (it2->first)) {
					TypeKey key1 = it->first;
					TypeData data1 = it->second;
					TypeKey key2 = it2->first;
					TypeData data2 = it2->second;
					it->first = key2;
					it->second = data2;
					it2->first = key1;
					it2->second = data1;
				}
			}
		}
	}
};
template <typename TypeKey, typename TypeData>
class SortTable : public Table<TypeKey, TypeData> {
private:
	vector<pair<TypeKey, TypeData>> ar;
public:
};
