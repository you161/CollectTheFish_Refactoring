//
// StartScene.cpp
//

#include "StartScene.h"

using namespace HE;



// initialize member variables.
StartScene::StartScene()
{

}

// rearrange UI to fit the size.
void StartScene::ResizeLayout()
{
    Scene::ResizeLayout();



}

// load resources.
void StartScene::Load()
{



    Scene::Load();
}

// initialize a variables.
void StartScene::Initialize()
{

}

// releasing resources required for termination.
void StartScene::Terminate()
{

}

// updates the scene.
void StartScene::Update(float deltaTime)
{
    

    if (InputSystem.Keyboard.isPressed.Enter) {
        SceneManager.SetNextScene(NextScene::MainScene);
    }


    Scene::Update(deltaTime);
}

