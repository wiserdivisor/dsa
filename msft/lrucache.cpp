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
#include <unique_ptr>

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

std::ostream& operator<<(std::ostream& os, Node const *node) {
    os << "Node(" << node->key << "," << node->value << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, DoublyLinkedList const &dll) {
    Node* currnode = dll->first->child;
    
    os << "DoublyLinkedList(" << "HEAD";
    while(currnode != dll->last) {
        os << "=" << currnode << "=";
        currnode = currnode->child;
    }
    os << "TAIL)";
    return os;
}

std::ostream& operator<<(std::ostream& os, LRUCache const &lrucache) {
    os << "LRUCache(";
    os << lrucache.to_string(); 
    os << ")";
    return os;
}

struct Node{
    int key;
    int value;
    Node* parent;
    Node* child;
    Node(int k, int v) : key(k), value(v), parent(nullptr), child(nullptr) {}
};

class DoublyLinkedList {

private:
    Node* first;
    Node* last;

public:
    DoublyLinkedList(){
        first = new Node(0,0);
        last = new Node(0,0);
        first->child = last;
        tail->parent = first;
    }
    ~DoublyLinkedList(){
        Node* curr = first;
        while(curr != nullptr) {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }
    void prepend(Node* newnode) {
        newnode->parent = first;
        newnode->child = first->child;
        first->child->parent = newnode;
        first->child = newnode;
    }
    void append(Node* newnode) {
        newnode->child = last;
        newnode->parent = last->parent;
        last->parent->child = newnode;
        last->parent = newnode;
    }
    void detach(Node* oldnode) {
        oldnode->parent->child = oldnode->child;
        oldnode->child->parent = oldnode->parent;
    }
    void replace(Node* newnode, Node* oldnode) {
        newnode->parent = oldnode->parent;
        newnode->child = oldnode->child;
        oldnode->parent->child  = newnode;
        oldnode->child->parent = newnode;
        delete oldnode;
    }
    void move_to_front(Node* midnode) {
        detach(midnode);
        prepend(midnode);
    }
    Node* popLRU(){
        Node* lru_node = last->parent;
        if(lru_node == first) { return nullptr; }
        detach(lru_node);
        return lru_node;
    }
}

class LRUCache {
private:
    int capacity;
    DoublyLinkedList nodelist;
    std::unordered_map<int,Node*> cache;

public:
    LRUCache(int cap) : capacity(cap) {};

    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        nodelist.move_to_front(node);
        int retval = node->value;
        std::cout << nodelist << std::endl;
        return retval;
    };

    void put(int key, int value) {
        auto itr = cache.find(key);
        if(itr != cache.end()) {
            Node* node = itr->second;
            node->value = value;
            nodelist.move_to_front(node);
            std::cout << nodelist << std::endl;
            return;
        }
        if(static_cast<int>(cache.size()) == capacity) {
            Node* lrunode = nodelist.popLRU();
            cache.erase(lrunode->key);
            delete lrunode;
        }
        Node* newnode = new Node(key,value);
        cache[key] = newnode;
        nodelist.prepend(newnode);
        std::cout << nodelist << std::endl;
        return;
    }

    std::string const& to_string() {
        std::string output = "";
        for(auto& [k,v] : cache) {
            output += "{" + k + ":" + v->value + "},";
        }
        return output;
    }
};

void test(std::string const &testname, vec_var_i_pii const &vec) {
    LRUCache lruc(3);
    std::cout << testname << ": " << vec << std::endl;
    for(auto &x : vec) {
        if(std::holds_alternative<int>(x)) {
            int ti = std::get<int>(x);
            lruc.get(ti);
            std::cout << lruc << std::endl;
        } else {
            pii tpii = std::get<pii>(x);
            lruc.put(tpii.first,tpii.second);
            std::cout << lruc << std::endl;
        }
    }
    return;
}

int main() {
    test("simple",{1,pii{1,2},1,pii{1,2},1,pii{1,2},1,pii{1,2},1,pii{1,2}});
    return 0;
}
