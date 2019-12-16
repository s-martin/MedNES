#ifndef Controller_hpp
#define Controller_hpp

#include "INESBus.hpp"
#include <cstdio>
#include <string>

#include <SDL2/SDL.h>
class Controller : INESBus {
    uint8_t JOY1 = 0;
    uint8_t JOY2 = 0;
    uint8_t btnStateLocked = 0;
    uint8_t btnState = 0;
    bool strobe;
    
public:
    //Bus
    uint8_t* read(uint16_t address) override;
    void write(uint16_t address, uint8_t data) override;
    
    //Input
    void setButtonPressed(SDL_Keycode, bool);
    
};
#endif /* Controller_hpp */
