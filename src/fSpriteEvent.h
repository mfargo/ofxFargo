//
//  fTouchEvent.h
//  kazuControl
//
//  Created by Matthew Fargo on 2015/04/08.
//
//

#ifndef __ofxFargo__fSpriteEvent__
#define __ofxFargo__fSpriteEvent__

#include "ofMain.h"
class fSprite;



class fSpriteEvent : public ofEventArgs {
public:
    fSpriteEvent(fSprite * target, ofVec3f velocity=ofVec3f()) {
        _target = target;
        _velocity = velocity;
    }
    
    fSprite *   getTarget() { return _target; }
    ofVec3f     getVelocity() { return _velocity; }

private:
    
    fSprite *   _target;
    ofVec3f     _velocity;
    
};

#endif /* defined(__ofxFargo__fSpriteEvent__) */
