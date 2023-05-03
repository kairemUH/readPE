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
#include <cassert>
#include <cstdio>
#include <cstring>

class DosHeader {

////////////////////  DOS Header Member Variables  ////////////////////
private:
    uint16_t    e_magic;              // Magic number. Should be set to 'MZ'
    uint16_t    e_cblp;               // Bytes on last page of file
    uint16_t    e_cp;                 // Pages in file
    uint16_t    e_crlc;               // Relocations
    uint16_t    e_cparhdr;            // Size of header in paragraphs
    uint16_t    e_minalloc;           // Minimum extra paragraphs needed
    uint16_t    e_maxalloc;           // Maximum extra paragraphs needed
    uint16_t    e_ss;                 // Initial (relative) SS value
    uint16_t    e_sp;                 // Initial SP value
    uint16_t    e_csum;               // Checksum
    uint16_t    e_ip;                 // Initial IP value
    uint16_t    e_cs;                 // Initial (relative) CS value
    uint16_t    e_lfarlc;             // File address of relocation table
    uint16_t    e_ovno;               // Overlay number
    uint16_t    e_res1[4];            // Reserved words. 4 words at 2 bytes each
    uint16_t    e_oemid;              // OEM identifier (for e_oeminfo)
    uint16_t    e_oeminfo;            // OEM information; e_oemid specific
    uint16_t    e_res2[10];           // Reserved words. 10 words at 2 bytes each
    uint32_t    e_lfanew;             // File address of new exe header

////////////////////  Constructors  ////////////////////
public:
    DosHeader( uint8_t dosLine[64] );

////////////////////  Getters and Printing  ////////////////////
public:
    uint16_t getMagic();
    uint32_t getElfanew();
    void printDosHeaderInfo();

};