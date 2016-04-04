#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// define struct Date to collect information for Date
struct  Date {
    int day;                // variable to collect day
    int month;              // variable to collect month
    int year;               // variable to collect year
    int weekday;            // variable to store weekday value
    string event;           // string to hold events
    int last;
    
};
struct Event{
    int day;
    int month;
    int year;
    int weekday;
    string event;
};


void inputDate(Date &);     // prototype of inputDate function
void checkYear(Date &);     // prototype of checkYear function
void checkMonth(Date &);    // prototype of checkMonth function
void checkDay(Date &);      // prototype of checkDay function
void checkLast(Date &);     // prototype of checkLast function
void increment(Date &);     // prototype of increment function
void setWeekDay(Date &);    // prototype of setWeekDay function
void setEvent(Date &,Event[]);      // prototype of setEvent function
void outputDate(Date &);    // prototype of outputDate function

// main function
int main()
{
    Date time;                          // intialiaze our struct
    inputDate(time);                    // Ask from user to input a date
    Event  MyHappenings[] =
    {
        { -1, 0, 0, 0, "Payday" },
        { 1, 3, 0, 0, "Birthday Party" },
        { 0, 0, 0, 5, "Darts evening" },
        {13, 0, 0, 5, "Friday the 13th" },
      //  {2,3,0,0,"Hooooraaa another event"}, // You can add other events too here," no limits "
    };                                      // Initialize the events,
    
    
    for (int i = 0; i < 7; i++)
    {
        setWeekDay(time);               // Calculate the weekday of a date
        checkLast(time);                // check that if a date is the last date of the month or not
        setEvent(time,MyHappenings);    // compare the date and events, and set events related to that date
        outputDate(time);               // print date with weekdays and events
        increment(time);                // increment a date by one day
    }
    
    
}// end of main function

//  inputDate function to get date from user and store it in Date struct
void inputDate(Date &date)
{
    
    cout<<" Enter Your Date (Year starts from 1754) and Follow this format by space DD MM YYYY :"<<endl;
    cin>>date.day>>date.month>>date.year;
    checkYear(date);
    checkMonth(date);
    checkDay(date);
    cout<< " Your Given Date is : "<<date.day<<" "<<date.month<<" "<<date.year<<endl;
}// end function inputDate

// checkYear Function to check year value to be correct and ask user for correct value if it is uncorrect
void checkYear(Date &date)
{
    while (date.year<1754 or date.year>9999) {
        cout<< " You pick wrong Year!(It should be between 1754 and 9999)Please Enter new Year Value : ";
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

// checkLast funtion to find if a date is last day of the month or not
void checkLast(Date &date)
{
    date.last = 0;
    switch (date.month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12 :
            if (date.day ==31)
                date.last=-1;
            break;
        case 4: case 6: case 9: case 11:
            if (date.day ==30)
                date.last=-1;
            break;
        case 2 :
            if ((date.year % 4 ==0 and date.year%100 !=0) or date.year%400==0  ){
                if (date.day ==29)
                    date.last=-1;
            }else{
                if (date.day ==28)
                    date.last=-1;
            }
            break;
            
        default:
            cout<<" The program should not get into this code"<<endl;
            break;
    }
}// End checkLast function

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

//setWeekDay function to calculate weekday
void setWeekDay(Date &date){
    // find the algorithm here "https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week"
    int a = (14-date.month)/12;
    int y = date.year-a;
    int m = date.month+12*a-2;
    date.weekday = (date.day + y + y/4 - y/100 + y/400 +(31 * m/12)) % 7;
}// end setWeekDay function

//setEvent function to set events related to their related events
void setEvent(Date &date,Event event[]){
    date.event = "-";
    string a;
    for(int i=0 ; i<sizeof(event); i++){
        if((date.day==event[i].day or event[i].day == 0 or event[i].day == date.last) and (date.month==event[i].month or event[i].month == 0) and (date.year==event[i].year or event[i].year == 0) and (date.weekday==event[i].weekday or event[i].weekday == 0)){
            if(a.empty()){
                date.event = event[i].event;
                a = date.event;
                continue;
            }else{
                date.event = event[i].event+","+ a;
                a = date.event;
                continue;
            }
        }
    }
} // end of setEvent function

// outputDate function which use increment function to increment a date and also set event related to input date
void outputDate(Date &date)
{
    string Day[7] = { "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    cout<<setfill('0');
    cout<<setw(2)<<date.day<<"."<<setw(2)<<date.month<<"."<<setw(4)<<date.year<<"      "<<"[ "<<Day[date.weekday]<<" ]"<<"     "<<date.event<<endl;
} // end of outputDate function



