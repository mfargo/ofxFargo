//
//  fTimer.cpp
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/05/26.
//
//

#include "fTimer.h"

fTimer::fTimer() {
    _millis = 0.f;
    _isRunning = false;
}
fTimer::fTimer(float seconds, bool autoStart) {
    _millis = seconds*1000;
    _isRunning = false;
    if (autoStart) start();
}
fTimer::~fTimer() {}


void fTimer::_update(ofEventArgs & e) {
    //printf(" TIMER UPDATE\n");
    if (!_isRunning) stop();
    if (ofGetElapsedTimeMillis() >= _startMillis + _millis) _complete();
}
        
void fTimer::_complete() {
    stop();
    fTimerEvent event = fTimerEvent(this);
    ofNotifyEvent(this->TIMER_COMPLETE, event);
}

void fTimer::start() {
    if (_isRunning) return;
    _isRunning = true;
    _startMillis = ofGetElapsedTimeMillis();
    ofAddListener(ofEvents().update, this, &fTimer::_update);
}

void fTimer::stop() {
    _isRunning = false;
    ofRemoveListener(ofEvents().update, this, &fTimer::_update);
}

void fTimer::restart() {
    stop();
    start();
}
