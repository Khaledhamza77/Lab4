#include<iostream>
#include<string>
#include<ctime>
#include<random>
#include"section.h"
using namespace std;

int main(){
    srand(time(0));
    Section S1("PHIL2100",4);
    Section S2("PHIL2100",4);
    Section S3("CSCE1106",2);
    Section S4("DSCI3340",5);
    Section S5("DSCI3340",2);
    Section S6("MACT4430",1);
    for(int i=0;i<4;i++){
        S1.setStudentID(to_string(900190000 + rand() % (( 900229999 + 1 ) - 900190000)),i); //  for random interval -> min + rand() % (( max + 1 ) - min)
    }
    for(int i=0;i<4;i++){
        S2.setStudentID(to_string(900190000 + rand() % (( 900229999 + 1 ) - 900190000)),i);
    }
    for(int i=0;i<2;i++){
        S3.setStudentID(to_string(900190000 + rand() % (( 900229999 + 1 ) - 900190000)),i);
    }
    for(int i=0;i<5;i++){
        S4.setStudentID(to_string(900190000 + rand() % (( 900229999 + 1 ) - 900190000)),i);
    }
    for(int i=0;i<2;i++){
        S5.setStudentID(to_string(900190000 + rand() % (( 900229999 + 1 ) - 900190000)),i);
    }
    for(int i=0;i<1;i++){
        S6.setStudentID(to_string(900190000 + rand() % (( 900229999 + 1 ) - 900190000)),i);
    }
    if(S1>S6) cout<<"There are more students in S1 than in S6\n";else cout<<"S1 doesn't have more students compared to S6\n";
    if(S3<=S5) cout<<"S3 has less or equal number of students compared to S5\n"; else cout<<"S3 has more students than S5\n";
    if(S1==S2) cout<<"S1 and S2 have the same number of students\n";
    cout<<"The ID of the fourth student in section 4 is: "<<S4[3]<<"\n";
    Section S8=S5+S6;
    Section S7=S1+S2;
    cout<<"There are 8 students in S7 now, their IDs are:\n";
    for(int i=0;i<8;i++){
        cout<<S7.getStudentID(i)<<"\n";
    }

    return 0;
}