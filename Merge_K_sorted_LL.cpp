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
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
    }
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
struct comp{
bool operator ()(LLNode *node1,LLNode *node2){
    return node1->data>node2->data;
}
};
void printList(LLNode *head){
    if (head==NULL){
        return ;
    }
    cout << head->data << " ";
    printList(head->next);
}
LLNode * mergeKLists(vector <LLNode *> &heads){
    priority_queue <LLNode *,vector <LLNode *>,comp> pq;
    // push the first node of each list into the min-heap
    for (auto u:heads){
        pq.push(u);
    }
    LinkedList output;
    while (!pq.empty()){
        LLNode *min=pq.top();
        pq.pop();
        output.push_back(min->data);
        if (min->next!=NULL){
            pq.push(min->next);
        }
    }
    return output.head;
}
LLNode * mergeTwoLL(LLNode *head1,LLNode *head2){
    //Base cases
    if (head1==NULL){
        return head2;
    }
    if (head2==NULL){
        return head1;
    }
    //Recursive merge function in Linked List
    LLNode *result;
    if (head1->data <= head2->data){
        result=head1;
        result->next=mergeTwoLL(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeTwoLL(head1,head2->next);
    }
    return result;
}
LLNode * KListsMerge(vector <LLNode *> & lists){
    int k=lists.size();
    if (k==0){
        return NULL;
    }
    int last=k-1;
    while (last!=0){
        int i=0;
        int j=last;
        while (i<j){
            lists[i]=mergeTwoLL(lists[i],lists[j]);
            i++;
            j--;
            if (i>=j){ // if all pairs are merged, update last
                last=j;
            }
        }
    }
    return lists[0];
}
int main(){
    LinkedList l1;
    l1.push_back(1);
    l1.push_back(5);
    l1.push_back(7);
    LinkedList l2;
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(6);
    l2.push_back(9);
    LinkedList l3;
    l3.push_back(4);
    l3.push_back(8);
    l3.push_back(10);
    vector <LLNode *> arr={l1.head,l2.head,l3.head};
    LLNode *head=mergeKLists(arr);
    printList(head);
    LLNode *head1=KListsMerge(arr);
    cout << "\n";
    printList(head1);
    return 0;
}