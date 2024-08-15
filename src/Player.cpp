// Our includes
#include <huno/Player.h>
#include <huno/Game.h>

// std includes
#include <cassert>

namespace huno
{
    Player::Player(const Vec2<f32> pos, const u32 uuid, const bool hidden) HCLIB_NOEXCEPT :
        pos(pos), uuid(uuid), hidden(hidden)
    {
        cardsInHand.reserve(0x10);

        // auto game = Game::instance();
        // const f32 boardWidth = game->getWidth();
        // const f32 boardHeight = game->getHeight();
        static const Vec2<f32> cardSize = { 100, 150 };
        Vec2<f32> cardPos = this->pos;
        constexpr f32 spacingX = 10.0F;
        constexpr u32 initialHandSize = 7;

        for (u32 i = 0; i < initialHandSize; ++i)
        {
            const auto cardValueOpt = ordinal(i);
            assert(cardValueOpt.has_value());

            cardsInHand.emplace_back(cardPos, cardSize, uuid != 0, EnumColor::BLUE, *cardValueOpt);
            cardPos.x += spacingX + cardSize.x;
        }
    }

    void Player::render()
    {
        for (auto& card : cardsInHand)
        {
            card.render();
        }
    }

    void Player::update(const f32 deltaTime)
    {
        for (auto& card : cardsInHand)
        {
            card.update(deltaTime);
        }
    }
}

