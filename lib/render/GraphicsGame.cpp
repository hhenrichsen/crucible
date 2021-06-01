#include "GraphicsGame.hpp"

void GraphicsGame::initWindow() {
    this->videoMode.width = this->width;
    this->videoMode.height = this->height;

    this->window = new sf::RenderWindow(this->videoMode, this->name);
}

void GraphicsGame::checkEvents() {
    while (this->window->pollEvent((this->windowEvent))) {
        switch (this->windowEvent.type) {
            case sf::Event::EventType::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->windowEvent.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
        }
    }
}

GraphicsGame::GraphicsGame(std::string name, int width, int height)
    : Game(), name(name), width(width), height(height) {}

GraphicsGame::~GraphicsGame() { delete this->window; }

void GraphicsGame::init() {
    Game::init();
    this->initWindow();
}

void GraphicsGame::render(double dt) {
    this->window->clear(sf::Color(0, 116, 217));
    for (auto sys : this->graphicSystems) {
        sys->update(dt);
    }
    this->window->display();
}

void GraphicsGame::update(double dt) {
    this->checkEvents();
    Game::update(dt);
    this->render(dt);
}

void GraphicsGame::addGraphicSystem(BaseSystem* system) {
    if (system != nullptr) {
        this->graphicSystems.emplace_back(system);
    }
}

const bool GraphicsGame::isRunning() const { return this->window->isOpen(); }
