#include "EnemyManager.h"
#include "Engine\\Model.h"
#include "Enemy.h"

EnemyManager::EnemyManager(GameObject* parent)
	:GameObject(parent,"EnemyManager"),hModel_(-1)
{
}



namespace
{
	std::vector<Enemy*>enemies_;//配列を作る
	int ENEMY_SPWAN_MAX = 5;//敵をスポーンさせる数（数字をいじれば変更も可能）
}

void EnemyManager::Initialize()
{
	for (int d = 0;d < ENEMY_SPWAN_MAX;d++)
	{
		Enemy* e = Instantiate<Enemy>(this);
		enemies_.push_back(e);
	}
	
}

void EnemyManager::Update()
{
	for (auto e : enemies_)
	{
		e->Update();
	}
}

void EnemyManager::Draw()
{
	for (auto e : enemies_)
	{
		e->Draw();
	}
}

void EnemyManager::Release()
{
}
