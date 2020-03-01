#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int length = 0 ;

struct node
{
    struct node* right ;
    int data ;
    struct node* left ;
};

struct node* newNode(int data) 
{ 
    length++;
     struct node* node = (struct node*)malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
     return(node); 
} 

struct node* createNode (int element )
{
   // printf(" I am called \n");
    length++;
    struct node* temp ; 
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->left = NULL ;
    temp->right = NULL ;
    temp->data = element ;
    return temp ;
}

void inorderDisplay (struct node* p)
{
    if (p != NULL)
    {
        //printf ("\n Calling left \n");
        inorderDisplay(p->left);
        //printf("\nCalling Data\n");
        printf ("%d ",p->data);
        //printf("\nCalling Right\n");
        inorderDisplay(p->right);
    }
    else 
        return ;
}

void exchange (struct node* p , struct node* q )
{
    int temp = p->data ;
    p->data = q->data ;
    q->data = p->data ;
}

struct node* maxHeapify (struct node* p )
{
    struct node *largest ;
    int leftData = p->left->data ;
    int rightData = p->right->data ;
    if (leftData > p->data )
        largest = p->left ; 
    else 
        largest = p;
    if (rightData > largest->data )
    {
        largest = p->right ;
    }
    if (largest != p){
        // Exchange A[i]  And A[largest]
        exchange (p, largest);
        p = maxHeapify(p);
    }
}

void buildHeapSort (struct node* p)
{
    int i ;
    int heapSize = length ;
    for (i = (length/2)-1 ; i >= 0 ; i-- )
        p = maxHeapify(p);
    printf ("\nInside Build Heap Sort\n");
    inorderDisplay(p);
}




void main ()

{
    struct node *root  = newNode(10); 
    root->left             = newNode(5); 
    root->right           = newNode(12); 
    root->left->left     = newNode(20); 
    root->left->right   = newNode(30);
    root->left->left->left = newNode(6);
    root->right->left = newNode(6);
    root->right->right = newNode(15);  
    printf  ("\n The list looks like \n");
    inorderDisplay(root);
    buildHeapSort(root);


    // int inputArray [] = {5,2,4,3,1};
    // selectionSort(inputArray,5);
    // for (int i = 0 ; i < 5 ; i++ )
    //     printf ("%d ",inputArray[i]);
}
/*#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void swap (int *a , int *b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

void insertionSort (int inputArray [] , int size )
{
    int i , j ;
    j = 1 ;
    int key ;
    for (j = 1 ; j < size ; j++)
    {
        key = inputArray[j] ;
        i = j-1 ;
        while (inputArray[i] > key && i >= 0)
        {
            inputArray[i+1] = inputArray[i] ; 
            i-- ;
        }
        inputArray[i+1] = key ;
    }
}

void selectionSort (int inputArray [] , int size )
{
    int i , j ;
    for (j = 0 ; j < size-1 ; j++ )
    {
        int min = j ;
        for ( i = j+1 ; i < size ; i++ )
        {
            if (inputArray[min] > inputArray[i])
                min = i ;
        }
        swap(&inputArray[min],&inputArray[j]);
    }
}
void swap (int *element1 , int *element2 )
{
    int temp = *element1 ;
    *element1 = *element2 ;
    *element2 = temp ;
}

void selectionSort (int inputArray [] , int size )
{
    int i , j ;
    for ( j = 0 ; j < size-1 ; j++)
    {
        int min = j ;
        for (i = j+1 ; i < size ; i++ )
        {
            if (inputArray[min] > inputArray[i])
                min = i ;
        }
        swap (&inputArray[min],&inputArray[j]);
    }
}

void insertionSort (int inputArray [] ,int size )
{

    int i , j ;
    for (j = 1 ; j < size ; j++ )
    {
        int key = inputArray[j];
        i = j-1 ;
        while ( i >= 0 && inputArray[i] > key )
        {
            inputArray[i+1] = inputArray[i];
            i--;
        }
        inputArray[i+1] = key ;
    }
}

void display (int inputArray [] ,int size )
{
    int i ;
    for (i = 0 ; i < size ; i++ )
        printf ("%d ",inputArray[i]);
}

void main ()

{
    int size = 5 ;
    int inputArray[] = {5,2,4,3,1};
    // Insertion Sort 
    //insertionSort(inputArray,size);
    selectionSort(inputArray,size);
    display (inputArray , size );
}

/*
//#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
//#include <string>

//using namespace std ;

char inputString [100];
int integerConverted [100];
int indexInputString = 0 ;
int indexIntegerConverted = 0;

int convertInteger ()
{
    if (inputString[indexInputString] == '1')
        return 1 ;
    else if (inputString[indexInputString] == '2')
        return 2 ;
        if (inputString[indexInputString] == '3')
        return 3 ;
    else if (inputString[indexInputString] == '4')
        return 4 ;
            if (inputString[indexInputString] == '5')
        return 5 ;
    else if (inputString[indexInputString] == '6')
        return 6 ;
            if (inputString[indexInputString] == '7')
        return 7 ;
    else if (inputString[indexInputString] == '8')
        return 8 ;
            if (inputString[indexInputString] == '9')
        return 9 ;
    else if (inputString[indexInputString] == '0')
        return 0 ;
}

void applyInput ()
{
    printf ("\nPlz Enter Postfix Expression to be evaluated in Space Form \n");
    gets (inputString);
    for (indexInputString ; inputString[indexInputString] != '\0' ; indexInputString+=2 )
    {
        if (inputString[indexInputString] == '-' )
        {
            
        }


        if (isdigit(inputString[indexInputString]) != 0 ){
            int temp = convertInteger();
            printf ("%d themp si  " , temp );
            integerConverted[indexIntegerConverted] = temp ;
            printf ("\n %d is the alue" , integerConverted[indexIntegerConverted]);
            indexIntegerConverted++;

        }
        else if (inputString[indexInputString] == '+' || inputString[indexInputString] == '-' || inputString[indexInputString] == '*') 
        {
            if (indexIntegerConverted >= 2){
                if (inputString[indexInputString] == '+'){
                    integerConverted[indexIntegerConverted-2] = integerConverted[indexIntegerConverted-2]+integerConverted[indexIntegerConverted-1];
                }

                if (inputString[indexInputString] == '-'){
                    integerConverted[indexIntegerConverted-2] = integerConverted[indexIntegerConverted-2]-integerConverted[indexIntegerConverted-1];
                }

                if (inputString[indexInputString] == '*'){
                    integerConverted[indexIntegerConverted-2] = integerConverted[indexIntegerConverted-2]*integerConverted[indexIntegerConverted-1];
                }

                // if (inputString[indexInputString] == '/'){
                //     integerConverted[indexInputString-2] = integerConverted[indexInputString-2]/integerConverted[indexInputString-1];
                // }

                // if (inputString[indexInputString] == '^'){
                //     integerConverted[indexInputString-2] = pow(integerConverted[indexInputString-2],integerConverted[indexInputString-1]);
                // }
            }
            printf ("\nThe Answer is %d",integerConverted[indexIntegerConverted-2]);
            indexIntegerConverted = indexIntegerConverted-2+1 ;
        }
    }
}


int main () 

{
    applyInput();
    return 0;
}
// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #include <string.h>
// #include <iostream>
// #include <string>

// using namespace std ;

// char inputString[100];
// char sudoStackInputString[100] ;
// char stackOperators[100];
// //int stackOutput [100];
// int integerStackOutput [100] ;
// int indexInputString = 0 ;
// int indexIntegerStackOutput = 0 ;
// int indexStackOperator = 0 ;

// void display ();
// void check ()
// {
//      if (indexIntegerStackOutput > 2 && stackOperators[--indexStackOperator])
//     {
//     cout << "I have entered";
//      if (stackOperators[indexStackOperator] == '+')
//      {
//     integerStackOutput[indexIntegerStackOutput-2] =
//     integerStackOutput[indexIntegerStackOutput-2] + integerStackOutput[indexIntegerStackOutput-1];
//     indexIntegerStackOutput = 1 ;
//     }
//  if (stackOperators[indexStackOperator] == '*')
//  {
//  integerStackOutput[indexIntegerStackOutput-2] =
// integerStackOutput[indexIntegerStackOutput-2] * integerStackOutput[indexIntegerStackOutput-1];
//  indexIntegerStackOutput = 1 ;
//  }
//  if (stackOperators[indexStackOperator] == '-')
//  {
//  integerStackOutput[indexIntegerStackOutput-2] = 
// integerStackOutput[indexIntegerStackOutput-2] - integerStackOutput[indexIntegerStackOutput-1];
//  indexIntegerStackOutput = 1 ;
//  }
//  if (stackOperators[indexStackOperator] == '/')
//  {
//  integerStackOutput[indexIntegerStackOutput-2] = int
// (integerStackOutput[indexIntegerStackOutput-2] / integerStackOutput[indexIntegerStackOutput1]);
//  indexIntegerStackOutput = 1 ;
//  }
//  if (stackOperators[indexStackOperator] == '^')
//  {
//  integerStackOutput[indexIntegerStackOutput-2] = pow
// (integerStackOutput[indexIntegerStackOutput-2],integerStackOutput[indexIntegerStackOutput-1]);
//  indexIntegerStackOutput = 1 ;
//  }
//  cout << "Hey I am there \n";
//  display();
//  }
// }
// void display ()
// {
//  printf ("\nInteger Stack Output is\n");
//  int i ;
//  for ( i = 0 ; i < indexIntegerStackOutput ; i++ )
//  printf ("%d " ,integerStackOutput[indexIntegerStackOutput]);
//  cout <<"\n";
//  // for ( i = 0 ; i < indexStackOperator ; i++ )
//  // printf ("%c " ,stackOperators[indexStackOperator]);

// }
// int change()
// {
//  //cout << "\nEntered\n";
//  if (inputString[indexInputString] == '0')
//  return 0 ;
//  if (inputString[indexInputString] == '1')
//  return 1 ;
//  if (inputString[indexInputString] == '2')
//  return 2 ;
//  if (inputString[indexInputString] == '3')
//  return 3 ;
//  if (inputString[indexInputString] == '4')
//  return 4 ;
//  if (inputString[indexInputString] == '5')
//  return 5 ;
//  if (inputString[indexInputString] == '6')
//  return 6 ;
//  if (inputString[indexInputString] == '7')
//  return 7 ;
//  if (inputString[indexInputString] == '8')
//  return 8 ;
//  if (inputString[indexInputString] == '9')
//  return 9 ;
// }
// void input ()
// {
//  printf ("\nPlz Enter the Space Generated PostFix Expression \n");
//  gets (inputString);
//  //scanf("%s",inputString);
//  int i = 0 ;
//  for (indexInputString ; inputString[indexInputString] != '\0' ; indexInputString =
// indexInputString+2 )
//  {
//  int element;
//  if (inputString[indexInputString] == '-')
//  {
//  indexInputString++;
//  int element = change();
//  element = 0-element ;
//  integerStackOutput[indexIntegerStackOutput] = element ;
//  }
//  if (isdigit(inputString[indexInputString]))
//  {
//  //cout << "\nEntered\n";
//  // cout << "inputString" << int (inputString[indexInputString]);
//  //cout <<"\n";
//  int temp = change ();
//  integerStackOutput[indexIntegerStackOutput] = temp ;
//  //cout << "Integer stack u is \n" << integerStackOutput[indexIntegerStackOutput] << "Thevalue of indexInteger is "<< indexIntegerStackOutput; indexIntegerStackOutput++;
//  //cout <<"\n";
//  //cout << indexIntegerStackOutput;
//  // display();
//  }
//  //check ();
//  if (inputString[indexInputString] == '+' || inputString[indexInputString] == '-' ||inputString[indexInputString] == '*' || inputString[indexInputString] == '/' ||inputString[indexInputString] == '^' )
//  {
//  cout << inputString[indexInputString];
//  stackOperators[indexStackOperator] = inputString[indexInputString] ;
//  //cout << "\nstackoperatrs is " << stackOperators[indexStackOperator] << "\n";
//  indexStackOperator++;
//  }
//  //check ();
//  if (indexIntegerStackOutput == 2 && stackOperators[indexStackOperator-1])
//  {
//  //cout << "I have entered";
//  cout << "\n I got " << stackOperators[indexStackOperator-1];
//  if (stackOperators[indexStackOperator-1] == '+')
//  {
//  integerStackOutput[indexIntegerStackOutput-2] =
// integerStackOutput[indexIntegerStackOutput-2] + integerStackOutput[indexIntegerStackOutput-1];
//  indexIntegerStackOutput = 1 ;
//  }
//  if (stackOperators[indexStackOperator-1] == '*')
//  {
//  //cout << "I am here \n";
//  //cout << integerStackOutput[indexIntegerStackOutput-2] *
// integerStackOutput[indexIntegerStackOutput-1];
//  integerStackOutput[indexIntegerStackOutput-2] =
// integerStackOutput[indexIntegerStackOutput-2] * integerStackOutput[indexIntegerStackOutput-1];
//  indexIntegerStackOutput = 1 ;
//  }
//  if (stackOperators[indexStackOperator-1] == '-')
//  {
//  integerStackOutput[indexIntegerStackOutput-2] =
// integerStackOutput[indexIntegerStackOutput-2] - integerStackOutput[indexIntegerStackOutput-1];
//  indexIntegerStackOutput = 1 ;
//  }
//  if (stackOperators[indexStackOperator-1] == '/')
//  {
//  integerStackOutput[indexIntegerStackOutput-2] = int
// (integerStackOutput[indexIntegerStackOutput-2] / integerStackOutput[indexIntegerStackOutput1]);
//  indexIntegerStackOutput = 1 ;
//  }
//  if (stackOperators[indexStackOperator-1] == '^')
//  {
//  integerStackOutput[indexIntegerStackOutput-2] = pow
// (integerStackOutput[indexIntegerStackOutput-2],integerStackOutput[indexIntegerStackOutput-1]);
//  indexIntegerStackOutput = 1 ;
//  }
//  cout << "Hey the answer is \n" << integerStackOutput[0];
//  //display();
//  }
//  // display ();
//  }
// }
// int main ()
// {
//  input();
//  return 0 ;
// }

// /*/
// Implementing Tree Concept in C 
// #include <stdio.h>
// #include <stdlib.h>
// #include "DeepankarJainHeader.h"

