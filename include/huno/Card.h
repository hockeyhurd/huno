#pragma once

#ifndef UNO_CARD_H
#define UNO_CARD_H

// Our includes
#include <huno/Enums.h>

// HCLib includes
#include <hclib/Types.h>
#include <hclib/Vec2.h>

namespace huno
{
    using namespace hclib;

    class Card
    {
    public:

        Card(const Vec2<f32> pos, const Vec2<f32> size, const bool hidden,
             const EnumColor color, const EnumCardValue cardValue) HCLIB_NOEXCEPT;
        Card(const Card&) = delete;
        Card(Card&&) HCLIB_NOEXCEPT = default;
        ~Card() = default;

        Card& operator= (const Card&) = delete;
        Card& operator= (Card&&) HCLIB_NOEXCEPT = default;

        Vec2<f32> getPosf() const HCLIB_NOEXCEPT;
        Vec2<f32> getSize() const HCLIB_NOEXCEPT;
        f32 getWidth() const HCLIB_NOEXCEPT;
        f32 getHeight() const HCLIB_NOEXCEPT;
        EnumColor getColor() const HCLIB_NOEXCEPT;
        EnumCardValue getCardValue() const HCLIB_NOEXCEPT;
        bool isHighlighted() const HCLIB_NOEXCEPT;

        void render();
        void update(const float deltaTime);

    private:

        Vec2<f32> pos;
        Vec2<f32> size;
        bool hidden;
        Vec2<f32> midpoint;
        EnumColor color;
        EnumCardValue cardValue;
        bool clicked;
        bool highlighted;
    };
}

#endif //!UNO_CARD_H

