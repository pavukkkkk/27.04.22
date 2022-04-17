#include <iostream>
using namespace std;
#include <string>
class VectorException {
private:
    string str;
public:
    VectorException(string massage) : str(massage) {}
    string what() {
        return str;
    }
};

template <typename type> class SimpleVector{
    int len,ind1x;
    type* m;
public:
    int lentgth(){
        return ind1x;
    }
    SimpleVector(int n): len(n), ind1x(0){
        m=new type[len];
    }
   
  
    void push_back(type a){
        if (ind1x>=len)
        {
            newm();
        }
        
        m[ind1x]=a;
        ind1x++;
        
    }
    int indexmin(){
        int flag=0;
        type a=0;
        for (int i=0;i<ind1x;i++){
            if (m[i]<a || flag==0){
                flag=1;
                a=m[i];
            }
        }
        return a;
    }
    int find(type a){
        for (int i =0; i<=ind1x; i++){
            if (m[i]==a)
                return i;
        }
        return -1;
    }
    void newm(){
        type* m1=new type[len*2];
        for (int i =0; i<len;i++){
            m1[i]=m[i];
        }
        type* m=new type[len*2];
        for (int i =0; i<len;i++){
            m[i]=m1[i];
        };
        delete [] m1;
        m1=nullptr;
   
        len=len*2;
    }
    int &operator[] (int i) {
        if (i>=ind1x){
            throw VectorException("index_out_of_range");
        }
        return m[i];
        
    }
   bool remove(type a){
        int k=find(a);
        if (k>-1){
        for (int i = k; i < ind1x - 1; i++) {
                           m[i]=m[i + 1];
                       }
                       ind1x --;
            return true;
    }
        return false;
    }
    bool insert_after(type x, type y){
        int k=find(y);
        if (k>=len)
        {
            newm();
        }
        if (k>-1){
            for (int i = ind1x; i > k; i--) {
                            m[i] = m[i - 1];
                        }
                    
                        m[k+1] = x;

            ind1x ++;
            
            return true;
    }
        return false;
    }
    
    
    bool insert_before(type x, type y){
        int k=find(y);
        if (k>=len)
        {
            newm();
        }
        if (k>-1){
            for (int i = ind1x; i > k; i--) {
                            m[i] = m[i - 1];
                        }
                    
                        m[k] = x;

            ind1x ++;
            
            return true;
    }
        return false;
    }
    //A
    /*
     Время работы = O(n^2), т.к. поиск просходит за линейное время, а вставка за n^2
     */
    void zero(){
        type k;
        k=indexmin();
        insert_after(0, k);
        insert_before(0, k);
    }
    //B
    /*
     Время работы = O(n), т.к. поиск просходит за линейное время, а замена за O(1)
     */
    void changemiddle(){
        int flag=0;
        type a=1;
   
        for (int i=0;i<ind1x;i++){
            if ((m[i]<a || flag==0)&&m[i]<0){
                flag=1;
                a=m[i];
                
            }
        }
        if (ind1x%2==0 || a>0){
            throw VectorException("Error_changemiddle");
        }
        else{
            int t=ind1x/2;
            m[t]=a;
        }
    }
    ~SimpleVector<type>(){
        delete[] m;
        m=nullptr;

    }
    
};

int main() {
    try{
        
    
    SimpleVector<int> m(1);

        
            m.push_back(10);
        m.push_back(3);
        m.push_back(-1);
        m.push_back(-2);
        m.push_back(0);
        m.push_back(-5);
        m.push_back(7);
        m.changemiddle();

        for (int i=0; i<m.lentgth();i++){
            cout<<m[i]<<endl;
        }
        
    m.~SimpleVector();
  
    }
    catch(VectorException s){
           cout<<s.what()<<endl;
       }
}
