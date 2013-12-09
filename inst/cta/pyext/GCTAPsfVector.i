/***************************************************************************
 *        GCTAPsfVector.i - CTA point spread function vector class         *
 * ----------------------------------------------------------------------- *
 *  copyright (C) 2012 by Juergen Knoedlseder                              *
 * ----------------------------------------------------------------------- *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/
/**
 * @file GCTAPsfVector.i
 * @brief CTA point spread function vector class definition
 * @author Juergen Knoedlseder
 */
%{
/* Put headers and other declarations here that are needed for compilation */
#include "GCTAPsfVector.hpp"
#include "GTools.hpp"
%}


/***********************************************************************//**
 * @class GCTAPsfVector
 *
 * @brief CTA vector point spread function class
 *
 * This class implements the CTA point spread function response as function
 * of energy as determined from a FITS table.
 ***************************************************************************/
class GCTAPsfVector : public GCTAPsf {

public:
    // Constructors and destructors
    GCTAPsfVector(void);
    GCTAPsfVector(const std::string& filename);
    GCTAPsfVector(const GCTAPsfVector& psf);
    virtual ~GCTAPsfVector(void);

    // Operators
    double operator()(const double& delta,
                      const double& logE, 
                      const double& theta = 0.0, 
                      const double& phi = 0.0,
                      const double& zenith = 0.0,
                      const double& azimuth = 0.0,
                      const bool&   etrue = true) const;

    // Implemented pure virtual methods
    void           clear(void);
    GCTAPsfVector* clone(void) const;
    void           load(const std::string& filename);
    std::string    filename(void) const;
    double         mc(GRan&         ran,
                      const double& logE, 
                      const double& theta = 0.0, 
                      const double& phi = 0.0,
                      const double& zenith = 0.0,
                      const double& azimuth = 0.0,
                      const bool&   etrue = true) const;
    double         delta_max(const double& logE, 
                             const double& theta = 0.0, 
                             const double& phi = 0.0,
                             const double& zenith = 0.0,
                             const double& azimuth = 0.0,
                             const bool&   etrue = true) const;

    // Other methods
    void read(const GFitsTable& table);
};


/***********************************************************************//**
 * @brief GCTAPsfVector class extension
 ***************************************************************************/
%extend GCTAPsfVector {
    GCTAPsfVector copy() {
        return (*self);
    }
};