// struct Node *root = NULL ;

// void Treecreate ()
// {
//     struct Node *p , *t ;
//     int x ;
//     struct Queue q ;
//     create (&q , 100);

//     printf ("\nEnter the Root Value \n");
//     scanf("%d",&x);
//     root = (struct Node*)malloc(sizeof(struct Node));
//     root->data = x ;
//     root->lchild = root->rchild = NULL ;
//     enQueue(&q,root);
//     while (!isEmpty(q))
//     {
//         p = deQueue(&q);//why???????
//         printf ("\nEnter the left child of %d ", p->data);
//         scanf ("%d",&x);
//         if (x != -1)
//         {
//             t = (struct Node*)malloc(sizeof(struct Node));
//             t->data = x ;
//             t->lchild = t->rchild = NULL ;
//             p->lchild = t ;
//             enQueue(&q,t);
//         }
//         printf ("\nEnter the Right child of %d",p->data);
//         scanf ("%d",&x);
//         if (x != -1)
//         {
//             t = (struct Node*)malloc(sizeof(struct Node));
//             t->data = x ;
//             t->rchild = t->lchild = NULL;
//             p->rchild = t ;
//             enQueue(&q,t);
//         }

//     }
// }

// void preorder (struct Node* p)
// {
//     if (p)
//     {
//         printf ("%d ",p->data);
//         preorder(p->lchild);
//         preorder(p->rchild);
//     }
// }

// int main ()

// {
//     Treecreate ();
//     preorder(root);
//     return 0 ;
// }
/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ;
    struct node* right ;
    struct node* left ;
};

struct node* createNode (int element )
{
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp->left = NULL ;
    temp->data = element ;
    temp->right = NULL ;
}

void inorderDisplay (struct node* root )
{
    if (root == NULL)
        return ;
    else 
    {
        inorderDisplay (root->left);
        printf ("%d ",root->data);
        inorderDisplay (root->right);
    }
}

void preOrderDisplay (struct node* root )
{
    if (root == NULL )
        return ;
    else{
        printf ("%d ",root->data);
        preOrderDisplay(root->left);
        preOrderDisplay(root->right);
    }
}

void postOrderDisplay (struct node* root )
{
    if (root == NULL )
        return ;
    else {
        preOrderDisplay(root->left);
        preOrderDisplay(root->right);
        printf ("%d ",root->data);
    }
}

void main ()

{
    struct node* root ;
    root = createNode (1);
    root->left = createNode(2);
    root->right = createNode(3);
    inorderDisplay(root);
    printf ("\n Pre Order ");
    preOrderDisplay(root);
    printf ("\nPost Order ");
    postOrderDisplay(root);
}

// /*#include <stdio.h>
// #include <math.h>
// #include <stdlib.h>

// struct node
// {
//     int data ;
//     struct node* link ;
// };

// struct node* root = NULL ;

// void createNode ()
// {
//     printf ("\nEnter The elements in linked list \n");
//     int inputElement ;
//     scanf ("%d",&inputElement);
//     struct node* temp ;
//     temp = (struct node*)malloc(sizeof(struct node*));
//     temp->data = inputElement ;
//     temp->link = NULL ;
//     if (root == NULL)
//         root = temp ;
//     else {
//         struct node* p ;
//         p = root ;
//         while (p->link != NULL)
//             p = p->link ;
//         p->link = temp ;
//         //printf ("\nSuccess");
//     }

// }

// void display ()
// {
//     struct node* p ;
//     p = root ;
//     while (p != NULL){
//         printf ("%d-->",p->data);
//         p = p->link ;
//     }
// }

// void reverseLinkedList ()
// {
//     struct node* p ;
//     struct node* q ;
//     struct node* r ;
//     q = NULL ;
//     r = NULL ;
//     p = root ;
//     while (p != NULL ){
//         r = q ;
//         q = p ;
//         p = p->link ;
//         q->link = r ;
//     }
//     root = q ;
// }

// void main ()

// {
//     for (int i = 0 ; i < 5 ; i++ )
//         createNode();
//     reverseLinkedList();
//         display();
// }

// // #include <stdio.h>

// // #define ROW 3
// // #define COL 3


// // /* Function declarations */
// // void matrixInput(int mat[][COL]);
// // void matrixPrint(int mat[][COL]);
// // void matrixMultiply(int mat1[][COL], int mat2[][COL], int res[][COL]);



// // int main()
// // {
// //     int mat1[ROW][COL];
// //     int mat2[ROW][COL];
// //     int product[ROW][COL];


// //     /*
// //      * Input elements in matrices.
// //      */
// //     printf("Enter elements in first matrix of size %dx%d\n", ROW, COL);
// //     matrixInput(mat1);

// //     printf("Enter elements in second matrix of size %dx%d\n", ROW, COL);
// //     matrixInput(mat2);


// //     // Call function to multiply both matrices
// //     matrixMultiply(mat1, mat2, product);


// //     // Print product of both matrix
// //     printf("Product of both matrices is : \n");
// //     matrixPrint(product);

// //     return 0;
// // }



// // /**
// //  * Function to input elements in matrix from user.
// //  *
// //  * @mat     Two-dimensional array to store user input.
// //  */
// // void matrixInput(int mat[][COL])
// // {
// //     int row, col;

// //     for (row = 0; row < ROW; row++)
// //     {
// //         for (col = 0; col < COL; col++)
// //         {
// //             // printf ("\nthe pointer to mat + row is %u",(mat+row));
// //             // printf ("\n If I used & then expression is %u ",(mat + row)+col );
// //              scanf("%d", (*(mat + row) + col));
// //         }
// //     }
// // }




