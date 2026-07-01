#include "EnemyManager.h"
#include "Engine\\Model.h"
#include "Enemy.h"
#include "Weeds.h"

EnemyManager::EnemyManager(GameObject* parent)
	:GameObject(parent,"EnemyManager"),hModel_(-1)
{
}



namespace
{
	int ENEMY_SPWAN_MAX = 8;//敵をスポーンさせる数（数字をいじれば変更も可能）
	int WEED_SPAWN_MAX = 5;
}

void EnemyManager::Initialize()
{
	for (int d = 0;d < ENEMY_SPWAN_MAX;d++)
	{
		Enemy* e = Instantiate<Enemy>(this);
		enemies_.push_back(e);
	}
	for (int c = 0;c < WEED_SPAWN_MAX;c++)
	{
		Weeds* w = Instantiate<Weeds>(this);
		weeds_.push_back(w);
	}
	
	
}

void EnemyManager::Update()
{
	
}

void EnemyManager::Draw()
{
	
}

void EnemyManager::Release()
{
}
