#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(GDUMMenuLayer, MenuLayer) {

    bool init() {
        if (!MenuLayer::init())
            return false;

        auto menu = this->getChildByID("bottom-menu");

        if (menu) {
            auto sprite = ButtonSprite::create("ULTIMATE");

            auto button = CCMenuItemSpriteExtra::create(
                sprite,
                this,
                menu_selector(GDUMMenuLayer::openMenu)
            );

            button->setID("ultimate-menu-button");

            menu->addChild(button);
            menu->updateLayout();

            sprite->runAction(CCRepeatForever::create(
                CCSequence::create(
                    CCTintTo::create(0.5f, 255, 0, 0),
                    CCTintTo::create(0.5f, 0, 255, 0),
                    CCTintTo::create(0.5f, 0, 100, 255),
                    nullptr
                )
            ));
        }

        return true;
    }

    void openMenu(CCObject*) {
        FLAlertLayer::create(
            "GD ULTIMATE MENU",
            "Welcome to the ultimate RGB menu!\n\n"
            "PLAYER\n"
            "GAMEPLAY\n"
            "EDITOR\n"
            "VISUALS\n"
            "STATISTICS\n"
            "TOOLS\n"
            "SETTINGS",
            "CLOSE"
        )->show();
    }
};
