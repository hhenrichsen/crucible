#ifndef CRUCIBLE_LIB_SYSTEM_BASESYSTEM_HPP_
#define CRUCIBLE_LIB_SYSTEM_BASESYSTEM_HPP_

#include <entt/entt.hpp>

class BaseSystem {
   protected:
    const entt::registry* registry = nullptr;

   public:
    BaseSystem(const entt::registry& reg) : registry(&reg){};
    virtual void update(double dt) = 0;
};

#endif  //   CRUCIBLE_LIB_SYSTEM_BASESYSTEM_HPP_