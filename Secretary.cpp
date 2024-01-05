#include <vector>
#include <iostream>
#include <string>
#include "Secretary.h"
using namespace std;


        Secretary::Secretary(){                             //Ο constructor της secretary
            cout<<"Secretary constructed"<<endl;            //Εκτπώνω οτι κατασκευάστηκε
        }

        Secretary::Secretary(const Secretary& other){        //O copy constructor της secretary
            for(auto i = 0; i < other.people.size(); i++){   //Αντιγράφω όλα τα περιεχόμενα του other.people στο people
                Person* p = other.people[i];
                people.push_back(new Person(*p)); 
            }
        }

        Secretary::~Secretary(){                        //Ο destructor της secretary
            for(auto i = 0; i < people.size(); i++){    //Απελευθερώνω ολα τα περιεχόμενα του people δηλαδή τους pointers σε person που δέσμευσα
                delete people[i];
            }
            cout<<"Secretary destructed"<<endl;         //Εκτυπωνω οτι καταστράφηκε
        }

        Secretary& Secretary::operator+=(Person* p){       //Υπερφορτωση του +=
            people.push_back(p);
            return *this;
        }

        void Secretary::printAll(){                //Συνάρτηση που εκτυπώνει ολα τα στοιχεία της secretary
            for (auto it = people.begin(); it!=people.end();it++){
                cout<<*it;
            }
        }

        void Secretary::findPerson(string name){           //Συνάρτηση που βρίσκει αν υπάρχει ενας person με βάση το όνομα του
            for (auto i = 0; i < people.size(); i++) {
                if (people[i]->getName() == name) {
                    cout<<people[i]->getName()<<" Found"<<endl;
                    return;
                }
            }
            cout<<name<<" not found"<<endl;
            return;
        }

        Secretary& Secretary::operator=(const Secretary& s) {
            for(auto it = s.people.begin(); it != s.people.end(); it++){
                Person* p = new Person();
                p = *it;
                people.push_back(new Person(*p));
            }
            return *this;
        }

        Secretary& Secretary::operator+(Person* p){    //Υπερφόρτωση του +
            people.push_back(new Person(*p));
            return *this;
        }

        ostream& operator<<(ostream& os, Secretary& s){     //Friend συνάρτηση υπερφόρτωσης του τελεστή << για έξοδο
            for(auto i = 0; i < s.people.size();i++){
                os << s.people[i];
            }
            return os;
        }

        istream& operator>>(istream& is, Secretary& s){      //Friend συνάρτηση υπερφόρτωσης του τελεστή >> για είσοδο
            Person* p = new Person();
            is >> p;
            s.people.push_back(p);
            return is;
        }