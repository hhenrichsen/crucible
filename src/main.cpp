#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>
#include <entt/entt.hpp>
#include <iostream>

#include "../lib/component/position.hpp"
#include "../lib/component/velocity.hpp"

static entt::registry registry;
static std::uint64_t dt = 0;
static std::uint64_t lastTime = 0;

void init() { std::cout << "Hello world!" << std::endl; }

int main() {
    init();

    for (auto i = 0; i < 10; ++i) {
        const auto entity = registry.create();
        registry.emplace<Position>(entity, i * 1.f, i * 1.f);
        if (i % 2 == 0) {
            registry.emplace<Velocity>(entity, i * .1f, i * .1f);
        }
    }

    sf::RenderWindow window(sf::VideoMode(600, 360), "Crucible",
                            sf::Style::Titlebar | sf::Style::Close);
    sf::Event e;

    while (window.isOpen()) {
        while (window.pollEvent(e)) {
            switch (e.type) {
                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (e.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    break;
            }
        }

        window.clear(sf::Color(0, 116, 217));
        window.display();
    }
    return 0;
}