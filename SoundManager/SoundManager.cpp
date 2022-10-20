#include "SoundManager.h"

void SoundManager::Initialize()
{
	audio_ = Audio::GetInstance();
	bgm_.push_back(audio_->LoadWave("sound/GameTitle.mp3"));
	bgm_.push_back(audio_->LoadWave("sound/GamePlay.mp3"));
	bgm_.push_back(audio_->LoadWave("sound/GameClear.mp3"));
	bgm_.push_back(audio_->LoadWave("sound/GameOver.mp3"));
	se_.push_back(audio_->LoadWave("sound/PlayerHitSE.mp3"));
}

void SoundManager::PlayBGM(BGM index)
{
	if (audio_->IsPlaying(bgm_[index])) { return; }
	audio_->PlayWave(bgm_[index], true, 0.8f);
}

void SoundManager::PlaySE(SE index)
{
	audio_->PlayWave(se_[index]);
}

void SoundManager::StopBGM(BGM index)
{
	audio_->StopWave(bgm_[index]);
}

SoundManager* SoundManager::GetInstance()
{
	static SoundManager instance;
	return &instance;
}