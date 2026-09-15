#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include<sstream>
#include <cmath>
#include "book.h"
using namespace std;
class member {
    private:
    int id ;
    string name ;
    public :
    vector<string> borrowedbooks ;
    string bookname ;
    member (int memberid , string membername) : id (memberid) , name (membername){}
    int getmemberid(){
        return id ;
    }
    string getmembername(){
        return name ;
    }
    void displayborrowedlist(){
            cout<<" member name : "<< getmembername()<<" => "
            <<getmembername()<<"'s ID : "<<getmemberid()<<endl;
            cout<<"---------------"<<endl;
            cout<<getmembername()<<"'s borrowed books :"<<endl;
            if(borrowedbooks.empty()){
                cout<<"U  don't have borrowed books !"<<endl;
                return ;
            }
            else{
                for( int i = 0 ; i < borrowedbooks.size() ; i++){
                    cout<<i+1<<":"<<borrowedbooks[i]<<endl;
                }
                cout<<"---------------"<<endl;
        }
        
    }
};
class node2{
    public :
    member data ;
    node2* next ; 
    node2 (member m , node2* nexxt) : data (m) , next (nexxt){};

};
inline node2* front = NULL ;
inline void appendmember( member x){
    node2* newnode = new node2 ( x , NULL) ;
    if( front == NULL){
        front = newnode ;
    }
    else{
        node2* last = front ;
        while( last ->next != NULL){
            last = last->next ;
        }
        last->next = newnode ;
        newnode->next =NULL ;
    }
}
inline void displaymember(){
    if(front == NULL){
        cout<<" no members yet ."<<endl ;
    }
    else {
        node2* newnode = front ;
        while (newnode !=NULL )
        {
            cout<<" member name : "<< newnode->data.getmembername()<<" => "
            <<newnode->data.getmembername()<<"'s ID : "<<newnode->data.getmemberid()<<endl;
            newnode = newnode->next;
        }
        
    }
}
inline void searchmemberbyname(string name){
    if(front == NULL){
        cout<<"NO member yet .";
        return;
    }
    else {
        node2* newnode =front;
        while (newnode->data.getmembername() != name)
        {
            newnode = newnode->next ;
            if(newnode == NULL){
                cout<<"NO member has this name :"<<name <<"  "<<endl;
                return;
            }
        }
        cout<<" member name : "<< newnode->data.getmembername()<<" => "
            <<newnode->data.getmembername()<<"'s ID : "<<newnode->data.getmemberid()<<endl;//
            cout<<"---------------"<<endl;
            cout<<newnode->data.getmembername()<<"'s borrowed books :"<<endl;
            if(newnode->data.borrowedbooks.empty()){
                cout<<"U  don't have borrowed books !"<<endl;
            }
            else{
                for( int i = 0 ; i < newnode->data.borrowedbooks.size() ; i++){
                    cout<<i+1<<":"<<newnode->data.borrowedbooks[i]<<endl;
                }
                cout<<"---------------"<<endl;
        }
        
    } 
}
inline int makeid(){
    int max = 0 ;
    node2* newnode = front ;
    while (newnode != NULL){
        max++;
        newnode = newnode->next;   
    }
    return max+1 ;  
}
inline void loadfravalaible(){
    ifstream load ("C:\\Users\\Ahmed\\Documents\\avalaiblebooks.txt");
    if(!load){
        cout<<" no avalaible books"<<endl;
        return;
    }
    string line ;
    while(getline(load , line)){
            if(line.empty()){
                continue;
            }
        string name , id , author ;
        stringstream temp (line);
        getline(temp , name , ';');
        getline(temp , id , ';');
        getline(temp , author , ';');

        int ID =stoi(id);
        book b2 (ID , name , author);
        avalabalebooks.push_back(b2);
    }
}
inline void displayallavalaiblebooks(){
    if(avalabalebooks.empty()){
        cout<<" no available books"<<endl;
        return;
    }
    for (int i = 0; i < avalabalebooks.size()  ;)
    {
        cout<<"book name : "<<avalabalebooks[i].getbookname() <<" => "<<"book ID : "<<avalabalebooks[i].getid()<<" => "
        <<"book author : "<<avalabalebooks[i].authorname()<<endl;
        i++;
    }
}
inline void addborrowed(string name){
    node2* newnode = front ;
    string bookname ;
    if ( front == NULL){
        cout<<"no members in the list "<<endl;
        return;
    }
    while(newnode != NULL && newnode->data.getmembername() != name){
        newnode = newnode->next;
    }
    if(newnode == NULL){
        cout<<"no member has this name "<<endl;
    }
    else{
        displayallavalaiblebooks();
        cout<<"Enter name of book  :"<<endl;
        cin>> bookname ;
        int i = 0 ;
        auto o =avalabalebooks.end();
        makeborrow(bookname);
        while(avalabalebooks[i].getbookname() != bookname ){
            if(i == avalabalebooks.size() ){
                cout<<"pleas enter the name correctly !"<<endl;
                cin>>bookname;
                i = 0 ;
            }
            i++;
        }
        if( b == true ){
            newnode->data.borrowedbooks.push_back(bookname);
         for( auto i = avalabalebooks.begin() ;  i != avalabalebooks.end() ; ++i){
            if( i->getbookname() == bookname){
                o = i ;
                break ;
            }
         }
         o->setavailable(false);
         avalabalebooks.erase(o);
        }
        node* node1 = head ;
            if(node1->book1.getbookname() != bookname){
                node1 = node1->next;
            }
            node1->book1.setavailable(false);
        }
    }
