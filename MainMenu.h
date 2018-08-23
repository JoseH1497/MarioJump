#ifndef MainMenu_h
#define MainMenu_h

#include "Object.h"
#include "Background.h"

class MainMenu{
protected:
	bool playing;
public:
	MainMenu();
	void checkForClick(float, float);
	void draw();
	void setPlaying(bool);
	bool isPlaying();
	Background* background;
	Object* playButton;
	Object* restartButton;
	Object* saveButton;
    bool checkForSave(float, float);
     bool checkForLoad(float, float);
    
};



#endif
