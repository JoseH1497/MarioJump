#include"GameOver.h"
#include<iostream>
using namespace std;
GameOver::GameOver(){
        back = new Background("images/mainBack.png", -1, 1, 2, 2);
        restart = new Object("images/restartButton.png", -0.7, -0.18, 0.8, 0.4);
        exit = new Object("images/exitButton.png", -1, -0.58, 0.8, 0.4);
	gameOverBool = false;
	exitBool = false;
}

void GameOver::draw(){
        back->draw();
        restart->draw();
        exit->draw();
}

bool GameOver::Exit(){
	return exitBool;
}

void GameOver::setGameOver(bool play){
        gameOverBool = play;
}
bool GameOver::gameOver(){
        //to check if player is playing
        return gameOverBool;
}
bool GameOver::isRestarting(){
	return restartBool;
}

void GameOver::checkForClick(float x, float y){
        cout<<"Whats going on???"<<endl;
        if(restart->contains(x,y)){
		restartBool = true;
                gameOverBool = false;
                cout<<"user is playing"<<endl;
        }else if(exit->contains(x,y)){
                cout<<"user is exiting"<<endl;
		exitBool = true;
	}
}


