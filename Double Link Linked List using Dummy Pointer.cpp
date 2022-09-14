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
            head = tail = nullptr;
        }
        node* createNode (T val){
            node* temp = new node();
            temp->data = val;
            temp->next = nullptr;
            temp->prev = nullptr;
            return temp;
        }
        void push (T val){
            if(head ==nullptr)
                head = tail = createNode(val);
            else{
                tail->next = createNode(val);
                tail->next->prev = tail;
                tail = tail->next;
            }
        }

        T pop (void){
          if(head){
            node* temp = head;
            T val = head->data;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return val;
          }
          return -1;
        }

        void printList (void){
            node* ptr=head;
            while(ptr){
                cout<<ptr->data<<"\t";
                ptr=ptr->next;
            }
            cout<<endl;
        }
        
        void printListReverse (void){
            node* ptr=tail;
            while(ptr){
                cout<<ptr->data<<"\t";
                ptr=ptr->prev;
            }
            cout<<endl;
        }
        
        bool search (T val){
            node* ptr = head->next;
            if(head->data == val && head)
                return true;
            else if(tail->data == val && tail)
                return true;
            else{
                while(ptr != tail && ptr){
                    if(val == ptr->data)
                        return true;
                    ptr=ptr->next;
                }
            }
            return false;
        }
private:
        void deleteAtHeadHelper(){
            node* ptr = head;
            head = head->next;
            head->prev = nullptr;
            delete ptr;
        }
        void deleteAtTailHelper(){
            node* ptr =head;
            node* temp;
            while(ptr->next != tail)
                ptr = ptr->next;
            temp = ptr->next;  
            ptr->next = nullptr;
            tail = ptr;
            delete temp;
        }
        node* deleteHelper (T val){
            node* ptr = head;
                while(ptr->next != tail && ptr){
                    if(val == ptr->next->data)
                        return ptr;
                    ptr=ptr->next;
                }
            return nullptr;
        }
public:
        void deleteNode (T val){
            if(val ==  head->data)
                deleteAtHeadHelper();
            else if (val == tail->data)
                deleteAtTailHelper();
            else{
                node* prevptr = deleteHelper(val);
                if(prevptr){
                node* temp = prevptr->next;
                prevptr->next = temp->next;
                temp->next->prev = prevptr;
                delete temp;
                }
            }
        }
};

int main(){
    LinkedList<int> l;
    for (int i=0; i<9; i++)
      l.push(i+1);
    l.printList();
    l.printListReverse();
    cout<<"Popping:\t"<<l.pop()<<endl;
    cout<<"Popping:\t"<<l.pop()<<endl;
    l.deleteNode(2);
    l.deleteNode(5);
    l.deleteNode(9);
    l.printList();
    l.printListReverse();
    return 0;
}
