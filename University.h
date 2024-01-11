#include "Course.h"
#include "fout.cpp"
#include "fin.cpp"
#include <time.h>
#include <cstdlib>
#include <cmath>
#define MAX_YEARS 2
#define COMPULSORY_COURSES 3
#define MIN_ECTS 30


class UniSystem {
        vector <Student> students;            //Φτιάχνω ένα vector απο Student
        vector <Professor> professors;        //Φτιάχνω ένα vector απο Professor
        vector <Course> courses;              //Φτιάχνω ένα vector απο Course
        unordered_map <int, vector <Course>> enrolledCourses;           //unorderd map για enrolled Courses με παραμετρους int για εξάμηνο και vector <course> για τα μαθήματα του εξαμήνου
        unordered_map <int, vector <Course>> enrolledStudentInCourses;  //unordered map για τα μαθήματα που κανει enroll ένας μαθητής με παραμέτρους int για το id μαθητή και vector <courses> για τα μαθήματα που πήρε ο μαθητής
        unordered_map <int, vector <int>> studentGradesInCourses;       //unordered map για τους βαθμους σε μαθήματα ενώς μαθητή με παραμέτρους int για το id μαθητή και vector <int> για τους βαθμούς σε μαθήματα που πήρε ο μαθητής
        Semester semester;                                              //Φτιάχνω ένα αντικείμενο κλάσης Semester

        bool hasCompletedRequirements(Student &student){                //Συνάρτηση που ελέγχει αν ένας μαθητής πληρεί τις απαιτήσεις για πτυχίο και επιστρέφει αληθής ή ψευδής ανάλογα
            int sum_compulsory = 0;
            int sum_ects = 0;
            if(student.getStudentYear() >= MAX_YEARS){
                vector <Course> course = enrolledStudentInCourses[student.getStudentId()];
                for(auto i = 0; i < course.size(); i++){
                    if(studentGradesInCourses[student.getStudentId()][i] >= 5){
                        if(course[i].isCompulsory() == 1){
                            sum_compulsory++;
                        }
                        sum_ects += course[i].getEcts();
                    }
                    if(sum_compulsory >= COMPULSORY_COURSES && sum_ects >= MIN_ECTS){
                        return 1;
                    }
                }
            }
            return 0;
        }

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

