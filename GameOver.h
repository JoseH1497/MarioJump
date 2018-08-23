#ifndef GameOver_h
#define GameOver_h
#include"Background.h"
#include"Object.h"

class GameOver{
protected:
	bool gameOverBool;
	bool exitBool;
	bool restartBool;
public:

	GameOver();
	bool gameOver();
	bool isRestarting();
	void setGameOver(bool);
	void draw();
	bool Exit();
	void checkForClick(float, float);
	Background* back;
	Object* restart;
	Object* exit;
};


#endif
