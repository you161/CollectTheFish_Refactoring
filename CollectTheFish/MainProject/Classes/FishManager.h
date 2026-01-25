#pragma once
#include "../HuEngine.h"
#include "Fish.h"

class FishManager
{
public:
    void Load(const std::vector<FishParam>& params);
    void Initialize();
    void Update();

    std::vector<Fish>& GetFishList();

private:
    std::vector<Fish> fishes_;
};
