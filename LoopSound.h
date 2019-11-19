#pragma once
#include "Sound.h"
class LoopSound :
	public Sound
{

public:

	using Sound::Sound;
	virtual void playSound() override;
};

