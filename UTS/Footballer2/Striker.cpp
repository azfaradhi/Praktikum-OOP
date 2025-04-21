#include "Striker.hpp"

Striker::Striker(): Footballer(){
    this->goalScore = 0;
    this->shotsOnTarget = 0;
    this->playPosition = "striker";
}

Striker::Striker(const string& a, int b, int g, int h): Footballer(a,b,"striker","Indonesia",180,70){
    this->goalScore = g;
    this->shotsOnTarget = h;
}
void Striker::setGoalScore(int a){
    this->goalScore = a;
}
int Striker::getGoalScore(){
    return this->goalScore;
}
void Striker::setShotsOnTarget(int a){
    this->shotsOnTarget = a;
}
int Striker::getShotsOnTarget(){
    return this->shotsOnTarget;
}
float Striker::conversionRate(){
    if (shotsOnTarget == 0){
        return 0.0;
    }
    return (static_cast<float>(goalScore) / shotsOnTarget) * 100;
}
int Striker::transferRate(){
    return static_cast<int>(1000000 * goalScore + 10000.0f * conversionRate());
}
void Striker::displayInfo(){
    Footballer::displayInfo();
    cout << "Goals: " << this->goalScore << endl;
    cout << "Conversion Rate: " << fixed << setprecision(2) << conversionRate() << "%" << endl;
}