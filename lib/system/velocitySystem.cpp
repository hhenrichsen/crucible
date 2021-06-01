#include "velocitySystem.hpp"

#include "../component/position.hpp"
#include "../component/velocity.hpp"

void VelocitySystem::update(double dt) {
    auto view = this->registry->view<Position, Velocity>();
    for (const entt::entity entity : view) {
        Position& position = view.get<Position>(entity);
        Velocity& velocity = view.get<Velocity>(entity);

        position.x += velocity.dx * dt;
        position.y += velocity.dy * dt;
    }
}