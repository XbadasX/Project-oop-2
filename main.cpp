#include <iostream>
#include <string>
#include <vector>
#include "University.h"


int main() {                            

    UniSystem university;                           //Ορίζω ενα αντικείμενο κλάσης UniSystem το οποίο θα διαχειρίζει όλα τα παρακάτω

    vector <Student> students = studentFin("Students.txt");
    university.addStudent(students[0]);
    university.addStudent(students[1]);
    university.addStudent(students[2]);
    university.printStudents();                 //Τους εκτυπώνω
    university.changeName(students[0], "Mike");              //Αλλάζω τα περιεχόμενα τους
    university.changeSurname(students[0], "Feliz");
    university.changeAge(students[0], 28);
    cout<<"------"<<endl;
    students = university.deleteStudent(students[1]);
    university.printStudents();
    studentFout(students, "StudentsAfter.txt");
    cout<<endl;

    vector <Professor> professors = professorFin("Professors.txt");
    university.addProfessor(professors[0]);
    university.addProfessor(professors[1]);
    university.addProfessor(professors[2]);
    university.printProfessors();                   //Τους εκτυπώνω
    university.changeName(professors[0], "Jim");               //Αλλάζω τα περιεχόμενα τους
    university.changeSurname(professors[0], "Dake");
    university.changeAge(professors[0], 45);
    cout<<"------"<<endl;
    professors = university.deleteProfessor(professors[1]);                 //Διαγράφω έναν professor και εκτυπώνω τον ανανεομένο vector απο students
    university.printProfessors();
    professorFout(professors);
    cout<<endl;

    vector <Course> courses = courseFin("Courses.txt");
   /* university.addCourse(courses[0]);
    university.addCourse(courses[1]);
    university.addCourse(courses[2]);
    university.addCourse(courses[3]); */
    for (auto i = 0; i < courses.size(); i++){
        university.addCourse(courses[i]);
    }
     university.printCourses();                      //Τα εκτυπώνω
    university.changeName(courses[1], "Python");            //Αλλάζω τα περιεχόμενα τους
    university.changeEcts(courses[1], 10);  
    university.changeCompulsory(courses[1], false);
    cout<<"------"<<endl;
    courses = university.deleteCourse(courses[0]);                    //Διαγράφω ένα course και εκτυπώνω τον ανανεομένο vector απο courses
    university.printCourses();
    courseFout(courses);
    cout<<endl;

    university.enrollCourses(1, {courses[0], courses[1], courses[2], courses[3]});          //Εγγράφω τα μαθήματα ανά εξάμηνο
    university.enrollCourses(3, {courses[4], courses[5], courses[6], courses[7], courses[8]});      
    university.printCoursesBySemester(1);           //Τα εκτυπώνω
    university.printCoursesBySemester(2);
    university.printCoursesBySemester(3);
    cout<<endl;

    university.changeCourseSemester(courses[0], 1, 2);      //Αλλάζω το εξάμηνο ενώς μαθήματος. Στις παραμέτρους έχω το course , το εξάμηνο που ήταν και το εξάμηνο που θέλω να πάει
    university.printCoursesBySemester(1);
    university.printCoursesBySemester(2);
    university.printCoursesBySemester(3);
    cout<<endl;

    university.appointProfessors(courses[0], {professors[0], professors[1]});     //Εγγράφω τους καθηγητές ανά μάθημα
    university.appointProfessors(courses[1], {professors[1]});
    university.appointProfessors(courses[2], {professors[0], professors[1]});
    university.appointProfessors(courses[3], {professors[0], professors[1]});
    university.appointProfessors(courses[4], {professors[0], professors[1]});
    university.appointProfessors(courses[5], {professors[0], professors[1]});
    university.appointProfessors(courses[6], {professors[0], professors[1]});
    university.appointProfessors(courses[7], {professors[0], professors[1]});
    university.appointProfessors(courses[8], {professors[0], professors[1]});
    university.printProfessorsByCourse(courses[0]);         //Τους εκτυπώνω
    cout<<endl;

    university.enrollStudentInCourse(students[0], {courses[0], courses[1], courses[2], courses[3], courses[4], courses[5], courses[6], courses[7], courses[8]});    //Εγγράφω τους μαθητές ανά μάθημα
    university.enrollStudentInCourse(students[1], {courses[0], courses[1], courses[2], courses[3], courses[4], courses[5], courses[6], courses[7], courses[8]});
    university.printCoursesByStudent(students[0]);               //Τους εκτυπώνω
    university.printCoursesByStudent(students[1]);
    cout<<endl;

    university.displayPassedStudents(courses[0], 2);
    cout<<endl;

    university.professorStatistics(professors[0], 3);
    cout<<endl;

    university.printStudentGradesInAllSemesters(students[0]);
    university.printStudentGradesInAllSemesters(students[1]);
    cout<<endl;

    university.printStudentGradesBySemester(students[1], 1);
    university.printStudentGradesBySemester(students[1], 2);
    university.printStudentGradesBySemester(students[1], 3);
    cout<<endl;

    university.printElligibleForDegree();
    return 0;
}