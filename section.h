#include <iostream>
#include <string>
using namespace std;

class Section{
private:
    string courseID;
    int studentsCount;
    string* studentsIDs;
public:
    Section(){
        courseID = "XXXX";
        studentsCount = 3;
        studentsIDs = new string[studentsCount];
    }
    Section(string ID, int count){
        courseID = ID;
        studentsCount = count;
        studentsIDs = new string[studentsCount];
    }
    ~Section(){
        delete[] studentsIDs;
    }
    void setCourseID(string ID){
        courseID = ID;
    }
    string getCourseID() const {
        return courseID;
    }
    void setStudentID(string ID, int studentIndex){
        *(studentsIDs + studentIndex) = ID;
    }
    string getStudentID(int studentIndex) const {
        return *(studentsIDs + studentIndex);
    }
    void printData(){
        cout << courseID << " has " << studentsCount << " students enrolled, whose IDs are ( ";
        for (int i = 0; i < studentsCount; i++)
        cout << *(studentsIDs + i) << " ";
        cout << ")";
    }
    bool operator > (const Section& S2){
    if(this->studentsCount>S2.studentsCount)
        return true;
    else
        return false;
    }
    bool operator <= (const Section& S2){
        if(this->studentsCount<=S2.studentsCount)
            return true;
        else
            return false;
    }
    bool operator == (const Section& S2){
        if(this->studentsCount==S2.studentsCount)
            return true;
        else
            return false;
    }
    string operator [] (const int& i){
        if(i>=studentsCount) cout<<"Index out of range!\n";
        return this->getStudentID(i);
    }
    void operator=(const Section& S2){
        this->studentsCount=S2.studentsCount;
        this->courseID=S2.courseID;
        for(int i=0;i<this->studentsCount;i++){
            this->setStudentID(S2.getStudentID(i),i);
        }
    }
    Section operator + (const Section& S2){
        int j=0;
        if(this->getCourseID()==S2.getCourseID()){
            Section S3(this->getCourseID(),this->studentsCount+S2.studentsCount);
            for(int i=0;i<this->studentsCount;i++){
                S3.setStudentID(this->getStudentID(i),i);
            }
            for(int i=this->studentsCount;i<S3.studentsCount;i++){
                S3.setStudentID(S2.getStudentID(j),i);
                j++;
            }
            return S3;
        }
        else{
            cout<<"These two sections do not have the same course ID, they can't be merged into one section!\n";
            return S2;
        }
    }
};