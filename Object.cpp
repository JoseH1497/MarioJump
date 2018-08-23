#include "Object.h"

#include<iostream>
using namespace std;

Object::Object(){
};
Object::Object (const char* filename, float x, float y, float w, float h){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

     texture_id = SOIL_load_OGL_texture (
     filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    rising = false;
    movingLeft = true;

    xinc = 0.01;
    yinc = 0.01;


}
float Object::getX(){
	return x;

}
float Object::getY(){
	return y;
}
float Object::getH(){
	return h;
}
float Object::getW(){
	return w;
}
void Object::setX(float x){
	this->x =  x;
}
void Object::setY(float y){
	this->y = y;
}
void Object::setH(float h){
	this->h = h;
}
void Object::setW(float w){
	this->w = w;
}
void Object::setID(GLuint id){
	this->texture_id = id;
}
void Object::draw(){
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex2f(x, y - h);
    glTexCoord2f(0, 1);
    glVertex2f(x, y);
    glTexCoord2f(1, 1);
    glVertex2f(x+w, y);
    glTexCoord2f(1, 0);
    glVertex2f(x+w, y - h);
    glEnd();
    glDisable(GL_TEXTURE_2D);



}
bool Object::contains(float mx, float my){
	return mx >= x && mx <= x+w && my <= y && my >= y - h;
}
void Object::moveUp(float rate){

}
void Object::moveDown(float rate){

}
void Object::moveLeft(float rate){

}
void Object::moveRight(float rate){

}
void Object::jump(){

}
