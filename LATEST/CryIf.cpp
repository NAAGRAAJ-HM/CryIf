/******************************************************************************/
/* File   : CryIf.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.hpp"
#include "infCryIf_EcuM.hpp"
#include "infCryIf_Dcm.hpp"
#include "infCryIf_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CRYIF_AR_RELEASE_MAJOR_VERSION                                         4
#define CRYIF_AR_RELEASE_MINOR_VERSION                                         3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CRYIF_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible CRYIF_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(CRYIF_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible CRYIF_AR_RELEASE_MINOR_VERSION!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_CryIf:
      public abstract_module
{
   public:
      module_CryIf(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, CRYIF_CODE) InitFunction   (void);
      FUNC(void, CRYIF_CODE) DeInitFunction (void);
      FUNC(void, CRYIF_CODE) MainFunction   (void);
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
#include "CfgCryIf.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_CryIf, CRYIF_VAR) CryIf(
   {
         0x0000
      ,  0xFFFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, CRYIF_CODE) module_CryIf::InitFunction(void){
   CryIf.IsInitDone = E_OK;
}

FUNC(void, CRYIF_CODE) module_CryIf::DeInitFunction(void){
   CryIf.IsInitDone = E_NOT_OK;
}

FUNC(void, CRYIF_CODE) module_CryIf::MainFunction(void){
}

class class_CryIf_Unused{
   public:
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

FUNC(void, CRYIF_CODE) class_CryIf_Unused::ProcessJob(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::CancelJob(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::KeyElementSet(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::KeySetValid(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::KeyElementGet(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::KeyElementCopy(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::KeyElementCopyPartial(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::KeyCopy(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::RandomSeed(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::KeyGenerate(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::KeyDerive(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::KeyExchangeCalcPubVal(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::KeyExchangeCalcSecret(void){
}

FUNC(void, CRYIF_CODE) class_CryIf_Unused::CbNotification(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

