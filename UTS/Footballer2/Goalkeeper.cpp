#include "Goalkeeper.hpp"

Goalkeeper::Goalkeeper(): Footballer(){
    this->cleanSheets = 0;
    this->saves = 0;
    this->totalShotsOnGoal = 0;
    this->playPosition = "goalkeeper";
}

Goalkeeper::Goalkeeper(const string& a, int b, int c, int d, int f): Footballer(a,b,"goalkeeper","Indonesia",180,70){
    this->cleanSheets = c;
    this->saves = d;
    this->totalShotsOnGoal = f;
}
void Goalkeeper::setCleanSheets(int a){
    this->cleanSheets = a;
}
int Goalkeeper::getCleanSheets(){
    return this->cleanSheets;
}
void Goalkeeper::setSaves(int a){
    this->saves = a;
}
int Goalkeeper::getSaves(){
    return this->saves;
}
void Goalkeeper::setTotalShotsOnGoal(int a){
    this->totalShotsOnGoal = a;
}
int Goalkeeper::getTotalShotsOnGoal(){
    return this->totalShotsOnGoal;
}
float Goalkeeper::savePercentage(){
    if (totalShotsOnGoal == 0){
        return 0.0;
    }
    return (static_cast<float>(saves) / totalShotsOnGoal) * 100;
}
int Goalkeeper::transferRate(){
    return (700000 * cleanSheets) + (50000 * saves);
}
void Goalkeeper::displayInfo(){
    Footballer::displayInfo();
    cout << "Clean Sheets: " << this->cleanSheets << endl;
    cout << "Saves: " << this->saves << endl;
    cout << "Save Percentage: " << fixed << setprecision(2) << savePercentage() << "%" << endl;
}