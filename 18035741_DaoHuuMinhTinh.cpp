#include <stdlib.h>
#include <stdio.h>
#include <NEW>

//Khai bao cau  mot node
struct Node{
	int data;
	Node *link;
};

//Khai bao cau truc mot danh sach
struct List{
	Node *first, *last;
};

//Khoi tao danh sach rong
void Init(List &l){
	l.first = l.last = NULL;
}

//Tao mot node
Node *GetNode(int x){
	Node *p;
	p = new Node;
	if(p != NULL)
		return NULL;
	p->data = x;
	p->link = NULL;
	return p;
}

//Them mot node moi vao dau danh sach
void AddFirst(List &l, Node *new_ele){
	if(l.first == NULL) //Danh sach rong
	{
		l.first = new_ele;
		l.last = l.first;
	}
	else{
		new_ele->link = l.first;
		l.first = new_ele;
	}
}

//Them mot node vao cuoi danh sach
void addLast(List &l, Node *new_node)
{
	if (l.first == NULL)  
	{
		l.first = l.last = new_node;
	}
	else
	{
		l.last->link = new_node;
		l.last = new_node ;
	}	
}
//Them mot node moi co gia tri x vao dau danh sach
void InsertFirst(List &l, int x){
	Node *new_ele = GetNode(x);
	if(new_ele == NULL)
		return;
	AddFirst(l, new_ele);
}

//Them mot node moi co gia tri x vao cuoi danh sach
void InsertLast(List &l, datatype x)
{	
		NODE* new_node = GetNode(x);
		if (new_node == NULL)
			return;
		addLast(l, new_node);

}

//Tao danh sach bang cach them vao dau
void CreateListFirst(List &l){
	int x;
	printf("\nBat dau nhap danh sach cac so nguyen, nhap -1 de ket thuc: \n");
	scanf("%d", &x);
	while(x != -1){
		InsertFirst(l, x);
		printf("\nBat dau nhap danh sach cac so nguyen, nhap -1 de ket thuc: \n");
		scanf("%d", &x);		
	}
	printf("\nDa nhap du lieu xong: \n");
}

//Xoa node dau danh sach
int removeFirst (List &l)
{
	if (l.first == NULL) return 0;
	Node* p = l.first;
	l.first = p->link;
	if (l.first == NULL)  l.last = NULL; //N?u danh sách sau khi xóa là r?ng
	delete p;
	return 1;
}

//Xóa node sau node q trong danh sách
int removeAfter (List &l, Node *q )
{
	if (q !=NULL && q->link !=NULL)
	{
		Node*   p = q->link;
		q->pNext = p->link;
		if  (p == l.last)	 l.last = q;
		delete p;
		return 1;
	}
	else return 0;
}

//Xóa node có khoá k
int removeNode  (List &l, int k) 
{	
	Node    *p = l.first; 
	Node    *q = NULL;   
	while  (p != NULL) 
	{ 
		if  (p->data == k) break; 
		q = p;    
		p = p->link; 
	} 
	if (p == NULL)  { cout<<“Khong tim thay”; return 0;}
	else if (q != NULL) 
            { if(p == l.last)      l.last = q; 
               q->link = p->link; 
               delete p; 
              }      

//Xuat danh sach
void PrinttList(List l){
	Node 	*p;
	p = l.first;
	while(p != NULL){
		printf("%10d", p->data);
		p = p->link;
	}
}

//Xoa toan bo danh sach
void RemoveList(List &l){
	Node *p;
	while(l.first != NULL){
		p = l.first;
		l.first = p->link;
		delete p;
	}
	L.last = NULL;
}
//Hoan doi
void Swap(int &c, int &d){
	int t;
	t=c;
	c=d;
	d=t;
}

//Interchange Sort 
void   SLL_InterChangeSort ( List  &l )
{
	for ( Node* p=l.first ; p!=l.last ; p=p->link )
		for ( Node* q=p->link ; q!=NULL ; q=q->link )
			if ( p->data > q->data )
				Swap( p->data , q->data );
} 

//Selection sort 
void	ListSelectionSort (LIST &l)
{	
	for ( Node* p = l.first ; p != l.last ; p = p->link )
 	{
		Node* min = p;
		for ( Node* q = p->link ; q != NULL ; q = q->link )
				if ( min->data > q->data ) min = q ;
				 	Swap(min->data, p->data); 
	}
}


int main(){
	int x;
	List L;
	Init(L);
	CreateListFirst(L);
	printf("\n Danh sach la: ");
	PrinttList(L);
	return 0;
}

