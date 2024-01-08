#include "Secretary.cpp"
#include <string>
#include <cstring>
#include <unordered_map>


class Course{
    private:
        string courseName;              //Το όνομα του course
        int ects;                       //Τα ects του course
        bool compulsory;                //Η υποχρεωτικότητα του course
        int courseId;                   //Το Id του course
    public:
        Course(string c_name, int ec, bool comp, int Id): courseName(c_name), ects(ec), compulsory(comp), courseId(Id){}        //O constructor ενώς course

        void display(){         //Εκτυπώνω τα περιεχόμενα ενώς course
            cout << "Course: " << courseName << ", Ects: " << ects << ", Compulsory: " << (compulsory ? "Yes" : "No") << ", Course Id: " << courseId <<endl;
        }

        void setName(string nam){           //Ακολουθούν setters για όνομα, ects, υποχρεωτικότητα και id
            courseName = nam;
        }

        void setEcts(int ect){
            ects = ect;
        }

        void setCompulsory(bool comp){
            compulsory = comp;
        }


        string getCourseName(){             //Ακολουθούν getters για όνομα, ects, υποχρεωτικότητα και id
            return courseName;
        }

        int getEcts(){
            return ects;
        }

        bool isCompulsory(){
            return compulsory;
        }

        int getCourseId(){
            return courseId;
        }

};

class Semester{
        unordered_map <string, vector<Professor>> teachers;                     //Ενα unordered_map που περιέχει ενα vector με τους καθηγητές με βαση το μάθημα
    public:
        void setProfessors(Course course, vector<Professor> professors) {       //Κάνω set τους professors ενώς μαθήματος
            teachers[course.getCourseName()] = professors;
        }

        void getTeachers(Course course) {   //?                                 //Εκτυπώνω τους professors ενώς μαθήματος
            vector <Professor> p;
            p = teachers[course.getCourseName()];
            for (int i = 0; i < p.size(); i++){
                cout <<i + 1<<". "<< p[i]<<" ";
            }
            cout<<endl;
        }

        unordered_map <string, vector<Professor>> getTeachersMap(){
            return teachers;
        }
}; 
