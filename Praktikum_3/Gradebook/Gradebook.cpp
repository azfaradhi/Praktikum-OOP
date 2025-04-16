#include "Gradebook.hpp"

void Gradebook::addOrUpdateStudent(const string &studentName, double grade){
    if (studentGrades.find(studentName) != studentGrades.end()){
        studentGrades.find(studentName)->second += grade;
        return;
    }
    studentGrades[studentName] = grade;
}

bool Gradebook::removeStudent(const string &studentName){
    if (studentGrades.find(studentName) == studentGrades.end()){
        return false;
    }
    auto it = studentGrades.find(studentName);
    studentGrades.erase(it);
    return true;
}

bool Gradebook::getGrade(const string &studentName, double &grade) const {
    if (studentGrades.find(studentName) == studentGrades.end()){
        return false;
    }
    auto it = studentGrades.find(studentName);
    grade = it->second;
    return true;
}

bool Gradebook::studentExists(const string &studentName) const{
    return !(studentGrades.find(studentName) == studentGrades.end());
}


void Gradebook::printGrades() const{
    int idx = 1;
    for (auto it = studentGrades.begin(); it != studentGrades.end(); it++){
        cout << idx << ". " << it->first << ": " << it->second << endl;
        idx ++;
    }
}

void Gradebook::printGradesRank() const{
    vector<pair<string,double>> data;
    for (auto it = studentGrades.begin(); it != studentGrades.end(); it++){
        data.emplace_back(it->first,it->second);
    }
    sort(data.begin(),data.end(),[] (auto&left, auto &right){
        return left.second > right.second;
    });
    int idx = 1;
    for (auto& pair:data) {
        cout << idx << ". " << pair.first << ": " << pair.second << endl;
        idx++;
    }
}

vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const {
    vector<string> daftar;
    for (auto it = studentGrades.begin(); it != studentGrades.end(); it++){
        if (it->second > threshold) {
            daftar.push_back(it->first);
        }
    }
    sort(daftar.begin(), daftar.end());
    return daftar;
}

double Gradebook::getAverageGrade() const{
    if (studentGrades.size() == 0){
        return 0.0;
    }
    double avg = 0.0;
    for (auto it = studentGrades.begin(); it != studentGrades.end(); it++){
        avg += it->second;
    }
    return avg/studentGrades.size();
}

size_t Gradebook::getNumberOfStudents() const{
    return studentGrades.size();
}