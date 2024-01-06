#include <iostream>
#include <string>
#include <vector>
#include "University.h"
#define MAXSEMESTERS 2


int main() {                            

    UniSystem university;                           //Ορίζω ενα αντικείμενο κλάσης UniSystem το οποίο θα διαχειρίζει όλα τα παρακάτω

    Student s1(20, "Chris", "Badas", 1, 100);          //Φτιάχνω students και τους προσθέτω στον vector του university
    Student s2(22, "Nick", "Badas", 2, 101);
    university.addStudent(s1);
    university.addStudent(s2);
    university.printStudents();                     //Τους εκτυπώνω
    university.changeName(s1, "Mike");              //Αλλάζω τα περιεχόμενα τους
    university.changeSurname(s1, "Feliz");
    university.changeAge(s1, 28);
    cout<<"------"<<endl;
    university.deleteStudent(s2);                   //Διαγράφω έναν student και εκτυπώνω τον ανανεομένο vector απο professors
    university.printStudents();
    cout<<endl;

    Professor p1(35, "David", "Crow", 200);         //Φτιάχνω professors και τους προσθέτω στον vector του university
    Professor p2(40, "Johnson", "Malb", 201), p3(34, "Mike", "Bat", 202);   
    university.addProfessor(p1);
    university.addProfessor(p2);
    university.addProfessor(p3);
    university.printProfessors();                   //Τους εκτυπώνω
    university.changeName(p1, "Jim");               //Αλλάζω τα περιεχόμενα τους
    university.changeSurname(p1, "Dake");
    university.changeAge(p1, 45);
    cout<<"------"<<endl;
    university.deleteProfessor(p2);                 //Διαγράφω έναν professor και εκτυπώνω τον ανανεομένο vector απο students
    university.printProfessors();
    cout<<endl;

    Course c1("C++ Programming", 8, true, 300);     //Φτιάχνω courses και τα προσθέτω στον vector του university
    Course c2("C Programming", 6, true, 301), c3("Java", 9, true, 302);
    university.addCourse(c1);
    university.addCourse(c2);
    university.addCourse(c3);
    university.printCourses();                      //Τα εκτυπώνω
    university.changeName(c2, "Python");            //Αλλάζω τα περιεχόμενα τους
    university.changeEcts(c2, 10);  
    university.changeCompulsory(c2, false);
    cout<<"------"<<endl;
    university.deleteCourse(c1);                    //Διαγράφω ένα course και εκτυπώνω τον ανανεομένο vector απο courses
    university.printCourses();
    cout<<endl;

    university.enrollCourses(1, {c1, c2});          //Εγγράφω τα μαθήματα ανά εξάμηνο
    university.enrollCourses(3, {c3});      
    university.printCoursesBySemester(1);           //Τα εκτυπώνω
    university.printCoursesBySemester(2);
    university.printCoursesBySemester(3);
    cout<<endl;

    university.changeCourseSemester(c1, 1, 2);      //Αλλάζω το εξάμηνο ενώς μαθήματος. Στις παραμέτρους έχω το course , το εξάμηνο που ήταν και το εξάμηνο που θέλω να πάει
    university.printCoursesBySemester(1);
    university.printCoursesBySemester(2);
    university.printCoursesBySemester(3);
    cout<<endl;

    university.appointProfessors(c1, {p1, p2});     //Εγγράφω τους καθηγητές ανά μάθημα
    university.appointProfessors(c2, {p2});
    university.printProfessorsByCourse(c1);         //Τους εκτυπώνω
    cout<<endl;

    university.enrollStudentInCourse(s1, {c1, c2});    //Εγγράφω τους μαθητές ανά μάθημα
    university.enrollStudentInCourse(s2, {c3});
    university.printCoursesByStudent(s1);               //Τους εκτυπώνω
    university.printCoursesByStudent(s2);
    return 0;
}