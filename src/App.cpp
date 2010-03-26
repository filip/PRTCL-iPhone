
#include "App.h"


//some code you might want for use with the Accelerometer 
#define ACCELEROMETER_FORCE		0.2
//vel.x += ACCELEROMETER_FORCE * ofxAccelerometer.getForce().x * ofRandomuf();
//vel.y += -ACCELEROMETER_FORCE * ofxAccelerometer.getForce().y * ofRandomuf();		// this one is subtracted cos world Y is opposite to opengl Y


//--------------------------------------------------------------
void testApp::setup(){	
	printf("setup()\n");
	
	
	ofSetBackgroundAuto(true);
	ofSetFrameRate(60);
	
	// initialize the accelerometer
	ofxAccelerometer.setup();

	// touch events will be sent to this class (testApp)
	ofxMultiTouch.addListener(this);
	
	hello.setup();
	mello.setup();
	someFont.loadFont("04B_03__.TTF", 6, false, false);
	
	
	vx = 10;
	vy = 10;
	l = 120;
	
	mello.pos.x = 160;
	
	r = mello.pos.x;
	g = mello.pos.x;
	b = mello.pos.x;
	
	ofBackground(r, g, b);
	
	tooltip.setup();

	
	
}


//--------------------------------------------------------------
void testApp::update(){

	
	for (int i = 0; i < pts.size(); i++){
		pts[i].x += ofRandom(-1.25, 1.25);
		pts[i].y += ofRandom(-1.25, 1.25);
		
		pts[i].y += sin(ofGetElapsedTimef()) * vy;
		pts[i].x += cos(ofGetElapsedTimef()) * vx;
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].update();
		particles[i].pos.y += sin(ofGetElapsedTimef()) * vy;
		particles[i].pos.x += cos(ofGetElapsedTimef()) * vx;
		
		if (particles.size() > 600){
			particles.erase(particles.begin());
		}
		
	}
	
	if (vx == 1){
		for (int i = 0; i < pts.size(); i++){
			pts[i].x += ofRandom(-1.25, 1.25);
			pts[i].y += ofRandom(-1.25, 1.25);
			pts[i].y += 40*(ofxAccelerometer.getForce().y);
			pts[i].x += 40*(-ofxAccelerometer.getForce().x);
					
		}
	}
	
	if (vx == 1){
		for (int i = 0; i < particles.size(); i++){
			particles[i].update();
			particles[i].pos.y += 40*(ofxAccelerometer.getForce().y);
			particles[i].pos.x += 40*(-ofxAccelerometer.getForce().x);
			
		}
	}
		

		
	
	followPt.x = 0.96f * followPt.x + 0.04 * mouseX;
	followPt.y = 0.96f * followPt.y + 0.04 * mouseY;
	
	
	
	///ZACH CODE START
	
//	for(int i=particles.size()-1;i>=0;i--)
//	{
//		if(particles[i].life > l)
//		{
//			particles.erase(particles.begin()+i);
//		}
//	}
	
	//ZACH CODE END
	

	
	
	///SLIDERS
	
	if (mello.mVisible){
	
		r = mello.pos.x;
		g = mello.pos.x;
		b = mello.pos.x;
		
	}
	
	if(mello.pos.x > 290) {
		mello.pos.x = 290;
	}
	
	if(mello.pos.x < 30) {
		mello.pos.x = 30;
	}
	
	ofBackground(r, g, b);
	
	tooltip.r = r;
	tooltip.g = g;
	tooltip.b = b;
	
	
}

//--------------------------------------------------------------
void testApp::draw(){

	
	ofNoFill();
	ofBeginShape();
	ofEnableSmoothing();
	//ofSetColor(r-100, g-100, b-100);
	for (int i = 0; i < pts.size(); i++){
		ofVertex(pts[i].x, pts[i].y);
	}
	
	ofEndShape();
	
	for (int i = 0; i < pts.size(); i++){
		ofCircle(pts[i].x, pts[i].y, (pts[i].y)*0.15);
		ofSetColor(((pts[i].y)+r), ((pts[i].y-g)), b);
		ofFill();
		
	}
	
	
#pragma mark YOYO	
	
	ofFill();
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	//ofSetColor((ofRandom(0, 255)), (ofRandom(0, 255)), (ofRandom(0, 255)), 50);
	ofSetColor(r, g/2, b);
	
	ofBeginShape();
	for (int i = 0; i < particles
		 .size(); i++){
		ofCircle(particles[i].pos.x, particles[i].pos.y, 8);
		
	}
	
	ofEndShape();
	
	//the interior shape
	
	// lines
	
	ofBeginShape();
	ofNoFill();
	ofSetColor(r, g-100, b);
	ofEnableSmoothing();
	
	for (int i = 0; i < particles.size(); i++){
		ofVertex(particles[i].pos.x, particles[i].pos.y);
	}
	
	ofEndShape();
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].pos.x += ofRandom(-5, 5);
		particles[i].pos.y += ofRandom(-5, 5);
		
	}

	
	
	hello.draw();
	
	mello.draw();
	
	
	
	
	//////////////UI ELEMENTS START//////////////
	
	///UI BACKGROUND
	ofPushStyle();
	ofFill();
	ofEnableAlphaBlending();
	ofSetColor(0,0,0,70);	
	ofRect(0, 450, 320, 30);
	ofPopStyle();
	
	
	///CLEAR BUTTON
	ofPushStyle();
	ofSetColor(r,g,b);
	ofLine(300, 460, 310, 470);
	ofLine(310, 460, 300, 470);
	ofPopStyle();
	
	
	///ON OFF ACC BUTTON
	ofPushStyle();
	ofSetColor(r,g,b);
	ofRect(193, 458, 20, 15);
	ofRect(217, 458, 20, 15);
	ofRect(241, 458, 20, 15);
	ofSetLineWidth(1);
	ofPopStyle();

	
	///UI TEXT
	ofPushStyle();
	ofSetColor(r,g,b);
	someFont.drawString("SETTINGS", 10,468);
	
	someFont.drawString("1", 75,468);
	someFont.drawString("2", 105,468);
	someFont.drawString("3", 135,468);
	
	someFont.drawString("MOTION", 160,468);
	someFont.drawString("ON", 198,468);
	someFont.drawString("OFF", 221,468);
	someFont.drawString("ACC", 244,468);
	someFont.drawString("CLEAR", 270,468);
	
	ofPopStyle();

	tooltip.draw();
	
	//////////////UI ELEMENTS END//////////////

}

