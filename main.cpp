#include <iostream>
#include <string>
#include <vector>
#include "University.h"

void displayMenu() {                        //Συνάρτηση που δείχνει το μενού επιλογών
    cout << "\nMenu:\n";
    cout << "0. Exit\n";
    cout << "1. Add a student\n";
    cout << "2. Modify a student\n";
    cout << "3. Delete a student\n";
    cout << "4. Add a professor\n";
    cout << "5. Modify a professor\n";
    cout << "6. Delete a professor\n";
    cout << "7. Add a course\n";
    cout << "8. Modify a course\n";
    cout << "9. Delete a course\n";
    cout << "10. Enroll courses in semesters\n";
    cout << "11. Change a course's semester\n";
    cout << "12. Appoint teachers for a course\n";
    cout << "13. Enroll a student in a course\n";
    cout << "14. Display and save in a file the students who passed a course in an academic semester\n";
    cout << "15. Allow a professor to print statistics of a semester for all his/her courses\n";
    cout << "16. Allow a student to print analytical grades for the current semester and all years\n";
    cout << "17. Print students who can get a degree\n";
    cout << "Enter your choice (0-17): ";
}

void choice(){                  //Συνάρτηση που λαμβάνει την επιλογή του χρήστη και εκτελεί τις αντίστοιχες εντολές
    int choice;
    UniSystem university;                                               //Ορίζω ενα αντικείμενο κλάσης UniSystem το οποίο θα διαχειρίζει όλα τα παρακάτω
    vector <Student> students = studentFin("Students.txt");             //Αποθηκέυω σε ενα vector students τους μαθητές του αρχείου Students.txt
    vector <Professor> professors = professorFin("Professors.txt");     //Αποθηκέυω σε ενα vector professors τους καθηγητές του αρχείου Professors.txt
    vector <Course> courses = courseFin("Courses.txt");                 //Αποθηκέυω σε ενα vector courses τα μαθήματα του αρχείου Courses.txt
    do {
        displayMenu();
        cin >> choice;
        cout<<endl;
        switch (choice) {
            case 1:
                for (auto i = 0; i < students.size(); i++){                          //Προσθέτω τoυς μαθητές
                    university.addStudent(students[i]);
                }
                university.printStudents();                                        //Τους εκτυπώνω
                cout<<endl;
                break;
            case 2:
                university.changeName(students[0], "Mike");                         //Αλλάζω τα περιεχόμενα τους
                university.changeSurname(students[0], "Feliz");
                university.changeAge(students[0], 28);
                cout<<"After changes:\n";
                university.printStudents();
                studentFout(students, "StudentsAfter.txt");                         //Εισάγω στο αρχείο StudentsAfter.txt τις αλλαγές
                cout<<endl;
                break;
            case 3:
                students = university.deleteStudent(students[1]);                   //Διαγράφω ένα μαθητή
                cout<<"After changes:\n";
                university.printStudents();
                studentFout(students, "StudentsAfter.txt");                         //Εισάγω στο αρχείο StudentsAfter.txt τις αλλαγές
                cout<<endl;
                break;
            case 4:
                for (auto i = 0; i < professors.size(); i++){                          //Προσθέτω τους professors
                    university.addProfessor(professors[i]);
                }
                university.printProfessors();
                cout<<endl;
                break;
            case 5:
                university.changeName(professors[0], "Jim");                           //Αλλάζω τα περιεχόμενα τους
                university.changeSurname(professors[0], "Dake");
                university.changeAge(professors[0], 45);
                cout<<"After changes:\n";
                university.printProfessors();
                professorFout(professors);                                          //Εισάγω στο αρχείο ProfessorsAfter.txt τις αλλαγές
                cout<<endl;
                break;
            case 6:
                professors = university.deleteProfessor(professors[1]);             //Διαγράφω εναν καθηγητή
                cout<<"After changes:\n";
                university.printProfessors();
                professorFout(professors);                                          //Εισάγω στο αρχείο ProfessorsAfter.txt τις αλλαγές
                cout<<endl;
                break;
            case 7:
                for (auto i = 0; i < courses.size(); i++){                          //Προσθέτω τα μαθήματα
                    university.addCourse(courses[i]);
                }
                university.printCourses();         
                cout<<endl;
                break;
            case 8:
                university.changeName(courses[1], "Python");                        //Αλλάζω τα περιεχόμενα τους
                university.changeEcts(courses[1], 10);  
                university.changeCompulsory(courses[1], false);
                cout<<"After changes:\n";
                university.printCourses();
                courseFout(courses);                                                //Εισάγω στο αρχείο CoursesAfter.txt τις αλλαγές
                cout<<endl;
                break;
            case 9:
                courses = university.deleteCourse(courses[0]);                      //Διαγράφω ενα μάθημα
                cout<<"After changes:\n";
                university.printCourses();
                courseFout(courses);                                                //Εισάγω στο αρχείο CoursesAfter.txt τις αλλαγές
                cout<<endl;
                break;
            case 10:
                university.enrollCourses(1, {courses[0], courses[1], courses[2], courses[3]});                      //Εγγράφω τα μαθήματα ανά εξάμηνο
                university.enrollCourses(3, {courses[4], courses[5], courses[6], courses[7], courses[8]});      
                university.printCoursesBySemester(1);                                                               //Τα εκτυπώνω ανα εξάμηνο
                university.printCoursesBySemester(2);
                university.printCoursesBySemester(3);
                cout<<endl;
                break;
            case 11:
                university.changeCourseSemester(courses[0], 1, 2);      //Αλλάζω το εξάμηνο ενώς μαθήματος. Στις παραμέτρους έχω το course , το εξάμηνο που ήταν και το εξάμηνο που θέλω να πάει
                university.printCoursesBySemester(1);                   //Τα εκτυπώνω ανα εξάμηνο
                university.printCoursesBySemester(2);
                university.printCoursesBySemester(3);
                cout<<endl;
                break;
            case 12:
                university.appointProfessors(courses[0], {professors[0], professors[1]});     //Εγγράφω τους καθηγητές ανά μάθημα
                university.appointProfessors(courses[1], {professors[1]});  
                university.appointProfessors(courses[2], {professors[0], professors[1]});
                university.appointProfessors(courses[3], {professors[0], professors[1]});
                university.appointProfessors(courses[4], {professors[0], professors[1]});
                university.appointProfessors(courses[5], {professors[0], professors[1]});
                university.appointProfessors(courses[6], {professors[0], professors[1]});
                university.appointProfessors(courses[7], {professors[0], professors[1]});
                university.appointProfessors(courses[8], {professors[0], professors[1]});
                university.printProfessorsByCourse(courses[0]);                                 //Τους εκτυπώνω ανα μάθημα
                cout<<endl;
                break;
            
            case 13:
                for(int i = 0; i < students.size(); i++){
                    university.enrollStudentInCourse(students[i], {courses[0], courses[1], courses[2], courses[3], courses[4], courses[5], courses[6], courses[7], courses[8]});    //Εγγράφω τους μαθητές σε μαθήματα
                }

                for(int i = 0; i < students.size(); i++){
                    university.printCoursesByStudent(students[i]);                      //Εκτυπώνω τα μαθήματα ανα μαθητή
                }
                cout<<endl;
                break;
            case 14:
                university.displayPassedStudents(courses[0], 2);                    //Εκτυπώνω τους μαθητές που πέρασαν ενα συγκεκριμένο μάθημα σε ένα συγκεκριμένο εξάμηνο και τους εισάγω και σε ενα αρχείο PassedStudents.txt
                cout<<endl;
                break;
            case 15:
                university.professorStatistics(professors[0], 3);                   //Εκτυπώνω τα statistics ενώς καθηγητή για ένα συγκεκριμένο εξάμηνο
                cout<<endl;
                break;
            case 16:
                for(int i = 0; i < students.size(); i++){
                    university.printStudentGradesInAllSemesters(students[i]);           //Εκτυπώνω τους βαθμούς ενώς μαθητή για όλα τα μαθήματα σε όλα τα εξάμηνα
                }
                cout<<endl;
                university.printStudentGradesBySemester(students[1], 1);            //Εκτυπώνω τους βαθμούς ενώς μαθητή για τα μαθήματα ενώς εξαμήνου
                university.printStudentGradesBySemester(students[1], 2);
                university.printStudentGradesBySemester(students[1], 3);
                cout<<endl;
                break;
            case 17:
                university.printElligibleForDegree();                               //Εκτυπώνω τους μαθητές που πληρούν τις απαιτήσεις για πτυχίο
                cout<<endl;
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 9.\n";
        }

    } while (choice != 0);


}

