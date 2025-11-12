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

/**
 * @class Planet
 * @brief Represents a planet in the solar system with physical and orbital properties.
 *
 * This class encapsulates all the information needed to render and simulate a planet
 * in a solar system visualization, including its orbital characteristics, physical
 * properties, appearance, and satellite count.
 */
class Planet {

	private :
	/**
	 * @class Orbit
	 * @brief Nested class representing the orbital characteristics of a planet.
	 *
	 * Contains information about a planet's elliptical orbit around the sun,
	 * including its closest and farthest distances, orbital period, and inclination.
	 */
	class Orbit {
		
		public :
		double aphelion;      ///< Farthest distance from the sun (in AU or appropriate units)
		double perihelion;    ///< Closest distance from the sun (in AU or appropriate units)
		float period;         ///< Orbital period (time to complete one orbit around the sun)
		float inclination;    ///< Orbital inclination relative to the ecliptic plane (in degrees)
		
		/**
		 * @brief Default constructor.
		 * Initializes all orbital parameters to zero.
		 */
		Orbit();
		
		/**
		 * @brief Constructor that copies from an existing Orbit object.
		 * @param newOrbit Pointer to the Orbit object to copy from.
		 * @note This is not a standard copy constructor as it takes a pointer.
		 */
		Orbit(const Orbit* newOrbit);
		
		/**
		 * @brief Calculates the average orbital distance.
		 * @return The average distance between aphelion and perihelion.
		 */
		double getAverageDistance() const;
		
		/**
		 * @brief Gets the aphelion distance.
		 * @return The farthest distance from the sun.
		 */
		double getAphelion() const;
		
		/**
		 * @brief Sets the aphelion distance.
		 * @param newAphelion The new aphelion value.
		 * @return The value that was set.
		 */
		double setAphelion(double newAphelion);
		
		/**
		 * @brief Gets the perihelion distance.
		 * @return The closest distance from the sun.
		 */
		double getPerihelion() const;
		
		/**
		 * @brief Sets the perihelion distance.
		 * @param newPerihelion The new perihelion value.
		 * @return The value that was set.
		 */
		double setPerihelion(double newPerihelion);
		
		/**
		 * @brief Gets the orbital period.
		 * @return The time to complete one orbit.
		 */
		float getPeriod() const;
		
		/**
		 * @brief Sets the orbital period.
		 * @param newPeriod The new orbital period value.
		 * @return The value that was set.
		 */
		float setPeriod(float newPeriod);
		
		/**
		 * @brief Gets the orbital inclination.
		 * @return The inclination angle in degrees.
		 */
		float getInclination() const;
		
		/**
		 * @brief Sets the orbital inclination.
		 * @param newInclination The new inclination angle in degrees.
		 * @return The value that was set.
		 */
		float setInclination(float newInclination);
		
	};
	
	string name;         ///< Name of the planet (e.g., "Earth", "Mars")
	Orbit *orbit;        ///< Pointer to the orbital characteristics
	float radius;        ///< Radius of the planet (in km or appropriate units)
	float period;        ///< Rotational period (time for one complete rotation)
	float axialTilt;     ///< Axial tilt relative to the orbital plane (in degrees)
	Colour *colour;      ///< Visual colour of the planet for rendering
	int satellites;      ///< Number of natural satellites (moons)

	public :
	/**
	 * @brief Default constructor.
	 * Initializes a planet with default values and allocates memory for orbit and colour.
	 */
	Planet();
	
	/**
	 * @brief Destructor.
	 * Cleans up dynamically allocated memory for orbit and colour.
	 */
	~Planet();
	
	/**
	 * @brief Copy constructor.
	 * @param copyMe The Planet object to copy from.
	 */
	Planet(const Planet& copyMe);
	
	/**
	 * @brief Assignment operator.
	 * @param assignFromMe The Planet object to assign from.
	 * @return Reference to this object.
	 */
	Planet& operator=(const Planet& assignFromMe);
	
	/**
	 * @brief Gets the planet's name.
	 * @return The name of the planet.
	 */
	string getName() const;
	
	/**
	 * @brief Sets the planet's name.
	 * @param newName The new name for the planet.
	 * @return The name that was set.
	 */
	string setName(string newName);
	
	/**
	 * @brief Gets the orbital characteristics.
	 * @return Pointer to the Orbit object.
	 */
	Orbit* getOrbit() const;
	
	/**
	 * @brief Sets the orbital characteristics.
	 * @param newOrbit Pointer to a new Orbit object.
	 * @return Pointer to the orbit that was set.
	 */
	Orbit* setOrbit(Orbit *newOrbit);
	
	/**
	 * @brief Gets the planet's radius.
	 * @return The radius of the planet.
	 */
	float getRadius() const;
	
	/**
	 * @brief Sets the planet's radius.
	 * @param newRadius The new radius value.
	 * @return The radius that was set.
	 */
	float setRadius(float newRadius);
	
	/**
	 * @brief Gets the rotational period.
	 * @return The time for one complete rotation.
	 */
	float getPeriod() const;
	
	/**
	 * @brief Sets the rotational period.
	 * @param newPeriod The new rotational period value.
	 * @return The period that was set.
	 */
	float setPeriod(float newPeriod);
	
	/**
	 * @brief Gets the axial tilt.
	 * @return The axial tilt in degrees.
	 */
	float getAxialTilt() const;
	
	/**
	 * @brief Sets the axial tilt.
	 * @param newAxialTilt The new axial tilt value in degrees.
	 * @return The axial tilt that was set.
	 */
	float setAxialTilt(float newAxialTilt);
	
	/**
	 * @brief Gets the planet's colour.
	 * @return Pointer to the Colour object.
	 */
	Colour* getColour() const;
	
	/**
	 * @brief Sets the planet's colour.
	 * @param newColour Pointer to a new Colour object.
	 * @return Pointer to the colour that was set.
	 */
	Colour* setColour(Colour *newColour);
	
	/**
	 * @brief Gets the number of satellites.
	 * @return The number of natural satellites (moons).
	 */
	int getNumSatellites() const;
	
	/**
	 * @brief Sets the number of satellites.
	 * @param newNumSatellites The new number of satellites.
	 * @return The number that was set.
	 */
	int setNumSatellites(int newNumSatellites);
};