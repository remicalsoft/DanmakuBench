#pragma once

#include "ScenePrmBase.h"

class ScorePrm : public ScenePrmBase {
	int _score;
public :
	ScorePrm(int score) {
		_score = score;
	}
	int getScore() {
		return _score;
	}
};