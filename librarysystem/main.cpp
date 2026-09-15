#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "member.h"
#include "switchADMIN.h"
#include "switchmembers.h"
// ADMIN password :1n3zf98^67zS-K7
using namespace std;
int main() {
  string n ;
  string password , key = "1n3zf98^67zS-K7";
   cout<<" 1 => ADMIN "<<endl
      <<" 2 => MEMBER "<<endl
      <<" 3 => quit "<<endl
      <<"Enter the number : ";
      cin>>n;
      while ( n != "1" && n != "2" && n != "3"){
            cout<<"pleas enter right number : ";
            cin>>n;        
      }
      int h = stoi(n);
      switch(h){
          case 1 :{
            cout<<"Enter ADMIN Password : ";
            cin>>password;
            while(password != key){
              cout<<" worng password "<<endl;
              cout<<"Enter ADMIN Password : ( 0 to quit)"<<endl;
              cin>>password;
              if(password == "0"){
                return h = 3 ;
              }
            }
            clearScreen();
            switchADMIN();
            break;
          }
          case 2 : {
            clearScreen();
            memberswitch();
            break;
          }
          case 3 :
          {
            return 0;
          }
          default:
            break;
      }
}