int main(){
    choice();
    return 0;
}



/* int main() {                            

    UniSystem university;                           //Ορίζω ενα αντικείμενο κλάσης UniSystem το οποίο θα διαχειρίζει όλα τα παρακάτω

    vector <Student> students = studentFin("Students.txt");             //Αποθηκέυω σε ενα vector students τους μαθητές του αρχείου Students.txt
    university.addStudent(students[0]);                                 //Προσθέτω τους μαθητές
    university.addStudent(students[1]);
    university.addStudent(students[2]);
    university.printStudents();                                         //Τους εκτυπώνω
    university.changeName(students[0], "Mike");                         //Αλλάζω τα περιεχόμενα τους
    university.changeSurname(students[0], "Feliz");
    university.changeAge(students[0], 28);
    cout<<"------"<<endl;
    students = university.deleteStudent(students[1]);                   //Διαγράφω ένα μαθητή
    university.printStudents();                                         //Τους εκτυπώνω
    studentFout(students, "StudentsAfter.txt");                         //Εισάγω στο αρχείο StudentsAfter.txt τις αλλαγές
    cout<<endl;

    vector <Professor> professors = professorFin("Professors.txt");     //Αποθηκέυω σε ενα vector professors τους καθηγητές του αρχείου Professors.txt
    university.addProfessor(professors[0]);                             //Προσθέτω τους καθηγητές
    university.addProfessor(professors[1]);
    university.addProfessor(professors[2]);
    university.printProfessors();                                       //Τους εκτυπώνω
    university.changeName(professors[0], "Jim");                        //Αλλάζω τα περιεχόμενα τους
    university.changeSurname(professors[0], "Dake");
    university.changeAge(professors[0], 45);
    cout<<"------"<<endl;
    professors = university.deleteProfessor(professors[1]);             //Διαγράφω έναν professor και εκτυπώνω τον ανανεομένο vector απο professors
    university.printProfessors();
    professorFout(professors);                                          //Εισάγω στο αρχείο ProfessorsAfter.txt τις αλλαγές
    cout<<endl;

    vector <Course> courses = courseFin("Courses.txt");                 //Αποθηκέυω σε ενα vector courses τα μαθήματα του αρχείου Courses.txt
    for (auto i = 0; i < courses.size(); i++){                          //Προσθέτω τα μαθήματα
        university.addCourse(courses[i]);
    }
     university.printCourses();                                         //Τα εκτυπώνω
    university.changeName(courses[1], "Python");                        //Αλλάζω τα περιεχόμενα τους
    university.changeEcts(courses[1], 10);  
    university.changeCompulsory(courses[1], false);
    cout<<"------"<<endl;
    courses = university.deleteCourse(courses[0]);                      //Διαγράφω ένα course και εκτυπώνω τον ανανεομένο vector απο courses
    university.printCourses();
    courseFout(courses);                                                //Εισάγω στο αρχείο CoursesAfter.txt τις αλλαγές
    cout<<endl;

    university.enrollCourses(1, {courses[0], courses[1], courses[2], courses[3]});                      //Εγγράφω τα μαθήματα ανά εξάμηνο
    university.enrollCourses(3, {courses[4], courses[5], courses[6], courses[7], courses[8]});      
    university.printCoursesBySemester(1);                                                               //Τα εκτυπώνω ανα εξάμηνο
    university.printCoursesBySemester(2);
    university.printCoursesBySemester(3);
    cout<<endl;

    university.changeCourseSemester(courses[0], 1, 2);      //Αλλάζω το εξάμηνο ενώς μαθήματος. Στις παραμέτρους έχω το course , το εξάμηνο που ήταν και το εξάμηνο που θέλω να πάει
    university.printCoursesBySemester(1);                   //Τα εκτυπώνω ανα εξάμηνο
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
    university.printProfessorsByCourse(courses[0]);                                 //Τους εκτυπώνω ανα μάθημα
    cout<<endl;

    university.enrollStudentInCourse(students[0], {courses[0], courses[1], courses[2], courses[3], courses[4], courses[5], courses[6], courses[7], courses[8]});    //Εγγράφω τους μαθητές σε μαθήματα
    university.enrollStudentInCourse(students[1], {courses[0], courses[1], courses[2], courses[3], courses[4], courses[5], courses[6], courses[7], courses[8]});
    university.printCoursesByStudent(students[0]);                      //Εκτυπώνω τα μαθήματα ανα μαθητή
    university.printCoursesByStudent(students[1]);
    cout<<endl;

    university.displayPassedStudents(courses[0], 2);                    //Εκτυπώνω τους μαθητές που πέρασαν ενα συγκεκριμένο μάθημα σε ένα συγκεκριμένο εξάμηνο και τους εισάγω και σε ενα αρχείο PassedStudents.txt
    cout<<endl;

    university.professorStatistics(professors[0], 3);                   //Εκτυπώνω τα statistics ενώς καθηγητή για ένα συγκεκριμένο εξάμηνο
    cout<<endl;

    university.printStudentGradesInAllSemesters(students[0]);           //Εκτυπώνω τους βαθμούς ενώς μαθητή για όλα τα μαθήματα σε όλα τα εξάμηνα
    university.printStudentGradesInAllSemesters(students[1]);
    cout<<endl;

    university.printStudentGradesBySemester(students[1], 1);            //Εκτυπώνω τους βαθμούς ενώς μαθητή για τα μαθήματα ενώς εξαμήνου
    university.printStudentGradesBySemester(students[1], 2);
    university.printStudentGradesBySemester(students[1], 3);
    cout<<endl;

    university.printElligibleForDegree();                               //Εκτυπώνω τους μαθητές που πληρούν τις απαιτήσεις για πτυχίο
    return 0;
} */