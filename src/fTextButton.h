//
//  fTextButton.h
//  ofxFargo
//
//  Created by Matthew Fargo on 2015/04/03.
//
//

#ifndef __ofxFargo__fTextButton__
#define __ofxFargo__fTextButton__

#include "fButton.h"
#include "fTextField.h"

class fTextButton : public fButton {
public:

    fTextButton(string text, ofxFontStash * font, ofColor textColor = ofColor(0), ofColor backgroundColor=ofColor(255), ofVec4f padding=ofVec4f(4, 4, 4, 4));
    virtual ~fTextButton();

    fTextField *    getTextField() { return _textField; }
    
protected:
    virtual void    onDown();
    virtual void    onUp(float totalDrag);
    void            onDraw();
    
    fTextField *    _textField;
    ofVec4f         _padding;
};

#endif /* defined(__ofxFargo__fTextButton__) */
