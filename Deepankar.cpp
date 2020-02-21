 #include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std ;

class Student 
{
    string name ;
    public:
    Student ();
    virtual string getStudentDetails ();
};

class UG  : virtual public Student 
{
    protected :
    int regNo ;
    public :
    UG(int);
};

class PG : virtual public Student 
{
    protected :
    int regNo ;
    public :
    PG(int);
};

class Biodata : public PG , public UG 
{
    public :
    Biodata (int , int );
    string getStudentDetails();
};

Student :: Student (){
    cout << "\nConstructor For Student Called";
    this->name ="UnAssigned";
}

UG :: UG (int regNo){
    cout << "\nConstructor For UG Called";
    this->regNo = regNo ;
}

PG :: PG (int regNo){
    cout << "\nConstructor For PG Called";
    this->regNo = regNo ;
}

Biodata :: Biodata (int ugRegNo , int pgRegNo ) : UG (ugRegNo) , PG (pgRegNo)
{
    cout << "\nConstructor For Biodata Called";
}

string Biodata :: getStudentDetails ()
{
    return "\nRegNo For UG is " + to_string(UG::regNo)+ " RegNo for PG is " + to_string (PG::regNo) ;    
}

string Student :: getStudentDetails ()
{
    return "\n" + this->name ;
}

int main ()

{
    Student *rahul = new Biodata(1111,2222);
    cout << rahul->getStudentDetails();
    cout << "\n";
    return 0 ;
}

