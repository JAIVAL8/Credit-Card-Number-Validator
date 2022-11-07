#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;
// Luhn algorithm
bool isnumberStr(string S){

    for(int i = 0 ; i < S.length() ; i++){
            if(S[i] < '0' || S[i] > '9') return false;
        }

    return true;
}

int main(){
    string C_card_n;
    

    while(true){
        cout<<"Enter Credit Card Number or type 'exit' to quit"<<endl;
        cin>>C_card_n;

        // int count = 0;
 
        // for (int i = 0; C_card_n[i]; i++)
        //     {
        //         if (C_card_n[i] != ' ') C_card_n[count++] = C_card_n[i];
        //     }                                
        // C_card_n[count] = '\0';
        
        //cout<<C_card_n<<endl;

        if (C_card_n == "exit")
                break;
            
            else if (!isnumberStr(C_card_n)) {
                cout << "Bad input! "<<endl;
                continue;
            }
            int len = C_card_n.length();
            int doubleEvenSum = 0;
            
            //doubling every 2nd number from right side and adding 

            for(int i=len-2;i>=0;i-=2){
              
                int db= (C_card_n[i]-48)*2;
                
                if(db>9){ 
                    db=db%10+db/10;
                }
                doubleEvenSum+=db;
            }

            //adding all odd places to even sum from right

             for(int i=len-1;i>=0;i-=2){

                doubleEvenSum+=(C_card_n[i]-48);
            }

            //check if doubleEven sum is div by 10 if yes than valid else invalid.

            cout<<(doubleEvenSum%10==0 ? "Valid Card Number." : "Invalid.")<<endl ;
            continue;
    }
}