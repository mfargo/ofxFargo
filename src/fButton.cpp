//
//  fButton.cpp
//  kazuControl
//
//  Created by Matthew Fargo on 2015/04/03.
//
//

#include "fButton.h"

fButton::fButton(ofColor backgroundColor, float cornerRadius) {
    _backgroundColor = backgroundColor;
    _cornerRadius = cornerRadius;
    _outlineColor = ofColor(0,0,0);
    size = ofVec2f(16, 16);
    hasOutline = false;
}
fButton::~fButton() {}

void fButton::onDown() {
    opacity = 0.5;
}
void fButton::onUp(float totalDrag) {
    opacity = 1;
}


void fButton::onDraw() {
    ofSetColor(_backgroundColor, getCollectiveOpacity()*255.f);
    ofDrawRectRounded(0, 0, size.x, size.y, _cornerRadius);
    if (hasOutline) {
        ofNoFill();
        ofSetColor(_outlineColor);
        ofDrawRectRounded(0, 0, size.x, size.y, _cornerRadius);
        ofFill();
    }
}
