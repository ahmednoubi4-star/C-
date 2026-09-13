#include "member.h"
inline void memberswitch(){
    loadfravalaible();
    loadfromfilemember();
    loadfromfilebooks();
    loadallborrowedbooks();
    int n ;
    bool p = true ;
    while (p){
        cout<<"1 =>  BORROW BOOK "<<endl
            <<"2 => return book"<<endl
            <<"3 => show you borrwed books "<<endl
            <<"4 => to quit "<<endl;
            cout<<"Enter number : ";
            cin>>n;
        switch (n)
        {
        case 1 :{
                clearScreen();
                string name;
                cout<<"Enter your name : ";
                cin>>name;
                addborrowed(name);
                avalaiblebooks(avalabalebooks);
                savemembrsbooks();
                cout<<"--------------"<<endl
                <<"press Y to go back to the list"<<endl;
                char y = ' ';
                while ( y != 'y' && y != 'Y')
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
                cout<<"--------------"<<endl
                <<"press Y to go back to the list"<<endl;
                char y = ' ';
                while ( y != 'y' && y != 'Y')
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
                char y = ' ';
                while ( y != 'y' && y != 'Y')
                {
                    cout<<"pleas press Y : ";
                    cin>>y;
                }
                break;
            }
        case 4 : { return ;}
        default:
                while(n < 1 || n > 4){  
            cout<<"pleas enter right number :";
            cin>>n;
            }
        break;
        }
    }
}