/*#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
// Generates and prints 'count' random 
// numbers in range [lower, upper]. 
void printRandoms(int lower, int upper,  
                             int count) 
{ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        printf("%d,", num); 
    } 
} 
  
// Driver code 
int main() 
{ 
    int lower = 17, upper = 20, count = 60; 
  
    // Use current time as  
    // seed for random generator 
    srand(time(0)); 
  
    printRandoms(lower, upper, count); 
  
    return 0; 
} 

// #include <iostream> 

// int main() 
// { 
//     int lower = 17, upper = 20, count = 60; 
  
//     // Use current time as  
//     // seed for random generator 
//     srand(time(0)); 
  
//     printRandoms(lower, upper, count); 
  
//     return 0; 
// } 
/*using namespace std; 

int main() 
{ 
	try { 
	throw 'a'; 
	} 
	catch (int x) { 
		cout << "Caught "; 
	} 
	return 0; 
}

/*#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std ;

struct Term 
{
    int coeff ;
    int power ;
};

struct Poly 
{
    int n ;
    struct Term *terms ;
};

void create (struct Poly *p)
{
    printf ("\nNumber Of Terms?\n");
    scanf ("%d",p->n);
    p->terms = (struct Term*)malloc(p->n*sizeof(struct Term*));
    
}
/*#include <iostream>

using namespace std ;

class Element 
{
    public :
         int i ;
         int j ;
         int x ;
};

class Sparse 
{
    private :
        int m ;
        int n ;
        int num ;
        Element *ele ;
    
    public :
        Sparse (int m , int n , int num )
        {
            this->m = m ;
            this->n = n ;
            this->num = num ;
            ele = new Element[this->num];
        }

        ~Sparse ()
        {
            delete []ele ;
        }
        Sparse operator+ (Sparse &s);
        friend istream & operator >> (istream &is , Sparse &s);
        friend ostream & operator << (ostream &os , Sparse &s);
};

Sparse Sparse :: operator+(Sparse &s)
{
    int i , j , k ;
    if (m != s.m || n != s.n)
        exit (-1);
    Sparse *sum = new Sparse (m,n,num+s.num);
    i = j = k = 0 ;
    while (i < num && j <s.num )
    {
        if (ele[i].i < s.ele[j].i)
            sum->ele[k++] = ele[i++];
        else if (ele[i].i > s.ele[j].i)
            sum->ele[k++] = s.ele[j++];
        else 
        {
            if (ele[i].j < s.ele[j].j)
                sum->ele[k++] = ele[i++];
            else if (ele[i].j > s.ele[j].j)
                sum->ele[k++] = s.ele[j++] ;
            else 
            {
                sum->ele[k] = ele[i] ;
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x ;
            }
        }
    }

    while (i < num || j < s.num )
    {
        if (i < num)
            sum->ele[k++] = s.ele[i++];
        else if (j < num)
            sum->ele[k++] = s.ele[j++];
    }
    sum->num = k ;
    return *sum ;

}

        istream & operator >> (istream &is , Sparse &s)
        {
            cout <<"\nEnter The Non-Zero Elements\n";
            for (int i = 0 ; i < s.num ; i++ )
                cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x ;
            return is ;
        }

        ostream & operator << (ostream &os , Sparse &s)
        {
            int k = 0 ;
            for (int i = 0 ; i < s.m ; i++ )
            {
                for (int j = 0 ; j < s.n ; j++ )
                {
                    if (s.ele[k].i == i && s.ele[k].j == j)
                        cout << s.ele[k++].x << " ";
                    else 
                        cout << "0 ";
                }
                cout << "\n";
            }
            return os ;
        }


int main ()

{
    Sparse s1 (5,5,5);
    Sparse s2 (5,5,5);
    cin >>s1 ;
    cin >> s2 ;

    Sparse sum = s1 + s2 ;
    cout << "First Matrix " << endl << s1 ;
    cout << "Second Matrix " << endl << s2 ;
    cout << "Sum Matrix " << endl << sum ;

    return 0 ;
}

/*
// C program for generating a 
// random number in a given range. 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
// Generates and prints 'count' random 
// numbers in range [lower, upper]. 
void printRandoms(int lower, int upper,  
                             int count) 
{ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        printf("%d,", num); 
    } 
} 
  
// Driver code 
int main() 
{ 
    int lower = 45, upper = 129, count = 60; 
  
    // Use current time as  
    // seed for random generator 
    srand(time(0)); 
  
    printRandoms(lower, upper, count); 
  
    return 0; 
} 

/*#include<stdio.h>

https://islidedocs.com/document/lab5
variableX = 0.20*900 
variableX

variableY = 0.15*1600
variableY

setXAndY = c (variableX , variableY)

setNumberXAndNumberY = c (900,1600)


prop.test (setXAndY,setNumberXAndNumberY,alternative="less",correct="FALSE")

prop.test (setXAndY,setNumberXAndNumberY,correct="FALSE")


## Null Hypothesis :- mho = 16.4
xbar = 15.6
mu0 = 16.4
sigma = 3.5
n = 36 

z = (xbar - mu0 )/(sigma/sqrt(n))

z

alpha = .05
z.half.alpha = qnorm (1-alpha/2)
c(-z.half.alpha,z.half.alpha)

qnorm(.95)

##R version 3.3.2 
#Height = c (149,154,178,149,176,149,147,179,189,192,144,144,188,148,189,165,149,166,172,172,185,172,150,181,160,169,174,167,157,172,195,164,183,157,149,195,163,185,157,156,182,190,158,174,143,183,175,181,185,183,190,174,191,144,192,155,149,170,179,143);
#Height 
#Weight = c (63,77,80,81,59,57,51,63,87,82,71,98,45,89,59,58,103,63,101,109,109,89,90,56,50,88,89,51,71,78,123,47,119,115,83,49,98,47,109,84,84,51,52,127,52,108,55,110,126,95,90,62,54,92,74,101,50,75,108,76)
#Weight 
#BMI = c(Weight/((Height/100)*(Height/100)))
#BMI
#Variable = c (1:60)
#Variable
#BODY_MASS_RATIO = data.frame (Variable,Height,Weight,BMI)
#BODY_MASS_RATIO 
#Regression
#Regression <- lm (BMI ~ Height +  Weight)
#summary (Regression)




#define max 10
https://www.slideshare.net/VimalaMathew/hypothesis-testing-69449433
https://www.coursehero.com/file/22533799/Lab-7/

int pqinsert(int[],int);
int pqserve(int [],int,int);
void pqdisplay(int[],int,int);
int main()
{
    ## Null Hypothesis :- mho = 16.4

qnorm(.95)

#variableX = 0.20*900 
#variableX

#variableY = 0.15*1600
#variableY

#setXAndY = c (variableX , variableY)

#setNumberXAndNumberY = c (900,1600)


#prop.test (setXAndY,setNumberXAndNumberY,alternative="less",correct="FALSE")

#prop.test (setXAndY,setNumberXAndNumberY,correct="FALSE")

#prop.test (c(96,656), c(578,2992), alternative=c("less") ,correct="FALSE")



#xbar = 15.6
#mu0 = 16.4
#sigma = 3.5
#n = 36 

#z = (xbar - mu0 )/(sigma/sqrt(n))

#z

#alpha = .05
#z.half.alpha = qnorm (1-alpha/2)
#c(-z.half.alpha,z.half.alpha)

#qnorm(.95)

##R version 3.3.2 
#Height = c (149,154,178,149,176,149,147,179,189,192,144,144,188,148,189,165,149,166,172,172,185,172,150,181,160,169,174,167,157,172,195,164,183,157,149,195,163,185,157,156,182,190,158,174,143,183,175,181,185,183,190,174,191,144,192,155,149,170,179,143);
#Height 
#Weight = c (63,77,80,81,59,57,51,63,87,82,71,98,45,89,59,58,103,63,101,109,109,89,90,56,50,88,89,51,71,78,123,47,119,115,83,49,98,47,109,84,84,51,52,127,52,108,55,110,126,95,90,62,54,92,74,101,50,75,108,76)
#Weight 
#BMI = c(Weight/((Height/100)*(Height/100)))
#BMI
#Variable = c (1:60)
#Variable
#BODY_MASS_RATIO = data.frame (Variable,Height,Weight,BMI)
#BODY_MASS_RATIO 
#Regression
#Regression <- lm (BMI ~ Height +  Weight)
#summary (Regression)


    int pq[max],F=-2,R=-2,ch;
    do
    {
        printf("\n1. INSERT \n2.SERVE\n3.DISPLAY\n4. EXIT\n\n");
        printf("\nENTER YOUR CHOICE");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            R=pqinsert(pq,R);
            if(F==-2)
                F=0;
            break;
        case 2:
            if(F==-2)
            printf("\n\nPRIORITY QUEUE UNDERFLOW\n\n");
            else
            F=pqserve(pq,F,R);
            if (F==-2)
                R=-2;
                break;
        case 3:
            pqdisplay(pq,F,R);
            break;
        case 4:
            break;
        default:
            printf("WRONG CHOICE");
        }
    }while(ch!=4);
    return 0;
}
int pqinsert(int pq[],int R)
{
    if(R==max)
        printf("PRIORITY QUEUE OVERFLOW");
    else
    {
        R+=2;
        printf("ENTER ELEMENT AND ITS PRIORITY\n");
        scanf("%d %d",&pq[R],&pq[R+1]);
    }
    return (R);
}
int pqserve(int pq[],int F,int R)
{
    int v,p,i,j;
    v=pq[F];
    p=pq[F+1];
    for(i=F+1;i<=R+1;i+=2)
    {
        if(p>pq[i])
        {
            v=pq[i-1];
            p=pq[i];  
            j=i;
        }
    }
    printf("ELEMENT SERVED IS %d AND ITS PRIORITY IS %d",v,p);
    if(j-1==0)
        F+=2;
        else if (F==R)
            F=-2;
        else
        {
            for(i=j;i>=0;i-=2)
            {
                pq[i]=pq[i-2];
                pq[i-1]=pq[i-3];
            }
            F+=2;
        }
        return F;
}
void pqdisplay(int pq[],int F,int R)
{
    int i;
    if(F==-2)
        printf("PRIORITY QUEUE IS EMPTY");
    else
    {
        for(i=F;i<=R+1;i++)
            printf("%d  ",pq[i]);
    }
}

/*#include<stdio.h>

int size ;

struct array {
int a[100];
int size;
int length;

};

void display (struct array arr)
{
  int i;
  for (i=0;i<5;i++)
  {
    printf("%d",arr.a[i]);
  }
}
void append (struct array *arr,int x)
{
  if (arr->length<arr->size)
  {
    arr->a[arr->length++]=x;
  }
}
void insert (struct array *arr,int index,int x)
{
int i;
  if (index>=0 && index <=arr->length)
  {
    for (i=arr->length;i>index;i--)
    arr->a[i]=arr->a[i-1];
    
    arr->a[index]=x;
    arr->length++;

  }
}

void insertion (struct array *arr)
{
    printf ("Plz Enter the digits ");
    printf ("\nPlz Enter the total size of the array : ");
    scanf ("%d",&size);
    arr->length = size ;
    printf ("\nPlz Enter the Size upto Which you want to enter \n");
    int inputSize ;
    scanf ("%d",&inputSize);

    for (int i = 0 ; i < inputSize ; i++ )
    {
        int inputElement ;
        scanf ("%d",&inputElement);
        arr->a[i] = inputElement; 
    }
}

int main()
{
   // struct array arr={{2,3,4,5,6},10,5};
  struct array arr ;
  insertion (&arr);
  append(&arr,10);
  insert(&arr,2,5);
  display(arr);
  return 0;
}
/*#include <iostream>

using namespace std ;

class Element 
{
    public :
         int i ;
         int j ;
         int x ;
};

class Sparse 
{
    private :
        int m ;
        int n ;
        int num ;
        Element *ele ;
    
    public :
        Sparse (int m , int n , int num )
        {
            this->m = m ;
            this->n = n ;
            this->num = num ;
            ele = new Element[this->num];
        }

        ~Sparse ()
        {
            delete []ele ;
        }

        friend istream & operator >> (istream &is , Sparse &s);
        friend ostream & operator << (ostream &os , Sparse &s);
};
        istream & operator >> (istream &is , Sparse &s)
        {
            cout <<"\nEnter The Non-Zero Elements\n";
            for (int i = 0 ; i < s.num ; i++ )
                cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x ;
            return is ;
        }

        ostream & operator << (ostream &os , Sparse &s)
        {
            int k = 0 ;
            for (int i = 0 ; i < s.m ; i++ )
            {
                for (int j = 0 ; j < s.n ; j++ )
                {
                    if (s.ele[k].i == i && s.ele[k].j == j)
                        cout << s.ele[k++].x << " ";
                    else 
                        cout << "0 ";
                }
                cout << "\n";
            }
            return os ;
        }


int main ()

{
    Sparse s1 (5,5,5);
    cin >> s1 ;
    cout << s1 ;
}

// #include <stdio.h>
// #include <math.h>
// #include <string.h>
// #include <stdlib.h>

// struct Element 
// {
//     int i ;
//     int j ;
//     int x ;
// };

// struct Sparse 
// {
//     int m ;
//     int n ;
//     int num ;
//     struct Element *ele ;
// };

// void create (struct Sparse *s)
// {
//     printf ("\nEnter Dimensions");
//     scanf ("%d%d",&s->m,&s->n);
//     printf ("\nNumber Of Non-Zero\n");
//     scanf ("%d",&s->num);

//     s->ele = (struct Element *)malloc(s->num*sizeof(struct Element));
//     printf ("\n Enter Non-Zero Elements\n");
//     for (int i = 0 ; i < s->num ; i++ )
//         scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
// }

// void display (struct Sparse s)
// {
//     int i , j , k = 0 ;
//     for (i = 0 ; i < s.m ; i++ ){
//         for (j = 0 ; j < s.n ; j++){
//             if (i == s.ele[k].i && j == s.ele[k].j)
//                 printf ("%d ",s.ele[k++].x);
//             else 
//                 printf ("0 ");
//         }
//         printf ("\n");
//     }
// }


// struct Sparse* add (struct Sparse* s1 , struct Sparse* s2)
// {
//     int i , j , k ;
//     i = j = k = 0 ;
//     struct Sparse* sum ;
//     sum = (struct Sparse*)malloc(sizeof(struct Sparse));
//     sum->ele = (struct Element*)malloc((s1->num + s2->num)*sizeof(struct Element));

//     while (i < s1->num && j < s2->num)
//     {
//         if (s1->ele[i].i < s2->ele[j].i)
//             sum->ele[k++] = s1->ele[i++];
//         else if (s1->ele[i].i > s2->ele[j].i)
//             sum->ele[k++] = s2->ele[j++] ; 
//         else 
//         {
//             if (s1->ele[i].j < s2->ele[j].j)
//                 sum->ele[k++] = s1->ele[i++];
//             else if (s2-> ele[j].j < s1->ele[i].j)
//                 sum->ele[k++] = s2->ele[j++];
//             else{
//                 sum->ele[k] = s1->ele[i++];
//                 sum->ele[k++].x += s2->ele[j++].x ; 
//             }
//         }
//     }

//     while ( i < s1-> num || j < s2->num )
//     {
//         if (i < s1->num)
//             sum->ele[k++] = s1->ele[i++];
        
//         else if (j < s2->num)
//             sum->ele[k++] = s2->ele[j++];
//     }

//     sum->m = s1->m ;
//     sum->n = s1->n ;
//     sum->num = k ;

//     return sum ;
// }

// int main ()

// {
//     struct Sparse s1 , s2 , *s3 ;
//     create (&s1);
//     create (&s2);

//     s3 = add(&s1 , &s2);
//     printf ("\nFirst Matrix\n");
//     display(s1);
//     printf ("\nSecond Matrix\n");
//     display(s2);
//     printf ("\nFsum Matrix\n");
//     display(*s3);


//     return 0 ;
// }

/*#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <string>
#include <stdbool.h>

using namespace std ;

char inputString [100];
int indexing = 0 ;
int temp ;
int romanSum = 0 ;

int romanEvaluation (char ch)
{
    int tempStorage ;
    if (ch == 'I')
        tempStorage = 1 ;
    else if (ch == 'V')
        tempStorage = 5 ;
    else if (ch == 'X')
        tempStorage = 10 ;
    else if (ch == 'L')
        tempStorage = 50 ;
    else if (ch == 'C')
        tempStorage = 100 ;
    else if (ch == 'D')
        tempStorage = 500 ;
    else if (ch == 'M')
        tempStorage = 1000;
    
    return tempStorage ; 
}   

int continuationDifference ()
{
    while (true){
        if (inputString[indexing+1] != inputString[indexing])
            break ;
        else 
            indexing++;
    }
    return indexing;
}

void continuationCounter()
{
    romanSum += romanEvaluation(inputString[indexing]);
    while (true)
    {
        if (inputString[indexing] != inputString[indexing+1])
        {
            //cout << "\n Indexing I am breaking is " << indexing ;
            break ;
        }
        else 
        {
            cout << "\n Summing up " << inputString[indexing];
            romanSum += romanEvaluation(inputString[indexing]);
            ++indexing;
        }
    }
    if (inputString[indexing+1] != '\0')
    {
        if (romanEvaluation(inputString[indexing]) > romanEvaluation(inputString[++indexing]))
        {
            temp = indexing ;
            int alphacheck = continuationDifference();
            cout << "\n Next Brekage point is " << indexing ;
            if (romanEvaluation(inputString[indexing+1]) > romanEvaluation(inputString[indexing]))
            {
                romanSum = romanSum + romanEvaluation(inputString[indexing+1])-romanEvaluation(inputString[indexing]);
            }
            else {
                indexing = temp ;
            continuationCounter();
            }//cout << "\nRoman SUm is " << romanSum;
        }
        else {
            
            continuationCounter();
        }
    }
    else {
        romanSum += romanEvaluation(inputString[indexing]);
    }
}

int main ()

{
    printf ("\nPlz Enter the String\n");
    scanf ("%s",inputString);
    continuationCounter();
    cout << "\nroman sum is " << romanSum ;
}
*/
// #include <iostream>
// #include "DeepankarJainHeader.h"
// #include <math.h>

