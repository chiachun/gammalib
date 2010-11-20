/***************************************************************************
 *    GFitsTableBitCol.i  - FITS table bit column class SWIG definition    *
 * ----------------------------------------------------------------------- *
 *  copyright : (C) 2010 by Jurgen Knodlseder                              *
 * ----------------------------------------------------------------------- *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
/**
 * @file GFitsTableBitCol.i
 * @brief GFitsTableBitCol class SWIG file.
 * @author J. Knodlseder
 */
%{
/* Put headers and other declarations here that are needed for compilation */
#include "GFitsTableBitCol.hpp"
%}


/***********************************************************************//**
 * @class GFitsTableBitCol
 *
 * @brief SWIG interface for FITS table logical column
 ***************************************************************************/
class GFitsTableBitCol : public GFitsTableCol {
public:
    // Constructors and destructors
    GFitsTableBitCol(void);
    GFitsTableBitCol(const std::string& name, const int& length,
                     const int& size = 1);
    GFitsTableBitCol(const GFitsTableBitCol& column);
    virtual ~GFitsTableBitCol(void);

    // Methods
    std::string    string(const int& row, const int& col = 0);
    double         real(const int& row, const int& col = 0);
    int            integer(const int& row, const int& col = 0);
    unsigned char* data(void) { return m_data; }
    void           nulval(const unsigned char* value);
    unsigned char* nulval(void) { return m_nulval; }
};


/***********************************************************************//**
 * @brief GFitsTableBitCol class extension
 ***************************************************************************/
%extend GFitsTableBitCol {
    bool __getitem__(int GFitsTableColInx[]) {
        if (GFitsTableColInx[0] == 1)
            return (*self)(GFitsTableColInx[1]);
        else if (GFitsTableColInx[0] == 2)
            return (*self)(GFitsTableColInx[1], GFitsTableColInx[2]);
        else {
            PyErr_SetString(PyExc_ValueError,"Too many arguments in tuple");
            return NULL;
        }
    }
    void __setitem__(int GFitsTableColInx[], bool value) {
        if (GFitsTableColInx[0] == 1)
            (*self)(GFitsTableColInx[1]) = value;
        else if (GFitsTableColInx[0] == 2)
            (*self)(GFitsTableColInx[1], GFitsTableColInx[2]) = value;
        else {
            PyErr_SetString(PyExc_ValueError,"Too many arguments in tuple");
            return;
        }
    }
    GFitsTableBitCol copy() {
        return (*self);
    }
};
