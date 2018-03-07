//
//  fTouchStage.cpp
//  Writeboard
//
//  Created by Matthew Fargo on 2016/02/22.
//
//

#include "fTouchStage.h"


fTouchStage::fTouchStage() {
    //ofRegisterTouchEvents(this);
}

void fTouchStage::touchDown(ofTouchEventArgs &touch) {
    printf("d: %d", touch.id);
}
void fTouchStage::touchMoved(ofTouchEventArgs &touch) {
    printf("m: %d", touch.id);
    
}
void fTouchStage::touchUp(ofTouchEventArgs &touch) {
    printf("u: %d", touch.id);

}
void fTouchStage::touchDoubleTap(ofTouchEventArgs &touch) {
    
}
void fTouchStage::touchCancelled(ofTouchEventArgs &touch) {
    printf("c: %d", touch.id);

}