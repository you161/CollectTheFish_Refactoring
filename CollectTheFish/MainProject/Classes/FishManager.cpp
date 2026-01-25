#include "FishManager.h"

void FishManager::Load(const std::vector<FishParam>& params)
{
    fishes_.resize(params.size());

    for (size_t i = 0; i < params.size(); i++)
    {
        fishes_[i].Load(params[i]);
    }
}

void FishManager::Initialize()
{
    for (auto& fish : fishes_)
        fish.Initialize();
}

void FishManager::Update()
{
    for (auto& fish : fishes_)
        fish.Update();
}

std::vector<Fish>& FishManager::GetFishList()
{
    return fishes_;
}
