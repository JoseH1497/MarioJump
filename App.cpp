#include "App.h"

#include<iostream>
using namespace std;
static App* singleton;
int spacePressedCount = 0;

void drawBitmapText(int score,float x,float y,float z)
{
    char *c;
    glRasterPos2f(x, y);
    
    
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score);
    
}

void restart(){
    singleton->numEnemy = -1;
    singleton->enemy1 = new Enemy("images/mushroom.png", 1,1,-0.95, -0.465, 0.1, 0.1);
    singleton->enemy2 = new Enemy("images/mushroom.png", 1,1,-1.2, -0.465, 0.1, 0.1);
    singleton->enemy3 = new Enemy("images/mushroom.png", 1,1,1.5, -0.465, 0.1, 0.1);
    singleton->enemy4 = new Enemy("images/mushroom.png", 1,1,-1.5, -0.465, 0.1, 0.1);
    singleton->enemy5 = new Enemy("images/mushroom.png", 1,1,-1.5, -0.465, 0.1, 0.1);
    singleton->enemy6 = new Enemy("images/mushroom.png", 1,1,1.5, -0.465, 0.1, 0.1);
    singleton->mario = new Player("images/MarioRunJump.png",2,4,0.0,-0.365,0.25,0.3);
    
    singleton->moving = true;
    singleton->game_over = false;
    
    if(singleton->trackScore->isGameLoadable()){
        cout<<"savedScore "<<singleton->trackScore->getSavedScore()<<endl;
        cout<<"savedEnemies "<<singleton->trackScore->getSavedNumEnemies()<<endl;
        singleton->trackScore->setScore(singleton->trackScore->getSavedScore());
        singleton->trackScore->setNumEnemy(singleton->trackScore->getSavedNumEnemies());
        singleton->trackScore->setLoadGameToFalse();
    }else{
        //cout<<"No game Loaded"<<endl;
        singleton->score = 0;
        singleton->trackScore->resetNumEnemy();
        
    }
   // cout<<"enemiesARRAYSize "<<singleton->enemies.size()<<endl;
    //make sure to allocate space just in case
    if(singleton->enemies.size() == 0){
        //cout<<"HEREEEEE"<<endl;
        singleton->enemies.push_back(singleton->enemy1);
        singleton->enemies.push_back(singleton->enemy2);
        singleton->enemies.push_back(singleton->enemy3);
        singleton->enemies.push_back(singleton->enemy4);
        singleton->enemies.push_back(singleton->enemy5);
        singleton->enemies.push_back(singleton->enemy6);
    }
    //refresh data
        singleton->enemies.at(0) = singleton->enemy1;
        singleton->enemies.at(1) = singleton->enemy2;
        singleton->enemies.at(2) = singleton->enemy3;
        singleton->enemies.at(3) = singleton->enemy4;
        singleton->enemies.at(4) = singleton->enemy5;
        singleton->enemies.at(5) = singleton->enemy6;
    
}
void app_timer(int value){
        if (singleton->up || singleton->down || singleton->left || singleton->right || singleton->moving && !singleton->game_over){
	    //if enemy touches mario its game over
	    //for(int i = 0;i<= singleton->numEnemy;i++){
	   if(singleton->enemies.at(0)->touchedPlayer(singleton->mario->getX(), singleton->mario->getY(), singleton->mario->getW(),singleton->mario->getH())||
		singleton->enemies.at(1)->touchedPlayer(singleton->mario->getX(), singleton->mario->getY(), singleton->mario->getW(),singleton->mario->getH())||
		singleton->enemies.at(2)->touchedPlayer(singleton->mario->getX(), singleton->mario->getY(), singleton->mario->getW(),singleton->mario->getH())||
		singleton->enemies.at(3)->touchedPlayer(singleton->mario->getX(), singleton->mario->getY(), singleton->mario->getW(),singleton->mario->getH())||
		singleton->enemies.at(4)->touchedPlayer(singleton->mario->getX(), singleton->mario->getY(), singleton->mario->getW(),singleton->mario->getH())||
		singleton->enemies.at(5)->touchedPlayer(singleton->mario->getX(), singleton->mario->getY(), singleton->mario->getW(),singleton->mario->getH())
		){
                      //cout<<"Enemy size1: "<<singleton->trackScore->getNumEnemy()<<endl;
            //cout<<"Touch player-------------------------"<<endl;
            //cout<<"mario y: "<<singleton->mario->getY()<<" y-h: "<<singleton->mario->getY() - singleton->mario->getH()<<endl;
            //cout<<"enemy y: "<<singleton->enemy1->getY()<<endl;
            singleton->trackScore->gameOver();
            singleton->trackScore->topThreeScores();
            singleton->gameOverMenu->setGameOver(true);
            
            
	    }
            //}
            singleton->redraw();
            glutTimerFunc(60, app_timer, value);
        }
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    singleton = this;
    mx = 0.0;
    my = 0.0;
    singleton->trackScore = new Score();
    restart();
    singleton->background = new Background("images/gameBackground.png", -1, 1, 2, 2);
    singleton->menu = new MainMenu();
    singleton->gameOverMenu = new GameOver();
    singleton->score = 0;
    singleton->moving = true;
    
    singleton->game_over = false;
    up = down = left = right = false;
    score = 0;
    moving = true;
    game_over = false;
    numEnemy =-1;
    app_timer(1);

}

