#include "Tank.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include <assert.h>

Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),hModel_(-1)
{
}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	hModel_ = Model::Load("Assets/TankBody.fbx");
	assert(hModel_ >= 0);
}

void Tank::Update()
{
	//Aキーを押している間左回転
	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.y -= 1.0f;
	}
	
	//Dキーを押している間右回転
	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.y += 1.0f;
	}
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}
