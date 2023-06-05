//name: Andrewdai Truong
//date: June 6th, 2023
//description: this program will allow you to view the different kindas of lists
//Vectors, Linked List, Stacks, Queues

#include <iostream>
#include <string>
#include "input.h"
#include "Rational.h"
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

//prototypes
char menuOption();
void programS();
void programQ();
void programL();
void programV();

//precondition: none
//postcondition: none
int main()
{
    do
    {
        switch (toupper(menuOption()))
        {
        case 'X': exit(1); break;
        case 'V': programV(); break; // vector
        case 'L': programL(); break; // list
        case 'S': programS(); break; // stack
        case 'Q': programQ(); break; // queue

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

//precondition: none
//postcondition: returns a letter for the switch case
char menuOption()
{
    system("cls"); //clears screen

    cout << "\n\tA container is a holder object that stores a collection of other objects(its elements).They";
    cout << "\n\tare implemented as class templates, which allows great flexibility in the types supported as";
    cout << "\n\telements.The container manages the storage space for its elementsand provides member functions";
    cout << "\n\tto access them, either directly or through iterators(reference objects with similar properties";
    cout << "\n\tto pointers).";
    cout << "\n";
    cout << "\n\tCMPR121 Exam3: STL (Standard Template Library) Containers and Container Adaptors by Andrewdai Truong";
    cout << "\n\t" + string(100, char(205));
    cout << "\n\t\tV. Vector Container";
    cout << "\n\t\tL. List Container";
    cout << "\n\t\tS. Stack Container Adaptor";
    cout << "\n\t\tQ. Queue Container Adaptor";
    cout << "\n\t" + string(100, char(196));
    cout << "\n\t\tX. Exit";
    cout << "\n\t" + string(100, char(205));

    return inputChar("\n\t\tOption: ", "VLXQS");
}

//precondition: none
//postcondition: displays the stack and return if its empty
void printStackContents(stack<Rational> stack)
{
    if (stack.empty()) //base case
        return;

    Rational topRational = stack.top(); //starts with the top rational fraction
    cout << "\n\t" << topRational; //outputs the rational fraction
    stack.pop(); //pops to the next

    printStackContents(stack); //calls itself

    stack.push(topRational); // push to the next fraction
}


//precondition: input integer from int main should be S
//postcondition: returns a menu allowing different functions of stacks
void programS()
{

    stack<Rational> rationalStack; //initializes Rational as a stack

    do
    {

        system("cls"); //clears screen

        cout << "\n\tStacks are a type of container adaptors with LIFO(Last In First Out) type of working, where";
        cout << "\n\ta new element is added(push) at one end(top) and an element is removed(pop) from that end";
        cout << "\n\tonly.Stack uses an encapsualted object of either vector or deque(by default) or list(sequential";
        cout << "\n\tcontainer class) as its underlying container, providing a specific set of member functions to";
        cout << "\n\taccess its elements.";
        cout << "\n\n";

        if (!rationalStack.empty()) //if stack is NOT empty, display the function as well as how many are in the stack
        {
            cout << "\tThe current stack contains " << rationalStack.size() << " elements"; //outputs how many are in the stack
            printStackContents(rationalStack); //function to display stack
        }
        else //else just type stack is empty
        {
            cout << "\n\tStack is empty." << "\n";
        }

        cout << "\n\n\t\tStack Menu Options";
        cout << "\n\t" + string(100, char(205));
        cout << "\n\t\t1. Push";
        cout << "\n\t\t2. Top";
        cout << "\n\t\t3. Pop";
        cout << "\n\t" + string(100, char(196));
        cout << "\n\t\t0. Return";
        cout << "\n\t" + string(100, char(205));
        
        int option = inputInteger("\n\tOption: ", 0, 3); // input validation for switch case for stack

        switch (option)
        {

        case 0: return; //returns to main menu
        case 1: //Pushes number into the stack
        {
            int numerator = inputInteger("\n\tEnter a numerator   (-9...9): ", -9, 9); //input validation for numerator
            int denominator = inputInteger("\n\tEnter a denominator (-9...9): ", -9, 9); //input validation for denominator
        
            try //try case
            {
                Rational rational(numerator, denominator); //first number is numerator and second number is denominator
                rationalStack.push(rational); //pushes the number
                cout << rational <<" will be pushed onto the stack." << "\n";
            }
            catch (const Rational::ZeroDenominator& out) //catches if the number is not a rational number
            {
                cout << "\n\tInvalid rational number." << "\n";
            }


            
            break;
        }

        case 2: //outputs the top of the stack
        {
            if (!rationalStack.empty()) //if the stack is NOT empty, output the top of the stack
            {
                Rational topRational = rationalStack.top(); //element of the top stack
                cout << "\n\tTop of the stack: " << topRational << "\n\n"; //outputs what the top stack is
                system("pause");
            }

            else //the stack is empty ...output
            {
                cout << "\n\tStack is empty!" << "\n";
                system("pause");
            }
        }
             break;
        case 3: //pops the number out of the stack
        {
            if (!rationalStack.empty()) //if teh stack is NOT empty, popping a stack is available
            {
                Rational topRational = rationalStack.top(); //element of the top stack
                cout << "\n\t" << topRational << " popped from the stack." << "\n\n";
                rationalStack.pop(); //stack popping
                

            }
            else //the stack is empty... output
            {
                cout << "\n\tStack is empty." << "\n";
                system("pause");
                break;
            }

            system("pause");
        }
        break;
        default:
            cout << "\n\tInvalid option.";
            break;
        }

    } while (true);
}

//precondition: none
//postcondition: displays the order of queue
void printQueueContents(queue<Rational> queue)
{
    if (queue.empty()) //returns if the queue is empty
        return;

    Rational frontRational = queue.front(); //front of queue
    cout << "\n\t" << frontRational; // outputs the front of queue
    queue.pop(); //pops the queue

    printQueueContents(queue); //repeats the queue until the queue is empty

    queue.push(frontRational); //pushes the queue
}

//precondition: input integer from int main should be Q
//postcondition: returns a menu allowing different functions of queues
void programQ()
 {

    queue<Rational> rationalQueue; //initializes the queue
        
    do
    {
        system("cls"); //clears screen
       
        cout << "\n\tQueues are a type of container adaptors that operate in a first in first out (FIFO) type of";        
        cout << "\n\tarrangement. Elements are inserted(enqueued) at the back and are deleted (dequeued) from the";        
        cout << "\n\tfront. Queues use an encapsulated object of deque or list(sequential container class) as its";      
        cout << "\n\tunderlying container, providing a specific set of member functions to access elements.";        
        cout << "\n";

        if (!rationalQueue.empty()) //if the queue is NOT empty
        {
            cout << "\tThe current queue contains " << rationalQueue.size() << " elements"; //outputs the amount inside the queue
            printQueueContents(rationalQueue); //function to show queue
        }
        else //otherwise output text
        {
            cout << "\n\tQueue is empty.";
        }

        cout << "\n\t\tQueue Menu Options";        
        cout << "\n\t" + string(100, char(205));        
        cout << "\n\t\t1. Enqueue (push in from the back)";        
        cout << "\n\t\t2. Front";       
        cout << "\n\t\t3. Back";        
        cout << "\n\t\t4. Dequeue (pop from the front)";        
        cout << "\n\t" + string(100, char(196));        
        cout << "\n\t\t0. Return";        
        cout << "\n\t" + string(100, char(205));
        
        int option = inputInteger("\n\tOption: ", 0, 4); //input validation for switch
        
        switch (option)
        {
        case 0: return;
        case 1: //Enqueue
        {
            int numerator = inputInteger("\n\tEnter a numerator   (-9...9): ", -9, 9); //input validation for numerator
            int denominator = inputInteger("\n\tEnter a denominator (-9...9): ", -9, 9); //input validaiton for denominator

            try
            {
                Rational rational(numerator, denominator); //makes the two numbers into one
                rationalQueue.emplace(rational); //emplaces is similar to enqueue
                cout << "\n\tRational number pushed to the stack." << "\n";
            }

            catch (const Rational::ZeroDenominator& out)
            {
                cout << "\n\tInvalid rational number." << "\n";
                system("pause");
            }

        }

        break;
        case 2: //Front
        {
            if (!rationalQueue.empty()) //if NOT empty, show the number in the front of the queue
                cout << "\n\tFront element: " << rationalQueue.front() << "\n";
            else //output when the queue is empty
                cout << "\n\tQueue is empty." << "\n";
                system("pause");
        }
        break;
        case 3: //Back
        {
            if (!rationalQueue.empty()) //if NOT empty, show the number in the back of the queue
                cout << "\n\tBack element: " << rationalQueue.back() << "\n";
            else //output when the queue is empty
                cout << "\n\tQueue is empty." << "\n";
                system("pause");
        }

        break;
        case 4: //Dequeue or pop from the front
        {
            if (!rationalQueue.empty()) //if the queue is not empty, dequeue the front of the queue
            {
                rationalQueue.pop(); //pop the front
            }
            else //output when the queue is empty 
                cout << "\n\tQueue is empty." << "\n";
                system("pause");
        }

        break;
        }
        
    } while (true);
    
}

//precondition: none
//postcondition: shows the content of the list
void printListContents(list<Rational> list)
{
    for (const Rational& rational : list)
    {
        cout << "\n\t" << rational;
    }
}

//precondition: input integer from int main should be L
//postcondition: returns a menu allowing different functions of lists 
void programL()
{

    list<Rational> rationalList; //initializing constructor from Rational.h

    do
    {
        system("cls"); //clears screen

        cout << "\n\tLists are sequence containers that allow non-contiguous memory allocation. As compared to";
        cout << "\n\tvector, the list has slow traversal, but once a position has been found, insertion and";
        cout << "\n\tdeletion are quicker.";
        cout << "\n";

        if (!rationalList.empty()) //if NOT empty, count the amount in the list as well as display it
        {
            cout << "\tThe current list contains " << rationalList.size() << " elements";
            printListContents(rationalList);
        }
        else //output if list is empty
        {
            cout << "\n\tList is empty.";
        }

        cout << "\n\t\tList Menu Options";
        cout << "\n\t" + string(100, char(205));
        cout << "\n\t\t1. Add an element";
        cout << "\n\t\t2. Insert an element after";
        cout << "\n\t\t3. Remove element(s)";
        cout << "\n\t\t4. Sort the elements in ascending order";
        cout << "\n\t\t5. Clear all elements";
        cout << "\n\t" + string(100, char(196));
        cout << "\n\t\t0. Return";
        cout << "\n\t" + string(100, char(205));

        int option = inputInteger("\n\tOption: ", 0, 5); //input validation for the upcoming switch

        switch (option)
        {

        case 0: return;
        case 1: //appending a fraction
        {
            if (rationalList.empty()) //if the list is empty, it will just add the fraction anywhere
            {
                int numerator = inputInteger("\n\tEnter a numerator   (-9...9): ", -9, 9);
                int denominator = inputInteger("\n\tEnter a denominator (-9...9): ", -9, 9);

                try
                {
                    Rational rational(numerator, denominator);
                    rationalList.push_back(rational);
                    cout << "\n\tRational number inserted.";
                }
                catch (const Rational::ZeroDenominator& out)
                {
                    cout << "\n\tInvalid rational number";
                    system("pause");
                }
                break;
            }

            if (!rationalList.empty()) //if the list is empty, it will just add the fraction anywhere
            {
                int numerator = inputInteger("\n\tEnter a numerator   (-9...9): ", -9, 9);
                int denominator = inputInteger("\n\tEnter a denominator (-9...9): ", -9, 9);

                try
                {
                    Rational rational(numerator, denominator);
                    rationalList.push_back(rational);
                    cout << "\n\tRational number inserted.";
                }
                catch (const Rational::ZeroDenominator& out)
                {
                    cout << "\n\tInvalid rational number";
                    system("pause");
                }
                break;
            }
            break;

        case 2:
        {
            if (rationalList.empty())
            {
                cout << "\n\tList is empty. Please add an element first.";
                system("pause");
                break;
            }

            cout << "\n\tCurrent list:";
            printListContents(rationalList);

            int numerator = inputInteger("\n\tEnter a numerator   (-9...9): ", -9, 9);
            int denominator = inputInteger("\n\tEnter a denominator (-9...9): ", -9, 9);

            int size = rationalList.size();
            int position = inputInteger("\n\tEnter the position after which you want to insert an element (Front = 0... up to the size of the list)", 0, size - 1);


            try
            {
                Rational rational(numerator, denominator);

                auto it = rationalList.begin();
                advance(it, position); // Move the iterator to the desired position

                rationalList.insert(it, rational);
                cout << "\n\tRational number inserted.";
            }
            catch (const Rational::ZeroDenominator& out)
            {
                cout << "\n\tInvalid rational number";
            }
            system("pause");
            break;
        }

        case 3: break;
        case 4: //sorting the list
            rationalList.sort();
            break;
        case 5: //list clear
        {
            if (rationalList.empty())
            {
                cout << "\n\tCannot clear an empty list";
                system("pause");
                break;
            }

            else
                rationalList.clear();
        }
        break;


        }
        }
    }while (true);
}

//precondition: none
//postcondition: shows the content of the list
void printVectorContents(vector<Rational> vector)
{
    for (const Rational& rational : vector)
    {
        cout << "\n\t" << rational;
    }
}

//precondition: input integer from int main should be V
//postcondition: returns a menu allowing different functions of vectors
void programV()
{

    vector<Rational> rationalVector; //initializing constructor from Rational.h

    do
    {

        system("cls");

        cout << "\n\tVectors are same as dynamic arrays with the ability to resize itself automatically when an";
        cout << "\n\telement is inserted or deleted, with their storage being handled automatically by the container.";
        cout << "\n\tVector elements are placed in  contiguous storage so that they can be accessed and traversed";
        cout << "\n\tusing iterators or indexes.";
        cout << "\n";

        if (!rationalVector.empty()) //if NOT empty, count the amount in the vector as well as display it
        {
            cout << "\tThe current list contains " << rationalVector.size() << " elements";
            printVectorContents(rationalVector);
        }
        else //output if list is empty
        {
            cout << "\n\tList is empty.";
        }

        cout << "\n\n\t\tVector Menu Options";
        cout << "\n\t" + string(100, char(205));
        cout << "\n\t\t1. Add an element to the back";
        cout << "\n\t\t2. Insert an element at an index";
        cout << "\n\t\t3. Retrieve an element at an index";
        cout << "\n\t\t4. Erase element(s)";
        cout << "\n\t\t5. Sort the elements in ascending order";
        cout << "\n\t\t6. Clear all elements";
        cout << "\n\t" + string(100, char(196));
        cout << "\n\t\t0. Return";
        cout << "\n\t" + string(100, char(205));

        int option = inputInteger("\n\tOption: ", 0, 6);

        switch (option)
        {

        case 0: return;
        case 1: 
        {
            int numerator = inputInteger("\n\tEnter a numerator   (-9...9): ", -9, 9);
            int denominator = inputInteger("\n\tEnter a denominator (-9...9): ", -9, 9);

            try
            {
                Rational rational(numerator, denominator);
                rationalVector.push_back(rational);
                cout << "\n\tRational number inserted at the back of the vector.";
            }
            catch (const Rational::ZeroDenominator& out)
            {
                cout << "\n\tInvalid rational number";
                system("pause");
            }
            break;
        }
        break;
        case 2: 
        {
            if (rationalVector.empty())
            {
                cout << "\n\tVector is empty. Please add an element first.";
                system("pause");
                break;
            }

            int numerator = inputInteger("\n\tEnter a numerator   (-9...9): ", -9, 9);
            int denominator = inputInteger("\n\tEnter a denominator (-9...9): ", -9, 9);

            int size = rationalVector.size();
            int position = inputInteger("\n\tEnter the position after which you want to insert an element (Front = 0... up to the size of the vector): ", 0, size);

            try
            {
                Rational rational(numerator, denominator);
                rationalVector.insert(rationalVector.begin() + position + 1, rational);
                cout << "\n\tRational number inserted.";
            }
            catch (const Rational::ZeroDenominator& out)
            {
                cout << "\n\tInvalid rational number";
            }
            system("pause");
            break;
        }
        break;

        case 3: 
        {
            if (rationalVector.empty())
            {
                cout << "\n\tVector is empty. Please add an element first.";
                system("pause");
                break;
            }

            cout << "\n\tCurrent vector:";
            printVectorContents(rationalVector);

            int size = rationalVector.size();
            int index = inputInteger("\n\tEnter the index of the element you want to access  ", 0, size - 1);

            Rational& rational = rationalVector[index];
            cout << "\n\tRational number at index " << index << ": " << rational;
            system("pause");
            break;
        }

        case 4: 
        {
            if (rationalVector.empty())
            {
                cout << "\n\tVector is empty. There are no elements to remove.";
                system("pause");
                break;
            }

            int size = rationalVector.size();
            int choice = inputInteger("\n\tSelect removal option:\n\t1. Remove a single element\n\t2. Remove all elements\n\tOption: ", 1, 2);

            if (choice == 1)
            {
                int index = inputInteger("\n\tEnter the index of the element you want to remove (Starting from 0): ", 0, size-1);
                rationalVector.erase(rationalVector.begin() + index);
                cout << "\n\tElement at index " << index << " removed.";
            }
            else if (choice == 2)
            {
                rationalVector.clear();
                cout << "\n\tAll elements removed.";
            }
            else
            {
                cout << "\n\tInvalid option.";
            }

            system("pause");
            break;
        }
        case 5: 
        {
            sort(rationalVector.begin(), rationalVector.end());
            break;
        }
        case 6: 
        {
            if (rationalVector.empty())
            {
                cout << "\n\tVector is already empty. There are no elements to clear.";
                system("pause");
                break;
            }

            rationalVector.clear();
            cout << "\n\tAll elements cleared from the vector.";
            system("pause");
            break;
        }

        }

    } while (true);
}   