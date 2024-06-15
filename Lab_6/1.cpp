/*
1 Solve this.
Fresh business scenario to apply inheritance , polymorphism   to emp based organization scenario.

Create Emp based organization structure --- Emp , Mgr , Worker


1.1 Emp state--- id(int), name, deptId , basicSalary(double)
Accept all of above in constructor arguments.

Methods ---
1.2. compute net salary ---ret 0
(eg : public double computeNetSalary(){return 0;})

1.2 Mgr state  ---id,name,basic,deptId , perfBonus
Add suitable constructor
Methods ----
1. compute net salary (formula: basic+perfBonus) -- override computeNetSalary


1.3 Worker state  --id,name,basic,deptId,hoursWorked,hourlyRate
Methods : 
1.  compute net salary (formula:  = basic+(hoursWorked*hourlyRate) --override computeNetSalary
2. get hrlyRate of the worker  -- add a new method to return hourly rate of a worker.(getter)

Create suitable array to store organization details.
Provide following options
1. Hire Manager
I/P : all manager details

2. Hire Worker  
I/P : all worker details

3. Display information of all employees net salary (by invoking computeNetSal), 

4. Exit
----------------------------------------------------
*/

#include<iostream>
#include<string.h>
#include<typeinfo.h>
using namespace std;

class Emp{
    int empID;
    int deptID;
    string name;
protected:    double salary;
public: 
    Emp(){
        empID=1;
        deptID=0;
        name="---";
        salary=0.0;
    }
    Emp(int eID,int dID,string nm,double sal){
        empID=eID;
        deptID=dID;
        name=nm;
        salary=sal;
    }
    // double NetSalary(){
    //     return salary;
    //     cout<<"net sal of employee"<<endl;
    // }
    virtual double NetSalary()=0;
    void display(){
        cout<<"Employee ID: "<<empID<<"\nDepartment ID: "<<deptID<<"\nEmployee Name: "<<name<<"\nSalary: "<<salary<<endl;
        
        cout<<"display of employee"<<endl;
    }
};

class Mgr:public Emp{
    double perfBonus;
public:
    Mgr(){
        perfBonus=0.0;
    }
    Mgr(int eID,int dID,string nm,double sal,double perfBonus):Emp(eID,dID,nm,sal){
        this->perfBonus=perfBonus;
    }
    double NetSalary(){
        int NetSal=(salary+perfBonus);
        return NetSal;
        cout<<"net sal of manager"<<endl;
    }
    void display(){
        Emp::display();
        cout<<"display of manager"<<endl;
        cout<<"Net Salary of Manager(basic salary + performance bonus) : "<<NetSalary()<<endl;
    }
};
class Worker:public Emp{
    double HourlyRate;
public:
    int HoursWorked;
    Worker(){
        HourlyRate=0.0;
        HoursWorked=0;
    }
    Worker(int eID,int dID,string nm,double sal,double HourlyRate,int HoursWorked):Emp(eID,dID,nm,sal){
        this->HourlyRate=HourlyRate;
        this->HoursWorked=HoursWorked;
    }
    double NetSalary(){
        int NetSal=salary+(HourlyRate*HoursWorked);
        return NetSal;
        
        cout<<"net sal of worker"<<endl;
    }
    void display(){
        Emp::display();
        
        cout<<"display of worker"<<endl;
        cout<<"Net Salary of Worker(basic salary + (HourlyRate*HoursWorked)) :"<<NetSalary()<<endl;
    }
    // void setHourlyRate(double HourlyRate){
    //     cout<<"in set";
    //     this->HourlyRate=HourlyRate;
    // }
    
    // double getHourlyRate(){
    //     cout<<"in get";
    //     return HourlyRate;
    // }
};
int main(){
//reference fruitbasket
    Emp* empArray[20];//organization of 20 employees
    Mgr *m;
    Worker *w;

    int choice=0,index=0;
    string name;
    int employeeID;
    int departmentID;
    double salary;
    double perfbonus;
    double hourlyRate=0.0;
    int hoursWorked=0;

    do{
        cout<<"\n\n1.Hire Manager\n2.Hire Worker\n3.Show All employees\n4.Exit.\n"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"\n\n";

        switch(choice){
            case 1:
            //int eID,int dID,string nm,double sal,double perfBonus
                // m=new Mgr(101,201,"Amrita",60000,20000);
                // empArray[index]=m; //upcasting as base class pointer,derived class object
                // compile time datatypes:   emp ptr= mango obj
                // runtime datatypes :       mango ptr = mango 
                
                cout<<"\nEnter empid: ";
                cin>>employeeID;
                cout<<"Enter department id: ";
                cin>>departmentID;
                cout<<"Enter Manager Name: ";
                cin>>name;

                
                
                cout<<"Enter Manager salary: ";
                cin>>salary;
                cout<<"Enter Performance Bonus for manager:";
                cin>>perfbonus;

                m=new Mgr(employeeID,departmentID,name,salary,perfbonus);
                
                empArray[index++]=m;
                // m->display();

                cout<<"Manager is hired"<<endl;


                

                
                break;
            case 2:
                cout<<"Enter employee ID: ";
                cin>>employeeID;
                cout<<"Enter department ID: ";
                cin>>departmentID;
                cout<<"Enter Worker name: ";
                cin>>name;
                cout<<"Enter Worker basic salary: ";
                cin>>salary;
                cout<<"Enter Hours Worked: ";
                cin>>hoursWorked;
                cout<<"Enter hourly rate of worker: ";
                cin>>hourlyRate;
                // w->setHourlyRate(hourlyRate);
                // hourlyRate=w->getHourlyRate();
                // cout<<"hourly rate in main: "<<hourlyRate<<endl;


                
                w=new Worker(employeeID,departmentID,name,salary,hourlyRate,hoursWorked);
                empArray[index++]=w;//upcasting
                // w->display();

                cout<<"Worker is hired"<<endl;
                break;
            case 3: 
            for(int i=0;i<index;i++){

                if(typeid(*empArray[i])==typeid(Mgr)){
                    Mgr * objMgr = dynamic_cast<Mgr *> (empArray[i]);
                    objMgr->display();
                }

                if(typeid(*empArray[i])==typeid(Worker)){
                    Worker *objWorker = dynamic_cast <Worker*>(empArray[i]);
                    objWorker->display();
                }

                
                cout<<"\n\n";
            }

            case 4:exit(0);
                break;
        }
    }while(choice!=4);
    return 0;
}

