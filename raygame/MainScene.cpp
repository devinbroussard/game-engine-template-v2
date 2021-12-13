#include "MainScene.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "Transform2D.h"

void MainScene::start()
{
	Player* player = new Player(10, 10, "player", 100, 10);
	Enemy* enemy = new Enemy(10, 100, "enemy", 60, 10, player);
	player->getTransform()->setScale({ 50, 50 });

	addActor(player);
	addActor(enemy);
}
