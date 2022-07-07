/******************************************************************************/
/* File   : CryIf.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CryIf.hpp"
#include "infCryIf_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CRYIF_AR_RELEASE_VERSION_MAJOR                                         4
#define CRYIF_AR_RELEASE_VERSION_MINOR                                         3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CRYIF_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible CRYIF_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(CRYIF_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible CRYIF_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_CryIf, CRYIF_VAR) CryIf;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CRYIF_CODE) module_CryIf::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, CRYIF_CONFIG_DATA, CRYIF_APPL_CONST) lptrCfgModule
){
#if(STD_ON == CryIf_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         lptrCfg = lptrCfgModule;
      }
      else{
#if(STD_ON == CryIf_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == CryIf_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == CryIf_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CRYIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CRYIF_CODE) module_CryIf::DeInitFunction(
   void
){
#if(STD_ON == CryIf_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == CryIf_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == CryIf_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CRYIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CRYIF_CODE) module_CryIf::MainFunction(
   void
){
#if(STD_ON == CryIf_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == CryIf_InitCheck)
   }
   else{
#if(STD_ON == CryIf_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CRYIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CRYIF_CODE) module_CryIf::ProcessJob(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::CancelJob(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::KeyElementSet(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::KeySetValid(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::KeyElementGet(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::KeyElementCopy(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::KeyElementCopyPartial(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::KeyCopy(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::RandomSeed(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::KeyGenerate(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::KeyDerive(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::KeyExchangeCalcPubVal(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::KeyExchangeCalcSecret(
   void
){
}

FUNC(void, CRYIF_CODE) module_CryIf::CbNotification(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

