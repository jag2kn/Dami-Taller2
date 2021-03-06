#include "Steiner.h"

Steiner::Steiner	(int w, int h, int r) : ParametricObject(w, h) {
	this->r = r;
}


Steiner::~Steiner(void){
}

ofPoint Steiner::computePosition(ofPoint point){
	float theta = point.x * PI * 0.5, phi = point.y * TWO_PI;
	float r = getSmallR(phi, theta/*, 10, 20, 0*/);

	return ofPoint(
					r*r * cos(theta) * sin(theta) * sin(phi),
					r*r * cos(theta) * sin(theta) * cos(phi),
					r*r * cos(theta) * cos(theta) * cos(phi) * sin(phi)
				);
}

ofPoint Steiner::computeNormal(ofPoint point){
	float theta = point.x * PI*0.5 , phi = point.y * TWO_PI;
	float r = getSmallR(phi, theta/*, 10, 20, 0*/);

	ofPoint dTheta = ofPoint(
					r*r * cos(2*theta) * sin(phi),
					r*r * cos(2*theta) * cos(phi),
					-2 * r*r * sin(theta) * cos(theta) * sin(phi) * cos(phi)
						);

	ofPoint dPhi = ofPoint(
					r*r * sin(theta) * cos(theta) * cos(phi),
					r*r * sin(theta) * cos(theta) * sin(phi),
					r*r * cos(theta) * cos(theta) * cos(2*phi)
						);

	ofPoint normal = dPhi.getCrossed(dTheta).getNormalized();
	/*
	if (point.x<0.5 && point.y<0.5){
		normal = normal.getCrossed(ofPoint(-1,-1,-1)).getNormalized();
	}
	*/
	return normal;
}

float Steiner::getSmallR(float phi, float theta, float periods, float waveMagnitude, float phase) {
	return r + waveMagnitude * sin(periods * theta + phase);
}
