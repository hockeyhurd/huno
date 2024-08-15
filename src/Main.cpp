// Our includes
#include <huno/Game.h>

// HCLib includes
#include <hclib/Types.h>

using namespace hclib;
using namespace huno;

int main(int argc, char* argv[])
{
    auto game = Game::instance();
    const s32 exitCode = game->launch();

    return exitCode;
}

