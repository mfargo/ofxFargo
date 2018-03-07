//
//  fButton.h
//  ofxFargo
//
//  Created by Matthew Fargo on 2015/04/03.
//
//

#ifndef __ofxFargo__fButton__
#define __ofxFargo__fButton__

#include "fSprite.h"
#include "fSpriteEvent.h"

typedef enum {
    FBUTTON_DOWN,
    FBUTTON_UP
} fButtonState;

class fButton : public fSprite {
public:
    fButton(ofColor backgroundColor=ofColor(), float cornerRadius = 8);
    virtual ~fButton();

    ofEvent<fSpriteEvent>    BUTTON_DOWN;
    ofEvent<fSpriteEvent>    BUTTON_UP;

    fButtonState    getState() { return _state; }
    ofColor &       getBackgroundColor() { return _backgroundColor; }
    ofColor         setOutlineColor(ofColor c) { _outlineColor = c; }
    ofColor &       getOutlineColor() { return _outlineColor; }
    
    bool            hasOutline;
    
protected:
    virtual void    onDown();
    virtual void    onUp();
    virtual void    onDraw();
    
    fButtonState    _state;
    ofColor         _backgroundColor;
    ofColor         _outlineColor;
    float           _cornerRadius;
};

#endif /* defined(__ofxFargo__fButton__) */
