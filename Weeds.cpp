#include "Weeds.h"
#include "Engine\\Model.h"
#include "Ground.h"
#include "EnemyManager.h"

Weeds::Weeds(GameObject* parent)
	:GameObject(parent,"Weeds"),hModel_(-1)
{

}

void Weeds::Initialize()
{
	hModel_ = Model::Load("kusa.fbx");
	Model::SetAnimFrame(hModel_, 1, 100, 1.0f);
	//モデルハンドル、開始フレーム、終了フレーム、アニメーション速度
	assert(hModel_ >= 0);
	float x = ((float)rand() / RAND_MAX) * 35.0f - 10.0f;
	float z = ((float)rand() / RAND_MAX) * 35.0f - 10.0f;
	transform_.position_.x = x;
	transform_.position_.z = z;
	SphereCollider* collider = new SphereCollider({ 0,0,0 }, 1.0f);//コライダーを作る
	AddCollider(collider);//コライダーをEnemyに追加
}

void Weeds::Update()
{
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

void Weeds::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Weeds::Release()
{
}

void Weeds::OnCollision(GameObject* pTarget)
{
	//衝突した相手がBulletだったら消える。
	if (pTarget->GetObjectName() == "Bullet")
	{
		EnemyManager* wEnemyManager = (EnemyManager*)GetParent();
		wEnemyManager->WeedDefeated();
		KillMe();//自分を消す
	}
}
