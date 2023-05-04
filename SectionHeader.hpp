///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 6 - readpe - SRE - Spring 2023
///
///
/// readpe - Read and display information about Portable Executable (PE) and Common Object File Format (COFF) files
/// 
///
/// @file    PEfile.hpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <cstring>

class SectionHeader {

////////////////////  Section Header Member Variables  ////////////////////
private:
    uint8_t     name[8];
    uint32_t    virtualSize;
    uint32_t    virtualAddress;
    uint32_t    sizeOfRawData;
    uint32_t    pointerToRawData;
    uint32_t    pointerToRelocations;
    uint32_t    pointerToLinenumbers;
    uint16_t    numberOfRelocations;
    uint16_t    numberOfLinenumbers;
    uint32_t    characteristics;

////////////////////  Constructors  ////////////////////
public:
    SectionHeader( uint8_t byteArray[40] );

////////////////////  Getters and Printing  ////////////////////
public:
    void printSectionHeaderInfo();

};