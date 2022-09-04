#include <iostream>
using namespace std;

template<class T>
class LinkedList{
    class node{
        public:
            T data;
            node* next;
    };
    node* head;
    public:
        LinkedList(){
            head = nullptr;
        }
        node* createNode (T val){
            node* temp = new node();
            temp->data = val;
            temp->next = nullptr;
            return temp;
        }
        void push (T val){
            if(head ==nullptr)
                head = createNode(val);
            else{
                node* temp = createNode(val);
                temp->next = head;
                head = temp;
            }
        }

        void pop (void){
          if(head){
            node* temp = head;
            head = head->next;
            delete temp;
          }
        }

        void printList (void){
            node* ptr=head;
            while(ptr){
                cout<<ptr->data<<"\t";
                ptr=ptr->next;
            }
            cout<<endl;
        }
        T peak (void){
          return head->data;
        }
};

int main(){
    LinkedList<int> l;
    for (int i=0; i<5; i++)
      l.push(i+1);
    cout<<"Peak Value is: "<<l.peak()<<endl;
    l.printList();
    for (int i=0; i<4; i++)
      l.pop();
    l.printList();
    return 0;
}