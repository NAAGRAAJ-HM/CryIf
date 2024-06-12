/******************************************************************************/
/* File   : EcuabCryIf.cpp                                                         */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "EcuabCryIf.hpp"
#include "infEcuabCryIf_Imp.hpp"

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
VAR(module_EcuabCryIf, CRYIF_VAR) EcuabCryIf;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CRYIF_CODE) module_EcuabCryIf::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, CRYIF_CONST,       CRYIF_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   CRYIF_CONFIG_DATA, CRYIF_APPL_CONST) lptrCfgModule
){
#if(STD_ON == EcuabCryIf_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstEcuabCryIf_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == EcuabCryIf_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == EcuabCryIf_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == EcuabCryIf_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CRYIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::DeInitFunction(
   void
){
#if(STD_ON == EcuabCryIf_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == EcuabCryIf_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == EcuabCryIf_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CRYIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::MainFunction(
   void
){
#if(STD_ON == EcuabCryIf_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == EcuabCryIf_InitCheck)
   }
   else{
#if(STD_ON == EcuabCryIf_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  CRYIF_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::ProcessJob(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::McalCancelJob(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::KeyElementSet(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::KeySetValid(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::KeyElementGet(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::KeyElementCopy(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::KeyElementCopyPartial(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::KeyCopy(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::RandomSeed(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::KeyGenerate(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::KeyDerive(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::KeyExchangeCalcPubVal(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::KeyExchangeCalcSecret(
   void
){
}

FUNC(void, CRYIF_CODE) module_EcuabCryIf::CbNotification(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

