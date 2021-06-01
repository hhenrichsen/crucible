#ifndef CRUCIBLE_LIB_RENDER_GRAPHICSGAME_HPP_
#define CRUCIBLE_LIB_RENDER_GRAPHICSGAME_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "../game.hpp"

class GraphicsGame : public Game {
   private:
    int width;
    int height;
    std::string name;

    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event windowEvent;

    std::vector<BaseSystem*> graphicSystems;

    void initWindow();
    void checkEvents();

   public:
    GraphicsGame(std::string name, int width, int height);
    virtual ~GraphicsGame();

    void init();
    void render(double dt);
    void update(double dt);
    void addGraphicSystem(BaseSystem* system);
    const bool isRunning() const;
};

#endif  // CRUCIBLE_LIB_RENDER_GRAPHICSGAME_HPP_