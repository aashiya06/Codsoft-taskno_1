/* Create a program that generates a random number and asks the user to guess it. Provide feedback on whether the 
guess is too high or too low until the user guesses the correct number.
*/

#include<iostream>
#include <ctime>
using namespace std;

class RandomNumberGame {

private:
    int randomNumber;  

public:

    RandomNumberGame() {
        srand(time(0));
        randomNumber = (rand()%100)+1;
    }

    void play(){

        int guess;
        int choice;
        string chances;
        int cnt=0;

        cout<<"Welcome to the Random Number Guessing Game!"<< endl;
        cout<<"Enter your choice! \n 1. PLAY \n 2. EXIT"<<endl;
        cin>>choice;

        cout<<"RULES:\n\n1. Firstly, you have to choose the number of chances you think you can guess the number."<<endl;
        cout<<"(You can choose any number of chances, but the maximum is 100.)"<<endl;
        cout<<"2. So, now your goal is to guess the random number chosen by the computer in the number of chances you have entered"<<endl;
        cout<<"3. If your guess is lower than the random number, you will be prompted to guess a higher number."<<endl;
        cout<<"4. If your guess is higher than the random number, you will be prompted to guess a lower number."<<endl;
        cout<<"5. If you guess the correct number, you win!"<<endl;

        cout<<"\n";
        cout<<"Let's start the game!"<<endl;
        cout<<"\n";
        cout<<"Enter the number of guesses (Enter 'unlimited' for infinite number of cases): ";
        cin>>chances;
        cout<<"\n";
        
        switch(choice){

            case 1: 
                
                if(chances == "unlimited") {

                    cout<<"You have chosen unlimited chances. You can guess until you find the correct number."<<endl;
                    cout<<"I have chosen a random number between 1 and 100. Can you guess it? "<<endl;

                    while(true){
                        
                        cout<<"Enter your guess: ";
                        cin>>guess;
                    
                        if(guess==randomNumber){
                            cout<<"Congratulations! You've guessed the number: "<<randomNumber<<endl;
                            cout<<"You guessed it in "<<cnt+1<<" attempts."<<endl;
                            break;
                        } 
                        else if(guess<randomNumber){
                            cout<<"The random number is higher than your guess! Try again! "<<endl;
                            cnt++;
                        } 
                        else {
                            cout<<"The random number is lower than your guess! Try again! "<<endl;
                            cnt++;
                        }
                    }
                }

                else if (chances == "0") {
                    cout<<"You have chosen 0 chances. Exiting the game."<<endl;
                    return;
                }

                else {
                    cout<<"I have chosen a random number between 1 and 100. Can you guess it? "<<endl;
                    int num = stoi(chances);
                    for(int i = 0; i < num; i++) {
                        cout<<"Enter your guess: ";
                        cin>>guess;

                        if(guess == randomNumber) {
                            cout<<"YOU WIN! Congratulations! You've guessed the number: "<<randomNumber<<endl;
                            break;
                        } 

                        else if(guess < randomNumber) {
                            cout<<"The random number is higher than your guess! Try again! "<<endl;
                        } 

                        else {
                            cout<<"The random number is lower than your guess! Try again! "<<endl;
                        }
                    }
                    cout<<"YOU LOST! You have used all your chances. The random number was: "<<randomNumber<<endl;
                }
                
                break;

            case 2: cout<<"Exiting the game. Goodbye!"<<endl;
                return;
                break;
        }
    };
};

int main() {

    RandomNumberGame game;
    game.play();
    
    char again;
    cout << "Do you wish to play again? (Y/N): ";   
    cin >> again;
    if(again == 'Y' || again == 'y') {
        main(); 
    } 

    else {
        cout << "Thank you for playing! Goodbye!" << endl;
    }

    return 0;
}
    










