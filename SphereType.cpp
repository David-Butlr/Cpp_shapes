//Implementation File for the class SphereTypre
// SphereType.cpp

#include "SphereType.h"

//Constructor with one default parameter.  Client assigned.
//Postcondition: if parameters are given:  radius = r
SphereType::SphereType(double r)             // constructor (w/one default parameter)
        :CircleType (r)                  // initalizes r
{
    radius = r;                          // assign the private radius
    name = "Sphere";                     // assign the name of the sphere
}


//Destructor destroys sphere objects [and returns memory to the heap]
SphereType::~SphereType()
{
    //cout << "sphere destructor called" << endl; // outputs destructor to console
}


//Function to return the surface area of a sphere
//Overrides the circle's area function.
//Postcondition: Surface area is calculated and returned.
double SphereType::area() const
{
    return 4.0 * CircleType::area(); // returns 4 * circles area, which is the area of a sphere
}


//Function to return the volume of a sphere
//Postcondition: Volume is calculated and returned.
double SphereType::volume() const
{
    return (4.0/3.0) * CircleType::area() * radius;  // returns (4/3)* circles area * radius, which is the volume of a sphere
}

// function to override circle's print
// displays the radius, height, surface area, and volume
void SphereType::print(ostream& outF) const // print function for the object one line
{
	cout << setw(11) << getName()           // outputs name to console
         << setw(12) << radius              // outputs radius to console
		 << setw(12) << circumference()     // outputs circumference to console
		 << setw(12) << area()              // outputs area to console
		 << setw(12) << getHeight()         // outputs height to console
		 << setw(12) << volume()            // outputs volume to console
		 << endl;                           // outputs newline to console
	outF << setw(11) << getName()           // prints name to output file
         << setw(12) << radius              // prints radius to output file
		 << setw(12) << circumference()     // prints circumference to output file
		 << setw(12) << area()              // prints area to output file
		 << setw(12) << getHeight()         // prints height to output file
		 << setw(12) << volume()            // prints volume to output file
		 << endl;                           // prints newline to output file
}


// Function to return the height of a sphere (really the same as diameter)
// Postcondition:  height (diameter) is calculated and returned
double SphereType::getHeight() const
{
    return CircleType::radius*2;   // returns circle's radius * 2, which is the height of a sphere
}


// gets the name of the object
string SphereType::getName() const
{
    return name;    // returns name
}


// sets the height (diameter) of a sphere
// by setting the circle’s radius to half the sphere’s height
void SphereType::setHeight(double r)
{
   radius = r/2.0;  // assigns r/2.0 to radius
}
