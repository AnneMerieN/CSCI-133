#include <iostream>


using namespace std;

class Student {
    private:
        string name;
        int id;
        double gpa;
    public:
        int getID() const;
        string getName() const;
        double getGPA() const;
        void setID(int id);
        void setName(string name);
        void setGPA(double gpa);

        // Default constructor
        Student() : id(0), name(""), gpa(0) {}

        // Parameterized constructor
        Student(int id, string name, double gpa) : id(id), name(name), gpa(gpa) {}

};

class Cohort {
    private:
        int numOfStudents;
        string subject;
        string teacher;
        Student classRoom[30];

   // public:
     //   Cohort(int classSize, string sub, string teach) : 
      //  classSize(numOfStudents), sub(subject), teach(teacher) {}
};

void Student::setID(int id) {
    id = id;
}
void Student::setName(string name) {
    name = name;
}
void Student::setGPA(double gpa) {
    gpa = gpa;
}

int Student::getID() const {
    return id;
}
string Student::getName() const {
    return name;
}
double Student::getGPA() const {
    return gpa;
}



