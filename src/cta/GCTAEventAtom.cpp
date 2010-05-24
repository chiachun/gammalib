/***************************************************************************
 *               GCTAEventAtom.cpp  -  CTA event atom class                *
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
 * @file GCTAEventAtom.cpp
 * @brief GCTAEventAtom class implementation.
 * @author J. Knodlseder
 */

/* __ Includes ___________________________________________________________ */
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <iostream>
#include "GException.hpp"
#include "GCTAEventAtom.hpp"

/* __ Method name definitions ____________________________________________ */
#define G_MODEL                    "GCTAEventAtom::model(GModels&, GVector*)"
#define G_COPY_MEMBERS    "GCTAEventAtom::copy_members(const GCTAEventAtom&)"

/* __ Macros _____________________________________________________________ */

/* __ Coding definitions _________________________________________________ */

/* __ Debug definitions __________________________________________________ */


/*==========================================================================
 =                                                                         =
 =                         Constructors/destructors                        =
 =                                                                         =
 ==========================================================================*/

/***********************************************************************//**
 * @brief Constructor
 ***************************************************************************/
GCTAEventAtom::GCTAEventAtom() : GEventAtom()
{
    // Initialise class members for clean destruction
    init_members();

    // Return
    return;
}


/***********************************************************************//**
 * @brief Copy constructor
 *
 * @param[in] atom Event atom from which the instance should be built.
 ***************************************************************************/
GCTAEventAtom::GCTAEventAtom(const GCTAEventAtom& atom) : GEventAtom(atom)
{
    // Initialise class members for clean destruction
    init_members();

    // Copy members
    copy_members(atom);

    // Return
    return;
}


/***********************************************************************//**
 * @brief Destructor
 ***************************************************************************/
GCTAEventAtom::~GCTAEventAtom()
{
    // Free members
    free_members();

    // Return
    return;
}


/*==========================================================================
 =                                                                         =
 =                                Operators                                =
 =                                                                         =
 ==========================================================================*/

/***********************************************************************//**
 * @brief Assignment operator
 *
 * @param[in] atom Event atom which should be assigned.
 ***************************************************************************/
GCTAEventAtom& GCTAEventAtom::operator= (const GCTAEventAtom& atom)
{
    // Execute only if object is not identical
    if (this != &atom) {

        // Copy base class members
        this->GEventAtom::operator=(atom);

        // Free members
        free_members();

        // Initialise private members for clean destruction
        init_members();

        // Copy members
        copy_members(atom);

    } // endif: object was not identical

    // Return this object
    return *this;
}


/*==========================================================================
 =                                                                         =
 =                              Public methods                             =
 =                                                                         =
 ==========================================================================*/

/***********************************************************************//**
 * @brief Return model value
 *
 * @param[in] models Model descriptor.
 *
 * @todo Add CTA specific code (so far only dummy)
 ***************************************************************************/
double GCTAEventAtom::model(GModels& models)
{
    // Set model value
    double model = models.eval(dir(), energy(), time());
    
    // Return
    return model;
}


/***********************************************************************//**
 * @brief Return model value and gradient
 *
 * @param[in] models Model descriptor.
 * @param[out] gradient Pointer to gradient vector.
 *
 * @todo Add CTA specific code (so far only dummy)
 ***************************************************************************/
double GCTAEventAtom::model(GModels& models, GVector* gradient)
{
    // Verify that gradients vector has the same dimension than the
    // model has parameters
    #if defined(G_RANGE_CHECK)
    if (models.npars() != gradient->size())
        throw GException::gradient_par_mismatch(G_MODEL, gradient->size(), 
                                                models.npars());
    #endif

    // Evaluate model and gradients
    double model = models.eval_gradients(dir(), energy(), time());
        
    // Set gradient vector
    for (int i = 0; i < gradient->size(); ++i)
        (*gradient)(i) = models.par(i)->gradient();

    // Return
    return model;
}


/*==========================================================================
 =                                                                         =
 =                             Private methods                             =
 =                                                                         =
 ==========================================================================*/

/***********************************************************************//**
 * @brief Initialise class members
 ***************************************************************************/
void GCTAEventAtom::init_members(void)
{
    // Initialise LAT data format attributes
    m_event_id    = 0;
    m_flags       = 0;
    m_multip      = 0;
    m_telmask     = 0; 
    m_dir_err     = 0.0;
    m_detx        = 0.0;
    m_dety        = 0.0;
    m_alt_pnt     = 0.0;
    m_az_pnt      = 0.0;
    m_alt         = 0.0;
    m_az          = 0.0;
    m_corex       = 0.0;
    m_corey       = 0.0;
    m_core_err    = 0.0;
    m_xmax        = 0.0;
    m_xmax_err    = 0.0;
    m_energy_err  = 0.0;
    m_hil_msw     = 0.0;
    m_hil_msw_err = 0.0;
    m_hil_msl     = 0.0;
    m_hil_msl_err = 0.0;

    // Return
    return;
}


/***********************************************************************//**
 * @brief Copy class members
 *
 * @param[in] atom GCTAEventAtom members which should be copied.
 ***************************************************************************/
void GCTAEventAtom::copy_members(const GCTAEventAtom& atom)
{
    // Copy LAT data format attributes
    m_event_id    = atom.m_event_id;
    m_flags       = atom.m_flags;
    m_multip      = atom.m_multip;
    m_telmask     = atom.m_telmask; 
    m_dir_err     = atom.m_dir_err;
    m_detx        = atom.m_detx;
    m_dety        = atom.m_dety;
    m_alt_pnt     = atom.m_alt_pnt;
    m_az_pnt      = atom.m_az_pnt;
    m_alt         = atom.m_alt;
    m_az          = atom.m_az;
    m_corex       = atom.m_corex;
    m_corey       = atom.m_corey;
    m_core_err    = atom.m_core_err;
    m_xmax        = atom.m_xmax;
    m_xmax_err    = atom.m_xmax_err;
    m_energy_err  = atom.m_energy_err;
    m_hil_msw     = atom.m_hil_msw;
    m_hil_msw_err = atom.m_hil_msw_err;
    m_hil_msl     = atom.m_hil_msl;
    m_hil_msl_err = atom.m_hil_msl_err;

    // Return
    return;
}


/***********************************************************************//**
 * @brief Delete class members
 ***************************************************************************/
void GCTAEventAtom::free_members(void)
{
    // Return
    return;
}


/***********************************************************************//**
 * @brief Clone class
***************************************************************************/
GCTAEventAtom* GCTAEventAtom::clone(void) const
{
    return new GCTAEventAtom(*this);
}


/*==========================================================================
 =                                                                         =
 =                                Friends                                  =
 =                                                                         =
 ==========================================================================*/
