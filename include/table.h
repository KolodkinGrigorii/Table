#pragma once

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <typename TypeKey, typename TypeData>
class Table {
protected:
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
	// TODO: podsazka Table a(20); a=a; // ????
	Table<TypeKey, TypeData>& operator=(const Table<TypeKey, TypeData>& t) {
		ar = t.ar;
		return *this;
	}
	~Table() {
		ar.clear();
	}
	auto insert(const TypeKey& key, const TypeData& data) {
		ar.push_back(make_pair(key, data));
		auto iter = ar.begin();
		for (auto it = ar.begin(); it != ar.end(); it++) {
			if (it->first == key) {
				return it;
			}
		}
	}
	auto find(const TypeKey& key) {
		if (ar.size() == 0) {
			return ar.end();
		}
		auto iter = ar.begin();
		for (auto it = ar.begin(); it != ar.end(); it++) {
			if (it->first == key) {
				return it;
			}
		}
		return ar.end();
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
	// TODO: test for TypeData&
	TypeData& operator [] (const TypeKey& key) {
		for (auto it = ar.begin(); it != ar.end(); it++) {
			if (it->first == key) {
				return it->second;
			}
		}
		throw 'FALL';
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
public:
	auto insert(const TypeKey& key, const TypeData& data) {
		if (ar.size() == 0) {
			ar.push_back(make_pair(key, data));
			return ar.begin();
		}
		else {
			int left = 0;
			int right = ar.size()-1;
			auto pos=ar.begin();
			if (key >= ar[right].first) {
				ar.push_back(make_pair(key, data));
				return ar.end()-=1;
			}
			else if (key <= ar[left].first) {
				ar.insert(ar.begin(), make_pair(key, data));
				return ar.begin();
			}
			else {
				int mid;
				while (right - left != 1) {
					mid = (right + left) / 2;
					if (key >= ar[mid].first) {
						left = mid;
					}
					else {
						right = mid;
					}
				}
				pos += right;
				return ar.insert(pos, make_pair(key, data));
			}
		}
	}
	auto find(const TypeKey& key) {
		if (ar.size() == 0 || key<ar.begin()->first 
			|| key> (ar.end()-=1)->first) {
			return ar.end();
		}
		else {
			int left = 0;
			int right = ar.size() - 1;
			auto pos = ar.begin();
			if (key == ar[right].first) {
				return ar.end()-=1;
			}
			else if (key == ar[left].first) {
				return pos;
			}
			else {
				int mid = left;
				while (ar[mid].first != key && right-left!=1) {
					mid = (right + left) / 2;
					if (key > ar[mid].first) {
						left = mid;
					}
					else if (key<ar[mid].first) {
						right = mid;
					}
				}
				if (ar[mid].first != key) {
					return ar.end();
				}
				else {
					pos += mid;
					return pos;
				}
			}
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const SortTable& v) {
		for (auto it = v.ar.begin(); it != v.ar.end(); it++) {
			cout << it->first << " " << it->second << endl;
		}
		return out;
	}
};
