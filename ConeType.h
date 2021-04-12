// ConeType.h  Class specifications header file for the derived class ConeType
#ifndef H_ConeType
#define H_ConeType

class ConeType : public CircleType
{
    public:
        ConeType(double rad = 1.0, double heit = 1.0);
          //Constructor with two default parameters.  Client assigned.
          //Postcondition: if parameters are given:  radius = rad, height = heit
          //       without parameters:   radius = 1.0    height = 1.0
          //       name is assigned "Cone"

        ~ConeType();
          //Destructor destroys cone objects [and returns memory to the heap]

        string getName() const;
          //overrides base class & gets the name of the cone    ** override **

        double area() const;
          //Function to return the surface area of a cone
          //Overrides the circle's area function                  ** override **
          //Postcondition: Surface area is calculated and returned.

        void print(ostream& ) const;
          // function to override circle's print                  ** override **
          // displays the radius, height, surface area, and volume

        double volume() const;
          //Function to return the volume of a cone
          //Postcondition: Volume is calculated and returned.

        double getHeight() const;
          // Function to return the height of a cone (really the same as diameter)
          // Postcondition:  height (diameter) is calculated and returned

        double getSlantHeight() const;
          // Function to return the slant height of a cone (based on pythag. theorem)
          // Postcondition:  slant height is calculated and returned

        void setHeight(double);
          // sets the height (diameter) of a cone
          // by setting the circle’s radius to half the cone’s height

    protected:
        double height;
        string name;
};
#endif
