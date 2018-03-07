//
//  pUtils.cpp
//  ofxFargo
//
//  Created by Matthew Fargo on 2013/02/15.
//
//

#include "fUtils.h"

string utf8_substr(const string& str, unsigned int start, unsigned int leng)
{
    int pos;
    unsigned char lead;
    int char_size;
    int index = 0;
    stringstream s;
    
    for (pos = 0; pos < str.size(); pos += char_size) {
        
        lead = str[pos];
        
        if (lead < 0x80) {
            char_size = 1;
        } else if (lead < 0xE0) {
            char_size = 2;
        } else if (lead < 0xF0) {
            char_size = 3;
        } else {
            char_size = 4;
        }
        if (index>=start) s << str.substr(pos, char_size);
        if (index+1>=start + leng) return s.str();
        
        index++;
    }
    return "";

}

ofVec3f getRandomPointOnSphere(float radius) {
    float t1 = ofRandom(0, TWO_PI);
    float t2 = ofRandom(0, TWO_PI);
    ofVec3f p;
    p.x = cos(t1) * cos( t2 );
    p.y = sin(t1);
    p.z = cos(t1) * sin( t2 );
    p *= radius;
    return p;
}
