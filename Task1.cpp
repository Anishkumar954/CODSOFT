#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main (){
srand(time(0));
int secretNumber=rand() % 100 +1;
int userGuess ;
cout<<"Welcome To Number Guessing Game! "<< endl;
cout<<"Guess the number between 1 and 100"<< endl;
do{
    cout<<"Enter your Guess: ";
    cin>>userGuess;
    if(userGuess < secretNumber){
        cout<<"Too low! Try again. "<<endl;
    }
    else if(userGuess > secretNumber){
        cout<<"Too high! Try again. "<<endl ;
        
    }
    
    else{
        cout<<"Congratulations! You gUess The Write Number."<< endl;

    }
   
} while(userGuess != secretNumber);
   return 0;
}
