#pragma once
#include "StateStack.h"
#include "AssetsManger.h"
#include <SFML/Graphics.hpp>

struct GameData {
    StateStack stateStack;
    sf::RenderWindow window;
    AssetsManger assetsManger;
};
