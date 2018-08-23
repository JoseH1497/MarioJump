#ifndef Background_h
#define Background_h
#include"Object.h"

class Background : public Object{

public:
	Background(const char*,float,float,float,float);
	void draw();
};





#endif
