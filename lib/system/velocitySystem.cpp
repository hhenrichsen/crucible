#include "velocitySystem.hpp"

#include "../component/position.hpp"
#include "../component/velocity.hpp"

void VelocitySystem::update(double dt) {
    auto view = this->registry->view<const Velocity, Position>();
    for (auto ent : view) {
        auto pos = view.get<Position>(ent);
        auto velocity = view.get<const Velocity>(ent);

        pos.x += velocity.dx * dt;
        pos.y += velocity.dy * dt;
    }
}