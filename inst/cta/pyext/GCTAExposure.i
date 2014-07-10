/***************************************************************************
 *            GCTAExposure.hpp - CTA mean point spread function class       *
 * ----------------------------------------------------------------------- *
 *  copyright (C) 2014 by Chia-Chun Lu                                     *
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
 * @file GCTAExposure.hpp
 * @brief CTA mean point spread function class definition
 * @author Chia-Chun Lu
 */

%{
/* __ Includes ___________________________________________________________ */
#include "GCTAExposure.hpp"
#include "GTools.hpp"
%}

/***********************************************************************//**
 * @class GCTAExposure
 *
 * @brief Class of CTA exposure cube
 *
 * This class implements the CTA exposure cube
 *
 ***************************************************************************/
class GCTAExposure : public GBase {

public:
   
    // Constructors and destructors
    GCTAExposure(void);
    GCTAExposure(const GCTAExposure& exp);
    GCTAExposure(const GObservations& obs, 
		const double& x, const double& y, 
		const double& dx, const double& dy,
		const int& nx, const int& ny,
		const double& emin, const double& emax, const int& nebins);
    virtual ~GCTAExposure(void);

    // Operators
    GCTAExposure& operator=(const GCTAExposure& exp);

    // Methods
    void         clear(void);
    GCTAExposure* clone(void) const;
    void         load(const std::string& filename);
    void         write(GFits& file) const;
    void         save(const std::string& filename, 
		      const bool& clobber) const;
    std::string  print(const GChatter& chatter = NORMAL) const;
    const GSkymap& map(void) const;
    const GEbounds& ebounds(void) const;
   
};
%extend GCTAExposure {
};
