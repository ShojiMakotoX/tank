#include "TestScene.h"
#include "Engine\\Input.h"
#include "Engine\\SceneManager.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"),pText_()
{
}

//初期化
void TestScene::Initialize()
{
	pText_ = new Text;
	HRESULT result = pText_->Initialize();
}

//更新
void TestScene::Update()
{
	if (Input::IsKey(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TestScene::Draw()
{
	pText_->Draw(550, 300, "Tank Game");
	pText_->Draw(500, 400, "Press Space Start!");
}

//開放
void TestScene::Release()
{
}
