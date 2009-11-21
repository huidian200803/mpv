/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2003 Robert Osfield 
 *
 * This library is open source and may be redistributed and/or modified under  
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * OpenSceneGraph Public License for more details.
*/
//osgParticle - Copyright (C) 2002 Marco Jez

#ifndef OSGPARTICLE_COUNTER_
#define OSGPARTICLE_COUNTER_ 1

#include <osg/CopyOp>
#include <osg/Object>

#include "Export.h"

namespace osgParticleHPS
{

    class OSGPARTICLE_EXPORT Counter: public osg::Object {
    public:
        inline Counter();
        inline Counter(const Counter &copy, const osg::CopyOp &copyop = osg::CopyOp::SHALLOW_COPY);

        virtual const char *libraryName() const { return "osgParticleHPS"; }
        virtual const char *className() const { return "Counter"; }
        virtual bool isSameKindAs(const osg::Object *obj) const { return dynamic_cast<const Counter *>(obj) != 0; }

        virtual int numParticlesToCreate(double dt) const = 0;

    protected:
        ~Counter() {}
        Counter &operator=(const Counter &) { return *this; }
    };
    
    // INLINE FUNCTIONS
    
    inline Counter::Counter()
    : osg::Object()
    {
    }
    
    inline Counter::Counter(const Counter &copy, const osg::CopyOp &copyop)
    : osg::Object(copy, copyop)
    {
    }

}

#endif
