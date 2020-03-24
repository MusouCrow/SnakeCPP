#include "core.h"

int main() {
    auto core = Core("SnakeCPP", 1280, 720);
    
    while (true) {
        core.Update();
        core.Draw();
    }
    
    return 0;
}
