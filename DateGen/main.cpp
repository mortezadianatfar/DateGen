#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// define struct Date to collect information for Date
struct  Date {
    int day;                // variable to collect day
    int month;              // variable to collect month
    int year;               // variable to collect year
}; // end of struct Date

void inputDate(Date &);       // prototype of inputDate function
void checkYear(Date &);     // prototype of checkYear function
void checkMonth(Date &);    // prototype of checkMonth function
void checkDay(Date &);      // prototype of checkDay function
void increment(Date &);     // prototype of increment function
void outputDate(Date &);    // prototype of outputDate function

// main function
int main()
{
    Date time;          // intialiaze our struct
    inputDate(time);    // Ask use to input a date
    outputDate(time);   // print 7 date after the user date input
    
}// end of main function
//  inputDate function to get date from user and store it in Date struct
void inputDate(Date &date)
{
    cout<<" Enter Your Date as following order :"<<endl;
    cout<< " Enter the Year(Years start from 1754) : ";
    cin>>date.year;
    checkYear(date);
    cout<<" Enter the Month : " ;
    cin>>date.month;
    checkMonth(date);
    cout<< " Enter the Day : ";
    cin>>date.day;
    checkDay(date);
    cout<< " Your Given Date is : "<<date.day<<" "<<date.month<<" "<<date.year<<endl;
}// end function inputDate

// checkYear Function to check year value to be correct and ask user for correct value if it is uncorrect
void checkYear(Date &date)
{
    while (date.year<1754) {
        cout<< " You pick wrong Year!(It should be greater than 1754)Please Enter new Year Value : ";
        cin>>date.year;
    }
}// End checkYear function

// checkMonth Function to check month value to be correct and ask user for correct value if it is uncorrect
void checkMonth(Date &date)
{
    while (date.month>12 or date.month<1) {
        cout<< " You pick wrong Month!(You should pick months between 1-12) Please Enter new Month Value : ";
        cin>>date.month;
    }
}//End function checkMonth

//checkDay Function to check day value to be correct and ask user for correct value if it is uncorrect
void checkDay(Date &date)
{
switch (date.month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12 :
            while (date.day>31 or date.day<1) {
                cout<< " You pick wrong Day!(It should be in 1- 31 range) Please Enter new Day Value : ";
                cin>>date.day;
            }
            break;
        case 4: case 6: case 9: case 11:
            while (date.day>30 or date.day<1) {
                cout<< " You pick wrong Day!(It should be in 1- 30 range) Please Enter new Day Value : ";
                cin>>date.day;
            }
            break;
        case 2 :
        if ((date.year % 4 ==0 and date.year%100 !=0) or date.year%400==0  ){
                    if (date.day>29 or date.day<1) {
                        cout<< " You pick wrong Day!(It should be in 1- 29 range) Please Enter new Day Value : ";
                        cin>>date.day;
                    }
            }else{
                while (date.day>28 or date.day<1) {
                    cout<< " You pick wrong Day!(It should be in 1- 28 range) Please Enter new Day Value : ";
                    cin>>date.day;
                }
            }
            break;

        default:
        cout<<" The program should not get into this code"<<endl;
            break;
    }
}// End checkDay function

// increment Function to calculate increment days respect to the user input
void increment(Date &date)
{
    date.day= date.day + 1;
    switch (date.month) {
            case 1: case 3: case 5: case 7: case 8: case 10:
            
            if (date.day > 31)
            {
                date.month++;
                date.day= date.day- 31;
            }
            break;
            
            case 4: case 6: case 9: case 11:
            
            if (date.day > 30)
            {
                date.month++;
                date.day= date.day- 30;
            }
            break;

            case 2:
            if ((date.year % 4 ==0 and date.year%100 !=0) or date.year%400==0  ){
                if (date.day > 29){
                        date.month++;
                        date.day = date.day - 29;
                    }
            }else {
                if (date.day > 28){
                date.month++;
                date.day = date.day - 28;
                }
            }
            break;

            case 12 :
            
             if (date.day > 31)
            {
                date.month = date.month - 11;;
                date.year++;
                date.day = date.day - 31;
            }
            break;
            
            default:
            cout<<"Program should not get into this error in increment Function!!!"<<endl;
            break;
        }
} // end increment Function

// outputDate function which use increment function and print 7 days date
void outputDate(Date &date)
{
    for (int i = 0; i < 7; i++)
    {
        cout<<setfill('0');
        cout<<setw(2)<<date.day<<"."<<setw(2)<<date.month<<"."<<setw(4)<<date.year<<endl;
        increment(date);
    }
} // end of outputDate function
