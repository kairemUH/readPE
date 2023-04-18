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

class PeFile {

////////////////////  DOS Header Member Variables  ////////////////////
private:
    Dosheader;
    char PEsignature[4];
    CoffHeader;
    OptionalHeader;
    SectionTable;

////////////////////  Constructors  ////////////////////
public:


////////////////////  Getters  ////////////////////
public:
    char* getPEsignature();

};