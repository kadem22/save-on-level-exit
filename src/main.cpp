#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(SaveOnExitPlayLayer, PlayLayer) {
    void onQuit() {
        PlayLayer::onQuit();

        if (auto app = AppDelegate::get()) {
            app->trySaveGame();
        }
    }
};
