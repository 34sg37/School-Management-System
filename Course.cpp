#include "Course.hpp"
#include "Student.hpp"

P4::Course::Course(){} //default constructor
P4::Course::Course(const string& n, int c) : name(n), code(c), studentRef(nullptr){} //user defined constructor
P4::Course::~Course(){ //destructor
    delete [] studentRef;
}
//getters
int P4::Course::getCode()const{return code;}
int P4::Course::getStudentAmount()const{return studentAmount;}
string P4::Course::getName()const {return name;}
P4::Student** P4::Course::getStudents()const {return studentRef;}
//setters
void P4::Course::setCode(int num) {code=num;}
void P4::Course::setName(string n) {name=n;}
//assignment operator overloading
P4::Course& P4::Course::operator=(const Course& other){
    if (this!=&other){
        name=other.name;
        code=other.code;
        
        studentAmount=other.studentAmount;
        delete[] studentRef;
        studentRef= new Student*[studentAmount];
        for(int i=0; i<studentAmount; i++){
            studentRef[i]=other.studentRef[i];
        }
    }
    return *this;
}
//add a new student and hold it inside studentRef
void P4::Course::addStudent(const string& name, int id) {
    Student* student = new Student(name,id);//the new student
    for(int i=0; i<studentAmount;i++) if(studentRef[i]==student) return; //if student already exists dont add
    studentAmount++;

    Student** newStudent = new Student*[studentAmount];
    for (int i = 0; i < studentAmount-1; i++) {
        newStudent[i] = studentRef[i];
    }
    newStudent[studentAmount-1] = student; //new student
    delete[] studentRef;
    studentRef = newStudent;
}
//remove student from studentRef
void P4::Course::removeStudent(const string& name, int id) {
    for (int i = 0; i < studentAmount; i++) {
        if (studentRef[i]->getName() == name && studentRef[i]->getId() == id) { 
            for (int j = i; j < studentAmount - 1; j++) {
                studentRef[j] = studentRef[j+1]; //find the index to remove and shift
            }
            studentAmount--;
            break;
        }
    }
    Student** newStudent = new Student*[studentAmount]; //rearrange the array with correct size
    for (int i = 0; i < studentAmount; i++) {
        newStudent[i] = studentRef[i];
    }
    delete[] studentRef;
    studentRef = newStudent;
}
