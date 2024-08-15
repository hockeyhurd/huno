// Our includes
#include <huno/Card.h>
#include <huno/Mouse.h>
#include <huno/Utils.h>

// raylib includes
#include <raylib.h>

// std includes
#include <iostream>

namespace huno
{
    static constexpr f32 FONT_SIZE = 32.0F;

    Card::Card(const Vec2<f32> pos, const Vec2<f32> size, const bool hidden, const EnumColor color,
               const EnumCardValue cardValue) HCLIB_NOEXCEPT :
        pos(pos), size(size), midpoint(0.0F, 0.0F), color(color), cardValue(cardValue), highlighted(false)
    {
        this->midpoint.x = pos.x + (size.x / 2.0F);
        this->midpoint.y = pos.y + (size.y / 2.0F) - (FONT_SIZE / 2.0F);
    }

    Vec2<f32> Card::getPosf() const HCLIB_NOEXCEPT
    {
        return pos;
    }

    Vec2<f32> Card::getSize() const HCLIB_NOEXCEPT
    {
        return size;
    }

    f32 Card::getWidth() const HCLIB_NOEXCEPT
    {
        return size.x;
    }

    f32 Card::getHeight() const HCLIB_NOEXCEPT
    {
        return size.y;
    }

    EnumColor Card::getColor() const HCLIB_NOEXCEPT
    {
        return color;
    }

    EnumCardValue Card::getCardValue() const HCLIB_NOEXCEPT
    {
        return cardValue;
    }

    bool Card::isHighlighted() const HCLIB_NOEXCEPT
    {
        return highlighted;
    }

    void Card::render()
    {
        // void DrawRectangle(int posX, int posY, int width, int height, Color color);
        if (hidden)
        {
            DrawRectangle(pos.x, pos.y, size.x, size.y, BLACK);
        }

        else
        {
            DrawRectangle(pos.x, pos.y, size.x, size.y, BLUE);

            if (highlighted)
            {
                DrawRectangleLines(pos.x, pos.y, size.x, size.y, GOLD);
            }

            else
            {
                DrawRectangleLines(pos.x, pos.y, size.x, size.y, BLACK);
            }

            DrawText(huno::toString(cardValue), midpoint.x - 5.0F, midpoint.y, FONT_SIZE, WHITE);
        }
    }

    void Card::update(const f32 deltaTime)
    {
        const auto mousePtr = Mouse::instance();
        const Vec2<f32> mousePos = mousePtr->getPosf();
        const bool lastWasClicked = clicked;
        highlighted = false;

        if (huno::inBounds(pos, size, mousePos))
        {
            highlighted = true;

            const bool leftClick = mousePtr->isLeftButtonClicked();
            std::cout << "left button clicked: " << mousePtr->isLeftButtonClicked() << std::endl;

            if (leftClick && !lastWasClicked)
            {
                clicked = true;
                pos.y -= 10;
            }
        }

        else if (lastWasClicked)
        {
            clicked = false;
            pos.y += 10;
        }
    }
}

