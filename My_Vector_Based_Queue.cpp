#include <iostream>
using namespace std;

template<class T>
class my_vector_based_queue{
  int size;
  int capacity;
  T* arr;
  public:
  my_vector_based_queue(){
    size = -1;
    capacity = 1;
    arr = new T[capacity];
  }
  void enqueue (T val){
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
  T dequeue (void){
    if(size<=capacity/2){
      T* temp = new T [capacity/2];
      for (int i=0;i<capacity/2;i++){
        temp[i] = arr[i+1];
      }
      T tmp = arr[0];
      arr = temp;
      capacity /=2;
      size--;
      return tmp;
    }
    T tmp = arr[0];
    for (int j=0;j<size;j++)
        arr[j] = arr[j+1];
      arr[size] = NULL;
      size--;
    return tmp;
  }
  void print_queue(void){
    cout<<"Elements present in Queue are:\n";
    for (int i=0; i<capacity;i++)
      cout<<arr[i]<<"\t";
    cout<<endl;
  }
  
};

int main() 
{
    my_vector_based_queue<int> myqueue;
    for (int i=0; i<=8; i++){
      myqueue.enqueue(i+1);
      myqueue.print_queue();
    }
    for (int j=0; j<6; j++){
      cout<<"Extracted\t"<<myqueue.dequeue()<<"\tfrom Queue"<<endl;
      myqueue.print_queue();
    }
    return 0;
}