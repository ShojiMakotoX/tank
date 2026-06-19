#include "Bullet.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include <assert.h>

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1), move_(XMFLOAT3(0, 0, 0))
{ 

}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
}

void Bullet::Update()
{
	//transform_.position_ = transform_.position_ + move_;
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
	XMVECTOR vMove = XMLoadFloat3(&move_);
	vPos = vPos + vMove;
	XMStoreFloat3(&transform_.position_, vPos);
	/*transform_.position_.x += move_.x;
	transform_.position_.y += move_.y;
	transform_.position_.z += move_.z;*/
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
