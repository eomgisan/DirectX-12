#include "pch.h"
#include "Game.h"
#include "Engine.h"

void Game::Init(const WindowInfo& _window)
{
	GEngine->Init(_window);
}

void Game::Update()
{
	GEngine->Render();
}
