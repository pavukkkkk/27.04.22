#include <iostream>

using namespace std;
class ListException {
private:
    string str;
public:
   ListException(string massage) : str(massage) {}
    string what() {
        return str;
    }
};
template <typename T>
class List
{
  struct Node
  {
    T inf;
    Node* next;
    Node(T x, Node* ref = nullptr) : inf(x), next(ref) {}
  } *first = nullptr, *last = nullptr;
    int size=0;
public:
  void add(T x)
  {
    Node *item = new Node(x);
    if (last != nullptr)
      last->next = item;
    last = item;
    if (first == nullptr)
      first = last;
      size++;
  }
  void print()
  {
    for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
    {
      cout << tmp->inf << " ";
    }
    cout << '\n';
  }

  void doubleX(T x)
  {
    for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
    {
      if (tmp->inf == x)
      {
          size++;
        Node* newItem = new Node(x, tmp->next);
        tmp->next = newItem;
        if (tmp == last)
          last = tmp->next;
        tmp = tmp->next;
      }
    }
      
  }
    void del(T x){
        Node* in=nullptr;
        for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
        {
            if (tmp->inf ==x){
                in = tmp;
                break;
            }
        }
        if (in !=nullptr){
        del1(first,x);
            size--;
        }
        first=in;
        
    }
    void del1(Node* cur, T x) {

               if (cur->inf != x) {
                   Node* i = cur->next;
                   
                   delete cur;
                   del1(i, x);
               }
    }
    List sorting( T x){
        List<T> l2;
        for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
        {
            l2.add(tmp->inf);
            if (tmp->inf==x){
                tmp=tmp->next;
            }
        }
        return l2;
    }
    //A
    /*
     работает за O(n), т.к поиск элементов происходит за O(n), вставка за O(1)
     */
    void zero(T x)
    {
        int flag =0;
        T a=0;
        int j=0,i=0;
        for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
        {
            if (flag==0 || a>tmp->inf){
                a=tmp->inf;
                j=i;
                flag=1;
            }
            i++;
        }
      for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
      {
        if (tmp->inf == a)
        {
          Node* newItem = new Node(0, tmp->next);
          tmp->next = newItem;
          if (tmp == last)
            last = tmp->next;
          tmp = tmp->next;
            break;
        }
      }
        if (j==0){
            Node* newItem = new Node(0);
            newItem->next = first;
            first = newItem;
        }
        else{
            i=0;
            for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
            {
                if(i==j-1){
                    Node* newItem = new Node(0, tmp->next);
                    tmp->next = newItem;
                    if (tmp == last)
                      last = tmp->next;
                    tmp = tmp->next;
                      break;
                }
                i++;
            }
        }
        size+=2;
    }
    //B
    /*
     Время работы = O(n), т.к. поиск просходит за линейное время, а замена за O(1)
     */
    void changemiddle(){
        int flag =0;
        T a=0;
        int j=0,i=0;
        for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
        {
            if (flag==0 || a>tmp->inf){
                a=tmp->inf;
                j=i;
                flag=1;
            }
            i++;
        }
        if (size%2==0 || a>0){
            throw ListException("Error_changemiddle");
        }
        else{
            int i=0;
            for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
            {
                if(i==size/2){
                    tmp->inf=a;
                }
                i++;
            }
        }
    }
};

int main() {
    try{
  List<int> lst;
    lst.add(-4);
  lst.add(5);
    lst.add(2);
  lst.add(1);
    lst.add(3);
  lst.print();
  lst.doubleX(4);
  lst.print();
  lst.add(10);
    lst.print();
    lst.add(-21);
        lst.print();
    lst.changemiddle();
  
  lst.print();
   
    }
    catch(ListException s){
           cout<<s.what()<<endl;
       }
}
