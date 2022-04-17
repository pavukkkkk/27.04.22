//
//  Header.h
//  27.04.22
//
//  Created by Константин Кириленко on 17.04.2022.
//

#ifndef Header_h

#include <iostream>
#include <string>
#include <fstream>
using namespace std;




class StackException {
private:
    string str;
public:
    StackException(string massage) : str(massage) {}
    string what() {
        return str;
    }
};
class DoubleListException {
private:
    string str;
public:
    DoubleListException(string massage) : str(massage) {}
    string what() {
        return str;
    }
};

class QueueException {
private:
    string str;
public:
    QueueException(string massage) : str(massage) {}
    string what() {
        return str;
    }
};

class ListException {
private:
    string str;
public:
    ListException(string message) : str(message) {}
    string what() {
        return str;
    }
};

template <class Item> class List {
    struct Element {
        Item inf;
        Element* next;
        Element(Item x) :inf(x), next(0) {};
    };
    Element* head;
    Element* tail;
    int size;
    Element* Find(int index) {
        if ((index < 1) || (index > size)) {
            return NULL;
        }
        else {
            Element* cur = head;
            for (int i = 1; i < index; i++) {
                cur = cur->next;
            }
            return cur;
        }
    }
    void Read1(Element* cur, ifstream &in){
        
            Item value;

        if (in>>value){
            
            Element* newPtr = new Element(value);
            size ++;
            if (cur == NULL) {
            
                head = newPtr;
                tail = newPtr;
            }
            else {
                newPtr->next = cur->next;
                cur->next = newPtr;
                if (cur == tail) {
                    tail = newPtr;
                
                }}

        Read1(newPtr,in);
            }
        }
public:
    List() : head(0), size(0),tail(0) {}
    ~List() {
        while (!Empty()) {
            Remove(1);
        }
    }
    bool Empty() {
        return head == 0;
    }
    int GetLength() {
        return size;
    }
    Item Get(int index) {
        if ((index < 1) || (index > size)) {
            throw ListException("ListException: get - list error");
        }
        else {
            Element* r = Find(index);
            Item i = r->inf;
            return i;
        }
    }
    void Insert(int index, Item data) {
        if ((index < 1) || (index > size + 1)) {
            throw ListException("ListException: insert - list error");
        }
        else {
            Element* newPtr = new Element(data);
            
            size++;
            if (index == size){
                tail=newPtr;
            }
            if (index == 1) {
                newPtr->next = head;
                head = newPtr;
            }
            else {
                Element* prev = Find(index - 1);
                newPtr->next = prev->next;
                prev->next = newPtr;
            }
        }
        
    }
    void Read(int index, ifstream &in){
        if ((index < 1 && head != NULL) || (index > size + 1)) {
           
        throw DoubleListException("Exception: insert ó double-linked list error");
    }
        
        else{
            Element* cur = Find(index);
            
            Read1(cur, in);
        }
    }
    
    void Pushback(Item data){
        size++;
        Element* newPtr = new Element(data);
        if (size ==1){
            head = newPtr;
            tail = newPtr;
           
        }
        else{
        tail->next = newPtr;
            tail=newPtr;}
                    
                
            
        
    }
    void Remove(int index) {
        if ((index < 1) || (index > size)) {
            throw ListException("ListException: remove - list error");
        }
        else {
            Element* cur;
            --size;
            if (index == 1) {
                cur = head;
                head = head->next;
            }
            else {
                Element* prev = Find(index - 1);
                cur = prev->next;
                prev->next = cur->next;
            }
            cur->next = NULL;
            delete cur;
        }
    }
    void Print() {
        for (Element* cur = head; cur != NULL; cur = cur->next) {
            cout << cur->inf << ' ';
        }
        cout << endl;
    }
   
    int Getfirstplus() {
        int k=0;
        Element* cur = head;
        if (!Empty() ){
        while ( cur->inf <0 ){
            k++;
            if (cur->next == NULL){
                break;
            }
            cur = cur->next;
        }
        }
        return k;
    }
};

template <class Item> class Stack {
    struct Element {
        Item inf;
        Element* next;
        Element(int x, Element* p) : inf(x), next(p) {}
    };
    Element* head;
public:
    Stack() : head(0) {}
    bool Empty() {
        return head == 0;
    }
    int Pop() {
        if (Empty()) {
            throw StackException("StackException: get - stack empty");
        }
        Element* r = head;
        int i = r->inf;
        head = r->next;
        delete r;
        return i;
    }
    void Push(int data) {
        head = new Element(data, head);
    }
    int Top() {
        if (Empty()) {
            throw StackException("StackException: get - stack empty");
        }
        else {
            return head->inf;
        }
    }
};

template <class Item>
class Queue {
    struct Element {
        Item inf;
        Element* next;
        Element(Item x) : inf(x), next(0) {}
    };
    Element* head, * tail;
public:
    Queue() : head(0), tail(0) {}
    bool Empty() {
        return head == 0;
    }
    Item Get() {
        if (Empty()) {
            throw QueueException("QueueException: get - queue empty");
        }
        else {
            Element* t = head;
            Item i = t->inf;
            head = t->next;
            if (head == NULL) {
                tail = NULL;
            }
            delete t;
            return i;
        }
    }
    void Put(Item data) {
        Element* t = tail;
        tail = new Element(data);
        if (!head) {
            head = tail;
        }
        else {
            t->next = tail;
        }
    }
};

