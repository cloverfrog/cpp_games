#include "scene_manager.h"

namespace PlantsVs {
SceneManager::SceneManager() {
    menu_scene_ = std::make_unique<MenuScene>();
    game_scene_ = std::make_unique<GameScene>();
    selector_scene_ = std::make_unique<SelectorScene>();

    menu_scene_->SetChangeSceneCallback([this](SceneType type){ ChangeScene(type); });
    game_scene_->SetChangeSceneCallback([this](SceneType type){ ChangeScene(type); });
    selector_scene_->SetChangeSceneCallback([this](SceneType type){ ChangeScene(type); });

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
}