        vector <Student> deleteStudent(Student& student){                      //Διαγράφω έναν student απο τον vector students
            for(auto i = 0; i < students.size(); i++){
                if(student.getStudentId() == students[i].getStudentId()){
                    students.erase(students.begin() + i);
                    return students;
                }
            }
            return students;
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

        vector <Professor> deleteProfessor(Professor& professor){                   //Διαγράφω έναν professor απο το vector professors
            for(auto i = 0; i < professors.size(); i++){
                if(professor.getProfessorId() == professors[i].getProfessorId()){
                    professors.erase(professors.begin() + i);
                    return professors;
                }
            }
            return professors;
        }
        

        void addCourse(Course& course) {                                            //Προσθέτω ενα course στο vector courses
            courses.push_back(course);
        }

        vector <Course> deleteCourse(Course& course){                              //Διαγράφω ενα course απο το vector courses
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    courses.erase(courses.begin() + i);
                    return courses;
                }
            }
            return courses;
        }

        void changeName(Course& course, string nam){                               //Αλλάζω το όνομα ενώς course με βαση το id του
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    course.setName(nam);
                    courses[i].setName(nam);
                    return;
                }
            }
            cout<<"Course not found"<<endl;
        }

        void changeEcts(Course& course, int ect){                                  //Αλλάζω τα ects ενώς course με βαση το id του
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    course.setEcts(ect);
                    courses[i].setEcts(ect);
                    return;
                }
            }
            cout<<"Course not found"<<endl;
        }

        void changeCompulsory(Course& course, bool comp){                          //Αλλάζω την υποχρεωτικότητα ενώς course με βαση το id του
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    course.setCompulsory(comp);
                    courses[i].setCompulsory(comp);
                    return;
                }
            }
            cout<<"Course not found"<<endl;
        }

        void enrollCourses(int semester, vector <Course> courses){                //Εγγράφω τα μαθήματα ενώς εξαμήνου σε ενα unordered map (enrolledCourses)
            enrolledCourses[semester - 1] = courses;
        }

        void changeCourseSemester(Course course, int prevSemester, int newSemester){        //Αλλάζω το εξάμηνο ενώς μαθήματος
            vector <Course> c = enrolledCourses[prevSemester - 1];
            for(auto i = 0; i < c.size(); i++){
                if(course.getCourseId() == c[i].getCourseId()){
                    c.erase(c.begin() + i);
                }
                enrolledCourses[prevSemester - 1] = c;
                enrolledCourses[newSemester - 1].push_back({course});
                return;
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


        void printStudents(){                                               //Εκτυπώνω όλους τους μαθητές
            for(auto i = 0; i < students.size(); i++){
                students[i].print();
            }
        }

        void printProfessors(){                                             //Εκτυπώνω όλους τους professors
            for(auto i = 0; i < professors.size(); i++){
                professors[i].print();
            }
        }

        void printCourses(){                                                 //Εκτυπώνω ολα τα courses
            for(auto i = 0; i < courses.size(); i++){
                courses[i].display();
            }
        }

        void displayPassedStudents(Course &course, int academicSemester) {      //Εκτυπώνω τους μαθητές που πέρασαν ένα μαθημα σε συγκεκριμένο εξάμηνο και τους εισάγω σε ενα αρχείο PassedStudents.txt
            cout << "Students who passed " << course.getCourseName() << " in semester " << academicSemester << ":\n";
            vector <Student> students2;
            for(auto i = 100; i < enrolledStudentInCourses.size() + 100; i++){
                vector <Course> courses2 = enrolledStudentInCourses[i];
                for(auto j = 0; j < courses2.size(); j++){
                    int grade = giveGrade(i + j);
                    studentGradesInCourses[i].push_back(grade);
                    if(course.getCourseId() == courses2[j].getCourseId()){
                        if(grade >= 5){
                            for(auto k = 0; k < students.size(); k++){
                                if(students[k].getStudentId() == i) {
                                    students[k].print();
                                    students2.push_back(students[k]);
                                }
                            }
                        }
                        
                       
                    }
                }
            }
            studentFout(students2, "PassedStudents.txt");
        }

        void professorStatistics(Professor &professor, int sem){                //Εκτυπώνω τα statistics ενώς καθηγητή
            cout << "Professor " << professor.getName() << "'s statistics for semester " << sem << ":\n";
            unordered_map <string, vector<Professor>> teachers = semester.getTeachersMap();
            for(auto i = 0; i < courses.size(); i++){
                vector <Professor> prof = teachers[courses[i].getCourseName()];
                for(auto j = 0; j < prof.size(); j++){
                    if(prof[j].getProfessorId() == professor.getProfessorId()){
                        for(auto k = 0; k < enrolledCourses.size(); k++){
                            vector <Course> cour = enrolledCourses[k];
                            for (auto l = 0; l < cour.size(); l++){
                                if(cour[l].getCourseId() == courses[i].getCourseId() && sem == k+1){
                                    cout << "Course: " << courses[i].getCourseName()<< endl;
                                    for(auto m = 100; m < enrolledStudentInCourses.size() + 100; m++){
                                        vector <Course> c = enrolledStudentInCourses[m];
                                        for(auto n = 0; n < c.size(); n++){
                                            if(c[n].getCourseId() == courses[i].getCourseId()){
                                                cout << " Student: " << students[m - 100].getName() << ", Grade: " << studentGradesInCourses[m][n] << endl;
                                            }
                                        }
                                    }
                                }
                            }
                        
                        }
                
                    }
                
                }
            }
        }

        void printStudentGradesInAllSemesters(Student &student){                //Εκτυπώνω τους βαθμούς ενώς μαθητή για όλα τα μαθήματα σε όλα τα εξάμηνα
            cout << "Analytical grades for student " << student.getName() << " (ID: " << student.getStudentId() << ") "  << ":\n";
            vector <Course> c = enrolledStudentInCourses[student.getStudentId()];
            for(auto n = 0; n < c.size(); n++){
                cout << " Course: " << c[n].getCourseName() << ", Grade: " << studentGradesInCourses[student.getStudentId()][n] << endl;
            }
        }

        void printStudentGradesBySemester(Student &student, int sem){           //Εκτυπώνω τους βαθμούς ενώς μαθητή για τα μαθήματα ενώς εξαμήνου
             cout << "Analytical grades for student " << student.getName() << " (ID: " << student.getStudentId() << ") " << " in semester "<< sem << ":\n";
            vector <Course> course = enrolledCourses[sem - 1];
            for (auto i = 0; i < course.size(); i++){
                vector <Course> c = enrolledStudentInCourses[student.getStudentId()];
                for (auto j = 0; j < c.size(); j++){
                    if(course[i].getCourseId() == c[j].getCourseId()){
                        cout << "Course: " << c[j].getCourseName() << ", Grade: " << studentGradesInCourses[student.getStudentId()][j] << endl;
                    }
                }
            }
        }

        void printElligibleForDegree() {                            //Εκτυπώνω τους μαθητές που πληρούν τις απαιτήσεις για πτυχίο
            cout << "Students eligible for degree:\n";
            for(auto i = 0; i < students.size(); i++){
                if(hasCompletedRequirements(students[i]) == 1){
                    students[i].print();
                }
            }
        }

        

        int giveGrade(int i){                                       //Συνάρτηση παραγωγής τυχαίου βαθμόυ μαθήματος
            int lb = 0, ub = 10;
            srand((i)*time(0));
            int grade = (rand() % (ub - lb + 1)) + lb;
            return grade; 
        }


          

};