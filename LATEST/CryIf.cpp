/******************************************************************************/
/* File   : CryIf.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgCryIf.hpp"
#include "CryIf_core.hpp"
#include "infCryIf_Exp.hpp"
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
class module_CryIf:
      INTERFACES_EXPORTED_CRYIF
      public abstract_module
   ,  public class_CryIf_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
            Std_TypeReturn          IsInitDone{E_NOT_OK};
      const CfgModule_TypeAbstract* lptrCfg{(CfgModule_TypeAbstract*)NULL_PTR};

   public:
      module_CryIf(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, CRYIF_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, CRYIF_CONFIG_DATA, CRYIF_APPL_CONST) lptrCfgModule
      );
      FUNC(void, CRYIF_CODE) DeInitFunction (void);
      FUNC(void, CRYIF_CODE) MainFunction   (void);
      CRYIF_CORE_FUNCTIONALITIES
};

extern VAR(module_CryIf, CRYIF_VAR) CryIf;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, CRYIF_VAR, CRYIF_CONST) gptrinfEcuMClient_CryIf = &CryIf;
CONSTP2VAR(infDcmClient,  CRYIF_VAR, CRYIF_CONST) gptrinfDcmClient_CryIf  = &CryIf;
CONSTP2VAR(infSchMClient, CRYIF_VAR, CRYIF_CONST) gptrinfSchMClient_CryIf = &CryIf;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_CryIf, CRYIF_VAR) CryIf(
   {
         CRYIF_AR_RELEASE_VERSION_MAJOR
      ,  CRYIF_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

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
         if(STD_HIGH){
            lptrCfg = lptrCfgModule;
         }
         else{
            lptrCfg = &PBcfgCryIf;
         }
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

