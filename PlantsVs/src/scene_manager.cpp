#include "scene_manager.h"

SceneManager::SceneManager() {
    menu_scene_ = std::make_unique<MenuScene>();
    game_scene_ = std::make_unique<GameScene>();
    selector_scene_ = std::make_unique<SelectorScene>();

    menu_scene_->SetObserver(this);
    game_scene_->SetObserver(this);
    selector_scene_->SetObserver(this);

    ChangeScene(SceneType::Menu);
}

void SceneManager::ChangeScene(SceneType type) {
    if(current_scene_) {
        current_scene_->OnExit();
    }
    switch (type) {
    case SceneType::Menu:
        current_scene_ = menu_scene_.get();
        break;
    case SceneType::Game:
        current_scene_ = game_scene_.get();
        break;
    case SceneType::Selector:
        current_scene_ = selector_scene_.get();
        break;
    default:
        break;
    }
    current_scene_->OnEnter();
}