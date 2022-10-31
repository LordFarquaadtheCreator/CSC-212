#include <iostream>
#include <cmath>
using namespace std;

/*
A Date class is described by month(m), day(d), year(y). An Employee is described by a unique 
data structure having a name (e.g. “George”), salary(75000.25) and date_of_birth (06, 10, 1998). 
Calculate the number of days between his day of birth and (09, 20, 2022). Assume that the Employee object contains a Date sub-object)
*/



class Date{
    public:
    int month = 9;
    int day = 29;
    int year = 2022;
};

class Employee : public Date{
    
    int daysLived (int bmonth, int bday, int byear){
        int i =1;
        int daysLived = day;

        while (month > i){ //finds days lived up till current month
            if (i == 4 || i == 6 || i == 9 || i == 11){
                daysLived += 30;
            }
            else if (i == 2){
                daysLived += 28;
            }
            else{
                daysLived += 31;
            }
            i++;
        } // correctly adds how many days passed since beginning of year

        if (bmonth == 4 || bmonth == 6 || bmonth == 9 || bmonth == 11){ // days from birth to end of month
            daysLived += 30 - bday;
        }
        else if (bmonth == 2){
            daysLived += 28 - bday;
        }
        else{
            daysLived += 31 - bday;
        } // works
        
        i = 12;
        while (bmonth < i){ // days lived from month till end of year (dec 31)
            if (i == 4 || i == 6 || i == 9 || i == 11){
                daysLived += 30;
            }
            else if (i == 2){
                daysLived += 28;
            }
            else{
                daysLived += 31;
            }
            i--;
        }
        
        
        i = byear; 
        while (i < year){ // adds days from leap years
            if (i % 4 == 0){
                daysLived += 1;
            }
            i++;
        }

        return daysLived += (year-byear-1)*365; // adds years inbetween
    } // daysLived function 

    public:
    string name;
    int salary;
    int monthDays;

    Employee(){}
    ~Employee(){}

    Employee(int month, int day, int year){
        cout << "Number of days lived from birth: " << daysLived(month, day, year) << " days" << endl;
    }

    void date_of_birth(){
        printf("\n%i, %i, %i", month, day, year); // date inhertied from class Date
    }

};


int main (){

    string name = "Fahad Faruqi";
    cout << endl << "==================================================================================\n";
    cout << " " << name << "\t File: " << __FILE__ << "\t Date: " << __DATE__<< "\tCSC 21200 LM24126" << endl;
    cout << "==================================================================================\n" << endl;

    Employee davie(6,10,1998);
}