// using namespace std ;

// int main ()

// {
//     Student raj ;
//     Student deepankar (1,"Deepankar");
//     cout << raj.display() << "\n";
//     cout << deepankar.display() << "\n";
//     raj = deepankar ;
//     cout << raj.display() <<"\n";
//     //cout << deepankar.display();
//     return 0 ;
// }

// #include <iostream>
// #include <stdio.h>
// #include <math.h>
// #include "DeepankarJainHeader.h"

// using namespace std ;

// int main ()

// {
//     Student balu ;
//     Student raj (500);
//     cout << balu <<"\n";
//     cout << raj <<"\n";
//     return 0 ;  
// }

// #include <stdio.h>
// #include <iostream>
// #include <math.h>
// #include "DeepankarJainHeader.h"

// using namespace std ;

// //Account Account :: oper

// int main ()
// {
//     Account aju ;
//     aju.setBalance(500);
//     cout <<aju.display();
//     cout << (aju++).display();
//     cout << (++aju).display () << "\n";
// }







    // Account aju , antony , prince ;
    // aju.setBalance(500);
    // cout << aju.display();
    // aju++;//aju = aju+1 ; // floati = int(i) ;
    // cout << aju.display() ;
    // cout << (aju++).display();
    // cout<< aju.display();
    // antony.setBalance(600);
    // cout << "\n Antony balance \n" << antony.display();
    // ++antony ;
    // cout << antony.display();
   

