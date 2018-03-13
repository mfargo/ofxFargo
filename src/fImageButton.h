//
//  fImageButton.h
//  ofxFargo
//
//  Created by Matthew Fargo on 2018/03/07.
//

#ifndef fImageButton_h
#define fImageButton_h

#include "fButton.h"

class fImageButton : public fButton {
public:
    fImageButton(string url);
    virtual ~fImageButton();
    
    void            setUrl(string url);
    string          getUrl();
    ofImage         image;
    ofColor         tint = ofColor(255);
    
protected:
    virtual void    onDraw();

private:
    void            _load(string url);
    string          _url;

};

#endif /* fImageButton_h */
