#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
cpp_int factorial(int a)
{
    if(a==0 || a==1)
        return 1;
    else return a*factorial(a-1);
}
int main() {
    int a = 10;
    std::cout <<a <<"!= " << factorial(a) << std::endl;
    return 0;
}