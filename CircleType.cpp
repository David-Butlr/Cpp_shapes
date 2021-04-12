//Implementation File for the class CircleType
// CircleType.cpp
// This is only a start.  More functions must be implemented

#include "CircleType.h"


//Constructor with one default parameter.
//Radius is set according to the parameter.
//Postcondition: radius = r or 1.0 if not specified
CircleType::CircleType(double r)            // constructor (w/default parameter)
{
    radius = r;                             // assigns the private radius
    name = "2D Circle";                     // assigns the name of the circle
}


//Destructor destroys circle objects [and returns memory to the heap]
CircleType::~CircleType()
{
    //cout << "circle destructor called" << endl; //outputs destructor to console
}


//Function to return the radius.
//Postcondition: The value of radius is returned.
double CircleType::getRadius() const
{
    return radius; // returns radius
}


//Function to return the area of a circle.
//Postcondition: Area is calculated and returned.
double CircleType::area() const
{
    return M_PI * pow(radius,2); // returns pi * radius^squared, which is the area of a circle
}


//Function to return the circumference of a circle.
//Postcondition: Circumference is calculated and returned.
double CircleType::circumference() const
{
    return 2.0 * M_PI * radius;  // returns 2 * pi * radius, which is the circumference of a circle
}


// function to print the radius, area, and circumference
// of the object (in one complete line)
void CircleType::print(ostream& outF) const
{
	cout << setw(11) << getName()          // outputs name to console
         << setw(12) << getRadius()        // outputs radius to console
		 << setw(12) << circumference()    // outputs circumference to console
		 << setw(12) << area()             // outputs area to console
		 << endl;                          // outputs newline to console
	outF << setw(11) << getName()          // prints name to output file
         << setw(12) << getRadius()        // prints radius to output file
		 << setw(12) << circumference()    // prints circumference to output file
		 << setw(12) << area()             // prints area to output file
		 << endl;                          // prints newline to output file
}


// function to return the name of the object
string CircleType::getName() const
{
    return name;    //returns name
}


//Function to set the radius.
//Postcondition: if (r >= 0) radius = r;
// otherwise radius = 1;
void CircleType::setRadius(double r)
{
    if (r >= 0)                             // if/else statement to check if radius is positive
        radius = r;                         // sets radius to value of r
    else                                    //else
        radius = 1;                         // sets the radius to 1
}
