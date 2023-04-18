///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 6 - readpe - SRE - Spring 2023
///
///
/// readpe - Read and display information about Portable Executable (PE) and Common Object File Format (COFF) files
///
///
/// @file    DosHeader.hpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>

class DosHeader {

////////////////////  DOS Header Member Variables  ////////////////////
private:
    char    e_magic[2];              // Magic number. Should be set to 0x5A4D
    char    e_cblp[2];               // Bytes on last page of file
    char    e_cp[2];                 // Pages in file
    char    e_crlc[2];               // Relocations
    char    e_cparhdr[2];            // Size of header in paragraphs
    char    e_minalloc[2];           // Minimum extra paragraphs needed
    char    e_maxalloc[2];           // Maximum extra paragraphs needed
    char    e_ss[2];                 // Initial (relative) SS value
    char    e_sp[2];                 // Initial SP value
    char    e_csum[2];               // Checksum
    char    e_ip[2];                 // Initial IP value
    char    e_cs[2];                 // Initial (relative) CS value
    char    e_lfarlc[2];             // File address of relocation table
    char    e_ovno[2];               // Overlay number
    char    e_res1[8];               // Reserved words. 4 words at 2 bytes each
    char    e_oemid[2];              // OEM identifier (for e_oeminfo)
    char    e_oeminfo[2];            // OEM information; e_oemid specific
    char    e_res2[20];              // Reserved words. 10 words at 2 bytes each
    char    e_lfanew[4];             // File address of new exe header

////////////////////  Constructors  ////////////////////
public:
    DosHeader( char dosLine[64] );

////////////////////  Getters and Printing  ////////////////////
public:
    void printDosHeaderInfo();
    char* get0x3c();


};