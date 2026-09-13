#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
 inline bool b = false;
//book class
class book {
    private:
     int id ;
     string author ;
     string bookname ;
     bool available ;
     
     public :
      book ( int bookid , string bookName ,string authorname ,bool availablebook = true){
            id = bookid;
            author = authorname;
            available = availablebook ;
            bookname = bookName;
      }
      void setavailable(bool availablebook = true){
          available = availablebook  ;
      }
      string isavalaible() {
        if(available){
            return "YES, it's avaliable" ;
        }
        else{
            return"NO, it's not avaliable";
        }
      }
       bool getavailable(){
        return available;
       }
      int getid(){
        return id ;
      }
      string getbookname(){
        return bookname ;
      }
       string authorname(){
        return   author;
      }
      bool makeborrowed(){
       return available = false ;
      }
      void displaybookbyid(string book){}
};
//linked list1
class node{
    public :
    book book1 ;
     node* next ;
     node (book b , node* nexxt) : book1 (b) , next (nexxt) {}
     
};
 inline node* head = NULL ;
 vector<book>avalabalebooks;
inline void searchbyvalue(string name){
    node* newnode = head ;
    if( head == NULL){
        cout<<"the list is empty now "<<endl;
    }
    else{
        while( newnode->book1.getbookname() != name ){
            newnode =newnode->next;
            if(newnode == NULL){
                cout<<"this "<<name<<" doesn't exist ."<<endl;
                return;
            }
        }
            cout <<"book name : "<< newnode->book1.getbookname() << endl 
            <<"book ID : "<<newnode->book1.getid()<<endl;
            cout<<"book author : "<<newnode->book1.authorname()<<endl;

            cout<<"book status : "<< newnode->book1.isavalaible()<<endl;
            cout<<"-----------------------"<<endl;
}
}
 inline void append(book book1){
    node* newnode = new node (book1 , NULL) ;
    if(head == NULL){
        head = newnode ;
    }
    else{
        node* last = head ;
        while( last->next != NULL){
            last = last->next ;
        }
        last->next = newnode ;
        newnode->next = NULL ;
    }
}
 inline void displaylist(){
    if(head == NULL){
        cout<<"the list empty "<<endl;
    }
    else{
        node* temp = head ;
        while(temp != NULL){
           cout <<"book name : "<< temp->book1.getbookname() << endl 
           <<"book ID : "<<temp->book1.getid()<<endl;
           cout<<"book author : "<<temp->book1.authorname()<<endl;
           cout<<"-----------------------"<<endl;
            temp = temp->next ;
        }
    }
}
 inline void makeborrow(string x ){
    node* newnode = head ;
     if( head == NULL){
        cout<<"the list is empty now "<<endl;
    }
    else{
        while( newnode->book1.getbookname() != x ){
            newnode =newnode->next;
            if(newnode == NULL){
                cout<<"this "<<x<<" doesn't exist .";
                return;
            }
        }
            cout<<"------------------------------------"<<endl;
           cout <<"book name : "<< newnode->book1.getbookname() << endl 
           <<"book ID : "<<newnode->book1.getid()<<endl;
           cout<<"book author : "<<newnode->book1.authorname()<<endl;
           cout<<"book status : "<< newnode->book1.isavalaible()<<endl;
            cout<<"-----------------------"<<endl;
            if(newnode->book1.isavalaible() == "YES, it's avaliable"){
                
                char Confirmation ;
                cout<<" U can borrow it !      "<<"Confirmation of book borrowing (Y/N)"<<endl;
                cin>>Confirmation;
                while( Confirmation != 'Y' && Confirmation != 'y' && Confirmation != 'N' && Confirmation != 'n'){
                    cout<<"pleas enter (Y/N)"<<endl;
                    cin>>Confirmation;
                }
                if(Confirmation == 'Y' ||  Confirmation == 'y'){
                     b = true ;
                    cout<<"congratulations u have borrowed the book "<<endl
                    <<"don't forget to return it in 14 days    ";
                    cout<<"thanks for coming here "<<endl;
                    newnode->book1.setavailable(false);
                    char f ;
                     do {
                        cout<<"enter (Y) to get out   "<<endl;
                        cin>>f;}
                    while(f != 'Y' &&  f !=  'y');
                }
                else if( Confirmation == 'N' || Confirmation ==  'n'){
                    b = false ;
                    cout<<"as u like"<<endl;
                    return;
                }
            }
            else{
                b = false ;
                cout<<"sorry this book doesn't exist right now"<<endl;
                char t;
                do {
                    cout<<"enter (Y) to get out   "<<endl;
                    cin>>t;}
                    while(t != 'Y' &&  t !=  'y');
            }     
    }
}
 inline void returnbook(string x){
    node* newnode = head ;
    if( head == NULL){
        cout<<"the list is empty now "<<endl;
    }
    else{
        while( newnode->book1.getbookname() != x ){
            b = false ;
            newnode =newnode->next;
             if(newnode == NULL){
                cout<<"this "<<x<<" doesn't exist ."<<endl;
                return;
            }
        }
          
           cout <<"book name : "<< newnode->book1.getbookname() << endl 
           <<"book ID : "<<newnode->book1.getid()<<endl;
           cout<<"book author : "<<newnode->book1.authorname()<<endl;
            cout<<"-----------------------"<<endl;
            char y ;
            do{
                cout<<"DO yo want to return "<<x <<" book ?  (Y/N)"<<endl;
                cin>>y;
            }while(y != 'Y' && y != 'y' && y != 'N' && y != 'n');
            if( y == 'Y' || y =='y'){
                 b = true ;
                cout<<"thank u for coming here "<<endl;
                newnode->book1.setavailable(true);
                avalabalebooks.push_back(newnode->book1);
            }
            else{
                cout<<"as u like"<<endl;
            }
    }    
}
inline void loadfromfilebooks () {
    ifstream bookfile ("C:\\Users\\Ahmed\\Documents\\books.txt.txt");
    if(!bookfile) {
        return ;
    }
    else{
        string line ;
        while(getline(bookfile , line)){
            if(line.empty()){
                continue;
            }
            string name , nameauthor , ID , avalaible;
            int id ;
            bool k ;
            stringstream temp (line);
            getline(temp , name , ';');
            getline(temp , ID , ';');
            id = stoi(ID);
            getline(temp , nameauthor , ';');
            getline(temp , avalaible , ';');
            if(avalaible == "YES, it's avaliable"){
                k = true ;
            }
            else {
                k = false;
            }
            book b0 ( id , name , nameauthor, k );
            append(b0);
        }
        bookfile.close();
    }

}
inline int makebookid(){
    int max = 0 ;
    node* newnode = head ;
    while (newnode != NULL){
        max++;
        newnode = newnode->next;   
    }
    return max+1 ;  
}
inline void savetofilebooks(int id , string name , string author){
    ofstream bookfile ("C:\\Users\\Ahmed\\Documents\\books.txt.txt",ios ::app);
    book b8 ( id , name , author);
    append(b8);
    bookfile<<name<<';'<<id<<';'<<author<<';'<<b8.isavalaible()<<';'<<endl;
    bookfile.close();
}
 inline void clearScreen() {
    cout << "\033[2J\033[1;1H";
}
inline void savebooks(){
    ofstream bookfile ("C:\\Users\\Ahmed\\Documents\\books.txt.txt");
    node* newnode = head;
    if(head == NULL){
        cout<<"there is no books right now"<<endl;
    }
    else{
        while(newnode != NULL){
            bookfile<<newnode->book1.getbookname()<<';'<<newnode->book1.getid()<<';'
                    <<newnode->book1.authorname()<<';'<<newnode->book1.isavalaible()<<';'<<endl;
                    newnode = newnode->next;
        }
        bookfile.close();
    }
    
}