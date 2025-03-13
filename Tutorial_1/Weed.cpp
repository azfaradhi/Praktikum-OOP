#include "Weed.hpp"
#include <stdio.h>
#include <iostream>

Weed::Weed(): many(1){}
Weed::Weed(int n): many(n){}
Weed::Weed(const Weed &b): many(b.many){}
Weed::~Weed(){}
void Weed::step(){
    for (int i = 0; i< this->many; i++){
        std::cout << "kresek...";
    }
    std::cout << std::endl;
}