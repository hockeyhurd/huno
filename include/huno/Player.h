#pragma once

#ifndef UNO_PLAYER_H
#define UNO_PLAYER_H

// Our includes
#include <huno/Card.h>

// HCLib includes
#include <hclib/Types.h>
#include <hclib/Vec2.h>

// std includes
#include <vector>

namespace huno
{
    using namespace hclib;

    class Player
    {
    public:

        Player(const Vec2<f32> pos, const u32 uuid, const bool hidden) HCLIB_NOEXCEPT;
        Player(const Player&) = default;
        Player(Player&&) HCLIB_NOEXCEPT = default;
        ~Player() = default;

        Player& operator= (const Player&) = default;
        Player& operator= (Player&&) HCLIB_NOEXCEPT = default;

        void render();
        void update(const f32 deltaTime);

    private:

        Vec2<f32> pos;
        [[maybe_unused]] u32 uuid;
        [[maybe_unused]] bool hidden;
        std::vector<Card> cardsInHand;
    };
}

#endif //!UNO_PLAYER_H

