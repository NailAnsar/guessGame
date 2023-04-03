//
// Created by user on 4/3/2023.
//

#include "guessutils.h"
#include <iostream>
using std::cout,std::cin,std::endl;
int rightscore{0};
int wrongscore{0};
int score{0};
bool isGameStarted=false;
using std::cout,std::cin,std::endl;
void startGame(){
    if(isGameStarted == false){
        isGameStarted==true;
    }
    cout<<"Guess the right number.Number is between 1-10 good luck"<<endl;
    int x{0};
    while(x<5){
        srand(time(0));
        int randomnumber=(rand()%3)+1;
        int answer{};
        cin>>answer;
        if(answer ==randomnumber){
            cout<<"you have guest it right! your guess: "<<answer<<"target number"<<randomnumber<<'\n';
            rightscore++;
        }else if(answer!=randomnumber){
            cout<<"wrong answer your guess: "<<answer<<"target number"<<randomnumber<<'\n';
            wrongscore++;
        }
        x++;
    }
    score=rightscore-wrongscore;
    if(score>0){
        cout<<"you gained this amount of"<<score<<"points"<<'\n';
    }else{
        cout<<"your score is 0";
    }
    if(x==5){
        continueGame();isGameStarted==false;
    }

}
void continueGame() {

    cout << "do you want to continue game?" << '\n';
    std::string answer = "";
    cin >> answer;
    if (answer == "yes") {
        if (isGameStarted == true) {
            isGameStarted = false;
            startGame();
        }
    }
    if (answer == "no") {
        if (score < 0) {
            cout << "game is finished your score is 0. Better luck next time." << score << '\n';
        } else if (score > 0) {
            cout << "Game is finished and your score is :" << score << '\n';
        }
    }
}