#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>
#include <iostream>

#include "../lib/component/position.hpp"
#include "../lib/component/velocity.hpp"
#include "../lib/render/GraphicsGame.hpp"
#include "../lib/system/velocitySystem.hpp"

static std::uint64_t dt = 0;
static std::uint64_t lastTime = 0;
static GraphicsGame game("Crucible", 600, 400);

int main() {
    game.init();
    game.addSystem<VelocitySystem>();
    while (game.isRunning()) {
        game.update(0);
    }
    return 0;
}