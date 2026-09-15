#include "member.h"
#include <cstdlib>
inline void switchADMIN(){
    loadfromfilemember();
    loadfromfilebooks();
    loadfravalaible();
    loadallborrowedbooks();
    string n ;
    bool p = true;
    while(p){
        cout<<" 1 => show ALL members "<<endl
        <<" 2 => ADD NEW MEMBER "<<endl
        <<" 3 => show ALL BOOKS"<<endl
        <<" 4 => ADD NEW BOOK"<<endl
        <<" 5 => show ALL AVALAIBLE BOOKS"<<endl
        <<" 6 => shearch member information"<<endl
        <<" 7 => shearch book information"<<endl
        <<" 8 =>  to quit "<<endl;
        cout<<"ENTER THE NUMBER : ";
        cin>>n;
        while ( n != "1" && n != "2" && n != "3" && n!= "4" && n!= "5" && n!= "6" && n!= "7" && n!= "8" ){
            cout<<"pleas enter right number : ";
            cin>>n;        
            }
        int h = stoi(n);
        switch (h)
        {
        case 1:{
            
            clearScreen();
            displaymember();
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
            string name ;
            cout<<"ENTER member's name : ";
            cin>>name;
            int id=makeid();
            savetofilemembers(name , id);
            clearScreen();
            cout<<"member added"<<endl;
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
            displaylist();
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
    case 4 : {
            string bookname ,authorname ;
            cout<<"ENTER BOOK NAME : ";
            cin>>bookname;
            cout<<"ENTER BOOK author : ";
            cin>>authorname;
            int id = makebookid();
            savetofilebooks(id , bookname,authorname);
            saveavalabilebooks(id , bookname , authorname);
            clearScreen();
            cout<<"book added"<<endl;
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
    case 5 : {
            clearScreen();
            displayallavalaiblebooks();
            cout<<"--------------"<<endl
            <<"press Y to go back to the list"<<endl;
            string y = " ";
            while ( y != "y" && y != "Y" )
            {
                cout<<"pleas press Y : ";
                cin>>y;
            }
            break ;
        }
    case 6 : {
            clearScreen();
            string name ;
            cout<<"ENTER member's name : ";
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
    case 7 : {
            clearScreen();
            string bookname ;
            cout<<"ENTER BOOK NAME : ";
            cin>>bookname;
            searchbyvalue(bookname);
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
    case 8 : {
            return ;
        }
        
    
    default:
        break;
    }

    }
}