//
//  fTouchStage.h
//  Writeboard
//
//  Created by Matthew Fargo on 2016/02/22.
//
//

#ifndef fTouchStage_h
#define fTouchStage_h

#include "fAppStage.h"


class fTouchStage : public fAppStage {
public:
    fTouchStage();
    
    void touchDown(ofTouchEventArgs &touch);
    void touchMoved(ofTouchEventArgs &touch);
    void touchUp(ofTouchEventArgs &touch);
    void touchDoubleTap(ofTouchEventArgs &touch);
    void touchCancelled(ofTouchEventArgs &touch);
    
};

#endif /* fTouchStage_h */
