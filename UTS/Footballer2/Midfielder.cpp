#include "Midfielder.hpp"

Midfielder::Midfielder(): Footballer(){
    this->assist = 0;
    this->keyPasses = 0;
    this->playPosition = "midfielder";
}
Midfielder::Midfielder(const string& a, int b,int g, int h): Footballer(a,b,"midfielder","Indonesia",180,70){
    this->assist = g;
    this->keyPasses = h;
}

void Midfielder::setAssist(int a){
    this->assist = a;
}
int Midfielder::getAssist(){
    return this->assist;
}
void Midfielder::setKeyPasses(int a){
    this->keyPasses = a;
}
int Midfielder::getKeyPasses(){
    return this->keyPasses;
}
int Midfielder::playmakerRating(){
    return (assist * 3) + keyPasses;
}
int Midfielder::transferRate(){
    return (800000 * assist) + (30000 * keyPasses);
}
void Midfielder::displayInfo(){
    Footballer::displayInfo();
    cout << "Assists: " << this->assist << endl;
    cout << "Key Passes: " << this->keyPasses << endl;
    cout << "Playmaker Rating: " << this->playmakerRating() << endl;
}