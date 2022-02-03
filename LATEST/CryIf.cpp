/*****************************************************/
/* File   : CryIf.cpp                                */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "CryIf.h"

#include "CryIf_EcuM.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
class_CryIf CryIf;
class_CryIf_EcuM CryIf_EcuM;
class_EcuM_Client *EcuM_Client_ptr_CryIf = &CryIf_EcuM;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, CRYIF_CODE) class_CryIf_EcuM::InitFunction(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::GetVersionInfo(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::ProcessJob(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::CancelJob(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::KeyElementSet(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::KeySetValid(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::KeyElementGet(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::KeyElementCopy(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::KeyElementCopyPartial(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::KeyCopy(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::RandomSeed(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::KeyGenerate(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::KeyDerive(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::KeyExchangeCalcPubVal(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::KeyExchangeCalcSecret(void){
}

FUNC(void, CRYIF_CODE) class_CryIf::CbNotification(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

