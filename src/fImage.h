//
//  fImage.h
//  ofxFargo
//
//  Created by Matt Fargo on 2013/03/01.
//
//

#ifndef __ofxFargo__fImage__
#define __ofxFargo__fImage__

#include "fSprite.h"

class fImage : public fSprite {
public:
    fImage(string url);
    fImage();
    virtual ~fImage();
    
    virtual void    onUpdate();
    virtual void    onDraw();
    
    void            setUrl(string url);
    string          getUrl();
    ofImage         image;
    ofColor         tint = ofColor(255);
    
private:
    void            _load(string url);
    string          _url;

};

#endif /* defined(__ofxFargo__fImage__) */
