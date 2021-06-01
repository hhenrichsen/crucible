#ifndef CRUCIBLE_LIB_SYSTEM_VELOCITYSYSTEM_HPP_
#define CRUCIBLE_LIB_SYSTEM_VELOCITYSYSTEM_HPP_

#include <entt/entt.hpp>

#include "baseSystem.hpp"

class VelocitySystem : public BaseSystem {
   public:
    VelocitySystem(entt::registry& reg) : BaseSystem(reg){};
    void update(double dt);
};

#endif  // CRUCIBLE_LIB_SYSTEM_VELOCITYSYSTEM_HPP_
