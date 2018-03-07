#include "appStage.h"

void appStage::setup(){
    addChild(new fImage("images/wes.jpg"));
    addChild(new fVideoView("movies/hella_handsome.mp4"))->position = ofVec2f(300, 0);
    addChild(new fImage("images/val.jpg"))->position = ofVec2f(600, 0);
}

void appStage::onUpdate() {
    
}

void appStage::onDraw() {
    
}

void appStage::onKeyPressed(int key) {
    
}
