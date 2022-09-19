#include <iostream>
using namespace std;

template<class T>
class linkedlist{
  public:
  class node{
    public:
    T data;
    node* next;
    node* prev;
  };
  class iterator{
    public:
    node *p; 
    iterator(){ 
      p = nullptr;
    }
    iterator(node* n)
    { 
      p = n;
    }
    iterator(const iterator& i)
    { 
      this->p = i.p;
    }
    iterator& operator++ ()
    { 
      p = p->next; 
      return *this;
    }
    iterator& operator-- ()
    { 
      p = p->prev; 
      return *this;
    }
    T operator* ()
    { 
      return p->data;
    }
    T operator[] (int index)
    { 
      for (int i=0; i<index; i++) 
          p=p->next;
      return p->data;
    }
    bool operator== (const iterator& i)
    { 
      return this->p == i.p;
    }
    bool operator!= (const iterator& i)
    { 
      return this->p != i.p;
    }
  };
  public:
  node* head;
  node* tail;
  linkedlist(){
    head = createNode(-1);
    tail = createNode(-1);
    head->next = tail;
    tail->next = head;
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
    tail->next = head;
  }
  void displayList(void){
    node* ptr = head->next;
    while(ptr!=tail){
      cout<<ptr->data<<"\t";
      ptr = ptr->next;
    }
    cout<<endl;
  }
  iterator Begin(){ 
    return iterator(head->next);
  }
  iterator RBegin(){ 
    return iterator(tail->prev);
  }
  iterator End(){ 
    return iterator(tail);
  }
  iterator REnd(){ 
    return iterator(head);
  }
};

int main(){
  linkedlist<int> l;
  l.push(10);
  l.push(20);
  l.push(30);
  l.push(40);
  linkedlist<int>::iterator i;
  for (i = l.Begin(); i!=l.End(); ++i) 
  {
    cout<<*i<<" "; 
  } 
  cout<<endl;
  return 0;
}