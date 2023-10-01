#include <stdio.h>
#include <conio.h>
#include <malloc.h>

//khai bao danh sach lien ket

typedef int ElementType;

//typedef int Position;

struct Node {
    
    ElementType Element; //chứa nội dung phần tử
    struct Node* Next; //trỏ tới phần tử kế tiếp

};

typedef struct Node* Position; //kieu vi tri

typedef Position List;

//tao danh sach rong
void MakeNull_List ( List *Header) {
    (*Header) = (struct Node*)malloc(sizeof(struct Node));
    (*Header) -> Next = NULL;
}

//ham kiem tra danh sach rong 
int Empty_List (List L) {
    return(L->Next == NULL);
}

//them phan tu co noi dung X vao vi tri P trong danh sach lien ket

void Insert_List (ElementType X, Position P, List *L) {
    Position T ;
    T = (struct Node*) malloc (sizeof(struct Node));
    T -> Element = X;
    T -> Next = P->Next;
    P -> Next = T;
}

//xoa phan tu tai vi tri P ra khỏi danh sach

void Delete_List (Position P, List *L) {
    Position T;
    if (P -> Next != NULL) {
        // giữ ô chứa phần tử cần xóa để thu hồi vùng nhớ
        T = P->Next;
        // nối kết con trỏ chỉ tới phần tử kế tiếp
        P -> Next = P -> Next -> Next;

        //giải phóng vùng nhớ
        free(T);
    }
    else {
        printf ("Null list");
    }
}

//tim vi tri dau tien cua phan tu co noi dung x
Position Locate (ElementType X, List L) {
    Position P;
    int flag = 0;
    while ( (P->Next != NULL) && (flag == 0) ) {

        if (P->Next->Element == X) {
            flag = 1;
        }
        else {
            P = P -> Next;
        }

    }
    return P;
}

//ham lay noi dung phan tu tai vi tri P trong danh sach

ElementType Retrieve (Position P, List L) {

    if (P->Next != NULL) {
        return P ->Next ->Element;
    }

}

//ham tra ve vi tri dau tien cua danh sach

Position First (List L) {
    return L;
}

//ham tra ve vi tri Endlist 
Position EndList (List L) {
    Position P;
    P = First(L);
    while (P -> Next != NULL) {
        P = P -> Next;
    }
    return P;
}

//ham tra ve vi tri phan tu ke tiep 
Position Next (Position P ,List L) {
    return P->Next;
}

//in danh sach ra man hinh 

void Print_List (List L) {
    Position P;
    for (P = First(L); P<EndList(L); P = P -> Next){
        printf("%d\t", Retrieve(P, L));
    }
}

//nhap danh sach

void Read_List (List *L) {

    int i;
    int n; // so phan tu co trong danh sach
    int t;

    ElementType x; // nhan gia tri tu ban phim day vao list

    Position P = First(*L);

    printf("SO PHAN TU TRONG DANH SACH : "); scanf("%d", &n);

    for(int i = 1; i<= n; i++) {

        printf("Phan tu %d ", i);
        scanf("%d", &x);

        Insert_List(x, EndList(*L), L);
    }

}


int main () {
    
    

    List L;
    
    MakeNull_List(&L);
    printf("Da tao danh sach rong \n");
    printf("Nhap gia tri cho danh sach \n");
    Read_List(&L);

    printf("In danh sach ra man hinh\n");

    Print_List(L);

    return 0;
}