inline void returnmemberbook(string name){
    node2* newnode = front ;
    if ( front == NULL){
        cout<<"no members in the list "<<endl;
        return;
    }
    while(newnode != NULL && newnode->data.getmembername() != name){
        newnode = newnode->next;
    }
    if(newnode == NULL){
        cout<<"no member has this name "<<endl;
        return;
    }
        newnode->data.displayborrowedlist();
        if(newnode->data.borrowedbooks.empty()){
            return;
        }
        string borrowedbook;
        cout<<"Enter the name of book to return it :"<<endl;
        cin>>borrowedbook;
        returnbook(borrowedbook);
        if( b != false){
            auto it = find(newnode->data.borrowedbooks.begin() , newnode->data.borrowedbooks.end() , borrowedbook );
            newnode->data.borrowedbooks.erase(it);
        }
    }
inline void loadfromfilemember(){
    ifstream memberfile("C:\\Users\\Ahmed\\Documents\\members.txt.txt");
    if(!memberfile){
        return ;
    }
    else {
        string line ;
        while (getline( memberfile,line))
        {
            if(line.empty()){
                continue;
            }
            string name , ID ;
            int memberid ;
            stringstream temp (line);
            getline(temp , name , ';');
            getline(temp , ID , ';');
            memberid =stoi(ID);
            member m0 ( memberid , name) ;
            appendmember(m0);
        }
        memberfile.close();
    }
}
inline void savetofilemembers(string name , int id){
    ofstream allmembers("C:\\Users\\Ahmed\\Documents\\members.txt.txt", ios::app);
    allmembers <<name<<';'<<id<<';'<<endl;
    member m1(id , name);
    appendmember(m1);
    allmembers.close();

}
inline void savemembrsbooks(){
    ofstream borrwed("C:\\Users\\Ahmed\\Documents\\membersborrwedbooks.txt");
    node2* newnode = front ;
    if ( front == NULL){
        cout<<"no members in the list "<<endl;
        return;
    }
    while(newnode != NULL){
       for( int i = 0 ; i < newnode->data.borrowedbooks.size() ; i++){
        borrwed<<newnode->data.getmembername()<<';'<<newnode->data.getmemberid()<<';';
        borrwed << newnode->data.borrowedbooks[i]<<';'<<endl;
       }
        newnode = newnode->next;
    }
}
inline void loadborrowedbooks(string name){
    ifstream borrwed("C:\\Users\\Ahmed\\Documents\\membersborrwedbooks.txt");
     node2* newnode = front ;
    if( front == NULL){
        cout<<"sorry"<<endl;
        return;
    }
    else{
            node2* newnode =front;
            while (newnode->data.getmembername() != name)
            {
                newnode = newnode->next ;
                if(newnode == NULL){
                    cout<<"NO member has this name :"<<name <<"  "<<endl;
                    return;
                }
            }
            if(!borrwed){
                return ;
            }
        string line ;
        while(getline(borrwed , line)){
            string y ,membername,id;
            stringstream x (line);
            getline(x , membername , ';');
            getline(x , id , ';');
            getline(x , y , ';');
            if(membername == name){
                newnode->data.borrowedbooks.push_back(y);
            }

        }
    }
    borrwed.close();
}
inline void saveavalabilebooks(int id , string name , string author){
    ofstream bookfile ("C:\\Users\\Ahmed\\Documents\\avalaiblebooks.txt",ios::app);
    bookfile<<name<<';'<<id<<';'<<author<<';'<<endl;
    book b8 ( id , name , author);
    avalabalebooks.push_back(b8);
    bookfile.close();
}
inline void avalaiblebooks(vector<book>abooks){
     ofstream file ("C:\\Users\\Ahmed\\Documents\\avalaiblebooks.txt");
     for(int i = 0 ; i < abooks.size() ; i++){
        file <<abooks[i].getbookname()<<';'<<abooks[i].getid()<<';'<<abooks[i].authorname()<<';'<<endl;
     }
     file.close();
}
inline void loadallborrowedbooks(){
    node2* newnode = front;
    if(front == NULL){
        return;                          
    }
    ifstream borrwed("C:\\Users\\Ahmed\\Documents\\membersborrwedbooks.txt");
    if(!borrwed){
        return;                        
    }
    string line;
    while(getline(borrwed, line)){    
        string membername, id, y;
        stringstream x(line);
        getline(x, membername, ';');      
        getline(x, id, ';');              
        getline(x, y, ';');             
        while(newnode != NULL && newnode->data.getmembername() != membername){
            newnode = newnode->next;       
        }
        if(newnode != NULL){
            newnode->data.borrowedbooks.push_back(y); 
        }
    }
    borrwed.close();
}
