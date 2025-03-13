#include "A.hpp"
#include "iostream"

int main(){
    A x('1');
    A y('2');
    A z(x);
    z = y;
    y.show();




}