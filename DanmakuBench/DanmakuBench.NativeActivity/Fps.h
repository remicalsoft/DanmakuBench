#pragma once

#include <list>
#include "Task.h"
#include "IFpsGettable.h"

class Fps : public Task, IFpsGettable {

	std::list<int>	_list;
	int _font;
	float _fps;
	unsigned _counter;

	void		regist();
	unsigned	getWaitTime();

public:
	Fps();
	bool		update();
	void		draw();
	void		wait();

	//override IFpsGettable
	float		getFps() {
		return _fps;
	}

};

