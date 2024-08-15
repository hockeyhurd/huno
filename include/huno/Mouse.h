#pragma once

#ifndef UNO_MOUSE_H
#define UNO_MOUSE_H

// HCLib includes
#include <hclib/Types.h>
#include <hclib/Vec2.h>

// std includes
#include <memory>

namespace huno
{
    using namespace hclib;

    class Mouse
    {
    private:

        Mouse() HCLIB_NOEXCEPT;

    public:

        Mouse(const Mouse&) = delete;
        Mouse(Mouse&&) HCLIB_NOEXCEPT = delete;
        ~Mouse() = default;

        Mouse& operator= (const Mouse&) = delete;
        Mouse& operator= (Mouse&&) HCLIB_NOEXCEPT = delete;

        static std::shared_ptr<Mouse> instance();

        Vec2<s32> getPos() const HCLIB_NOEXCEPT;
        Vec2<f32> getPosf() const HCLIB_NOEXCEPT;
        bool isLeftButtonClicked() const HCLIB_NOEXCEPT;
        bool isMiddleButtonClicked() const HCLIB_NOEXCEPT;
        bool isRightButtonClicked() const HCLIB_NOEXCEPT;

        void update(const float deltaTime);

    private:

        Vec2<s32> cachedPos;
        bool cachedLeftClicked;
        bool cachedMiddleClicked;
        bool cachedRightClicked;
    };
}

#endif //!UNO_MOUSE_H

