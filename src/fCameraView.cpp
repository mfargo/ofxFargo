//
//  fCameraView.cpp
//  kazuExample
//
//  Created by Matthew Fargo on 2015/04/28.
//
//

#include "fCameraView.h"

fCameraView::fCameraView(float width, float height, int deviceID) {
    if (deviceID>-1) camera.setDeviceID(deviceID);
    camera.initGrabber(width, height);
    size = ofVec2f(width, height);
}
fCameraView::~fCameraView() {}


void fCameraView::onUpdate() {
    camera.update();
}

void fCameraView::onDraw() {
    camera.draw(0, 0);
}