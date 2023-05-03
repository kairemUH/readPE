///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 6 - readpe - SRE - Spring 2023
///
///
/// readpe - Read and display information about Portable Executable (PE) and Common Object File Format (COFF) files
///
///
/// @file    DosHeader.cpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "DosHeader.hpp"

////////////////////  Constructors  ////////////////////
DosHeader::DosHeader( uint8_t byteArray[64] ) {

    // Store each value into its respective section.
    memcpy( &e_magic,    byteArray,     2 );

    if( e_magic != 0x5A4D ) {
        //@todo print error
    }

    memcpy( &e_cblp,     byteArray+2,   2 );
    memcpy( &e_cp,       byteArray+4,   2 );
    memcpy( &e_crlc,     byteArray+6,   2 );
    memcpy( &e_cparhdr,  byteArray+8,   2 );
    memcpy( &e_minalloc, byteArray+10,  2 );
    memcpy( &e_maxalloc, byteArray+12,  2 );
    memcpy( &e_ss,       byteArray+14,  2 );
    memcpy( &e_sp,       byteArray+16,  2 );
    memcpy( &e_csum,     byteArray+18,  2 );
    memcpy( &e_ip,       byteArray+20,  2 );
    memcpy( &e_cs,       byteArray+22,  2 );
    memcpy( &e_lfarlc,   byteArray+24,  2 );
    memcpy( &e_ovno,     byteArray+26,  2 );
    memcpy( &e_res1,     byteArray+28,  8 );
    memcpy( &e_oemid,    byteArray+36,  2 );
    memcpy( &e_oeminfo,  byteArray+38,  2 );
    memcpy( &e_res2,     byteArray+40, 20 );
    memcpy( &e_lfanew,   byteArray+60,  4 );

}

////////////////////  Getters and Printing  ////////////////////
uint16_t DosHeader::getMagic() {
    return DosHeader::e_magic;
}

uint32_t DosHeader::getElfanew() {
    return DosHeader::e_lfanew;
}

void DosHeader::printDosHeaderInfo() {

    char str[33];
    printf( "DOS Header\n" );

    std::strcpy(str, "Magic number:");
    printf( "    %-33s0x%x (%.2s)\n", str, e_magic, (char*)&e_magic );

    std::strcpy(str, "Bytes in last page:");
    printf( "    %-33s%u\n", str, e_cblp );

    std::strcpy(str, "Pages in file:");
    printf( "    %-33s%u\n", str, e_cp );

    std::strcpy(str, "Relocations:");
    printf( "    %-33s%u\n", str, e_crlc );

    std::strcpy(str, "Size of header in paragraphs:");
    printf( "    %-33s%u\n", str, e_cparhdr );

    std::strcpy(str, "Minimum extra paragraphs:");
    printf( "    %-33s%u\n", str, e_minalloc );

    std::strcpy(str, "Maximum extra paragraphs:");
    printf( "    %-33s%u\n", str, e_maxalloc );

    std::strcpy(str, "Initial (relative) SS value:");
    printf( "    %-33s%u\n", str, e_ss );

    std::strcpy(str, "Initial SP value:");
    printf( "    %-33s0x%x\n", str, e_sp );

    std::strcpy(str, "Initial IP value:");
    printf( "    %-33s%u\n", str, e_ip );

    std::strcpy(str, "Initial (relative) CS value:");
    printf( "    %-33s%u\n", str, e_cs );

    std::strcpy(str, "Address of relocation table:");
    printf( "    %-33s0x%x\n", str, e_lfarlc );

    std::strcpy(str, "Overlay number:");
    printf( "    %-33s%u\n", str, e_ovno );

    std::strcpy(str, "OEM identifier:");
    printf( "    %-33s%u\n", str, e_oemid );

    std::strcpy(str, "OEM information:");
    printf( "    %-33s%u\n", str, e_oeminfo );

    std::strcpy(str, "PE header offset:");
    printf( "    %-33s0x%x\n", str, e_lfanew );

}