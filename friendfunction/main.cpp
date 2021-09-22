#include <iostream>

using namespace std;
class Base1;//forword declaration
class Base{
    friend class Base1;
    friend void database(Base b);//friend function syntax is friend data_type nameof function
    friend void getBase(Base b,Base1 c);
    int a=10;
    int b=20;
    int sum(int a,int b){
        return a+b;
    }
};
class Base1{
    friend void getBase(Base b,Base1 c);
    int c=20;
    int d=210;
    public:
    int sum1(Base x){
        cout<<"Sum is "<< x.a+x.b <<endl;
    }
};
void database(Base b){//Access private data of Base

    cout<<"from the database "<<b.a<<endl;
}
void getBase(Base y,Base1 x){//Access private data of both classes

    cout<<"Value of A from Base "<<y.a <<endl<<"Value of C from Base1 "<<x.c<<endl;
}
int main(){
    Base b;
    Base1 c;
    getBase(b,c);
    database(b);
    c.sum1(b);
    return 0;
}
