#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    string roll_number; 
    string name;
    string department;
    string course;
    Student* prev;
    Student* next;
    Student(const string& roll_number, const string& name, const string& department, const string& course)
        : roll_number(roll_number), name(name), department(department), course(course), prev(nullptr), next(nullptr) {}
};
class StudentList {
private:
    Student* head;
public:
    StudentList() : head(nullptr) {}
    void addStudent(const string& roll_number, const string& name, const string& department, const string& course) {
        Student* newStudent = new Student(roll_number, name, department, course);
        if (!head) {
            head = newStudent;
        } else {
            Student* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newStudent;
            newStudent->prev = current;
        }
        cout << "Student added successfully!\n";
    }
    void removeStudent(const string& roll_number) {
        Student* current = head;
        while (current && current->roll_number != roll_number) {
            current = current->next;
        }
        if (!current) {
            cout << "Student with roll number " << roll_number << " not found!\n";
            return;
        }
        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Student with roll number " << roll_number << " removed successfully!\n";
    }
    void displayStudents() const {
        if (!head) {
            cout << "No students to display.\n";
            return;
        }
        cout << "Student Details:\n";
        Student* current = head;
        while (current) {
            cout << "Roll Number: " << current->roll_number
                 << ", Name: " << current->name
                 << ", Department: " << current->department
                 << ", Course: " << current->course << "\n";
            current = current->next;
        }
    }
    void searchStudent(const string& roll_number) const {
        Student* current = head;
        while (current) {
            if (current->roll_number == roll_number) {
                cout << "Student Found:\n";
                cout << "Roll Number: " << current->roll_number
                     << ", Name: " << current->name
                     << ", Department: " << current->department
                     << ", Course: " << current->course << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Student with roll number " << roll_number << " not found!\n";
    }
    ~StudentList() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    StudentList list;
    int choice;
    string roll_number, name, department, course;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Search Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> roll_number;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Department: ";
                getline(cin, department);
                cout << "Enter Course: ";
                getline(cin, course);
                list.addStudent(roll_number, name, department, course);
                break;
            case 2:
                cout << "Enter Roll Number to remove: ";
                cin >> roll_number;
                list.removeStudent(roll_number);
                break;
            case 3:
                list.displayStudents();
                break;
            case 4:
                cout << "Enter Roll Number to search: ";
                cin >> roll_number;
                list.searchStudent(roll_number);
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    }

    return 0;
}

