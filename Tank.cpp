#include "Tank.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Engine\\Debug.h"
#include"Ground.h"
#include "Engine\\Camera.h"
#include <assert.h>

namespace
{
	XMVECTOR vFront = { 0,0,1,0 };//タンクの前方向のベクトル
	const float moveSpeed = 0.1f;
	enum CAM_TYPE
	{
		FIXED_CAM, //固定カメラ
		TPS_CAM,   //三人視点カメラ
		TPS_CAMROT,//三人称視点カメラ（回転）
		FPS_CAM,   //一人称視点カメラ
		CAM_TYPE_MAX
	};
}

//タンクのボディを表す
Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),hModel_(-1),camType_(FIXED_CAM)
{
}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);
}

void Tank::Update()
{
	if (Input::IsKeyDown(DIK_C))
	{
		camType_ = (camType_ + 1) % CAM_TYPE_MAX;
		//0,1,2......CAM_TYPE_MAX-1の順でcamType_を切り替える
	}
	switch (camType_)
	{
	case FIXED_CAM:
		//固定カメラ処理
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		Camera::SetPosition(XMFLOAT3(0, 20, -30));
		break;
	case TPS_CAM:
		//三人称視点カメラの処理
		break;
	case TPS_CAMROT:
		//三人称視点カメラ（回転）の処理
		break;
	case FPS_CAM:
		//一人称視点カメラの処理
		break;
	}

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
	Debug::Log("CAMTYPE = ");
	Debug::Log(camType_, true);//後のtrueは改行するかどうか
	//wキーを押している間前に進む
	if (Input::IsKey(DIK_W))
	{
		XMVECTOR vPos = XMLoadFloat3(&transform_.position_);//ロード　読み込み
		XMMATRIX matRot = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));//y軸回転行列を作る
		//XMVector3TransformCoordはベクトルを行列で変換する関数。回転行列をベクトルにかけると回転したベクトルが得られる
		XMVECTOR vMove = XMVector3TransformCoord(vFront, matRot);
		vPos = vPos + moveSpeed * vMove;
		XMStoreFloat3(&transform_.position_, vPos);//ストア　書き込み（格納）
	}

	//レイキャストして、浮いてたら地面まで落とす
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0.0f;//地面は0より下に作られている。そうじゃないときはもっと上から
	data.dir = { 0,-1,0 };//真下にレイを飛ばす
	
	Ground* pGround = (Ground*)FindObject("Ground");//グラウンドオブジェクトを探す
	int hGroundModel = pGround->GetModelHandle();//グラウンドオブジェクトモデルのハンドルを返す
	Model::RayCast(hGroundModel, &data);//レイキャストして、地面に当たったかどうか、当たった時の距離や向きを返す
	if (data.hit == true)
	{
		transform_.position_.y = - data.dist;
		//レイの八社一から、地面までの距離をひいて地面にぴったりつける
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
