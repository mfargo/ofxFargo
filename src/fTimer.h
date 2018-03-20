//
//  fTimer.h
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/05/26.
//
//

#ifndef __ofxFargo__fTimer__
#define __ofxFargo__fTimer__

#include "ofMain.h"

class fTimer;
class fTimerEvent : public ofEventArgs {
    
public:
    fTimerEvent(fTimer * timer) {
        _timer = timer;
    }
    virtual ~fTimerEvent() {}

    fTimer *    getTimer() { return _timer; }
private:
    fTimer *    _timer;
};

class fTimer {
public:
    fTimer();
	fTimer(float seconds, bool autoStart=false);
    virtual ~fTimer();

    ofEvent<fTimerEvent> TIMER_COMPLETE;
    
    void    start();
    void    stop();
    void    restart();
    bool    isRunning() { return _isRunning; }
    void    setSeconds(float seconds) { _millis = seconds * 1000.f; }
    float   getSeconds() { return _millis/1000.f; }
    float   getProgress() { return ofClamp(((float)ofGetElapsedTimeMillis() - _startMillis)/_millis, 0, 1); }

private:
    
    void    _update(ofEventArgs & e);
    void    _complete();
    float   _startMillis;
    float   _millis;
    bool    _isRunning;

};

#endif /* defined(__ofxFargo__fTimer__) */
