//
// CollisionDetection.cpp
//

#include "CollisionDetection.h"

using namespace HE;

void CollisionDetection::AddCollider(const std::wstring group, ICollider* iCollider)
{
	collider_group_[group].push_back(iCollider);
}

void CollisionDetection::Detect(const std::wstring groupA, const std::wstring groupB, const bool isBreak)
{
	auto&& group_a = collider_group_[groupA];
	auto&& group_b = collider_group_[groupB];
	for (const auto& collider_a : group_a) {
		const auto& collision_a = collider_a->GetCollider();
		for (const auto& collider_b : group_b) {
			if (collision_a.Intersects(collider_b->GetCollider())) {
				collider_a->OnCollision();
				collider_b->OnCollision();
				if (isBreak)
					return;
			}
		}
	}
}

void CollisionDetection::Clear()
{
	collider_group_.clear();
}