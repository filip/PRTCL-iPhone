#pragma once

#include "ofMain.h"
#include "ofxMultiTouch.h"
#include "ofxAccelerometer.h"
#include "particle.h"
#include "about.h"
#include "slider.h"
#include "tooltip.h"


class testApp : public ofSimpleApp, public ofxMultiTouchListener  {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key) {}
	void keyReleased(int key)  {}
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
	void mouseReleased(int x, int y, int button );
	
	void touchDown(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL);
	void touchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL);
	void touchUp(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL);
	void touchDoubleTap(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL);
	
	vector < ofPoint > pts;
	
	ofPoint followPt;
	
	ofTrueTypeFont  someFont;
	
	vector < particle > particles;
	
	About hello;
	Slider mello;
	
	Tooltip tooltip;
	
	float r;
	float g;
	float b;
	
	float vx;
	float vy;
	float l;
	
	
};

