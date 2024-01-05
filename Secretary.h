#include <string>
#include <vector>
#include "Person.cpp"

class Secretary{
    vector <Person*> people;      //Ορίζω ως private ενα vector που περιέχει δείκτες που δείχνουν σε ανικείμενα Person
    public:
        Secretary();              //Ο constructor της secretary

        Secretary(const Secretary& other);      //O copy constructor της secretary

        ~Secretary();             //Ο destructor της secretary

        void printAll();          //Συνάρτηση που εκτυπώνει ολα τα στοιχεία της secretary

        void findPerson(string name);       //Συνάρτηση που βρίσκει αν υπάρχει ενας person με βάση το όνομα του

        Secretary& operator+=(Person* p);       //Υπερφόρτωση του τελεστη +=
           
        Secretary& operator=(const Secretary& newS);       //Υπερφόρτωση του τελεστή =

        Secretary& operator+(Person* p);     //Υπερφόρτωση του τελεστή +

        friend istream& operator>>(istream& is, Secretary& s);       //Friend συνάρτηση υπερφόρτωσης του τελεστή << για έξοδο

        friend ostream& operator<<(ostream& os, Secretary& s);       //Friend συνάρτηση υπερφόρτωσης του τελεστή >> για είσοδο
      
};