void App::specialKeyPress(int key){
    if (!game_over){
        if (key == 100){
	    mario->setMoveLeft(1);
	    //cout<<"GOING LEFT"<<endl;
            //left = true;
        }
        if (key == 101){
            //up = true;
        }
        if (key == 102){
	    mario->setMoveRight(1);
      	    //cout<<"GOING Right"<<endl;
            //right = true;
        }
        if (key == 103){
            //down = true;
        }
    }
}

void App::specialKeyUp(int key){
    if (key == 100) {
	//cout<<"stop going left"<<endl;
	mario->setMoveLeft(0);
	//mario->setMoveStill(true);
        //left = false;
    }
    if (key == 101) {
       // up = false;
    }
    if (key == 102) {
	mario->setMoveRight(0);
	//mario->setMoveStill(true);
        //right = false;
    }
    if (key == 103) {
        down = false;
    }
}

void App::draw() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 1.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    if(gameOverMenu->gameOver()){
       // singleton->trackScore->gameOver();
        //singleton->trackScore->topThreeScores();
	//cout<<"game is over"<<endl;
	if(gameOverMenu->Exit()){
	        delete enemy1;
        	delete background;
        	delete this;
        	exit(0);
	}else if(gameOverMenu->isRestarting()){
        trackScore->resetScore();
		restart();
       // cout<<"-----------RESTART------------"<<endl;
	}
	gameOverMenu->draw();

    }else if(!menu->isPlaying()){
	menu->draw();
    }else{
    background->draw();
    
    
 
        //cout<<"Enemy size: "<<trackScore->getNumEnemy()<<endl;
    numEnemy = trackScore->getNumEnemy();	
    if(numEnemy >=enemies.size()){
	numEnemy = enemies.size() -1;
    }

    for(int i = 0;i <= numEnemy;i++){
		enemies.at(i)->draw();
    	}
    
	

    mario->draw();
       
    trackScore->addScore();
    
        
    mario->jumpAnim();
    //cout<<"Score "<<trackScore->getScore()<<endl;
        
   //     drawBitmapText(trackScore->getScore(), 0.0, .8, 0.0);
    }
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
    
    
}

void App::mouseDown(float x, float y){
    // Update app state

    mx = x;
    my = y;
   
    if(!menu->isPlaying()){
        
	//if player isnt playing check the menu for clicks
	menu->checkForClick(x,y);
        if(menu->checkForSave(x,y)){
            cout<<"Pressed Save"<<endl;
            trackScore->setSavedScore(trackScore->getScore());
            trackScore->setSavedNumEnemies(trackScore->getNumEnemy());
            cout<<"Saved Stuff "<<trackScore->getSavedScore()<<"  "<<trackScore->getSavedNumEnemies()<<endl;
            
        }
        if(menu->checkForLoad(x, y)){
            trackScore->setLoadGame();
            menu->setPlaying(true);
            cout<<"Pressed Load"<<endl;
            restart();
        }
        
    }
    if(gameOverMenu->gameOver()){
	gameOverMenu->checkForClick(x,y);
        
    }
	//cout<<"x::: "<<mx<<"  y:: "<<my<<endl;
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;

}

void App::idle(){

}

void App::keyPress(unsigned char key) {
    if(key == 13){
	cout<<"pause the game"<<endl;
	if(menu->isPlaying()){
		menu->setPlaying(false);
	}else{
		menu->setPlaying(true);
	}
    }
    if (key == 27){
        // Exit the app when Esc key is pressed
        delete enemy1;
        //delete platform;
        //delete gameOver;
        delete background;
        delete this;
        exit(0);
    }
    
    if (key == ' '){
        if(!mario->playerOnGround()){
            spacePressedCount++;
            //cout<<"Space Count === "<<spacePressedCount<<endl;
        }
        if(mario->playerOnGround()){
            //cout<<"RESET------------------------------"<<endl;
            spacePressedCount = 0;
        }
        if(spacePressedCount < 2 || mario->playerOnGround()){
            mario->setVelocityY(0.165f);
            //cout<<"--------------OVER HERE"<<endl;
        }
        //cout<<"Space Count === "<<spacePressedCount<<endl;
        //cout<<"New velocity = "<<mario->getVelocityY()<<endl;
	    //cout<<"JUMP"<<endl;
        //score++;

    }
}
