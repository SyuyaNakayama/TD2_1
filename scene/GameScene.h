﻿#pragma once

#include <vector>
#include "Audio.h"
#include "DirectXCommon.h"
#include "DebugText.h"
#include "DebugCamera.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "player/Player.h"
#include "stage/Wall.h"
#include "Collider/CollisionManager.h"
#include "Fade/Fade.h"
#include "enum.h"
#include "animationManager/AnimationManager.h"
#include "uiDrawer/UIDrawer.h"
#include "skydome/Skydome.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {
public: // メンバ関数
	/// <summary>
	/// 初期化
	 /// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	DebugText* debugText_ = nullptr;
	Model* model_;
	std::vector<Sprite*> sceneSprite_;
	ViewProjection viewProjection_;
	ViewProjection mapCamera_;
	uint32_t stage_ = 1;
	CollisionManager collisionManager_;
	Scene scene_ = Scene::Play;
	Player player_;
	WallManager wallManager_;
	Fade fadeManager_;
	AnimationManager animationManager_;
	UIDrawer uiDrawer_;
	Skydome background_;
};
