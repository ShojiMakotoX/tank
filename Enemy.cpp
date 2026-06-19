#include "Enemy.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Ground.h"
#include <assert.h>

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{

}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
}

void Enemy::Update()
{
	//レイキャストして、浮いてたら地面まで落とす
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0.0f;//地面は0より下に作られている、そうじゃない時はもっと上から
	data.dir = { 0,-1,0 };//真下にレイを飛ばす

	Ground* pGround = (Ground*)FindObject("Ground");//グラウンドオブジェクトを探す
	int hGroundModel = pGround->GetModelHandle();//グラウンドオブジェクトモデルのハンドル探し
	Model::RayCast(hGroundModel, &data);//レイキャストして地面に当たったかどうか、当たった時の距離や向きを返す

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist;
		//レイの発射位置から、地面までの距離をひいて地面にぴったりつける
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
