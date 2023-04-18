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

DosHeader::DosHeader( char dosLine[64] ) {

    std::string dos = dosLine;

    if( dos.substr(0,2).compare("ZM") ) {
        //Error
    }
    // Store each value into its respective char array as big endian bytes. Then can simply type cast to int if need to process.
    e_magic     = dos.substr(0,2);   std::reverse(std::begin(e_magic), std::end(e_magic));
    e_cblp      = dos.substr(2,2);   std::reverse(std::begin(e_cblp), std::end(e_cblp));
    e_cp        = dos.substr(4,2);   std::reverse(std::begin(e_cp), std::end(e_cp));
    e_crlc      = dos.substr(6,2);   std::reverse(std::begin(e_crlc), std::end(e_crlc));
    e_cparhdr   = dos.substr(8,2);   std::reverse(std::begin(e_cparhdr), std::end(e_cparhdr));
    e_minalloc  = dos.substr(10,2);  std::reverse(std::begin(e_minalloc), std::end(e_minalloc));
    e_maxalloc  = dos.substr(12,2);  std::reverse(std::begin(e_maxalloc), std::end(e_maxalloc));
    e_ss        = dos.substr(14,2);  std::reverse(std::begin(e_ss), std::end(e_ss));
    e_sp        = dos.substr(16,2);  std::reverse(std::begin(e_sp), std::end(e_sp));
    e_csum      = dos.substr(18,2);  std::reverse(std::begin(e_csum), std::end(e_csum));
    e_ip        = dos.substr(20,2);  std::reverse(std::begin(e_ip), std::end(e_ip));
    e_cs        = dos.substr(22,2);  std::reverse(std::begin(e_cs), std::end(e_cs));
    e_lfarlc    = dos.substr(24,2);  std::reverse(std::begin(e_lfarlc), std::end(e_lfarlc));
    e_ovno      = dos.substr(26,2);  std::reverse(std::begin(e_ovno), std::end(e_ovno));
    e_res1      = dos.substr(28,8);  std::reverse(std::begin(e_res1), std::end(e_res1));
    e_oemid     = dos.substr(36,2);  std::reverse(std::begin(e_oemid), std::end(e_oemid));
    e_oeminfo   = dos.substr(38,2);  std::reverse(std::begin(e_oeminfo), std::end(e_oeminfo));
    e_res2      = dos.substr(40,20); std::reverse(std::begin(e_res2), std::end(e_res2));
    e_lfanew    = dos.substr(60,4);  std::reverse(std::begin(e_lfanew), std::end(e_lfanew));

}

/*

for(i=0;i<strlen(str)/2;i++) {
    swap(str[i], str[sizeof(str) - i - 1]);
}


*/