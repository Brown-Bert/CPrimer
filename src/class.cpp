#include "class.h"
#include <cstdio>
class test : public Disc_quote
{
public:
    double net_price(std::size_t) const override{
        std::cout << "hello world" << std::endl;
        return 0.0;
    }
};
struct base
{
public:
    base() = default;
    base(int val) : a(val){};
    base(base &&b) : a(b.a){
        std::cout << "hello" << std::endl;
    };
    base(base &b) = default;
    // virtual void func();
public:
    int a = 0;
};

struct D : public base
{
    D() : base(){};
    D(int val1, int val2) : base(val1), b(val2){};
    D(D&& d) : base(std::move(d)) , b(d.b){
        // 如果是指针的话提交了权限之后，需要把移交源的指针清空
    };
    D(D &d) : base(d){};
public:
    int b = 1;
};
int main(int argc, char* argv[])
{
    D d(4, 8);
    D p(std::move(d));
    std::cout << p.a << std::endl;
    std::cout << p.b << std::endl;
    exit(0);
}