// // /**
// //  * Function to print elements in a two-dimensional array.
// //  *
// //  * @mat     Two-dimensional array to print.
// //  */
// // void matrixPrint(int mat[][COL])
// // {
// //     int row, col;

// //     for (row = 0; row < ROW; row++)
// //     {
// //         for (col = 0; col < COL; col++)
// //         {
// //             printf("%d ", *(*(mat + row) + col));
// //         }

// //         printf("\n");
// //     }
// // }




// // /**
// //  * Function to multiply two matrices.
// //  *
// //  * @mat1    First matrix
// //  * @mat2    Second matrix
// //  * @res     Resultant matrix to store product of both matrices.
// //  */
// // void matrixMultiply(int mat1[][COL], int mat2[][COL], int res[][COL])
// // {
// //     int row, col, i;
// //     int sum;


// //     for (row = 0; row < ROW; row++)
// //     {
// //         for (col = 0; col < COL; col++)
// //         {
// //             sum = 0;

// //             /*
// //              * Find sum of product of each elements of 
// //              * rows of first matrix and columns of second 
// //              * matrix.
// //              */
// //             for (i = 0; i < COL; i++)
// //             {
// //                 sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
// //             }


// //             /* 
// //              * Store sum of product of row of first matrix 
// //              * and column of second matrix to resultant matrix.
// //              */
// //             *(*(res + row) + col) = sum;
// //         }
// //     }
// // }

// // /* Histogram of Frequency of Different Characters in Input */

// // #include<stdio.h>
// // #define TNOCHAR 128  /* Total Number of characters is 128: 0 - 127 */
// /*
// int main(void)
// {
//     int c,i,j;

//     int character[TNOCHAR];
    
//     for(i=0;i<TNOCHAR;++i)
//         character[i] = 0;
    
//     while((c=getchar())!=EOF)
//         ++character[c];

//     for(i=0;i<TNOCHAR;++i)
//     {
//         putchar(i);
        
//         for(j=0;j<character[i];++j)
//             putchar('*');
        
//         putchar('\n');
//     }
// return 0;
// }

// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <math.h>

// // int main ()

// // {
// //     FILE *fp ;
// //     fp = fopen ("check.txt","r");
// //     char ch ;
// //     char storingArray [100][100];
// //     int top = 0;
// //     int counterColumn = 0 ;

// //     while (1)
// //     {
// //         ch = fgetc (fp);
// //         if (ch == EOF)
// //             break ;
// //         if (ch != ' ')
// //         {
// //             //printf ("%c",ch);
// //             storingArray[top][counterColumn] = ch ;
// //             //printf ("The array is %c\n",storingArray[top][counterColumn]);
// //            // printf ("\nThe top is %d and counterColum is %d and element is %c",top,counterColumn,storingArray[top][count]);
// //             counterColumn++;
// //         }
// //         if (ch == ' ')
// //         {
// //             //printf ("\n");
// //             storingArray[top][counterColumn] = '\0';
// //             //printf ("After this is %c",storingArray[top][counterColumn]);
// //            //printf ("The top is %d and counterColum is %d",top,counterColumn);
// //             top++;
// //             counterColumn = 0 ;
// //         }
// //     }

// //     printf ("The Array looks like this \n");
// //     for(int i = 0 ; i < top ; i++ )
// //         printf ("%s\n",storingArray[i]);
// //     return 0 ; 
// // }









// // #include <stdio.h>
// // #include <stdlib.h>
// // int main() {
// //     char sentence[1000];
// //     // creating file pointer to work with files
// //     FILE *fptr;
// //     // opening file in writing mode
// //     fptr = fopen("program.txt", "w");
// //     // exiting program 
// //     if (fptr == NULL) {
// //         printf("Error!");
// //         exit(1);
// //     }
// //     printf("Enter a sentence:\n");
// //     fgets(sentence, sizeof(sentence), stdin);
// //     fprintf(fptr, "%s", sentence);
// //     fclose(fptr);
// //     return 0;
// // }

// /* #include<stdio.h>
//     #include<stdlib.h>
//     //#include<conio.h>


//         void push(int);
//         void pop();
//         void display();
//     void peek();
//     int stack[10];
//     int top=-1;
//     int main()
//     {
//     while(1){
//     int value,choice;
//     printf("\nEnter choice\n");
//     printf("\n 1.PUSH 2.POP 3.DISPLAY 4.PEEK\n");
//     scanf("%d",&choice);
//     printf("Your Choice is:%d\n",choice);
//     switch(choice)
//     {

//         case 1:printf("Enter the value to insert");
//     scanf("%d",&value);
//     push(value);
//     break;
//         case 2:scanf("%d",&value);
//     pop();
//     break;

//         case 3:display();
//     break;
//     case 4: printf("Pick Element ");
//     scanf("%d",&value);
//     peek(value);
//         default :
//     printf("error!");
//     }
//     }
//     }
//     void push(int value){
//     if (top==10-1)
//     {
//     printf("stack overflow");
//     }
//     else
//     {
//     top++;
//     //printf("%d",top);
//     stack[top]=value;
//     printf("\n complete!\n"); 
//     }
//     }
//     void pop()
//     {
//     if (top==-1)
//     {
//         //printf("%d",top);
//         printf("stack underflow!");
//     }
//     else
//     {

//         printf("deleted! :%d",stack[top]);

//     top--;

//     }
//     }
// void peek(int x){
//     if (top==-1)
//     {
//     printf("no elements are to pick\n" );
//     }
//     else
// {
//     printf ("\n The element is %d",stack[x]);
//  //   x=stack[top];
//  }

//     }
//     void display()
//     {
//     int i;

//     //printf("%d",top);
//     printf("YOU CHOICE IS DISPLAYING\n");

//     for (i=top;i>=0;i--)
//     {
//         printf("  %d,",stack[i]);

//     }
//     }


//     /*#include <stdlib.h>
//     #include <stdio.h>
//     #include <math.h>

//     struct node
//     {
//         struct node* right ;
//         int data ;
//         struct node* left;
//     };

//     struct node* createNode (int element )
//     {
//         struct node* temp ;
//         temp = (struct node*)malloc(sizeof(struct node*));
//         temp->data = element ;
//         temp->right = NULL ;
//         temp->left = NULL ;    
//         return temp ;
//     }

//     struct node* search (struct node* root ,int element)
//     {
//         if (root == NULL || root->data == element)
//             return root ;
//         else if (root->data > element )
//             return search (root->right , element );
//         else if (root->data < element )
//             return search (root->left , element );
//     }

//     void inorderDisplay (struct node* root )
//     {
//         if (root != NULL){
//             inorderDisplay (root->left);
//             printf ("\n%d",root->data);
//             inorderDisplay (root->right);
//         }
//         //printf ("\n%d",root->data);
//     }

//     void insert (struct node* root ,int element)
//     {
//         if (root == NULL)
//         {
//             root = createNode (element);
//             return ;
//         }
//         else if (element > root->data){
//             //printf ("\nInserted");
//             insert (root->right,element);
//             //return root->right = ;
            
//             }
//         else if (element < root->data){
//             //printf ("\nInserted");
//             insert (root->left , element );
//             //return root->left = 
            
//             }
//         //return root ;
//     }

//     int main ()

//     {
//         struct node* root = NULL ;
//         insert (root , 50);
//         insert (root , 30);
//         insert (root , 20);
//         insert (root , 40);
//         insert (root , 70);
//         insert (root , 60);
//         insert (root , 80);
//         printf("Hello!\n");
//         inorderDisplay (root);
//         return 0 ;
//     }

//     // #include <stdlib.h> 
//     // #include <stdio.h>
//     // #include <math.h>
    
//     // /* A binary tree node has data, pointer to left child 
//     //    and a pointer to right child */
//     // struct node 
//     // { 
//     //      int data; 
//     //      struct node* left; 
//     //      struct node* right; 
//     // }; 
    
//     // /* Helper function that allocates a new node with the 
//     //    given data and NULL left and right pointers. */
//     // struct node* newNode(int data) 
//     // { 
//     //      struct node* node = (struct node*) 
//     //                                   malloc(sizeof(struct node)); 
//     //      node->data = data; 
//     //      node->left = NULL; 
//     //      node->right = NULL; 
    
//     //      return(node); 
//     // } 
    
//     // /* Given a binary tree, print its nodes according to the 
//     //   "bottom-up" postorder traversal. */
//     // void printPostorder(struct node* node) 
//     // { 
//     //      if (node == NULL) 
//     //         return; 
    
//     //      // first recur on left subtree 
//     //      printPostorder(node->left); 
    
//     //      // then recur on right subtree 
//     //      printPostorder(node->right); 
    
//     //      // now deal with the node 
//     //      printf("%d ", node->data); 
//     // } 
    
//     // /* Given a binary tree, print its nodes in inorder*/
//     // void printInorder(struct node* node) 
//     // { 
//     //      if (node == NULL) 
//     //           return; 
    
//     //      /* first recur on left child */
//     //      printInorder(node->left); 
    
//     //      /* then print the data of node */
//     //      printf("%d ", node->data);   
    
//     //      /* now recur on right child */
//     //      printInorder(node->right); 
//     // } 
    
//     // /* Given a binary tree, print its nodes in preorder*/
//     // void printPreorder(struct node* node) 
//     // { 
//     //      if (node == NULL) 
//     //           return; 
    
//     //      /* first print data of node */
//     //      printf("%d ", node->data);   
    
//     //      /* then recur on left sutree */
//     //      printPreorder(node->left);   
    
//     //      /* now recur on right subtree */
//     //      printPreorder(node->right); 
//     // }     
    
//     // /* Driver program to test above functions*/
//     // int main() 
//     // { 
//     //      struct node *root  = newNode(1); 
//     //      root->left             = newNode(2); 
//     //      root->right           = newNode(3); 
//     //      root->left->left     = newNode(4); 
//     //      root->left->right   = newNode(5);  
    
