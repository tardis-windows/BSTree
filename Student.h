#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>


using namespace std;

class Student
{
    public:
        // CONSTRUCTOR
        Student();

        // SETTERS AND GETTERS MEMBER FUNCTIONS
        void SetSSID(string valSSID);
        string GetSSID()const {return SSID;};

        void SetName(string valFname, string valLname);
        string GetFname(){return fname;};
        string GetLname(){return lname;};

        void studentSSID();
        void studentName();
        void randomName();

        //friend functions created to make the bag run
        friend bool operator==(const Student& lhs, const Student& rhs);
        friend bool operator!=(const Student& lhs, const Student& rhs);
        friend bool operator<(const Student& lhs, const Student& rhs);
        friend bool operator>(const Student& lhs, const Student& rhs);
        friend ostream& operator<<(ostream&, const Student&);

        //PRIVATE MEMBER VARIABLES
    private:
        string SSID;
        string fname;
        string lname;
};

#endif // STUDENT_H
