#include "Ground.h"
#include "Engine\\Model.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent, "Ground"), hModel_(-1)
{
}

/// <summary>
/// 何もしない
/// </summary>
Ground::~Ground()
{
	//(デストラクタ（オブジェクトが削除されるときに呼ばれる関数）
}

void Ground::Initialize()
{
	hModel_ = Model::Load("Assets/Ground.fbx");
}

void Ground::Update()
{
}

void Ground::Draw()
{
	//transform_クラスのデフォルト値
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Ground::Release()
{
}
