#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <unordered_map>

typedef std::pair<int,int> pii;
typedef std::vector<pii> vpii;
typedef long long ll;

std::ostream& operator<<(std::ostream& os, pii const &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, vpii const &vp) {
    os << "[";
    for(pii p : vp) {
        os << "(" << p.first << "," << p.second << "),";
    }
    os << "]";
    return os;
}

vpii root_finder(std::vector<int> const &numbers, int x, int y) {
    vpii result;
    std::unordered_map<int,std::vector<int>> map;
    for(int i=0; i<numbers.size(); i++) {
        if(numbers[i] == x || numbers[i] == y) {
            map[numbers[i]].push_back(i);
        }
    }
    if(x==y){
        size_t size = map[x].size();
        for(int a=0; a<size-1; a++) {
            for(int b=a+1; b<size; b++) {
                result.push_back({map[x][a],map[x][b]});
            }
        }
    } else {
        for(int a : map[x]) {
            for(int b : map[y]) {
                result.push_back({a,b});
            }
        }
    }
    
    std::cout << "\nOPTIMIZED =>" << result << std::endl;
    return result;
}

vpii optimized(std::vector<int> const &numbers, ll const tsum, ll const tprod) {
    
    size_t size = numbers.size();
    vpii emptyresult;
    
    if(numbers.size() < 2) { return emptyresult; }
    if(tprod != 0 && tsum == 0) { return emptyresult; }
    
    if(tprod == 0 && tsum == 0) {
        return root_finder(numbers, 0, 0);
    }
    
    if(tprod == 0 && tsum != 0) {
        return root_finder(numbers, 0, tsum);
    }
    
    int x = 0;
    int y = 0;
    bool roots_found = false;
    for (int i=0; i<size; i++) {
        int currno = numbers[i];
        if(currno * (tsum - currno) == tprod) {
            x = currno;
            y = tsum - currno;
            roots_found = true;
            break;
        }
    }
    
    if(roots_found) {
        return root_finder(numbers, x, y);
    } else {
        return emptyresult;
    }
    
}

vpii bruteforce( std::vector<int> const &numbers, ll const tsum, ll const tprod) {
    vpii result;
    size_t const size = numbers.size();
    for (int i=0; i<size-1; i++) {
        for (int j=i+1; j<size; j++) {
            int numi = numbers[i];
            int numj = numbers[j];
            if (numi + numj == tsum && numi * numj == tprod) {
                result.push_back({i,j});
            }
        }
    }
    std::cout << "BRUTE =>" << result << std::endl;
    return result;
}

void test(std::string const &testname, std::vector<int> const &numbers, ll tsum, ll tprod) {
    std::cout << "\nTest Name: " << testname << " -> ";
    vpii optimized_output = optimized(numbers, tsum, tprod);
    vpii bruteforce_output = bruteforce(numbers, tsum, tprod);
    std::sort(optimized_output.begin(), optimized_output.end());
    std::sort(bruteforce_output.begin(), bruteforce_output.end());
    std::cout << ((optimized_output == bruteforce_output) ? "PASSED!" : "FAILED!") << std::endl;
}

int main(int argc, char **argv) {
    
    test("Basic pair (2+7, 2*7)", { 2, 7, 4, 0, 9, 5, 1, 3 }, 9, 14);
    test("Multiple pairs (2+3, 2*3)", { 1, 5, 3, 2, -1, 6 }, 5, 6);
    test("Zero elements (0+0, 0*0)", { 0, 0 }, 0, 0);
    test("Duplicate values (3+3, 3*3)", { 3, 3 }, 6, 9);
    test("No valid pair", { 1, 2, 3 }, 10, 20);
    test("Negative numbers (-3+5, -3*5)", { -3, 7, 4, -2, 5 }, 2, -15);
    test("Single element (no pair possible)", { 5 }, 10, 25);
    test("All zeros, targetProduct != 0", { 0, 0, 0 }, 0, 5);
    test("Large repeated value", { 4, 4, 4, 4 }, 8, 16);
    
    return 0;
}