//     //      printf("\nPreorder traversal of binary tree is \n"); 
//     //      printPreorder(root); 
    
//     //      printf("\nInorder traversal of binary tree is \n"); 
//     //      printInorder(root);   
    
//     //      printf("\nPostorder traversal of binary tree is \n"); 
//     //      printPostorder(root); 
    
//     //      getchar(); 
//     //      return 0; 
//     // } 

//     /* // C program to print reverse of a linked list 
//     #include<stdio.h> 
//     #include<stdlib.h> 

//     /* Link list node */
//     /*struct Node 
//     { 
//         int data; 
//         struct Node* next; 
//     }; 

//     /* Function to reverse the linked list */
//     /*void printReverse(struct Node* head) 
//     { 
//         // Base case 
//         if (head == NULL) 
//         return; 

//         // print the list after head node 
//         printReverse(head->next); 

//         // After everything else is printed, print head 
//         printf("%d ", head->data); 
//     } 

//     /*UTILITY FUNCTIONS*/
//     /* Push a node to linked list. Note that this function 
//     changes the head */
//     /*void push(struct Node** head_ref, char new_data) 
//     { 
//         /* allocate node */
//     /*	struct Node* new_node = 
//                 (struct Node*) malloc(sizeof(struct Node)); 

//         /* put in the data */
//     //	new_node->data = new_data; 

//         /* link the old list off the new node */
//     //	new_node->next = (*head_ref); 

//         /* move the head to pochar to the new node */
//     //	(*head_ref) = new_node; 
//     //} 

//     /* Drier program to test above function*/
//     //int main() 
//     //{ 
//         // Let us create linked list 1->2->3->4 
//     //	struct Node* head = NULL;	 
//     //	push(&head, 4); /
//     //	push(&head, 3); 
//     //	push(&head, 2); 
//     //	push(&head, 1); 
        
//     //	printReverse(head); 
//     //	return 0; 
//     //} 


//     /*#include <stdio.h>
//     #include <math.h>
//     #include <stdlib.h>

//     int inputArray [5];
//     int size = 9 ;
//     int front = -1 ;
//     int rear = -1 ;

//     void enQueue (int element){
//         if ((rear+1)%size == front){
//             printf ("\nStack Overflow\n");
//             exit(-1);
//         }
//         else if (front == -1)
//             front++;
//         rear = (rear+1)%size;
//         inputArray[rear] = element ;
//         printf ("\nSuccess And Element in the array is %d at position %d \n",inputArray[rear],rear);

//     }

//     void deQueue (){
//         if (front == -1){
//             printf ("\nStack Underflow\n");
//             exit (-1);
//         }
//         else if (front == rear){
//             front =-1 ;
//             rear = -1 ;
//         }
//         else {
//             front = (front+1)%size;
//         }
//     }

//     void displayQueue (){
//         if (front == -1){
//             printf ("No Possible \n");
//             exit (-1);
//         }
//         int i ;
//         for ( i = front ; i != rear ; i = (i+1)%size )
//             printf("%d-->",inputArray[i]);
//         printf ("%d",inputArray[i]);
//     }

//     void main ()

//     {
//     for (int k = 0 ; k <= 8 ; k++ )
//         printf (enQueue(k));
//     for (int k = 0 ; k <= 5 ; k++ )
//     {
//         printf (enQueue(deQueue());
//         printf(deQueue());
//         printf((deQueue());
//     }
//     }

//     /*#include <stdio.h>
//     #include <stdlib.h>
//     #include <math.h>

//     struct node
//     {
//         int data ;
//         struct node* link ;
//     };

//     struct node* root = NULL ;

//     void append ()
//     {
//         printf ("\nPlz Enter The Data for at the end insertion ");
//         struct node* temp ;
//         temp = (struct node*)malloc(sizeof(struct node*));
//         temp->link = NULL ;
//         scanf ("%d",&temp->data);
//         if (root == NULL)
//             root = temp ;
//         else{
//             struct node* p ;
//             p = root ;
//             while (p->link != NULL )
//                 p = p->link ;
//             p->link = temp ;
//         }
//     }

//     void AddBegin ()
//     {
//         printf ("\nPlz Enter The Data for the above held construction ");
//         struct node* temp ;
//         temp = (struct node*)malloc(sizeof(struct node*));
//         temp->link = NULL ;
//         scanf ("%d",&temp->data);

//         if (root == NULL)
//             root = temp ;
//         else{
//             temp->link = root ;
//             root = temp ;
//         }
//     }

//     int length ()
//     {
//         int len = 1 ;
//         struct node* p ;
//         p = root ;
//         while ( p->link != NULL)
//         {
//             len++;
//             p = p->link ;
//         }
//         return len ;
//     }

//     void display ()
//     {
//         struct node* p;
//         p = root ;
//         while (p->link != NULL){
//             printf ("%d-->",p->data);
//             p = p->link ;
//         }
//         printf ("%d",p->data);
//     }

//     void delete ()
//     {
//         struct node* p ;
//         p = root ;
//         int loc ;
//         printf ("\nEnter the Node Loc ");
//         scanf ("%d",&loc);
//         if (loc == 1)
//             root = p->link ;
//         else if (loc == length())
//         {
//             for (int i = 1 ; i < loc-1 ; i++ )
//                 p = p->link ;
//             p->link = NULL;
//         }
//         else 
//         {
//             for (int i = 1 ; i < loc-1 ; i++ )
//             p = p->link ;
//             struct node* q ;
//             q = p->link ;
//             struct node* l ;
//             l = q->link ;
//             q->link = NULL ;
//             p->link = l ;
//             free (q);
//             }
//     }

//     void addAnyPoint ()
//     {
//         struct node* p;
//         struct node* q;
//         struct node* temp;
//         temp = (struct node*)malloc(sizeof(struct node*));
//         temp->link = NULL ;
//         int loc ;
//         printf ("\n Enter the node of data insertion \n");
//             scanf("%d",&loc);  
//         p = root ;
        
//         if (loc == 1)
//             AddBegin();
//         else if (loc == length()){
//             //printf ("I got into the if statement for length = %d",length());
//             append();}
//         else {
//             printf ("\n Enter the data for Add At Any Point ");
//         scanf ("%d",&temp->data); 
//             for (int i = 1 ; i < loc-1 ; i++)
//                 p = p->link ;
//             q = p->link ;
//             temp->link = q ;
//             p->link = temp  ;
//         }
//     }

//     // void ReverseList ()
//     // {
//     //     struct node* p ;
//     //     struct node* q ;
//     //     int i = 0 ;
//     //     int j = length();
//     //     p = root ;
//     //     q = root ;
//     //     while ( i < j )
//     //     {
//     //         int loc = j ;
//     //         for (int k = 1 ; k < loc ;k++ )
//     //             q = q->link ;
//     //         int temp = p->data;
//     //         p->data = q->data;
//     //         q->data= temp ;
//     //         p = p->link ;
//     //         q = root ;
//     //         i++;
//     //         j--;
//     //     }
//     // }


//     void ReverseList (){
//         struct node* p ;
//         struct node* q ;
//         p = root ; 
//         q = root ;
//         int len = length();
//         for (int j = 0 , k = length()-1 ; j < k ; j++ , k--){
//         for (int i = j+1 ; i < len ; i++ ){
//             q= q->link ;
//         }
//         int temp = p->data ; 
//         p->data = q->data ;
//         q->data = temp ;
//         p = p->link ;
//         q = root ;
//     }
//     }

//     void main ()

//     {
//         append();
//         append();
//         append();
//         append();
//         append();
//         // display();
//         // delete();
//         // display();
//         // addAnyPoint ();
//         // display();
//         // addAnyPoint();
//         // display();
//         ReverseList();
//         printf ("\n");
//         display();
//     }
//     /*#include <stdio.h>
//     #include <math.h>
//     #include <stdlib.h>

//     struct node 
//     {
//         int coeff ;
//         int power ;
//         struct node* link ;
//     };

//     void createNode (int inputCoeff , int inputPower , struct node **temp)
//     {
//         struct node* p ;
//         struct node* q ;
//         q = *temp ;
//         if (q == NULL){
//             p = (struct node*)malloc(sizeof(struct node*));
//             p->coeff = inputCoeff ;
//             p->power = inputPower ;
//             *temp = p ; 
//             p->link = (struct node*)malloc(sizeof(struct node*));
//             p = p->link ;
//             p->link = NULL ;
//         }
//         else{
//             p->coeff = inputCoeff;
//             p->power = inputPower ;
//             p->link = (struct node*)malloc(sizeof(struct node*));
//             p = p->link ;
//             p->link = NULL ;
//         }
//     }

//     void polyAdd (struct node* poly1 , struct node* poly2 , struct node* poly3 ){
//         while (poly1->link && poly2->link){
//             if (poly1->power > poly2->power){
//                 poly3->power = poly1->power;
//                 poly3->coeff = poly1->coeff ;
//                 poly1 = poly1->link ;
//             }
//             else if (poly1->power < poly2->power){
//                 poly3->power = poly2->power ;
//                 poly3->coeff = poly2->coeff ;
//                 poly2 = poly2->link ;
//             }
//             else {
//                 poly3->power = poly1->power;
//                 poly3->coeff = poly1->coeff + poly2->coeff ;
//                 poly1 = poly1->link ;
//                 poly2 = poly2->link ;
//             }
//             poly3->link = (struct node*)malloc(sizeof(struct node*));
//             poly3 = poly3->link;
//             poly3->link = NULL ; 
//         }
//         while (poly1->link || poly2->link){
//             if (poly1->link){
//                 poly3->power = poly1->power ;
//                 poly3->coeff = poly1->coeff ;
//                 poly1 = poly1->link ;
//             }
//             else if (poly2->link){
//                 poly3->power = poly2->power ;
//                 poly3->coeff = poly2->coeff ;
//                 poly2 = poly2->link ;
//             }
//             poly3->link = (struct node*)malloc(sizeof(struct node*));
//             poly3 = poly3->link ;
//             poly3->link = NULL ;
//         }

