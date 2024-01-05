#include <iostream>
#include <string>
#include <vector>
#include "Course.h"

int main() {                            
    /* Secretary s;                        //Φτιάχνω αντικειμενο της secretary
    for(int i = 0; i < 5; i++){         //Φτιάχνω 5 αντικείμενα person και αποθηκεύονται στην secretary s
        cin >> s;
    }
    
    Person* p = new Person();           //Δημιουργώ pointer σε person και με τελεστή πρόσθεσης το εκχωρώ στην secretary s
    cin>>p;
    s + p;

    cout << s;                          //Εκτυπώνω ολα τα στοιχεία της secretary s

    cout<<"Created "<<count<<" persons"<<endl;     //Εκτυπώνω πόσα persons έχουν φτιαχτεί

    s.findPerson("Chris");     //Καλώ την συνάρτηση findPerson να ελέγξει αν υπάρχει το συγκεκριμένο όνομα

    Secretary s2;              //Φτιάχνω 2η secretary και της αναθέτω τα στοιχεία της 1ης με την υπερφόρτωση της ανάθεσης
    s2 = s;

    cout << s2;                //Εκτυπώνω την 2η secretary
    free(p); */

    UniSystem university;

    Student s1(20, "Chris", "Badas", 100);
    Student s2(22, "Nick", "Badas", 101);
    university.addStudent(s1);
    university.addStudent(s2);
    university.printStudents();
    university.changeName(s1, "Mike");
    university.changeSurname(s1, "Feliz");
    university.changeAge(s1, 28);
    cout<<"------"<<endl;
    university.deleteStudent(s2);
    university.printStudents();
    cout<<endl;

    Professor p1(35, "David", "Crow", 200);
    Professor p2(40, "Johnson", "Malb", 201), p3(34, "Mike", "Bat", 202);
    university.addProfessor(p1);
    university.addProfessor(p2);
    university.addProfessor(p3);
    university.printProfessors();
    university.changeName(p1, "Jim");
    university.changeSurname(p1, "Dake");
    university.changeAge(p1, 45);
    cout<<"------"<<endl;
    university.deleteProfessor(p2);
    university.printProfessors();
    cout<<endl;

    Course c1("C++ Programming", 8, true, 300);
    Course c2("C Programming", 6, true, 301);
    university.addCourse(c1);
    university.addCourse(c2);
    university.printCourses();
    university.changeName(c2, "Python");
    university.changeEcts(c2, 10);
    university.changeCompulsory(c2, false);
    cout<<"------"<<endl;
    university.deleteCourse(c1);
    university.printCourses();
    cout<<endl;

    return 0;
}