#pragma once
#include "Engine\\GameObject.h"
class Weeds :
    public GameObject
{
public:
	//コンストラクタ
	Weeds(GameObject* parent);
	//デストラクタ
	~Weeds() {}//インライン定義
	//初期化
	void Initialize() override;
	//更新
	void Update() override;
	//描画
	void Draw() override;
	//開放
	void Release() override;

	void OnCollision(GameObject* pTarget);

private:
	int hModel_;//タンクの弾モデルのハンドル
	int enemyPos_;

};

