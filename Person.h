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

    string getSurname();                                     //Συνάρτηση που παίρνω το επίθετω όταν την καλέσω

    int getAge();                                            //Συνάρτηση που παίρνω την ηλικία όταν την καλέσω

    void setName(string nam);

    void setSurname(string sur);

    void setAge(int ag);

    virtual void print();                                            //Συνάρτηση που εκτυπώνω τα στοιχεία ενός person

    friend ostream& operator<<(ostream& os, const Person* a);       //Friend συνάρτηση υπερφόρτωσης του τελεστή << για έξοδο και καλείται οταν του δίνω pointer σε person;
    
    friend istream& operator>>(istream& is,  Person* a);            //Friend συνάρτηση υπερφόρτωσης του τελεστή >> για είσοδο και καλείται οταν του δίνω pointer σε person;

    friend ostream& operator<<(ostream& os, Person& a);             //Friend συνάρτηση υπερφόρτωσης του τελεστή << για έξοδο και καλείται οταν του δίνω person;

    friend istream& operator>>(istream& is, Person& a);             //Friend συνάρτηση υπερφόρτωσης του τελεστή >> για είσοδο και καλείται οταν του δίνω person;
};

class Student: public Person{
        int studentId, studentYear;
    public:
        Student(int ag, string nam, string sur, int year, int id) : Person(ag, nam, sur), studentYear(year), studentId(id) {}

        void print() {
            Person::print();
            cout <<", Year Of Study: "<< studentYear<< ", Student ID: " << studentId << endl;
        }

        int getStudentId(){
            return studentId;
        }

        int getStudentYear(){
            return studentYear;
        }
};

class Professor: public Person{
    private:
        int professorId;
    public:
        Professor(int ag, string nam, string sur, int id) : Person(ag, nam, sur), professorId(id) {}

        void print() {
            Person::print();
            cout << ", Professor ID: " << professorId << endl;
        }

        int getProfessorId(){
            return professorId;
        }
};