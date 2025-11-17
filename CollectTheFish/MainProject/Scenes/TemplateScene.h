#pragma once

#include "../HuEngine.h"

class StartScene : public HE::Scene
{
public:
	StartScene();
	virtual ~StartScene() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

private:



};
