#include <iostream>
#include <string>
#include "Person.h"

int count = 0;

using namespace std;

    Person::Person(int ag, string nam, string sur): age(ag), name(nam), surname(sur){         //O constructor του Person όταν του δίνω δεδομένα
        cout << "Person Constructed" <<endl;                                       //Εκτυπωνω οτι φτιαχτηκε αντικειμενο
        count++;                                                            //Αυξανω το count με τα αντικειμενα που εχω φτιαξει
    }

    Person::Person(): age(0), surname(""), name(""){            //Ο constructor του Person όταν δεν του δίνω δεδομένα
        cout << "Person Constructed" <<endl;                                       //Εκτυπωνω οτι φτιαχτηκε αντικειμενο
        count++;                                                            //Αυξανω το count με τα αντικειμενα που εχω φτιαξει
    }

    Person::~Person() {                                                      //Αυτος εδω ειναι ο destructor και καλειται οταν καταστρεφεται το αντικειμενο δηλαδη στο τελος του προγραμματος
        //cout << "Person Destructed" <<endl;                                        //Εκτυπωνω οτι καταστράφηκε
        count--;                                                            //Μειωνω το count
    }

    string Person::getName(){                           //Συνάρτηση που παίρνω το όνομα όταν την καλέσω 
        return name;
    }

    string Person::getSurname(){                        //Συνάρτηση που παίρνω το επίθετω όταν την καλέσω
        return surname;
    }



    int Person::getAge(){                               //Συνάρτηση που παίρνω την ηλικία όταν την καλέσω
        return age;
    }

    void Person::setName(string nam){                   //Συνάρτηση που κάνω set το όνομα όταν την καλέσω
        name = nam;
    }

    void Person::setSurname(string sur){                //Συνάρτηση που κάνω set το επίθετο όταν την καλέσω
        surname = sur;
    }

    void Person::setAge(int ag){                        //Συνάρτηση που κάνω set την ηλικία όταν την καλέσω
        age = ag;
    }

    ostream& operator<<(ostream& os, const Person* a){              //Friend συνάρτηση υπερφόρτωσης του τελεστή << για έξοδο
        os<< "Name: "<<a->name<<" / "<<"Surname: "<<a->surname<<" / "<<" / "<<"Age: "<<a->age<<endl;
        return os;
    }
    
    istream& operator>>(istream& is,  Person* a){                    //Friend συνάρτηση υπερφόρτωσης του τελεστή >> για είσοδο
        cout<<"Give Name: ";
        is>>a->name;
        cout<<"Give Surname: ";
        is>>a->surname;
        cout<<"Give Age: ";
        is>>a->age;
        return is;
    }

    ostream& operator<<(ostream& os, Person& a){        //Friend συνάρτηση υπερφόρτωσης του τελεστή << για έξοδο και καλείται οταν του δίνω person;
            os<< "Name: "<<a.name<<" / "<<"Surname: "<<a.surname<<" / "<<"Age: "<<a.age<<endl;
            return os;
        }

    istream& operator>>(istream& is, Person& a){        //Friend συνάρτηση υπερφόρτωσης του τελεστή >> για είσοδο και καλείται οταν του δίνω person;
            cout<<"Give name, surname, age"<<endl;
            is>>a.name >>a.surname>>a.age;
            return is;
        }