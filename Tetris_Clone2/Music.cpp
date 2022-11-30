#include "Music.h"

bool Music::initAudio()
{
	if (Mix_OpenAudio(frequency, format, channels, chunksize) == -1)
		return false;
	return true;
}

Music::Music()
{
	if(!initAudio())
		std::cout << "Failed to make an audio device!!!\n";
}

Music::~Music()
{
	Mix_FreeMusic(music);
	music = NULL;
}

bool Music::playMusic()
{
	//song is looping endlessly, set value to 0 if u want music to play once and stop or a higher value corressponding to the number of times looping
	if (Mix_PlayMusic(music, -1) == -1)
		return false;
	return true;
}

bool Music::isMusicPlayed()
{
	return Mix_PlayingMusic();
}

bool Music::isMusicPaused()
{
	return Mix_PausedMusic();;
}

void Music::pauseMusic()
{
	Mix_PauseMusic();
}

void Music::resumeMusic()
{
	Mix_ResumeMusic();
}

void Music::stopMusic()
{
	Mix_HaltMusic();
}

bool Music::loadMusic(const std::string musicPath)
{
	if(isMusicPlayed())
		stopMusic();
	music = Mix_LoadMUS(musicPath.c_str());
	if (!music)
	{
		std::cout << "Cannot load music from " << musicPath << "\n";
		return false;
	}
	return true;
}
