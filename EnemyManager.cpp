#include "EnemyManager.h"
#include "Engine\\Model.h"
#include "Enemy.h"
#include "Weeds.h"
#include "Engine\\SceneManager.h"

EnemyManager::EnemyManager(GameObject* parent)
	:GameObject(parent,"EnemyManager"),hModel_(-1)
{
}



namespace
{
	int ENEMY_SPWAN_MAX = 2;//敵をスポーンさせる数（数字をいじれば変更も可能）
	int WEED_SPAWN_MAX = 2;
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
	if (ENEMY_SPWAN_MAX == 0 && WEED_SPAWN_MAX == 0)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void EnemyManager::Draw()
{
	
}

void EnemyManager::Release()
{
}
