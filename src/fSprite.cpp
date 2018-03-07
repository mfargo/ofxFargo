//
//  fSprite.cpp
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/02/15.
//
//

#include "fSprite.h"
#include "ofxTweenzor.h"

fSprite::fSprite() {
    name = "fSprite";
	size.set(0,0);
	position.set(0,0);
	scale = 1.0;
	touchPadding = 0.0;
	opacity = 1.0;
    collectiveOpacity = opacity;
	enabled = true;
    visible = true;
    dragging = false;
    draggable = false;
	parent = NULL;
}

fSprite::~fSprite() {
    children.clear();
}

fSprite * fSprite::addChild(fSprite *child) {
    child->parent = this;
    //children.push_back(child);
    return fSpriteContainer::addChild(child);
}

void fSprite::update() {
    if (!visible) return;
	if (opacity <= 0.f) return;
    onUpdate();
    for (vector<fSprite *>::iterator it=children.begin(); it!=children.end(); ++it)
        (*it)->update();
    onUpdateComplete();
    fSpriteContainer::update();
}

void fSprite::draw() {
    
    
    if (!visible) return;
    collectiveOpacity = (parent==NULL) ? opacity : opacity * parent->collectiveOpacity;
	if (collectiveOpacity <= 0.f) return;
	ofSetColor(255, 255, 255, collectiveOpacity*255.f);
	ofPushMatrix();
	ofTranslate(position);
    ofRotateX(rotation.x);
	ofRotateY(rotation.y);
    ofRotateZ(rotation.z);
	ofScale(scale, scale);
	ofTranslate(-size.x * 0.5, -size.y * 0.5);  // calculate from the middle by default like UIKit instead of Flash
	onDraw();
    for (int i=0; i<children.size(); i++)
        children[i]->draw();
    
    onDrawComplete();
	ofPopMatrix();
	glColor3f(1.0, 1.0, 1.0);
}


fSprite *fSprite::processTouchDown(int touchID, const ofVec2f &globalPoint) {
    if (!enabled) return NULL;
    for (int i=children.size()-1; i>-1; i--) {
		fSprite *sprite = children[i]->processTouchDown(touchID, globalPoint);
        if (sprite) return sprite;
	}
    ofVec3f localPoint = globalToLocal(globalPoint);
    if (!containsLocalPoint(localPoint))
		return NULL;
    else {
        touchVelocity = ofVec2f(0, 0);
        totalDrag = 0.f;
        touchPoint = localPoint;
        globalTouchPoint = globalPoint;
        dragging = true;
        this->onDown();
        return this;
    }
}

void fSprite::processTouchMove(int touchID, const ofVec2f &globalPoint) {
    touchPoint = globalToLocal(globalPoint);
    touchVelocity = globalPoint - globalTouchPoint; /// might wanna smoob this
    globalTouchPoint = globalPoint;
    totalDrag += touchVelocity.length();
    if (draggable) {
        position += touchVelocity;
    }
    this->onMove(touchVelocity);
}

void fSprite::processTouchUp(int touchID, const ofVec2f &globalPoint) {
    dragging = false;
    this->onUp(totalDrag);
    totalDrag = 0;
}

ofVec3f fSprite::globalToLocal(const ofVec3f &globalPoint) {
	ofMatrix4x4 curTransform, invTransform;
	fSprite *curParent = this;
	while (curParent != NULL) {
		curTransform.postMultTranslate(-curParent->size.x * 0.5, -curParent->size.y * 0.5, 0.0);
		curTransform.postMultScale(curParent->scale, curParent->scale, 1.0);
        curTransform.postMultRotate(ofQuaternion(curParent->rotation.x, curParent->rotation.y, curParent->rotation.z, 0));
		//curTransform.postMultRotate(curParent->rotation, 0.0, 0.0, 1.0);
		curTransform.postMultTranslate(curParent->position.x, curParent->position.y, 0.0);
		curParent = curParent->parent;
	}
    
	invTransform.makeInvertOf(curTransform);
	return ofVec3f(globalPoint) * invTransform;
}

