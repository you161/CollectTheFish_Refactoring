#include "SEmanager.h"

void SEmanager::Load()
{
	main_bgm_ = Sound("Sound/mainbgm.wav", Sound::LoopCount::BGM);
	collect_se_ = Sound("Sound/PushA.wav", Sound::LoopCount::SE);
	damage_se_ = Sound("Sound/Da.wav", Sound::LoopCount::SE);

	main_bgm_.SetVolume(bgm_volume);
	collect_se_.SetVolume(collect_se_volume);
	damage_se_.SetVolume(damage_se_volume);
}

void SEmanager::PlayMainBGM()
{
	main_bgm_.PlayFromTop();
}

void SEmanager::PlayCollectSe()
{
	collect_se_.PlayFromTop();
}

void SEmanager::PlayDamageSE()
{
	damage_se_.PlayFromTop();
}