template <class Item> class DoubleLinkedList {
    struct Element {
        Item inf;
        Element* next;
        Element* prev;
        Element(Item x) : inf(x), next(0), prev(0) {}
    };
    Element* head;
    Element* tail;
    int size;
    Element* Find(int index) {
        if ((index < 1) || (index > size)) {
            return NULL;
        }
        else {
            Element* cur = head;
            for (int i = 1; i < index; i++) {
                cur = cur->next;
            }
            return cur;
        }
    }
    void Read1(Element* cur, ifstream &in){
        
            Item value;

        if (in>>value){
            Element* newPtr = new Element(value);
            size ++;
            if (cur == NULL) {
            
                head = newPtr;
                tail = newPtr;
            }
            else {
                newPtr->next = cur->next;
                newPtr->prev = cur;
                cur->next = newPtr;
                if (cur == tail) {
                    tail = newPtr;
                }
                else {
                    newPtr->next->prev = newPtr;
                }}

        Read1(newPtr,in);
            }
        }
    void Sort1(Element* cur,const  Element* l ){
        if (l != NULL){
            Element* newPtr = new Element(l->inf);
            size ++;
            if (cur == NULL) {
                head = newPtr;
                tail = newPtr;
                cur=newPtr;
            }
            else if (l->inf <0) {
                if (cur->inf>=0){
                    newPtr->next = cur;
                    newPtr->prev = cur->prev;
                    cur->prev = newPtr;
                    head=newPtr;
                    cur=cur->prev;
                }
                else{
                newPtr->next = cur->next;
                newPtr->prev = cur;
                cur->next = newPtr;
                if (cur == tail) {
                    tail = newPtr;
                }
                else {
                    newPtr->next->prev = newPtr;
                }
                    cur=cur->next;
                }

            }
            else{
                Pushback(l->inf);
                size--;
            }

        Sort1(cur, l->next);
            }
        }
public:
    DoubleLinkedList() : head(0), tail(0), size(0) {}
    ~DoubleLinkedList() {
        while (!Empty()) {
            Remove(1);
        }
    }
    bool Empty() {
        return head == 0;
    }
    int GetLength() {
        return size;
    }
    Item Get(int index) {
        if ((index < 1) || (index > size)) {
            throw DoubleListException("Exception: get - double-linked list error");
        }
        else {
            Element* r = Find(index);
            Item i = r->inf;
            return i;
        }
    }
    
    void InsertLeft(int index, Item data) {
        if ((index < 1) || (index > size + 1)) {
            throw DoubleListException("Exception: insert - double-linked list error");
        }
        else {
            Element* newPtr = new Element(data);
            size = GetLength() + 1;
            Element* cur = Find(index);
            if (cur == NULL) {
                head = newPtr;
                tail = newPtr;
            }
            else {
                newPtr->next = cur;
                newPtr->prev = cur->prev;
                cur->prev = newPtr;
                if (cur == head) {
                    head = newPtr;
                }
                else {
                    newPtr->prev->next = newPtr;
                }
            }
        }
    }
    void InsertRight(int index, Item data) {
        if ((index < 1 && head != NULL) || (index > size + 1)) {
            throw DoubleListException("Exception: insert ó double-linked list error");
        }
        else {
            Element* newPtr = new Element(data);
            size = GetLength() + 1;
            Element* cur = Find(index);
            if (cur == NULL) {
                head = newPtr;
                tail = newPtr;
            }
            else {
                newPtr->next = cur->next;
                newPtr->prev = cur;
                cur->next = newPtr;
                if (cur == tail) {
                    tail = newPtr;
                }
                else {
                    newPtr->next->prev = newPtr;
                }
            }
        }
    }
  double Remove(int index) {
        if ((index < 1) || (index > size)) {
            throw DoubleListException("Exception: remove - double - linked list error");
        }
        else {
            Element* cur = Find(index);
            --size;
            double in=cur->inf;
            if (size == 0) {
                head = NULL;
                tail = NULL;
            }
            else if (cur == head) {
                head = head->next;
                head->prev = NULL;
            }
            else if (cur == tail) {
                tail = tail->prev;
                tail->next = NULL;
            }
            else {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            cur->next = NULL;
            cur->prev = NULL;
            delete cur;
            return in;
        }
    }
    void PrintLeftToRight() {
        for (Element* cur = head; cur != NULL; cur = cur->next) {
            cout << cur->inf << ' ';
        }
        cout << endl;
    }
    Item min() {
        int flag=0;
        Item a=0;
        for (Element* cur = head; cur != NULL; cur = cur->next) {
            if (cur->inf<a || flag==0){
                flag=1;
                a=cur->inf;
            }
        }
  
        return a;
    }
    void PrintRightToLeft() {
        for (Element* cur = tail; cur != NULL; cur = cur->prev) {
            cout << cur->inf << ' ';
        }
        cout << endl;
    }
    Element* Getfirstplus() {
        Element* cur = head;
        if (!Empty() ){
        while ( cur->inf <0 ){
            if (cur->next == NULL){
                break;
            }
            cur = cur->next;
        }
        }
        return cur;
    }
    
    void Read(int index, ifstream &in){
        if ((index < 1 && head != NULL) || (index > size + 1)) {
           
        throw DoubleListException("Exception: insert ó double-linked list error");
    }
        
        else{
            Element* cur = Find(index);
            
            Read1(cur, in);
        }
    }
    
    
    void Pushback(Item data){
        size++;
        Element* newPtr = new Element(data);
        if (size ==1){
            head = newPtr;
            tail = newPtr;
        }
        else{
        newPtr->prev = tail;
        tail->next = newPtr;
            tail=newPtr;}
                    
                
            
        
    }
    void Sort( const DoubleLinkedList& l2){
       
        Sort1(Getfirstplus(),l2.head);
        
        
    }
    
};

#endif /* Header_h */
