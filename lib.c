#include <stdio.h>
#include <conio.h>

#define Maxlength 30

typedef int ElementType;

typedef int Position;

typedef struct
{

    ElementType Elements[Maxlength];

    Position Last;

} List;

// tao danh sach rong

void MakeNull_List(List *L)
{
    L->Last = 0;
}

// kiem tra danh sach rong
int Empty_List(List L)
{
    return (L.Last == 0);
}

// kiem tra danh sach co day hay khong, neu day tra ve 1 nguoc lai tra ve 0
int Full_List(List L)
{
    return (L.Last == Maxlength);
}

// tra ve phan tu dau tien trong danh sach

Position FirstList(List L)
{
    return 1;
}

// Tra ve phan tu cuoi trong danh sach
Position EndList(List L)
{
    return L.Last + 1;
}

// tra ve vi tri sau p next (vi tri p + 1)
Position Next(Position P, List L)
{
    return P + 1;
}

// tra ve vi tri truoc p position (vi tri p - 1)
Position Previous(Position P, List L)
{
    return P - 1;
}

// tra ve noi dung phan tu tai vi tri P
ElementType Retrieve(Position P, List L)
{
    return L.Elements[P - 1];
}

// Them phan tu co noi dung X vao vi tri P
void Insert_List(ElementType X, Position P, List *L)
{
    int i = 0;

    if ((L->Last) == Maxlength)
    {
        printf("Danh sach day");
    }
    else
    {
        if ((P < 1) || (P > L->Last + 1))
        {

            printf("vi tri khong hop le");
        }
        else
        {
            for (i = L->Last; i >= P; i--)
            {

                L->Elements[i] = L->Elements[i - 1];
            }

            L->Last++;

            L->Elements[P - 1] = X;
        }
    }
}

// Xoa phan tu tai vi tri P trong danh sach
void Delete_List(Position P, List *L)
{
    if (P > L->Last || P < 1)
    {
        printf("vi tri khong hop le");
    }
    else
    {
        if (Empty_List(*L))
        {
            printf("Danh sach rong");
        }
        else
        {
            Position i;
            for (i = P; i < L->Last; i++)
            {
                // mang vi tri [P - 1] se duoc gan bang P

                // Array 		0	1	2	3	4	5

                // Position 		1	2	3	4	5	6

                // Element		2	7	5	8	6	Last

                /*

                Delete (4, L)

                //Array			0	1	2	4	5

                //Position 		1	2	3	5	6

                //Element		2	7	5	6	Last
                */
                L->Elements[i - 1] = L->Elements[i];
            }
        }
        L->Last--;
    }
}

void sort (List *pL) {
    
    
    for ( int p = 0; p < pL->Last; p++) {
        
        for (int q = p + 1; q <= pL->Last - 1; q++) {
            
            if (pL->Elements[p] > pL->Elements[q]) {
                
                int temp = pL->Elements[p];
                
                pL->Elements[p] = pL->Elements[q];
                
                pL->Elements[q] = temp;
                
                
            }
            
        }
        
    }
    
}

void unionSet (List L1, List L2, List *pL) {
    
    //tao danh sach rong
    makenullList(&(*pL));

    //insert all Elements from L1 to *pL
    for (int i = 0; i < L1.Last; i++) {
        
            insertSet(L1.Elements[i], &(*pL));
    
        
    }        
    
    //insert Elements from L2 to *pL with statement        
    for (int j = 0; j < L2.Last; j ++){
        
        //if Elements[j] in L2 hadn't existed in L1 then we add it to *pL  
        if(!member(L2.Elements[j], L1)) {
                
                insertSet(L2.Elements[j], &(*pL));
                
        }    
}
    
    // for (int j = 0; j < L2.Last; j ++) {
    //     insertSet(L2.Elements[j], &(*pL));
    // }    
    
}

int member(int x, List L) {
    
    int found = 0;
    
    for (int i = 1; i <= L.Last; i++) {
        
        if (L.Elements[i] == x) {
            
            found = 1;
            
            return found;
        }
        
    }
    return found;
}

void Print_List(List L)
{
    Position P;

    P = FirstList(L);

    printf("bat dau danh sach");

    while (P != EndList(L))
    {

        printf("%d\t", Retrieve(P, L));

        P = Next(P, L);
    }
}

void Read_List(List *L)
{
    int i, N;

    ElementType X;

    MakeNull_List(L);

    printf("Nhap vao so phan tu co trong danh sach: ");

    scanf("%d", &N);
    fflush(stdin);

    for (i = 1; i <= N; i++)
    {

        printf("\nPhan tu thu %d la ", i);

        scanf("%d", &X);

        fflush(stdin);

        Insert_List(X, EndList(*L), L);
    }
}

Position Locate(ElementType X, List L)
{

    Position P;

    int found = 0;

    P = FirstList(L);

    while ((P != EndList(L)) && (found == 0))
    {
        if (Retrieve(P, L) == X)
        {
            found = 1;
        }
        else
            P = Next(P, L);
    }
    return P;
}
