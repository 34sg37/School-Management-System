#include <iostream>
#include <string>
#include "Course.hpp" 
#include "Student.hpp"
#include "SchoolManagerSystem.hpp"

using namespace std;

int main(){
    P4::SchoolManagementSystem system;
    char in1='1'; //input1
    do{ //loop until 0 or invalid input entered
        char in2='1'; 
        cout<<"Main_menu"<<endl<<"0 exit"<<endl<<"1 student"<<endl<<"2 course"<<endl<<"3 list_all_students"<<endl<<"4 list_all_courses"<<endl;
        cin>>in1;
        switch(in1){
            case '0': //exit
                return 0;
            case '1':
                do{
                    cout<<">>1 student"<<endl<<"0 up"<<endl<<"1 add_student"<<endl<<"2 select_student"<<endl;
                    cin>>in2;
                    char in4='1';
                    if (in2=='1'){ 
                        getchar();
                        //getline into input 
                        //add letters and spaces to name string
                        //add numbers to id string
                        //send id as stoi(id) to addStudent(string,int)
                        string input,name ="", id=""; 
                        getline(cin,input);
                        for(char v :input){
                            if (v>'9' ||v==' ') name+=v;
                            else id+=v;
                        }
                        system.addStudent(name,stoi(id));
                    }
                    else if (in2=='2'){
                        getchar();
                        string input,name ="", id="";
                        getline(cin,input);
                        for(char v :input){
                            if (v>'9' ||v==' ') name+=v;
                            else id+=v;
                        }
                        do{
                            cout<<">>2 select_student"<<endl<<"0 up"<<endl<<"1 delete_student"<<endl<<"3 add_selected_student_to_a_course"<<endl<<"4 drop_selected_student_from_a_course"<<endl;
                            cin>>in4;
                            if(in4=='1') system.deleteStudent(system.selectStudent(name,stoi(id)));
                            else if(in4=='3') system.add_to_course(system.selectStudent(name,stoi(id)));
                            else if(in4=='4') system.drop_from_course(system.selectStudent(name,stoi(id)));
                        }while(in4!='0');
                    }
                }while(in2!='0');
                break;
            case '2':
                while(in2!='0'){// loop until 0 is entered
                    char in5='1';
                    cout<<">>2 course"<<endl<<"0 up"<<endl<<"1 add_course"<<endl<<"2 select_course"<<endl;
                    cin>>in2;
                    if(in2=='1'){
                        getchar();
                        string input,name ="", code="";
                        getline(cin,input);
                        for(char v :input){
                            if (v>'9' ||v==' ') name+=v;
                            else code+=v;
                        }
                        system.addCourse(name,stoi(code));
                    }
                    else if(in2=='2'){ 
                        getchar();
                        string input,name ="", code="";
                        getline(cin,input);
                        for(char v :input){
                            if (v>'9' ||v==' ') name+=v;
                            else code+=v;
                        }
                        do{
                            cout<<">>2 select_course"<<endl<<"0 up"<<endl<<"1 delete_course"<<endl<<"2 list_students_registered_to_the_selected_course"<<endl;
                            cin>>in5;
                            if(in5=='1') system.deleteCourse(system.selectCourse(name,stoi(code)));
                            else if(in5=='2') system.list_students(system.selectCourse(name,stoi(code)));
                        }while(in5!='0');
                    }
                }
                break;
            case '3':
                system.listAllStudents();
                break;
            case '4': 
                system.listAllCourses();
                break;
        }
    }while(in1!=0);
}
