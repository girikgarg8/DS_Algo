#include <bits/stdc++.h>
using namespace std;
class LLNode{
    public:
    int data;
    LLNode *next;
    public:
    LLNode(int val){
        this->data=val;
        this->next=NULL;
    }
};
class LinkedList{
    public:
    LLNode *head;
    LLNode *tail;
    void push_back(int data){
        LLNode *node=new LLNode (data);
        if (head==NULL){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
    }
};
 LLNode * findMiddle(LLNode *head){
        LLNode *slow=head;
        LLNode *fast=head;
        while (fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    LLNode *merge(LLNode *h1,LLNode *h2){
        LLNode *newHead=NULL;
        LLNode *newTail=NULL;
        LLNode *temp1=h1;
        LLNode *temp2=h2;
        if ((temp1->data)<=(temp2->data)){
            newHead=temp1;
            newTail=temp1;
            temp1=temp1->next;
        }
        else{
            newHead=temp2;
            newTail=temp2;
            temp2=temp2->next;
        }
        while (temp1!=NULL && temp2!=NULL){
            if ((temp1->data<=temp2->data)){
                newTail->next=temp1;
                newTail=temp1;
                temp1=temp1->next;
            }
            else{
                newTail->next=temp2;
                newTail=temp2;
                temp2=temp2->next;
            }
        }
        while (temp1!=NULL){
            newTail->next=temp1;
            newTail=temp1;
            temp1=temp1->next;
        }
        while (temp2!=NULL){
            newTail->next=temp2;
            newTail=temp2;
            temp2=temp2->next;
        }
        return newHead;
    }
LLNode * MergeSort(LLNode *head){
        if (head==NULL){ //empty list
            return NULL;
        }
        if (head->next==NULL){ // list with only 1 element
            return head;
        }
        LLNode *mid=findMiddle(head);
        LLNode *head1=mid->next;
        mid->next=NULL; //to create the sublist from the list
        LLNode *h1=MergeSort(head);
        LLNode *h2=MergeSort(head1);
        LLNode *newHead=merge(h1,h2);
        return newHead;
}
void print(LLNode *head){
    if (head==NULL){
        return ;
    }
    cout << head->data << " ";
    print(head->next);
}
int main(){
LinkedList l1;
l1.push_back(10);
l1.push_back(50);
l1.push_back(30);
l1.push_back(40);
LLNode *head=l1.head;
LLNode *newHead=MergeSort(head);
print(newHead);
return 0;
}