///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 6 - readpe - SRE - Spring 2023
///
///
/// readpe - Read and display information about Portable Executable (PE) and Common Object File Format (COFF) files
///
///
/// @file    FileHeader.cpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "FileHeader.hpp"


////////////////////  Constructors  ////////////////////
FileHeader::FileHeader( uint8_t byteArray[20] ) {

    memcpy( &machine,               byteArray,     2 );
    memcpy( &numberOfSections,      byteArray+2,   2 );
    memcpy( &timeDateStamp,         byteArray+4,   4 );
    memcpy( &pointerToSymbolTable,  byteArray+8,   4 );
    memcpy( &numberOfSymbols,       byteArray+12,  4 );
    memcpy( &sizeOfOptionalHeader,  byteArray+16,  2 );
    memcpy( &characteristics,       byteArray+18,  2 );
    
}

////////////////////  Getters and Printing  ////////////////////
uint16_t FileHeader::getMachine() {
    return FileHeader::machine;
}

uint16_t FileHeader::getNumberOfSections() {
    return FileHeader::numberOfSections;
}

uint32_t FileHeader::getTimeDateStamp() {
    return FileHeader::timeDateStamp;
}

uint32_t FileHeader::getPointerToSymbolTable() {
    return FileHeader::pointerToSymbolTable;
}

uint32_t FileHeader::getNumberOfSymbols() {
    return FileHeader::numberOfSymbols;
}

uint16_t FileHeader::getSizeOfOptionalHeader() {
    return FileHeader::sizeOfOptionalHeader;
}

uint16_t FileHeader::getCharacteristics() {
    return FileHeader::characteristics;
}

void FileHeader::printFileHeaderInfo() {

    char str[33];
    printf( "COFF/File header\n" );

    std::strcpy(str, "Machine:");
    printf( "    %-33s0x%x\n", str, machine );      // @todo print machine type

    std::strcpy(str, "Number of sections:");
    printf( "    %-33s%u\n", str, numberOfSections );

    std::strcpy(str, "Date/time stamp:");
    printf( "    %-33s0x%x\n", str, timeDateStamp );    // @todo print time

    std::strcpy(str, "Symbol Table offset:");
    printf( "    %-33s0x%x\n", str, pointerToSymbolTable );

    std::strcpy(str, "Number of symbols:");
    printf( "    %-33s0x%x\n", str, numberOfSymbols );

    std::strcpy(str, "Size of optional header:");
    printf( "    %-33s0x%x\n", str, sizeOfOptionalHeader );

    std::strcpy(str, "Characteristics:");
    printf( "    %-33s0x%x\n", str, characteristics );
    
    std::strcpy(str, "Characteristics names:");
    printf( "    %-33s\n", str );
    // @todo print characteristic names

}