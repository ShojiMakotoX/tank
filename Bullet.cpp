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
	Collider* collider = new SphereCollider({ 0,0,0 },0.25f);//コライダーを作る
	AddCollider(collider);//コライダーをEnemyに追加

}
//ture false型がなかったころ
//0:FALSE 1:TRUE　で表していた

void Bullet::Update()
{
	//transform_.position_ = transform_.position_ + move_;
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);//ロード、読み込み
	move_.y -= 0.005f;//重力をつける
	XMVECTOR vMove = XMLoadFloat3(&move_);//ロード、読み込み

	vPos = vPos + vMove;//弾の進行方向に移動する

	XMStoreFloat3(&transform_.position_, vPos);//ストア：書き込み
	/*transform_.position_.x += move_.x;
	transform_.position_.y += move_.y;
	transform_.position_.z += move_.z;*/

	/*if (transform_.position_.z > 50.0f || transform_.position_.z < -50.0f || transform_.position_.x > 50.0f || transform_.position_.x < -50.0f)*/
	if(transform_.position_.y < -50.0f)//ありえないくらい下に行ったら消す
	{
		KillMe();//弾がある程度遠くへ行ったら消す
	}
}


//敵を配置（敵もレイキャストしてx,z座標ランダムで）、まずは1体配置したい
//当たり判定（コライダーの配置）

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
