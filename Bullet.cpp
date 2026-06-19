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
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);//ロード、読み込み
	move_.y -= 0.005f;
	XMVECTOR vMove = XMLoadFloat3(&move_);//

	vPos = vPos + vMove;//弾の進行方向に移動する

	XMStoreFloat3(&transform_.position_, vPos);//ストア：書き込み
	/*transform_.position_.x += move_.x;
	transform_.position_.y += move_.y;
	transform_.position_.z += move_.z;*/

	/*if (transform_.position_.z > 50.0f || transform_.position_.z < -50.0f || transform_.position_.x > 50.0f || transform_.position_.x < -50.0f)*/
	if(transform_.position_.y < -10.0f)
	{
		KillMe();//弾がある程度遠くへ行ったら消す
	}
}

//弾の弾道を重力つける
//敵を配置（敵もレイキャストしてx,z座標ランダムで
//当たり判定（コライダーの配置）

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
