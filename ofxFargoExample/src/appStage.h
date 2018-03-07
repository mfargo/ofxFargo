#pragma once

#include "ofxFargo.h"

class appStage : public fAppStage {
public:
    void setup();
    
protected:
    void onUpdate();
    void onDraw();
    
    void onKeyPressed(int key);
};
