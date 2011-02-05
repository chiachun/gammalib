/***************************************************************************
 *               GPar.i - Application parameter class SWIG file            *
 * ----------------------------------------------------------------------- *
 *  copyright (C) 2010-2011 by Jurgen Knodlseder                           *
 * ----------------------------------------------------------------------- *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
/**
 * @file GPar.i
 * @brief Application parameter class SWIG file.
 * @author Jurgen Knodlseder
 */
%{
/* Put headers and other declarations here that are needed for compilation */
#include "GPar.hpp"
#include "GTools.hpp"
%}


/***********************************************************************//**
 * @class GPar
 *
 * @brief Application parameter class Python interface defintion
 ***************************************************************************/
class GPar {
public:
    // Constructors and destructors
    GPar(void);
    explicit GPar(const std::string& name, const std::string& type,
                  const std::string& mode, const std::string& value,
                  const std::string& min, const std::string& max, 
                  const std::string& prompt);
    GPar(const GPar& par);
    virtual ~GPar(void);
 
    // Methods
    void        type(const std::string& type);
    void        mode(const std::string& mode);
    void        value(const std::string& value);
    void        string(const std::string& value);
    void        filename(const std::string& value);
    void        boolean(const bool& value);
    void        integer(const int& value);
    void        real(const double& value);
    std::string name(void) const;
    std::string type(void) const;
    std::string mode(void) const;
    std::string value(void);
    std::string string(void);
    std::string filename(void);
    bool        boolean(void);
    int         integer(void);
    double      real(void);
    std::string min(void) const;
    std::string max(void) const;
    std::string prompt(void) const;
    bool        islearn(void) const;
    bool        isquery(void) const;
    bool        isfilename(void) const;
};


/***********************************************************************//**
 * @brief GPar class extension
 ***************************************************************************/
%extend GPar {
    char *__str__() {
        return tochar(self->print());
    }
    GPar copy() {
        return (*self);
    }
}
