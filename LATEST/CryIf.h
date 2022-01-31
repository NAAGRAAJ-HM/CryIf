#pragma once
/*****************************************************/
/* File   : CryIf.h                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Std_Types.h"
#include "Compiler_Cfg_CryIf.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class class_CryIf{
   public:
/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
      FUNC(void, CRYIF_CODE) InitFunction          (void);
      FUNC(void, CRYIF_CODE) GetVersionInfo        (void);
      FUNC(void, CRYIF_CODE) ProcessJob            (void);
      FUNC(void, CRYIF_CODE) CancelJob             (void);
      FUNC(void, CRYIF_CODE) KeyElementSet         (void);
      FUNC(void, CRYIF_CODE) KeySetValid           (void);
      FUNC(void, CRYIF_CODE) KeyElementGet         (void);
      FUNC(void, CRYIF_CODE) KeyElementCopy        (void);
      FUNC(void, CRYIF_CODE) KeyElementCopyPartial (void);
      FUNC(void, CRYIF_CODE) KeyCopy               (void);
      FUNC(void, CRYIF_CODE) RandomSeed            (void);
      FUNC(void, CRYIF_CODE) KeyGenerate           (void);
      FUNC(void, CRYIF_CODE) KeyDerive             (void);
      FUNC(void, CRYIF_CODE) KeyExchangeCalcPubVal (void);
      FUNC(void, CRYIF_CODE) KeyExchangeCalcSecret (void);
      FUNC(void, CRYIF_CODE) CbNotification        (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
extern class_CryIf CryIf;

/*****************************************************/
/* EOF                                               */
/*****************************************************/

