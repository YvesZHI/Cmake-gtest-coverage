#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>


class Student
{
public:
    Student();
    Student(unsigned int, const std::string &);
    ~Student() = default;
    Student(const Student &) = default;
    Student & operator=(const Student &) = default;
    Student(Student &&) = default;
    Student & operator=(Student &&) = default;

    inline void SetID(unsigned int _id)
    {
        id = _id;
    }

    inline void SetName(const std::string &_name)
    {
        name = _name;
    }

    inline unsigned int GetID() const
    {
        return id;
    }

    inline std::string GetName() const
    {
        return name;
    }

    inline void ShowInfo() const
    {
        std::cout<<id<<' '<<name<<std::endl;
    }
private:
    unsigned int id;
    std::string name;
};

#endif
