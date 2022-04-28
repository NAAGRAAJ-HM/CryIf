#pragma once
/******************************************************************************/
/* File   : CryIf_core.hpp                                                    */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_CryIf.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CRYIF_CORE_FUNCTIONALITIES                                             \
              FUNC(void, CRYIF_CODE) ProcessJob            (void);             \
              FUNC(void, CRYIF_CODE) CancelJob             (void);             \
              FUNC(void, CRYIF_CODE) KeyElementSet         (void);             \
              FUNC(void, CRYIF_CODE) KeySetValid           (void);             \
              FUNC(void, CRYIF_CODE) KeyElementGet         (void);             \
              FUNC(void, CRYIF_CODE) KeyElementCopy        (void);             \
              FUNC(void, CRYIF_CODE) KeyElementCopyPartial (void);             \
              FUNC(void, CRYIF_CODE) KeyCopy               (void);             \
              FUNC(void, CRYIF_CODE) RandomSeed            (void);             \
              FUNC(void, CRYIF_CODE) KeyGenerate           (void);             \
              FUNC(void, CRYIF_CODE) KeyDerive             (void);             \
              FUNC(void, CRYIF_CODE) KeyExchangeCalcPubVal (void);             \
              FUNC(void, CRYIF_CODE) KeyExchangeCalcSecret (void);             \
              FUNC(void, CRYIF_CODE) CbNotification        (void);             \

#define CRYIF_CORE_FUNCTIONALITIES_VIRTUAL                                     \
      virtual FUNC(void, CRYIF_CODE) ProcessJob            (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) CancelJob             (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) KeyElementSet         (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) KeySetValid           (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) KeyElementGet         (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) KeyElementCopy        (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) KeyElementCopyPartial (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) KeyCopy               (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) RandomSeed            (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) KeyGenerate           (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) KeyDerive             (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) KeyExchangeCalcPubVal (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) KeyExchangeCalcSecret (void) = 0;         \
      virtual FUNC(void, CRYIF_CODE) CbNotification        (void) = 0;         \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_CryIf_Functionality{
   public:
      CRYIF_CORE_FUNCTIONALITIES_VIRTUAL
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

