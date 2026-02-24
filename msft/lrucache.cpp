//
// Created by asura on 24/02/26.
//
#include <iostream>
#include <variant>
#include <vector>
#include <utility>
#include <string>
#include <list>
#include <unordered_map>

typedef std::pair<int,int> pii;
typedef std::variant<int, pii> var_i_pii;
typedef std::vector<var_i_pii> vec_var_i_pii;

std::ostream& operator<<(std::ostream& os, vec_var_i_pii const &p) {
    os << "{";
    for (auto x : p) {
        if (std::holds_alternative<int>(x)) {
            os << std::get<int>(x) << ",";
        } else {
            os << "(" << std::get<pii>(x).first << "," << std::get<pii>(x).second << "),";
        }
    }
    os << "}";
    return os;
}

class LRUCache {
private:
    int capacity;
    std::list<pii> cache;
    std::unordered_map<int,std::list<pii>::iterator> map;
public:
    LRUCache(int cap) : capacity(cap) {};
    int get(int key) {
        auto itr = map.find(key);
        if (itr == map.end()) { return -1; }
        cache.splice(cache.begin(),cache, itr->second);
        return itr->second->second;
    };
    void put(int key, int value) {
        return;
    }
};

void test(std::string const &testname, vec_var_i_pii const &vec) {
    std::cout << testname << ": " << vec << std::endl;
    return;
}

int main() {
    test("simple",{1,pii{1,2},1,pii{1,2},1,pii{1,2},1,pii{1,2},1,pii{1,2}});
    return 0;
}