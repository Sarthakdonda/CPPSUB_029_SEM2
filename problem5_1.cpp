#include<iostream>
using namespace std;
class Calculator
{
    public:
    int Add_numbers(int num1, int num2)
    {
        return num1+num2;
    }
    float Add_numbers(float fnum1,float fnum2)
    {
        return fnum1+fnum2;
    }
};
int main()
{
    Calculator Cal;
    int Choice, Number1 , Number2 ,Answere;
    float Fnumber1,Fnumber2,Fanswere;
    cout<<"Enter 1 to add intigers"<<endl;
    cout<<"Enter 2 to add floating point numbers"<<endl;
    cout<<"Enter your Choice : ";
    cin>>Choice;
    switch(Choice){
        case 1:
        cout<<"Enter 1st number : ";
        cin>>Number1;
        cout<<"Enter 2nd number : ";
        cin>>Number2;
        Answere=Cal.Add_numbers(Number1,Number2);
        cout<<"Sumation of 2 intiger number is "<<Answere<<endl;
        break;
        case 2:
        cout<<"Enter 1st number : ";
        cin>>Fnumber1;
        cout<<"Enter 2nd number : ";
        cin>>Fnumber2;
        Fanswere=Cal.Add_numbers(Fnumber1,Fnumber2);
        cout<<"Sumation of 2 floating-point number is "<<Fanswere<<endl;
        break;
        default: 
        cout<<"INVALID CHOICE";

    }
}