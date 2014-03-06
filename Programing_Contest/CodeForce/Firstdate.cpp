#include<iostream>
#include<string>

using namespace std;

int year,day,month,days,yearN;
string input,output="aaaa-mm-dd";
int dim[]={31,28,31,30,31,30,31,31,30,31,30,31};

bool is29F ()
{
    if (day == 28 && month == 2 && year %4 ==0 &&( year %100 ||year %400 == 0 ))
        return 1;
    return 0;
}

int main ()
{
    while(cin>>input) {
        days =11;
        year=0;

        for(int i=0;i<4;i++) {
            year*=10;
            year+=input[i]-'0';
        }

        month =0;
        for(int i=5;i<7;i++) {
            month*=10;
            month+=input[i]-'0';
        }

        day =0;
        for(int i=8;i<10;i++) {
            day*=10;
            day+=input[i]-'0';
        }

        yearN = year;
        if(month < 2 || (month ==2 && day <29))
           yearN--;

        for(int i=1700;i<=yearN;i+=100) {
            if(i%400)
                days++;
        }

        for(int i=0;i<days;i++) {
            if(day>=dim[month-1] && !is29F()) {
                day=0;
                month++;
            }
            if(month == 13) {
                month = 1;
                year ++;
            }
            day++;
        }

        for(int i=3;i>=0;i--) {
            output[i]=(year%10)+'0';
            year/=10;
        }
        
        for(int i=6;i>=5;i--) {
            output[i]=(month%10)+'0';
            month/=10;
        }

        for(int i=9;i>=8;i--) {
            output[i]=(day%10)+'0';
            day/=10;
        }
        cout<<output<<endl;
    }
    return 0;
}
