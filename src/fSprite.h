//
//  fSprite.h
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/02/15.
//
//

#ifndef __ofxFargo__fSprite__
#define __ofxFargo__fSprite__

#include "fSpriteContainer.h"
#include "fSpriteEvent.h"

class fSprite : public fSpriteContainer {
public:
    
    fSprite();
    virtual ~fSprite();
    
    virtual void    update();
    virtual void    draw();
    
    virtual fSprite *   addChild(fSprite * child);
    virtual fSprite *processTouchDown(int touchID, const ofVec2f &globalPoint);
    virtual void    processTouchMove(int touchID, const ofVec2f &globalPoint);
    virtual void    processTouchUp(int touchID, const ofVec2f &globalPoint);
    
    virtual bool    containsPoint(const ofVec2f &point);
    virtual bool    containsLocalPoint(const ofVec2f &point);
    
    float           getWidth() { return size.x; }
	float           getHeight() { return size.y; }
    float           getCollectiveOpacity() { return collectiveOpacity; }
    
    
	ofVec2f         size;
	ofVec3f         position;
	ofVec3f         rotation;
	float           opacity;
	float           scale;
	float           touchPadding;
    bool            draggable;
	fSprite *       parent;
    ofVec3f         globalToLocal(const ofVec3f &globalPoint);
	ofVec3f         localToGlobal(const ofVec3f &localPoint);
    ofVec2f         scaledSize();
    
    // Animations
    void            animatePosition(ofVec3f point, float time, float delay=0.f, int easeType=5, bool notifyCompletion=true);
    void            animateScale(float scale, float time, float delay=0.f, int easeType=5, bool notifyCompletion=true);
    void            animateRotation(ofVec3f rotation, float time, float delay=0.f, int easeType=5, bool notifyCompletion=true);
    void            stopPositionAnimation();
    void            stopScaleAnimation();
    void            stopRotationAnimation();
    void            stopAllAnimations();
    
    ofEvent<fSpriteEvent>    ANIMATION_POSITION_COMPLETE;
    ofEvent<fSpriteEvent>    ANIMATION_ROTATION_COMPLETE;
    ofEvent<fSpriteEvent>    ANIMATION_SCALE_COMPLETE;


protected:
    
    virtual void onDown() {}
    virtual void onMove(ofVec2f velocity) {}
    virtual void onUp(float totalDrag) {}
        
    float           collectiveOpacity;
    
    bool            dragging;
    float           totalDrag;
    ofVec2f         touchVelocity;
    ofVec2f         touchPoint;
    ofVec2f         globalTouchPoint;
    
    
private:
    void            onPositionAnimationComplete(float *arg);
    void            onRotationAnimationComplete(float *arg);
    void            onScaleAnimationComplete(float *arg);

};

#endif /* defined(__ofxFargo__fSprite__) */
