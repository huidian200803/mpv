/** <pre>
 *  The Multi-Purpose Viewer
 *  Copyright (c) 2004 The Boeing Company
 *  
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *  
 *  
 *  FILENAME:   Vect4.h
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Multi-Purpose Viewer
 *  
 *  PROGRAM DESCRIPTION: 
 *  A class to manage and manipulate 3D homogeneous vectors.
 *  This is not a true 4 element vector.
 *  The 4th element is a scaling factor not a true element.
 *
 *  General Usage:
 *
 *  1a.  Create a new object using Vect4 and
 *         then call the Set method with the x, y, z, and w values.
 *  Or
 *  1b.  Create a new object using Vect4 with the x, y, z, and w values.
 *
 *  Then
 *  2.   Call other methods as needed.
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  04/21/2005 Greg Basler                       MPV_CR_DR_1
 *  Initial Release.
 *  
 *  2008-08-30 Andrew Sampson
 *      Renamed class to Vect4.  Moved class to the mpv namespace.  Modified 
 *      class to use an array to store the vector elements, instead of 
 *      individual member variables.
 *  
 * </pre>
 *  The Boeing Company
 *  1.0
 */

#include <math.h>

#include "Vect4.h"


using namespace mpv;

// ================================================
// Vect4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4::Vect4()
{
	vect[0] = 0.0;
	vect[1] = 0.0;
	vect[2] = 0.0;
	vect[3] = 0.0;
}


// ================================================
// Vect4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4::Vect4(double x_in, double y_in, double z_in, double w_in)
{
	vect[0] = x_in;
	vect[1] = y_in;
	vect[2] = z_in;
	vect[3] = w_in;
}


// ================================================
// ~Vect4
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4::~Vect4()
{

}


// ================================================
// Set
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void Vect4::Set(double x_in, double y_in, double z_in, double w_in)
{
	vect[0] = x_in;
	vect[1] = y_in;
	vect[2] = z_in;
	vect[3] = w_in;
}


// ================================================
// mag
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
double Vect4::mag() const
{
	return sqrt( vect[0]*vect[0] + vect[1]*vect[1] + vect[2]*vect[2] );
}


// ================================================
// mag2
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
double Vect4::mag2() const
{
	return( vect[0]*vect[0] + vect[1]*vect[1] + vect[2]*vect[2] );
}


// ================================================
// operator *(const double k)
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4 Vect4::operator *(const double k) const
{

   double rx,ry,rz;

   rx = vect[0] * k;
   ry = vect[1] * k;
   rz = vect[2] * k;

   return(Vect4(rx,ry,rz,vect[3]));

}


// ================================================
// operator /(const double k)
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4 Vect4::operator /(const double k) const
{

   double rx,ry,rz;

   rx = vect[0] / k;
   ry = vect[1] / k;
   rz = vect[2] / k;

   return(Vect4(rx,ry,rz,vect[3]));

}


// ================================================
// operator +(const Vect4 &v)
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4 Vect4::operator +(const Vect4 &v) const
{

   double rx,ry,rz;

   rx = vect[0] + v.vect[0];
   ry = vect[1] + v.vect[1];
   rz = vect[2] + v.vect[2];

   return(Vect4(rx,ry,rz,1.0));

}


// ================================================
// operator -(const Vect4 &v)
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4 Vect4::operator -(const Vect4 &v) const
{

   double rx,ry,rz;

   rx = vect[0] - v.vect[0];
   ry = vect[1] - v.vect[1];
   rz = vect[2] - v.vect[2];

   return(Vect4(rx,ry,rz,1.0));

}


// ================================================
// operator ^(const Vect4 &v)
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4 Vect4::operator ^(const Vect4 &v) const
{

   double rx,ry,rz;

   rx = vect[1]*v.vect[2] - vect[2]*v.vect[1];
   ry = vect[2]*v.vect[0] - vect[0]*v.vect[2];
   rz = vect[0]*v.vect[1] - vect[1]*v.vect[0];

   return(Vect4(rx,ry,rz,1.0));

}


// ================================================
// operator *(const Vect4 &v)
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
double Vect4::operator *(const Vect4 &v) const
{

   return(vect[0]*v.vect[0] + vect[1]*v.vect[1] + vect[2]*v.vect[2]);

}


// ================================================
// angle
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
double Vect4::angle(Vect4 &v) const
{
   return((double)acos((*this*v)/(mag()*v.mag())));
}


// ================================================
// angleD
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
double Vect4::angleD(Vect4 &v) const
{
   return(((double)acos((*this*v)/(mag()*v.mag())))*(180.0f/3.1415926f));
}


// ================================================
// Unit
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4 Vect4::Unit() const
{

   double rx,ry,rz,mg;

   mg = mag();
   if( mg != 0 )
   {
      rx = vect[0] / mg;
      ry = vect[1] / mg;
      rz = vect[2] / mg;
   }
   else
      rx = ry = rz = 0.0;

   return(Vect4(rx,ry,rz,1.0));

}


// ================================================
// Rotate
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4 Vect4::Rotate(Vect4 &N, double angle) const
{

   double C;  // cosine angle
   double S;  // sin angle

   double Mtx[3][3];  // rotation matrix[row][column]
   double R[3];       // result vector

   int rdx;  // Running row and result vector element index
   int cdx;  // Running column and source vector element index

   C = cos(angle);
   S = sin(angle);

   // Standard rotation matrix
   Mtx[0][0] = C + N.vect[0]*N.vect[0]*(1-C);
   Mtx[0][1] = N.vect[0]*N.vect[1]*(1-C) - N.vect[2]*S;
   Mtx[0][2] = N.vect[0]*N.vect[2]*(1-C) + N.vect[1]*S;

   Mtx[1][0] = N.vect[0]*N.vect[1]*(1-C) + N.vect[2]*S;
   Mtx[1][1] = C + N.vect[1]*N.vect[1]*(1-C);
   Mtx[1][2] = N.vect[1]*N.vect[2]*(1-C) - N.vect[0]*S;

   Mtx[2][0] = N.vect[0]*N.vect[2]*(1-C) - N.vect[1]*S;
   Mtx[2][1] = N.vect[1]*N.vect[2]*(1-C) + N.vect[0]*S;
   Mtx[2][2] = C + N.vect[2]*N.vect[2]*(1-C);


   // Multiply the current vector and the transformation matrix
   for(rdx=0;rdx<3;rdx++)
   {
      R[rdx] = 0;
      for(cdx=0;cdx<3;cdx++)
      {
         R[rdx] += vect[cdx]*Mtx[rdx][cdx];
      }
   }

   return(Vect4(R[0],R[1],R[2],vect[3]));

}


// ================================================
// Neg
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
Vect4 Vect4::Neg() const
{

	return(Vect4(-vect[0],-vect[1],-vect[2],vect[3]));

}