// #include <iostream>
// using namespace std ;

// class Base {
//     public : void disp()
//     {
//     cout <<"\nBase Clases display ";

//     }
//     virtual void show ()
//     {
//         cout << "\n Base Class Show";
//     }
// };

// class Derived : public Base {
//     public :
//     void disp ()
//     {
//         cout << "Derived class Derived";
//     }
//     void show ()
//     {
//         cout << "Derived Class Show";
//     }
// };

// int main ()

// {
//     Base *p ;
//     Base objb ;
//     Derived objd ;
//     p = &objb ;
//     p->disp();
//     p->show();
//     p = &objd ;
//     p->disp();
//     p->show();

//     return 0 ;
// }

//Pointer to Derived Claass

// #include <iostream>

// using namespace std ;

// class Base 
// {
//     protected :
//     int b ;
//     public :
//     void setb (int x)
//     {
//         b = x ;
//     }
//     void disp ()
//     {
//         cout << "\nBase Class \n";
//         cout << "\n\t value of b" << b ; 
//     }
// };

// class Derived : public Base 
// {
//     int d ;
//     public :
//     void setd(int y)
//     {
//         d = y;
//     }
//     void disp ()
//     {
//         cout << "\n Derived Class \n";
//         cout << "\n Value of B is " << b ;
//         cout << "\n Value of D is "<< d;
//     }
// };

