/***************************************************************************
 *        GCTASourceCubeDiffuse.cpp - CTA diffuse source cube class        *
 * ----------------------------------------------------------------------- *
 *  copyright (C) 2014 by Juergen Knoedlseder                              *
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
 * @file GCTASourceCubeDiffuse.cpp
 * @brief CTA diffuse source cube class implementation
 * @author Juergen Knoedlseder
 */

/* __ Includes ___________________________________________________________ */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "GCTASourceCubeDiffuse.hpp"
#include "GModelSpatialDiffuse.hpp"
#include "GTools.hpp"
#include "GObservation.hpp"
#include "GCTAEventCube.hpp"
#include "GCTAResponseCube.hpp"

/* __ Method name definitions ____________________________________________ */
#define G_SET     "GCTASourceCubeDiffuse::set(GModelSpatial&, GObservation&)"

/* __ Macros _____________________________________________________________ */

/* __ Coding definitions _________________________________________________ */

/* __ Debug definitions __________________________________________________ */

/* __ Constants __________________________________________________________ */


/*==========================================================================
 =                                                                         =
 =                        Constructors/destructors                         =
 =                                                                         =
 ==========================================================================*/

/***********************************************************************//**
 * @brief Void constructor
 ***************************************************************************/
GCTASourceCubeDiffuse::GCTASourceCubeDiffuse(void) : GCTASourceCube()
{
    // Initialise class members
    init_members();

    // Return
    return;
}


/***********************************************************************//**
 * @brief Copy constructor
 *
 * @param[in] cube Diffuse source cube.
 ***************************************************************************/
GCTASourceCubeDiffuse::GCTASourceCubeDiffuse(const GCTASourceCubeDiffuse& cube) :
                       GCTASourceCube(cube)
{
    // Initialise class members
    init_members();

    // Copy members
    copy_members(cube);

    // Return
    return;
}


/***********************************************************************//**
 * @brief Destructor
 ***************************************************************************/
GCTASourceCubeDiffuse::~GCTASourceCubeDiffuse(void)
{
    // Free members
    free_members();

    // Return
    return;
}


/*==========================================================================
 =                                                                         =
 =                               Operators                                 =
 =                                                                         =
 ==========================================================================*/

/***********************************************************************//**
 * @brief Assignment operator
 *
 * @param[in] cube Diffuse source cube.
 * @return Diffuse source cube.
 ***************************************************************************/
GCTASourceCubeDiffuse& GCTASourceCubeDiffuse::operator=(const GCTASourceCubeDiffuse& cube)
{
    // Execute only if object is not identical
    if (this != &cube) {

        // Copy base class members
        this->GCTASourceCube::operator=(cube);

        // Free members
        free_members();

        // Initialise private members
        init_members();

        // Copy members
        copy_members(cube);

    } // endif: object was not identical

    // Return this object
    return *this;
}


/*==========================================================================
 =                                                                         =
 =                             Public methods                              =
 =                                                                         =
 ==========================================================================*/

/***********************************************************************//**
 * @brief Clear instance
 *
 * This method properly resets the object to an initial state.
 ***************************************************************************/
void GCTASourceCubeDiffuse::clear(void)
{
    // Free class members
    free_members();
    this->GCTASourceCube::free_members();

    // Initialise members
    this->GCTASourceCube::init_members();
    init_members();

    // Return
    return;
}


/***********************************************************************//**
 * @brief Clone instance
 *
 * @return Deep copy of diffuse source cube.
 ***************************************************************************/
GCTASourceCubeDiffuse* GCTASourceCubeDiffuse::clone(void) const
{
    // Return deep copy
    return new GCTASourceCubeDiffuse(*this);
}


/***********************************************************************//**
 * @brief Set diffuse source cube for a given observation
 *
 * @param[in] model Spatial model.
 * @param[in] obs Observation.
 ***************************************************************************/
void GCTASourceCubeDiffuse::set(const std::string&   name,
                                const GModelSpatial& model,
                                const GObservation&  obs)
{
    // Get pointer to model source model
    const GModelSpatialDiffuse* src = dynamic_cast<const GModelSpatialDiffuse*>(&model);
    if (src == NULL) {
        std::string msg = "Model is not a spatial diffuse source model.";
        throw GException::invalid_value(G_SET, msg);
    }

    // Get pointer on CTA event cube
    const GCTAEventCube* cube = dynamic_cast<const GCTAEventCube*>(obs.events());
    if (cube == NULL) {
        std::string msg = "Observation does not contain a CTA event cube.";
        throw GException::invalid_value(G_SET, msg);
    }

    // Get pointer on CTA response cube
    const GCTAResponseCube* rsp = dynamic_cast<const GCTAResponseCube*>(obs.response());
    if (rsp == NULL) {
        std::string msg = "Observation does not contain a CTA response cube.";
        throw GException::invalid_value(G_SET, msg);
    }

    // Get diffuse source attributes
    m_name        = name;
    GTime srcTime = cube->time();

    // Setup empty skymap
    m_cube = cube->map();
    m_cube = 0.0;

    //TODO: implement response computation

    // Return
    return;
}


/***********************************************************************//**
 * @brief Print diffuse source cube information
 *
 * @param[in] chatter Chattiness (defaults to NORMAL).
 * @return String containing diffuse source cube information.
 ***************************************************************************/
std::string GCTASourceCubeDiffuse::print(const GChatter& chatter) const
{
    // Initialise result string
    std::string result;

    // Continue only if chatter is not silent
    if (chatter != SILENT) {

        // Append header
        result.append("=== GCTASourceCubeDiffuse ===");
        result.append("\n"+gammalib::parformat("Source name") + name());

    } // endif: chatter was not silent

    // Return result
    return result;
}


/*==========================================================================
 =                                                                         =
 =                            Private methods                              =
 =                                                                         =
 ==========================================================================*/

/***********************************************************************//**
 * @brief Initialise class members
 ***************************************************************************/
void GCTASourceCubeDiffuse::init_members(void)
{
    // Initialise members
    m_cube.clear();
   
    // Return
    return;
}


/***********************************************************************//**
 * @brief Copy class members
 *
 * @param[in] cube Point diffuse cube.
 ***************************************************************************/
void GCTASourceCubeDiffuse::copy_members(const GCTASourceCubeDiffuse& cube)
{
    // Copy members
    m_cube = cube.m_cube;

    // Return
    return;
}

/***********************************************************************//**
 * @brief Delete class members
 ***************************************************************************/
void GCTASourceCubeDiffuse::free_members(void)
{
    // Return
    return;
}