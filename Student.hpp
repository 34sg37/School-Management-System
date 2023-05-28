#include <iostream>
#include <string>

#ifndef STUDENT
#define STUDENT
#include "Course.hpp"
using namespace std;

namespace P4{
    class Course;
    class Student{
        public:
            Student();
            Student(string n, int num);
            ~Student();
            int getId()const;
            string getName()const;
            int getCourseAmount()const;
            Course** getCourses()const;
            void setId(int num);
            void setName(string n);
            Student& operator=(const Student& other);
            bool addToCourse(const string& name, int code);
            void dropCourse(const string& name, int code);
        private:
            string name;
            int id;
            Course** courseRef;
            int courseAmount=0;
    };
}
#endif