#include "member.h"
inline void memberswitch(){
    loadfromfilemember();
    loadfromfilebooks();
    loadfravalaible();
    loadallborrowedbooks();
    string n ;
    bool p = true ;
    while (p){
        cout<<"1 =>  BORROW BOOK "<<endl
            <<"2 => return book"<<endl
            <<"3 => show you borrwed books "<<endl
            <<"4 => to quit "<<endl;
            cout<<"Enter number : ";
            cin>>n;
            while ( n != "1" && n != "2" && n != "3" && n!= "4" ){
            cout<<"pleas enter right number : ";
            cin>>n;        
             }
        int h = stoi(n);
        switch (h)
        {
        case 1 :{
                clearScreen();
                string name;
                cout<<"Enter your name : ";
                cin>>name;
                addborrowed(name);
                avalaiblebooks(avalabalebooks);
                savemembrsbooks();
                savebooks();
                cout<<"--------------"<<endl
                <<"press Y to go back to the list"<<endl;
                string y = " ";
                while ( y != "y" && y != "Y" )
                {
                    cout<<"pleas press Y : ";
                    cin>>y;
                }
                break;
            }
        case 2 : {
                clearScreen();
                string name;
                cout<<"Enter your name : ";
                cin>>name;
                returnmemberbook(name);
                savemembrsbooks();
                avalaiblebooks(avalabalebooks);
                savebooks();
                cout<<"--------------"<<endl
                <<"press Y to go back to the list"<<endl;
                string y = " ";
                while ( y != "y" && y != "Y" )
                {
                    cout<<"pleas press Y : ";
                    cin>>y;
                }
                break;
            }
        case 3 : {
                clearScreen();
                string name;
                cout<<"Enter your name : ";
                cin>>name;
                searchmemberbyname(name);
                cout<<"press Y to go back to the list"<<endl;
                string y = " ";
                while ( y != "y" && y != "Y" )
                {
                    cout<<"pleas press Y : ";
                    cin>>y;
                }
                break;
            }
        case 4 : { return ;}
        default:
        break;
        }
    }
}