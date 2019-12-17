#ifndef _502_hpp
#define _502_hpp

#include "Controller.hpp"
#include "PPU.hpp"
#include "RAM.hpp"
#include "ROM.hpp"
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>

struct ExecutionState {
    uint8_t accumulator;
    uint8_t xRegister;
    uint8_t yRegister;
    uint16_t programCounter;
    uint8_t stackPointer;
    uint8_t statusRegister;
    int cycle;
};

class CPU6502 {
    
private:
    //Arithmetic
    uint8_t accumulator = 0;
    uint8_t xRegister = 0;
    uint8_t yRegister = 0;
    
    //Other
    uint16_t programCounter = 0;
    uint8_t stackPointer = 0xFD;
    uint8_t statusRegister = 0x24;
    
    int cycle = 7;
    
    //Devices
    RAM ram;
    ROM* rom;
    PPU* ppu;
    Controller* controller;
    
    std::stringstream execLog;
    
    enum MemoryAccessMode {
        READ,
        WRITE
    };
    
    enum StatusFlags {
        NEGATIVE = 7,
        OVERFLO = 6,
        BREAK5 = 5,
        BREAK4 = 4,
        DECIMAL = 3,
        INTERRUPT = 2,
        ZERO = 1,
        CARRY = 0
    };
    
    inline void setSRFlag(StatusFlags, bool);
    inline void setNegative(bool);
    inline void setOverflow(bool);
    inline void setBreak4(bool);
    inline void setBreak5(bool);
    inline void setDecimal(bool);
    inline void setInterruptDisable(bool);
    inline void setZero(bool);
    inline void setCarry(bool);
    
    //vectors
    inline void irq();
    inline void NMI();
    
    inline void LOG_EXEC(uint8_t instr);
    
    inline void LOG_PC();
    
    inline void LOG_CPU_STATE();
    
    inline void PRINT_LOG();
    
    inline void tick();
    
    //stack
    void pushStack(uint8_t);
    
    uint8_t popStack();
    
    //addressing
    uint16_t immediate();
    
    uint16_t zeroPage();
    
    uint16_t zeroPageX();
    
    uint16_t zeroPageY();
    
    uint16_t absolute();
    
    uint16_t absoluteX(bool);
    
    uint16_t absoluteY(bool);
    
    uint16_t indirectX();
    
    uint16_t indirectY(bool);
    
    uint16_t relative();
    
    void ADC(const std::function<uint16_t()>&);
    
    void ADC(uint8_t); //for RRA
    
    //And with accumulator
    void AND(const std::function<uint16_t()>&);
    
    void AND(uint8_t); //for RLA
    
    //Arithmetic shift left
    void ASL(const std::function<uint16_t()>&);
    
    void ASL_val(uint8_t*); //for SLO
    
    //Branch on carry clear
    void BCC(std::function<uint16_t()>);
    
    //branch on carry set
    void BCS(std::function<uint16_t()>);
    
    //branch on equal (zero set)
    void BEQ(std::function<uint16_t()>);
    
    //Bit test
    void BIT(const std::function<uint16_t()>&);
    
    //Branch on minus (negative set)
    void BMI(std::function<uint16_t()>);
    
    //Branch on not equal (zero clear)
    void BNE(std::function<uint16_t()>);
    
    //Branch on plus (negative clear)
    void BPL(std::function<uint16_t()>);
    
    //Interrupt
    void BRK();
    
    //Branch on overflow clear
    void BVC(std::function<uint16_t()>);
    
    //Branch on overflow set
    void BVS(std::function<uint16_t()>);
    
    //Clear carry
    void CLC();
    
    //Clear decimal
    void CLD();
    
    //clear interrupt disable
    void CLI();
    
    //Clear overflow
    void CLV();
    
    //Compare (with accumulator}
    void CMP(const std::function<uint16_t()>&);
    
    void CMP(uint8_t); //for DCP
    
    //Compare with X
    void CPX(const std::function<uint16_t()>&);
    
    //Compare with Y
    void CPY(const std::function<uint16_t()>&);
    
