#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <unordered_map>

typedef std::vector<std::pair<int,int>> vpii;
typedef long long ll;

vpii optimized( std::vector<int> const &numbers, ll const tsum, ll const tprod) {
    vpii result;
    size_t size = numbers.size();
    for (int i=0; i<size; i++) {

    }
    return result;
}

vpii bruteforce( std::vector<int> const &numbers, ll const tsum, ll const tprod) {
    vpii result;
    size_t const size = numbers.size();
    for (int i=0; i<size-1; i++) {
        for (int j=i+1; j<size; j++) {
            int numi = numbers[i];
            int numj = numbers[j];
            if (numi + numj == tsum && numi * numj == tprod) {
                result.push_back({numi,numj});
            }
        }
    }
    return result;
}

void test(std::string const &testname, std::vector<int> const &numbers, ll tsum, ll tprod) {
    std::cout << "Test Name: " << testname << " -> ";
    vpii optimized_output = optimized(numbers, tsum, tprod);
    vpii bruteforce_output = bruteforce(numbers, tsum, tprod);
    std::sort(optimized_output.begin(), optimized_output.end());
    std::sort(bruteforce_output.begin(), bruteforce_output.end());
    std::cout << ((optimized_output == bruteforce_output) ? "PASSED!" : "FAILED!") << std::endl;
}

int main(int argc, char **argv) {
    test("simple",{2,4,6,3,1},7, 12);
    return 0;
}