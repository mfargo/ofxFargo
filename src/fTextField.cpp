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
    _dropShadow = false;
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
    if (_dropShadow) {
        ofSetColor(0, 0, 0, collectiveOpacity*140.f);
        ofPushMatrix();
        ofTranslate(-2, 2);
        drawLines();
        ofPopMatrix();
    }
    ofSetColor(textColor, collectiveOpacity*255.f);
    drawLines();
}

void fTextField::drawLines() {
    float y = 0;
    _fbo.draw(0, 0);
}

void fTextField::setText(string text)  {
    if (!_fbo.isAllocated()) {
        _fbo.allocate(ofGetWidth(), ofGetHeight());
    }
    int numLines = 0;
    _text = text;
    ofRectangle r = _font.drawMultiLineColumn(_text, _fontSize, 0, 0, _maxWidth, numLines);

    size = ofVec2f(r.width, r.height);
    _fbo.begin();
    ofClear(255,255,255, 0);
    ofSetColor(255, 255, 255);
    ofSetColor(textColor);
    _font.drawMultiLineColumn(_text, _fontSize, size.y/2.f, size.y/2.f+_fontSize, _maxWidth, numLines);
    _fbo.end();
}


