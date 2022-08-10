#include <iostream>
using namespace std;

template<class T>
class my_vector_bad{
  int size;
  int capacity;
  T* arr;
  public:
  my_vector_bad(){
    size = -1;
    capacity = 1;
    arr = new T[capacity];
  }
  void push_back (T val){
    size++;
    if(capacity>size)
      arr[size] = val;
    else{
      T* temp;
      temp = new T [capacity+1];
      for (int i=0;i<capacity;i++){
        temp[i] = arr[i];
      }
      temp[size]=val;
      arr = temp;
      capacity +=1;
    }
  }
  T pop_back (void){
    T val = arr[size];
    T* temp = new T [size];
    for (int i=0;i<size;i++){
        temp[i] = arr[i];
    }
    arr = temp;
    capacity = size;
    size--;
    return val;
  }
  void display_list(void){
    cout<<"Elements present in list are:\n";
    for (int i=0; i<capacity;i++)
      cout<<arr[i]<<"\t";
    cout<<endl;
  }
  
};

int main() 
{
    my_vector_bad<int> list;
    for (int i=0; i<5; i++){
      list.push_back(i+1);
      list.display_list();
    }
    for (int j=0; j<=4; j++){
      cout<<"Extracted\t"<<list.pop_back()<<"\tfrom list"<<endl;
      list.display_list();
    }
    return 0;
}