#pragma once
#include "Engine\\GameObject.h"

class EnemyManager :
    public GameObject
{
	EnemyManager(GameObject* parent);
	//デストラクタ
	~EnemyManager() {}//インライン定義
	//初期化
	void Initialize() override;
	//更新
	void Update() override;
	//描画
	void Draw() override;
	//開放
	void Release() override;
private:
	int hModel_;//タンクの弾モデルのハンドル
	int enemyPos_;
	
};