void testApp::exit() {
	printf("exit()\n");
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

// mouse functions are there for backwards compatibility
// they are simply the first finger to touch the screen
// you can omit the mouse functions and just use touch functions
// or omit touch functions and just use mouse functions if you don't need multitouch
//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}


//--------------------------------------------------------------
void testApp::touchDown(float x, float y, int touchId, ofxMultiTouchCustomData *data) {

	
	//SETTINGS
	if(x>10 && x<10+50 && y>450 && y<450+30)
	{
		hello.bVisible = !hello.bVisible;
		mello.mVisible = !mello.mVisible;
	
	}
	
	//1
	if(x>65 && x<65+30 && y>450 && y<450+30)
	{
		r = 255;
		g = 100;
		b = 0;
		ofBackground(r, g, b);
		
		//TOOLTIPS
		
		tooltip.x = 5;
		tooltip.bVisible = true;
		tooltip.text = "PRESET LOADED";
	}
	
	
	//2
	if(x>95 && x<95+30 && y>450 && y<450+30)
	{
		r = 255;
		g = 255;
		b = 0;
		ofBackground(r, g, b);
		
		tooltip.x = 35;
		tooltip.bVisible = true;
		tooltip.text = "PRESET LOADED";
	}
	
	//3
	if(x>125 && x<125+30 && y>450 && y<450+30)
	{
		r = 255;
		g = 100;
		b = 255;
		ofBackground(r, g, b);
		
		tooltip.x = 65;
		tooltip.bVisible = true;
		tooltip.text = "PRESET LOADED";
	}
	
	
	//MOTION ON
	if(x>193 && x<193+30 && y>450 && y<450+30)
	{
		vy = 10;
		vx = 10;
		l = 120;
		
		tooltip.x = 128;
		tooltip.bVisible = true;
		tooltip.text = "MOTION ON";
	}
	
	//MOTION OFF
	if(x>217 && x<217+30 && y>450 && y<450+30)
	{
		vy = 0;
		vx = 0;
		l = 240;
		
		tooltip.x = 153;
		tooltip.bVisible = true;
		tooltip.text = "MOTION OFF";
	}
	
	//MOTION ACC-ELOROMETER
	if(x>241 && x<241+30 && y>450 && y<450+30)
	{
		vx = 1;
		l = 60;		
		
		tooltip.x = 178;
		tooltip.bVisible = true;
		tooltip.text = "ACCELEROMETER";
	}
	
	//CLEAR
	if(x>290 && x<290+30 && y>450 && y<450+30)
	{
		pts.clear();
		particles.clear();
		
		//TOOLTIPS
		
		tooltip.x = 235;
		tooltip.bVisible = true;
		tooltip.text = "SCENE CLEARED";
	}
	
	

	
	
	
	
}


void testApp::touchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data) {

	ofPoint myPt;
	myPt.x = x;
	myPt.y = y;
	pts.push_back(myPt);
	
	
//	float dx = x - followPt.x;
//	float dy = y - followPt.y;
	
	for (int i = 0; i < 5; i++){
		particle tempParticle;
		tempParticle.pos.set(x,y);
		tempParticle.vel.set( ofRandom(-1,1), ofRandom(-1,1));
		//	tempParticle.vel.set( dx/80.0, dy/80.0);
		
		particles.push_back(tempParticle);
	}
	
	
	//SLIDERS
	
	
	mello.touchMoved(x, 250, 0);
	
	//x>95 && x<95+30 && y>450 && y<450+30
	
	
}


void testApp::touchUp(float x, float y, int touchId, ofxMultiTouchCustomData *data) {

}

void testApp::touchDoubleTap(float x, float y, int touchId, ofxMultiTouchCustomData *data) {

	//ofToggleFullscreen();
	
//	pts.clear();
//	particles.clear();
	
	
	
	
	
	
}

