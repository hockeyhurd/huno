#pragma once

#ifndef UNO_BOARD_H
#define UNO_BOARD_H

// HCLib includes
#include <hclib/Types.h>

// std includes
#include <memory>
#include <vector>

namespace huno
{
    class Player;
    using namespace hclib;

    class Board
    {
    public:

        Board() HCLIB_NOEXCEPT;
        Board(const Board&) = default;
        Board(Board&&) HCLIB_NOEXCEPT = default;
        ~Board() = default;

        Board& operator= (const Board&) = default;
        Board& operator= (Board&&) HCLIB_NOEXCEPT = default;

        void reset(const u32 numPlayers);
        void render();
        void update(const f32 deltaTime);

    private:

        std::vector<std::shared_ptr<Player>> players;
        std::shared_ptr<Player> currentPlayersTurn;
    };
}

#endif //!UNO_BOARD_H

