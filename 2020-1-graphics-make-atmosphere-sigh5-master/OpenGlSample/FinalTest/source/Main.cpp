#include "Renderer.h"
#include "Time.h"


#include "..//include/BackGround.h"
#include "..//include/FallingObj.h"
#include "..//FinalTest/include/Player.h"
#include "..//include/Restart.h"


#include "SampleNonRenderingObj.h"

#include "CompositeObj.h"



bool CheckCollision(CompositeObj* one, CompositeObj* two) 
{
	bool collisionX = one->position.x + 1.5 >= (two->position.x) / 1 &&
		(two->position.x) / 2 + 1 >= one->position.x;
	bool collisionY = one->position.y + 1.5 >= (two->position.y) / 1 &&
		(two->position.y) / 2 + 1 >= one->position.y;
	return collisionX && collisionY;
}

int main(void)
{
	Renderer* renderer = Renderer::instance();
	
	Player* player = new Player();
	BackGround* bg = new BackGround();
	Restart* restart = new Restart();
	
	vector<FallingObj*>* fallobj = new vector<FallingObj*>();

	for (int i = 0; i < 15; i++)
	{
		fallobj->push_back(new FallingObj());
	}

	renderer->init();

	player->setScale(0.2f, 0.2f, 0.2f);
	bg->setScale(5.0f, 5.0f, 0.1f);

	for (
		vector<FallingObj*>::const_iterator it = fallobj->begin();
		it != fallobj->end();
		++it
		)
	{
		(*it)->setScale(0.15f, 0.15f, 0.15f);
	}

	while (glfwGetKey(renderer->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer->window) == 0)
	{
		renderer->renderup();

		if (Time::GetInstance()->IsFixedRendering())
		{
			renderer->Update();
		}

		renderer ->render();

		for (
			vector<FallingObj*>::const_iterator it = fallobj->begin();
			it != fallobj->end();
			++it
			)
		{
			if (CheckCollision(player, (*it)))
			{
				player->setPos(40.0f, 40, 0);
				player->setLive(false);
				restart->setGameOver(false);
			}
		}

		if (restart->getGameOver() && player->getLive() == false)
		{
			player->init();

			for (
				vector<FallingObj*>::const_iterator it = fallobj->begin();
				it != fallobj->end();
				++it
				)
			{
				(*it)->init();
			}

		}

		renderer->renderdown();
	}

	renderer->shutDown();

	for (
		vector<FallingObj*>::const_iterator it = fallobj->begin();
		it != fallobj->end();
		++it
		)
	{
		delete (*it);
	}

	delete fallobj;
	delete player;
	delete bg;

	return 0;
}


//  충돌체크 참조
//https://m.blog.naver.com/PostView.nhn?blogId=enter_maintanance&logNo=220950165847&proxyReferer=https:%2F%2Fwww.google.com%2F