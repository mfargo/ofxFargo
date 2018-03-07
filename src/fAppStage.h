//
//  fAppStage.h
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/03/03.
//
//

#ifndef __ofxFargo__fAppStage__
#define __ofxFargo__fAppStage__

#include "fSpriteContainer.h"
#include "fSprite.h"


class pInteraction {
public:
    pInteraction(int interactionID, fSprite * sprite) {
        _sprite = sprite;
        _interactionID = interactionID;
    }
    ~pInteraction() {}

    fSprite *   getSprite() { return _sprite; }
    int         getInteractionID() { return _interactionID; }
    
private:
    fSprite *   _sprite;
    int         _interactionID;
};


class fAppStage : public ofBaseApp, public fSpriteContainer {
public:
	fAppStage();
	virtual ~fAppStage();
    
    ofVec2f stageSize();
	
    
protected:
    
            // abstract methods
    virtual void    onExit() {}
	virtual void	onUpdate() {}
	virtual void	onDraw() {}
    virtual void    onKeyPressed(int key) {}
    

private:
    
    void update();
    void draw();
    
    void keyPressed(int key);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);


    void    _exit(ofEventArgs & e);
	map<int, pInteraction *>    _interactions;
    
};

#endif /* defined(__ofxFargo__fAppStage__) */
