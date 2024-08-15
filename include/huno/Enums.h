#pragma once

#ifndef UNO_ENUMS_H
#define UNO_ENUMS_H

// HCLib includes
#include <hclib/Types.h>

// std includes
#include <optional>

namespace huno
{
    using namespace hclib;

    enum class EnumColor
    {
        WILD = 0, BLUE, GREEN, RED, YELLOW
    };

    enum class EnumCardValue
    {
        ZERO = 0, ONE, TWO, THREE, FOUR,
        FIVE, SIX, SEVEN, EIGHT, NINE,
        PLUS_TWO, WILD, WILD_PLUS_FOUR
    };

    const char* toString(const EnumCardValue cardValue) HCLIB_NOEXCEPT;
    std::optional<EnumCardValue> ordinal(const u32 index) HCLIB_NOEXCEPT;
}

#endif //!UNO_ENUMS_H

