#include <algorithm>
#include <iterator>
#include <numeric>
#include <chrono>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <thread>
#include <sstream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <set>
using std::string;
// typedef int arr[10];
using arr = int[3];
int func(int a)
{
    std::cout << a << std::endl;
    return a;
}

class data
{
public:
    data(string no){
        this->bookNo = no;
    }
    string isbn()const{
        // bookNo = "asdfg";
        return bookNo;
    }
private:
    string bookNo;
};

class X
{
public:
    int i;
    int j;
public:
    X(int val): j(val), i(j){}; 
};


int main(int argc, char* argv[])
{
    // std::cin.clear();
    std::vector<int> v;
    v.push_back(1);
    v.push_back(-1);
    v.push_back(2);
    v.push_back(-2);
    auto f = [](int i) {
        if (i > 0)
        {
            return i;
        }else
        {
            return -i;
        }
    };
    std::transform(v.begin(), v.end(), v.begin(), f);
    std::for_each(v.begin(), v.end(), [](int i){
        std::cout << i << std::endl;
    });
    int x = 5;
    int&& rvalueRef = 10;
    int &s = rvalueRef;
    rvalueRef = 20;
    std::cout << rvalueRef << std::endl;
    auto t = std::back_inserter(v);
     
    exit(0);
}