#include "TransformationsState.h"

TransformationsState::TransformationsState(StateMachineApp* app) : State(app){	
}

void TransformationsState::setup(){
	

	torus = new Torus(20, 20, 200, 80);

	delta = 0;
	direccioncolor = 1;
	renderMode = ParametricObject::SOLID;
}

void TransformationsState::update(){
	delta = (ofGetElapsedTimeMillis()%1000)/1000.0;
}

void TransformationsState::draw(){
	ofBackgroundGradient(ofColor(64), ofColor(0), OF_GRADIENT_BAR);
	
	

	glEnable(GL_DEPTH_TEST);

	GLfloat ambient[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat position[] = {ofGetWidth(), ofGetHeight(), 0, 1.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);	

	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

	/*
	if (delta==0){
		direccioncolor*=-1;
	}*/

	ofFloatColor amb, dif, spe;
	float shi;
	amb.r=0.0;
	amb.g=0.0;
	amb.b=0.0;
	dif.r=1.0*abs(2*(delta-delta/2));
	dif.g=0.0;
	dif.b=1.0;
	spe.r=1;
	spe.g=1;
	spe.b=1;
	shi = 10;

	ofFloatColor amb2, dif2, spe2;
	float shi2;
	amb2.r=0.0;
	amb2.g=0.0;
	amb2.b=0.0;
	dif2.g=0.0;
	dif2.r=1.0*abs(2*(delta-delta/2));
	dif2.b=1.0;
	spe2.r=1;
	spe2.g=1;
	spe2.b=1;
	shi2 = 10;


	float rotacion1 =360.0*delta;
	float rotacion2 =2.0*360.0*delta;
	int n=3, n_i;
	int m=8, m_j;
	float dato_escala;
	float dato_rotacion;
	float angulo_desfase=5;


	// Pintado de toro central
	//camara.begin();

	glTranslatef(0.0, 0.0, -500.0);
	glPushMatrix();
		//glTranslatef(0, 0, -400);
		glTranslatef(ofGetWidth() / 2, ofGetHeight() / 2, 0.0);
		glRotatef(90, 1, 0, 0);
		glRotatef(rotacion1, 0, 0, 1);
		dato_escala=0.8;
		glScalef(dato_escala,dato_escala,dato_escala);
		glTranslatef(-ofGetWidth() / 2, -ofGetHeight() / 2, 0.0);
		torus->draw(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2, 0), amb2,dif2, spe2, shi2, renderMode);
	glPopMatrix();

	glPushMatrix();
		//glTranslatef(0, 0, -400);
		//glTranslatef(ofGetWidth() / 2, ofGetHeight() / 2, 0.0);
		//glRotatef(90, 1, 0, 0);
		//glRotatef(rotacion1, 0, 0, 1);
		for(int j=0;j<m;j++){
			dato_rotacion = 360.0*((float)j/m);
			glTranslatef(ofGetWidth() / 2, ofGetHeight() / 2, 0.0);
			glRotatef(dato_rotacion, 0, 0, 1);
			glTranslatef(-ofGetWidth() / 2, -ofGetHeight() / 2, 0.0);
			for(int i=1;i<=n;i++){
				glRotatef(i*angulo_desfase, 0, 0, 1);
				glPushMatrix();
					dato_escala = 0.2-(float)i/n/10;
					//ofLogNotice()<<i<<", "<<n<<"<--4----\t"<<dato_rotacion<<"\t----> "<<n-i;
					glTranslatef(200+100*(i), 0.0, 0.0);

					glTranslatef(ofGetWidth() / 2, ofGetHeight() / 2, 0.0);
					glRotatef(-90, 1, 0, 0);
					glRotatef(360.0*delta, 0, 1, 0);
					glScalef(dato_escala,dato_escala,dato_escala);
					glTranslatef(-ofGetWidth() / 2, -ofGetHeight() / 2, 0.0);


					torus->draw(ofPoint(ofGetWidth() / 2, ofGetHeight() / 2, 0), amb,dif, spe, shi, renderMode);
				
				glPopMatrix();
				glRotatef(-i*angulo_desfase, 0, 0, 1);
			}
			glTranslatef(ofGetWidth() / 2, ofGetHeight() / 2, 0.0);
			glRotatef(-dato_rotacion, 0, 0, 1);
			glTranslatef(-ofGetWidth() / 2, -ofGetHeight() / 2, 0.0);
		}
		//glTranslatef(-ofGetWidth() / 2, -ofGetHeight() / 2, 0.0);
	glPopMatrix();

	
	//camara.end();


	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POINT_SMOOTH);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

}

string TransformationsState::getStateName(){
	return "TransformationsState";
}

void TransformationsState::keyPressed(int key){
}

void TransformationsState::keyReleased(int key){


	if(key == 'l' || key == 'L')
		renderMode = ParametricObject::WIREFRAME;

	if(key == 's')
		renderMode = ParametricObject::SOLID;

	if(key == 'p')
		renderMode = ParametricObject::POINTS;
}

void TransformationsState::mouseMoved(int x, int y ){
}

void TransformationsState::mousePressed(int x, int y, int button){
}

void TransformationsState::mouseReleased(int x, int y, int button){
}

void TransformationsState::mouseDragged(int x, int y, int button){
}

void TransformationsState::in(){
}

void TransformationsState::out(){
}

void TransformationsState::exit(){
	delete torus;
}