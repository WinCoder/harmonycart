//=========================================================================
//
//  H   H    A    RRRR   M   M   OOO   N   N  Y   Y
//  H   H   A A   R   R  MM MM  O   O  NN  N   Y Y
//  HHHHH  AAAAA  RRRR   M M M  O   O  N N N    Y   "Harmony Cart software"
//  H   H  A   A  R R    M   M  O   O  N  NN    Y
//  H   H  A   A  R  R   M   M   OOO   N   N    Y
//
// Copyright (c) 2009-2017 by Stephen Anthony <sa666666@gmail.com>
//
// See the file "License.txt" for information on usage and redistribution
// of this file, and for a DISCLAIMER OF ALL WARRANTIES.
//
// $Id$
//=========================================================================

#ifndef __CART_DETECTOR_HXX
#define __CART_DETECTOR_HXX

#include "bspf_harmony.hxx"
#include "BSType.hxx"

/**
  Auto-detect cart type.
  Based on auto-detection code from Stella (https://stella-emu.github.io)

  @author  Stephen Anthony
*/
class CartDetector
{
  public:
    /**
      Try to auto-detect the bankswitching type of the cartridge,
      based first on filename, then on actual file content

      @param rom    The file containing the ROM image
      @param image  A pointer to the ROM image (may be null)
      @param size   The size of the ROM image (may be 0)
      @return  The "best guess" for the cartridge type
    */
    static BSType autodetectType(const string& rom, const uInt8* image = 0, uInt32 size = 0);

  private:
    /**
      Try to auto-detect the bankswitching type of the cartridge
      based on the filename extensions as defined in the Harmony
      manual

      @param rom  The file containing the ROM image
      @return  The "best guess" for the cartridge type
    */
    static BSType autodetectTypeByExtension(const string& rom);

    /**
      Try to auto-detect the bankswitching type of the cartridge
      based on an analysis of the ROM data (from Stella)

      @param rom  The file containing the ROM image
      @return  The "best guess" for the cartridge type
    */
    static BSType autodetectTypeByContent(const uInt8* image, uInt32 size);

    /**
      Search the image for the specified byte signature

      @param image      A pointer to the ROM image
      @param imagesize  The size of the ROM image
      @param signature  The byte sequence to search for
      @param sigsize    The number of bytes in the signature
      @param minhits    The minimum number of times a signature is to be found

      @return  True if the signature was found at least 'minhits' time, else false
    */
    static bool searchForBytes(const uInt8* image, uInt32 imagesize,
                               const uInt8* signature, uInt32 sigsize,
                               uInt32 minhits);

    /**
      Returns true if the image is probably a SuperChip (256 bytes RAM)
    */
    static bool isProbablySC(const uInt8* image, uInt32 size);

    /**
      Returns true if the image probably contains ARM code in the first 1K
    */
    static bool isProbablyARM(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a 0840 bankswitching cartridge
    */
    static bool isProbably0840(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a 3E bankswitching cartridge
    */
    static bool isProbably3E(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a 3F bankswitching cartridge
    */
    static bool isProbably3F(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a 4A50 bankswitching cartridge
    */
    static bool isProbably4A50(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a CTY bankswitching cartridge
    */
    static bool isProbablyCTY(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a CV bankswitching cartridge
    */
    static bool isProbablyCV(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a DPC+ bankswitching cartridge
    */
    static bool isProbablyDPCplus(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a E0 bankswitching cartridge
    */
    static bool isProbablyE0(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a E7 bankswitching cartridge
    */
    static bool isProbablyE7(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably an EF/EFSC bankswitching cartridge
    */
    static bool isProbablyEF(const uInt8* image, uInt32 size, BSType& type);

    /**
      Returns true if the image is probably an F6 bankswitching cartridge
    */
    static bool isProbablyF6(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably an FA2 bankswitching cartridge
    */
    static bool isProbablyFA2(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably an FE bankswitching cartridge
    */
    static bool isProbablyFE(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a SB bankswitching cartridge
    */
    static bool isProbablySB(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably a UA bankswitching cartridge
    */
    static bool isProbablyUA(const uInt8* image, uInt32 size);

    /**
      Returns true if the image is probably an X07 bankswitching cartridge
    */
    static bool isProbablyX07(const uInt8* image, uInt32 size);
};

#endif
