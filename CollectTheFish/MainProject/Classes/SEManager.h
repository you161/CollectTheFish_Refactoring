#pragma once
#include "../HuEngine.h"

using namespace HE;
using namespace Math;
using namespace std;

class SEmanager
{
public:
    void Load();
    void PlayMainBGM();
    void PlayCollectSe();
    void PlayDamageSE();
private:
    Sound main_bgm_;
    Sound collect_se_;
    Sound damage_se_;

    float bgm_volume = 0.1f;
    float collect_se_volume = 0.05f;
    float damage_se_volume = 0.05f;
};