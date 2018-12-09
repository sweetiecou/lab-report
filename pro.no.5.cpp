/*Project no:5
Project name:A Mess owner wants to develop a software for it's mess member.Everyday mess member meal details will be entered in the software and after the month it will show the bill of
the mess member.Mess member deposite at least 1000tk at beginning of the month.As a student of CSE,write OOP code for the project*/

#include<bits/stdc++.h>
using namespace std;
float deposite=1000;
class Member;
class Person
{
    string Name,Dob;
public:
    Person(){}
    Person(string name,string dob)
    {
        Name=name;
        Dob=dob;
    }
    void display()
    {
        cout<<"Name:"<<Name<<endl;
        cout<<"Date of Birth:"<<Dob<<endl;
    }
};
class Owner:public Person
{
public:
    float Meal_rate;
    Owner(){}
    Owner(string Owner_name,string Owner_dob,float meal_rate):Person(Owner_name,Owner_dob)
    {
        Meal_rate=meal_rate;
    }
    void display_owner()
    {
        cout<<"\nDetails of Mess Owner:"<<endl;
        cout<<"--------------------"<<endl;
        display();
        cout<<"Meal Rate:"<<Meal_rate<<endl;
    }
    friend void count_meal(Owner,Member);
};
class Member:public Person
{
public:
    int No_of_meal=0;
    float Meal_cost;
    Member(){}
    Member(string Member_name,string Member_dob):Person(Member_name,Member_dob){}
    void get_meal()
    {
        int day;
        cout<<"\nwrite how many days for executing meal management?";
        cin>>day;
        char C;
        for(int i=0;i<day;i++)
        {
            cout<<"\nDo you want to eat today:";
            cin>>C;
            if(C=='y')
            {
                cout<<"For breakfast?";
                cin>>C;
                if(C=='y')
                    increase();
                cout<<"For lunch?";
                cin>>C;
                if(C=='y')
                    increase();
                cout<<"For dinner?";
                cin>>C;
                if(C=='y'||C=='y')
                    increase();
            }
        }

    }
    void increase()
    {
        No_of_meal++;
    }
    void display_member()
    {
        cout<<"\nMember's Information"<<endl;
        cout<<"--------------------"<<endl;
        display();
        get_meal();
        cout<<"\nNo of total meal:"<<No_of_meal<<endl;
    }
};
    void count_meal(Owner a,Member b)
    {
        int Cost;
        Cost=a.Meal_rate*b.No_of_meal;
        cout<<"Total Meal Cost:"<<Cost<<"taka"<<endl;
        if(Cost<deposite)
            cout<<"You will get"<<deposite-Cost<<"taka"<<endl;
        else
            cout<<"You due money for this month is"<<Cost-deposite<<"taka"<<endl;
    }
    int main()
    {
        Owner O1("Trisha","15/06/1986",22);
        O1.display_owner();
        Member M1("Rony","20//01/2000");
        M1.display_member();
        count_meal(O1,M1);
    }

