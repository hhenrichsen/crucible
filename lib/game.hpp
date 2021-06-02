#ifndef CRUCIBLE_LIB_GAME_HPP_
#define CRUCIBLE_LIB_GAME_HPP_

#include <entt/entt.hpp>
#include <functional>
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
    const bool isRunning() const;
    template <class T, class... Args>
    void addSystem(Args&&... args) {
        static_assert(std::is_base_of<BaseSystem, T>::value,
                      "Trying to add a non-system.");
        this->systems.emplace_back(
            new T(registry, std::forward<Args>(args)...));
    }
};

#endif  // CRUCIBLE_LIB_GAME_HPP_