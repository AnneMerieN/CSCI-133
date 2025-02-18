#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

class Student {
    private:
        int id;
        string name;
        string grade;
    public:
        Student() : id(0), name(""), grade("") {}
        Student(int id, string name, string grade) : id(id), name(name), grade(grade) {}

        string getName() const { return name; }
        string getGrade() const { return grade; }
        int getID() const { return id; }
};

vector<Student> readInFile(const string& filename) {
    vector<Student> students;

    ifstream file(filename);

    if(!file.is_open()) {
        cout << "Error opening file: " << endl;
        return students; // Safety check
    }

    int id;
    string name;
    string grade;

    while (file >> id >> name >> grade) {
        students.push_back(Student(id, name, grade));
    }
    file.close();
    return students;
}

void searchbyName(const vector<Student> students) {
    cout << "Enter name to search: " << flush;
    string name;
    cin >> name;

    for (unsigned i = 0; i < students.size(); ++i) {
        if (students[i].getName() == name) {
            cout << "Grade: " << students[i].getGrade();
            return;
        }
    }
    cout << "Name not found" << endl;
}

int main() {
    vector<Student> students = readInFile("students.txt");

    if (students.empty()) { // Safety check
        cout << "Vector is empty" << endl;
        return -1;
    }

    searchbyName(students);

    return 0;
}