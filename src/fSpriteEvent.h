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
    fSpriteEvent(fSprite * target) {
        _target = target;
    }
    
    fSprite *   getTarget() { return _target; }
    
private:
    
    fSprite *   _target;
};

#endif /* defined(__ofxFargo__fSpriteEvent__) */
