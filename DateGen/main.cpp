#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// define struct Date to collect information for Date
struct  Date {
    int day;                // variable to collect day
    int month;              // variable to collect month
    int year;               // variable to collect year
};
// define struct WeekDay to set information need to make WeekDay
struct WeekDay {
    int monthValue;
    int dayValue;
    int centuryValue;
    string weekValue;
};

void inputDate(Date &);       // prototype of inputDate function
void checkYear(Date &);     // prototype of checkYear function
void checkMonth(Date &);    // prototype of checkMonth function
void checkDay(Date &);      // prototype of checkDay function
void increment(Date &);     // prototype of increment function
void outputDate(Date &,WeekDay &);    // prototype of outputDate function

// define struct WeekDay to Find and set Weekdays

int setCenturyValue(Date , WeekDay &);
void setMonthValue(Date,WeekDay &);
void setDayValue(Date,WeekDay &);
string setWeekDay(Date,WeekDay &);

// main function
int main()
{
    Date time;          // intialiaze our struct
    inputDate(time);
    WeekDay week;// Ask use to input a date
    outputDate(time,week);   // print 7 date after the user date input
    


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
void outputDate(Date &date,WeekDay &weekday)
{
    for (int i = 0; i < 7; i++)
    {
        setWeekDay(date, weekday);
        cout<<setfill('0');
        cout<<setw(2)<<date.day<<"."<<setw(2)<<date.month<<"."<<setw(4)<<date.year<<setw(4)<<"      "<<weekday.weekValue<<endl;
        increment(date);
    }
} // end of outputDate function

int setCenturyValue(Date date,WeekDay &weekday){
    int x = date.year /100;
    int diff = 0;
    int diff2 = 0;
    for (int i=1; 4*i<= x; ++i)
        diff = x - 4*i;
    for (int j=1; 7*j<=diff*5; ++j) {
        diff2= (diff*5)-7*j;
    }
    weekday.centuryValue = diff2;
    return weekday.centuryValue;
}
void setMonthValue(Date date, WeekDay &weekday){
    switch (date.month) {
        case 1: case 10:
            weekday.monthValue=0;
            break;
        case 2: case 3: case 11:
            weekday.monthValue = 3;
            break;
        case 4: case 7:
            weekday.monthValue=6;
            break;
            
        case 5:
            weekday.monthValue=1;
            break;
            
        case 6:
            weekday.monthValue=4;
            break;
            
        case 8:
            weekday.monthValue=2;
            break;
            
        case 9: case 12:
            weekday.monthValue=5;
            break;
        default:
            cout<<"Program should not come to this point at seting monthValue";
            break;
    }
}
void setDayValue(Date date, WeekDay &weekday){
    switch (weekday.dayValue) {
        case 1:
            weekday.weekValue = "Sunday";
            break;
        case 2:
            weekday.weekValue = "Monday";
            break;
        case 3:
            weekday.weekValue = "Tuesday";
            break;
        case 4:
            weekday.weekValue = "Wednesday";
            break;
        case 5:
            weekday.weekValue = "Thursday";
            break;
        case 6:
            weekday.weekValue = "Friday";
            break;
        case 7: case 0:
            weekday.weekValue = "Saturday";
            break;
            
        default:
            cout<<"Program should not come to this point at seting dayValue";
            break;
    }
}
string setWeekDay(Date date,WeekDay &weekday){
    int result1;
    int result2;
    int result3;
    int result4;
    
    setMonthValue( date, weekday);
    setCenturyValue(date, weekday);
    result1 = date.day+weekday.monthValue;
    if (result1 > 6) {
        int res1 = 0;
        for (int i =1; 7*i<= result1; ++i) {
            res1 = result1 - 7*i;
        }
        result1 = res1;
    }
        int res2 = 0;
        int res3 = date.year%100;
        if (res3>28) {
            for (int j =1; 28*j<= res3; ++j) {
                res2 = res3 - 28*j;
            }
            res3 = res2;
        }
        int res4 = res3 / 4;
        result2 = res4+res3;
    
        if ((date.month==1 or date.month==2) and ((date.year % 4 ==0 and date.year%100 !=0) or date.year%400==0)) {
            result3 = result2 - 1;
        }
        else
            result3= result2 + weekday.centuryValue;
    
        result4 = result3+result1;
    
        if (result4 > 6) {
            int res5 = 0;
            for (int k =1; 7*k<= result4; ++k) {
                res5 = result4 - 7*k;
            }
            result4=res5;
        }
    
    weekday.dayValue = result4;
    setDayValue(date,weekday);
    return weekday.weekValue;
}
