//
//  fImage.cpp
//  ofxFargo
//
//  Created by Matt Fargo on 2013/03/01.
//
//

#include "fImage.h"

fImage::fImage() {}
fImage::fImage(string url) {
    _load(url);
}
fImage::~fImage() {
    image.clear();
}

void fImage::_load(string url) {
    _url = url;
    bool loaded = image.load(url);
    if (!loaded) printf("fImage: WARNING -> couldn't load image at %s\n", url.c_str());
    size.x = image.getWidth();
    size.y = image.getHeight();
}

void fImage::onUpdate() {}

void fImage::onDraw() {
    if (!image.isAllocated()) return;
    ofSetColor(tint.r, tint.g, tint.b, getCollectiveOpacity()*255.f);
    image.draw(0, 0, size.x, size.y);    
}

void fImage::setUrl(string url) {
    image.clear();
    _load(url);
}

string fImage::getUrl() {
    return _url;
}
