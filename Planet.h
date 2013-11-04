/*
 *  Planet.h
 *  Solar
 *
 *  Created by Michael Robinson on 29/11/2010.
 *  Copyright 2010 . All rights reserved.
 *
 */
#import <string>
#import "Colour.h"

using std::string;

class Planet {

	private :
	class Orbit {
		
		public :
		double aphelion;
		double perihelion;
		float period;
		float inclination;
		
		Orbit();
		Orbit(const Orbit* newOrbit);
		
		double getAverageDistance() const;
		double getAphelion() const;
		double setAphelion(double newAphelion);
		double getPerihelion() const;
		double setPerihelion(double newPerihelion);
		float getPeriod() const;
		float setPeriod(float newPeriod);
		float getInclination() const;
		float setInclination(float newInclination);
		
	};
	
	string name;
	Orbit *orbit;
	float radius;
	float period;
	float axialTilt;
	Colour *colour;
	int satellites;

	public :
	Planet();
	~Planet();
	Planet(const Planet& copyMe);
	Planet& operator=(const Planet& assignFromMe);
	
	string getName() const;
	string setName(string newName);
	Orbit* getOrbit() const;
	Orbit* setOrbit(Orbit *newOrbit);
	float getRadius() const;
	float setRadius(float newRadius);
	float getPeriod() const;
	float setPeriod(float newPeriod);
	float getAxialTilt() const;
	float setAxialTilt(float newAxialTilt);
	Colour* getColour() const;
	Colour* setColour(Colour *newColour);
	int getNumSatellites() const;
	int setNumSatellites(int newNumSatellites);
};