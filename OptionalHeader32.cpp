///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 6 - readpe - SRE - Spring 2023
///
///
/// readpe - Read and display information about Portable Executable (PE) and Common Object File Format (COFF) files
///
///
/// @file    OptionalHeader32.cpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "OptionalHeader32.hpp"

OptionalHeader32::OptionalHeader32( uint8_t byteArray[96] ) {

    memcpy( &magic,                         byteArray,      2 );

    // @todo test for magic being 32 bit

    memcpy( &majorLinkerVersion,            byteArray+2,    1 );
    memcpy( &minorLinkerVersion,            byteArray+3,    1 );
    memcpy( &sizeOfCode,                    byteArray+4,    4 );
    memcpy( &sizeOfInitializedData,         byteArray+8,    4 );
    memcpy( &sizeOfUninitializedData,       byteArray+12,   4 );
    memcpy( &addressOfEntryPoint,           byteArray+16,   4 );
    memcpy( &baseOfCode,                    byteArray+20,   4 );
    memcpy( &baseOfData,                    byteArray+24,   4 );
    memcpy( &imageBase,                     byteArray+28,   4 );
    memcpy( &sectionAlignment,              byteArray+32,   4 );
    memcpy( &fileAlignment,                 byteArray+36,   4 );
    memcpy( &majorOperatingSystemVersion,   byteArray+40,   2 );
    memcpy( &minorOperatingSystemVersion,   byteArray+42,   2 );
    memcpy( &majorImageVersion,             byteArray+44,   2 );
    memcpy( &minorImageVersion,             byteArray+46,   2 );
    memcpy( &majorSubsystemVersion,         byteArray+48,   2 );
    memcpy( &minorSubsystemVersion,         byteArray+50,   2 );
    memcpy( &win32VersionValue,             byteArray+52,   4 );
    memcpy( &sizeOfImage,                   byteArray+56,   4 );
    memcpy( &sizeOfHeaders,                 byteArray+60,   4 );
    memcpy( &checkSum,                      byteArray+64,   4 );
    memcpy( &subsystem,                     byteArray+68,   2 );
    memcpy( &dllCharacteristics,            byteArray+70,   2 );
    memcpy( &sizeOfStackReserve,            byteArray+72,   4 );
    memcpy( &sizeOfStackCommit,             byteArray+76,   4 );
    memcpy( &sizeOfHeapReserve,             byteArray+80,   4 );
    memcpy( &sizeOfHeapCommit,              byteArray+84,   4 );
    memcpy( &loaderFlags,                   byteArray+88,   4 );
    memcpy( &numberOfRvaAndSizes,           byteArray+92,   4 );

}

uint16_t OptionalHeader32::getMagic() {
    return magic;
}

void OptionalHeader32::printOptionalHeaderInfo() {

    char str[33];
    printf( "Optional/Image Header\n" );

    std::strcpy(str, "Magic number:");
    printf( "    %-33s0x%x (PE32)\n", str, magic );

    std::strcpy(str, "Linker major version:");
    printf( "    %-33s%u\n", str, majorLinkerVersion );

    std::strcpy(str, "Linker minor version:");
    printf( "    %-33s%u\n", str, minorLinkerVersion );

    std::strcpy(str, "Size of .text section:");
    printf( "    %-33s0x%x\n", str, sizeOfCode );

    std::strcpy(str, "Size of .data section:");
    printf( "    %-33s0x%x\n", str, sizeOfInitializedData );

    std::strcpy(str, "Size of .bss section:");
    printf( "    %-33s%u\n", str, sizeOfUninitializedData );

    std::strcpy(str, "Entrypoint:");
    printf( "    %-33s0x%x\n", str, addressOfEntryPoint );

    std::strcpy(str, "Address of .text section:");
    printf( "    %-33s0x%x\n", str, baseOfCode );

    std::strcpy(str, "Address of .data section:");
    printf( "    %-33s0x%x\n", str, baseOfData );

    std::strcpy(str, "Imagebase:");
    printf( "    %-33s0x%x\n", str, imageBase );

    std::strcpy(str, "Alignment of sections:");
    printf( "    %-33s0x%x\n", str, sectionAlignment );

    std::strcpy(str, "Alignment factor:");
    printf( "    %-33s0x%x\n", str, fileAlignment );

    std::strcpy(str, "Major version of required OS:");
    printf( "    %-33s%u\n", str, majorOperatingSystemVersion );

    std::strcpy(str, "Minor version of required OS:");
    printf( "    %-33s%u\n", str, minorOperatingSystemVersion );

    std::strcpy(str, "Major version of image:");
    printf( "    %-33s%u\n", str, majorImageVersion );

    std::strcpy(str, "Minor version of image:");
    printf( "    %-33s%u\n", str, minorImageVersion );

    std::strcpy(str, "Major version of subsystem:");
    printf( "    %-33s%u\n", str, majorSubsystemVersion );

    std::strcpy(str, "Minor version of subsystem:");
    printf( "    %-33s%u\n", str, minorSubsystemVersion );

    std::strcpy(str, "Size of image:");
    printf( "    %-33s0x%x\n", str, sizeOfImage );

    std::strcpy(str, "Size of headers:");
    printf( "    %-33s0x%x\n", str, sizeOfHeaders );

    std::strcpy(str, "Checksum:");
    printf( "    %-33s%u\n", str, checkSum );

    std::strcpy(str, "Subsystem required:");
    printf( "    %-33s0x%x\n", str, subsystem );

    std::strcpy(str, "DLL characteristics:");
    printf( "    %-33s0x%x\n", str, dllCharacteristics );

    std::strcpy(str, "DLL characteristics names:");     // @todo print characteristic names
    printf( "    %-33s\n", str );

    std::strcpy(str, "Size of stack to reserve:");
    printf( "    %-33s0x%x\n", str, sizeOfStackReserve );

    std::strcpy(str, "Size of stack to commit:");
    printf( "    %-33s0x%x\n", str, sizeOfStackCommit );

    std::strcpy(str, "Size of heap space to reserve:");
    printf( "    %-33s0x%x\n", str, sizeOfHeapReserve );

    std::strcpy(str, "Size of heap space to commit:");
    printf( "    %-33s0x%x\n", str, sizeOfHeapCommit );


}