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