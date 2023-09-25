#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
    float gpa;
};

void display(struct Student *ptr)
{   
    cout<<"ID : "<<ptr->id<<endl;
    cout<<"Name : "<<ptr->name<<endl;
    cout<<"GPA : "<<ptr->gpa<<endl;
}

int main()
{
    struct Student *ptr;
    
    ptr = new Student;

    if(ptr==NULL)
    {
        cout<<"Memory Allocation Failed\n";
        return 0;
    }

    ptr->id=2018040;
    ptr->name= "Sajjad Hossain";
    (*ptr).gpa = 3.74;

    display(ptr);

    delete ptr;
    
}