//     }

//     void display (struct node* p){
//         while (p->link != NULL){
//             printf ("Coeff is %d and Power is %d ",p->coeff , p->power);
//             p = p->link ;
//         }
//         printf ("Coeff is %d and Power is %d ",p->coeff , p->power);
//     }

//     void main ()

//     {
//         struct node* poly1 = NULL ;
//         struct node* poly2 = NULL  ;
//         struct node* polyResultant = NULL ;
//         createNode(2,5,&poly1); 
//         createNode(4,1,&poly1);
//         createNode(2,0,&poly1);
//         printf ("\n1st Array is ");
//         display(poly1);
//         createNode(5,1,&poly2); 
//         createNode(5,0,&poly2);
//         printf ("\n2nd Array is ");
//         display(poly2);
//         polyResultant = (struct node*)malloc(sizeof(struct node*));
//         polyAdd(poly1,poly2,polyResultant);
//         printf ("\nThe resultant is \n");   
//         display (polyResultant);    
//     }


//     /*#include <stdio.h>
//     #include <math.h>
//     #include <stdlib.h>

//     struct node
//     {
//         int data ;
//         struct node* link ;
//     };

//     void createNode (int x , struct node **temp )
//     {
//         struct node* p ;
//         struct node* q ;
//         q = *temp;
//         if (q == NULL)
//         {
//             p = (struct node*)malloc(sizeof(struct node*));
//             p->data = x ;
//             *temp = p ;
//             p->link = (struct node*)malloc(sizeof(struct node*));
//             p = p->link ;
//             p->link = NULL ;
//         }
//         else {
//             p->data = x ;
//             p->link = (struct node*)malloc(sizeof(struct node*));
//             p = p->link ;
//             p->link = NULL ;
//         }
//     }

//     void mergeList (struct node* l , struct node* p , struct node* resultantlist )
//     {
//         while (l->link && p->link ){
//             if (l->data < p->data){
//                 resultantlist->data = l->data ; 
//                 l = l->link ;
//             }
//             else if ( p->data < l->data){
//                 resultantlist->data = p->data ;
//                 p = p->link;
//             }
//             else {
//                 resultantlist->data = p->data;
//                 p = p->link ;
//                 l = l->link ;
//             }
//             resultantlist->link = (struct node*)malloc(sizeof(struct node*));
//             resultantlist=resultantlist->link ;
//             resultantlist->link = NULL ;
//         }

//         while (l->link || p->link ){
//             if (l->link){
//                 resultantlist->data = l->data;
//                 l = l->link ;
//             }
//             else if ( p->link){
//                 resultantlist->data = p->data;
//                 p = p->link ;
//             }
//             resultantlist->link = (struct node*)malloc(sizeof(struct node*));
//             resultantlist=resultantlist->link ;
//             resultantlist->link = NULL ;
//         }
//     }

//     void display (struct node* p){
//         printf ("\nDisplaying the Data : \n ");
//         while (p->link != NULL){
//             printf ("%d-->",p->data);
//             p = p->link ;
//         }
//         printf ("%d",p->data);
//     }

//     void main ()

//     {
//         struct node* poly1  = NULL ;
//         struct node* poly2 = NULL ;
//         struct node* resultant = NULL ;

//         createNode(1,&poly1);
//         createNode(12,&poly1);
//         createNode(24,&poly1);
//         createNode(36,&poly1);
//         createNode(48,&poly1);
//         createNode(60,&poly1);
//         createNode(72,&poly1);

//         display(poly1);

//         createNode(8,&poly2);
//         createNode(9,&poly2);
//         createNode(18,&poly2);
//         createNode(25,&poly2);
//         createNode(28,&poly2);
//         createNode(30,&poly2);

//         printf ("\n");

//         resultant = (struct node*)malloc(sizeof(struct node*));
//         display (poly2);

//         mergeList(poly1,poly2,resultant);

//         display(resultant);

//     }




//     /*#include <stdio.h>
//     #include <stdlib.h>
//     #include <math.h>

//     struct node
//     {
//         int coeff ;
//         int power ;
//         struct node* link ;
//     };

//     void createNode (int x , int y , struct node **temp )
//     {
//         //printf ("\nEntered Created Node'\n");
//         struct node* p ;
//         struct node* q ;
//         q = *temp ;
//         if (q == NULL)
//         {
//             p = (struct node*)malloc (sizeof(struct node*));
//             p->coeff = x ;
//             p->power = y ;
//             *temp = p ;
//             p->link = (struct node*)malloc(sizeof(struct node*));
//             p = p->link;
//             p->link = NULL ;
//         }
//         else {
//             p->coeff = x ;
//             p->power = y ;
//             p->link = (struct node*)malloc(sizeof(struct node*));
//             p = p->link ;
//             p->link = NULL ;
//         }
//     }

//     void polyAdd (struct node* p , struct node* q , struct node* resultant )
//     {
//         while (p->link && q->link){
//             if (p->power > q-> power){
//                 resultant->power = p->power;
//                 resultant->coeff = p->coeff ;
//                 p = p->link ;
//             }
//             else if (p->power < q->power){
//                 resultant->power = q->power;
//                 resultant->coeff = q->coeff ;
//                 q = q->link ;
//             }
//             else {
//                 resultant->power = q->power ;
//                 resultant->coeff = q->coeff + p->coeff ;
//                 q = q->link ;
//                 p = p->link ;
//             }

//             resultant->link = (struct node*)malloc(sizeof(struct node*));
//             resultant = resultant->link ;
//             resultant->link = NULL ;
//         }

//         while (p->link || q->link ){
//             if (p->link){
//                 resultant->power = p->power ;
//                 resultant->coeff = p->coeff ;
//                 p = p->link ;
//             }
//             else if (q->link){
//                 resultant->power = q->power ;
//                 resultant->coeff = q->coeff ;
//                 q = q->link ;
//             }
//             resultant->link = (struct node*)malloc(sizeof(struct node*));
//             resultant=resultant->link ;
//             resultant->link = NULL ;
//         }
//     }

//     void display (struct node *q )
//     {
//         while (q->link != NULL ){
//             printf ("%d x^ %d",q->coeff,q->power);
//             q = q->link ;
//             if (q->link != NULL )
//                 printf ("+");
//         }
//     }

//     void main ()

//     {
//         struct node* poly1 = NULL ;
//         struct node* poly2 = NULL  ;
//         struct node* polyResultant = NULL ;
//         createNode(2,5,&poly1); 
//         createNode(4,1,&poly1);
//         createNode(2,0,&poly1);
//         printf ("\n1st Array is ");
//         display(poly1);
//         createNode(5,1,&poly2); 
//         createNode(5,0,&poly2);
//         printf ("\n2nd Array is ");
//         display(poly2);
//         polyResultant = (struct node*)malloc(sizeof(struct node*));
//         polyAdd(poly1,poly2,polyResultant);
//         printf ("\nThe resultant is \n");   
//         display (polyResultant);
//     }

//     /*#include <stdio.h>
//     #include <stdlib.h>
//     #include <math.h> 
//     using namespace std; 
    
//     // Node structure containing power and coefficient of variable 
//     struct Node 
//     { 
//         int coeff; 
//         int pow; 
//         struct Node *link; 
//     }; 
                
//     // Function to create new node 
//     void create_node(int x, int y, struct Node **temp) 
//     { 
//         struct Node *r, *z; 
//         z = *temp; 
//         if(z == NULL) 
//         { 
//             r =(struct Node*)malloc(sizeof(struct Node)); 
//             r->coeff = x; 
//             r->pow = y; 
//             *temp = r; 
//             r->link = (struct Node*)malloc(sizeof(struct Node)); 
//             r = r->link; 
//             r->link = NULL; 
//         } 
//         else
//         { 
//             r->coeff = x; 
//             r->pow = y; 
//             r->link = (struct Node*)malloc(sizeof(struct Node)); 
//             r = r->link; 
//             r->link = NULL; 
//         } 
//     } 

//     void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly) 
//     { 
//     while(poly1->next && poly2->next) 
//         { 
//             // If power of 1st polynomial is greater then 2nd, then store 1st as it is 
//             // and move its pointer 
//             if(poly1->pow > poly2->pow) 
//             { 
//                 poly->pow = poly1->pow; 
//                 poly->coeff = poly1->coeff; 
//                 poly1 = poly1->next; 
//             } 
            
//             // If power of 2nd polynomial is greater then 1st, then store 2nd as it is 
//             // and move its pointer 
//             else if(poly1->pow < poly2->pow) 
//             { 
//                 poly->pow = poly2->pow; 
//                 poly->coeff = poly2->coeff; 
//                 poly2 = poly2->next; 
//             } 
            
//             // If power of both polynomial numbers is same then add their coefficients 
//             else
//             { 
//                 poly->pow = poly1->pow; 
//                 poly->coeff = poly1->coeff+poly2->coeff; 
//                 poly1 = poly1->next; 
//                 poly2 = poly2->next; 
//             } 
            
//             // Dynamically create new node 
//             poly->next = (struct Node *)malloc(sizeof(struct Node)); 
//             poly = poly->next; 
//             poly->next = NULL; 
//         } 
//     while(poly1->next || poly2->next) 
//         { 
//             if(poly1->next) 
//             { 
//                 poly->pow = poly1->pow; 
//                 poly->coeff = poly1->coeff; 
//                 poly1 = poly1->next; 
//             } 
//             if(poly2->next) 
//             { 
//                 poly->pow = poly2->pow; 
//                 poly->coeff = poly2->coeff; 
//                 poly2 = poly2->next; 
//             } 
//             poly->next = (struct Node *)malloc(sizeof(struct Node)); 
//             poly = poly->next; 
//             poly->next = NULL; 
//         } 
//     } 


