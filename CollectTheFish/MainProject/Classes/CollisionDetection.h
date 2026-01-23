#pragma once

#include "../HuEngine.h"

#include "ICollider.h"

#include <map>
#include <unordered_set>
#include <list>

class CollisionDetection {
public:
	void AddGroupList(const std::wstring group, ICollider* iCollider);

	void Detect(const std::wstring groupA, const std::wstring groupB, const bool isBreak = true);

	void ClearGroup(const std::wstring group);
	void Clear();

private:
	std::map<std::wstring, std::unordered_set<ICollider*>> collider_group_;
};
