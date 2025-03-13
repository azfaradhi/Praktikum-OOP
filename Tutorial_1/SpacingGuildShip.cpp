#include "SpacingGuildShip.hpp"
#include <iostream>


float SpacingGuildShip:: totalGuildTravel = 0;
int SpacingGuildShip:: producedShips = 0;
SpacingGuildShip::SpacingGuildShip() : passengerCount(0), guildNavigatorCount(3), maxPassengerCap(50), spiceStock(50), operatingGuildNavigator(3), serialNum(SpacingGuildShip::producedShips+1){producedShips++;}

SpacingGuildShip:: SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock): maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(producedShips+1){
    producedShips++;
    this->spiceStock =  spiceStock;
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& S): maxPassengerCap(S.maxPassengerCap), guildNavigatorCount(S.guildNavigatorCount), serialNum(producedShips+1){
    this->passengerCount = S.passengerCount;
    this->operatingGuildNavigator = S.operatingGuildNavigator;
    this->spiceStock = S.spiceStock;
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip(){}

int SpacingGuildShip::getShipSerialNum() const{
    return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const{
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance){
    if (this->operatingGuildNavigator == 0){}
    else{
        totalGuildTravel += (distance / (E*E*this->operatingGuildNavigator));
        operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPasengers){
    if (this->passengerCount + addedPasengers > this->maxPassengerCap){
        this->passengerCount = this->maxPassengerCap;
    }
    else{
        this->passengerCount+= addedPasengers;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers){
    if (this->passengerCount - droppedPassengers < 0){
        this->passengerCount = 0;
    }
    else{
        this->passengerCount-= droppedPassengers;
    }
}

void SpacingGuildShip::refreshNavigator(int n){
    if ((operatingGuildNavigator + n) > guildNavigatorCount){
        n = guildNavigatorCount - operatingGuildNavigator;
    }
    int max = spiceStock / GUILD_NAVIGATOR_SPICE_DOSE;
    if (max < n){
        n = max;
    }
    this->operatingGuildNavigator += n;
    this->spiceStock -= n * GUILD_NAVIGATOR_SPICE_DOSE;
}

void SpacingGuildShip::transitToArrakis(int addedSpice){
    this->spiceStock += addedSpice;
}