//     void show(struct Node *node) 
//     { 
//     while(node->link != NULL) 
//         { 
//         printf("%dx^%d", node->coeff, node->pow); 
//         node = node->link; 
//         if(node->link != NULL) 
//             printf(" + "); 
//         } 

//     }   

//     int main ()
//     {
//         struct Node* poly = NULL ;
//         create_node ( 5 , 2 , &poly );
//         create_node ( 4 , 1 , &poly );
//         create_node ( 2 , 0 , &poly );

//         printf ("\n 1st Polynomial ");
//         show (poly);
//         return  0 ;
//     }







//     /*#include<stdio.h>
//     int main()
//     {
//         int arr1[100],arr2[100];
//         int a,b,i,j;
//         printf("enter the size of array 1 and array 2: ");
//         scanf("%d%d",&a,&b);
//         printf("enter the elements of array 1: ");
//         for(i=0;i<a;i++)
//         {
//             scanf("%d",&arr1[i]);
//         }
//         printf("enter the elements of array 2: ");
//         for(j=0;j<b;j++)
//         {
//             scanf("%d",&arr2[j]);
//         }
//         if(a>b)
//         {
//         for(i=0;i<a;i++)
//         {
//             for(j=0;j<b;j++)
//             {
//                 if(arr1[i]==arr2[j])
//                 {
//                     printf("%d\t",arr2[j]);
//                     arr2[j]=-1;
//                     break;
//                 }
//                 else
//                 {
//                     printf("%d\t",arr1[i]);
//                     arr1[i]=-1;
//                     break;
//                 }
//             }
//         }
//         for(i=0;i<a;i++)
//         {
//             for(j=0;j<b;j++)
//             {
//                 if(arr1[i]!=-1)
//                 {
//                     printf("%d\t",arr1[i]);
//                     break;
//                 }
                
//             }
//         }
//         }
//         else
//         {
//         for(j=0;j<b;j++)
//         {
//             for(i=0;i<a;i++)
//             {
//                 if(arr2[j]==arr1[i])
//                 {
//                     printf("%d\t",arr1[i]);
//                     arr1[i]=-1;
//                     break;
//                 }
//                 else
//                 {
//                     printf("%d\t",arr2[j]);
//                     arr2[j]=-1;
//                     break;
//                 }
//             }
//         }
//         for(j=0;j<b;j++)
//         {
//             for(i=0;i<a;i++)
//             {
//                 if(arr2[j]!=-1)
//                 {
//                     printf("%d\t",arr2[j]);
                    
//                 }
                
//             }
//         }
//         }
        
        
//     }

//     /*#include <stdio.h>
//     #include <math.h>
//     #include <stdlib.h>

//     struct node 
//     {
//         int coeff ;
//         int power ;
//         struct node* link ;
//     };

//     struct node* root = NULL ;

//     void append ()
//     {
//         printf ("\nEnter the Coeff of the variable : ");
//         struct node* temp ;
//         temp = (struct node*)malloc(sizeof(struct node*));
//         scanf("%d",&temp->coeff);
//         temp->link = NULL ;
//         printf ("\nEnter the power of the variable : ");
//         scanf ("%d",&temp->power);
//         if (root == NULL)
//             root = temp ;
//         else
//         {
//             struct node* p ;
//             p = root ;
//             while (p->link != NULL)
//                 p = p->link ;
//             p->link = temp ;
//         }
        
//     }

//     int length ()
//     {
//         int len = 1 ;
//         struct node* p ;
//         p = root ;
//         while (p->link != NULL){
//             len++;
//             p = p->link ;
//         }
//         return len ;
//     }

//     void appendSum (int elementCoeff,int elementPower)
//     {
//         struct node* temp ;
//         temp = (struct node*)malloc(sizeof(struct node*));
//         temp->coeff = elementCoeff ;
//         temp->power = elementPower;
//         temp->link = NULL ;
//         struct node *p ;
//         p = root ;
//         while(p->link != NULL)
//             p = p->link ;
//         p->link = temp ;
//     }

//     void addition ()
//     {
//         int i ;
//         int sum = 0 ;
//         struct node* p ;
//         struct node* q ;
//         p = root ;
//         q = root ;
//         int varStoringTempValue ;
//         for( i = 1; i < length() ; i++ )
//         {
//             sum = 0 ;
//             varStoringTempValue = p->power ;
//             //printf ("\nThe p->power value is %d",p->power);  
//             for(int j = 1 ; j < length() ; j++ )
//             {
//                 //printf ("\nThe q->power value is %d",q->power);
//                 if (q->power == varStoringTempValue){
//                     sum += q->coeff;
//                     //printf("The Sum is %d",sum);
//                 // q->power = -1;
//                     }
//                 q = q->link ;        
//             }
//             appendSum(sum,varStoringTempValue);
//             p = p->link ;
//             q = root;
//         }
//     }

//     void display ()
//     {
//         struct node* p ;
//         p = root ;
//         while (p->link != NULL)
//         {
//             printf ("\n The Coeff is %d and Power is %d",p->coeff,p->power);
//             p = p->link ;
//         }
//         printf ("\n The Coeff is %d and Power is %d",p->coeff,p->power);
//     }


//     void main ()

//     {
//         append();
//         append();
//         append();
//         append();
//         display();
//         addition();
//     }
//     // #include <stdio.h>
//     // #include <math.h>
//     // #include <stdlib.h>

//     // struct node
//     // {
//     //     int data ;
//     //     struct node* link ;
//     // };

//     // struct node* root = NULL ;

//     // void append ()
//     // {
//     //     printf ("\nPlz Enter The Data for at the end insertion ");
//     //     struct node* temp ;
//     //     temp = (struct node*)malloc(sizeof(struct node*));
//     //     temp->link = NULL ;
//     //     scanf ("%d",&temp->data);
//     //     if (root == NULL)
//     //         root = temp ;
//     //     else{
//     //         struct node* p ;
//     //         p = root ;
//     //         while (p->link != NULL )
//     //             p = p->link ;
//     //         p->link = temp ;
//     //     }
//     // }

//     // void AddBegin ()
//     // {
//     //     printf ("\nPlz Enter The Data for the above held construction ");
//     //     struct node* temp ;
//     //     temp = (struct node*)malloc(sizeof(struct node*));
//     //     temp->link = NULL ;
//     //     scanf ("%d",&temp->data);

//     //     if (root == NULL)
//     //         root = temp ;
//     //     else{
//     //         temp->link = root ;
//     //         root = temp ;
//     //     }
//     // }

//     // int length ()
//     // {
//     //     int len = 1 ;
//     //     struct node* p ;
//     //     p = root ;
//     //     while ( p->link != NULL)
//     //     {
//     //         len++;
//     //         p = p->link ;
//     //     }
//     //     return len ;
//     // }

//     // void display ()
//     // {
//     //     struct node* p;
//     //     p = root ;
//     //     while (p->link != NULL){
//     //         printf ("%d-->",p->data);
//     //         p = p->link ;
//     //     }
//     //     printf ("%d",p->data);
//     // }

//     // void delete ()
//     // {
//     //     struct node* p ;
//     //     p = root ;
//     //     int loc ;
//     //     printf ("\nEnter the Node Loc ");
//     //     scanf ("%d",&loc);
//     //     if (loc == 1)
//     //         root = p->link ;
//     //     else if (loc == length())
//     //     {
//     //         for (int i = 1 ; i < loc-1 ; i++ )
//     //             p = p->link ;
//     //         p->link = NULL;
//     //     }
//     //     else 
//     //     {
//     //         for (int i = 1 ; i < loc-1 ; i++ )
//     //         p = p->link ;
//     //         struct node* q ;
//     //         q = p->link ;
//     //         struct node* l ;
//     //         l = q->link ;
//     //         q->link = NULL ;
//     //         p->link = l ;
//     //         free (q);
//     //         }
//     // }

//     // void addAnyPoint ()
//     // {
//     //     struct node* p;
//     //     struct node* q;
//     //     struct node* temp;
//     //     temp = (struct node*)malloc(sizeof(struct node*));
//     //     temp->link = NULL ;
//     //     int loc ;
//     //     printf ("\n Enter the node of data insertion \n");
//     //         scanf("%d",&loc);  
//     //     p = root ;
        
//     //     if (loc == 1)
//     //         AddBegin();
//     //     else if (loc == length()){
//     //         //printf ("I got into the if statement for length = %d",length());
//     //         append();}
//     //     else {
//     //          printf ("\n Enter the data for Add At Any Point ");
//     //     scanf ("%d",&temp->data); 
//     //         for (int i = 1 ; i < loc-1 ; i++)
//     //             p = p->link ;
//     //         q = p->link ;
//     //         temp->link = q ;
//     //         p->link = temp  ;
//     //     }
//     // }

//     // void ReverseList ()
//     // {
//     //     struct node* p ;
//     //     struct node* q ;
//     //     int i = 0 ;
//     //     int j = length();
//     //     p = root ;
//     //     q = root ;
//     //     while ( i < j )
//     //     {
//     //         int loc = j ;
//     //         for (int k = 1 ; k < loc ;k++ )
//     //             q = q->link ;
//     //         int temp = p->data;
//     //         p->data = q->data;
//     //         q->data= temp ;
//     //         p = p->link ;
//     //         q = root ;
//     //         i++;
//     //         j--;
//     //     }
//     // }

//     // void main ()

//     // {
//     //     append();
//     //     append();
//     //     append();
//     //     append();
//     //     append();
//     //     // display();
//     //     // delete();
//     //     // display();
//     //     // addAnyPoint ();
//     //     // display();
//     //     // addAnyPoint();
//     //     // display();
//     //     ReverseList();
//     //     printf ("\n");
//     //     display();
//     // }
//     // #include <stdio.h>
//     // #include <math.h>