ofVec3f fSprite::localToGlobal(const ofVec3f &localPoint) {
	ofMatrix4x4 curTransform;
	fSprite *curParent = this;
	while (curParent != NULL) {
		curTransform.postMultTranslate(-curParent->size.x * 0.5, -curParent->size.y * 0.5, 0.0);
		curTransform.postMultScale(curParent->scale, curParent->scale, 1.0);
        curTransform.postMultRotate(ofQuaternion(curParent->rotation.x, curParent->rotation.y, curParent->rotation.z, 0));
		//curTransform.postMultRotate(curParent->rotation, 0.0, 0.0, 1.0);
		curTransform.postMultTranslate(curParent->position.x, curParent->position.y, 0.0);
		curParent = curParent->parent;
	}
    
	return ofVec3f(localPoint) * curTransform;
}

ofVec2f fSprite::scaledSize() {
    return this->size * this->scale;
}

void fSprite::animatePosition(ofVec3f point, float time, float delay, int easeType, bool notifyCompletion) {
    if (point==this->position) return;
    if (point.x != this->position.x)
        Tweenzor::add( &this->position.x, this->position.x, point.x, delay, time, easeType );
    if (point.y != this->position.y)
        Tweenzor::add( &this->position.y, this->position.y, point.y, delay, time, easeType );
    if (point.z != this->position.z)
        Tweenzor::add( &this->position.z, this->position.z, point.z, delay, time, easeType );
    if (notifyCompletion) Tweenzor::addCompleteListener( Tweenzor::getRecentTween(), this, &fSprite::onPositionAnimationComplete );
}
void fSprite::animateScale(float scale, float time, float delay, int easeType, bool notifyCompletion) {
    if (scale==this->scale) return;
    Tweenzor::add( &this->scale, this->scale, scale, delay, time, easeType );
    if (notifyCompletion) Tweenzor::addCompleteListener( Tweenzor::getRecentTween(), this, &fSprite::onScaleAnimationComplete );
}
void fSprite::animateRotation(ofVec3f rotation, float time, float delay, int easeType, bool notifyCompletion) {
    if (rotation==this->rotation) return;
    if (rotation.x != this->rotation.x)
        Tweenzor::add( &this->rotation.x, this->rotation.x, rotation.x, delay, time, easeType );
    if (rotation.y != this->rotation.y)
        Tweenzor::add( &this->rotation.y, this->rotation.y, rotation.y, delay, time, easeType );
    if (rotation.z != this->rotation.z)
        Tweenzor::add( &this->rotation.z, this->rotation.z, rotation.z, delay, time, easeType );
    if (notifyCompletion) Tweenzor::addCompleteListener( Tweenzor::getRecentTween(), this, &fSprite::onRotationAnimationComplete );
}

void fSprite::onPositionAnimationComplete(float *arg) {
    fSpriteEvent e = fSpriteEvent(this);
    ofNotifyEvent(this->ANIMATION_POSITION_COMPLETE, e);

}
void fSprite::onRotationAnimationComplete(float *arg) {
    fSpriteEvent e = fSpriteEvent(this);
    ofNotifyEvent(this->ANIMATION_ROTATION_COMPLETE, e);
}
void fSprite::onScaleAnimationComplete(float *arg) {
    fSpriteEvent e = fSpriteEvent(this);
    ofNotifyEvent(this->ANIMATION_SCALE_COMPLETE, e);
}

void fSprite::stopPositionAnimation() {
    Tweenzor::removeTween(&this->position.x);
    Tweenzor::removeTween(&this->position.y);
    Tweenzor::removeTween(&this->position.z);
}
void fSprite::stopRotationAnimation() {
    Tweenzor::removeTween(&this->rotation.x);
    Tweenzor::removeTween(&this->rotation.y);
    Tweenzor::removeTween(&this->rotation.z);
}
void fSprite::stopScaleAnimation() {
    Tweenzor::removeTween(&this->scale);
}
void fSprite::stopAllAnimations() {
    stopPositionAnimation();
    stopScaleAnimation();
    stopRotationAnimation();
}

bool fSprite::containsPoint(const ofVec2f &globalPoint) {
	return containsLocalPoint(globalToLocal(globalPoint));
}

bool fSprite::containsLocalPoint(const ofVec2f &localPoint) {
	float padding = touchPadding / scale;
	return (localPoint.x >= -padding && localPoint.x < size.x + padding && localPoint.y >= -padding && localPoint.y < size.y + padding);
}

