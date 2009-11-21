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
 *  FILENAME:   DefTreeHandler.h
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Multi-Purpose Viewer
 *  
 *  PROGRAM DESCRIPTION: 
 *  This class responds to http client requests; it inherits from EHS and 
 *  overrides the HandleRequest method.  The class can report on entity status, 
 *  and can handle some http-form requests.
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  01/19/2005 Andrew Sampson                       MPV_CR_DR_1
 *  Initial Release.
 * </pre>
 *  The Boeing Company
 *  1.0
 */


#ifndef DEFTREEHANDLER_H
#define DEFTREEHANDLER_H

#include <list>
#include <string>
#include <sstream>

#include <EHS.h>

#include "DefFileGroup.h"

class DefTreeHandler : public EHS
{
public:
	DefTreeHandler();
	
	virtual ResponseCode HandleRequest( HttpRequest * ipoHttpRequest,
										 HttpResponse * ipoHttpResponse );
	
	void setDefTree(DefFileGroup **);

protected:

	ResponseCode sendExternalFile( 
		HttpResponse * ipoHttpResponse, const std::string &filename );
	ResponseCode sendHTMLPage( HttpResponse * ipoHttpResponse );
	ResponseCode sendErrorFileNotFound( 
		HttpResponse * ipoHttpResponse, const std::string &filename );
	void recurseThroughDefTree( 
		int myID, DefFileGroup *myGroup, std::ostringstream &oss );

	DefFileGroup **defTree;
	int jsVariableNameCounter;
};


#endif

