#include <iostream>
#include <vector>
#include <unordered_map>

typedef std::vector<int> vi;

int optimized(vi const &nums, int k) {
    int result = 0;
    int current_sum = 0;
    std::unordered_map<int,int> map;
    size_t n = nums.size();

    map[0] = 1;
    for (int i=0; i<n; i++) {
        current_sum += nums[i];
        result += map[current_sum - k];
        map[current_sum] += 1;
    }
    return result;
}

int bruteforce(vi const &nums, int tsum) {
    int result = 0;
    size_t n = nums.size();
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            //std::cout << sum << " + " << nums[j] << std::endl;
            sum += nums[j];
            if (sum == tsum) {
                result += 1;
            }
        }
    }
    return result;
}

void test(std::string const &testname, vi const &nums, int tsum) {
    int bs = bruteforce(nums, tsum);
    int os = optimized(nums, tsum);
    std::cout << testname << ": " << ((bs == os)? "PASSED!" : "FAILED!") << " => " << "BS: "<< bs << ", " << "OS: " << os << std::endl;
}

int main(int argc, char** argv) {
    test("Ascending", {1,2,3,4,5,6,7,8,9,10,11,12}, 12);
    test("basic",          {1, 1, 1},          2);
    test("single match",   {1, 2, 3},          3);
    test("negatives",      {1, -1, 1},         1);
    test("all zeros",      {0, 0, 0},          0);
    test("no match",       {1, 2, 3},          7);
    test("whole array",    {1, 2, 3, 4},      10);
    test("duplicates",     {3, 3, 3},          6);
    test("single elem",    {5},                5);
    test("large k",        {1, 2, 3, 4, 5},   15);
    test("neg and pos",    {-1, 2, -1, 2},     2);
    return 0;
}