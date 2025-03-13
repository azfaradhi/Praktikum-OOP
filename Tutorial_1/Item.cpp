#include "Item.hpp"
#include <iostream>


int Item::totalRevenue = 0;
int Item::totalItems = 0;

Item:: Item(): stock(0),price(0),sold(0), serialNum(Item::totalItems+1){totalItems ++;}

Item::Item(int stock, int price): sold(0), stock(stock), price(price), serialNum(Item::totalItems + 1){Item::totalItems++;}

Item:: Item(const Item& A): serialNum(Item::totalItems+1){
    this->stock = A.stock;
    this->price = A.price;
    this->sold = A.sold;
    Item::totalItems++;
}

Item::~Item() {}


int Item::getSerialNum() const{
    return this->serialNum;
}

int Item::getSold() const{
    return this->sold;
}

int Item::getPrice() const{
    return this->price;
}

void Item::addStock(int addedStock) {
    this->stock += addedStock;
}

void Item::sell(int soldStock){
    if (this->stock - soldStock < 0){
        this->sold += this->stock;
        Item::totalRevenue += this->stock*this->price;
        this->stock = 0;
    }
    else{
        this->stock -= soldStock;
        this->sold += soldStock;
        Item::totalRevenue += soldStock * this->price;
    }
}

void Item::setPrice(int newPrice){
    this->price = newPrice;
}