// int main ()

// {
//     Base *bp ;
//     Base b ;
//     bp = &b ;
//     bp->setb(100);
//     cout << "\nBP points to Base Object";
//     bp->disp();
//     Derived d ;
//     bp = &d ;
//     bp->setb(202);
//     cout << "\nBP points to Derived Object";
//     bp->disp();
//     Derived *dp ;
//     dp = &d ;
//     dp->setd (500);
//     cout << "\nDerived Type Pointer\n";
//     dp->disp();
//     ((Derived*)bp)->setd(211);
//     ((Derived*)bp)->disp();
//     return 0 ;
// }

// #include <bits/stdc++.h> 
// using namespace std; 
  
// // base class 
// class Parent 
// {    
//     // protected data members 
//     protected: 
//     int id_protected; 
//     public :
//     virtual :id_protected ;
//     void displayId() 
//     { 
//         cout << "id_protected is: " << id_protected << endl; 
//     }   
// }; 
  
// // sub class or derived class 
// class Child : public Parent 
// { 
     
      
//     public: 
//     void setId(int id) 
//     { 
          
//         // Child class is able to access the inherited  
//         // protected data members of base class 
          
//         id_protected = id; 
          
//     } 
      

// };

// // main function 
// int main() { 
      
//     Child obj1; 
      
//     // member function of the derived class can 
//     // access the protected data members of the base class 
//    //obj1.id_protected = 12;  
//     obj1.setId(81); 
//     obj1.displayId(); 
//     return 0; 
// } 

// #include <iostream>
// #include <math.h>

// using namespace std ;

// class Test 
// {
//     int data ;
//     public :
//     Test (){
//         data = 0 ;
//     }
//     int getData ()
//     {
//         return data ;
//     }
// };

// int main ()

// {
//     Test t ;
//     int *ptr = (int*)&t ;
//     *ptr = 10 ;
//     cout << t.getData();
//     return 0 ;
// }

//  #include <iostream>

// using namespace std ;

