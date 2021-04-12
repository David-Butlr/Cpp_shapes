//Implementation File for the class ConeType
// ConeType.cpp

#include "ConeType.h"

//Constructor with two default parameters.  Client assigned.
//Postcondition: if parameters are given:  radius = rad, height = heit
//       without parameters:   radius = 1.0    height = 1.0
ConeType::ConeType(double r, double h)
        :CircleType (r)                // initalizes r
{
    height = h;                        // assign the private height
    name = "Cone";                     // assign the name of the cone
}

//Destructor destroys cone objects [and returns memory to the heap]
ConeType::~ConeType()
{
    //cout << "sphere destructor called" << endl; // outputs destructor to console
}


//Function to return the surface area of a cone
//Overrides the circle's area function                  ** override **
//Postcondition: Surface area is calculated and returned.
double ConeType::area() const
{
    ConeType sh(radius,height); // creates a coneType called sh
    return  CircleType::area() + (M_PI * radius * sh.getSlantHeight()); // returns area of circle * PI * radius * slant height which = the area of a cone
}


//Function to return the volume of a cone
//Postcondition: Volume is calculated and returned.
double ConeType::volume() const
{
    return (1.0/3.0) * CircleType::area() * height; // returns 1.0/3.0 * circles area * height which = volume of a cone
}


// function to override circle's print                  ** override **
// displays the radius, height, surface area, and volume
void ConeType::print(ostream& outF) const // print function for the object one line
{
	cout << setw(11) << getName()           // outputs name to console
         << setw(12) << radius              // outputs radius to console
		 << setw(12) << circumference()     // outputs circumference to console
		 << setw(12) << area()              // outputs area to console
		 << setw(12) << getHeight()         // outputs height to console
		 << setw(12) << volume()            // outputs volume to console
		 << setw(13) << getSlantHeight()    // outputs slant height to console
		 << endl;
	outF << setw(11) << getName()           // prints name to output file
         << setw(12) << radius              // prints radius to output file
		 << setw(12) << circumference()     // prints circumference to output file
		 << setw(12) << area()              // prints area to output file
		 << setw(12) << getHeight()         // prints height to output file
		 << setw(12) << volume()            // prints volume to output file
		 << setw(13) << getSlantHeight()    // prints slant height to output file
		 << endl;
}


// Function to return the height of a cone (really the same as diameter)
// Postcondition:  height (diameter) is calculated and returned
double ConeType::getHeight() const
{
    return height;      // returns height
}


//overrides base class & gets the name of the cone    ** override **
string ConeType::getName() const
{
    return name;        // returns name
}


// Function to return the slant height of a cone (based on pythag. theorem)
// Postcondition:  slant height is calculated and returned
double ConeType::getSlantHeight() const
{
    double cSqrd = pow(radius,2) + pow(height,2);  // apply a^2 + b^2 and assigns it to cSqrd
    return sqrt(cSqrd);     // returns the sqrt of cSqrd which is the slant height of a cone
}


// sets the height (diameter) of a cone
// by setting the circle’s radius to half the cone’s height
void ConeType::setHeight(double h)
{
    height = h;     // assigns h to private member height
}
