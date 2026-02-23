#include <iostream>
#include <unordered_map>

int optimized(std::string const &qstring) {
    int result = 0;

    return result;
}

int bruteforce(std::string const &qstring) {
    int result = 0;
    std::unordered_map<char, int> map;
    size_t const size = qstring.size();
    int longest = 0;
    int current = 0;
    for (int i = 0; i < size; i++) {
        if (map.find(qstring.at(i)) != map.end()) {
            longest = std::max(current, longest);
            map.clear();
            current = 0;
        } else {
            map[qstring.at(i)] = 1;
            current += 1;
        }
    }
    result = longest;
    return result;
}

void test(std::string const &qstring) {
    int brute_result = bruteforce(qstring);
    int optim_result = optimized(qstring);
    std::cout << qstring << ": " << ((brute_result == optim_result)? "PASSED!" : "FAILED!") << " => " << "BF_O: "<< brute_result << ", " << "OF_O: " << optim_result << std::endl;
}

int main(int argc, char** argv) {
    test("Ascending");
    test("basic");
    test("single match");
    test("negatives");
    test("all zeros");
    test("no match");
    test("whole array");
    test("duplicates");
    test("single elem");
    test("large k");
    test("neg and pos");
    return 0;
}