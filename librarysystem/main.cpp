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
  int n ;
  string password , key = "1n3zf98^67zS-K7";
   cout<<" 1 => ADMIN "<<endl
      <<" 2 => MEMBER "<<endl
      <<"Enter the number : ";
      cin>>n;
      switch(n){
          case 1 :{
            cout<<"Enter ADMIN Password : ";
            cin>>password;
            while(password != key){
              cout<<" worng password "<<endl;
              cout<<"Enter ADMIN Password : ( 0 to quit)"<<endl;
              cin>>password;
              if(password == "0"){
                return n = 0 ;
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
          default:
            break;
      }
}
