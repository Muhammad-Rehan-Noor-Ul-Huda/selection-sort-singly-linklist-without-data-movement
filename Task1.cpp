#include<iostream>
using namespace std;
class LinkedList; 
class Node {    
friend class LinkedList; 
private: 
int data; 
Node *next; 
};
class LinkedList {  
private: 
Node *head; 
public: 
LinkedList(); 
~LinkedList(); 
bool insert(int val);
void display();
bool unSortedRemove(int val);
bool search(int val);
void selectionSort();
void reverse();
}; 
LinkedList::LinkedList()
{
    head = nullptr;
}
LinkedList::~LinkedList()
{
    Node* temp=head;
    while(head!=nullptr)
    {
        head=head->next;
        delete temp;
        temp=head;
    }
}
bool LinkedList::insert(int val) 
{
    if (head == nullptr) 
    {
        head = new Node;
        head->data = val;
        head->next=nullptr;
    } else 
    {
        Node* temp = new Node;
        temp->data = val;
        temp->next = head;
        head = temp;
    }
    return true;
}
void LinkedList::display()
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
bool LinkedList::unSortedRemove(int val)
{
    Node* curr=head;
    Node* prev=nullptr;
    while(curr!=nullptr && curr->data!=val)
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr!=nullptr)
    {
        if(prev==nullptr)
        {
            head=head->next;
        }
        else
        {
            prev->next=curr->next;
        }
        
        delete curr;
        curr=nullptr;
        return true;
    }
    else
    {
        return false;
    }
}
bool LinkedList::search(int key) 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        if (temp->data == key) 
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void LinkedList::selectionSort()
{
    Node* curr=head;
    Node* sortedPortion=nullptr;
    Node* prevMin=nullptr;
    if(curr!=nullptr && curr->next!=nullptr)
    {

      while(curr!=nullptr)
      {
            Node* currMin=curr;
            Node* temp=curr;
            while(temp!=nullptr)
            {
                if(prevMin!=nullptr && temp->next==prevMin)
                { 
                    temp->next=temp->next->next;
                }
                if(temp->data<currMin->data)
                {
                    currMin=temp;
                }
                
                temp=temp->next;
                
            }
            if(sortedPortion==nullptr)
            {
                
                head=sortedPortion=currMin;

            }
            else
            {
                sortedPortion->next=currMin;
                sortedPortion=sortedPortion->next;
               
            }
            prevMin=currMin;
             if(currMin==curr)
            {
                    curr=curr->next;
            }
      }

    } 
}
void LinkedList::reverse()
{
    if(head!=nullptr && head->next!=nullptr)
    {
        Node* prev=nullptr;
        Node* curr=head;
        Node* leading=head->next;
        while(leading!=nullptr)
        {
            curr->next=prev;
            prev=curr;
            curr=leading;
            leading=leading->next;
        }
        curr->next=prev;
        head=curr;
    }
    
}
int main()
{
    LinkedList l1;
    l1.insert(5);
    l1.insert(8);
    l1.insert(9);
    l1.insert(10);
    l1.insert(11);
    l1.display();
    cout<<endl;
    l1.reverse();
    l1.display();
    return 0;
}