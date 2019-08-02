#include "Student.h"


Student::Student() : id(0), name()
{
    // nothing to do
}

Student::Student(unsigned int _id, const std::string &_name) : id(_id), name(_name)
{
    // nothing to do
}
