//
//  fVideoView.h
//  ofxFargo
//
//  Created by Matt Fargo on 2013/03/03.
//
//

#ifndef __ofxFargo__fVideoView__
#define __ofxFargo__fVideoView__

#include "fSprite.h"
#include "fSpriteEvent.h"

class fVideoView : public fSprite {
public:
    fVideoView();
    fVideoView(string url, bool autoStart=true, bool hasAlpha=false, ofLoopType loopType=OF_LOOP_NORMAL);
    virtual ~fVideoView();
    
    ofEvent<fSpriteEvent>    VIDEO_COMPLETE;
    ofVideoPlayer   player;
    
    void    load(string url, bool autoStart=true, bool hasAlpha=false, ofLoopType loopType=OF_LOOP_NORMAL);
    void    replay();
    void    play();
    void    stop();

    
protected:
    virtual void    onUpdate();
    virtual void    onDraw();

};

#endif /* defined(__ofxFargo__fVideoView__) */
