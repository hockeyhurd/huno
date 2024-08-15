#pragma once

#ifndef UNO_UTILS_H
#define UNO_UTILS_H

// HCLib includes
#include <hclib/Types.h>
#include <hclib/Vec2.h>

namespace huno
{
    template<class T>
    bool inBounds(const hclib::Vec2<T>& pos, const hclib::Vec2<T>& size, const hclib::Vec2<T>& pos2)
    {
        const bool result = (pos.x <= pos2.x && pos2.x <= pos.x + size.x) &&
                            (pos.y <= pos2.y && pos2.y <= pos.y + size.y);
        return result;
    }
}

#endif //!UNO_UTILS_H

