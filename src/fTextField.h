//
//  fTextField.h
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/02/20.
//
//

#ifndef __ofxFargo__fTextField__
#define __ofxFargo__fTextField__

#include "fSprite.h"
#include "ofxFontStash.h"

typedef enum {
    F_ALIGN_LEFT,
    F_ALIGN_CENTER,
    F_ALIGN_RIGHT
} fTextFieldTextAlign;



class fTextField : public fSprite {
public:
    fTextField(string text, int fontSize, string fontUrl, float maxWidth=0.f);
    fTextField(string text, ofxFontStash * font);
    virtual ~fTextField();
    
    ofColor             textColor;
    fTextFieldTextAlign textAlign;

    virtual void        onDraw();
    virtual void        onUpdate();
    
    void                setText(string text);
    string              getText() { return _text; }
    void                setMaxWidth(float maxWidth);
    float               getMaxWidth() { return _maxWidth; }
    void                setLineHeight(float lineHeight) { _lineHeight = lineHeight; }
    float               getLineHeight() { return _lineHeight; }
    float               getFontSize() { return _fontSize; }

protected:

private:
    
    
    ofxFontStash        _font;
    string              _text;
    float               _fontSize;
    float               _maxWidth;
    float               _lineHeight;
    ofRectangle         _textBounds;

};

#endif /* defined(__ofxFargo__fTextField__) */
