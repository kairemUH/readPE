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

#include "SectionHeader.hpp"

SectionHeader::SectionHeader( uint8_t byteArray[40] ) {

    memcpy( &name,                  byteArray,      8 );
    memcpy( &virtualSize,           byteArray+8,    4 );
    memcpy( &virtualAddress,        byteArray+12,   4 );
    memcpy( &sizeOfRawData,         byteArray+16,   4 );
    memcpy( &pointerToRawData,      byteArray+20,   4 );
    memcpy( &pointerToRelocations,  byteArray+24,   4 );
    memcpy( &pointerToLinenumbers,  byteArray+28,   4 );
    memcpy( &numberOfRelocations,   byteArray+32,   2 );
    memcpy( &numberOfLinenumbers,   byteArray+34,   2 );
    memcpy( &characteristics,       byteArray+36,   4 );

}

void SectionHeader::printSectionHeaderInfo() {

    char str[33];
    printf( "    Section\n" );

    std::strcpy(str, "Name:");
    printf( "        %-33s%.8s\n", str, (char*)&name );

    std::strcpy(str, "Virtual Size:");
    printf( "        %-33s0x%x\n", str, virtualSize );         // @todo print out bytes for these

    std::strcpy(str, "Virtual Address:");
    printf( "        %-33s0x%x\n", str, virtualAddress );

    std::strcpy(str, "Size Of Raw Data:");
    printf( "        %-33s0x%x\n", str, sizeOfRawData );

    std::strcpy(str, "Pointer To Raw Data:");
    printf( "        %-33s0x%x\n", str, pointerToRawData );

    std::strcpy(str, "Number Of Relocations:");
    printf( "        %-33s%u\n", str, numberOfRelocations );

    std::strcpy(str, "Characteristics:");
    printf( "        %-33s0x%x\n", str, characteristics );

    std::strcpy(str, "Characteristics Names:");
    printf( "        %-33s\n", str );     // @todo print out characteristic names

}