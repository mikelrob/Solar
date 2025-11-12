/*
 *  Colour.h
 *  Solar
 *
 *  Created by Michael Robinson on 29/11/2010.
 *  Copyright 2010 . All rights reserved.
 *
 */

/**
 * @class Colour
 * @brief Represents a colour with red, green, blue, and alpha (transparency) components.
 *
 * This class provides a way to store and manipulate RGBA colour values, typically used
 * for rendering planets and celestial objects in the Solar system visualization.
 * Component values are internally stored as floats normalized to the range [0.0, 1.0].
 */
class Colour {

	float red;    ///< Red component, normalized to range [0.0, 1.0]
	float green;  ///< Green component, normalized to range [0.0, 1.0]
	float blue;   ///< Blue component, normalized to range [0.0, 1.0]
	float alpha;  ///< Alpha (transparency) component, normalized to range [0.0, 1.0]

public:
	/**
	 * @brief Default constructor.
	 * Initializes a black colour with full opacity (red=0, green=0, blue=0, alpha=1).
	 */
	Colour();
	
	/**
	 * @brief Destructor.
	 */
	~Colour();
	
	/**
	 * @brief Copy constructor.
	 * @param copyMe The Colour object to copy from.
	 */
	Colour(const Colour& copyMe);
	
	/**
	 * @brief Assignment operator.
	 * @param assignFromMe The Colour object to assign from.
	 * @return Reference to this object.
	 */
	Colour& operator=(const Colour& assignFromMe);
	
	/**
	 * @brief Addition operator for colour blending.
	 * @param otherColour The colour to add to this colour.
	 * @return A new Colour object with component-wise addition (capped at 1.0).
	 */
	Colour operator+(const Colour& otherColour) const;
	
	/**
	 * @brief Constructor with float components.
	 * @param newRed Red component value.
	 * @param newGreen Green component value.
	 * @param newBlue Blue component value.
	 * @param newAlpha Alpha component value (default: 1.0).
	 * @param limit The maximum value for normalization (default: 1.0).
	 *              All components are divided by this value to normalize to [0.0, 1.0].
	 */
	Colour(float newRed, float newGreen, float newBlue, float newAlpha = 1.0f, float limit = 1.0f);
	
	/**
	 * @brief Constructor with unsigned short components.
	 * @param newRed Red component value.
	 * @param newGreen Green component value.
	 * @param newBlue Blue component value.
	 * @param newAlpha Alpha component value (default: 255).
	 * @param limit The maximum value for normalization (default: 255).
	 *              All components are divided by this value to normalize to [0.0, 1.0].
	 */
	Colour(unsigned short newRed, unsigned short newGreen, unsigned short newBlue, unsigned short newAlpha = 255u, unsigned short limit = 255u);

	
	
	/**
	 * @brief Gets the red component.
	 * @return The red component as a float in the range [0.0, 1.0].
	 */
	float getRedComponent() const;
	
	/**
	 * @brief Gets the green component.
	 * @return The green component as a float in the range [0.0, 1.0].
	 */
	float getGreenComponent() const;
	
	/**
	 * @brief Gets the blue component.
	 * @return The blue component as a float in the range [0.0, 1.0].
	 */
	float getBlueComponent() const;
	
	/**
	 * @brief Gets the alpha (transparency) component.
	 * @return The alpha component as a float in the range [0.0, 1.0].
	 */
	float getAlphaComponent() const;
	
	/**
	 * @brief Sets the red component using a float value.
	 * @param newRed The new red component value (should be in range [0.0, 1.0]).
	 * @return The value that was set.
	 */
	float setRedComponent(float newRed);
	
	/**
	 * @brief Sets the green component using a float value.
	 * @param newGreen The new green component value (should be in range [0.0, 1.0]).
	 * @return The value that was set.
	 */
	float setGreenComponent(float newGreen);
	
	/**
	 * @brief Sets the blue component using a float value.
	 * @param newBlue The new blue component value (should be in range [0.0, 1.0]).
	 * @return The value that was set.
	 */
	float setBlueComponent(float newBlue);
	
	/**
	 * @brief Sets the alpha component using a float value.
	 * @param newAlpha The new alpha component value (should be in range [0.0, 1.0]).
	 * @return The value that was set.
	 */
	float setAlphaComponent(float newAlpha);
	
	/**
	 * @brief Sets all RGBA components using float values.
	 * @param newRed Red component value.
	 * @param newGreen Green component value.
	 * @param newBlue Blue component value.
	 * @param newAlpha Alpha component value.
	 * @param limit The maximum value for normalization. All components are divided by this value.
	 * @return Pointer to this object.
	 */
	Colour* setRGBA(float newRed, float newGreen, float newBlue, float newAlpha, float limit);
	
	/**
	 * @brief Sets the red component using an unsigned short value.
	 * @param newRed The new red component value.
	 * @param limit The maximum value for normalization (default: 255).
	 * @return The input value that was provided.
	 */
	unsigned short setRedComponent(unsigned short newRed, unsigned short limit = 255u);
	
	/**
	 * @brief Sets the green component using an unsigned short value.
	 * @param newGreen The new green component value.
	 * @param limit The maximum value for normalization (default: 255).
	 * @return The input value that was provided.
	 */
	unsigned short setGreenComponent(unsigned short newGreen, unsigned short limit = 255u);
	
	/**
	 * @brief Sets the blue component using an unsigned short value.
	 * @param newBlue The new blue component value.
	 * @param limit The maximum value for normalization (default: 255).
	 * @return The input value that was provided.
	 */
	unsigned short setBlueComponent(unsigned short newBlue, unsigned short limit = 255u);
	
	/**
	 * @brief Sets the alpha component using an unsigned short value.
	 * @param newAlpha The new alpha component value.
	 * @param limit The maximum value for normalization (default: 255).
	 * @return The input value that was provided.
	 */
	unsigned short setAlphaComponent(unsigned short newAlpha, unsigned short limit = 255u);
	
	/**
	 * @brief Sets all RGBA components using unsigned short values.
	 * @param newRed Red component value.
	 * @param newGreen Green component value.
	 * @param newBlue Blue component value.
	 * @param newAlpha Alpha component value (default: 255).
	 * @param limit The maximum value for normalization (default: 255).
	 * @return Pointer to this object.
	 */
	Colour* setRGBA(unsigned short newRed, unsigned short newGreen, unsigned short newBlue, unsigned short newAlpha = 255u, unsigned short limit = 255u);

};