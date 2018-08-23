//
//  Score.cpp
//  glutapp
//
//  Created by Jose Herrera on 5/3/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Score.h"
#include <iostream>
using namespace std;

Score::Score(){
    score = 0;
    incrementScore = 0;
    numEnemy = 0;
    savedScore = -1;
    savedNumEnemies = -1;
    loadGame = false;
}


void Score::addToScores(int newScore){
    
    if(highScores.size() <3){
        //need at least 3 scores so push this one on
        highScores.push(newScore);
    }else{
        highScores.push(newScore);
        int currentHighScoreSize = highScores.size();
        int *allScores = new int[currentHighScoreSize];//get all scores and see if the newScore is better than these scores
        for(int i = 0; i < currentHighScoreSize; i++){
            allScores[i] = highScores.top();//get all scores, only care about top 3
            highScores.pop();
        }
        for(int i = 0; i < 3; i++){
            highScores.push(allScores[i]); //push top 3 scores on priorityQueue
        }
        
        delete[] allScores; //delete and release memory resources
        
    }
}
void Score::resetScore(){
    this->score = 0;
    this->incrementScore = 0;
}
void Score::setScore(int score){
    this->score = score;
}
void Score::gameOver(){
    //put into highscores to see if this is a new highScore
    this->addToScores(this->score);
    //reset score
    this->score = 0;
    
}

void Score::addScore(){
    incrementScore++;
     //only add to score every so often, helps simulate 1 second == 1 point
    if(incrementScore %10 == 0){
        this->score++;
        cout<<"Score "<<getScore()<<endl;    
    }
   
    if(incrementScore%100 ==0){
        this->numEnemy++;
        cout<<"numEnemy is " << getNumEnemy()<<endl;
    }
}
int Score::getScore(){
    return this->score;
}
void Score::resetNumEnemy(){
    this->numEnemy = 0;
}
void Score::setNumEnemy(int num){
    this->numEnemy = num;
}
void Score::setSavedScore(int saveScore){
    this->savedScore = saveScore;
}
int Score::getSavedScore(){
    return this->savedScore;
}
void Score::setSavedNumEnemies(int saveEnemies){
    this->savedNumEnemies =  saveEnemies;
}
int Score::getSavedNumEnemies(){
    return this->savedNumEnemies;
}
bool Score::isGameLoadable(){
    return this->loadGame;
}
void Score::setLoadGame(){
    if(this->getSavedNumEnemies()  > -1 && this->getSavedScore() >-1){
        this->loadGame = true;
    }
    
}
void Score::setLoadGameToFalse(){
    this->loadGame = false;
}
void Score::topThreeScores(){
    int size =  highScores.size();
    int *allScores = new int[size];
    for(int i =0; i < size; i++){
        allScores[i] = highScores.top();
        cout<<i+1<<". "<<allScores[i]<<endl;
        highScores.pop();
    }
    //put back to queue
    for(int i = 0; i < size; i ++){
        highScores.push(allScores[i]);
    }
   
    delete[] allScores;
}
int Score::getNumEnemy(){
	return this-> numEnemy;
}
