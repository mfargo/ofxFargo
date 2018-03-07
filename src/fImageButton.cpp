//
//  fImageButton.cpp
//  easel
//
//  Created by Matthew Fargo on 2018/03/07.
//

#include "fImageButton.h"



fImageButton::fImageButton(string url) {
    _load(url);
}
fImageButton::~fImageButton() {
    image.clear();
}

void fImageButton::_load(string url) {
    _url = url;
    bool loaded = image.load(url);
    if (!loaded) printf("fImage: WARNING -> couldn't load image at %s\n", url.c_str());
    size.x = image.getWidth();
    size.y = image.getHeight();
}

void fImageButton::onDraw() {
    if (!image.isAllocated()) return;
    ofSetColor(tint.r, tint.g, tint.b, getCollectiveOpacity()*255.f);
    image.draw(0, 0, size.x, size.y);
}

void fImageButton::setUrl(string url) {
    image.clear();
    _load(url);
}

string fImageButton::getUrl() {
    return _url;
}
