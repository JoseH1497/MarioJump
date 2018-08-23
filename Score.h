//
//  Score.h
//  glutapp
//
//  Created by Jose Herrera on 5/3/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Score_h
#define Score_h

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;


class Score{
    int score;
    priority_queue<int> highScores;
    int incrementScore;
    int numEnemy;
    int savedScore;
    int savedNumEnemies;
    bool loadGame;
    
public:
    Score();
    void addToScores(int newScore);
    int getScore();
    void setScore(int);
    void addScore();
    void gameOver();
    void topThreeScores();
    void resetScore();
    int getNumEnemy();
    void resetNumEnemy();
    void setNumEnemy(int);
    void setSavedScore(int);
    int getSavedScore();
    void setSavedNumEnemies(int);
    int getSavedNumEnemies();
    bool isGameLoadable();
    void setLoadGame();
    void setLoadGameToFalse();
};
#endif /* Score_h*/
