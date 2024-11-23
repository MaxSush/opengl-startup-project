#include "Game.h"

#include "../Window/KeyListner.h"

#include <iostream>

Breaker::Game::Game()
{
}

Breaker::Game::~Game()
{
	ResourceManager::Clear();
	delete render;
}

void Breaker::Game::Init()
{
	ResourceManager::LoadShader("assets/cubeShader.vs", "assets/cubeShader.fg", "cube");
	ResourceManager::LoadTexture("assets/brick.png", true, "brick");
	render = new SpriteRenderer(ResourceManager::GetShader("cube"));
}

void Breaker::Game::Update(float dt)
{
	if (KeyListner::isKeyPressed(GLFW_KEY_W))
	{
		std::cout << "Pressed \n";
	}
}

void Breaker::Game::Render()
{
	render->DrawSprite(ResourceManager::GetTexture("brick"), {10,10}, {100,50});
}
