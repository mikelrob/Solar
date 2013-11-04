/*
 *  Planet.cpp
 *  Solar
 *
 *  Created by Michael Robinson on 29/11/2010.
 *  Copyright 2010 . All rights reserved.
 *
 */

#include "Planet.h"

Planet::Orbit::Orbit() {
	aphelion = 0.0;
	perihelion = 0.0;
	period = 0.0f;
	inclination = 0.0f;
}

Planet::Orbit::Orbit(const Orbit *newOrbit) { //constructor with pointer to Orbit object - THIS IS NOT A COPY CONSTRUCTOR
	aphelion = newOrbit->aphelion;
	perihelion = newOrbit->perihelion;
	period = newOrbit->period;
	inclination = newOrbit->inclination;
}

double Planet::Orbit::getAverageDistance() const {
	return aphelion + perihelion / 2;
}

double Planet::Orbit::getAphelion() const {
	return aphelion;
}

double Planet::Orbit::setAphelion(double newAphelion) {
	return aphelion = newAphelion;
}

double Planet::Orbit::getPerihelion() const {
	return perihelion;
}

double Planet::Orbit::setPerihelion(double newPerihelion) {
	return perihelion = newPerihelion;
}

float Planet::Orbit::getPeriod() const {
	return period;
}

float Planet::Orbit::setPeriod(float newPeriod) {
	return period = newPeriod;
}

float Planet::Orbit::getInclination() const {
	return inclination;
}

float Planet::Orbit::setInclination(float newInclination) {
	return inclination = newInclination;
}

Planet::Planet() {
	name = "";
	radius = 0.0f;
	period = 0.0f;
	axialTilt = 0.0f;
	orbit = new Orbit();
	colour = new Colour();
	satellites = 0;
}

Planet::~Planet() {
	if (orbit != 0) {
		delete orbit;
		orbit = 0;
	}
}

Planet::Planet(const Planet& copyMe){
	//set data members stored in stack
	name = copyMe.getName();
	radius = copyMe.getRadius();
	period = copyMe.getPeriod();
	
	//data member pointer has not pointed to anythin yet so nothin the delete
	//create data members on the heap
	orbit = new Orbit(copyMe.getOrbit());
}

Planet& Planet::operator=(const Planet& assignFromMe) {
	if (this != &assignFromMe) {
		
		//set data members stored in stack
		name = assignFromMe.getName();
		radius = assignFromMe.getRadius();
		period = assignFromMe.getPeriod();
	
		//delete data members from the heap
		if (orbit != 0) {
			delete orbit;
		}
		// create new copies of data members on the heap
		orbit = new Orbit(assignFromMe.getOrbit());		  
	
	}
	return *this;
}

string Planet::getName() const {
	return name;
}

string Planet::setName(string newName) {
	return name = newName;
}

Planet::Orbit* Planet::getOrbit() const {
	return orbit;
}

Planet::Orbit* Planet::setOrbit(Orbit *newOrbit) {
	return orbit = newOrbit;
}

float Planet::getRadius() const {
	return radius;
}

float Planet::setRadius(float newRadius) {
	return radius = newRadius;
}

float Planet::getPeriod() const {
	return period;
}

float Planet::setPeriod(float newPeriod) {
	return period = newPeriod;
}

float Planet::getAxialTilt() const {
	return axialTilt;
}

float Planet::setAxialTilt(float newAxialTilt) {
	return axialTilt =  newAxialTilt;
}

Colour* Planet::getColour() const {
	return colour;
}

Colour* Planet::setColour(Colour *newColour) {
	return colour = newColour;
}

int Planet::getNumSatellites() const {
	return satellites;
}

int Planet::setNumSatellites(int newNumSatellites) {
	return satellites = newNumSatellites;
}
