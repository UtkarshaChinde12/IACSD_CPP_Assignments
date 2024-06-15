// Employee Payroll System with Abstract Classes:
// Problem Statement: Design an employee payroll system. Create an abstract class Employee with attributes like name and employee ID. Derive concrete classes like HourlyEmployee and SalariedEmployee. Define abstract methods for calculating pay in the base class and implement them in the derived classes.

#include<iostream>
using namespace std;

class Employee{
protected:    string name;
    int empID;
public:
    Employee(){
        name="---";
        empID=0;
        cout<<"Employee default ctor"<<endl;
    }
    Employee(string nm, int eID){
        name=nm;
        empID=eID;
        cout<<"Employee Parameterized fault ctor"<<endl;
    }
    virtual void calSalary()=0; //the class contains atleast one pure virtual function is abstract class
    
};
class HourlyEmployee: public Employee{
    double perHourPay;
    int numOfWorkingHrs;
public:
    HourlyEmployee(){
        perHourPay=150;
        numOfWorkingHrs=4;
        cout<<"HourlyEmployee default ctor"<<endl;
    }
    HourlyEmployee(string nm,int eID, double perHourPay, int numOfWorkingHrs):Employee(nm,eID){
        this->perHourPay=perHourPay;
        this->numOfWorkingHrs=numOfWorkingHrs;
        cout<<"HourlyEmployee Parameterized fault ctor"<<endl;
    }
    void calSalary(){
        cout<<"Employee Name: "<<name<<"\nEmployee id: "<<empID<<endl;
        // Employee::calSalary();
        cout<<"Salary of HourlyEmployee(perHourPay*numOfWorkingHrs): "<<(perHourPay*numOfWorkingHrs)<<endl;
    }
};
class SalariedEmployee: public Employee{
    double salary;
    double bonus;
public:
    SalariedEmployee(){
        salary=30000;
        bonus=10000;
        cout<<"SalariedEmployee default ctor"<<endl;
    }
    SalariedEmployee(string nm,int eID, double salary, double bonus):Employee(nm,eID){
        this->salary=salary;
        this->bonus=bonus;
        cout<<"SalariedEmployee Parameterized fault ctor"<<endl;
    }
    void calSalary(){
        cout<<"Employee Name: "<<name<<"\nEmployee id: "<<empID<<endl;
        cout<<"Salary of SalariedEmployee(salary+bonus): "<<(salary+bonus)<<endl;
        
    }
};
int main(){
    // Employee e;//eror obj of abstract employee is not allowed
    // Employee e1;


    // SalariedEmployee s;
    // s.calSalary();

    // SalariedEmployee s1("Ram",101,50000,20000);
    // s1.calSalary();

    // HourlyEmployee h;
    // h.calSalary();
    HourlyEmployee h1("Sham",102,200,5);
    h1.calSalary();
    return 0;
}