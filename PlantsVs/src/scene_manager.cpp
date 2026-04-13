#include "scene_manager.h"

SceneManager::SceneManager() {
    menu_scene = std::make_shared<MenuScene>();
    game_scene = std::make_shared<GameScene>();
    selector_scene = std::make_shared<SelectorScene>();

    menu_scene->setObserver(this);
    game_scene->setObserver(this);
    selector_scene->setObserver(this);

    changeScene(SceneType::Menu);
}

void SceneManager::changeScene(SceneType type) {
    if(current_scene) {
        current_scene->on_exit();
    }
    switch (type) {
    case SceneType::Menu:
        current_scene = menu_scene;
        break;
    case SceneType::Game:
        current_scene = game_scene;
        break;
    case SceneType::Selector:
        current_scene = selector_scene;
        break;
    default:
        break;
    }
    current_scene->on_enter();
}