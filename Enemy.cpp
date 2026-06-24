#include "Enemy.h"
#include "Engine\\Model.h"
#include "Ground.h"
#include "Engine\\SphereCollider.h"
#include <assert.h>

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{

}

//敵を複数出す
//・どこで敵を管理する？
//・次回、得点表示をやってみる（スプライト）
//（得点をintでもっておいて、各桁の数字の画像を並べて表示する（気合で））

void Enemy::Initialize()
{

	hModel_ = Model::Load("Enemy.fbx");

	Model::SetAnimFrame(hModel_, 1, 100, 1.0f);
	//モデルハンドル、開始フレーム、終了フレーム、アニメーション速度
	assert(hModel_ >= 0);
	float x = (rand() / RAND_MAX) * 5.0f - 10.0f;
	float z = (rand() / RAND_MAX) * 5.0f - 10.0f;
	transform_.position_.x = x;
	transform_.position_.z = z;
	SphereCollider* collider = new SphereCollider({ 0,0,0 },0.5f);//コライダーを作る
	AddCollider(collider);//コライダーをEnemyに追加
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

void Enemy::OnCollision(GameObject* pTarget)
{
	//衝突した相手がBulletだったら消える。
	if (pTarget->GetObjectName() == "Bullet")
	{
		KillMe();//自分を消す
	}
}
