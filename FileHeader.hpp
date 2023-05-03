///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 6 - readpe - SRE - Spring 2023
///
///
/// readpe - Read and display information about Portable Executable (PE) and Common Object File Format (COFF) files
///
///
/// @file    FileHeader.hpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <cstdio>

class FileHeader {

////////////////////  File Header Member Variables  ////////////////////
private:
    uint16_t    machine;
    uint16_t    numberOfSections;
    uint32_t    timeDateStamp;
    uint32_t    pointerToSymbolTable;
    uint32_t    numberOfSymbols;
    uint16_t    sizeOfOptionalHeader;
    uint16_t    characteristics;

////////////////////  Constructors  ////////////////////
public:
    FileHeader( uint8_t byteArray[20] );

////////////////////  Getters and Printing  ////////////////////
public:
    uint16_t getMachine();
    uint16_t getNumberOfSections();
    uint32_t getTimeDateStamp();
    uint32_t getPointerToSymbolTable();
    uint32_t getNumberOfSymbols();
    uint16_t getSizeOfOptionalHeader();
    uint16_t getCharacteristics();
    void     printFileHeaderInfo();

};