#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

vector <Student> studentFin(string file){
    string fileName = file;
    ifstream fin;
    fin.open(fileName);
    vector <Student> students;
    string name, surname;
    int age, year, id;
    if(fin.is_open()){
        while(fin >> age >> name >> surname >> year >> id){
            students.emplace_back(age, name, surname, year, id);
        }
    }else {
        cout << "Unable to open file";
    }
    fin.close();
    return students;
}

vector <Professor> professorFin(string file){
    string fileName = file;
    ifstream fin;
    fin.open(fileName);
    vector <Professor> professors;
    string name, surname;
    int age, id;
    if(fin.is_open()){
        while(fin >> age >> name >> surname >> id){
            professors.emplace_back(age, name, surname, id);
        }
    } else {
        cout << "Unable to open file";
    }
    fin.close();
    return professors;
}

vector <Course> courseFin(string file){
    string fileName = file;
    ifstream fin;
    fin.open(fileName);
    vector <Course> courses;
    string name;
    int ects, id;
    bool comp;
    if(fin.is_open()){
        while(fin >> name >> ects >> comp >> id){
            courses.emplace_back(name, ects, comp, id);
        }
    } else {
        cout << "Unable to open file";
    }
    fin.close();
    return courses;
}