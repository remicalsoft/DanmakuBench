#pragma once
class Task
{
public:
	Task() {}
	virtual ~Task() {}
	virtual bool initialize() { return true; }
	virtual void finalize() {}
	virtual bool update() { return true; }
	virtual void draw() {}
};

