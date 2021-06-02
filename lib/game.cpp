#include "game.hpp"

void Game::updateSystems(double dt) {
    for (auto system : this->systems) {
        if (system != nullptr) {
            system->update(dt);
        }
    }
}

void Game::init() { initRegistry(); }

Game::Game() { this->registry = new entt::registry(); }

Game::~Game() { delete this->registry; }

void Game::initRegistry() {}

void Game::update(double dt) { this->updateSystems(dt); }

const bool Game::isRunning() const { return this->running; }
