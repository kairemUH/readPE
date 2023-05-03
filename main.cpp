///////////////////////////////////////////////////////////////////////////////
///          University of Hawaii, College of Engineering
///          Lab 6 - readpe - SRE - Spring 2023
///
///
/// readpe - Read and display information about Portable Executable (PE) and Common Object File Format (COFF) files
///
///
/// @file    main.cpp
/// @author  Kai Matsusaka <kairem@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <fstream>

#include "DosHeader.hpp"

using namespace std;

int main( int argc, char* argv[] ) {

    // @todo send all errors to stderr

    //////////  Error checking  //////////

    if( argc < 2 ) {

        printf( "Error: No file specified.\n" );

        exit(EXIT_FAILURE);

    }

    if( argc > 2 ) {

        printf("Error: Too many arguments.\n");

        exit(EXIT_FAILURE);

    }

    /// Open the PE file in read only mode
    ifstream PEFile;

    PEFile.open( argv[1], ios::in );

    if( !PEFile ) {

        cout << "Error: could not open file [" << argv[1] << "]." << endl;

        exit(EXIT_FAILURE);

    }

    uint8_t byteArray[64];

    PEFile.read( (char*)byteArray, 64 );

    DosHeader testHeader = DosHeader( byteArray );

    testHeader.printDosHeaderInfo();

    return 0;
}