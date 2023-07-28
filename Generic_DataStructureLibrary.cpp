// #################################################################
//
//
//	Generic Data Structure library
//  Author			: 	Sejal D Kharche
//	Date			:	27 June 2023
//
//
// #################################################################

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
public:
    struct NodeS<T> *first;
    int iCount;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    T Addition();
    T Maximum();
    T Minimum();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{

    cout << "Elements of Singly Linear Linked list are : "
         << "\n";

    NodeS<T> *temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{

    int iCount = Count();

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{

    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{

    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{

    int iCount = Count();

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp1 = first;
        NodeS<T> *temp2 = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}

template <class T>
int SinglyLL<T>::SearchFirstOcc(T No)
{

    int iCnt = 1;
    while (first->data != No)
    {
        first = first->next;
        iCnt++;
    }
    return iCnt;
}
template <class T>
int SinglyLL<T>::SearchLastOcc(T No)
{

    int iCnt = 1;
    int iPos = 0;
    while (first->next != NULL)
    {
        if (first->data == No)
        {
            iPos = iCnt;
        }
        first = first->next;
        iCnt++;
    }

    return iPos;
}

template <class T>
T SinglyLL<T>::Addition()
{

    int iAns = 0;
    while (first != NULL)
    {
        iAns = iAns + first->data;
        first = first->next;
    }

    return iAns;
}

template <class T>
T SinglyLL<T>::Maximum()
{

    int Max = 0;
    while (first != NULL)
    {
        if (first->data > Max)
        {
            Max = first->data;
        }
        first = first->next;
    }

    return Max;
}
template <class T>
T SinglyLL<T>::Minimum()
{

    int Min = first->data;
    while (first != NULL)
    {
        if (first->data < Min)
        {
            Min = first->data;
        }
        first = first->next;
    }

    return Min;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
public:
    struct NodeS<T> *first;
    struct NodeS<T> *last;
    int iCount;

    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    T Addition();
    T Maximum();
    T Minimum();
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{

    cout << "Elements of Doubly Circular Linked list are : "
         << "\n";

    NodeS<T> *temp = first;
    for (int icnt = 1; icnt <= iCount; icnt++)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;
    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;
    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->next = first;
        last = newn;
    }
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    if (iPos < 1 || iPos > iCount + 1)
    {
        return;
    }
    else if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *newn = new NodeS<T>;
        NodeS<T> *temp = first;
        newn->data = no;
        newn->next = NULL;
        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> *temp = first;
        while (temp->next->next != first)
        {
            temp = temp->next;
        }
        last = temp;
        delete temp->next;
        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {

        NodeS<T> *temp = first;
        NodeS<T> *tempX = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}
template <class T>
int SinglyCL<T>::SearchFirstOcc(T No)
{

    int iCnt = 1;
    while (first->data != No)
    {
        first = first->next;
        iCnt++;
    }
    return iCnt;
}
template <class T>
int SinglyCL<T>::SearchLastOcc(T No)
{

    int iCnt = 1;
    int iPos = 0;
    while (first->next != NULL)
    {
        if (first->data == No)
        {
            iPos = iCnt;
        }
        first = first->next;
        iCnt++;
    }

    return iPos;
}

template <class T>
T SinglyCL<T>::Addition()
{

    int iAns = 0;
    while (first != NULL)
    {
        iAns = iAns + first->data;
        first = first->next;
    }

    return iAns;
}

template <class T>
T SinglyCL<T>::Maximum()
{

    int Max = 0;
    while (first != NULL)
    {
        if (first->data > Max)
        {
            Max = first->data;
        }
        first = first->next;
    }

    return Max;
}
template <class T>
T SinglyCL<T>::Minimum()
{

    int Min = first->data;
    while (first != NULL)
    {
        if (first->data < Min)
        {
            Min = first->data;
        }
        first = first->next;
    }

    return Min;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
public:
    struct NodeD<T> *first;
    int iCount;

    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int SearchFirstOcc(T);
int SearchLastOcc(T);
T Addition();
T Maximum();
T Minimum();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{

    NodeD<T> *temp = first;
    cout << "Elements Doubly Linear linked list are:\n";
    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeD<T> *temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{

    if (iPos < 1 || iPos > iCount + 1)
    {
        return;
    }
    else if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *newn = new NodeD<T>;
        newn->data = no;
        newn->next = NULL;
        NodeD<T> *temp = first;
        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{

    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{

    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> *temp = first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{

    if (iPos < 1 || iPos > iCount)
    {
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;
        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

template <class T>
int DoublyLL<T>::SearchFirstOcc(T No)
{

    int iCnt = 1;
    while (first->data != No)
    {
        first = first->next;
        iCnt++;
    }
    return iCnt;
}
template <class T>
int DoublyLL<T>::SearchLastOcc(T No)
{

    int iCnt = 1;
    int iPos = 0;
    while (first->next != NULL)
    {
        if (first->data == No)
        {
            iPos = iCnt;
        }
        first = first->next;
        iCnt++;
    }

    return iPos;
}

template <class T>
T DoublyLL<T>::Addition()
{

    int iAns = 0;
    while (first != NULL)
    {
        iAns = iAns + first->data;
        first = first->next;
    }

    return iAns;
}

template <class T>
T DoublyLL<T>::Maximum()
{

    int Max = 0;
    while (first != NULL)
    {
        if (first->data > Max)
        {
            Max = first->data;
        }
        first = first->next;
    }

    return Max;
}
template <class T>
T DoublyLL<T>::Minimum()
{

    int Min = first->data;
    while (first != NULL)
    {
        if (first->data < Min)
        {
            Min = first->data;
        }
        first = first->next;
    }

    return Min;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly cicular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
public:
    struct NodeD<T> *first;
    struct NodeD<T> *last;
    int iCount;

    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int SearchFirstOcc(T);
int SearchLastOcc(T);
T Addition();
T Maximum();
T Minimum();
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeD<T> *temp = first;
    cout << "Elements Doubly Linear linked list are:\n";
    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = last->next;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{

    if (iPos < 1 || iPos > iCount + 1)
    {
        return;
    }
    else if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *newn = new NodeD<T>;
        newn->data = no;
        newn->next = NULL;
        NodeD<T> *temp = first;
        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{

    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{

    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last;
        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;
        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

template <class T>
int DoublyCL<T>::SearchFirstOcc(T No)
{

    int iCnt = 1;
    while (first->data != No)
    {
        first = first->next;
        iCnt++;
    }
    return iCnt;
}
template <class T>
int DoublyCL<T>::SearchLastOcc(T No)
{

    int iCnt = 1;
    int iPos = 0;
    while (first->next != NULL)
    {
        if (first->data == No)
        {
            iPos = iCnt;
        }
        first = first->next;
        iCnt++;
    }

    return iPos;
}

template <class T>
T DoublyCL<T>::Addition()
{

    int iAns = 0;
    while (first != NULL)
    {
        iAns = iAns + first->data;
        first = first->next;
    }

    return iAns;
}

template <class T>
T DoublyCL<T>::Maximum()
{

    int Max = 0;
    while (first != NULL)
    {
        if (first->data > Max)
        {
            Max = first->data;
        }
        first = first->next;
    }

    return Max;
}
template <class T>
T DoublyCL<T>::Minimum()
{

    int Min = first->data;
    while (first != NULL)
    {
        if (first->data < Min)
        {
            Min = first->data;
        }
        first = first->next;
    }

    return Min;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Stack

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
public:
    struct NodeS<T> *First;
    int iCount;

    Stack();
    void Push(T); // InsertLast
    T Pop();      // DleteLast
    void Display();
    int Count();
   
T Addition();
T Maximum();
T Minimum();
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}
template <class T>

void Stack<T>::Push(T no) // InsertLast
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeS<T> *temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
T Stack<T>::Pop() // DeleteLast
{
    T Value = 0;

    if (iCount == 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    else if (iCount == 1)
    {
        Value = First->data;
        delete First;
        First = NULL;
    }
    else
    {
        NodeS<T> *temp = First;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;

    return Value;
}

template <class T>
void Stack<T>::Display()
{
    cout << "Elements of stack are : \n";

    NodeS<T> *temp = First;

    for (int icnt = 1; icnt <= iCount; icnt++)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
T Stack<T>::Addition()
{

    int iAns = 0;
    while (First != NULL)
    {
        iAns = iAns + First->data;
        First = First->next;
    }

    return iAns;
}

template <class T>
T Stack<T>::Maximum()
{

    int Max = 0;
    while (First != NULL)
    {
        if (First->data > Max)
        {
            Max = First->data;
        }
        First = First->next;
    }

    return Max;
}
template <class T>
T Stack<T>::Minimum()
{

    int Min = First->data;
    while (First != NULL)
    {
        if (First->data < Min)
        {
            Min = First->data;
        }
        First = First->next;
    }

    return Min;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Queue

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
public:
    struct NodeS<T> *First;
    int iCount;

    Queue();
    void Enqueue(T); // InsertLast
    T Dequeue();     // DleteFirst
    void Display();
    int Count();
    
T Addition();
T Maximum();
T Minimum();
};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}
template <class T>
void Queue<T>::Enqueue(T no) // InsertLast
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;
    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeS<T> *temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}
template <class T>
T Queue<T>::Dequeue() // DeleteFirst
{
    T Value = 0;

    if (iCount == 0)
    {
        cout << "Queue is empty\n";
        return -1;
    }
    else if (iCount == 1)
    {
        Value = First->data;
        delete First;
        First = NULL;
    }
    else
    {
        Value = First->data;
        NodeS<T> *temp = First;
        First = First->next;
        delete temp;
    }

    iCount--;

    return Value;
}
template <class T>
void Queue<T>::Display()
{
    if (First == NULL)
    {
        cout << "Nothing to display as Queue is empty\n";
        return;
    }

    cout << "Elements of Queue are : \n";

    NodeS<T> *temp = First;

    for (int icnt = 1; icnt <= iCount; icnt++)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}
template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
T Queue<T>::Addition()
{

    int iAns = 0;
    while (First != NULL)
    {
        iAns = iAns + First->data;
        First = First->next;
    }

    return iAns;
}

template <class T>
T Queue<T>::Maximum()
{

    int Max = 0;
    while (First != NULL)
    {
        if (First->data > Max)
        {
            Max = First->data;
        }
        First = First->next;
    }

    return Max;
}
template <class T>
T Queue<T>::Minimum()
{

    int Min = First->data;
    while (First != NULL)
    {
        if (First->data < Min)
        {
            Min = First->data;
        }
        First = First->next;
    }

    return Min;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Class of BST
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct NodeB
{
    T data;
    struct NodeB *lchild;
    struct NodeB *rchild;
};

template <class T>
class BST
{
public:
    struct NodeB<T> *First;
    int iCount;

    BST();

    void Insert(T);
    void Preorder(NodeB<T> *First);
    void Postorder(NodeB<T> *First);
    void Inorder(NodeB<T> *First);
    bool Search(T);
    int CountNodes(NodeB<T> *First);
    int CountLeafNodes(NodeB<T> *First);
    int CountParentNodes(NodeB<T> *First);
};

template <class T>
BST<T>::BST()
{
    First = NULL;
    iCount = 0;
}
template <class T>
void BST<T>::Insert(T no)
{
    NodeB<T> *newn = new NodeB<T>;
    newn->data = no;

    newn->lchild = NULL;
    newn->rchild = NULL;

    NodeB<T> *temp = First;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        while (1)
        {
            if (no == temp->data)
            {
                cout << "Duplicate element : Unable to insert\n";
                delete newn;
                break;
            }
            else if (no > temp->data)
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if (no < temp->data)
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}
template <class T>
void BST<T>::Preorder(NodeB<T> *First)
{
    if (First != NULL)
    {
        cout << First->data << "\t";
        Preorder(First->lchild);
        Preorder(First->rchild);
    }
}
template <class T>
void BST<T>::Postorder(NodeB<T> *First)
{
    if (First != NULL)
    {
        Postorder(First->lchild);
        Postorder(First->rchild);
        cout << First->data << "\t";
    }
}

template <class T>
void BST<T>::Inorder(NodeB<T> *First)
{
    if (First != NULL)
    {
        Inorder(First->lchild);
        cout << First->data << "\t";
        Inorder(First->rchild);
    }
}
template <class T>
bool BST<T>::Search(T no)
{
    bool flag = false;

    if (First == NULL)
    {
        cout << "There is empty\n";
        return flag;
    }

    while (First != NULL)
    {
        if (no == First->data)
        {
            flag = true;
            break;
        }
        else if (no > First->data)
        {
            First = First->rchild;
        }
        else if (no < First->data)
        {
            First = First->lchild;
        }
    }
    return flag;
}
template <class T>
int BST<T>::CountNodes(NodeB<T> *First)
{

    static int iCnt = 0;

    if (First != NULL)
    {
        iCnt++;
        CountNodes(First->lchild);
        CountNodes(First->rchild);
    }

    return iCnt;
}
template <class T>
int BST<T>::CountLeafNodes(NodeB<T> *First)
{
    static int iCnt = 0;

    if (First != NULL)
    {
        if ((First->lchild == NULL) && (First->rchild == NULL))
        {
            iCnt++;
        }
        CountLeafNodes(First->lchild);
        CountLeafNodes(First->rchild);
    }

    return iCnt;
}
template <class T>
int BST<T>::CountParentNodes(NodeB<T> *First)
{
    static int iCnt = 0;

    if (First != NULL)
    {
        if ((First->lchild != NULL) || (First->rchild != NULL))
        {
            iCnt++;
        }
        CountParentNodes(First->lchild);
        CountParentNodes(First->rchild);
    }

    return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Entry Point function
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    cout << "----------------------------------------";
    cout << "\nSingly Linear linked list\n";
    cout << "----------------------------------------";
    SinglyLL<int> obji;
    obji.InsertFirst(51);
    obji.InsertFirst(21);
    obji.InsertFirst(11);
    obji.InsertLast(101);
    obji.InsertLast(111);

   
    
    obji.InsertAtPos(55, 4);
    obji.Display();
    cout << "Number of elements are : " << obji.Count() << "\n";
    obji.DeleteAtPos(4);
    obji.Display();
    cout << "Number of elements are : " << obji.Count() << "\n";
    obji.DeleteFirst();
    obji.DeleteLast();
    obji.Display();
    cout << "Number of elements are : " << obji.Count() << "\n";

    SinglyLL<char> objc;
    objc.InsertFirst('C');
    objc.InsertFirst('B');
    objc.InsertFirst('A');
    objc.InsertLast('D');
    objc.InsertLast('E');
    objc.Display();
    cout << "Number of elements are : " << objc.Count() << "\n";

    SinglyLL<double> objd;
    objd.InsertFirst(90.90);
    objd.InsertFirst(80.80);
    objd.InsertFirst(70.70);
    objd.InsertLast(60.60);
    objd.InsertLast(50.50);
    objd.Display();
    cout << "Number of elements are : " << objd.Count() << "\n";

    cout<<"Addition is : "<<obji.Addition()<<"\n";

    cout << "----------------------------------------";
    cout << "\nSingly Circular linked list\n";
    cout << "----------------------------------------";
    SinglyCL<int> objci;
    objci.InsertFirst(51);
    objci.InsertFirst(21);
    objci.InsertFirst(11);
    objci.InsertLast(101);
    objci.InsertLast(111);
    objci.InsertAtPos(55, 4);
    objci.Display();
    cout << "Number of elements are : " << objci.Count() << "\n";
    objci.DeleteAtPos(4);
    objci.Display();
    cout << "Number of elements are : " << objci.Count() << "\n";
    objci.DeleteFirst();
    objci.DeleteLast();
    objci.Display();
    cout << "Number of elements are : " << objci.Count() << "\n";

    SinglyCL<char> objcc;
    objcc.InsertFirst('C');
    objcc.InsertFirst('B');
    objcc.InsertFirst('A');
    objcc.InsertLast('D');
    objcc.InsertLast('E');
    objcc.Display();
    cout << "Number of elements are : " << objcc.Count() << "\n";

    SinglyCL<double> objcd;
    objcd.InsertFirst(90.90);
    objcd.InsertFirst(80.80);
    objcd.InsertFirst(70.70);
    objcd.InsertLast(60.60);
    objcd.InsertLast(50.50);
    objcd.Display();
    cout << "Number of elements are : " << objcd.Count() << "\n";

    cout << "----------------------------------------";
    cout << "\nDoubly Linear linked list\n";
    cout << "----------------------------------------";
    DoublyLL<int> objdi;
    objdi.InsertFirst(51);
    objdi.InsertFirst(21);
    objdi.InsertFirst(11);
    objdi.InsertLast(101);
    objdi.InsertLast(111);
    objdi.InsertAtPos(55, 4);
    objdi.Display();
    cout << "Number of elements are : " << objdi.Count() << "\n";
    objdi.DeleteAtPos(4);
    objdi.Display();
    cout << "Number of elements are : " << objdi.Count() << "\n";
    objdi.DeleteFirst();
    objdi.DeleteLast();
    objdi.Display();
    cout << "Number of elements are : " << objdi.Count() << "\n";

    DoublyLL<char> objdc;
    objdc.InsertFirst('C');
    objdc.InsertFirst('B');
    objdc.InsertFirst('A');
    objdc.InsertLast('D');
    objdc.InsertLast('E');
    objdc.Display();
    cout << "Number of elements are : " << objdc.Count() << "\n";

    DoublyLL<double> objdd;
    objdd.InsertFirst(90.90);
    objdd.InsertFirst(80.80);
    objdd.InsertFirst(70.70);
    objdd.InsertLast(60.60);
    objdd.InsertLast(50.50);
    objdd.Display();
    cout << "Number of elements are : " << objdd.Count() << "\n";

    cout << "----------------------------------------";
    cout << "\nDoubly Circular linked list\n";
    cout << "----------------------------------------";

    DoublyCL<int> objdci;
    objdci.InsertFirst(51);
    objdci.InsertFirst(21);
    objdci.InsertFirst(11);
    objdci.InsertLast(101);
    objdci.InsertLast(111);
    objdci.InsertAtPos(55, 4);
    objdci.Display();
    cout << "Number of elements are : " << objdci.Count() << "\n";
    objdci.DeleteAtPos(4);
    objdci.Display();
    cout << "Number of elements are : " << objdci.Count() << "\n";
    objdci.DeleteFirst();
    objdci.DeleteLast();
    objdci.Display();
    cout << "Number of elements are : " << objdci.Count() << "\n";

    DoublyCL<char> objdcc;
    objdcc.InsertFirst('C');
    objdcc.InsertFirst('B');
    objdcc.InsertFirst('A');
    objdcc.InsertLast('D');
    objdcc.InsertLast('E');
    objdcc.Display();
    cout << "Number of elements are : " << objdcc.Count() << "\n";

    DoublyCL<double> objdcd;
    objdcd.InsertFirst(90.90);
    objdcd.InsertFirst(80.80);
    objdcd.InsertFirst(70.70);
    objdcd.InsertLast(60.60);
    objdcd.InsertLast(50.50);
    objdcd.Display();
    cout << "Number of elements are : " << objdcd.Count() << "\n";

    int iRet = 0;
    bool bRet = false;

    BST<int> obj;

    obj.Insert(11);
    obj.Insert(8);
    obj.Insert(33);
    obj.Insert(66);
    obj.Insert(23);
    obj.Insert(3);
    obj.Insert(9);

    obj.Preorder(obj.First); // Pass obj.First as the root of the tree
    cout << endl;

    obj.Postorder(obj.First); // Pass obj.First as the root of the tree
    cout << endl;

    obj.Inorder(obj.First); // Pass obj.First as the root of the tree
    cout << endl;

    iRet = obj.CountNodes(obj.First); // Pass obj.First as the root of the tree
    cout << "Count of nodes: " << iRet << endl;

    iRet = obj.CountLeafNodes(obj.First); // Pass obj.First as the root of the tree
    cout << "Count of leaf nodes: " << iRet << endl;

    iRet = obj.CountParentNodes(obj.First); // Pass obj.First as the root of the tree
    cout << "Count of parent nodes: " << iRet << endl;

    bRet = obj.Search(66);
    if (bRet == true)
    {
        cout << "Element is there";
    }
    else
    {
        cout << "\nElement is not there";
    }

    //  int iChoice = 1;
    //     int iValue = 0;
    //     int iRet = 0;

    //     Stack<int> obj;

    //     cout<<"-----------------------------------------------------\n";
    //     cout<<"Dynamic Implementation of Stack\n";
    //     cout<<"-----------------------------------------------------\n";

    //     while(iChoice != 0)
    //     {
    //             cout<<"-----------------------------------------------------\n";
    //             cout<<"1 : Push element into stack\n";
    //             cout<<"2 : Pop element from the stack\n";
    //             cout<<"3 : Display elements from stack\n";
    //             cout<<"4 : Count number of elements from stack\n";
    //             cout<<"0 : Terminate the application\n";
    //             cout<<"-----------------------------------------------------\n";

    //             cout<<"Please enter the option : \n";
    //             cin>>iChoice;

    //             switch(iChoice)
    //             {
    //                 case 1 :
    //                     cout<<"Enter the element that you want to push\n";
    //                     cin>>iValue;
    //                     obj.Push(iValue);
    //                     break;

    //                 case 2:
    //                     iRet = obj.Pop();
    //                     if(iRet != -1)
    //                     {
    //                         cout<<"Poped element from stack is : "<<iRet<<"\n";
    //                     }
    //                     break;

    //                 case 3:
    //                     obj.Display();
    //                     break;

    //                 case 4:
    //                     iRet = obj.Count();
    //                     cout<<"Number of elements are : "<<iRet<<"\n";
    //                     break;

    //                 case 0:
    //                     cout<<"Thank you for using the applicatoion\n";
    //                     break;

    //                 default:
    //                     cout<<"Please enter valid option\n";
    //                     break;
    //             }  // End of switch
    //     } // End of while

    // int iChoice = 1;
    // int iValue = 0;
    // int iRet = 0;

    // Queue<int> obj;

    // cout << "-----------------------------------------------------\n";
    // cout << "Dynamic Implementation of Queue\n";
    // cout << "-----------------------------------------------------\n";

    // while (iChoice != 0)
    // {
    //     cout << "-----------------------------------------------------\n";
    //     cout << "1 : Insert element into Queue\n";
    //     cout << "2 : Remove element from the Queue\n";
    //     cout << "3 : Display elements from Queue\n";
    //     cout << "4 : Count number of elements from Queue\n";
    //     cout << "0 : Terminate the application\n";
    //     cout << "-----------------------------------------------------\n";

    //     cout << "Please enter the option : \n";
    //     cin >> iChoice;

    //     switch (iChoice)
    //     {
    //     case 1:
    //         cout << "Enter the element that you want to insert\n";
    //         cin >> iValue;
    //         obj.Enqueue(iValue);
    //         break;

    //     case 2:
    //         iRet = obj.Dequeue();
    //         if (iRet != -1)
    //         {
    //             cout << "Removed element from Queue is : " << iRet << "\n";
    //         }
    //         break;

    //     case 3:
    //         obj.Display();
    //         break;

    //     case 4:
    //         iRet = obj.Count();
    //         cout << "Number of elements are : " << iRet << "\n";
    //         break;

    //     case 0:
    //         cout << "Thank you for using the applicatoion\n";
    //         break;

    //     default:
    //         cout << "Please enter valid option\n";
    //         break;
    //     } // End of switch
    // }     // End of while



    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
