#include <iostream>
#include <string> 
using namespace std ; 

int add(int b, int n ){

    return b + n ; 
}

int sub(int b, int n){
    return b - n ;

}

int mult(int b, int n){
    return b * n ; 
}

float divideNum(float b, float n){
    if(b == 0 )
    {
        cout << "\nError: division by zero\n" ;
        return 0 ;
    }
    return b / n ;
}

int main()
{
    int x , y ; 
    int chose ;

    cout << "Enter first Number: " ;
    cin >> x ;

    cout << "Enter seconde Number:  " ; 
    cin >> y ;


    cout << "\nChoose operation: \n " ;
    cout <<"1- Add \n2- Subtract\n3- Multiply\n4- Divide\n5-Exit\n" ; 
    while(true)
    {
    cout << "If you need an operation enter your chose: " ;
    cin >> chose ;

    switch(chose)
    {
        case 1: cout<<"Sum:" << add (x, y) << " \n " ; break;
        case 2: cout <<"Subtract: " <<sub(x, y)<< "\n" ;  break;
        case 3: cout <<"Multiply: " <<mult(x, y) << "\n" ;  break;
        case 4: cout << "DivideNum: " << divideNum(x, y) << "\n" ;  break;
        case 5: cout << "Done Exit" ;   return 0 ;
    }

    }
  
}
