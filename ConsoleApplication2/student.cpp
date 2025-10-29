#include "student.h"

Student::Student()
{
	name = "Ivan";
	course = 1;
	gender = true;
}

Student::Student(const Student& student)
{
	name = student.name;
	course = student.course;
	gender = student.gender;

}

Student::Student(std::string name, int course, bool gender)
{
	set_name(name);
	set_course(course);
	this->gender = gender;

}

std::string Student::get_name()
{
	return name;
}

int Student::get_course()
{
	return course;
}

int Student::get_gender()
{
	return gender;
}

void Student::set_name(std::string)
{
	if (course >= 1 && course <= 6) {
		this->course = course;
	} else {
		std::cout << "ERROR" << std::endl;
		this->course = 1;
	}
	
}

void Student::set_course(int)
{
	this->course = course;
}

void Student::Print()
{
	std::cout << name << " " << course << " " << gender << std::endl;
}

void Student::DeleteStudent()
{
	std::cout << "";
}
