//
//  fTextField.cpp
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/02/20.
//
//

#include "fTextField.h"

fTextField::fTextField(string text, int fontSize, string fontUrl, float maxWidth) {
    _font = ofxFontStash();
    _font.setup(fontUrl, 1.0, 1024, false, 8, 1.5);
    _font.setCharacterSpacing(0);
    _fontSize = fontSize;
    _maxWidth = maxWidth;
    _lineHeight = fontSize * 0.3f;
    touchEnabled = false;
    setText(text);
    textAlign = F_ALIGN_LEFT;

}
fTextField::fTextField(string text, ofxFontStash * font) {
    _font = *font;
    _fontSize = _font.getSize();
    setText(text);
    textAlign = F_ALIGN_LEFT;
}
fTextField::~fTextField() {}

void fTextField::onUpdate() {}

void fTextField::onDraw() {
    if (_text=="") {
        //printf(" \n ** fTextField-> EMPTY TEXT!\n");
        return;
    }
    ofPushMatrix(); {
        int numLines = 0;
        bool isCentered = (textAlign==F_ALIGN_CENTER);
        
        float x = (isCentered) ? 0.f : (textAlign==F_ALIGN_RIGHT) ? -size.x : size.x/2.f;

        ofTranslate(-_textBounds.x + x, -_textBounds.y);
        
        
        bool wasCropped;
        ofSetColor(textColor);
        _textBounds = _font.drawMultiLineColumn(_text, _fontSize, 0, 0, _maxWidth, numLines);
        //_textBounds = _font.drawMultiLineColumn(_text, _fontSize, 0, 0, _maxWidth, numLines, true, 2, false, &wasCropped, isCentered);
        size = ofVec2f(_textBounds.width, _textBounds.height);
    } ofPopMatrix();
}

void fTextField::setText(string text)  {
    _text = text;
    int numLines = 0;
    _textBounds = _font.drawMultiLineColumn(_text, _fontSize, 0, 0, _maxWidth, numLines);
    size = ofVec2f(_textBounds.width, _textBounds.height);
}


