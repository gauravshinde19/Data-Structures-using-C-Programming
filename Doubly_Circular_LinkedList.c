// Program for Doubly Circular LinkedList

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE First, PNODE Last)
{
    if ((First == NULL) && (Last == NULL))
    {
        printf("Unable to display elements as there is no element present in Linked List\n");
    }
    else
    {
        PNODE temp = First;

        printf("<->");
        do
        {
            printf("| %d |<->", temp->data);
            temp = temp->next;
        } while (temp != Last->next);
    }
    printf("\n");
}

int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;

    if ((First == NULL) && (Last == NULL))
    {
        printf("Unable to count elements as there is no element present in Linked List\n");
    }
    else
    {
        PNODE temp = First;

        do
        {
            iCnt++;
            temp = temp->next;
        } while (temp != Last->next);
    }

    return iCnt;
}

void InsertFirst(PPNODE First, PPNODE Last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        newn->next = *First;
        newn->prev = *Last;
        *First = newn;
    }
    (*Last)->next = *First;
}

void InsertLast(PPNODE First, PPNODE Last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        (*Last)->next = newn;
        *Last = newn;
    }
    (*Last)->next = *First;
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
    if ((*First == NULL) && (*Last == NULL))
    {
        printf("Unable to delete element as Linked List is empty");
        return;
    }
    else if ((*First == *Last))
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        PNODE temp = *First;
        *First = (*First)->next;
        (*Last)->next = *First;
        free(temp);
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    if ((*First == NULL) && (*Last == NULL))
    {
        printf("Unable to delete element as Linked List is empty");
        return;
    }
    else if ((*First == *Last))
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        PNODE temp = *First;

        while ((temp)->next != *Last)
        {
            temp = temp->next;
        }
        free(temp->next);
        *Last = temp;
    }
    (*Last)->next = *First;
}

void InsertAtPos(PPNODE First, PPNODE Last, int iNo, int iPos)
{
    int iLength = Count(*First, *Last);

    if ((iPos < 1) || (iPos > iLength + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(First, Last, iNo);
    }
    else if (iPos == iLength + 1)
    {
        InsertLast(First, Last, iNo);
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = *First;
        int i = 0;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

void DeleteAtPos(PPNODE First, PPNODE Last, int iPos)
{
    int iLength = Count(*First, *Last);

    if ((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst(First, Last);
    }
    else if (iPos == iLength)
    {
        DeleteLast(First, Last);
    }
    else
    {    
        PNODE temp1 = *First;
        PNODE temp2 = NULL;
        int i = 0;
        
        for (i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1 -> next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int iRet = 0;

    InsertFirst(&Head, &Tail, 11);
    InsertFirst(&Head, &Tail, 13);
    InsertFirst(&Head, &Tail, 15);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("\nNumber of elements after InsertFirst : %d\n\n", iRet);

    InsertLast(&Head, &Tail, 21);
    InsertLast(&Head, &Tail, 23);
    InsertLast(&Head, &Tail, 25);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("\nNumber of elements after InsertLast : %d\n\n", iRet);

    DeleteFirst(&Head, &Tail);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("\nNumber of elements after DeleteFirst : %d\n\n", iRet);

    DeleteLast(&Head, &Tail);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("\nNumber of elements after DeleteLast : %d\n\n", iRet);

    InsertAtPos(&Head, &Tail, 55, 3);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("\nNumber of elements after InsertAtPos : %d\n\n", iRet);

    DeleteAtPos(&Head, &Tail, 3);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("\nNumber of elements after DeleteAtPos : %d\n\n", iRet);

    return 0;
}
