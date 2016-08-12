// Copyright (c) 2016, XMOS Ltd, All rights reserved

#ifndef _FIRDS3_H_
#define _FIRDS3_H_

    // ===========================================================================
    //
    // Defines
    //
    // ===========================================================================
    
    // General defines
    // ---------------
    // Filter related
    #define     FIRDS3_N_COEFS                          144                     // Number of coefficients must be a multiple of 6
    // Filters with "_b_" in their filenames in FIRDS3.h have higher attenuation at Nyquist (> 60dB compared with 20dB ) but with an earlier cutoff.
    #define     FIRDS3_COEFS_FILE                       "FilterData/firds3_b_144.dat"
    //#define     FIRDS3_COEFS_FILE                       "FilterData/firds3_144.dat"

    // ===========================================================================
    //
    // TypeDefs
    //
    // ===========================================================================

    // To avoid C type definitions when including this file from assembler
    #ifndef INCLUDE_FROM_ASM

        // FIRDS3 Return Codes
        // -------------------
        typedef enum _FIRDS3ReturnCodes                                 
        {
            FIRDS3_NO_ERROR                         = 0,
            FIRDS3_ERROR                            = 1
        } FIRDS3ReturnCodes_t;

        // FIRDS3 Ctrl
        // -----------
#ifdef __XC__
        typedef struct _FIRDS3Ctrl                                      
        {
            int*unsafe                                  piIn;           // Pointer to input data (3 samples)
            int*unsafe                                      piOut;          // Pointer to output data (1 sample)

            int*unsafe                                      piDelayB;       // Pointer to delay line base
            unsigned int                            uiDelayL;       // Total length of delay line
            int*unsafe                                      piDelayI;       // Pointer to current position in delay line
            int*unsafe                                      piDelayW;       // Delay buffer wrap around address (for circular buffer simulation)
            unsigned int                            uiDelayO;       // Delay line offset for second write (for circular buffer simulation)

            unsigned int                            uiNLoops;       // Number of inner loop iterations
            unsigned int                            uiNCoefs;       // Number of coefficients
            int*unsafe                                      piCoefs;        // Pointer to coefficients
        } FIRDS3Ctrl_t;
#else
        typedef struct _FIRDS3Ctrl
        {
            int*                                    piIn;           // Pointer to input data (3 samples)
            int*                                    piOut;          // Pointer to output data (1 sample)

            int*                                    piDelayB;       // Pointer to delay line base
            unsigned int                            uiDelayL;       // Total length of delay line
            int*                                    piDelayI;       // Pointer to current position in delay line
            int*                                    piDelayW;       // Delay buffer wrap around address (for circular buffer simulation)
            unsigned int                            uiDelayO;       // Delay line offset for second write (for circular buffer simulation)

            unsigned int                            uiNLoops;       // Number of inner loop iterations
            unsigned int                            uiNCoefs;       // Number of coefficients
            int*                                    piCoefs;        // Pointer to coefficients
        } FIRDS3Ctrl_t;
#endif

        
        // ===========================================================================
        //
        // Function prototypes
        //
        // ===========================================================================

        // ==================================================================== //
        // Function:        FIRDS3_init                                         //
        // Arguments:       FIRDS3Ctrl_t    *psFIRDS2Ctrl: Ctrl strct.          //
        // Return values:   FIRDS3_NO_ERROR on success                          //
        //                  FIRDS3_ERROR on failure                             //
        // Description:     Inits the FIRDS3                                    //
        // ==================================================================== //
#ifdef __XC__
        FIRDS3ReturnCodes_t             FIRDS3_init(FIRDS3Ctrl_t* unsafe psFIRDS3Ctrl);
#else
        FIRDS3ReturnCodes_t             FIRDS3_init(FIRDS3Ctrl_t* psFIRDS3Ctrl);
#endif
        // ==================================================================== //
        // Function:        FIRDS3_sync                                         //
        // Arguments:       FIRDS3Ctrl_t    *psFIRDS2Ctrl: Ctrl strct.          //
        // Return values:   FIRDS3_NO_ERROR on success                          //
        //                  FIRDS3_ERROR on failure                             //
        // Description:     Syncs the FIRDS3                                    //
        // ==================================================================== //
#ifdef __XC__
        FIRDS3ReturnCodes_t             FIRDS3_sync(FIRDS3Ctrl_t* unsafe psFIRDS3Ctrl);
#else
        FIRDS3ReturnCodes_t             FIRDS3_sync(FIRDS3Ctrl_t* psFIRDS3Ctrl);
#endif
        // ==================================================================== //
        // Function:        FIRDS3_proc                                         //
        // Arguments:       FIRDS3Ctrl_t    *psFIRDS3Ctrl: Ctrl strct.          //
        // Return values:   FIRDS3_NO_ERROR on success                          //
        //                  FIRDS3_ERROR on failure                             //
        // Description:     Processes the FIRDS3                                //
        // ==================================================================== //
#ifdef __XC__
        FIRDS3ReturnCodes_t             FIRDS3_proc(FIRDS3Ctrl_t* unsafe psFIRDS3Ctrl);
#else
        FIRDS3ReturnCodes_t             FIRDS3_proc(FIRDS3Ctrl_t* psFIRDS3Ctrl);
#endif
    #endif // nINCLUDE_FROM_ASM

#endif // _FIRDS3_H_
