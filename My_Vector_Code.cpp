#include <iostream>
using namespace std;

template<class T>
class my_vector{
  T data;
  int size;
  int capacity;
  T* arr;
  public:
  my_vector(){
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
      temp = new T [capacity*2];
      for (int i=0;i<capacity;i++){
        temp[i] = arr[i];
      }
      temp[size]=val;
      arr = temp;
      capacity *=2;
    }
  }
  T pop_back (void){
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
    return temp;
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
    my_vector<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    list.push_back(11);
    list.push_back(12);
    list.display_list();
    cout<<"Extracted\t"<<list.pop_back()<<"\tfrom list"<<endl;
    cout<<"Extracted\t"<<list.pop_back()<<"\tfrom list"<<endl;
    cout<<"Extracted\t"<<list.pop_back()<<"\tfrom list"<<endl;
    cout<<"Extracted\t"<<list.pop_back()<<"\tfrom list"<<endl;
    cout<<"Extracted\t"<<list.pop_back()<<"\tfrom list"<<endl;
    cout<<"Extracted\t"<<list.pop_back()<<"\tfrom list"<<endl;
    list.display_list();
    return 0;
}