// class ArrayList 
// {
//     struct ControlBlock 
//     {
//         int capacity ;
//         int *arr_ptr ;
//     };
//     ControlBlock *s ;
//     public :
//     ArrayList (int capacity )
// };
// // #include <stdio.h>
// // #include <math.h>

// // using namespace std ;

// // template <class X>
// // X big (X a , X b )
// // {
// //     if (a>b){
// //         //cout << "I got \n" << a ;
// //         return a ;}
// //     else {
// //        // cout << "I got \n" << a ;
// //         return b ;}
// // }

// // int main ()

// // {
// //     cout << big(3,4);
// //     cout << big(3.4,5.6);
// //     return 0 ;
// // }


// template <class X ,class Y>
// X add (X first , Y Second )
// {
//     return first+Second ;
// }

// int main ()

// {
//     //class T tan;
//     std::cout << add(2,12.21);
//     return 0 ;
// }

// #include <iostream>
// #include <math.h>
// #include <stdio.h>

// using namespace std ;

// class Account 
// {
//     int balance ;
//     //static int users ;
//     public :
//     static int users ;
//     Account ();
//     ~Account();
//     static int getUsers ();
// };

// int Account :: getUsers ()
// {
//     return Account::users ;
// }

// Account :: Account ()
// {
//     users++;
//     this->balance = 0 ;
//     //cut << users ;
// }

// Account :: ~Account ()
// {
//     users--;
//     cout << "Destructor Called\n";
// }
// int Account :: users = 0 ;

// int main ()

// {
//     Account B1 ,B2 ;
//     cout << "\n"<< Account::users ;
//     B1.~Account();
//     B2.~Account();
//     cout << "\n bro is " << Account::getUsers();
// //    cout << "\n Enter \n" << sizeof(short int);
// //    cout << "\n " << sizeof(int);
//     return 0 ;
// }

// #include <iostream>
// class Test
// {
// public:
//     int i;
//     void get();
// };
// void Test::get()
// {
//     std::cout << "Enter the value of i: ";
//     std::cin >> i;
// }
// Test t;  // Global object
// int main()
// {
//     Test t;  // local object
//     t.get();
//     std::cout << "value of i in local t: "<<t.i<<'n';
//     ::t.get(); 
//     std::cout << "value of i in global t: "<<::t.i<<'n';
//     return 0;
// }

// #include <iostream>
// #include <stdio.h>
// #include <math.h>

// using namespace std ;

// class Account 
// {
//     int balance ;
//     public :
//     Account(){
//         this->balance = 0 ;
//     }
//     Account(int balance){
//         this->balance = balance ;
//     } 
//     friend ostream operator << (ostream &mycout  , Account &a )
//     {
//         mycout << "Balance" << a.balance;
//     }
// };


// int main ()

// {
//     Account balu ;
//     Account raj (500);
//     cout << balu <<"\n";
//     cout << raj <<"\n";
//     return 0 ;  
// }





















// // #include <iostream>
// // #include <stdio.h>
// // #include <math.h>

// // using namespace std ;

// // class Student 
// // {
// //     int regNo ;
// //     string name ;
// //     public :
// //     Student ();
// //     string operator ++();// PreFix Increment
// //     string operator ++(int);// PostFlix Increment 
// // };

// // Student :: Student ()
// // {
// //     regNo = 0 ;
// //     name = "NULL";
// // }

// // string Student :: operator++()
// // {
// //     cout << "\nThis is Pre-Incremented\n";
// //     this->regNo += 1;
// //     return "Name " + this->name + " RegNo " + to_string(this->regNo) ;
// // }

// // string Student :: operator ++(int)
// // {
// //     cout << "\nThis is Post-Incremented\n";
// //     this->regNo = this->regNo + 5 ;
// //     return "Name " + this->name + " RegNo " + to_string(this->regNo++) ;
// // }

// // int main ()

// // {
// //     Student Varun ;
// //     cout << ++Varun ;
// //     cout << Varun++ <<"\n";
// //     return 0 ;
// // }
// // // #include <iostream>
// // #include <stdio.h>
// // #include <math.h>

// // using namespace std ;

// // class Faculty 
// // {
// //     string name ;
// //     string dept ;
// //     public :
// //     string display ();
// //     string display (string);
// //     string display (string , string );
// // };

// // string Faculty :: display ()
// // {
// //     this->name = "Unassigned";
// //     this->dept = "Unassigned";
// //     return this->name + " " + this->dept ;
// // }

// // string Faculty :: display (string name)
// // {
// //     this->name = name ;
// //  //   cout << "I am trying " <<this->dept<<"\n" ;
// //     return this->name + " " + this->dept ;
// // } 

// // string Faculty :: display (string name , string dept)
// // {
// //     this->name = name ;
// //     this->dept = dept ;
// //     return this->name + " " + this->dept ;
// // }

// // int main ()

// // {
// //     Faculty guru , john , vicky ;
// //     cout << guru.display ()<<"\n";
// //     cout << john.display ("John")<<"\n";
// //     cout << vicky.display ("Vicky Ji","EEE")<<"\n";
// //     return 0 ;
// // }

