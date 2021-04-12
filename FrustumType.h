// Frustum.h  Class specifications header file for the derived class Frustum
// (extra credit for implementing these Frustum of a right circular cone functions)
#ifndef H_Frustum
#define H_Frustum

class FrustumType : public ConeType
{
    public:
        FrustumType(double radR = 1.0, double heit = 0.5, double radr = 0.5);
          //Constructor with two default parameters.  Client assigned.
          //Postcondition: if parameters are given:  radius = rad, height = heit
          //       without parameters:   radius R = 1.0    height = 1.0
          //       name is assigned "Frustum"

        ~FrustumType();
          //Destructor destroys cone objects [and returns memory to the heap]

        string getName() const;
          //overrides base cone class & gets the name of the frustum    ** override **

        double area() const;
          //Function to return the surface area of a frustum
          //Overrides the cone's area function                          ** override **
          //Postcondition: Surface area is calculated and returned.

        void print(ostream& ) const;
          // function to override cone's print                          ** override **
          // displays the radius, height, surface area, and volume

        double volume() const;
          //Function to return the volume of a cone                     ** override **
          //Postcondition: Volume is calculated and returned.

        double getHeight() const;
          // Function to return the height of a frustum                 ** override **
          // Postcondition:  height (diameter) is calculated and returned

        double getSlantHeight() const;
          // Function to return the slant height of the frustum (based on pythag. theorem)
          // Postcondition:  slant height is calculated and returned    ** override **

        void setHeight(double);
          // sets the height of a frustum                               ** override **

    private:
        double rSmaller;    // minor (smaller radius of frustum)
        string name;        // object name Frustum
};
#endif
