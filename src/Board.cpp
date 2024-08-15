// Our includes
#include <huno/Board.h>
#include <huno/Player.h>

// HCLib includes
#include <hclib/Vec2.h>

namespace huno
{
    Board::Board() HCLIB_NOEXCEPT : players(), currentPlayersTurn(nullptr)
    {
        players.reserve(4);
    }

    void Board::reset(const u32 numPlayers)
    {
        players.clear();

        u32 uuid = 0;
        players.emplace_back(std::make_shared<Player>(Vec2<f32>(200, 25), uuid++, false));
        currentPlayersTurn = players[0];
    }

    void Board::render()
    {
        for (auto player : players)
        {
            player->render();
        }
    }

    void Board::update(const f32 deltaTime)
    {
        for (auto player : players)
        {
            player->update(deltaTime);
        }
    }
}

