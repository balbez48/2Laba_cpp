#pragma once
#include <iostream>

class Student {
  private:
    std::string name;
    int course;
    bool gender;
  public:
    Student();
    Student(const Student&);
    Student(std::string, int, bool);
  
  
    std::string get_name();
    int get_course();
    int get_gender();

    void set_name(std::string);
    void set_course(int);

    void Print();
    void DeleteStudent();


};