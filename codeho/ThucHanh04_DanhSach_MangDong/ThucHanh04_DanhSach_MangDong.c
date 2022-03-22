#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct darraylist
{
    int * element; // Mang dong element luu toan bo DS
    int last; // chi so cua phan tu cuoi cung
    int size; // kich thuoc (so phan tu toi da) cua mang element
};
typedef struct darraylist DArrayList;

// 1. Ham khoi tao danh sach rong
void DArrayListDefault(DArrayList * someList)
{
    someList->last = -1;
    someList->size = 100;
    someList->element = (int *) malloc (sizeof(int) * someList->size);
}

// 2. Ham khoi tao danh sach bang du lieu luu trong mang so nguyen khac
void DArrayListCopyArray(DArrayList * someList, int arrayList[], int noElement)
{
    // Viet code cua ban o day ...
}

// 3. Ham khoi tao danh sach bang du lieu luu trong tep van ban
void DArrayListCopyFile(DArrayList * someList, char * filename)
{
    // Viet code cua ban o day ...
}

void DArrayListCopyArrayList(DArrayList * someList, const DArrayList * arrayList)
{
    // Viet code cua ban o day ...
}

// 4. Ham kiem tra danh sach co rong khong
int DArrayListEmpty(DArrayList * someList)
{
    return someList->last == -1;
}

// 5. Ham xac dinh do dai danh sach
int DArrayListLength(DArrayList * someList)
{
    return someList->last + 1;
}

// 6. Ham chen gia tri value vao vi tri index trong danh sach
void DArrayListInsert(DArrayList * someList, int index, const int value)
{
    // Viet code cua ban o day ...
}

// 7. Ham chen gia tri value vao cuoi danh sach
void DArrayListAppend(DArrayList * someList, const int value)
{
    // Viet code cua ban o day ...
}

// 8. Ham loai khoi danh sach phan tu o vi tri index
void DArrayListErase(DArrayList * someList, int index)
{
    // Viet code cua ban o day ...
}

// 9. Ham tra ve dia chi cua phan tu o vi tri index
int * DArrayListAt(DArrayList * someList, int index){
    assert(someList->last >= 0 && index <= someList->last && index >= 0);
    return &someList->element[index];
}

// 10. Ham in ra man hinh toan bo danh sach
void DArrayListPrint(DArrayList * someList)
{
    // Viet code cua ban o day ...
}

void testappend(DArrayList * someList, const int value)
{
    printf("Danh sach truoc khi append %i\n", value);
    DArrayListPrint(someList); printf("\n");
    DArrayListAppend(someList, value);
    printf("Danh sach sau khi append %i\n", value);
    DArrayListPrint(someList); printf("\n\n");
}

void testinsert(DArrayList * someList, int index, const int value)
{
    printf("Danh sach truoc khi insert %i vao vi tri %i\n", value, index);
    DArrayListPrint(someList); printf("\n");
    DArrayListInsert(someList, index, value);
    printf("Danh sach sau khi insert %i vao vi tri %i\n", value, index);
    DArrayListPrint(someList); printf("\n\n");
}

void testerase(DArrayList * someList, int index)
{
    printf("Danh sach truoc khi erase tai vi tri %i\n", index);
    DArrayListPrint(someList); printf("\n");
    DArrayListErase(someList, index);
    printf("Danh sach sau khi erase tai vi tri %i\n", index);
    DArrayListPrint(someList); printf("\n\n");
}

int main()
{
    printf("Chuong trinh test KDLTT danh sach so nguyen\n");
    printf("Tac gia: [Your name please]\n--------------------");
/*
    DArrayList L1; DArrayListDefault(&L1); DArrayListPrint(&L1); printf("\n");

    testappend(&L1, 3);
    testappend(&L1, 4);
    testappend(&L1, 5);
    testinsert(&L1, 0, 2);
    testinsert(&L1, 0, 1);
    testinsert(&L1, 2, 3);

    DArrayList L2; DArrayListDefault(&L2);
    testappend(&L2, 4);
    testappend(&L2, 4);
    testappend(&L2, 1);
    testerase(&L2, 2);
    testinsert(&L2, 1, 5);
    testinsert(&L2, 2, 3);

    printf("L2.at(3): %i\n", *(DArrayListAt(&L2, 3)));
    DArrayListPrint(&L2); printf("\n");

    printf("\nL3: input.txt");
    DArrayList L3;
    DArrayListCopyFile(&L3, "input.txt");
    DArrayListPrint(&L3); printf("\n");

    printf("\nL4(L3); L4.insert(0, 10);\n");
    DArrayList L4;
    DArrayListCopyArrayList(&L4, &L3);
    testinsert(&L4, 0, 10);
    DArrayListPrint(&L4); printf("\n");
*/

    return 0;
}
