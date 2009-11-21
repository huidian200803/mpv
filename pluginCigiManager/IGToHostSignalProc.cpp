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
 *  FILENAME:   IGToHostSignalProc.h
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Multi-Purpose Viewer
 *  
 *  PROGRAM DESCRIPTION: 
 *  This class contains the data and methods necessary to
 *  
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  07/28/2004 Andrew Sampson                       MPV_CR_DR_1
 *  Initial Release.
 * </pre>
 *  The Boeing Company
 *  1.0
 */


#include <iostream>

#include "IGToHostSignalProc.h"


// ================================================
// IGToHostSignalProc
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
IGToHostSignalProc::IGToHostSignalProc()
{
	OmsgPtr = NULL;
	sendNetMessagesCB = NULL;
	isMaster = true;
}

// ================================================
// ~IGToHostSignalProc
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
IGToHostSignalProc::~IGToHostSignalProc()
{

}


// ================================================
// OnAnyIGToHost
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void IGToHostSignalProc::OnAnyIGToHost(CigiBasePacket *Packet)
{
	if( !OmsgPtr )
		return;
	
	// filter out start-of-frame packets
	if( Packet->GetPacketID() == CIGI_SOF_PACKET_ID_V3 )
	{
		// if this is the "master" or "blessed" IG channel, call sendNetMessages now
		if( isMaster )
		{
			if( sendNetMessagesCB )
				sendNetMessagesCB();
		}
		// ... otherwise ignore this SOF
	}
	else
	{
		(*OmsgPtr) << *Packet;
	}
	
}

