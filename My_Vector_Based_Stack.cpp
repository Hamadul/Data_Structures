#include <iostream>
using namespace std;

template<class T>
class my_vector_based_stack{
  int size;
  int capacity;
  T* arr;
  public:
  my_vector_based_stack(){
    size = -1;
    capacity = 1;
    arr = new T[capacity];
  }
  void push (T val){
    size++;
    if(capacity>size)
      arr[size] = val;
    else{
      T* temp;
      temp = new T [capacity*2];
      for (int i=0;i<capacity;i++){
        temp[i] = arr[i];
      }
      temp[size]=val;
      arr = temp;
      capacity *=2;
    }
  }
  T peak (void){
    return arr[size];
  }
  void pop (void){
    T temp = arr[size];
    arr[size] = NULL;
    if (size>capacity/2){
      size--;
    }
    else if(size<=capacity/2){
      T* temp = new T [capacity/2];
      for (int i=0;i<capacity/2;i++){
        temp[i] = arr[i];
        size = i;
      }
      arr = temp;
      capacity /=2;
    }
  }
  void print_stack(void){
    cout<<"Elements present in stack are:\n";
    for (int i=0; i<capacity;i++)
      cout<<arr[i]<<"\t";
    cout<<endl;
  }
  
};

int main() 
{
    my_vector_based_stack<int> mystack;
    for (int i=0; i<8; i++){
      mystack.push(i+1);
      mystack.print_stack();
    }
    for (int j=0; j<=4; j++){
      cout<<"Extracted\t"<<mystack.peak()<<"\tfrom list"<<endl;
      mystack.pop();
      mystack.print_stack();
    }
    return 0;
}