//
//  fAppStage.cpp
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/03/03.
//
//

#include "fAppStage.h"
#include "ofxTweenzor.h"

fAppStage::fAppStage() {
    ofAddListener(ofEvents().exit, this, &fAppStage::_exit);
    Tweenzor::init();
}
fAppStage::~fAppStage() {}

void fAppStage::_exit(ofEventArgs &e) {
    onExit();
}

ofVec2f fAppStage::stageSize() {
    return ofVec2f(ofGetWidth(), ofGetHeight());
}

void fAppStage::update() {
    Tweenzor::update( ofGetElapsedTimeMillis() );
    onUpdate();
    for (auto iter = children.begin(); iter != children.end(); ++iter) (*iter)->update();
    onUpdateComplete();
}

void fAppStage::draw() {
    ofEnableAlphaBlending();
    onDraw();
    for (auto iter = children.begin(); iter != children.end(); ++iter) (*iter)->draw();
    onDrawComplete();
}

void fAppStage::keyPressed(int key) {
    if (key=='f') ofToggleFullscreen();
    if (key=='m') ofShowCursor();
    
    onKeyPressed(key);
}


void fAppStage::mouseDragged(int x, int y, int button) {
    map<int, pInteraction *>::iterator it = _interactions.find(0);
    if(it != _interactions.end())
        it->second->getSprite()->processTouchMove(0, ofVec2f(x, y));
}
void fAppStage::mousePressed(int x, int y, int button) {
    if (button != 0) return; //
    for (auto iter = children.rbegin(); iter != children.rend(); ++iter) {
        fSprite * sprite = (*iter)->processTouchDown(0, ofVec2f(x, y));
        if (sprite!= NULL) {
            _interactions[0] = new pInteraction(0, sprite);
            break;
        }
    }

}
void fAppStage::mouseReleased(int x, int y, int button) {
    map<int, pInteraction *>::iterator it = _interactions.find(0);
    if(it != _interactions.end()) {
        _interactions[0]->getSprite()->processTouchUp(0, ofVec2f(x, y));
        _interactions.erase(it);
    }
}
