#ifndef Object_h
#define Object_h

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif

using namespace std;

class Object{
protected:
        float x;
        float y;
        float h;
        float w;
        GLuint texture_id;

public:
	Object();
	Object (const char*, float, float, float, float);
        float getX();
        float getY();
        float getH();
        float getW();
        void setX(float);
        void setY(float);
        void setH(float);
        void setW(float); 
        void setID(GLuint);
        void draw();
        bool contains(float, float);
        void moveUp(float rate=0.01);
        void moveDown(float rate=0.01);
        void moveLeft(float rate=0.01);
        void moveRight(float rate=0.01);
        void jump();
        bool rising;
        bool movingLeft;
        float xinc;
        float yinc;
};

#endif

