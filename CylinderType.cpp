//Implementation File for the class CylinderType
// CylinderType.cpp


#include "CylinderType.h"


//Constructor with two default parameters.  Client assigned.
//Postcondition: if parameters given:  radius = r;  height = h;
//       without parameters:   radius = 1.0; and  height = 1.0;
CylinderType::CylinderType(double r, double h)
            :CircleType (r)                 //initalizes r
{
    height = h;                            // assign the private height
    name = "Cylinder";                     // assign the name of the cylinder
}


//Destructor destroys cylinder objects [and returns memory to the heap]
CylinderType::~CylinderType()
{
    //cout << "cylinder destructor called" << endl; //outputs destructor to console
}

//Function to return the surface area of a cylinder.
//Overrides the circle's area function.
//Postcondition: Surface area is calculated and returned.
double CylinderType::area() const
{
    return 2 * CircleType::area() + circumference() * height;   // returns the area of a cylinder by performing the calculations necessary to find it
}


//Function to return the volume of a cylinder.
//Postcondition: Volume is calculated and returned.
double CylinderType::volume() const
{
    return CircleType::area() * height;   // returns the volume of a cylinder by performing the calculations necessary to find it
}


// function to override circle's print
// displays the radius, surface area, and volume
void CylinderType::print(ostream& outF) const // print function for the object one line
{
	cout << setw(11) << getName()            // outputs name to console
         << setw(12) << radius              // outputs radius to console
		 << setw(12) << circumference()     // outputs circumference to console
		 << setw(12) << area()              // outputs area to console
		 << setw(12) << getHeight()         // outputs height to console
		 << setw(12) << volume()            // outputs volume to console
		 << endl;
	outF << setw(11) << getName()           // prints name to output file
         << setw(12) << radius              // prints radius to output file
		 << setw(12) << circumference()     // prints circumference to output file
		 << setw(12) << area()              // prints area to output file
		 << setw(12) << getHeight()         // prints height to output file
		 << setw(12) << volume()            // prints volume to output file
		 << endl;
}

// gets the height of the cylinder
double CylinderType::getHeight() const
{
    return height;      // returns height
}

// gets the name of the object
string CylinderType::getName() const
{
   return name;         //returns name
}

// sets the height of the cylinder
void CylinderType::setHeight(double h)
{
    height = h;         //assigns h to private member height
}
