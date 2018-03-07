//
//  fCameraView.h
//  kazuExample
//
//  Created by Matthew Fargo on 2015/04/28.
//
//

#ifndef __kazuExample__fCameraView__
#define __kazuExample__fCameraView__

#include "ofxFargo.h"

class fCameraView : public fSprite {
public:
    fCameraView(float width, float height, int deviceID = -1);
    virtual ~fCameraView();
    
    ofVideoGrabber  camera;
    
    
protected:
    void    onUpdate();
    void    onDraw();
    
};

#endif /* defined(__kazuExample__fCameraView__) */
