#include <iostream>
#include <string>

#ifndef COURSE
#define COURSE
#include "Student.hpp"
using namespace std;

namespace P4{
    class Student;
    class Course{
        public:
            Course();
            Course(const string& n, int c);
            ~Course();
            int getCode()const;
            int getStudentAmount()const;
            string getName()const;
            Student** getStudents()const;
            void setCode(int num);
            void setName(string n);
            Course& operator=(const Course& other);
            void addStudent(const string& name, int id);
            void removeStudent(const string& name, int id);
        private:
            string name;
            int code;
            Student** studentRef;
            int studentAmount=0;
    };
}
#endif