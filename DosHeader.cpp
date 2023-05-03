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
DosHeader::DosHeader( uint8_t dosLine[64] ) {

    // Store each value into its respective section.
    memcpy(&e_magic,    dosLine,     2);

    if( e_magic != 0x5A4D ) {
        //@todo print error
    }

    memcpy(&e_cblp,     dosLine+2,   2);
    memcpy(&e_cp,       dosLine+4,   2);
    memcpy(&e_crlc,     dosLine+6,   2);
    memcpy(&e_cparhdr,  dosLine+8,   2);
    memcpy(&e_minalloc, dosLine+10,  2);
    memcpy(&e_maxalloc, dosLine+12,  2);
    memcpy(&e_ss,       dosLine+14,  2);
    memcpy(&e_sp,       dosLine+16,  2);
    memcpy(&e_csum,     dosLine+18,  2);
    memcpy(&e_ip,       dosLine+20,  2);
    memcpy(&e_cs,       dosLine+22,  2);
    memcpy(&e_lfarlc,   dosLine+24,  2);
    memcpy(&e_ovno,     dosLine+26,  2);
    memcpy(&e_res1,     dosLine+28,  8);
    memcpy(&e_oemid,    dosLine+36,  2);
    memcpy(&e_oeminfo,  dosLine+38,  2);
    memcpy(&e_res2,     dosLine+40, 20);
    memcpy(&e_lfanew,   dosLine+60,  4);

}

////////////////////  Getters and Printing  ////////////////////
uint16_t DosHeader::getMagic() {
    return DosHeader::e_magic;
}

uint32_t DosHeader::getElfanew() {
    return DosHeader::e_lfanew;
}

void DosHeader::printDosHeaderInfo() {
    std::string str;
    printf( "DOS Header\n" );
    str = "Magic number:";
    printf( "    %-33s%x (%.2s)\n", str, e_magic, (char*)&e_magic );
    str = "Bytes in last page:";
    printf( "    %-33s%u \n", str, e_cblp );
    str = "Pages in file:";
    printf( "    %-33s%u \n", str, e_cp );
    str = "Relocations:";
    printf( "    %-33s%u \n", str, e_crlc );
    str = "Size of header in paragraphs:";
    printf( "    %-33s%u \n", str, e_cparhdr );
    str = "Minimum extra paragraphs:";
    printf( "    %-33s%u \n", str, e_minalloc );
    str = "Maximum extra paragraphs:";
    printf( "    %-33s%u \n", str, e_maxalloc );
    str = "Initial (relative) SS value:";
    printf( "    %-33s%u \n", str, e_ss );
    str = "Initial SP value:";
    printf( "    %-33s%x \n", str, e_sp );
    str = "Initial IP value:";
    printf( "    %-33s%u \n", str, e_ip );
    str = "Initial (relative) CS value:";
    printf( "    %-33s%u \n", str, e_cs );
    str = "Address of relocation table:";
    printf( "    %-33s%x \n", str, e_lfarlc );
    str = "Overlay number:";
    printf( "    %-33s%u \n", str, e_ovno );
    str = "OEM identifier:";
    printf( "    %-33s%u \n", str, e_oemid );
    str = "OEM information:";
    printf( "    %-33s%u \n", str, e_oeminfo );
    str = "PE header offset:";
    printf( "    %-33s%x \n", str, e_lfanew );

}