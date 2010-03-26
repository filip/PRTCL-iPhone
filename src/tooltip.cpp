/*
 *  tooltip.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 18/03/2010.
 *  Copyright 2010 University for the Creative Arts. All rights reserved.
 *
 */

#include "tooltip.h"

void Tooltip::setup(){
	bVisible = false;
	
	someFont.loadFont("04B_03__.TTF", 6, false, false);
	titleFont.loadFont("PixelSplitter-Bold.ttf", 10, false, false);
	
	squareAlpha = 255.0f;
	
	
}

void Tooltip::update(){
	
		//if( squareAlpha = 0.0f ) bVisible = false;
		
}

void Tooltip::draw(){
	if (bVisible){
		
		
		squareAlpha -= 7.5f; 
		if( squareAlpha < 0.0f ) squareAlpha = 255.0f;
		if( squareAlpha == 0.0f ) bVisible = false;
		
		
		ofFill();
		ofEnableAlphaBlending();
		ofSetColor(r-150,g-150,b-150, (int)squareAlpha );
		ofRect(x, 420, 80, 20);
		ofTriangle(x+70, 440, x+80, 440, x+75, 445);
		
		ofEnableAlphaBlending();
		ofSetColor(r,g,b, (int)squareAlpha );
		someFont.drawString(text, x+10,432);
		
		
		//SHADOW
		
//		ofSetColor(r-20,g-20,b-20, 50 );
//		ofRect(x+2, 418, 80, 20);
//		
//		ofSetColor(r-20,g-20,b-20, 30 );
//		ofRect(x+4, 416, 80, 20);
		
		
		}
	
	
	
		
	
	}
	
	