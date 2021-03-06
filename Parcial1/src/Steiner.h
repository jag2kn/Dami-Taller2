#pragma once

#include "ParametricObject.h"


//http://en.wikipedia.org/wiki/Steiner_surface

class Steiner : public ParametricObject {
public:
	Steiner(int w, int h, int r);
	~Steiner(void);

	ofPoint computePosition(ofPoint point);
	ofPoint computeNormal(ofPoint point);

protected:
	float getSmallR(float phi, float theta, float periods = 1, float waveMagnitude = 0, float phase = 0);

	float r;
};

