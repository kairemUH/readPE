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
#include "FileHeader.hpp"

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

    uint8_t dosHeaderArray[64];
    PEFile.read( (char*)dosHeaderArray, 64 );
    DosHeader testDosHeader = DosHeader( dosHeaderArray );
    testDosHeader.printDosHeaderInfo();

    PEFile.seekg( testDosHeader.getElfanew(), ios::beg );    // Go to the file offset specified at elfanew 
                                                          // from the beginning of the file

    uint8_t signature[4];
    PEFile.read( (char*)signature, 4 );
    if( !( signature[0] == 'P' && signature[1] == 'E' && signature[2] == '\0' && signature[3] == '\0' ) ) {

        // @todo print error message
        exit(EXIT_FAILURE);

    }

    uint8_t fileHeaderArray[20];
    PEFile.read( (char*)fileHeaderArray, 20 );                       
    FileHeader testFileHeader = FileHeader( fileHeaderArray );
    testFileHeader.printFileHeaderInfo();

    return 0;
}