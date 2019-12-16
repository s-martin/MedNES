#ifndef RAM_hpp
#define RAM_hpp

#include "INESBus.hpp"
#include <cstdint>
#include <cstdio>

class RAM : public INESBus {
    
//256 byte pages, 8 pages on internal NES RAM
private:
    uint8_t ram[2048] = {0};
    
public:
    uint8_t* read(uint16_t address) override;
    void write(uint16_t address, uint8_t data) override;
};

#endif /* RAM_hpp */
