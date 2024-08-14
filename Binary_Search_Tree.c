// Program for BST (Binary Search Tree)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Insert(PPNODE Root, int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if (*Root == NULL) // Tree is empty
    {
        *Root = newn;
    }
    else // Tree contains atleast one node
    {
        temp = *Root;

        while (1)
        {
            if (temp->data == No)
            {
                printf("Unable to insert node as element %d is already present\n", No);
                free(newn);
                break;
            }
            else if (No > temp->data)
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if (No < temp->data)
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

void Inorder(PNODE Root)
{
    if (Root != NULL)
    {
        Inorder(Root->lchild);
        printf("%d\n", Root->data);
        Inorder(Root->rchild);
    }
}

void Preorder(PNODE Root)
{
    if (Root != NULL)
    {
        printf("%d\n", Root->data);
        Preorder(Root->lchild);
        Preorder(Root->rchild);
    }
}

void Postorder(PNODE Root)
{
    if (Root != NULL)
    {
        Postorder(Root->lchild);
        Postorder(Root->rchild);
        printf("%d\n", Root->data);
    }
}

bool Search(PNODE Root, int No)
{
    bool bFlag = false;

    if (Root == NULL)
    {
        printf("Tree is empty :\n");
        return bFlag;
    }
    while (Root != NULL)
    {
        if (Root->data == No)
        {
            bFlag = true;
            break;
        }
        else if (No > Root->data)
        {
            Root = Root->rchild;
        }
        else if (No < Root->data)
        {
            Root = Root->lchild;
        }
    }
    return bFlag;
}

int CountLeaf(PNODE Root)
{
    static int iCnt = 0;

    if (Root != NULL)
    {
        if ((Root->lchild == NULL) && (Root->rchild == NULL))
        {
            iCnt++;
        }
        CountLeaf(Root->lchild);
        CountLeaf(Root->rchild);
    }
    return iCnt;
}

int CountParent(PNODE Root)
{
    static int iCnt = 0;

    if (Root != NULL)
    {
        if ((Root->lchild != NULL) || (Root->rchild != NULL))
        {
            iCnt++;
        }
        CountParent(Root->lchild);
        CountParent(Root->rchild);
    }
    return iCnt;
}

int CountAll(PNODE Root)
{
    static int iCnt = 0;

    if (Root != NULL)
    {
        iCnt++;
        CountAll(Root->lchild);
        CountAll(Root->rchild);
    }
    return iCnt;
}

int main()
{
    PNODE Head = NULL;
    bool bRet = 0;
    int iRet = 0;

    Insert(&Head, 21);
    Insert(&Head, 34);
    Insert(&Head, 11);
    Insert(&Head, 98);
    Insert(&Head, 44);
    Insert(&Head, 28);
    Insert(&Head, 11);
    Insert(&Head, 7);
    Insert(&Head, 17);

    printf("\nInorder traversal :\n");
    Inorder(Head);

    printf("\nPreorder traversal :\n");
    Preorder(Head);

    printf("\nPostorder traversal :\n");
    Postorder(Head);

    bRet = Search(Head, 98);

    if (bRet == true)
    {
        printf("\nElement 98 is present in BST\n");
    }
    else
    {
        printf("\nElement 98 is not present in BST\n");
    }

    iRet = CountLeaf(Head);
    printf("\nNumber of leaf nodes :\n%d\n", iRet);

    iRet = CountParent(Head);
    printf("\nNumber of parent nodes :\n%d\n", iRet);

    iRet = CountAll(Head);
    printf("\nNumber of total nodes :\n%d\n", iRet);

    return 0;
}
