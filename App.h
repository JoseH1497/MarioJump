#ifndef App_hpp
#define App_hpp

#include "Background.h"
#include "Object.h"
#include "GlutApp.h"
#include "Player.h"
#include "Enemy.h"
#include "TexRect.h"
#include "GameOver.h"
#include "AnimatedRect.h"
#include "MainMenu.h"
#include "Score.h"
#include <vector>
class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    
    void specialKeyPress(int key);
    
    void specialKeyUp(int key);
    
    void idle();
    
    Enemy* enemy1;Enemy* enemy2;Enemy* enemy3;Enemy* enemy4;Enemy* enemy5;Enemy* enemy6;
    
    TexRect* platform;
    Object* mushroom;
    //TexRect* background;
    Background* background;
    AnimatedRect* gameOver;
    Player* mario;
    MainMenu* menu;
    GameOver* gameOverMenu;
    Score* trackScore;
    bool up;
    bool down;
    bool left;
    bool right;
    vector<Enemy*> enemies;
    bool moving;
    bool game_over;
    int score;
    int numEnemy;
    
};

#endif
