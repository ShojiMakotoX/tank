#include "TankHead.h"
#include "Engine\\Model.h"
#include "Tank.h"
#include "Ground.h"
#include <assert.h>

TankHead::TankHead(GameObject* parent)
	:GameObject(parent, "TankHead"), hModel_(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);

}

void TankHead::Update()
{
	Tank* tankh = (Tank*)FindObject("Tank");//タンクのオブジェクトを探す
	//ここで多分タンクの上に乗っける処理を書いていけばいいのかな
}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
