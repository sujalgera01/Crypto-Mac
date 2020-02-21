#include <iostream>
#include <math.h>
#include <string>

using namespace std ;

class Account 
{
    string userName ;
    int accountNumber ;
    
    public :
    
    Account (string inputUserName , int inputAccountNumber);
    string getUserName ();
    int getAccountNumber ();
};

string Account :: getUserName ()
{
    return userName ;
}

int Account :: getAccountNumber ()
{
    return accountNumber ;
}

Account :: Account (string inputUserName , int inputAccountNumber )
{
    userName = inputUserName ;
    accountNumber = inputAccountNumber ;
}

class SavingsAccount : public Account 
{
    int userBalance ;
    
    public :
    
    SavingsAccount (string inputBaseClassUserName , int inputBaseClassAccountNumber , int inputDerivedClassUserBalance ) ;
    int getUserBalance ();
};

SavingsAccount :: SavingsAccount (string inputBaseClassUserName , int inputBaseClassAccountNumber , int inputDerivedClassUserBalance ) : Account (inputBaseClassUserName , inputBaseClassAccountNumber)
{
    userBalance = inputDerivedClassUserBalance ;
}

int SavingsAccount :: getUserBalance ()
{
    return userBalance ;
}

int main ()

{
    SavingsAccount user1 ("VARUN",12345,200);
    cout << "The Balance is " << user1.getUserBalance ();
    cout << "\nThe Account Number is " << user1.getAccountNumber ();
    cout << "\nThe User Name is " << user1.getUserName ();
    return 0 ;
}
// #include <iostream>
// using namespace std ;
// class Base {
//     public :
//     void disp (void){
//         cout << "\nBase Class disp called";
//     }
//     virtual void show (void){
//         cout << "\nBase Class Void SHow \n";
//     }
// };
// class Derived : public Base {
//     public :
//     void disp (void){
//         cout << "\nDerived Class disp";
//     }
//     void show (){
//         cout << "\nDerived Class Show";
//     }
//     void game (){
//         cout <<"\nApna kaam karna\n";
//     }
// };

// int main (){
//     Base* p ;
//     Base objb ;
//     Derived objd;
//     p = &objb;
//     p->disp();
//     p->show();
//     p = &objd ;
//     p->disp();
//     p->show();
//     ((Derived*)p)->game();
//     return 0 ;
// }
// /*#include <iostream>
// using namespace std;
// class Weapon
// {
//     public:
//      // Weapon() { cout << "Loading weapon features.\n"; }
      
//     void features()
//          { cout << "Loading weapon features.\n"; }
// };
// class Bomb : public Weapon
// {
//     public:
//        void features()
//          { 
//             this->Weapon::features(); 
//             cout << "Loading bomb features.\n"; 
//          }
// };
// class Gun : public Weapon
// {
//     public:
//        void features()
//          {
//             this->Weapon::features(); 
//             cout << "Loading gun features.\n"; 
//          }
// };
// class Loader
// {
//    public:
//      void loadFeatures(Weapon *weapon)
//      {  
//         weapon->features();
//         //cout << "Loading Knife Features.\n";
//      }     
// };
// class Knife : public Weapon {
//     public :
//     void features(){
//         this->Weapon :: features ();
//         cout << "Loading Knife features.\n";
//     }
// };
// int main()
// {
//     Loader *l = new Loader;
//     Weapon *w;
//     Bomb b;
//     Gun g;
//     Knife k ;
//     w = &b;
//     l->loadFeatures(w);
//     w = &g;
//     l->loadFeatures(w);
//     w = &k;
//     l->loadFeatures(w);
//     return 0;
// }

// // #include <iostream>
// // #include <stdio.h>
// // #include <math.h>

// // using namespace std ;

// // class Parent {
// //     int age ;
// //     protected :
// //     int gender ;
// //     void outputParent(int inputGender){
// //         gender = inputGender;
// //         cout << "Parent Protected Called\n" << gender;
// //     }
// //     public :
// //     int male ;
// //     void outputParentPublic(int Male){
// //         this->male = Male ;
// //         cout << "Parent Public Called\n" << this->male;
// //     }
// // };

// // class Child : public Parent {
// //     protected :

// //     public :
// //     void checkAlpha(){
// //         outputParent(1);
// //     }
// //     void check2Alpha(){
// //         outputParentPublic();
// //     } 
// // };

// // int main ()
// // {
// //     Child A ; 
// //     //A.outputParent();
// //     A.checkAlpha();
// //     A.check2Alpha();
// //     return 0 ;
// // }*/