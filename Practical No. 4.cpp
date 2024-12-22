// Q.4.Write a C++ program that creates an output file, writes information to it, 
// closes the file, open it again as an input file and read the information from the 
// file.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee {
    string Name;
    int ID;
    double salary;

public:
    void accept() {
        cout << "\nName: ";
        cin.ignore();
        getline(cin, Name);
        cout << "ID: ";
        cin >> ID;
        cout << "Salary: ";
        cin >> salary;
    }

    void display() const {
        cout << "\nName: " << Name;
        cout << "\nID: " << ID;
        cout << "\nSalary: " << salary << endl;
    }

    void writeToStream(ofstream &out) const {
        size_t length = Name.size();
        out.write((char*)&length, sizeof(length));
        out.write(Name.c_str(), length);
        out.write((char*)&ID, sizeof(ID));
        out.write((char*)&salary, sizeof(salary));
    }

    void readFromStream(ifstream &in) {
        size_t length;
        in.read((char*)&length, sizeof(length));
        Name.resize(length);
        in.read(&Name[0], length);
        in.read((char*)&ID, sizeof(ID));
        in.read((char*)&salary, sizeof(salary));
    }
};

int main() {
    Employee o[5];
    ofstream outFile;
    ifstream inFile;
    int n;

    outFile.open("demo.txt", ios::out | ios::binary);
    cout << "\nEnter the number of employees you want to store (max 5): ";
    cin >> n;

    if (n > 5) {
        cout << "You can only store up to 5 employees." << endl;
        n = 5;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nEnter information of Employee " << i + 1 << "\n";
        o[i].accept();
        o[i].writeToStream(outFile);
    }

    outFile.close();

    inFile.open("demo.txt", ios::in | ios::binary);
    cout << "\nInformation of Employees is as follows:\n";

    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << "\n";
        o[i].readFromStream(inFile);
        o[i].display();
    }

    inFile.close();
    return 0;
}
