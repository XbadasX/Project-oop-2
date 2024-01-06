#include "Course.h"

class UniSystem {
        vector <Student> students;            //Φτιάχνω ένα vector απο Student
        vector <Professor> professors;        //Φτιάχνω ένα vector απο Professor
        vector <Course> courses;              //Φτιάχνω ένα vector απο Course
        unordered_map <int, vector <Course>> enrolledCourses;   
        unordered_map <int, vector <Course>> enrolledStudentInCourses;
        Semester semester;
    public:
    

        void changeName(Student& student, string nam){                  //Αλλάζω το όνομα ενώς student με βαση το id του
            for(auto i = 0; i < students.size(); i++){
                if(student.getStudentId() == students[i].getStudentId()){
                    student.setName(nam);
                    students[i].setName(nam);
                    return;
                }
            }
            cout<<"Student not found"<<endl;
        }

        void changeSurname(Student& student, string sur){                   //Αλλάζω το επίθετο ενώς student με βαση το id του
            for(auto i = 0; i < students.size(); i++){
                if(student.getStudentId() == students[i].getStudentId()){
                    student.setSurname(sur);
                    students[i].setSurname(sur);
                    return;
                }
            }
            cout<<"Student not found"<<endl;
            
        }

        void changeAge(Student& student, int ag){                               //Αλλάζω την ηλικία ενώς student με βαση το id του
            for(auto i = 0; i < students.size(); i++){
                if(student.getStudentId() == students[i].getStudentId()){
                    student.setAge(ag);
                    students[i].setAge(ag);
                    return;
                }
            }
            cout<<"Student not found"<<endl;
        }

        void addStudent(Student& student) {                                    //Προσθέτω έναν student στο vector students
            students.push_back(student);
        }

        void deleteStudent(Student& student){                                  //Διαγράφω έναν student απο τον vector students
            for(auto i = 0; i < students.size(); i++){
                if(student.getStudentId() == students[i].getStudentId()){
                    students.erase(students.begin() + i);
                    return;
                }
            }
        }

        void changeName(Professor& professor, string nam){                      //Αλλάζω το όνομα ενώς professor με βαση το id του
            for(auto i = 0; i < professors.size(); i++){
                if(professor.getProfessorId() == professors[i].getProfessorId()){
                    professor.setName(nam);
                    professors[i].setName(nam);
                    return;
                }
            }
            cout<<"Professor not found"<<endl;
        }

        void changeSurname(Professor& professor, string sur){                   //Αλλάζω το επίθετο ενώς professor με βαση το id του
            for(auto i = 0; i < professors.size(); i++){
                if(professor.getProfessorId() == professors[i].getProfessorId()){
                    professor.setSurname(sur);
                    professors[i].setSurname(sur);
                    return;
                }
            }
            cout<<"Professor not found"<<endl;
        }

        void changeAge(Professor& professor, int ag){                            //Αλλάζω την ηλικία ενώς professor με βαση το id του
            for(auto i = 0; i < professors.size(); i++){
                if(professor.getProfessorId() == professors[i].getProfessorId()){
                    professor.setAge(ag);
                    professors[i].setAge(ag);
                    return;
                }
            }
            cout<<"Professor not found"<<endl;
        }

        void addProfessor(Professor& professor) {                                   //Προσθέτω έναν professor στο vector professors
            professors.push_back(professor);
        }

        void deleteProfessor(Professor& professor){                                 //Διαγράφω έναν professor απο το vector professors
            for(auto i = 0; i < professors.size(); i++){
                if(professor.getProfessorId() == professors[i].getProfessorId()){
                    professors.erase(professors.begin() + i);
                    return;
                }
            }
        }
        

        void addCourse(Course& course) {                                            //Προσθέτω ενα course στο vector courses
            courses.push_back(course);
        }

