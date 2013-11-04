/*
 *  Colour.h
 *  Solar
 *
 *  Created by Michael Robinson on 29/11/2010.
 *  Copyright 2010 . All rights reserved.
 *
 */

class Colour {

	float red;
	float green;
	float blue;
	float alpha;

public:
	Colour();
	~Colour();
	Colour(const Colour& copyMe);
	Colour& operator=(const Colour& assignFromMe);
	Colour operator+(const Colour& otherColour) const;
	Colour(float newRed, float newGreen, float newBlue, float newAlpha = 1.0f, float limit = 1.0f);
	Colour(unsigned short newRed, unsigned short newGreen, unsigned short newBlue, unsigned short newAlpha = 255u, unsigned short limit = 255u);

	
	
	float getRedComponent() const;
	float getGreenComponent() const;
	float getBlueComponent() const;
	float getAlphaComponent() const;
	float setRedComponent(float newRed);
	float setGreenComponent(float newGreen);
	float setBlueComponent(float newBlue);
	float setAlphaComponent(float newAlpha);
	Colour* setRGBA(float newRed, float newGreen, float newBlue, float newAlpha, float limit);
	unsigned short setRedComponent(unsigned short newRed, unsigned short limit = 255u);
	unsigned short setGreenComponent(unsigned short newGreen, unsigned short limit = 255u);
	unsigned short setBlueComponent(unsigned short newBlue, unsigned short limit = 255u);
	unsigned short setAlphaComponent(unsigned short newAlpha, unsigned short limit = 255u);
	Colour* setRGBA(unsigned short newRed, unsigned short newGreen, unsigned short newBlue, unsigned short newAlpha = 255u, unsigned short limit = 255u);

};