//     // void reasoning (int totalBiscuits , int sudoNoVillages )
//     // {
//     //     for (int i = 1 ; i <= totalBiscuits ; i++ )
//     //     {
//     //         int beforeLoop = totalBiscuits-i ;
//     //         int afterLoop = totalBiscuits+i;
//     //         if (afterLoop/beforeLoop == sudoNoVillages){
//     //             //printf ("\nReached");
//     //             printf ("%d\n\n",beforeLoop);
//     //             break ;
//     //         }
//     //     }
//     // }

//     // void main ()

//     // {

//     //     int noVillages ;
//     //     int noBiscuits ;
    
//     //       scanf ("%d",&noVillages);
//     //      scanf ("%d",&noBiscuits);
//     //      reasoning (2*(noBiscuits-1),noVillages);
//     //     reasoning (2*(noBiscuits-2),noVillages);

//     //     reasoning (2*(noBiscuits-3),noVillages);
//     //     reasoning (2*(noBiscuits-4),noVillages);
//     // }


//     /*#include<bits/stdc++.h>
//     using namespace std;
    
//     int main()
//     {
//         float x;
//         cout<<"Enter a float : ";
//         cin>>x;
//         stringstream ss;
//         ss << abs(x-(int)x);
//         string s;
//         ss >> s;
//         cout<<"Numbers after decimal point = "<<s.length()-2<<endl;
//         return 0;
//     }

//     /*#include <stdio.h>
//     #include <math.h>

//     void main ()

//     {
//         double number ;
//         scanf ("%lf",&number);
//         printf ("%d",(int)number);
//         int counter = 0 ;
//         double sudoNumber = number - (int)number ;
//         // printf ("\n%lf",sudoNumber);
//         // sudoNumber = sudoNumber*10;
//         // printf ("\n%lf",sudoNumber);
//         // sudoNumber = sudoNumber*10;
//         // printf ("\n%lf",sudoNumber);
//         // sudoNumber = sudoNumber*10;
//         // printf ("\n%lf",sudoNumber);
//         // printf ("\n%lf",sudoNumber-(int)sudoNumber);
//         //while ((sudoNumber - (int)sudoNumber) != 0)
//         int i = 0 ;
//         while (i < 5)
//         {
//             // printf ("\n Entered");
//             counter++;
//             sudoNumber = sudoNumber*10;
//             printf ("\n%lf",sudoNumber);
//             printf("\n The value for sudo Subtracted %lf",sudoNumber - (int)sudoNumber); 
//             double game = sudoNumber - (int)sudoNumber;
//             if (game == 0.000000)
//                 printf ("I have entered here");
//             i++;
//         } 
//         //printf ("%d ",counter);
//     }

//     /*#include <stdio.h>
//     #include <math.h>
//     #include <stdlib.h>

//     // void swap (int *a , int *b )
//     // {
//     //     int temp = *a;
//     //     *a = *b ;
//     //     *b = temp ;
//     // }

//     struct node
//     {
//         int data ;
//         struct node* link;
//     };

//     struct node* root = NULL ;

//     void append ()
//     {
//         struct node* temp ;
//         temp = (struct node*)malloc(sizeof(struct node* ));
//         printf ("\nEnter The Data : ");
//         scanf ("%d",&temp->data);
//         temp->link = NULL ;
//         if (root == NULL){
//             printf ("Imtheone");
//             root = temp ;}
//         else 
//         {
//             struct node* p ;
//             p = root ;
//             while (p->link != NULL)
//                 p = p->link ;
//             p->link = temp ;
//         }
//     }

//     void AddBegin ()
//     {
//         struct node* temp ;
//         temp = (struct node*)malloc(sizeof(struct node*));
//         printf ("\nEnter The Data : ");
//         scanf ("%d",&temp->data);
//         temp->link = NULL ;
//         if (root == NULL )
//             root = temp ;
//         else {
//             temp->link = root;
//             root = temp ;
//         }
//     }

//     void Display ()
//     {
//         struct node* p ;
//         p = root ;
//         while (p->link != NULL){
//             printf ("%d-->",p->data);
//             p = p->link ;}
//         printf ("%d",p->data);
//     }

//     int length ()
//     {
//         int length = 1 ;
//         struct node* p = root ;
//         while (p->link != NULL){
//             length++;
//             p = p->link ;
//             }
//         return length ;
//     }

//     void addBetween ()
//     {
//         struct node* temp ;
//         temp = (struct node*)malloc(sizeof(struct node*));
//         printf ("\nEnter The Data : ");
//         scanf ("%d",&temp->data);
//         temp->link = NULL ;
//         int loc ;
//         printf ("\nEnter the loc :");
//         scanf ("%d",&loc);
//         if (loc == 1)
//             AddBegin();
//         else if (loc == length())
//             append();
//         else {
//             struct node* p;
//             struct node* q ;
//             p = root ;
//             for (int i = 1 ; i < loc-1 ; i++)
//                 p = p->link ;
//             temp->link = p->link ;
//             p->link = temp ;
//         }
//     }

//     void deletion ()
//     {
//         int loc ;
//         printf ("\nEnter The Location set you want to delete : ");
//         scanf ("%d",&loc);
//         struct node* p ;
//         struct node* q ;
//         struct node* temp ;
//         p = root ;
//         if (loc == 1){
//             root = p->link ;
//         free (p); }
//         else if (loc == length()){
//             printf ("Entered");
//             for (int i = 0 ; i < length()-1 ; i++ )
//                 p=p->link ;
//             struct node* q ;
//             q = p->link ;
//             p -> link = NULL ;
//             free (q);
//         }
//         else {
//             for (int i = 1 ; i < loc-1 ; i++ )
//                 p = p->link ;
//             temp = p->link ;
//             q = temp->link ;
//             p->link = q ;
//             temp->link = NULL ;
//             free (temp);
//         }
//     }

//     void ReverseList()
//     {
//         struct node* p ;
//         struct node* q ;
//         p = root ;
//         q = root ;
//         int len = length ();
//         int i = 0 ;
//         int j = len-1 ;
//         int k ;
//         while ( i < j )
//         {
//             k = 0 ;
//             while ( k < j )
//             {
//                 q = q->link ;
//                 k++;
//             }
//         //    swap (q->data,p->data);
//             int temp = p->data;
//             p->data = q->data;
//             q->data = p->data;
//             i++;
//             j--;
//             q = root ;
//             p = p ->link ;
//         }
//     }

//     void main ()

//     {
//         append();
//         append();
//         append();
//         append();
//         append();
//         append();
//         deletion();
//         AddBegin();
//         Display();
//         printf ("\n");
//         ReverseList();
//         Display();
//         printf ("\n");
//     /* printf ("\n1.Append\n2.Pop\n3.Disply\n4.Length\n5.Delete\n7.AddBegin\n8.Exit");
//         int choice ;
//         while (1)
//         {
//             scanf ("%d",&choice);
//             if (choice == 1)
//                 append();
//             else if (choice == 3)
//                 Display();
//             else if (choice == 4)
//                 printf ("\nTHe length is %d",length());
//             else if (choice == 5)
//                 delete();
//             else if(choice == 6)
//                 AddBegin();
//             else if (choice ==2)
//                 exit (-1);
//         }*/
//     //}

//     /*#include <iostream>
//     #include <string>
//     #include "StudentHeader.h"

//     using namespace std ;

//     int main ()

//     {
//         Student* varun = new Student ("Gamechanger") ;
//         //varun ("GameChanger");
//         varun -> setRegNo (1111);
//         varun -> setName ("Varun");
//         cout << varun -> getRegNo () << varun -> getName () ;
//         cout <<"\n";
//         cout << Student :: getTotalStudent ()<<"\n";
//         delete varun ;
//     //    cout << varun -> getRegNo () << varun -> getName () ;
//     /*    Student varun ;
//         varun.setRegNo (1111);
//         varun.setName ("Varun Updhayay");
//         cout << varun.getRegNo () << varun.getName () ;
//         return 0 ;*/
//     //}

//     /*#include <stdio.h>
//     #include <math.h>
//     #include <stdlib.h>
//     #include <string.h>

//     int front = -1 ;
//     int rear = -1 ;
//     int size ;
//     int inputArray[100] ;
//     char sudoArray [100][100] ; 

//     void append ()
//     {
//         if (rear == size-1 )
//         {
//             printf ("\nStack Overflow");
//             exit (-1);
//         }
//         else 
//         {
//             if (front == -1)
//                 front++;
//             rear++;
//         }
//         printf ("\nPlz Enter the Registration Number :\n");
//         char inputString [25] ;
//         scanf ("%s",sudoArray[rear]);
//         strcpy (inputArray,sudoArray[rear]);
//         int stringlength = strlen (inputArray);
//         //printf ("I got this %s ",inputArray);
//         int checkElement = strncmp (inputArray,"19BBS",5);
//         //printf ("the i o t %d " , checkElement );
//         int counterCheckDigit = 0 ;
//         for (int i = 5 ; i < 9 ; i++ )
//         {
//             if (!isdigit(inputArray[i]))
//                 counterCheckDigit++;
//         }
//         //printf ("\nCounter Check digit %d \n",counterCheckDigit);
//     if (checkElement != 0 || stringlength > 9 && counterCheckDigit == 4 )
//     {
//         //printf ("\nEntered");
//         {
//         printf ("Exiting\n");
//         exit (-1);}
//     }
//     }

//     void pop ()
//     {
//         if (front == size-1 )
//         {
//             printf ("Stack Underflow ");
//             exit (-1);
//         }
//         else
//             front++;
//     }

//     void display ()
//     {
//         int i ;
//         for ( i = rear ; i >= front ; --i )
//             printf ("%s \n",sudoArray[i] );
//     }

//     void main ()

//     {
//         printf ("\nPlease Enter the size of the array .\n");
//         scanf ("%d",&size);
//         int i ;
//         for (i = 0 ;  ; i++ )
//         {
//             printf ("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
//             int choiceUser ;
//             scanf ("%d",&choiceUser);
//             if (choiceUser == 1 )
//                 append();
//             else if (choiceUser == 2)
//                 pop ();
//             else if (choiceUser == 3 )
//                 display();
//             else if (choiceUser == 4 )
//                 exit (-1);
//             else
//             {
//                 printf ("Wrong Choice \n");
//             }
            