// // #include <stdio.h>
// // #include <iostream>
// // #include <math.h>

// // using namespace std ;

// // int main ()

// // {
// //     return 0 ;
// //     cout << "Hello World\n";
// // }






























// // // class Student
// // // {
// // //     int regNo ;
// // //     //string name ;
// // // public :
// // //     Student ();
// // //     int operator ++();
// // //     void operator ++(int);
// // // };

// // // Student :: Student ()
// // // {

// // //     regNo = 0001 ;
// // //     //name = "rekha";
// // // }

// // // int Student :: operator++ () // Pre Increment
// // // {
// // //         ++this->regNo ;
// // //         return this->regNo ;
// // // }

// // // int Student :: operator++ (int){
// // //     this->regNo++ ;
// // //     return this->regNo ;
// // // }

// // // int main ()

// // // {
// // //     Student deepu;
// // //     deepu++;

// // //     /* int i = 6 ;
// // //     i++ ; // u + i+1 ;
// // //     cout << i << "\n";
// // //     cout << i++ << "\n";

// // //     cout << i ;
// // //     return 0 ;*/
// // // }


// // // #include <iostream>
// // // #include <math.h>
// // // #include <stdio.h>

// // // using namespace std ;

// // // class Student {
// // //     protected :
// // //     int regNo ;
// // //     string name ;
// // //     public :

// // //     void setRegNo (int inputRegNo, string inputName){
// // //         regNo = inputRegNo;
// // //         name = inputName ;
// // //     }
// // //     int getRegNo(){
// // //         return regNo ;
// // //     }
// // //     string getName (){
// // //         return name ;
// // //     }
// // // };

// // // class ChildStudent : protected Student 
// // // {
// // //     public :
// // //     void zone (){
// // //     cout << "\nSuccessfully Entered the zone\n";
// // //     cout << "\nHey There I can also access the stuff of Main class " << getRegNo() << getName();}
// // //     void setChildClassFunctions (int inputChildClassRegNo ,string inputChildClassName){
// // //         regNo = inputChildClassRegNo ; 
// // //         name = inputChildClassRegNo ; 
// // //     }
// // //     int getChildClassFunctionsgetRegNo (){
// // //         return regNo ;
// // //     }
// // //     string getChildClassFunctionsgetName (){
// // //         return name;
// // //     }
// // // };

// // // int main ()

// // // {
// // //     ChildStudent children ;
// // //     children.setRegNo (1234,"ABCDE");
// // //     cout << "\nHey THere 1st Call is " << children.getRegNo() << "\n" << children.getName() ; 
// // //     children.setChildClassFunctions (5678,"FGHIJK");
// // //     cout << "\nHey there , 2nd call is " << children.getChildClassFunctionsgetRegNo() << "\n" << children.getChildClassFunctionsgetName();
// // //    // cout << "\nHey there , 3rd and final call is "<< children.getRegNo() << children.getName();
// // //     return 0 ;
// // // }























// // // // #include <bits/stdc++.h> 
// // // // using namespace std; 
  
// // // // // base class 
// // // // class Parent 
// // // // {    
// // // //     // protected data members 
// // // //     protected: 
// // // //     int id_protected; 
// // // //     public :
// // // //    //virtual :id_protected ;
// // // //     void displayId() 
// // // //     { 
// // // //         cout << "id_protected is: " << id_protected << endl; 
// // // //     }   
// // // // }; 
  
// // // // // sub class or derived class 
// // // // class Child : public Parent 
// // // // { 
     
      
// // // //     public: 
// // // //     void setId(int id) 
// // // //     { 
          
// // // //         // Child class is able to access the inherited  
// // // //         // protected data members of base class 
          
// // // //         id_protected = id; 
          
// // // //     } 
      

// // // // };

// // // // // main function 
// // // // int main() { 
      
// // // //     Child obj1; 
      
// // // //     // member function of the derived class can 
// // // //     // access the protected data members of the base class 
// // // //    //obj1.id_protected = 12;  
// // // //     obj1.setId(81); 
// // // //     obj1.displayId(); 
// // // //     return 0; 
// // // // } 

// // // // // #include <iostream>
// // // // // #include <math.h>
// // // // // #include <string>

// // // // // using namespace std ;

// // // // // class Add {
// // // // //     int varX , varY ;
// // // // //     public :
// // // // //     int add (int varX , int varY );
// // // // //     float add (float varX , float varY );
// // // // //     string add (string varX , string varY);
// // // // //     double add (double varX , double varY);
// // // // // };

// // // // // int Add :: add (int varX , int varY ){
// // // // //     return varX + varY ;
// // // // // }

// // // // // float Add :: add (float varX , float varY ){
// // // // //     cout << "\nFLoat called\n";
// // // // //     return varX + varY ;
// // // // // }


// // // // // string Add :: add (string varX , string varY ){
// // // // //     return varX + varY ;
// // // // // }

