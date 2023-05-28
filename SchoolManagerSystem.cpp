#include "SchoolManagerSystem.hpp"
#include "Course.hpp"

P4::SchoolManagementSystem::SchoolManagementSystem() : students(nullptr), courses(nullptr){}; //default constructor

//add student into students** 
void P4::SchoolManagementSystem::addStudent(const string& name, int id){
    for(int i=0; i<studentAmount; i++) if(students[i]->getName()==name && students[i]->getId()==id) return; //if student exists dont add
    Student* newStudent = new Student(name,id); //new student
    Student** newArr = new Student*[studentAmount+1]; //new array with increased size
    for(int i=0; i<studentAmount; i++)newArr[i]= students[i];
    
    newArr[studentAmount] = newStudent;
    students=newArr;
    studentAmount++;
}

void P4::SchoolManagementSystem::addCourse(const string& name, int code){
    for(int i=0; i<courseAmount; i++) if(courses[i]->getName()==name && courses[i]->getCode()==code) return; //if course exists dont add
    Course* newCourse = new Course(name,code); //new course
    Course** newArr = new Course*[courseAmount+1]; //new array with increased size
    for(int i=0; i<courseAmount; i++) newArr[i]= courses[i];

    newArr[courseAmount]= newCourse;
    courses=newArr;
    courseAmount++;
}

P4::Student* P4::SchoolManagementSystem::selectStudent(const string& name, int id){
    for(int i=0; i<studentAmount; i++) if (students[i]->getId()==id && students[i]->getName()==name){
        return students[i];
    }
    return nullptr; //if couldnt find the student return nullptr
}

P4::Course* P4::SchoolManagementSystem::selectCourse(const string& name, int code){
    for(int i=0; i<courseAmount; i++) if (courses[i]->getCode()==code && courses[i]->getName()==name){
        return courses[i];  
    }
    return nullptr; //if couldnt find the course return nullptr
}

//delete student from students**
void P4::SchoolManagementSystem::deleteStudent(Student* student){
    if (student==nullptr) return; //if selectStudent returned nullptr, return
    else if(studentAmount==0) return; //if student amount is 0, return
    for (int i=0; i <courseAmount; i++) courses[i]->removeStudent(student->getName(),student->getId()); //remove the student from all the courses they take
    int index=-1;
    for(int i=0; i<studentAmount; i++)
        if(students[i]==student){ //find student in students**
            index =i;
            break;
        }
    if (index==-1) return; //if couldnt find, return
    studentAmount--;
    Student** newStudents = new Student*[studentAmount]; //new array with decreased size
    for(int i=0; i<index;i++) newStudents[i]=students[i];
    for(int i=index; i<studentAmount; i++) newStudents[i]=students[i+1];
    delete [] students;
    students=newStudents;
}

void P4::SchoolManagementSystem::deleteCourse(Course* course){
    if (course==nullptr) return; //if selectCourse returned nullptr, return
    else if(courseAmount==0) return; //if course amount is 0, return
    for (int i=0; i <studentAmount; i++) students[i]->dropCourse(course->getName(), course->getCode()); //drop course from all students
    int index=-1;
    for(int i=0; i<courseAmount; i++) //find course in courses**
        if(courses[i]==course){
            index =i;
            break;
        }
    if (index==-1) return; //if couldnt find, return
    courseAmount--;
    Course** newCourses = new Course*[courseAmount]; //new array with decreased size
    for(int i=0; i<index;i++) newCourses[i]=courses[i];
    for(int i=index; i<courseAmount; i++) newCourses[i]=courses[i+1];
    delete [] courses;
    courses=newCourses;
}

//list all students that take the enetered course
void P4::SchoolManagementSystem::list_students(Course* course)const{
    if (course==nullptr) return; //if selectCourse returned nullptr, return
    for(int i=0; i<course->getStudentAmount(); i++){
        cout<<course->getStudents()[i]->getName()<<" "<<course->getStudents()[i]->getId()<<endl;
    }
}

//add a student to a course
void P4::SchoolManagementSystem::add_to_course(Student* student){
    if (student==nullptr) return; //if selectStudent returned nullptr, return
    else if (courseAmount==0) return; //if there are no courses, return
    int choice=-1;
    cout <<"0 up"<<endl; //menu go up choice
    for(int i=0; i<courseAmount; i++){
        bool taken =false; //check if student has already taken the course
        for(int j=0; j<courses[i]->getStudentAmount(); j++) 
            if(courses[i]->getStudents()[j]->getId()==student->getId() && courses[i]->getStudents()[j]->getName()==student->getName()){ //if taken
                taken=true;
                break;
            }
        if (!taken) cout << i+1 <<" "<< courses[i]->getCode()<<" "<< courses[i]->getName()<<endl; //if not taken then print the input value to take the 
                                                                                                  // selected course and course information
    }
    do{
        cin >> choice;
    } while(choice <0 || choice >courseAmount); 
    if (choice==0) return;
    for(int i=0; i<student->getCourseAmount(); i++) 
        if(student->getCourses()[i]->getName()==courses[choice-1]->getName() && student->getCourses()[i]->getCode()==courses[choice-1]->getCode())
            return; //if student already takes that course then dont add
    courses[choice-1]->addStudent(student->getName(),student->getId()); //add student to courses**
    student->addToCourse(courses[choice-1]->getName(),courses[choice-1]->getCode()); //add course to student
}

void P4::SchoolManagementSystem::drop_from_course(Student* student){
    if(student==nullptr) return;//if selectStudent returned nullptr, return
    else if (student->getCourseAmount()==0) return; //if student doesnt get any course
    int choice=-1;
    cout<<"0 up"<<endl;
    for(int i=0; i< courseAmount; i++)
        for(int j=0; j<courses[i]->getStudentAmount(); j++)
            if(courses[i]->getStudents()[j]->getId()==student->getId() && courses[i]->getStudents()[j]->getName()==student->getName())
                cout<<i+1<<" "<< courses[i]->getCode() <<" "<< courses[i]->getName()<<endl;
            
    do{
        cin>>choice;
    }while(choice<0 || choice >courseAmount);
    if (choice==0) return;
    //check if student takes the course
    bool valid=false;
    for(int i=0; i<student->getCourseAmount(); i++) 
        if(student->getCourses()[i]->getName()==courses[choice-1]->getName() || student->getCourses()[i]->getCode()==courses[choice-1]->getCode())
            valid=true; //if student takes the course set valid to true
    if (!valid) return; //if valid is false then return

    student->dropCourse(courses[choice-1]->getName(), courses[choice-1]->getCode());
    courses[choice-1]->removeStudent(student->getName(),student->getId());
}

//list all students "<name> <id>"
void P4::SchoolManagementSystem::listAllStudents()const{
    for(int i=0; i<studentAmount; i++) cout<<students[i]->getName()<<students[i]->getId()<<endl;
}
//list all courses "<code> <name>"
void P4::SchoolManagementSystem::listAllCourses()const{
    for(int i=0; i<courseAmount; i++) cout<<courses[i]->getCode()<<courses[i]->getName()<<endl;
}

//getters
P4::Student** P4::SchoolManagementSystem::getStudents()const {return students;}
P4::Course** P4::SchoolManagementSystem::getCourses()const {return courses;}
int P4::SchoolManagementSystem::getStudentAmount()const {return studentAmount;}
int P4::SchoolManagementSystem::getCourseAmount()const {return courseAmount;}

P4::SchoolManagementSystem::~SchoolManagementSystem(){ //destructor
    delete[] students;
    delete[] courses;
}