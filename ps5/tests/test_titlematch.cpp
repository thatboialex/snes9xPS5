// Standalone regression tests for the shared filename matcher (no PS5 SDK required).
#include "../frontend/fe_titlematch.h"
#include <cassert>
#include <string>
#include <vector>
#include <iostream>
int main()
{
    using fe::titles::Best;
    const std::vector<std::string> art = {
        "Kidou Butouden G Gundam (Japan)",
        "Kidou Senshi V Gundam (Japan)",
        "Super Mario World (USA)",
        "Super Mario World 2 - Yoshi's Island (USA)",
        "Secret of Mana (USA)",
        "Secret of Mana 2 (Japan)",
        "Mega Man X (USA)"
    };
    assert(Best(art,"Kidou Butoden G-Gundam") == "Kidou Butouden G Gundam (Japan)");
    assert(Best(art,"Super Mario World (USA)") == "Super Mario World (USA)");
    assert(Best(art,"Mega-Man X.sfc") == "Mega Man X (USA)");
    assert(Best(art,"Completely Different Game (USA)").empty());
    assert(Best(art,"Secret of Mana 2 (Japan)") == "Secret of Mana 2 (Japan)");
    assert(Best(art,"Secret of Mana (USA)") == "Secret of Mana (USA)");
    const std::vector<std::string> cheats = {
        "Kidou Butouden G Gundam (Japan).cht",
        "Super Mario World (USA).cht",
        "Secret of Mana (USA) (Game Genie).cht"
    };
    assert(Best(cheats,"Kidou Butoden G-Gundam") == cheats[0]);
    assert(Best(cheats,"Super Mario World (USA)") == cheats[1]);
    assert(Best(cheats,"This Name Has No Match").empty());
    std::cout << "Title matcher regressions passed\n";
    return 0;
}
