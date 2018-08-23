#include"Object.h"
#include"Player.h"
#include<iostream>
using namespace std;


float groundPosition = -0.365;


Player::Player(const char* filename,int rows, int cols, float x = 0, float y = 0, float w = 0.5, float h = 0.5){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture
    (
     filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    this->rows = rows;
    this->cols = cols;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->velocityY = 0.0;
    this->onGround = true;
    this->gravity = 1.25;
    this->groundPosition = -0.365;
    curr_row = 1;
    curr_col = 1;
    left = false;
    right = false;
    still = true;
    complete = false;
    animating = false;

}
void Player::draw(){


float xinc = 1.0/cols;
float yinc = 1.0/rows;
float top;
float bottom;
float leftI;
float rightI;

advance();
//cout<<"WHY????::Still:: "<<still<<"  left:: "<<left<<"  Right:: "<<right<<endl;
 glBindTexture( GL_TEXTURE_2D, texture_id );
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


if(still){
	//cout<<"Mario is Staying still"<<endl;
	top = 1;
	bottom = 0.5;
        leftI = 0;
	rightI = 0.25;
}else if(left){
	if (x >= -0.98)
		x= x-0.02;
	//cout<<"Mario is moving Left"<<endl;
	top = 1 - yinc * (curr_row - 1);
        bottom = 1 - yinc * curr_row;
        leftI = xinc * (curr_col - 1);
	rightI = xinc * curr_col;
}else if(right){
	if(x <= 0.8)
		x = x + 0.02;
    //cout<<"Mario on ground: "<<this->getY()<<endl;
	//cout<<"Mario is moving Right"<<endl;
	top = 1 - yinc * (curr_row - 1);
        bottom = 1 - yinc * curr_row;
        leftI = xinc * (curr_col - 1);
        rightI = xinc * curr_col;
	
}else if(jump){
	//cout<<"Mario is jumping"<<endl;

}

        glBegin(GL_QUADS);
        glTexCoord2f(leftI, bottom);
        glVertex2f(x, y - h);
        glTexCoord2f(leftI, top);
        glVertex2f(x, y);
        glTexCoord2f(rightI, top);
        glVertex2f(x+w, y);
        glTexCoord2f(rightI, bottom);
        glVertex2f(x+w, y - h);
        glEnd();
	glDisable(GL_TEXTURE_2D);


}
void Player::setMoveStill(bool move){
        still = move;
}
bool Player::getMoveStill(){
        return still;
}
void Player::setMoveLeft(bool move){
	if(move){
		still = false;
	}else{
		still = true;
	}
	//cout<<"??"<<move<<endl;
	this->left = move;
}
bool Player::getMoveLeft(){
	return left;
}
void Player::setMoveRight(bool move){
	if(move){
		still = false;
	}else{
		still = true;
	}
	//cout<<"right????"<<move<<endl;
        this->right = move;
}
bool Player::getMoveRight(){
        return right;
}
void Player::setMoveJump(bool move){
	if(move)
		still = false;
        jump = move;
}
bool Player::getMoveJump(){
        return jump;
}

void Player::setVelocityY(float vel){
    this->velocityY = vel;
}
float Player::getVelocityY(){
    return this->velocityY;
}
bool Player::done() {
    return complete;
}

void Player::incY(){
    y+=0.01;
    
}

bool Player::playerOnGround(){
    return this->onGround;
}

void Player::advance(){
	if(left){
		curr_row = 2;
		if (curr_col < 3){
			curr_col++;
    		}else{
			curr_col = 1;
		}
	}
	if(right){
        	curr_row = 1;
        	if (curr_col < 3){
                	curr_col++;
        	}else{
                	curr_col = 1;
        	}
	}
}

void Player::reset(){
    complete = false;
}

void Player::animate(){
    animating = true;
}

void Player::stop(){
    animating = false;
}

void Player::jumpAnim(){
    //cout<<"Mario position"<<this->y<<endl;
    if(this->getY() >-0.364){// if above ground-> add gravity
        
        //velocityY -= gravity*(1.f/60.f);
        this->setVelocityY(this->getVelocityY() - this->gravity*(1.f/60.f));
        this->onGround = false;
        
        
    }else if(this->getY() < -0.366){ //if below ground put back to ground
        
        this->y = -0.365;
        //velocityY = 0;
        this->setVelocityY(0.0);
        //cout<<"GOT HERE"<<endl;
        this->onGround = true;
        
    }
    //cout<<"Adding to y"<<endl;
    
    this->y += this->getVelocityY();
    //cout<<"Y = "<<this->y<<"getY = "<<this->getY()<<endl;
    
    
    
}



