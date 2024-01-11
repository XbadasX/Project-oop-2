#include <string>
using namespace std;
class Person {                  //Κλαση person
    string name;                //Ως private μέλη έχουμε όνομα, επίθετο και ηλικία. Βάζοντας τα private επιτυγχάνω την αρχή της ενθυλάκωσης
    string surname;
    int age;    
public:
    Person(int ag, string nam, string sur);      //O constructor του Person όταν του δίνω δεδομένα
    Person();                                                //Ο constructor του Person όταν δεν του δίνω δεδομένα

    ~Person();                                               //O destructor του Person

    string getName();                                        //Συνάρτηση που παίρνω το όνομα όταν την καλέσω

    string getSurname();                                     //Συνάρτηση που παίρνω το επίθετο όταν την καλέσω

    int getAge();                                            //Συνάρτηση που παίρνω την ηλικία όταν την καλέσω

    void setName(string nam);                                //Συνάρτηση που κάνω set το όνομα όταν την καλέσω

    void setSurname(string sur);                             //Συνάρτηση που κάνω set το επίθετο όταν την καλέσω

    void setAge(int ag);                                     //Συνάρτηση που κάνω set την ηλικία όταν την καλέσω

    virtual void print();                                            //Συνάρτηση που εκτυπώνω τα στοιχεία ενός person

    friend ostream& operator<<(ostream& os, const Person* a);       //Friend συνάρτηση υπερφόρτωσης του τελεστή << για έξοδο και καλείται οταν του δίνω pointer σε person;
    
    friend istream& operator>>(istream& is,  Person* a);            //Friend συνάρτηση υπερφόρτωσης του τελεστή >> για είσοδο και καλείται οταν του δίνω pointer σε person;

    friend ostream& operator<<(ostream& os, Person& a);             //Friend συνάρτηση υπερφόρτωσης του τελεστή << για έξοδο και καλείται οταν του δίνω person;

    friend istream& operator>>(istream& is, Person& a);             //Friend συνάρτηση υπερφόρτωσης του τελεστή >> για είσοδο και καλείται οταν του δίνω person;
};

class Student: public Person{                                   //Κλάση student που κληρονομέι την person
        int studentId, studentYear;                             //Ως private στοιχεία προσθέτω το Id και χρονιά φοίτησης
    public:
        Student(int ag, string nam, string sur, int year, int id) : Person(ag, nam, sur), studentYear(year), studentId(id) {}  //Constructor της student

        void print() {                                          //Εκτυπώνω τα περιεχόμενα ενώς student
            Person::print();
            cout <<", Year Of Study: "<< studentYear<< ", Student ID: " << studentId << endl;
        }

        int getStudentId(){                                     //Getters για id και χρονιά φοίτησης
            return studentId;
        }

        int getStudentYear(){
            return studentYear;
        }
};

class Professor: public Person{                                 //Κλάση professor που κληρονομέι την person
    private:
        int professorId;                                        //Ως private στοιχεία προσθέτω το Id
    public:
        Professor(int ag, string nam, string sur, int id) : Person(ag, nam, sur), professorId(id) {}

        void print() {                                          //Εκτυπώνω τα περιεχόμενα ενώς professor
            Person::print();
            cout << ", Professor ID: " << professorId << endl;
        }

        int getProfessorId(){                                   //Getter για id
            return professorId;
        }
};