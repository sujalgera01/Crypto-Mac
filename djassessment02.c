#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int a[10];
char stringArray [20][100];
int top = -1 ;
int  size ;
void push ()
{
    if (top == size-1 ){
        printf ("\nExiting");
        exit (-1);
    }
    char data[20] ;
    printf ("\nEnter the data :");
    scanf ("%s",data);
    int length = strlen (data);
    char sudoString [100];
    strcpy (sudoString,data);
    top++;
     int counterCheckDigit = 0 ;
    for (int i = 5 ; i < 9 ; i++ )
    {
        if (!isdigit(sudoString[i]))
            counterCheckDigit++;
    }
    int checkElement = (sudoString,"19BBS",5);
    if (checkElement != 0 && counterCheckDigit == 4 || length > 9)
    {
        printf ("\nExiting");
        exit (-1);        
    }
    strcpy (stringArray[top],sudoString);
}


void pop ()
{
    if (top == -1 )
        {
            printf ("Stack Underflow");
            exit (-1);
        }
        else
    top-- ;
}

void display ()
{
    int i ;
    for (i = top ; i >= 0 ; i-- )
        printf ("%s " ,stringArray[i] );
}

void main ()

{
    printf ("\n Enter the size of the array \n ");
    scanf ("%d",&size);
    int choice ;
    while (1)
    {
        printf ("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf ("%d",&choice);
        if (choice == 1)
            push();
        else if (choice == 2)
            pop();
        else if (choice == 3)
            display();
        else
            exit(-1);
    }
}

