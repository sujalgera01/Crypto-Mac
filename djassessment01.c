// data Entry

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int front = -1 ;
int rear = -1 ;
int size ;
int inputArray[100] ;
char sudoArray [100][100] ; 

void append ()
{
    if (rear == size-1 )
    {
        printf ("\nStack Overflow");
        exit (-1);
    }
    else 
    {
        if (front == -1)
            front++;
        rear++;
    }
    printf ("\nPlz Enter the Registration Number :\n");
    char inputString [25] ;
    scanf ("%s",sudoArray[rear]);
    strcpy (inputArray,sudoArray[rear]);
    int stringlength = strlen (inputArray);
    //printf ("I got this %s ",inputArray);
    int checkElement = strncmp (inputArray,"19BBS",5);
    //printf ("the i o t %d " , checkElement );
    int counterCheckDigit = 0 ;
    for (int i = 5 ; i < 9 ; i++ )
    {
        if (!isdigit(inputArray[i]))
            counterCheckDigit++;
    }
    //printf ("\nCounter Check digit %d \n",counterCheckDigit);
   if (checkElement != 0 || stringlength > 9 && counterCheckDigit == 4 )
   {
       //printf ("\nEntered");
       {
       printf ("Exiting\n");
       exit (-1);}
   }
}

void pop ()
{
    if (front == size-1 )
    {
        printf ("Stack Underflow ");
        exit (-1);
    }
    else
        front++;
}

void display ()
{
    int i ;
    for ( i = rear ; i >= front ; --i )
        printf ("%s \n",sudoArray[i] );
}

void main ()

{
    printf ("\nPlease Enter the size of the array .\n");
    scanf ("%d",&size);
    int i ;
    for (i = 0 ;  ; i++ )
    {
        printf ("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        int choiceUser ;
        scanf ("%d",&choiceUser);
        if (choiceUser == 1 )
            append();
        else if (choiceUser == 2)
            pop ();
        else if (choiceUser == 3 )
            display();
        else if (choiceUser == 4 )
            exit (-1);
        else
        {
            printf ("Wrong Choice \n");
        }
        
    }
}
