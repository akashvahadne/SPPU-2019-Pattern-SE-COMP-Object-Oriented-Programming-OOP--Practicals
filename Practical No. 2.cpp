// Q.2 : Develop a program in C++ to create a database of student’s information 
// system containing the following information: Name, Roll number, Class, 
// Division,Date of Birth, Blood group,Contact address, Telephone number, 
// Driving license no. and other. Construct the database with suitable member 
// functions. Make use of constructor, default constructor,copy 
// constructor,destructor, static member functions, friend class, this pointer, 
// inline code and dynamic memory allocation operators-new and delete as well 
// as exception handling.

#include <iostream>
#include <string>
using namespace std;

class StudData;

class Student {
    string name;
    int roll_no;
    string cls;
    char* division;
    string dob;
    char* bloodgroup;
    static int count;

public:
    Student() {
        name = "";
        roll_no = 0;
        cls = "";
        division = new char[10];
        dob = "dd/mm/yyyy";
        bloodgroup = new char[4];
    }

    ~Student() {
        delete[] division;
        delete[] bloodgroup;
    }

    static int getCount() {
        return count;
    }

    void getData(StudData*);
    void dispData(StudData*);
};

class StudData {
    string caddress;
    long telno;
    long dlno;
    friend class Student;

public:
    StudData() {
        caddress = "";
        telno = 0;
        dlno = 0;
    }

    void getStudData() {
        cout << "Enter Contact Address: ";
        cin.ignore();
        getline(cin, caddress);
        cout << "Enter Telephone Number: ";
        cin >> telno;
        cout << "Enter Driving License Number: ";
        cin >> dlno;
    }

    void dispStudData() {
        cout << "Contact Address: " << caddress << endl;
        cout << "Telephone Number: " << telno << endl;
        cout << "Driving License Number: " << dlno << endl;
    }
};

int Student::count = 0;

inline void Student::getData(StudData* st) {
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> roll_no;
    cout << "Enter Class: ";
    cin.ignore();
    getline(cin, cls);
    cout << "Enter Division: ";
    cin >> division;
    cout << "Enter Date of Birth: ";
    cin.ignore();
    getline(cin, dob);
    cout << "Enter Blood Group: ";
    cin >> bloodgroup;
    st->getStudData();
    count++;
}

inline void Student::dispData(StudData* st1) {
    cout << "Student Name: " << name << endl;
    cout << "Roll Number: " << roll_no << endl;
    cout << "Class: " << cls << endl;
    cout << "Division: " << division << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bloodgroup << endl;
    st1->dispStudData();
}

int main() {
    Student* stud1[100];
    StudData* stud2[100];
    int n = 0;
    char ch;
    do {
        stud1[n] = new Student;
        stud2[n] = new StudData;
        stud1[n]->getData(stud2[n]);
        n++;
        cout << "Do you want to addanother student (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    
    for (int i = 0; i < n; i++) {
        cout << "---------------------------------------------------------------" << endl;
        stud1[i]->dispData(stud2[i]);
    }
    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students: " << Student::getCount();
    cout << endl << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        delete stud1[i];
        delete stud2[i];
    }

    return 0;
}
