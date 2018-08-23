#include"MainMenu.h"
#include<iostream>
using namespace std;

MainMenu::MainMenu(){
	background = new Background("images/mainBack.png", -1, 1, 2, 2);
	playButton = new Object("images/playButton.png", -1, 0.25, 0.8, 0.4);
	restartButton= new Object("images/loadButton.png", -0.7, -0.18, 0.8, 0.4);
	saveButton = new Object("images/saveButton.png", -1, -0.58, 0.8, 0.4);
	playing = false;
}

void MainMenu::draw(){
	background->draw();
        playButton->draw();
        restartButton->draw();
        saveButton->draw();
}

void MainMenu::setPlaying(bool play){
	playing = play;
}
bool MainMenu::isPlaying(){
	//to check if player is playing
	return playing;
}

void MainMenu::checkForClick(float x, float y){
	//cout<<"Whats going on???"<<endl;
	if(playButton->contains(x,y)){
		playing = true;
	//	cout<<"user is playing"<<endl;
	}else if(restartButton->contains(x,y)){
       // playing = true;
	//IDK if this should even be here
	//	cout<<"user is restarting"<<endl;
	}else if(saveButton->contains(x,y)){

        cout<<"user is saving"<<endl;
	}

}
bool MainMenu::checkForSave(float x, float y){
    return saveButton->contains(x, y);
    
}
bool MainMenu::checkForLoad(float x, float y){
    
    return restartButton->contains(x, y);
    
}
