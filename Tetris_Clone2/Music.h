#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

class Music
{
private:
	enum{ frequency = 22050, format = MIX_DEFAULT_FORMAT, channels = 2, chunksize = 4096};
	Mix_Music* music = NULL;
	bool initAudio();

public:
	Music();
	~Music();
	//start music
	//return true if music plays successfully
	//music is looped indefinitely
	bool playMusic();
	//check if music is played, note that if a music is paused, it will still return true
	bool isMusicPlayed();
	//check if music is paused
	bool isMusicPaused();
	//pause music
	void pauseMusic();
	//resume music
	void resumeMusic();
	//stop music, call this function when you want to load and play a new music while currently playing a music
	void stopMusic();
	//load a music file
	bool loadMusic(const std::string musicPath);
};

