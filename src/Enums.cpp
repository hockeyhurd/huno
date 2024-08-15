// Our includes
#include <huno/Enums.h>

namespace huno
{
    const char* toString(const EnumCardValue cardValue) HCLIB_NOEXCEPT
    {
        switch (cardValue)
        {
        case EnumCardValue::ZERO:
            return "0";
        case EnumCardValue::ONE:
            return "1";
        case EnumCardValue::TWO:
            return "2";
        case EnumCardValue::THREE:
            return "3";
        case EnumCardValue::FOUR:
            return "4";
        case EnumCardValue::FIVE:
            return "5";
        case EnumCardValue::SIX:
            return "6";
        case EnumCardValue::SEVEN:
            return "7";
        case EnumCardValue::EIGHT:
            return "8";
        case EnumCardValue::NINE:
            return "9";
        case EnumCardValue::PLUS_TWO:
            return "+2";
        case EnumCardValue::WILD:
            return "WILD";
        case EnumCardValue::WILD_PLUS_FOUR:
            return "WILD +4";
        default:
            return "<UNKNOWN EnumCardValue>";
        }
    }

    std::optional<EnumCardValue> ordinal(const u32 index) HCLIB_NOEXCEPT
    {
        if (index <= static_cast<u32>(EnumCardValue::WILD_PLUS_FOUR))
        {
            const auto result = static_cast<EnumCardValue>(index);
            return result;
        }

        return std::nullopt;
    }
}

