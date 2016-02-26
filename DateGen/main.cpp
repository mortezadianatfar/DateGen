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
    cout<< " Enter the Year(Years start from 1754) : "; //  ask user to type year
    cin>>date.year;                                     //  store Year in object
    checkYear(date);                                    //   check the Year value
    cout<<" Enter the Month : " ;                       //    ask user to type month
    cin>>date.month;                                    // store Month in object
    checkMonth(date);                                   // check the Month value
    cout<< " Enter the Day : ";                         //   ask user to type day
    cin>>date.day;                                      //store Day in object
    checkDay(date);                                     //   check the Day value
    cout<< " Your Given Date is : "<<date.day<<" "<<date.month<<" "<<date.year<<endl; // print out the date that user input
}// end function inputDate

// checkYear Function to check year value to be correct and ask user for correct value if it is uncorrect
void checkYear(Date &date)
{
    while (date.year<1754) {    // till user input year less than 1754 do this operation
        cout<< " You pick wrong Year!(It should be greater than 1754)Please Enter new Year Value : ";  // ask user to type correct year
        cin>>date.year;         // store new value in our construct obj
    }
}// End checkYear function

// checkMonth Function to check month value to be correct and ask user for correct value if it is uncorrect
void checkMonth(Date &date)
{
    while (date.month>12 or date.month<1) {             // till user input month value out of range do follow operation
        cout<< " You pick wrong Month!(You should pick months between 1-12) Please Enter new Month Value : ";  // ask user to input correct month value
        cin>>date.month;                                // store new value in struct obj
    }
}//End function checkMonth

//checkDay Function to check day value to be correct and ask user for correct value if it is uncorrect
void checkDay(Date &date)
{
switch (date.month) { // take month object as statement for switch operation
        case 1: case 3: case 5: case 7: case 8: case 10: case 12 :                                          // cases which the months are 31 days.
            while (date.day>31 or date.day<1) {                                                             // do the operation until user put day in out of rane 1-31
                cout<< " You pick wrong Day!(It should be in 1- 31 range) Please Enter new Day Value : ";   // print out error for user that input wrong value
                cin>>date.day;                                                                              // store new value to object
            }
            break;
        case 4: case 6: case 9: case 11:                                                                    // cases which the months are 30 days.
            while (date.day>30 or date.day<1) {                                                             // do the operation until user put day in out of rane 1-30
                cout<< " You pick wrong Day!(It should be in 1- 30 range) Please Enter new Day Value : ";   // print out error for user that input wrong value
                cin>>date.day;                                                                              // store new value to object
            }
            break;
        case 2 :                                                                                            // case for second month which can be 28 or 29 days regard to leap year
            if (date.year %4==0) {                                                                          // if it is leap year
                if (date.day>29 or date.day<1) {                                                            // do the operation until user put day in out of rane 1-29
                    cout<< " You pick wrong Day!(It should be in 1- 29 range) Please Enter new Day Value : "; // print out error for user that input wrong value
                    cin>>date.day;                                                                          // store new value to object
                }
            }else{                                                                                          // if it is "NOT" leap year
                while (date.day>28 or date.day<1) {                                                         // do the operation until user put day in out of rane 1-28
                    cout<< " You pick wrong Day!(It should be in 1- 28 range) Please Enter new Day Value : "; // print out error for user that input wrong value
                    cin>>date.day;                                                                          // store new value to object
                }
            }
            break;

        default:                                                                                            // program should not get into this default,if it gets into it, it means that we have mistakes on correcting month value
        cout<<" The program should not get into this code"<<endl;
            break;
    }
}// End checkDay function

// increment Function to calculate increment days respect to the user input
void increment(Date &date)
{
    date.day= date.day + 1;                                                   // as we correct all of day value before, we can add "one" to day value
    switch (date.month) {
            case 1: case 3: case 5: case 7: case 8: case 10:                // cases for month is 31 days
            
            if (date.day > 31)                                              // if added value makes the day value greater than 31 it gets into next month
            {
                date.month++;                                               // add "one" to month value
                date.day= date.day- 31;                                     // calculate differences between new day value and last one,because we jump into next month
            }
            break;
            
            case 4: case 6: case 9: case 11:                                // cases for month is 30 days
            
            if (date.day > 30)                                              // if added value makes the day value greater than 30 it gets into next month
            {
                date.month++;                                               // add "one" to month value
                date.day= date.day- 30;                                     // calculate differences between new day value and last one,because we jump into next month
            }
            break;

            case 2:                                                         // case for second month which can be 28 or 29 days regards to be leap year
            if (date.year % 4 ==0 ) {                                        // check that if the year is leap year
                if (date.day > 29){                                          // if added value makes the day value greater than 29 it gets into next month
                date.month++;                                               // add "one" to month value
                date.day = date.day - 29;                                   // calculate differences between new day value and last one,because we jump into next month
                }
            } else if (date.day > 28)                                         // if it is "NOT" leap year
            {
                date.month++;                                           // add "one" to month value
                date.day = date.day - 28;                               // calculate differences between new day value and last one,because we jump into next month
            }
            
            break;

            case 12 :                                                       // in case when we are in the last day of the year
            
             if (date.day > 31)                                             // if added value makes the day value greater than 31 it gets into next month
            {
                date.month = date.month - 11;;                              // make month value back to the first month
                date.year++;                                                // add "one" value to the year value
                date.day = date.day - 31;                                   // calculate differences between new day value and last one,because we jump into next month
            }
            break;
            
            default:                                        // program should not make to this default value,unless we have issue with month object value
            cout<<"Program should not get into this error in increment Function!!!"<<endl;
            break;
        }
} // end increment Function

// outputDate function which use increment function and print 7 days date
void outputDate(Date &date)
{
    for (int i = 0; i < 7; i++)                     // loop for 7 days
    {
        increment(date);                            // calculate increment
        cout<<setfill('0');
        cout<<setw(2)<<date.day<<"."<<setw(2)<<date.month<<"."<<setw(4)<<date.year<<endl; // print the Date
    }
} // end of outputDate function
