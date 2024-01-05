#include "Secretary.cpp"
#include <string>
#include <cstring>
#include <unordered_map>


class Course{
    private:
        string courseName;
        int ects;
        bool compulsory;
        int courseId;
    public:
        Course(string c_name, int ec, bool comp, int Id): courseName(c_name), ects(ec), compulsory(comp), courseId(Id){}

        void display(){
            cout << "Course: " << courseName << ", Ects: " << ects << ", Compulsory: " << (compulsory ? "Yes" : "No") << ", Course Id: " << courseId <<endl;
        }

        void setName(string nam){
            courseName = nam;
        }

        void setEcts(int ect){
            ects = ect;
        }

        void setCompulsory(bool comp){
            compulsory = comp;
        }


        string getCourseName(){
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
        unordered_map <string, vector<Professor>> teachers;
    public:
        void setTeachers(Course course, vector<Professor> professors) {
            teachers[course.getCourseName()] = professors;
        }

      /*  vector<Professor> getTeachers(string courseName) {   //?
            vector<Professor> emptyVector;
            auto it = teachers.find(courseName);
            return (it != teachers.end()) ? it->second : emptyVector;
        } */
}; 

class UniSystem {
        vector <Student> students;
        vector <Professor> professors;
        vector <Course> courses;
        unordered_map <int, vector <Course>> enrolledCourses;
        Semester semester;
    public:
    

        void changeName(Student& student, string nam){
            for(auto i = 0; i < students.size(); i++){
                if(student.getStudentId() == students[i].getStudentId()){
                    student.setName(nam);
                    students[i].setName(nam);
                    return;
                }
            }
            cout<<"Student not found"<<endl;
        }

        void changeSurname(Student& student, string sur){
            for(auto i = 0; i < students.size(); i++){
                if(student.getStudentId() == students[i].getStudentId()){
                    student.setSurname(sur);
                    students[i].setSurname(sur);
                    return;
                }
            }
            cout<<"Student not found"<<endl;
            
        }

        void changeAge(Student& student, int ag){
            for(auto i = 0; i < students.size(); i++){
                if(student.getStudentId() == students[i].getStudentId()){
                    student.setAge(ag);
                    students[i].setAge(ag);
                    return;
                }
            }
            cout<<"Student not found"<<endl;
        }

        void addStudent(Student& student) {
            students.push_back(student);
        }

        void deleteStudent(Student& student){
            for(auto i = 0; i < students.size(); i++){
                if(student.getStudentId() == students[i].getStudentId()){
                    students.erase(students.begin() + i);
                    return;
                }
            }
        }

        void changeName(Professor& professor, string nam){
            for(auto i = 0; i < professors.size(); i++){
                if(professor.getProfessorId() == professors[i].getProfessorId()){
                    professor.setName(nam);
                    professors[i].setName(nam);
                    return;
                }
            }
            cout<<"Professor not found"<<endl;
        }

        void changeSurname(Professor& professor, string sur){
            for(auto i = 0; i < professors.size(); i++){
                if(professor.getProfessorId() == professors[i].getProfessorId()){
                    professor.setSurname(sur);
                    professors[i].setSurname(sur);
                    return;
                }
            }
            cout<<"Professor not found"<<endl;
        }

        void changeAge(Professor& professor, int ag){
            for(auto i = 0; i < professors.size(); i++){
                if(professor.getProfessorId() == professors[i].getProfessorId()){
                    professor.setAge(ag);
                    professors[i].setAge(ag);
                    return;
                }
            }
            cout<<"Professor not found"<<endl;
        }

        void addProfessor(Professor& professor) {
            professors.push_back(professor);
        }

        void deleteProfessor(Professor& professor){
            for(auto i = 0; i < professors.size(); i++){
                if(professor.getProfessorId() == professors[i].getProfessorId()){
                    professors.erase(professors.begin() + i);
                    return;
                }
            }
        }
        

        void addCourse(Course& course) {
            courses.push_back(course);
        }

        void deleteCourse(Course& course){
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    courses.erase(courses.begin() + i);
                    return;
                }
            }
        }

        void changeName(Course& course, string nam){
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    course.setName(nam);
                    courses[i].setName(nam);
                    return;
                }
            }
            cout<<"Course not found"<<endl;
        }

        void changeEcts(Course& course, int ect){
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    course.setEcts(ect);
                    courses[i].setEcts(ect);
                    return;
                }
            }
            cout<<"Course not found"<<endl;
        }

        void changeCompulsory(Course& course, bool comp){
            for(auto i = 0; i < courses.size(); i++){
                if(course.getCourseId() == courses[i].getCourseId()){
                    course.setCompulsory(comp);
                    courses[i].setCompulsory(comp);
                    return;
                }
            }
            cout<<"Course not found"<<endl;
        }

        void appointTeachers(Course course, vector<Professor> professors) {
            semester.setTeachers(course, professors);
        }

        void enrollStudentInCourse(Student student, Course course) {
            enrolledCourses[student.getStudentId()].push_back(course);
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