/*Project No:02
Project name:Like Uber,CNG owner's want to develop a software which can communicate with customer and driver.A customer needs to say his/her destination and nearer CNG driver will get message from the Uber company with name and mobile number of the customer.The driver can make a direct call and if the customer confirms the ride then driver will come to spot and carry the passenger.As a student of CSE,write OOP for the project.YOu need to pass message from one end to make communication..*/
#include<iostream>
#include<math.h>
using namespace std;
class Person
{
protected:
    string name;
    int national_id;
public:
    Person(){}
    Person(string name,int national_id)
    {
        this->name=name;
        this->national_id=national_id;
    }
};
class Driver:public Person
{
    int mobile_no;
    string current_location;
public:
    double lattitude;
    double longitude;
    Driver(){}
    Driver(string name,int national_id,int mobile_no,string current_location,double lattitude,double longitude):Person(name,national_id)
    {
        this->mobile_no=mobile_no;
        this->current_location=current_location;
        this->lattitude=lattitude;
        this->longitude=longitude;
    }
    void show_driverinfo()
    {
        cout<<"Driver information:"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"Name    :"<<name<<endl;
        cout<<"National id:"<<national_id<<endl;
        cout<<"Mobile number:"<<mobile_no<<endl;
        cout<<"Current location:"<<current_location<<endl;
        cout<<"Lattitude  :"<<lattitude<<"degree"<<endl;
        cout<<"Longitude :"<<longitude<<"degree"<<endl;
        cout<<"-------------------";
    }
    void Booking()
    {
        cout<<"a seat has been confirmed"<<endl;
    }
};
class Uber
{
    Driver d11,d22;
public:
    void driver_list(Driver&d1,Driver&d2)
    {
        d11=d1;
        d22=d2;
    }
    double calculate_distance(double nlattitude1,double nlongitude1,double nlattitude2,double nlongitude2)
    {
        int nRadius=6371;
        double nDlattitude=(nlattitude2-nlattitude1)*(M_PI/180);
        double nDlongitude=(nlongitude2-nlongitude1)*(M_PI/180);
        double nA=pow(sin(nDlattitude/2),2)+cos(nlattitude1)*cos(nlattitude2)*pow(sin(nDlongitude/2),2);
        double nC=2*atan2(sqrt(nA),sqrt(1-nA));
        double nD=nRadius*nC;
        return nD;
    }
    friend class Customer;
    void contact_with_driver(double nLat1,double nLon1)
    {
        double x,y;
        x=calculate_distance(nLat1,nLon1,d11.lattitude,d11.longitude);
        y=calculate_distance(nLat1,nLon1,d22.lattitude,d22.longitude);
        if(x<y)
            d11.Booking();
        else
            d22.Booking();
    }

};
class Customer:public Person
{
    int mobile_no;
    string destination;
    double lattitudec;
    double longitudec;
public:
    Customer(){}
    Customer(string name,int national_id,int mobile_no,string destination,double lattitudec,double longitudec):Person(name,national_id)
    {
        this->mobile_no=mobile_no;
        this->destination=destination;
        this->lattitudec=lattitudec;
        this->longitudec=longitudec;
    }
    void show_customerinfo()
    {
        cout<<"Customer Information:"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"Name    :"<<name<<endl;
        cout<<"National id:"<<national_id<<endl;
        cout<<"Mobile number:"<<mobile_no<<endl;
        cout<<"Lattitude  :"<<lattitudec<<"degree"<<endl;
        cout<<"Longitude :"<<longitudec<<"degree"<<endl;
        cout<<"Destination:"<<destination<<endl;
        cout<<"-------------------";
    }
    void contact_with_uber(Uber&x)
    {
        double lattitude,longitude;
        lattitude=lattitudec;
        longitude=longitudec;
        cout<<"\n\nFor customer"<<name<<",whose destination is "<<destination<<",";
        x.contact_with_driver(lattitude,longitude);
    }
};
int main()
{
    Customer c1("Sweetie",1,016445,"Comilaa",12,74);
    Driver d1("Rahim",2,0166455,"Dhaka",13,75);
    Driver d2("Rahman",3,0137466,"Magura",13,76);
    d1.show_driverinfo();
    c1.show_customerinfo();
    Uber u1;
    u1.driver_list(d1,d2);
    c1.contact_with_uber(u1);
}
