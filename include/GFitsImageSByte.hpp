/***************************************************************************
 *           GFitsImageSByte.hpp  - FITS signed Byte image class           *
 * ----------------------------------------------------------------------- *
 *  copyright (C) 2010 by Jurgen Knodlseder                                *
 * ----------------------------------------------------------------------- *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
/**
 * @file GFitsImageSByte.hpp
 * @brief GFitsImageSByte class definition.
 * @author J. Knodlseder
 */

#ifndef GFITSIMAGESBYTE_HPP
#define GFITSIMAGESBYTE_HPP

/* __ Includes ___________________________________________________________ */
#include "GFitsImage.hpp"


/***********************************************************************//**
 * @class GFitsImageSByte
 *
 * @brief Implements a FITS signed Byte image
 ***************************************************************************/
class GFitsImageSByte : public GFitsImage {

public:
    // Constructors and destructors
    GFitsImageSByte(void);
    explicit GFitsImageSByte(int nx, const char* pixels = NULL);
    explicit GFitsImageSByte(int nx, int ny, const char* pixels = NULL);
    explicit GFitsImageSByte(int nx, int ny, int nz, const char* pixels = NULL);
    explicit GFitsImageSByte(int nx, int ny, int nz, int nt, const char* pixels = NULL);
    explicit GFitsImageSByte(int naxis, const int* naxes, const char* pixels = NULL);
    GFitsImageSByte(const GFitsImageSByte& image);
    virtual ~GFitsImageSByte(void);

    // Operators
    GFitsImageSByte& operator= (const GFitsImageSByte& image);
    char&            operator() (const int& ix);
    char&            operator() (const int& ix, const int& iy);
    char&            operator() (const int& ix, const int& iy, const int& iz);
    char&            operator() (const int& ix, const int& iy, const int& iz, const int& it);
    const char&      operator() (const int& ix) const;
    const char&      operator() (const int& ix, const int& iy) const;
    const char&      operator() (const int& ix, const int& iy, const int& iz) const;
    const char&      operator() (const int& ix, const int& iy, const int& iz, const int& it) const;

    // Methods
    char&            at(const int& ix);
    char&            at(const int& ix, const int& iy);
    char&            at(const int& ix, const int& iy, const int& iz);
    char&            at(const int& ix, const int& iy, const int& iz, const int& it);
    const char&      at(const int& ix) const;
    const char&      at(const int& ix, const int& iy) const;
    const char&      at(const int& ix, const int& iy, const int& iz) const;
    const char&      at(const int& ix, const int& iy, const int& iz, const int& it) const;
    double           pixel(const int& ix) const;
    double           pixel(const int& ix, const int& iy) const;
    double           pixel(const int& ix, const int& iy, const int& iz) const;
    double           pixel(const int& ix, const int& iy, const int& iz, const int& it) const;
    void*            pixels(void);
    int              type(void) const;
    GFitsImageSByte* clone(void) const;

private:
    // Private methods
    void  init_members(void);
    void  copy_members(const GFitsImageSByte& image);
    void  free_members(void);
    void  alloc_data(void);
    void  init_data(void);
    void  release_data(void);
    void  construct_data(const char* pixels);
    void  alloc_nulval(const void* value);
    void* ptr_data(void) { return m_pixels; }
    void* ptr_nulval(void) { return m_nulval; }

    // Private data area
    char* m_pixels;      //!< Pixels
    char* m_nulval;      //!< NULL value
};

#endif /* GFITSIMAGESBYTE_HPP */