        void deleteCourse(Course& course){                                          //Διαγράφω ενα course απο το vector courses
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    courses.erase(courses.begin() + i);
                    return;
                }
            }
        }

        void changeName(Course& course, string nam){                                    //Αλλάζω το όνομα ενώς course με βαση το id του
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    course.setName(nam);
                    courses[i].setName(nam);
                    return;
                }
            }
            cout<<"Course not found"<<endl;
        }

        void changeEcts(Course& course, int ect){                                       //Αλλάζω τα ects ενώς course με βαση το id του
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    course.setEcts(ect);
                    courses[i].setEcts(ect);
                    return;
                }
            }
            cout<<"Course not found"<<endl;
        }

        void changeCompulsory(Course& course, bool comp){                               //Αλλάζω την υποχρεωτικότητα ενώς course με βαση το id του
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    course.setCompulsory(comp);
                    courses[i].setCompulsory(comp);
                    return;
                }
            }
            cout<<"Course not found"<<endl;
        }

        void enrollCourses(int semester, vector <Course> courses){                      //Εγγράφω τα μαθήματα ενώς εξαμήνου σε ενα unordered map (enrolledCourses)
            enrolledCourses[semester - 1] = courses;
        }

        void changeCourseSemester(Course course, int prevSemester, int newSemester){
            vector <Course> c = enrolledCourses[prevSemester - 1];
            for(auto i = 0; i < c.size(); i++){
                if(course.getCourseId() == c[i].getCourseId()){
                    c.erase(c.begin() + i);
                }
                enrolledCourses[prevSemester - 1] = c;
                enrolledCourses[newSemester - 1].push_back({course});
            }
        }

        void printCoursesBySemester(int semester){                                      //Εκτυπώνω τα μαθήματα ενώς εξαμήνου
            cout<< "In semester "<< semester << " there is/are: ";
            vector <Course> c = enrolledCourses[semester - 1];
            for (int i = 0; i < c.size(); i++){
                cout<< i + 1 <<". "<<c[i].getCourseName() <<" ";
            }
            cout<< endl;
        }

        void appointProfessors(Course course, vector<Professor> professors) {           //Εγγράφω τους καθηγητές σε μαθήματα
            semester.setProfessors(course, professors);
        }

        void printProfessorsByCourse(Course course){                                    //Εκτυπώνω τους καθηγητές ανα μάθημα
            cout << "Course "<<course.getCourseName()<<" is taught by: ";
            semester.getTeachers(course);
        }

        
        void enrollStudentInCourse(Student student,vector <Course> courses) {                    //Εγγράφω τον μαθητή σε μαθήματα
            int semester;
            if(student.getStudentYear() == 1){
                semester = 2;
            }
            else if(student.getStudentYear() == 2 ){
                semester = 4;
            }
            else if(student.getStudentYear() == 3 ){
                semester = 6;
            }
            else if(student.getStudentYear() == 4 ){
                semester = 8;
            }
            for(auto i = 0; i < courses.size(); i++){
                //cout<< "i = "<<i<<endl;
                for(auto j = 0; j < enrolledCourses.size(); j++){
                   // cout<<"j = "<<j<<endl;
                    vector <Course> c = enrolledCourses[j];
                    for(auto k = 0; k < c.size(); k++){
                        //cout<<"k = "<<k<<endl;
                        if(c[k].getCourseId() == courses[i].getCourseId()){
                            if(semester >= j + 1){
                                cout<<"Student "<<student.getName()<<" of year "<< student.getStudentYear()<< " enrolled in "<<courses[i].getCourseName()<<" of semester "<<j + 1<<endl;
                                enrolledStudentInCourses[student.getStudentId()].push_back({c[k]});
                            }
                        }
                    }
                }
            }
            
        }

        void printCoursesByStudent(Student student){                                      //Εκτυπώνω τα μαθήματα ενώς μαθητή
            cout<< "Student "<< student.getName() << " is enrolled in: ";
            vector <Course> c = enrolledStudentInCourses[student.getStudentId()];
            for (int i = 0; i < c.size(); i++){
                cout<< i + 1 <<". "<<c[i].getCourseName() <<" ";
            }
            cout<< endl;
        }


        void printStudents(){
            for(auto i = 0; i < students.size(); i++){
                students[i].print();
            }
        }

        void printProfessors(){
            for(auto i = 0; i < professors.size(); i++){
                professors[i].print();
            }
        }

        void printCourses(){
            for(auto i = 0; i < courses.size(); i++){
                courses[i].display();
            }
        }

};