//         }
//     }


//     /*
//     //Application of Stack 

//     #include <stdio.h>
//     #include <math.h>
//     #include <string.h>
//     #include <stdlib.h>
//     #include <stdbool.h>
//     //#include <iostream>
//     //using namespace std ;
//     //char inputString [100];
//     char sudoStackArray [100];
//     int top = -1 ;
//     int sizeOfStackArray = 100 ;
//     int i = 0 ;
//     void pushStackArray (char letterIntegration )
//     {
//         if (top == sizeOfStackArray-1 )
//             exit(-1);
//         else
//         {
//             top++;
//             sudoStackArray[top] = letterIntegration ; 
//         }
//     }

//     void popUndo ()
//     {
//         if (top == -1)
//             exit (-1);
//         else
//             top--;
//     }

//     void display ()
//     {
//         for ( i = 0 ; i <= top ; i++ )
//             printf("%c",sudoStackArray[i]);
//         printf ("\n");    
//     }

//     void dataEntry ()
//     {
//         //printf("\nReached");
//         char inputString [100] ; 
//         gets(inputString);
//         //printf ("\nItooktheinput");
//         int lengthString = strlen (inputString);
        
//         for ( i = 0 ; i < lengthString ; i++ )
//         pushStackArray(inputString[i]);
        
//     }


//     int main ()

//     {
//         for ( i = 0 ; i < 100 ; i++ )
//             sudoStackArray[i] = '\0';

//         printf ("Please Write Your Note Here \n");
//         dataEntry();
//         printf ("\nDo You want to enter more\n");
//         int inputUser = 0 ;
//         int choiceUser = 0 ;
//         for (int i ; ; i++ )
//         {
//             printf ("\nEnter the data set you require");
//             scanf("%d",&inputUser);
//             if (inputUser == 0 )
//                 dataEntry();
//             else if (inputUser == 1){
//                 printf ("How Many undo do you want to get ?\n");
//                 scanf ("%d",&choiceUser);
//                 for (int i  = 0 ; i < choiceUser ; i++ )
//                     popUndo();
//                     }
//             else
//             {
//                 display();
//                 break ;
//             }
            
//         }
//         }
//         //printf ("\n");

//         //dataEntry();
//         //display();
//         /*{
//             printf ("How Many Times Do You want to pop the element \n");
//             int numberIterative ;
//             scanf ("%d",&numberIterative);
//             for (int i = 0 ; i < numberIterative ; i++ )
//                 popUndo();
//             printf ("\n");
//         }
//         display();
//     */
//     /*    dataEntry();
//         display();
//         popUndo();
//         display();
//         dataEntry();
//         display();
//         dataEntry();
//         display();

//         while (true)
//         {
//             int number ;
//             scanf("%d",&number);
//             if (number == 1)
//                 dataEntry();
//             else
//             {
//                 display();
//                 break ;
//             }
            
//         }


//     /*#include <stdio.h>
//     #include <string.h>
//     void main ()
//     {
//         char input[] = "19BBS0163";
//         int e = strncmp (input,"19BBS0163",5);
//         printf ("%d \n",e );
//     }

//     /*#include <stdio.h>
//     #include <math.h>
//     #include <string.h>
//     #include <stdbool.h>


//     int stack [100];
//     int top = -1 ;
//     int topCounter = -1 ;
//     int inputArray [100]; 

//     bool isemptyStack ()
//     {
//         if (topCounter == -1 )
//             return true ;
//         else
//             return false ;
//     }

//     void interactTop()
//     {

//     }

//     void areaHisto ()
//     {
//         //inputArray [7] = {6,2,5,4,5,1,6};
//         inputArray[0] = 6 ;
//         inputArray[1] = 2 ;
//         inputArray[2] = 5 ;
//         inputArray[3] = 4 ;
//         inputArray[4] = 5 ;
//         inputArray[5] = 1 ;
//         inputArray[6] = 6 ;
//         int maxSize = 7 ;
//         for (int i = 0 ; i < 7 ; i++ )
//         {
//             //printf ("How many times is %d \n",i);
//             if (isemptyStack())
//             {
//                 topCounter++;
//                 top++;
//                 stack[topCounter] = i ; 
//                 //printf ("\nin first if statement statement Came for %d ", i );
//             }

//             else
//             {
                
//                 topCounter++;
//                 top++;
//                 stack[top] = i ;
//                 topCounter--;
//                 //printf ("The Top is %d and stack topcounter is %d",top , stack[topCounter]);
//                 if (inputArray[stack[topCounter]] > inputArray[stack[top]] )
//                 {
//                 // printf ("\nin if statement Came for %d ", i );
//                 // printf ("\nEntered\n");
//                 // printf ("inputarraystack is %d and top for input is %d",inputArray[stack[topCounter]],inputArray[stack[top]]);
//                     int counterTrack = 0 ;
//                     int temp = topCounter ;
//                     while (true)
//                     {
//                     // printf ("\n the temp is %d and topcounter is %d and top is %d",temp,topCounter,top);
//                     //  printf ("\n inputstacktop = %d and inputstacktemp is %d ",inputArray[stack[top]],inputArray[stack[temp]]);
//                         if (inputArray[stack[temp]] > inputArray[stack[top]])
//                         {
//                             counterTrack++;
//                             temp--;
//                             if (temp == -1 )
//                                 break ;
//                         }
//                         else
//                             break ;
//                     }
//                 // printf ("\nCouner array is %d",counterTrack);
//                     int area = 0 ;
//                     for (int j = 0 ; j < counterTrack ; j++ )
//                     {
//                         if (isemptyStack()){
//                             printf ("\nEntered and inputstacktop is %d and intputstacktopcounter is %d",inputArray[stack[top]],inputArray[stack[topCounter]]);
//                             printf ("\nthe top counter is %d",stack[topCounter]);
//                         area = inputArray[stack[temp]]*(j-stack[top]-1);}
//                         else{
//                         printf ("\nEntered and inputstacktop is %d and intputstacktopcounter is %d",inputArray[stack[top]],inputArray[stack[topCounter]]);
//                         printf ("\nthe top counter is %d",stack[topCounter]);
//                         area = inputArray[stack[top]]*i ;
//                         }
//                         printf ("\nArea = %d\n",area);

//                         top--;
//                         topCounter--;
//                         if (topCounter == -1)
//                             break ;
//                     }
//     /*
//                     /*while (inputArray[stack[temp]] > inputArray[stack[topCounter]] || (temp == 0) )
//                     {   

//                     }*/
//     /*            }
                

//             }

                
//         }
//     }

//     void main ()

//     {
//         areaHisto();
//     }

//     */


//     /*#include <stdio.h>
//     #include <math.h>
//     #include <string.h>
//     #include <stdlib.h>
//     //#include <iostream>
//     //using namespace std ;
//     //char inputString [100];
//     char sudoStackArray [100];
//     int top = -1 ;
//     int sizeOfStackArray = 100 ;

//     void pushStackArray (char letterIntegration )
//     {
//         if (top == sizeOfStackArray-1 )
//             exit(-1);
//         else
//         {
//             top++;
//             sudoStackArray[top] = letterIntegration ; 
//         }
//     }

//     void popUndo ()
//     {
//         if (top == -1)
//             exit (-1);
//         else
//             top--;
//     }

//     void display ()
//     {
//         for (int i = 0 ; i <= top ; i++ )
//             printf("%c",sudoStackArray[i]);
//         printf ("\n");    
//     }

//     void dataEntry ()
//     {
//         //printf("\nReached");
//         char inputString [100] ; 
//         gets(inputString);
//         //printf ("\nItooktheinput");
//         int lengthString = strlen (inputString);
//         for (int i = 0 ; i < lengthString ; i++ )
//         pushStackArray(inputString[i]);
        
//     }


//     int main ()

//     {
//         for (int i = 0 ; i < 100 ; i++ )
//             sudoStackArray[i] = '\0';

//         printf ("Please Write Your Note Here \n");
//         dataEntry();
//         //printf ("\n");

//         //dataEntry();
//         //display();
//         {
//             printf ("How Many Times Do You want to pop the element \n");
//             int numberIterative ;
//             scanf ("%d",&numberIterative);
//             for (int i = 0 ; i < numberIterative ; i++ )
//                 popUndo();
//             printf ("\n");
//         }
//         display();

//     /*    dataEntry();
//         display();
//         popUndo();
//         display();
//         dataEntry();
//         display();
//         dataEntry();
//         display();

//         while (true)
//         {
//             int number ;
//             scanf("%d",&number);
//             if (number == 1)
//                 dataEntry();
//             else
//             {
//                 display();
//                 break ;
//             }
            
//         }
//     */
//         //char inputString [100] ; 
//         //gets(inputString);
//         //int lengthString = strlen (inputString);
//         //for (int i = 0 ; i < lengthString ; i++ )
//         // pushStackArray(inputString[i]);
//         //dataEntry();
//         //popUndo();
//     // display ();   
//     // printf ("\n");
//     // dataEntry();
//     // display();
//         /*int inputUser ;
//         while (1)
//         {
//             printf ("Do You Want to enter the string ?");
//             //int inputUser ;
//             scanf ("%d",&inputUser);
//             if (inputUser == 1)
//                 dataEntry();
//             else if (inputUser == 2)
//                 popUndo();
//             else{
//                 display();
//                 break ;}
            
//         }*/
//         /*int inputUser = 0 ;
//         for (int i ; ; i++ )
//         {
//             printf ("\nEnter the data set you require");
//             scanf("%d",&inputUser);
//             if (inputUser == 0 )
//                 dataEntry();
//             else if (inputUser == 1)
//                 popUndo();
//             else
//             {
//                 display();
//                 break ;
//             }
            
//         }
//     }
//     */