// // // // // double Add :: add (double varX , double varY = 1.23456789 ){
// // // // //     cout << "\nDouble Called";
// // // // //     return varX + varY ;
// // // // // }


// // // // // int main ()

// // // // // {
// // // // //     Add object1 ;
// // // // //     cout.precision(10);
// // // // //     cout << object1.add(1,2);
// // // // //     cout << object1.add(1.00f,2.00f);
// // // // //     cout << object1.add("ONE","TWO");
// // // // //     cout << object1.add(1.23456789);
// // // // // }




// // // // // // #include <iostream>
// // // // // // #include <math.h>
// // // // // // #include <string>

// // // // // // using namespace std ;

// // // // // // class Student {
// // // // // //     int regNo ;
// // // // // //     //static int totalStudent ;
// // // // // //     public :
// // // // // //     static int totalStudent ;
// // // // // //     Student ();
// // // // // //     Student (int constructedInput);
// // // // // //     void setRegNo (int regNo);
// // // // // //     int getRegNo();
// // // // // //     static int displayTotalStudent();
// // // // // //     ~Student();
// // // // // // };

// // // // // //  int Student::totalStudent = 0 ;

// // // // // // Student :: Student(){
// // // // // //     Student::totalStudent++;
// // // // // //     regNo =  1111;
// // // // // // }

// // // // // // Student :: Student (int constructedInput){
// // // // // //     regNo = constructedInput;
// // // // // //     Student::totalStudent++;
// // // // // // }

// // // // // // void Student :: setRegNo (int regNo){
// // // // // //     this->regNo = regNo;
// // // // // // }

// // // // // // int Student :: getRegNo (){
// // // // // //     return regNo;
// // // // // // }

// // // // // // int Student :: displayTotalStudent(){
// // // // // //     return Student::totalStudent;
// // // // // // }

// // // // // // Student :: ~Student (){
// // // // // //     cout << "\nDestructor Called \n";
// // // // // //     Student::totalStudent--;
// // // // // // }

// // // // // // int main ()

// // // // // // {
// // // // // //     Student s1 ;
// // // // // //     Student *varun = new Student ();
// // // // // //     varun->setRegNo(199811);
// // // // // //     cout << varun->getRegNo() << "\n";
// // // // // //     cout << "\nHEY" << Student::displayTotalStudent() ; 
// // // // // //     delete varun ;
// // // // // //     varun->getRegNo();
// // // // // //     s1.setRegNo(1231);
// // // // // //     cout << s1.getRegNo() << "\n";
// // // // // //     cout << "\nHEY" << Student::displayTotalStudent() ; 
// // // // // // }



// // // // // // #include <iostream>
// // // // // // #include <math.h>
// // // // // // #include <string>
// // // // // // #include "DeepankarJainHeader.h"
// // // // // // using namespace std ;


// // // // // // int main ()

// // // // // // {
// // // // // //     Account krb , ant , balu ;
    
// // // // // //     Account *user1 = new Account () ;
// // // // // //     cout << "Total Number of Users are : " << Account :: getCountUser() ;
// // // // // //     cout << "\nTotal Amount in Bank is : " << Account :: getTotalBankAmount() ;
// // // // // //     cout << "\nPlz Enter the amount You Want to deposit in krb's account ";
// // // // // //     int inputAmountAnyUser ;
// // // // // //     cin >> inputAmountAnyUser ;
// // // // // //     krb.depositMoney (inputAmountAnyUser);
// // // // // //     cout << "\nPlz Enter the amount You Want to deposit in ant's account ";
// // // // // //     cin >> inputAmountAnyUser ;
// // // // // //     ant.depositMoney (inputAmountAnyUser);
// // // // // //     cout << "\nPlz Enter the amount You Want to deposit in balu's account ";
// // // // // //     cin >> inputAmountAnyUser ;
// // // // // //     balu.depositMoney (inputAmountAnyUser);
// // // // // //     cout << "\nPlz Enter the amount You Want to deposit in User's account ";
// // // // // //     cin >> inputAmountAnyUser ;
// // // // // //     user1->depositMoney (inputAmountAnyUser);
// // // // // //     cout << "\nTotal Amount in Bank is : " << Account :: getTotalBankAmount() ;
// // // // // //     cout << "\nThe Balance in Balu's Account is " << balu.getBalance() ;
// // // // // //     cout << "\nThe Balance in Ant's Account is " << ant.getBalance() ;
// // // // // //     cout << "\nThe Balance in Krb's Account is " << krb.getBalance() ;
// // // // // //     cout << "\nThe Balance in User's Account is " << user1->getBalance() ;
// // // // // //     cout << "\n Now Deleting the Dynamically Created User ... ";
// // // // // //     int sudoValueUser1 = user1->getBalance ();
// // // // // //     delete user1 ;
// // // // // //     cout << "\nThe User has been deleted and the Total count is : "<< Account::getCountUser();
// // // // // //     cout <<"\nthe total balance is " << Account::getTotalDeleted (sudoValueUser1);
// // // // // // }
