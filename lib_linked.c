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

int member (ElementType x, List L) {
    
    int flag = 0;
    Position P = L;
    while (P -> Next != NULL) {
        if (P -> Next -> Element == x) {
            return flag = 1;
        }
        P = P -> Next;
    }
    return flag;
    
}

void append (ElementType x, List *pL) {
    
    Position P = EndList(*pL);
    Position T = (struct Node*)malloc(sizeof(struct Node));
    T -> Element = x;
    T -> Next = NULL;
    P -> Next = T;
    
}

void normalize(List *pL) {
    
    Position p = *pL;
    
    while (p->Next != NULL) {
        
       Position q = p -> Next;
        
        while (q->Next != NULL) {
                
            if (p->Next->Element == q->Next->Element) {
                
                deleteList(q, &(*pL));
            } 
            else {
                q = q->Next;
            }
        }
        p = p->Next;
    }
    
}

/*bai tap tren else */

/*
Bằng cách sử dụng những phép toán trên tập hợp, hãy viết chương trình cho phép tìm tập hợp hợp của 2 danh sách biểu diễn tập hợp

Gợi ý

Khai báo kiểu List
Định nghĩa các hàm nhập tập hợp và hiển thị danh sách
Định nghĩa hàm tìm tập hợp hợp của 2 tập hợp
Gọi thực thi các hàm trên trong hàm main()
*/

typedef int ElementType;

struct Node {
    ElementType Element;
    struct Node* Next;
};

typedef struct Node* Position;
typedef Position List;


void makenullList(List *pL) {
    *pL = (struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}

void insert (ElementType x, Position P, List *pL) {

    Position T = (struct Node*)malloc(sizeof(struct Node));
    T -> Element = x;
    T -> Next = P -> Next;
    P -> Next = T;

}

Position first (List L) {
    return L;
}

Position endList (List L) {
    Position P = L;
    while (P -> Next != NULL) {
        P = P -> Next;
    }
    return P;
}

int member (ElementType x, List L) {
    Position P = L; 
    int flag = 0;
    while (P->Next != NULL) {
        if (P->Next->Element == x) {
            return flag = 1;
        }
        P = P -> Next;
    }
    return flag;
}

void nhap (List *pL) {
    
    //printf("\nNhap so luong phan tu: ");
    
    int n;

    scanf("%d", &n);

    ElementType x;

    for (int i = 0; i < n; i++) {
        //printf("\nNhap phan tu: ");
        
        scanf("%d", &x);

        if (!(member(x, *pL))) {
            insert(x, first(*pL), &(*pL));
        }
    }
}

void in (List L) {
    
    Position P = L;
    while (P-> Next != NULL) {

        printf("%d ", P->Next->Element);
              
        P = P -> Next;
    }
    printf("\n");
}



List hop (List L1, List L2) {
    
    List L3;
    
    makenullList(&L3);
    
    Position P1 = L1;

    while (P1->Next != NULL) {
        insert(P1->Next->Element, endList(L3), &L3);
        P1 = P1 -> Next;
    }

    Position P2 = L2;
    while (P2 -> Next != NULL) {
        if (!member(P2 -> Next -> Element, L1)) {
            insert(P2 -> Next -> Element, endList(L3), &L3);
        }
        P2 = P2 -> Next;
    }
    
    return L3;
}

// int main () {

//     List L1, L2;
//     makenullList(&L1);

//     makenullList(&L2);

//     //printf("Nhap L1: \n");
//     nhap(&L1);
//     //printf("in: \n");
//     in (L1);

//     //printf("Nhap L2: \n");
//     nhap(&L2);
//     //printf("in: \n");
//     in (L2);

//     //printf("Giao L1 vs L2: \n");
//     in(hop(L1, L2));

//     return 0;
// }


/*
Bằng cách sử dụng những phép toán chuẩn trên danh sách, hãy viết chương trình cho phép xóa phần tử x xuất hiện đầu tiên trong danh sách

Gợi ý

Khai báo kiểu List
Định nghĩa các hàm nhập và hiển thị danh sách
Định nghĩa hàm xóa phần tử x được tìm thấy đầu tiên trong danh sách
Hàm main()
            - Gọi thực thi hàm nhập và hiển thị trong hàm main()

            - Nhập vào một giá trị x

            - Gọi hàm xóa phần tử x xuất hiện đầu tiên

            - Hiển thị kết quả
*/

/*
Bằng cách sử dụng những phép toán chuẩn trên danh sách, 
hãy viết chương trình cho phép xóa phần tử x xuất hiện đầu tiên trong danh sách
*/

#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

struct Node {
    ElementType Element;
    struct Node* Next;
};

typedef struct Node* Position;
typedef Position List;

void makenullList (List *pL) {
    *pL = (struct Node*) malloc (sizeof(struct Node));
    (*pL) -> Next = NULL;
}

Position first (List L) {
    return L;
}

Position endList (List L) {
    Position P = L;
    while (P->Next != NULL) {
        P = P->Next;
    }
    return P;
}

Position locate (ElementType x, List L) {
    Position P = L;
    
    int found = 0;

    while (P-> Next != NULL && found == 0) {

        if (P->Next->Element == x) {
            found = 1;
        }
        else {
            P = P ->Next;
        }
    }
    return P;
}

void insert (ElementType x, Position P, List *pL) {
    Position T = (struct Node*) malloc (sizeof(struct Node));
    T -> Element = x;
    T -> Next = P -> Next;
    P -> Next = T;
}

void delete (Position P, List *pL) {
    
    Position T;
    
    if (P-> Next != NULL) {
        
        T = P -> Next;

        P ->Next = P-> Next->Next;

        free(T);
    }

    else {
        printf("DS Rong");
    }
}



void xoa (List *pL) {

    ElementType x;
    scanf("%d", &x);
    Position P = *pL;

    while (P -> Next != NULL) {
        if (P -> Next -> Element == x) {
            delete(locate(x, *pL), &(*pL));
            break;
        }
        else {
            P = P ->Next;
        }
        
    }

}

void nhap (List *pL) {

    
    int n;
    scanf("%d", &n);

    ElementType x;

    for (int i = 0; i < n; i++) {

        scanf("%d", &x);
        insert(x, endList(*pL), pL);

    }

}

void in (List L) {
    Position P = L;
    while (P->Next != NULL) {
        printf("%d ", P->Next->Element);
        P = P -> Next;    
    }
    printf("\n");
}

// int main () {

//     List L; 
//     makenullList(&L);
//     //printf("\nNhap: ");
//     nhap(&L);
//     //printf("\nIn: ");
//     in(L);
//     //printf("\nxoa: ");
//     xoa(&L);
//     //printf("\nIn: ");
//     in(L);
//     return 0;
// }

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
