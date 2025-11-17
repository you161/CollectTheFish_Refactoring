#pragma once

#include "../HuEngine.h"
#include "ICollider.h"

#include <map>
#include <vector>

class CollisionDetection {
public:
	void AddCollider(const std::wstring group, ICollider* iCollider);
	void Detect(const std::wstring groupA, const std::wstring groupB, const bool isBreak = true);
	void Clear();

private:
	std::map<std::wstring, std::vector<ICollider*>> collider_group_;
};