#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>
#include <entt/entt.hpp>
#include <iostream>

#include "../lib/component/position.hpp"
#include "../lib/component/velocity.hpp"
#include "../lib/render/GraphicsGame.hpp"

static entt::registry registry;
static std::uint64_t dt = 0;
static std::uint64_t lastTime = 0;
static GraphicsGame game("Crucible", 600, 400);

int main() {
    game.init();
    while (game.isRunning()) {
        game.update(0);
    }
    return 0;
}