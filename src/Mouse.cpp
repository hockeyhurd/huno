// Our includes
#include <huno/Mouse.h>

// raylib includes
#include <raylib.h>

namespace huno
{
    Mouse::Mouse() HCLIB_NOEXCEPT : cachedPos(0, 0), cachedLeftClicked(false), cachedMiddleClicked(false), cachedRightClicked(false)
    {
    }

    /* static */
    std::shared_ptr<Mouse> Mouse::instance()
    {
        static std::shared_ptr<Mouse> inst = nullptr;

        if (inst == nullptr)
        {
            inst = std::shared_ptr<Mouse>(new Mouse());
        }

        return inst;
    }

    Vec2<s32> Mouse::getPos() const HCLIB_NOEXCEPT
    {
        return cachedPos;
    }

    Vec2<f32> Mouse::getPosf() const HCLIB_NOEXCEPT
    {
        return Vec2<f32>(cachedPos.x, cachedPos.y);
    }

    bool Mouse::isLeftButtonClicked() const HCLIB_NOEXCEPT
    {
        return cachedLeftClicked;
    }

    bool Mouse::isMiddleButtonClicked() const HCLIB_NOEXCEPT
    {
        return cachedMiddleClicked;
    }

    bool Mouse::isRightButtonClicked() const HCLIB_NOEXCEPT
    {
        return cachedRightClicked;
    }

    void Mouse::update(const f32 deltaTime)
    {
        cachedPos.x = GetMouseX();
        cachedPos.y = GetMouseY();

#if 0
        cachedLeftClicked = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
        cachedMiddleClicked = IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON);
        cachedRightClicked = IsMouseButtonPressed(MOUSE_RIGHT_BUTTON);
#else
        cachedLeftClicked = IsMouseButtonDown(MOUSE_LEFT_BUTTON);
        cachedMiddleClicked = IsMouseButtonDown(MOUSE_MIDDLE_BUTTON);
        cachedRightClicked = IsMouseButtonDown(MOUSE_RIGHT_BUTTON);
#endif
    }
}

