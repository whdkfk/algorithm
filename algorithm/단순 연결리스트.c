#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct Node{
	char data[100];
	struct Node* next;
}Node;
Node* insertFirst(Node* head, char* data){
	Node* node = (Node* )malloc(sizeof(Node));
	strcpy(node->data, data);
	node->next = head;
	return node;
	
	
}
Node* insert(Node* head, Node* pre, char* data){
	Node* node = (Node *)malloc(sizeof(Node));//1) 새로운 노드 생성하고
	strcpy(node->data, data); //2)값 저장
	node->next = pre->next->next;//3) 새 노드 next값에 pre의 next값 저장
	pre->next =  node;
	
}
Node* deleteFirst(Node* head){
	if (head == NULL) return NULL;
	 Node* removed = head;//1) removed 노드에 헤드포인터의 주소를 저장
   Node* newhead = head->next;//2) 헤드포인터를  헤드포인터->next 로 변경 저장
   free(removed); //3) removed의 주소 반환
   return newhead;
}
Node* delete(Node* head, Node* pre){
	//프리가 가리키는 다음 노드를 삭제
	Node* removed = pre->next;
	pre->next = pre->next->next;// pre->next->next와 같은 주소
	free(removed);
}
void printList(Node* head){

	while(head!=NULL){
		printf("%s->", head->data);//6.head가 널이 아니면 노드데이터 출력
		head = head->next;
		
	}
	printf("NULL\n");
		
}
int main(){
	Node* head = NULL;
	Node* p;
  char str[3][10] ={"melon","kiwi","apple"};
	char find[10];
	//코드 작성
	head = insertFirst(head,str[0]); //melon 입력
	printList(head);
	head = insertFirst(head, str[1]);
	printList(head);
	head = insertFirst(head, str[2]);
	printList(head);
	printf("찾을 데이터를 입력하세요\n");
	scanf("%s",find);
	for(p=head;p!=NULL;p=p->next){
	if	(strcmp(p->data,find) == 0) printf("%s을 찾았습니다.",find);
	}
	return 0;
}

