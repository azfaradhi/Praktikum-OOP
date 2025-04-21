#include "Footballer.hpp"

Footballer::Footballer(){
    this->name = "noname";
    this->birthYear = 2000;
    this->playPosition = "none";
    this->nationality = "Indonesia";
    this->height = 180;
    this->weight = 70;
}

Footballer::Footballer(const string& name, int birthYear, const string& playPosition, const string& nationality, int height, int weight) {
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = playPosition;
    this->nationality = nationality;
    this->height = height;
    this->weight = weight;
}


Footballer::Footballer(const Footballer& other){
    this->name = other.name;
    this->birthYear = other.birthYear;
    this->playPosition = other.playPosition;
    this->nationality = other.nationality;
    this->height = other.height;
    this->weight = other.weight;
}

Footballer::~Footballer(){}

Footballer& Footballer::operator=(const Footballer& other){
    this->setName(other.name);
    this->birthYear = other.birthYear;
    this->setPlayPosition(other.playPosition);
    this->setNationality(other.nationality);
    this->setHeight(other.height);
    this->setWeight(other.weight);
    return *this;
}

void Footballer::setName(string a){
    this->name = a;
}
string Footballer::getName() const{
    return this->name;
}

void Footballer::setPlayPosition(string a){
    this->playPosition = a;
}
string Footballer::getPlayPosition() const {
    return this->playPosition;
}

void Footballer::setNationality(string a){
    this->nationality = a;
}
string Footballer::getNationality() const{
    return this->nationality;
}

void Footballer::setHeight(int a){
    this->height = a;
}
int Footballer::getHeight() const{
    return height;
}
void Footballer::setWeight(int a){
    this->weight = a;
}
int Footballer::getWeight() const{
    return this->weight;
}
int Footballer::getAge() const{
    return CURRENT_YEAR - this->birthYear;
}
float Footballer::getBMI() const{
    float met = this->height/100.0;
    return this->weight / (met * met);
}

string Footballer::getCategory(){
    float a = getBMI();
    if (a < 18.5){
        return "Underweight";
    }
    if (a < 25.0){
        return "Normal";
    }
    if (a < 30.0){
        return "Overweight";
    }
    return "Obese";
}
void Footballer::displayInfo(){
    cout << "Name: " << this->name << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Position: " << this->playPosition << endl;
    cout << "Nationality: " << this->nationality << endl;
    cout << "BMI: " << fixed << setprecision(2) << getBMI() << " (" << getCategory() << ")" << endl;
    cout << "Transfer Rate: " << this->transferRate() << endl;
}