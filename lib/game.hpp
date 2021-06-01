#ifndef CRUCIBLE_LIB_GAME_HPP_
#define CRUCIBLE_LIB_GAME_HPP_

#include <entt/entt.hpp>
#include <vector>

#include "system/baseSystem.hpp"

class Game {
   private:
    std::vector<BaseSystem*> systems;
    entt::registry* registry;

   protected:
    bool running = false;

    void updateSystems(double dt);
    void initRegistry();

   public:
    Game();
    virtual ~Game();

    void init();
    void update(double dt);
    void addSystem(BaseSystem* system);
    const bool isRunning() const;
};

#endif  // CRUCIBLE_LIB_GAME_HPP_