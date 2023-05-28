#include <iostream>
#include <string>

#ifndef MANAGER
#define MANAGER
#include "Course.hpp"

using namespace std;

namespace P4{
    class SchoolManagementSystem{
        public:
            SchoolManagementSystem();
            ~SchoolManagementSystem();
            void addStudent(const string& name, int id);
            void addCourse(const string& name, int code);
            Student* selectStudent(const string& name, int id);
            Course* selectCourse(const string& name, int code);
            void deleteStudent(Student* student);
            void deleteCourse(Course* course);
            void add_to_course(Student* student);
            void drop_from_course(Student* student);
            void list_students(Course* course)const;
            Student** getStudents()const;
            Course** getCourses()const;
            int getStudentAmount()const;
            int getCourseAmount()const;
            void listAllStudents()const;
            void listAllCourses()const;
        private:
            Student** students;
            int studentAmount=0;
            Course** courses;
            int courseAmount=0;
    };
}
#endif