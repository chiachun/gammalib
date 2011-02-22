/***************************************************************************
 *       GModelRadialGauss.i  -  Radial Gaussian source model class        *
 * ----------------------------------------------------------------------- *
 *  copyright (C) 2011 by Jurgen Knodlseder                                *
 * ----------------------------------------------------------------------- *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
/**
 * @file GModelRadialGauss.i
 * @brief Radial Gaussian model class Python interface definition
 * @author J. Knodlseder
 */
%{
/* Put headers and other declarations here that are needed for compilation */
#include "GModelRadialGauss.hpp"
#include "GTools.hpp"
%}


/***********************************************************************//**
 * @class GModelRadialGauss
 *
 * @brief Radial Gaussian model class
 ***************************************************************************/
class GModelRadialGauss : public GModelRadial {

public:
    // Constructors and destructors
    GModelRadialGauss(void);
    explicit GModelRadialGauss(const GSkyDir& dir, const double& sigma);
    explicit GModelRadialGauss(const GXmlElement& xml);
    GModelRadialGauss(const GModelRadialGauss& model);
    virtual ~GModelRadialGauss(void);

    // Implemented pure virtual methods
    virtual void               clear(void);
    virtual GModelRadialGauss* clone(void) const;
    virtual std::string        type(void) const;
    virtual double             eval(const double& theta) const;
    virtual double             eval_gradients(const double& theta) const;
    virtual GSkyDir            mc(GRan& ran) const;
    virtual double             theta_max(void) const;
    virtual void               read(const GXmlElement& xml);
    virtual void               write(GXmlElement& xml) const;

    // Other methods
    double  sigma(void) const;
    void    sigma(const double& sigma);
};


/***********************************************************************//**
 * @brief GModelRadialGauss class extension
 ***************************************************************************/
%extend GModelRadialGauss {
    GModelRadialGauss copy() {
        return (*self);
    }
};


/***********************************************************************//**
 * @brief GModelRadialGauss type casts
 ***************************************************************************/
%inline %{
    GModelRadialGauss* cast_GModelRadialGauss(GModelSpatial* model) {
        return dynamic_cast<GModelRadialGauss*>(model);
    }
%};