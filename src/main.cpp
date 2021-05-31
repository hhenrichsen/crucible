#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <cstdint>

struct position {
    float x;
    float y;
};

struct velocity {
    float dx;
    float dy;
};

struct shape {
    sf::RectangleShape rectangle;
    sf::Vector2f size;
};

void update(entt::registry& registry) {
    auto view = registry.view<const position, velocity>();

    for(auto entity: view) {
        // gets only the components that are going to be used ...

        auto &vel = view.get<velocity>(entity);

        vel.dx = 0.;
        vel.dy = 0.;

        // ...
    }
}

void update(std::uint64_t dt, entt::registry& registry) {
    registry.view<position, velocity>().each([dt](const auto entity, auto &pos, auto &vel) {
        // gets all the components of the view at once ...

        pos.x += vel.dx * dt;
        pos.y += vel.dy * dt;

        // ...
    });
}


int main() {
    entt::registry registry;
    std::uint64_t dt = 16;

    for(auto i = 0; i < 10; ++i) {
        const auto entity = registry.create();
        registry.emplace<position>(entity, i * 1.f, i * 1.f);
        if(i % 2 == 0) {
            registry.emplace<velocity>(entity, i * .1f, i * .1f);
        }
    }

    sf::RenderWindow sfmlWin(sf::VideoMode(600, 360), "Conan adventure begins!");

    while (sfmlWin.isOpen()) {

        sf::Event e;
        while (sfmlWin.pollEvent(e)) {

            switch (e.type) {
            case sf::Event::EventType::Closed:
                sfmlWin.close();
                break;
            }
        }

        update(dt, registry);
        update(registry);
        sfmlWin.clear(sf::Color(0, 116, 217));
        sfmlWin.display();
    }
    return 0;

}