/* testCCSC.cpp  (circle, cylinder, sphere, cone) (Lab2 Starter Files)
   Written by David Butler
   Date:  2/6/2019
   The user program that uses a base class CircleType
   and derives the following classes:  SphereType, SphereType, and ConeType
   implementation files to demonstrate more specific classes.
   This also demonstrates overriding the base class methods for area() & print().
*/

#include <fstream>                  //used to access input and output file abilities
#include <iostream>                 //used to output info to console
#include <iomanip>                  //used for output manipulation
#include <stdlib.h>                 //used to access system pause
#include <cmath>                    //used to access M_PI for value of pi

using namespace std;                  // namespace for standard template library

ifstream fin("ccscIn.txt");          // open the input file;
ofstream fout("ccscOut.txt");        // open the output file;

#include "CircleType.cpp"            // includes implementation files for circle
#include "CylinderType.cpp"          // includes implementation files for cylinder
#include "SphereType.cpp"             // includes implementation files for sphere
#include "ConeType.cpp"               // includes implementation files for cone
#include "FrustumType.cpp"            //includes implementation files for Frustum

void headings();                      //headings is used to print out the headings
void defaultObjects();                //defaultObjects is used to get calculations for the default objects and print them out
void fileProcess();                   //fileProcess is used to read in data from the input file and give those numbers to notDefaultObjects
void notDefaultObjects(double rad, double heit); //notDefaultObjects takes numbers from fileProcess function and calculates objects/prints them out

int main()
{
	headings();                         // display the title, name, and headings
    defaultObjects();                   // processes the default objects
	fileProcess();                      // read and process all input file data
	system("pause");                    // pauses execution when .exe file is run
	return 0;                           // returns 0 to op. system; all is well
}

// prints the headings of the output report to both the console and the printer
// prints the headings of the output report to both the console and the printer
void headings()
{
    cout << fixed << showpoint << setprecision(3);  // display only 3 digit precision fixed
    fout << fixed << showpoint << setprecision(3);  // display only 3 digit precision fixed
	cout << "C I R C L E,   C Y L I N D E R,   S P H E R E,  &  C O N E   C A L C U L A T I O N S"
         << "\n\n";
	cout << setw(53) << "by David Butler"<< "\n\n\n"; //displays name to console
	cout << setw(11) << "Object Name"               // display column headings
         << setw(12) << "Radius"                    //    "       "      "
         << setw(12) << "Circumf"                   //    "       "      "
	     << setw(12) << "Area"                      //    "       "      "
		 << setw(12) << "Height"                    //    "       "      "
		 << setw(12) << "Volume"                    //    "       "      "
		 << setw(13) << "Slant ht" << endl;         //    "       "      "
	cout << setw(11) << "-----------"               //    "       "      "
	     << setw(12) << "------"                    //    "       "      "
	     << setw(12) << "-------"                   //    "       "      "
	     << setw(12) << "----"                      //    "       "      "
		 << setw(12) << "------"                    //    "       "      "
		 << setw(12) << "------"                    //    "       "      "
         << setw(13) << "--------" << endl;         //    "       "      "

	fout << "C I R C L E,   C Y L I N D E R,   S P H E R E,  &  C O N E   C A L C U L A T I O N S"
         << "\n\n";
	fout << setw(53) << "by David Butler"<< "\n\n\n"; //prints my name to output file
	fout << setw(11) << "Object Name"               // display column headings
         << setw(12) << "Radius"                    //    "       "      "
         << setw(12) << "Circumf"                   //    "       "      "
	     << setw(12) << "Area"                      //    "       "      "
		 << setw(12) << "Height"                    //    "       "      "
		 << setw(12) << "Volume"                    //    "       "      "
		 << setw(13) << "Slant ht" << endl;         //    "       "      "
	fout << setw(11) << "-----------"               //    "       "      "
	     << setw(12) << "------"                    //    "       "      "
	     << setw(12) << "-------"                   //    "       "      "
	     << setw(12) << "----"                      //    "       "      "
		 << setw(12) << "------"                    //    "       "      "
		 << setw(12) << "------"                    //    "       "      "
         << setw(13) << "--------" << endl;         //    "       "      "
}


// process the default objects specified
void defaultObjects()
{
	CircleType cirDef;      // circle default constructor test
   	cirDef.print(fout);     // print the default circle

   	CylinderType cylDef;    // cylinder's default constructor test
   	cylDef.print(fout);     // print the default cylinder

   	SphereType sphDef;      // sphere's default constructor test
   	sphDef.print(fout);     // print the default sphere

   	ConeType conDef;        // cone's default constructor test
   	conDef.print(fout);     // print the default cone

   	FrustumType FrusDef;    // frustum's default constructor test
   	FrusDef.print(fout);    // print the frustum


    cirDef.setRadius(M_PI);  // circle's radius set to constant PI
    cirDef.print(fout);      // print circle data to console & file

    cylDef.setRadius(M_PI);  // cylinder's radius set to constant PI
    cylDef.print(fout);      // print cylinder data to console & file

    sphDef.setRadius(M_PI);  // sphere's radius set to constant PI
    sphDef.print(fout);      // print sphere data to console & file

    conDef.setRadius(M_PI);  // cone's radius set to constant PI
    conDef.print(fout);      // print cone data to console & file

    FrusDef.setRadius(M_PI);  // frustum's radius set to constant PI
    FrusDef.print(fout);      // print frustum data to console & file

    cylDef.setHeight(0.142857); // cylinder's Height set to 0.142857
    cylDef.print(fout);         // print cylinder data to console & file

    sphDef.setHeight(0.142857); // sphere's Height set to 0.142857
    sphDef.print(fout);         // print sphere data to console & file

    conDef.setHeight(0.142857); // cone's Height set to 0.142857
    conDef.print(fout);         // print cone data to console & file

    FrusDef.setHeight(0.142857); // frustum's Height set to 0.142857
    FrusDef.print(fout);         // print frustum data to console & file
}

// processes the data from the file, and closes both files
void fileProcess()
{
   	double rad;                     // declare a double for reading radius
	double heit;                    // declare a double for reading height
    fin >> rad;                     // priming read
    fin >> heit;                    //priming read

    while (!fin.eof())                  // loops until end of file, this loop reads in data and sends it to the function that holds
    {
        notDefaultObjects(rad, heit);   //calls notDefaultObjects and gives it the numbers from the input file
        fin >> rad;                     // reads in radius from input file
        fin >> heit;                    // reads in height from input file
    }
    // end of the loop

    cout << endl;         // outputs newline to console
    fout << endl;         // prints newline to file
    fin.close();          // close the input file
    fout.close();         // close the output file
}

//finds the calculations of the different objects with numbers read in from the input file and prints them out to the console and output file
void notDefaultObjects(double rad, double heit)
{
    CircleType cirDef(rad);           // circle with radius that was read in from the input file
   	cirDef.print(fout);               // prints the circle to the console and output file

   	CylinderType cylDef(rad,heit);    // cylinder with radius and height that were read in from the input file
   	cylDef.print(fout);               // prints the cylinder to the console and output file

   	SphereType sphDef(rad);           // sphere with radius that was read in from the input file
   	sphDef.print(fout);               // prints the sphere to the console and output file

   	ConeType conDef(rad,heit);        // cone with radius and height that were read in from the input file
   	conDef.print(fout);               // prints the cone to the console and output file

    FrustumType FrusDef(rad,heit,2.5);// frustum with radius and height that were read in from the input file and a small radius set to 2.5
   	FrusDef.print(fout);              // prints the frustum to the console and output file
}
