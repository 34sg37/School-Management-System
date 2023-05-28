#include "Student.hpp"
#include "Course.hpp"

P4::Student::Student(){} //default constructor
P4::Student::Student(string n, int num) : name(n), id(num), courseRef(nullptr){} //user defined constructor
P4::Student::~Student(){ //destructor
    delete [] courseRef;
}
//getters
int P4::Student::getId()const{return id;}
string P4::Student::getName()const{return name;}
void P4::Student::setId(int num) {id=num;}
int P4::Student::getCourseAmount()const{return courseAmount;}
P4::Course** P4::Student::getCourses()const{return courseRef;}
//setters
void P4::Student::setName(string n) {name=n;}
//assignment operator overloading
P4::Student& P4::Student::operator=(const Student& other){
    if (this!=&other){
        name=other.name;
        id=other.id;

        courseAmount=other.courseAmount;
        delete[] courseRef;
        courseRef= new Course*[courseAmount];
        for(int i=0; i<courseAmount; i++){
            courseRef[i]=other.courseRef[i];
        }
    }
    return *this;
}
//add student to a course
bool P4::Student::addToCourse(const string& name, int code){
    Course* course = new Course(name,code); //new course
    for(int i=0; i<courseAmount; i++) if(courseRef[i] == course) return false; //if student is already in the course, dont add
    courseAmount++; 
    //new array with increased size
    Course** newCourse = new Course*[courseAmount];
    for(int i=0; i<courseAmount-1; i++){
        newCourse[i]=courseRef[i];
    }
    newCourse[courseAmount-1] = course; //new course
    delete [] courseRef;
    courseRef=newCourse;
    return true;
}
//drop a course 
void P4::Student::dropCourse(const string& name, int code){
    int index=-1;
    for(int i=0; i<courseAmount; i++) if(courseRef[i]->getName()==name && courseRef[i]->getCode()==code) index=i; //find the index of course to drop
    if (index==-1) return; //if course not found, return
    courseAmount--;
    //new array with decreased size
    Course** newCourses = new Course*[courseAmount];
    //dont put the dropped course and shift
    for(int i=0; i<index; i++) newCourses[i]=courseRef[i];
    for(int i= index; i<courseAmount; i++) newCourses[i]=courseRef[i+1];
    courseRef=newCourses;
}