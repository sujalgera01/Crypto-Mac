struct Node 
{
    struct Node* lchild ;
    int data ;
    struct Node* rchild ;
};

struct Queue 
{
    int size ;
    int front ;
    int rear ;
    struct Node **Q ;
};

void create (struct Queue *q , int size )
{
    q->size = size ;
    q->front = 0;
    q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enQueue (struct Queue *q , struct Node* x )
{
    if ((q->rear+1)%q->size == q->front )
        printf ("\nQueue Is Full");
    else {
        q->rear = (q->rear+1)%q->size ;
        q->Q[q->rear] = x ;
    }
}

struct Node* deQueue (struct Queue *q)
{
    struct Node* x = NULL ;
    if (q->front == q->rear)
        printf ("\nQueue is Empty ");
    else 
    {
        q->front = (q->front + 1)%q->size ;
        x = q-> Q[q->front];
    }
    return x ;
}

int isEmpty (struct Queue q )
{
    return q.front == q.rear ;
}




/*#include <string>

using namespace std;

class Student 
{
    int regNo ;
    string name ;
    public :
    Student ();
    Student (int , string );
    Student (Student &);
    string display ();
};

Student :: Student ()
{
    this->regNo = 0 ;
    this->name = "NULL";
}

Student :: Student (int regNo , string name )
{
    this->regNo = regNo ;
    this->name = name;
}

string Student :: display ()
{
    return "Registration Number is " + to_string(this->regNo) + " Name is " + this->name ;
}

Student :: Student (Student &copyConstructorIntitialization)
{
    this->regNo = copyConstructorIntitialization.regNo ;
    this->name = copyConstructorIntitialization.name ;
 //   return copyConstructorIntitialization;
}











// #include <string>

// using namespace std ;

// class Student 
// {
//     int balance ;
//     public :
//     Student(){
//         this->balance = 0 ;
//     }
//     Student(int balance){
//         this->balance = balance ;
//     } 
//     friend ostream &operator << (ostream &mycout  , Student &a )
//     {
//         mycout << "Balance" << a.balance;
//     }
// };









// class Student
// {
//     int balance ;
//     public :
//     void setBalance (int);
//     int display ();
//     Student operator++(); // pre-Incerment ;
//     Student operator++(int); // post-Increment ;
// };


// void Student :: setBalance(int balance )
// {
//     this->balance = balance ;
// }

// int Student :: display()
// {
//     return this->balance ;
// }

// Student Student :: operator++(int) // Post Increment ;
// {
//     cout << "\n Post Increment has been executed successfully\n";
//     Student temp ;
//     temp.balance = this->balance++ ;
//     return temp ;
// }

// Student Student :: operator++ ()
// {
//     cout << "\n This is preIncrement \n";
//     Student temp ;
//     temp.balance = ++this->balance ;  /// cout << i++ ; <<c cout << ++i ;
//     return temp ;
// }



// // #include <string>

// // using namespace std ;

// // class Student 
// // {
// //     int balance ;
    
// //     public :
    
// //     static int countUser ;
// //     static int totalBankAmount ;
    
// //     Student ()
// //     {
// //         Student::countUser++;
// //         balance = 0 ; 
// //     }
    
// //     ~Student ()
// //     {
// //         Student :: countUser-- ;
// //     }
// //     static int getTotalDeleted (int balanceUserDeduction);
// //     static int getTotalBankAmount () ;
// //     static int getCountUser () ;
// //     int getBalance ();
// //     void depositMoney (int inputAmount );
// // };    
// //     void Student :: depositMoney (int inputAmount )
// //     {
// //         balance += inputAmount ;
// //         Student::totalBankAmount += inputAmount ;
// //     }
    
// //     int Student ::  getBalance ()
// //     {
// //         return balance ;
// //     }
// //      int Student :: getCountUser ()
// //     {
// //         return countUser ;
// //     }
// //      int Student :: getTotalBankAmount ()
// //     {
// //         return totalBankAmount ;
// //     }
// //      int Student :: getTotalDeleted (int balanceUserDeduction)
// //     {
// //         return totalBankAmount-balanceUserDeduction ;
// //     }


// // int Student :: countUser = 0 ;
// // int Student :: totalBankAmount = 0 ;
*/