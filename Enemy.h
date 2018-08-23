#ifndef Enemy_h
#define Enemy_h

#if defined WIN32
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <SOIL.h>
#else
#include <SOIL.h>
#endif

#include"Object.h"
class Enemy : public Object{

protected:

    int rows;
    int cols;
    int curr_row;
    int curr_col;
    bool complete;
    bool animating;

public:
        Enemy(const char*,int,int,float,float,float,float);
	bool touchedPlayer(float, float, float, float);
	void EnemyMovement();
        void draw();
        bool done();
        void advance();
        void incY();
        void reset();
        void animate();
        void stop();
        void jump();

};


#endif

