#pragma once
#include "StateStack.h"
#include "AssetsManger.h"
#include "InputManager.h"
#include <SFML/Graphics.hpp>

struct GameData {
    StateStack stateStack;
    sf::RenderWindow window;
    AssetsManger assetsManger;
    InputManager inputManager;
};
