//Implementation File for the class FrustumType
// FrustumType.cpp

#include "FrustumType.h"


//Constructor with two default parameters.  Client assigned.
//Postcondition: if parameters are given:  radius = rad, height = heit
//       without parameters:   radius R = 1.0    height = 1.0
FrustumType::FrustumType(double radR, double heit, double radr)
        :ConeType (heit)                  //initalizes r
{
    radius = radR;                        // assign the radR to radius
    rSmaller = radr;                      // assigns radr to rSmaller
    height = heit;                        // assigns heit to height
    name = "Frustum";                     // assign the name of the circle
}


//Destructor destroys cone objects [and returns memory to the heap]
FrustumType::~FrustumType()
{
    //cout << "Frustum destructor called" << endl;  // outputs destructor to console
}


//Function to return the surface area of a frustum
//Overrides the cone's area function                          ** override **
//Postcondition: Surface area is calculated and returned.
double FrustumType::area() const
{
    double partOne = M_PI*(radius+rSmaller);    // gets PI * radius * rSmaller and assigns it to partOne
    double partTwo = getSlantHeight();          // gets slant height and assigns it to partTwo
    double partThree = M_PI*pow(rSmaller,2);    // gets PI * rSmaller^2 and assigns it to partThree
    double partFour = M_PI*pow(radius,2);       // gets PI * radius^2 and assigns it to partFour
    double fArea = partOne*partTwo+partThree+partFour; // puts all of the peices of the equation together to get frustum area and assigns it to fArea
    return fArea;                               // returns fArea
}


//Function to return the volume of a cone                     ** override **
//Postcondition: Volume is calculated and returned.
double FrustumType::volume() const
{
    double one = pow(radius, 2);            // gets radius^2 and assigns it to one
    double two = pow(rSmaller, 2);          // gets rSmaller^2 and assigns it to two
    double three = radius * rSmaller;       // gets radius * rSmaller and assigns it to three
    double four = (M_PI / 3.0) * height;    // gets PI/3.0 * height and assigns it to four
    return four*(one + two + three);        // puts all pieces of equation together and returns it because this equation equals the volume of a frustum
}


// function to override cone's print                          ** override **
// displays the radius, height, surface area, and volume
void FrustumType::print(ostream& outF) const // print function for the object one line
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


// Function to return the height of a frustum                 ** override **
double FrustumType::getHeight() const
{
    return height;      // returns height
}


// Function to return the slant height of the frustum (based on pythag. theorem)
// Postcondition:  slant height is calculated and returned    ** override **
double FrustumType::getSlantHeight() const
{
    double cSqrd = pow(radius-rSmaller,2) + pow(height,2);  // gets a^2 + b^2 and assigns it to cSqrd
    return sqrt(cSqrd);     // returns sqrt of cSqrd
}


//overrides base cone class & gets the name of the frustum    ** override **
string FrustumType::getName() const
{
    return name;        // returns name
}


// sets the height of a frustum                               ** override **
void FrustumType::setHeight(double h)
{
   height = h;      // assigns h to height
}
