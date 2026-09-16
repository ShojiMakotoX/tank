#include "Clear.h"
#include "Engine\\Input.h"
#include "Engine\\SceneManager.h"

Clear::Clear(GameObject* parent)
	:GameObject(parent,"Clear"),pText_()
{
}

void Clear::Initialize()
{
}

void Clear::Update()
{
	if (Input::IsKey(DIK_R))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void Clear::Draw()
{
	pText_->Draw(550, 300, "CLEAR!");
	pText_->Draw(500, 400, "Press r return to Title.");
}

void Clear::Release()
{
}
