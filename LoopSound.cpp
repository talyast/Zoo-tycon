#include "LoopSound.h"





void LoopSound::playSound()
{
	Sound::playSound();
	loop();
}
