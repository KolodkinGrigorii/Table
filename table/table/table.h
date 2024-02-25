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
		if (ar.size() == 0) {
			throw'FALL';
		}
		auto iter = ar.begin();
		for (auto it = ar.begin(); it != ar.end(); it++) {
			if (it->first == key) {
				iter = it;
			}
			if (it->first != key && (it == ar.end() -= 1)) {
				throw 'FALL';
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
			throw 'FALL';
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
					throw 'FALL';
				}
				else {
					pos += mid;
					return pos;
				}
			}
		}
	}
	auto end() {
		auto iter = sortar.end()-=1;
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
