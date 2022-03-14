/******************************************************************************/
/* File   : CryIf.cpp                                                         */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
#include "infCryIf_EcuM.h"
#include "infCryIf_Dcm.h"
#include "infCryIf_SchM.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_CryIf:
      public abstract_module
{
   public:
      FUNC(void, CRYIF_CODE) InitFunction   (void);
      FUNC(void, CRYIF_CODE) DeInitFunction (void);
      FUNC(void, CRYIF_CODE) GetVersionInfo (void);
      FUNC(void, CRYIF_CODE) MainFunction   (void);
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


/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
VAR(module_CryIf, CRYIF_VAR) CryIf;
CONSTP2VAR(infEcuMClient, CRYIF_VAR, CRYIF_CONST) gptrinfEcuMClient_CryIf = &CryIf;
CONSTP2VAR(infDcmClient,  CRYIF_VAR, CRYIF_CONST) gptrinfDcmClient_CryIf  = &CryIf;
CONSTP2VAR(infSchMClient, CRYIF_VAR, CRYIF_CONST) gptrinfSchMClient_CryIf = &CryIf;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, CRYIF_CODE) module_CryIf::InitFunction(void){
}

FUNC(void, CRYIF_CODE) module_CryIf::DeInitFunction(void){
}

FUNC(void, CRYIF_CODE) module_CryIf::GetVersionInfo(void){
}

FUNC(void, CRYIF_CODE) module_CryIf::MainFunction(void){
}

#include "CryIf_Unused.h"

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

/*****************************************************/
/* EOF                                               */
/*****************************************************/