    //Decrement
    void DEC(const std::function<uint16_t()>&);
    
    void DEC(uint8_t*); //for DCP
    
    //decrement X
    void DEX();
    
    //decrement Y
    void DEY();
    
    //Exclusive or (with accumulator)
    void EOR(const std::function<uint16_t()>&);
    
    void EOR(uint8_t); //for SRE
    
    //Increment
    void INC(const std::function<uint16_t()>&);
    
    void INC(uint8_t*); //for ISB
    
    //Increment X
    void INX();
    
    //Increment Y
    void INY();
    
    //Jump
    void JMP(const std::function<uint16_t()>&);
    
    //Jump subroutine
    void JSR(const std::function<uint16_t()>&);
    
    //Load accumulator
    void LDA(const std::function<uint16_t()>&);
    
    void LDA(uint8_t); //for LAX
    
    //Load X
    void LDX(const std::function<uint16_t()>&);
    
    void LDX(uint8_t); //for LAX
    
    //Load Y
    void LDY(const std::function<uint16_t()>&);
    
    //Logical shift right
    void LSR(const std::function<uint16_t()>&);
    
    void LSR_val(uint8_t*); //for SRE
    
    //Or with accumulator
    void ORA(const std::function<uint16_t()>&);
    
    void ORA(uint8_t); //for SLO
    
    //Push accumulator
    void PHA();
    
    //Push processor status (SR)
    void PHP();
    
    //Pull accumulator
    void PLA();
    
    //Pull processor status (SR)
    void PLP();
    
    //Rotate left
    void ROL(const std::function<uint16_t()>&);
    
    void ROL_val(uint8_t*);
    
    //Rotate right
    void ROR(const std::function<uint16_t()>&);
    
    void ROR_val(uint8_t*); //for RRA
    
    //Return from interrupt
    void RTI();
    
    //Return from subroutine
    void RTS();
    
    //Subtract with carrz
    void SBC(const std::function<uint16_t()>&);
    
    void SBC(uint8_t); //for ISB
    
    //Set carry
    void SEC();
    
    //Set decimal;
    void SED();
    
    //Set interrupt disable
    void SEI();
    
    //Store accumulator
    void STA(const std::function<uint16_t()>&);
    
    //Store X
    void STX(const std::function<uint16_t()>&);
    
    //Store Y
    void STY(const std::function<uint16_t()>&);
    
    //Transfer accumulator to X
    void TAX();
    
    //Transfer accumulator to Y
    void TAY();
    
    //Transfer stack pointer to X
    void TSX();
    
    //Transfer X to accumulator
    void TXA();
    
    //Transfer X to stack pointer
    void TXS();
    
    //Transfer Y to accumulator
    void TYA();
    
    //UNOFFICIAL ONES
    void NOP(const std::function<uint16_t()>&);
    
    void LAX(const std::function<uint16_t()>&);
    
    void SAX(const std::function<uint16_t()>&);
    
    void DCP(const std::function<uint16_t()>&);
    
    void ISB(const std::function<uint16_t()>&);
    
    void SLO(const std::function<uint16_t()>&);
    
    void RLA(const std::function<uint16_t()>&);
    
    void RRA(const std::function<uint16_t()>&);
    
    void SRE(const std::function<uint16_t()>&);
    
    void commonBranchLogic(bool, const std::function<uint16_t()>&);
    
    void tickIfToNewPage(uint16_t, uint16_t);
    
    inline void pushPC();
public:
    CPU6502(ROM* rom, PPU* ppu, Controller* controller) : rom(rom), ppu(ppu), controller(controller) { };
    uint8_t fetchInstruction();
    void executeInstruction(uint8_t);
    uint8_t* memoryAccess(MemoryAccessMode, uint16_t, uint8_t);
    uint8_t* read(uint16_t);
    void write(uint16_t, uint8_t);
    void run();
    void step();
    void reset();
    void setProgramCounter(uint16_t);
    ExecutionState* getExecutionState();
};

#endif /* _502_hpp */
