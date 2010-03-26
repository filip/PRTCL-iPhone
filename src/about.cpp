/*
 *  about.cpp
 *  ptcleiPhone
 *
 *  Created by Filip Visnjic on 28/02/2010.
 *
 */

#include "about.h"




void About::setup(){
	bVisible = false;
	
	someFont.loadFont("04B_03__.TTF", 6, false, false);
	titleFont.loadFont("PixelSplitter-Bold.ttf", 10, false, false);
	
	
	r = 220;
	g = 220;
	b = 220;

}


void About::draw(){
	if (bVisible){
		
		ofPushStyle();
		ofFill();
		ofEnableAlphaBlending();
		ofSetColor(0,0,0,70);
		ofRect(10, 10, 300, 430);
		ofPopStyle();
		
		
		ofPushStyle();
		ofSetColor(r,g,b);
		someFont.drawString("FILIP VISNJIC 2010 // FVDA.CO.UK // CREATIVEAPPLICATIONS.NET", 30,50); 
		someFont.drawString("VER 1.0 CREATED AT THE V&A DECODE OPENFRAMEWORKS WORKSHOP\nIN LONDON 28/02/2010", 30,70);
		someFont.drawString("THANKS TO JOEL GETHIN LEWIS, ZACH LIEBERMAN, KYLE MCDONALD,\nARTURO CASTRO, ANDREAS MULLER, EDUARD PRATS MOLNER,\nZACH GAGE, ONEDOTZERO AND VICTORIA AND ALBERT MUSEUM\n", 30,110);
		someFont.drawString("CREATED WITH OPENFRAMEWORKS", 30,150);
		someFont.drawString("FOR INFORMATION ON OPENFRAMEWORKS SEE\nHTTP://OPENFRAMEWORKS.CC", 30,170);
		someFont.drawString("FOR INFORMATION ON PAST AND FUTURE WORKSHOPS SEE\nHTTP://WIKI.OPENFRAMEWORKS.CC", 30,200);
		someFont.drawString("CHANGE COLOUR MODE", 30,240);
		
		titleFont.drawString("PRTCL", 30,420); //font experiments
		someFont.drawString("1.1", 80,410);
		
		ofPopStyle();
		
		
		ofPushStyle();
		ofFill();
		ofSetColor(r,g,b);
		ofRect(30, 250, 260, 1);
		ofPopStyle();
		
//		ofPushStyle();
//		ofFill();
//		ofSetColor(r,g,b);
//		ofRect(50, 245, 10, 10);
//		ofPopStyle();
		
		
		
	}
	
	
}
