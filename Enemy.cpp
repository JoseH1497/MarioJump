#include"Object.h"
#include"Enemy.h"
#include <iostream>
using namespace std;
Enemy::Enemy(const char* filename,int rows = 1, int cols = 1, float x = 0, float y = 0, float w = 0.5, float h = 0.5){
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
    
    curr_row = 1;
    curr_col = 1;
    
    complete = false;
    animating = false;
}

void Enemy::draw(){
EnemyMovement();
if (animating){
        glBindTexture( GL_TEXTURE_2D, texture_id );
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


        float xinc = 1.0/cols;
        float yinc = 1.0/rows;


        float top = 1 - yinc * (curr_row - 1);
        float bottom = 1 - yinc * curr_row;

        float left = xinc * (curr_col - 1);
        float right = xinc * curr_col;

        glBegin(GL_QUADS);

        glTexCoord2f(left, bottom);
        glVertex2f(x, y - h);

        glTexCoord2f(left, top);
        glVertex2f(x, y);

        glTexCoord2f(right, top);
        glVertex2f(x+w, y);

        glTexCoord2f(right, bottom);
        glVertex2f(x+w, y - h);

        glEnd();

        glDisable(GL_TEXTURE_2D);
    }


}

void Enemy::EnemyMovement(){
	animating = true;
                if (movingLeft)
                        x= x-0.03;
                else
                        x= x + 0.03;
                if (x > .90)
                        movingLeft = true;
                if (x < -.98)
                        movingLeft = false;

}


bool Enemy::done() {
    return complete;
}

void Enemy::incY(){
    y+=0.01;
    
}

void Enemy::jump(){
    y += 0.5;
    
}

void Enemy::advance(){
    if (curr_col < cols){
        curr_col++;
    }
    else {
        if (curr_row < rows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }
    if (curr_row == rows && curr_col == cols){
	complete = true;
    }
}

bool Enemy::touchedPlayer(float mx, float my, float mw, float mh){
//Game is over
    //MARK: - Changed how this worked because it would return true whenever mario jumped over the enemy
    //instead of only returning true when it actually touched the enemy
	
    //cout<<"Mushroom y= "<<y<<endl;
    //cout<<"Mario y-h= "<<my - mh<<endl;
    return (mx <= x+w-0.06 && mx >= x || mx+mw-0.06 >= x && x+w >= mx+mw) && (my - mh) <= y;
    

}

void Enemy::reset(){
    complete = false;
}

void Enemy::animate(){
    animating = true;
}

void Enemy::stop(){
    animating = false;
}

