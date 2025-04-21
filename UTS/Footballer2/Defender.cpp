#include "Defender.hpp"

Defender::Defender():Footballer(){
    this->tackleSuccess = 0;
    this->interceptions = 0;
    this->playPosition = "defender";
}
Defender::Defender(const string& a, int b , int c, int d): Footballer(a,b,"defender","Indonesia",180,70){
    this->tackleSuccess = c;
    this->interceptions = d;
}

void Defender::setTackleSuccess(int a){
    this->tackleSuccess = a;
}
int Defender::getTackleSuccess(){
    return this->tackleSuccess;
}
void Defender::setInterceptions(int a){
    this->interceptions = a;
}
int Defender::getInterceptions(){
    return this->interceptions;
}
int Defender::defensiveRating(){
    return tackleSuccess*2 + interceptions;
}
int Defender::transferRate(){
    return (600000 * tackleSuccess) + (400000 * interceptions);
}
void Defender::displayInfo(){
    Footballer::displayInfo();
    cout << "Tackle Success: " << this->tackleSuccess << endl;
    cout << "Interceptions: " << this->interceptions << endl;
    cout << "Defensive Rating: " << this->defensiveRating() << endl;
}