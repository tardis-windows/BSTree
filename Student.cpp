#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include "Node.h"
#include "NodeBag.h"
#include "BST.h"
#include "Student.h"


using namespace std;
static const char pool[]=
"abcdefghijklmnopqrstuvwxyz";

Student::Student()
{
     studentName();
     studentSSID();
}

void Student::SetSSID(string valSSID){
    SSID = valSSID;
    }

void Student::SetName(string valFname, string valLname)
{
    fname = valFname;
    lname = valLname;
}

int uniform(const int a, const int b) { // returns [a, b].
    assert(a <= b); return a + rand()%(b-a+1);
			}

			/*
			 (c) Copyright 1994, Everett F. Carter Jr., modified by Akira Kawaguchi.
			  Permission is granted by the author to use this software for
			  any application provided this copyright notice is preserved.
			*/

void Student::studentSSID(){
    char ssid[12];

    for(int i = 0; i < 12; i++){
        ssid[i]='\0';
    }

    int a, x = 0;
    for(x = 0; x < 11; x++){
        if(x == 3 || x == 6){
            ssid[x]='-';
        }
        else{
            a = uniform(0,9);
            ssid[x] = a + '0';
        }
    }
        ssid[x]='\0';
        SetSSID(ssid);
}

char getRandom(){
        return pool[uniform(0,25)];
    }

void Student::studentName(){
        randomName();
    }

void Student::randomName(){
    char fname[15];
    char lname[15];

        for(int i=0;i<15;i++){
            fname[i]='\0';
            lname[i]='\0';
            }

    int pos=0, pos2=0;
    int len = uniform(3,12);
        for (pos=0; pos < len-1; pos++){
            if(pos==0){
            fname[pos]=toupper(getRandom());
            }
            else{
                fname[pos]=getRandom();
            }
        }

        fname[pos]='\0';

        int leng = uniform(3,12);
            for (pos2=0; pos2 < leng-1; pos2++){
                if(pos2==0){
                lname[pos2]=toupper(getRandom());
                }
                else{
                lname[pos2]=getRandom();
            }
        }
        lname[pos2]='\0';
        SetName(fname, lname);

}

//friend function overloaded ==
bool operator==(const Student& lhs, const Student& rhs){

        return (lhs.SSID==rhs.SSID) && (lhs.fname==rhs.fname) && (lhs.lname==rhs.lname);
}

//friend function overloaded !=
bool operator!=(const Student& lhs, const Student& rhs){
 if(lhs!=rhs)
        return true;
        else{
            return false;
        }
}

ostream& operator<<(ostream& outs, const Student& source){

    outs << source.fname << " " << source.lname << endl;
    outs << source.SSID;
    outs << endl;

    return outs;
}

bool operator<(const Student& lhs, const Student& rhs){
    return lhs.SSID < rhs.SSID;
}

bool operator>(const Student& lhs, const Student& rhs){
    return lhs.SSID > rhs.SSID;
}





