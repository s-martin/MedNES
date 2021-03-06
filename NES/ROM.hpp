#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <bitset>
#include "INESBus.hpp"

class Mapper;

struct INESHeader {
    //Header 16 byte
    char nes[4];
    u8 prgIn16kb;
    u8 chrIn8kb;
    u8 flags6;
    u8 flags7;
    u8 prgRamIn8kb;
    u8 flags9;
    u8 flags10;
    char zeros[5];
};

class ROM : public INESBus {
    
private:
    INESHeader header;
    std::vector<u8> trainer;
    std::vector<u8> prgCode;
    std::vector<u8> chrData;
    u8 chrRAM[8192];
    int mirroring;
    u8 mapperNum;
    
public:
    std::vector<u8> getChrData() { return chrData; };
    std::vector<u8> getPrgCode() { return prgCode; };
    void open(std::string);
    void printHeader();
    void loadTestProgramcode(std::vector<u8>);
    int getMirroring();
    Mapper* getMapper();
    
    //cpu address space
    u8* read(u16 address);
    void write(u16 address, u8 data);

    //ppu address space
    u8 ppuread(u16 address);
    void ppuwrite(u16 address, u8 data);
};
