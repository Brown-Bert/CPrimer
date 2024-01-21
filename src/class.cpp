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
    int mem(){
        puts("hello");
        return 0;
    }
};

struct D : public base
{
    int mem(int){
        puts("jg");
        return 0;
    }
};
int main(int argc, char* argv[])
{
    base b;
    D d;
    b.mem();
    exit(0);
}