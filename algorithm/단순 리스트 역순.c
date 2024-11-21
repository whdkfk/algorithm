#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;

void printList(Node *head){
	Node* p = head;
	while(p!=NULL){
		printf("%d", p->data);
		if (p->next != NULL) {
			printf("->");
		}
		p = p->next;
	}
	printf("\n");
}
Node* reverse(Node *head){
	Node *p,*q, *r;
	p = head;
	q = NULL;
	while(p!=NULL){
		r = q;
		q = p;
		p = p->next;
		q ->next = r;
	}
	return q;
  // 연결 리스트를 역순으로 연결하는 함수 작성
}
// 첫번째 노드로 삽입하는 연산
Node*  insertFirst(Node *head, int data ){
	Node* node = (Node* )malloc(sizeof(Node));
	node->data = data;
	node->next = head;
	return node;
}

int main(){
	Node* head = NULL ;
	for(int i=10;i<=50;i+=10){
		head = insertFirst(head, i);//insertFirst 함수호출
		printList( head );
	}
	reverse(head);//역순으로 연결하는 함
	printf("역순으로 출력\n");
	printList( head );	
	return 0;
}