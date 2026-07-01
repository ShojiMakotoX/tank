#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "TankHead.h"
#include "Enemy.h"
#include "EnemyManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);//親をplaysceneにして地面を生成する
	Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);
	/*Enemy* e = Instantiate<Enemy>(this);*/
	Instantiate<EnemyManager>(this);
	
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
