//
//  fSpriteContainer.cpp
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/03/03.
//
//

#include "fSpriteContainer.h"

fSpriteContainer::fSpriteContainer() {
    name = "fSpriteContainer";
}
fSpriteContainer::~fSpriteContainer() {
    children.clear();
}

void fSpriteContainer::update() {
    while (childrenToRemove.size()>0){
        for (vector<fSprite *>::iterator it=children.begin(); it!=children.end(); ++it)
            if ((*it)==childrenToRemove[0]) children.erase(it);
        fSprite * s = childrenToRemove[0];
        childrenToRemove.erase(childrenToRemove.begin());
        //children.erase(s);
        //
        //delete s;
    }
}
void fSpriteContainer::draw() {}

fSprite * fSpriteContainer::addChild(fSprite *child) {
	children.push_back(child);
    return child;
}
fSprite * fSpriteContainer::addChildAt(fSprite *child, int index) {
    children.insert(children.begin()+index, child);
    return child;
}

int fSpriteContainer::getNumChildren() {
    return children.size();
}

fSprite * fSpriteContainer::getFirstChild() {
    return children.front();
}
fSprite * fSpriteContainer::getChildAt(int index) {
    if (index<children.size() && index>-1) return children[index];
    return NULL;
}

fSprite * fSpriteContainer::removeFirstChild() {
    fSprite * s = children[0];
    children.erase(children.begin());
    return s;
}

fSprite * fSpriteContainer::removeChild(fSprite *child) {
    for (vector<fSprite *>::iterator it=children.begin(); it!=children.end(); ++it) {
        if ((*it)==child) {
            children.erase(it);
            return child;
        }
    }
    return NULL;
}
void fSpriteContainer::moveChildToTop(fSprite * child) {
    fSprite * s = this->removeChild(child);
    if (child) this->addChild(child);
}

