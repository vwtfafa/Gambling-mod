#pragma once

#include <Geode/Geode.hpp>
#include <Geode/binding/RewardUnlockLayer.hpp>

#include "RewardBox.hpp"

class RollingLayer : public cocos2d::CCLayerColor {
public:
    cocos2d::CCLayer* m_contentLayer = nullptr;
    RewardUnlockLayer* m_unlockLayer = nullptr;
    cocos2d::CCMenu* m_itemsMenu = nullptr;
    cocos2d::CCDrawNode* m_lineNode = nullptr;
    cocos2d::CCNode* m_backgroundGlow = nullptr;
    float m_timeElapsed = 0.f;
    float m_startX = 0.f;
    float m_moveAmountX = 0.f;
    cocos2d::CCPoint m_linePos = cocos2d::CCPointZero;
    RewardBox* m_hoveringBox = nullptr;
    bool m_isGold = false;
    bool m_finished = false;
    bool m_closed = false;
    int m_smoothFix = 2;
    geode::ListenerHandle m_inputEvent;

public:
    struct RewardMeta {
        int min;
        int max;
    };

public:
    bool init(RewardUnlockLayer* unlockLayer);
    void begin();
    RewardBox* getTargetBox();
    void setupTargetBox();
    CurrencySpriteType rewardToSpriteType(SpecialRewardItem item);
    cocos2d::ccColor3B rarityColorForRewardItem(GJRewardItem* item);
    void createRewardBoxes();
    void scatterRewards();
    void setupRewardBoxWithItem(RewardBox* box, GJRewardItem* item);
    void moveToRewardX(float newX);
    void startAnimation();
    void animationFinished();
    RewardMeta rewardMetaForRewardType(GJRewardType rewardType);
    float rewardBoxHeight();
    cocos2d::CCMenu* createMenuFromRewardObjects(cocos2d::CCArray* rewardObjects);
    void closeAndAward();

    void update(float dt) override;
    void onExit() override;

    static RollingLayer* create(RewardUnlockLayer* unlockLayer);
};