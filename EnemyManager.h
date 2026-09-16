#pragma once
#include "Engine\\GameObject.h"
#include <vector>
#include "Enemy.h"
#include "Weeds.h"

class EnemyManager :
    public GameObject
{
public:
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
	std::vector<Enemy*>enemies_;//配列を作る
	std::vector<Weeds*>weeds_;
	void EnemyDefeated();
	void WeedDefeated();
private:
	int hModel_;//タンクの弾モデルのハンドル
	int enemyCount_;//現在生きている敵の数
	int weedCount_;
	
};

