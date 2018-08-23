#ifndef Player_h
#define Player_h

#if defined WIN32
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <SOIL.h>
#else
#include <SOIL.h>
#endif

#include"Object.h"
class Player: public Object{

protected:

    int rows;
    int cols;
    int curr_row;
    int curr_col;
    bool complete;
    bool animating;
    bool left;
    bool right;
    bool jump;
    bool still;
    float velocityY;
    bool onGround;
    float gravity;
    float groundPosition;
public:
	Player(const char*,int,int,float,float,float,float);
	void draw();
	bool done();
    	void advance();
	void setMoveStill(bool);
	void setMoveLeft(bool);
	void setMoveRight(bool);
	void setMoveJump(bool);
	bool getMoveLeft();
	bool getMoveRight();
	bool getMoveJump();
	bool getMoveStill();
    	void incY();
   	void reset();
   	void animate();
   	void stop();
	void jumpAnim();
    void setVelocityY(float);
    float getVelocityY();
    bool playerOnGround();
};


#endif
