#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <typename TypeKey, typename TypeData>
class Table {
private:
	vector<pair<TypeKey, TypeData>> ar;
public:
	Table() {
		vector<pair<TypeKey, TypeData>> ar;
	}
	Table(const Table& t) {
		auto iter = t.ar.begin();
		for (auto it = t.ar.begin(); it != t.ar.end(); it++) {
			TypeKey key = it->first;
			TypeData data = it->second;
			ar.push_back(make_pair(key, data));
		}
	}
	Table<TypeKey, TypeData> operator=(const TypeKey& t) {
		while (ar.size() != 0) {
			ar.pop_back();
		}
		auto iter = t.ar.begin();
		for (auto it = t.ar.begin(); it != t.ar.end(); it++) {
			TypeKey key = it->first;
			TypeData data = it->second;
			ar.push_back(make_pair(key, data));
		}
		int size = t.ar.size();
		while (size != 0) {
			t.ar.pop_back();
			size = t.ar.size();
		}
		return *this;
	}
	~Table() {
		int size = ar.size();
		while (size != 0) {
			ar.pop_back();
			size = ar.size();
		}
	}
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
		if (ar.size() == 0) {
			return ar.end();
		}
		auto iter = ar.begin();
		for (auto it = ar.begin(); it != ar.end(); it++) {
			if (it->first == key) {
				iter = it;
			}
			if (it->first != key && (it == (ar.end()-= 1))) {
				return ar.end();
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
};
template <typename TypeKey, typename TypeData>
class SortTable: public Table<TypeKey,TypeData> {
private:
	vector<pair<TypeKey, TypeData>> sortar;
public:
    SortTable() {
		vector<pair<TypeKey, TypeData>> sortar;
	}
	SortTable(const SortTable& t) {
		auto iter = t.sortar.begin();
		for (auto it = t.sortar.begin(); it != t.sortar.end(); it++) {
			TypeKey key = it->first;
			TypeData data = it->second;
			sortar.push_back(make_pair(key, data));
		}
	}
	SortTable<TypeKey, TypeData> operator=(const TypeKey& t) {
		while (sortar.size() != 0) {
			sortar.pop_back();
		}
		auto iter = t.sortar.begin();
		for (auto it = t.sortar.begin(); it != t.ar.end(); it++) {
			TypeKey key = it->first;
			TypeData data = it->second;
			ar.push_back(make_pair(key, data));
		}
		int size = t.sortar.size();
		while (size != 0) {
			t.sortar.pop_back();
			size = t.sortar.size();
		}
		return *this;
	}
	~SortTable() {
		int size = sortar.size();
		while (size != 0) {
			sortar.pop_back();
			size = sortar.size();
		}
	}
	auto insert(const TypeKey& key, const TypeData& data) {
		if (sortar.size() == 0) {
			sortar.push_back(make_pair(key, data));
			return sortar.begin();
		}
		else {
			int left = 0;
			int right = sortar.size()-1;
			auto pos=sortar.begin();
			if (key >= sortar[right].first) {
				sortar.push_back(make_pair(key, data));
				return sortar.end()-=1;
			}
			else if (key <= sortar[left].first) {
				sortar.insert(sortar.begin(), make_pair(key, data));
				return sortar.begin();
			}
			else {
				int mid;
				while (right - left != 1) {
					mid = (right + left) / 2;
					if (key >= sortar[mid].first) {
						left = mid;
					}
					else {
						right = mid;
					}
				}
				pos += right;
				return sortar.insert(pos, make_pair(key, data));
			}
		}
	}
	auto find(const TypeKey& key) {
		if (sortar.size() == 0 || key<sortar.begin()->first 
			|| key> (sortar.end()-=1)->first) {
			return sortar.end();
		}
		else {
			int left = 0;
			int right = sortar.size() - 1;
			auto pos = sortar.begin();
			if (key == sortar[right].first) {
				return sortar.end()-=1;
			}
			else if (key == sortar[left].first) {
				return pos;
			}
			else {
				int mid = left;
				while (sortar[mid].first != key && right-left!=1) {
					mid = (right + left) / 2;
					if (key > sortar[mid].first) {
						left = mid;
					}
					else if (key<sortar[mid].first) {
						right = mid;
					}
				}
				if (sortar[mid].first != key) {
					return sortar.end();
				}
				else {
					pos += mid;
					return pos;
				}
			}
		}
	}
	auto end() {
		auto iter = sortar.end();
		return iter;
	}
	auto begin() {
		auto iter = sortar.begin();
		return iter;
	}
	bool remove(const TypeKey& key) {
		for (auto it = sortar.begin(); it != sortar.end(); it++) {
			if (it->first == key) {
				sortar.erase(it);
				return true;
			}
		}
		return false;
	}
	TypeData operator [] (const TypeKey& key) {
		for (auto it = sortar.begin(); it != sortar.end(); it++) {
			if (it->first == key) {
				return it->second;
			}
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const SortTable& v) {
		for (auto it = v.sortar.begin(); it != v.sortar.end(); it++) {
			cout << it->first << " " << it->second << endl;
		}
		return out;
	}
};
