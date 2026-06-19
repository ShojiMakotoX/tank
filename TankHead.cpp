#include "TankHead.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Bullet.h"
#include <assert.h>

TankHead::TankHead(GameObject* parent)
	:GameObject(parent, "TankHead"), hModel_(-1)
{
	//コンストラクタはメンバの初期化をする場合に書く
}

void TankHead::Initialize()
{
	//モデルの読み込み、データの用意
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
	//タンクヘッドの回転（左へ）
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y -= 1.5f;
	}

	//タンクヘッドの回転（右へ）
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y += 1.5f;
	}

	if (Input::IsKeyDown(DIK_SPACE))
	{
		const float BULLET_SPEED = 0.2f;//弾のスピードを設定する
		XMFLOAT3 cannonTop = Model::GetBonePosition(hModel_, "Top");//タンクヘッドのtop XMFLOAT3で返っている
		XMFLOAT3 cannonRoot = Model::GetBonePosition(hModel_, "Root");//タンクヘッドのtop XMFLOAT3で返っている
		//XMVECTORに２つとも変換する
		XMVECTOR vTop = XMLoadFloat3(&cannonTop);
		XMVECTOR vRoot = XMLoadFloat3(&cannonRoot);
		//VMoveを作って単位ベクトルか
		//XMVECTOR vMove = XMVectorSubtract(vTop, vRoot);
		XMVECTOR vMove = vTop - vRoot;
		//スピードを0.2fぐらいに設定する
		vMove = BULLET_SPEED * vMove;
		//XMFLOAT3に戻す
		XMFLOAT3 move;
		XMStoreFloat3(&move, vMove);

		Bullet* pBullet = Instantiate<Bullet>(GetParent()->GetParent());
		pBullet->SetMoveVector(move);
		pBullet->SetPosition(cannonTop);
	}

}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
