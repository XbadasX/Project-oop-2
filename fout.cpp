#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

void studentFout(vector <Student> students, string filename){
    ofstream fout;
    fout.open(filename);

    if (fout.is_open()) {
        for(int i = 0; i < students.size(); i++){
            fout << students[i].getAge() << " " <<students[i].getName() << " "  << students[i].getSurname() << " " << students[i].getStudentYear() << " " << students[i].getStudentId()<<endl;
        }
        fout.close();
    } else {
        cout << "Unable to open file";
    }

}

void professorFout(vector <Professor> professors){
    ofstream fout;
    fout.open("ProfessorsAfter.txt");

    if (fout.is_open()) {
        for(int i = 0; i < professors.size(); i++){
            fout << professors[i].getAge() << " " <<professors[i].getName() << " "  << professors[i].getSurname() << " " << professors[i].getProfessorId()<<endl;
        }
        fout.close();
    } else {
        cout << "Unable to open file";
    }

}

void courseFout(vector <Course> courses){
    ofstream fout;
    fout.open("CoursesAfter.txt");

    if (fout.is_open()) {
        for(int i = 0; i < courses.size(); i++){
            fout << courses[i].getCourseName() << " " <<courses[i].getEcts() << " "<<courses[i].isCompulsory()<<" " << courses[i].getCourseId()<<endl;
        }
        fout.close();
    } else {
        cout << "Unable to open file";
    }

}

