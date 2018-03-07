//
//  fTextButton.cpp
//  kazuControl
//
//  Created by Matthew Fargo on 2015/04/03.
//
//

#include "fTextButton.h"


fTextButton::fTextButton(string text, ofxFontStash * font, ofColor textColor, ofColor backgroundColor, ofVec4f padding) : fButton(backgroundColor) {
    _textField = new fTextField(text, font);
    _textField->textColor = textColor;
    _padding = padding;
    size = _textField->size;
    size.x += _padding.y + _padding.w;
    size.y += _padding.x + _padding.z;
    addChild(_textField)->enabled = false;
    _textField->position = ofVec2f(size.x/2.f, size.y/2.f);
}
fTextButton::~fTextButton() {
    delete _textField;
}
void fTextButton::onDown() {
    fButton::onDown();
    ofColor c = _textField->textColor;
    _textField->textColor = _backgroundColor;
    _backgroundColor = c;
}
void fTextButton::onUp() {
    fButton::onUp();
    ofColor c = _textField->textColor;
    _textField->textColor = _backgroundColor;
    _backgroundColor = c;
}
void fTextButton::onDraw() {
    fButton::onDraw();
}
