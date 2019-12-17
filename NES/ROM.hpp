#ifndef ROM_hpp
#define ROM_hpp

#include "INESBus.hpp"
#include <bitset>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

struct INESHeader {
    //Header 16 byte
    char nes[4];
    uint8_t prgIn16kb;
    uint8_t chrIn8kb;
    uint8_t flags6;
    uint8_t flags7;
    uint8_t prgRamIn8kb;
    uint8_t flags9;
    uint8_t flags10;
    char zeros[5];
};

class ROM : public INESBus {
    
private:
    INESHeader header;
    std::vector<uint8_t> trainer;
    std::vector<uint8_t> prgCode;
    std::vector<uint8_t> chrData;
    uint8_t chrRAM[8192];
    int mirroring;
    
public:
    std::vector<uint8_t> getChrData() { return chrData; };
    void open(const std::string&);
    void printHeader();
    void loadTestProgramcode(std::vector<uint8_t>);
    int getMirroring();
    
    //cpu address space
    uint8_t* read(uint16_t address) override;
    void write(uint16_t address, uint8_t data) override;
    
    //ppu address space
    uint8_t ppuread(uint16_t address);
    void ppuwrite(uint16_t address, uint8_t data);
};

#endif /* ROM_hpp */
