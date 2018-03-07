//
//  fVideoView.cpp
//  ofxFargo
//
//  Created by Matt Fargo on 2013/03/03.
//
//

#include "fVideoView.h"

fVideoView::fVideoView() {}
fVideoView::fVideoView(string url, bool autoStart, bool hasAlpha, ofLoopType loopType) {
    load(url, autoStart, hasAlpha, loopType);
}
fVideoView::~fVideoView() {}

void fVideoView::load(string url, bool autoStart, bool hasAlpha, ofLoopType loopType) {
    if (player.isLoaded()) player.close();
    if (hasAlpha) player.setPixelFormat(OF_PIXELS_RGBA);
    player.load(url);
    player.setLoopState(loopType);
    if (autoStart) player.play();
    this->size = ofVec2f(player.getWidth(), player.getHeight());
}

void fVideoView::replay() {
    player.setFrame(0);
    play();
}
void fVideoView::play() {
    player.play();
}

void fVideoView::stop() {
    player.stop();
}

void fVideoView::onUpdate() {
    if (!player.isLoaded()) return;
    player.update();
    if (player.getIsMovieDone()) {
        fSpriteEvent e = fSpriteEvent(this);
        ofNotifyEvent(this->VIDEO_COMPLETE, e);
    }
}

void fVideoView::onDraw() {
    if (!player.isLoaded()) return;
    player.draw(0, 0);
}

