#pragma once
#include "State.h"

class StateRojo : public State
{
	public:
		StateRojo(StateMachineApp* app);
		~StateRojo(void);
		void setup();
		void update();
		void draw();
		virtual void exit();
		virtual void keyPressed(int key);
		virtual void keyReleased(int key);
		virtual void mouseMoved(int x, int y);
		virtual void mouseDragged(int x, int y, int button);
		virtual void mousePressed(int x, int y, int button);
		virtual void mouseReleased(int x, int y, int button);

	protected:
		char* getStateName(int id);
		void in();
		void out();

		

};

