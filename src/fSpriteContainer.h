//
//  fSpriteContainer.h
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/03/03.
//
//

#ifndef __ofxFargo__fSpriteContainer__
#define __ofxFargo__fSpriteContainer__

#include "ofMain.h"

class fSprite;

class fSpriteContainer {
public:
	fSpriteContainer();
	virtual ~fSpriteContainer();
	
    virtual fSprite *   addChild(fSprite * child);
    virtual fSprite *   addChildAt(fSprite *child, int index);
    fSprite *           getFirstChild();
    int                 getNumChildren();
    fSprite *           getChildAt(int index);
    fSprite *           removeFirstChild();
    fSprite *           removeChild(fSprite * child);
    void                moveChildToTop(fSprite * child);

	bool                touchEnabled;
    bool                visible;
    string              name;   // for debugging purposes

protected:
    
    virtual void    update();
    virtual void    draw();

    
    virtual void onDraw() {}
    virtual void onDrawComplete() {}
	virtual void onUpdate() {}
	virtual void onUpdateComplete() {}

    vector<fSprite *>   children;
    vector<fSprite *>   childrenToRemove;

private:
    
	
};

#endif /* defined(__ofxFargo__fSpriteContainer__) */
