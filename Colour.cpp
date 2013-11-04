/*
 *  Colour.cpp
 *  Solar
 *
 *  Created by Michael Robinson on 29/11/2010.
 *  Copyright 2010 . All rights reserved.
 *
 */

#include "Colour.h"

Colour::Colour() {
	red = green = blue = 0.0f;
	alpha = 1.0f;
}

Colour::~Colour() {
	
}

Colour::Colour(const Colour& copyMe) {
	red = copyMe.getRedComponent();
	green = copyMe.getGreenComponent();
	blue = copyMe.getBlueComponent();
	alpha = copyMe.getAlphaComponent();
}

Colour& Colour::operator=(const Colour& assignFromMe) {
	if (this != &assignFromMe) {
		//delete members from the stack
		//none
		//copy in new members
		red = assignFromMe.getRedComponent();
		green = assignFromMe.getGreenComponent();
		blue = assignFromMe.getBlueComponent();
		alpha = assignFromMe.getAlphaComponent();
	}
	return *this;
}

Colour Colour::operator+(const Colour& otherColour) const {
	Colour newColour = Colour(otherColour.getRedComponent() + red, otherColour.getGreenComponent() + green, otherColour.getBlueComponent());
	if (newColour.getRedComponent() > 1.0f) {
		newColour.setRedComponent(1.0f);
	}
	if (newColour.getGreenComponent() > 1.0f) {
		newColour.setGreenComponent(1.0f);
	}
	if (newColour.getBlueComponent() > 1.0f) {
		newColour.setBlueComponent(1.0f);
	}
	return newColour;
}

Colour::Colour(float newRed, float newGreen, float newBlue, float newAlpha, float limit) {
	float factor = limit * 1.0f;
	red = newRed / factor;
	green = newGreen / factor;
	blue = newBlue / factor;
	alpha = newAlpha / factor;
}

Colour::Colour(unsigned short newRed, unsigned short newGreen, unsigned short newBlue, unsigned short newAlpha, unsigned short limit) {
	float factor = static_cast<float>(limit) * 1.0f;
	red = static_cast<float>(newRed) / factor;
	green = static_cast<float>(newGreen) / factor;
	blue = static_cast<float>(newBlue) / factor;
	alpha = static_cast<float>(newAlpha) / factor;
}

float Colour::getRedComponent() const {
	return red;
}

float Colour::getGreenComponent() const {
	return green;
}

float Colour::getBlueComponent() const {
	return blue;
}

float Colour::getAlphaComponent() const {
	return alpha;
}

float Colour::setRedComponent(float newRed) {
	return red = newRed;
}

float Colour::setGreenComponent(float newGreen) {
	return green = newGreen;
}

float Colour::setBlueComponent(float newBlue) {
	return blue = newBlue;
}

float Colour::setAlphaComponent(float newAlpha) {
	return alpha = newAlpha;
}

Colour* Colour::setRGBA(float newRed, float newGreen, float newBlue, float newAlpha = 1.0f, float limit = 1.0f) {
	float factor = limit * 1.0f;
	red = newRed / factor;
	green = newGreen / factor;
	blue = newBlue / factor;
	alpha = newAlpha / factor;
	return this;
}

unsigned short Colour::setRedComponent(unsigned short newRed, unsigned short limit) {
	red = static_cast<float> (newRed) / static_cast<float> (limit);
	return newRed;
}

unsigned short Colour::setGreenComponent(unsigned short newGreen, unsigned short limit) {
	green = static_cast<float> (newGreen) / static_cast<float> (limit);
	return newGreen;
}
unsigned short Colour::setBlueComponent(unsigned short newBlue, unsigned short limit) {
	blue = static_cast<float> (newBlue) / static_cast<float> (limit);
	return newBlue;
}
unsigned short Colour::setAlphaComponent(unsigned short newAlpha, unsigned short limit) {
	alpha = static_cast<float> (newAlpha) / static_cast<float> (limit);
	return newAlpha;
}
Colour* Colour::setRGBA(unsigned short newRed, unsigned short newGreen, unsigned short newBlue, unsigned short newAlpha, unsigned short limit) {
	red = static_cast<float> (newRed) / static_cast<float> (limit);
	green = static_cast<float> (newGreen) / static_cast<float> (limit);
	blue = static_cast<float> (newBlue) / static_cast<float> (limit);
	alpha = static_cast<float> (newAlpha) / static_cast<float> (limit);
	return this;
}

