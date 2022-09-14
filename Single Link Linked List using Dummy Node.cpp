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
    node* tail;
    public:
        LinkedList(){
            head = createNode(-1);
            tail = createNode(-1);
            head->next = tail;
        }
        node* createNode (T val){
            node* temp = new node();
            temp->data = val;
            temp->next = nullptr;
            return temp;
        }
        void push (T val){
                tail->data = val;
                tail->next = createNode(-1);
                tail = tail->next;
        }

        T pop (void){
          if(head->next!=tail){
            node* temp = head->next;
            T val = temp->data;
            head->next = temp->next;
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

};

int main(){
    LinkedList<int> l;
    for (int i=0; i<7; i++)
      l.push(i+1);
    cout<<l.search(4)<<endl;
    l.deleteElement(4);
    l.deleteElement(7);
    l.deleteElement(1);
    l.printList();
    return 0;
}