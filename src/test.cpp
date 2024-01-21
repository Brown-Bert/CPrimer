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
    string i;
public:
    X() = default;
    X(string s) : i(s){}
    X(const X &x) : i(x.i){}
    X& operator=(const X &x);

};

class SmallInt
{
public:
    SmallInt(int i = 0) : val(i){}
    operator string() const {return "helloadadsfa";}
private:
    int val;
    int b;
};


int main(int argc, char* argv[])
{
    SmallInt si;
    string st = si;
    std::cout << st << std::endl;
    exit(0);
}

inline X& X::operator=(const X &x) = default;