#include <iostream>
using namespace std;

template<class T>
class LinkedList{
    class node{
        public:
            T data;
            node* next;
            node* prev;
    };
    node* head;
    node* tail;
    public:
        LinkedList(){
            head = createNode(-1);
            tail = createNode(-1);
            head->next = tail;
            tail->prev = head;
        }
        node* createNode (T val){
            node* temp = new node();
            temp->data = val;
            temp->next = nullptr;
            temp->prev = nullptr;
            return temp;
        }
        void push (T val){
                tail->data = val;
                tail->next = createNode(-1);
                tail->next->prev = tail;
                tail = tail->next;
        }

        T pop (void){
          if(head->next!=tail){
            node* temp = head->next;
            T val = temp->data;
            head->next = temp->next;
            temp->next->prev = head;
            delete temp;
            return val;
          }
          return -1;
        }
        bool search (T val){
            node* ptr = head->next;
            while(ptr!=tail){
                if(ptr->data == val){
                    return true;
                }
                ptr=ptr->next;
            }
            return false;
        }
        void deleteElement (T val){
            node* ptr = head;
            while(ptr!=tail && ptr->next->data != val)
                ptr = ptr->next;
            if(ptr!=tail){
                node* temp = ptr->next;
                ptr->next = temp->next;
                temp->next->prev = ptr;
                delete temp;
                cout<<"Deleted\n";
            }
            else
                cout<<"Not Found\n";
        }

        void printList (void){
            node* ptr=head->next;
            while(ptr!= tail){
                cout<<ptr->data<<"\t";
                ptr=ptr->next;
            }
            cout<<endl;
        }
        void printListReverse (void){
            node* ptr=tail->prev;
            while(ptr!= head){
                cout<<ptr->data<<"\t";
                ptr=ptr->prev;
            }
            cout<<endl;
        }

};

int main(){
    LinkedList<int> l;
    for (int i=0; i<7; i++)
      l.push(i+1);
    l.printList();
    cout<<"Popping\t"<<l.pop()<<endl;
    cout<<"Popping\t"<<l.pop()<<endl;
    l.deleteElement(7);
    l.deleteElement(3);
    l.deleteElement(5);
    l.printListReverse();
    l.printList();
    return 0;
}