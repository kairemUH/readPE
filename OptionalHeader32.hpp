///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 6 - readpe - SRE - Spring 2023
///
///
/// readpe - Read and display information about Portable Executable (PE) and Common Object File Format (COFF) files
///
///
/// @file    OptionalHeader32.hpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <cstring>

class OptionalHeader32 {

////////////////////  Optional Header Member Variables  ////////////////////
private:
    uint16_t    magic;
    uint8_t     majorLinkerVersion;
    uint8_t     minorLinkerVersion;
    uint32_t    sizeOfCode;
    uint32_t    sizeOfInitializedData;
    uint32_t    sizeOfUninitializedData;
    uint32_t    addressOfEntryPoint;
    uint32_t    baseOfCode;
    uint32_t    baseOfData;

    uint32_t    imageBase;
    uint32_t    sectionAlignment;
    uint32_t    fileAlignment;
    uint16_t    majorOperatingSystemVersion;
    uint16_t    minorOperatingSystemVersion;
    uint16_t    majorImageVersion;
    uint16_t    minorImageVersion;
    uint16_t    majorSubsystemVersion;
    uint16_t    minorSubsystemVersion;
    uint32_t    win32VersionValue;
    uint32_t    sizeOfImage;
    uint32_t    sizeOfHeaders;
    uint32_t    checkSum;
    uint16_t    subsystem;
    uint16_t    dllCharacteristics;
    uint32_t    sizeOfStackReserve;
    uint32_t    sizeOfStackCommit;
    uint32_t    sizeOfHeapReserve;
    uint32_t    sizeOfHeapCommit;
    uint32_t    loaderFlags;
    uint32_t    numberOfRvaAndSizes;

////////////////////  Constructors  ////////////////////
public:
    OptionalHeader32( uint8_t byteArray[96] );

////////////////////  Getters and Printing  ////////////////////
public:
    uint16_t getMagic();
    void printOptionalHeaderInfo();
    
};