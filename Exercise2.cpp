#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
    string name;
    string address;

public:
    Person(string name, string address)
        : name(name), address(address) {}

    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }

    void setAddress(string newAddress) {
        address = newAddress;
    }

    string toString() const {
        return "Person[name=" + name + ", address=" + address + "]";
    }
};

class Student : public Person {
private:
    string program;
    int year;
    double fee;

public:
    Student(string name, string address, string program, int year, double fee)
        : Person(name, address), program(program), year(year), fee(fee) {}

    string getProgram() const {
        return program;
    }

    void setProgram(string newProgram) {
        program = newProgram;
    }

    int getYear() const {
        return year;
    }

    void setYear(int newYear) {
        year = newYear;
    }

    double getFee() const {
        return fee;
    }

    void setFee(double newFee) {
        fee = newFee;
    }

    string toString() const {
        return "Student[name=" + getName() + ", address=" + getAddress() + ", program=" + program + ", year=" + to_string(year) + ", fee=" + to_string(fee) + "]";
    }
};

class Staff : public Person {
public:
    Staff(string name, string address)
        : Person(name, address) {}
};

class SchoolBusinessTest {
public:
    static void main() {
        vector<Student> students;

        // Initialize students with new year 2023
        for (int i = 0; i < 5; i++) {
            students.push_back(Student("Student " + to_string(i + 1), "Address " + to_string(i + 1), "Program " + to_string(i + 1), 2023, 1000.0));
        }

        // Print information of all the students
        for (const Student& student : students) {
            cout << student.toString() << endl;
        }

        // Create a staff and set a new address for the staff
        Staff staff("Staff Member", "Old Address");
        staff.setAddress("New Address for Staff");
        cout << staff.toString() << endl;
    }
};

int main() {
    SchoolBusinessTest::main();
    return 0;
}
