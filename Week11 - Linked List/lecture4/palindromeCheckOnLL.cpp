#include<iostream>
using namespace std;
class Node{
        public:
        int data;
        Node* next;

        Node(int data) {
                this->data = data;
                this->next = NULL;
        }
};

Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = curr -> next;
        while(curr != NULL) {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
        }
        return prev;
}

bool checkPalindrome(Node* &head) {
    if(head==NULL) {
        cout<<"LL is empty"<<endl;
        return true;
    }
    if(head->next==NULL) {
        return true;
    }
    //>1 node in LL
    //Step A: find the middle node
    Node* slow = head;
    Node*fast= head->next;
    while(fast!=NULL) {
        fast=fast->next;
        if(fast!=NULL) {
            fast=fast->next;
            slow=slow->next;
        }
    }
    // slow pointer is pointing to the middle node
    //Step B: reverse the LL from the middle node
    Node*reverseLLKaHead=reverse(slow->next);
    slow->next=reverseLLKaHead;
    //Step C: compare the first half and second half
    Node*temp1=head;
    Node*temp2=reverseLLKaHead;
    while(temp2!=NULL) {
        if(temp1->data!=temp2->data) {
            return false;
        } else {
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return true;
}

int main() {
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(30);
  Node* fifth = new Node(20);
  Node* sixth = new Node(10);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;

  bool isPalindrome = checkPalindrome(head);

  if(isPalindrome) {
          cout << "LL is a valid palindrome" << endl;
  }
  else {
          cout << "LL is not a palindrome" << endl;
  }
  return 0;
}