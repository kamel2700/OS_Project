#include <stdio.h>
struct Node{
    int val;
    struct Node *next;
};
struct LinkedList{
    struct Node* head;
} ;

void insert_node(struct Node node, struct LinkedList* list){
    if((*list).head == NULL){
        (*list).head = &node;
        return;
    }
    struct Node current = *(*list).head;
    while(current.next!=NULL){
        current = *current.next;
    }
    current.next = &node;
}

void delete_node(struct Node node, struct LinkedList *list){
    if((*list).head == NULL)
        return;
    struct Node current = *(*list).head;
    while(current.next!=NULL&&(*current.next).val!=node.val&&(*current.next).next!=node.next){
        current = *current.next;
    }
    if((*current.next).val==node.val&&(*current.next).next==node.next){
        current.next = node.next;
    }
}

void print_list(struct LinkedList list){
    if(list.head==NULL){
        return;
    }
    struct Node current = *list.head;
    while(current.next!=NULL){
        printf("%d ", current.next);
        current = *current.next;
    }
    printf("%d\n",current.val);
}



int main()
{
    struct LinkedList list;
    list.head = NULL;
    printf("\n%d\n",list.head);
    print_list(list);
    struct Node node;
    node.val = 2;
    node.next = NULL;
    insert_node(node, &list);
    printf("%d ", list.head);
    return 0;
}
