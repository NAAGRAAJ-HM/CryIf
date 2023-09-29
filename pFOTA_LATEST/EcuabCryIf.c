#define CRYIF_SOURCE
#ifdef __cplusplus
extern "C"
{
#endif

#include "CryIf_Cbk.hpp"
#include "Csm_Cbk.hpp"

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
#include "SwcServiceDet.hpp"
#endif

#if((  CRYIF_SW_MAJOR_VERSION != (5u)) \
    || (CRYIF_SW_MINOR_VERSION != (1u)) \
    || (CRYIF_SW_PATCH_VERSION != (0u)))
# error "Vendor specific version numbers of CryIf.c and CryIf.h are inconsistent"
#endif

#define CRYIF_FIRST_KEY_PRIMITIVE                                     CRYPTO_RANDOMSEED

#define CryIf_Util_MemClr(dst, count)                                 CryIf_Util_MemSet(dst, 0u, count)

#if !defined (CRYIF_LOCAL)
#define CRYIF_LOCAL                                                  static
#endif

#if !defined (CRYIF_LOCAL_INLINE)
#define CRYIF_LOCAL_INLINE                                           LOCAL_INLINE
#endif

#define CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.hpp"

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)
CRYIF_LOCAL VAR(uint8, CRYIF_VAR_ZERO_INIT) CryIf_ModuleInitialized = CRYIF_UNINIT;
#endif

#define CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.hpp"

#define CRYIF_START_SEC_CODE
#include "MemMap.hpp"

CRYIF_LOCAL Std_ReturnType CryIf_KeyCopyForDifferentDrivers(uint32 cryIfKeyId, uint32 targetCryIfKeyId);

#if(CRYIF_REDIRECTION == STD_ON)

CRYIF_LOCAL FUNC(Std_ReturnType, CRYIF_CODE) CryIf_TranslateRedirectionKeys(P2VAR(uint32, AUTOMATIC, CRYIF_APPL_VAR) keyId);

CRYIF_LOCAL FUNC(Std_ReturnType, CRYIF_CODE) CryIf_UpdateRedirectionInfo(P2CONST(Crypto_JobType, AUTOMATIC, CRYIF_APPL_DATA) job);
#endif

CRYIF_LOCAL_INLINE FUNC(uint32, CRYIF_CODE) CryIf_Util_Max(uint32 a, uint32 b);

CRYIF_LOCAL_INLINE FUNC(void, CRYIF_CODE) CryIf_Util_MemSet(P2VAR(uint8, AUTOMATIC, AUTOMATIC) dst, uint8 pattern, uint32 count);

CRYIF_LOCAL_INLINE FUNC(void, CRYIF_CODE) CryIf_Util_MemCpy(P2VAR(uint8, AUTOMATIC, AUTOMATIC) dst, P2CONST(uint8, AUTOMATIC, AUTOMATIC) src, uint32 count);

CRYIF_LOCAL_INLINE FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementCopyPartial_Internal(CryIf_CryptoFunctionsIdxOfKeyType cryptoFctIdxSrc
   ,                                                                                        CryIf_CryptoFunctionsIdxOfKeyType cryptoFctIdxDst
   ,                                                                                        uint32 cryptoKeyId
   ,                                                                                        uint32 keyElementId
   ,                                                                                        uint32 keyElementSourceOffset
   ,                                                                                        uint32 keyElementTargetOffset
   ,                                                                                        uint32 keyElementCopyLength
   ,                                                                                        uint32 targetCryptoKeyId
   ,                                                                                        uint32 targetKeyElementId);

CRYIF_LOCAL Std_ReturnType CryIf_KeyCopyForDifferentDrivers(uint32 cryIfKeyId, uint32 targetCryIfKeyId){
  uint8 i, j;
  Std_ReturnType retVal = E_NOT_OK;
  Std_ReturnType retValSrc;
  Std_ReturnType retValDst;
  uint8 buffer[CryIf_GetMaxSizeOfKeyElementOfGeneral()];
  uint32 bufferSize = CryIf_GetMaxSizeOfKeyElementOfGeneral();
  uint32 elementIdsSrc[CryIf_GetMaxNumberOfKeyElementsOfGeneral()];
  uint32 elementIdsSrcSize = CryIf_GetMaxNumberOfKeyElementsOfGeneral();
  uint32 elementIdsDst[CryIf_GetMaxNumberOfKeyElementsOfGeneral()];
  uint32 elementIdsDstSize = CryIf_GetMaxNumberOfKeyElementsOfGeneral();

  retValSrc = CryIf_GetKeyElementIdsGetOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId), elementIdsSrc, &elementIdsSrcSize);
  retValDst = CryIf_GetKeyElementIdsGetOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(targetCryIfKeyId))(CryIf_GetRefOfKey(targetCryIfKeyId), elementIdsDst, &elementIdsDstSize);

  if((retValSrc == E_OK) && (retValDst == E_OK)){
    for(i = 0; i < elementIdsSrcSize; i++){
      for(j = 0; j < elementIdsDstSize; j++)
      {
        if(elementIdsSrc[i] == elementIdsDst[j])
        {
          if(E_OK == CryIf_GetKeyElementGetOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId), elementIdsSrc[i], buffer, &bufferSize))
          {
            if(E_OK == CryIf_GetKeyElementSetOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(targetCryIfKeyId))(CryIf_GetRefOfKey(targetCryIfKeyId), elementIdsDst[j], buffer, bufferSize))
            {
              retVal = E_OK;
            }
          }
          break;
        }
      }
    }
  }

  return retVal;
}

#if(CRYIF_REDIRECTION == STD_ON)

CRYIF_LOCAL FUNC(Std_ReturnType, CRYIF_CODE) CryIf_TranslateRedirectionKeys(P2VAR(uint32, AUTOMATIC, CRYIF_APPL_VAR) keyId){
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)
  if(*keyId >= CryIf_GetSizeOfKey()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    *keyId = CryIf_GetRefOfKey(*keyId);
  }

  return errorId;
}

CRYIF_LOCAL FUNC(Std_ReturnType, CRYIF_CODE) CryIf_UpdateRedirectionInfo(P2CONST(Crypto_JobType, AUTOMATIC, CRYIF_APPL_DATA) job){
  Std_ReturnType retVal = E_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

  if(job->jobRedirectionInfoRef != NULL_PTR){
    uint8 redirectionConfigValue = job->jobRedirectionInfoRef->redirectionConfig;

    if((redirectionConfigValue & ((uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT)) == (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT){
      errorId = CryIf_TranslateRedirectionKeys(&job->jobRedirectionInfoRef->inputKeyId);
    }

    if((redirectionConfigValue & ((uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT)) == (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT){
      errorId &= CryIf_TranslateRedirectionKeys(&job->jobRedirectionInfoRef->secondaryInputKeyId);
    }

    if((redirectionConfigValue & ((uint8)CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT)) == (uint8)CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT){
      errorId &= CryIf_TranslateRedirectionKeys(&job->jobRedirectionInfoRef->tertiaryInputKeyId);
    }

    if((redirectionConfigValue & ((uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT)) == (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT){
      errorId &= CryIf_TranslateRedirectionKeys(&job->jobRedirectionInfoRef->outputKeyId);
    }

    if((redirectionConfigValue & ((uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT)) == (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT){
      errorId &= CryIf_TranslateRedirectionKeys(&job->jobRedirectionInfoRef->secondaryOutputKeyId);
    }
  }

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    retVal = E_NOT_OK;

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError((uint16)CRYIF_MODULE_ID
   ,     CRYIF_INSTANCE_ID_DET
   ,     CRYIF_SID_PROCESS_JOB
   ,     errorId);
#else
    CRYIF_DUMMY_STATEMENT(errorId);
#endif
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}
#endif

CRYIF_LOCAL_INLINE FUNC(uint32, CRYIF_CODE) CryIf_Util_Max(uint32 a, uint32 b){
  return (a > b)?(a):(b);
}

CRYIF_LOCAL_INLINE FUNC(void, CRYIF_CODE) CryIf_Util_MemSet(P2VAR(uint8, AUTOMATIC, AUTOMATIC) dst, uint8 pattern, uint32 count){
  uint32_least i;

  for(i = 0; i < count; ++i){
    dst[i] = pattern;
  }
}

CRYIF_LOCAL_INLINE FUNC(void, CRYIF_CODE) CryIf_Util_MemCpy(P2VAR(uint8, AUTOMATIC, AUTOMATIC) dst, P2CONST(uint8, AUTOMATIC, AUTOMATIC) src, uint32 count){
  uint32_least i;

  for(i = 0; i < count; ++i){
    dst[i] = src[i];
  }
}

CRYIF_LOCAL_INLINE FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementCopyPartial_Internal(
      CryIf_CryptoFunctionsIdxOfKeyType cryptoFctIdxSrc
   ,     CryIf_CryptoFunctionsIdxOfKeyType cryptoFctIdxDst
   ,     uint32 cryptoKeyId
   ,     uint32 keyElementId
   ,     uint32 keyElementSourceOffset
   ,     uint32 keyElementTargetOffset
   ,     uint32 keyElementCopyLength
   ,     uint32 targetCryptoKeyId
   ,     uint32 targetKeyElementId){
  Std_ReturnType retVal;

  uint8 bufferSrc[CryIf_GetMaxSizeOfKeyElementOfGeneral()];
  uint8 bufferDst[CryIf_GetMaxSizeOfKeyElementOfGeneral()];
  uint32 bufferSizeSrc = CryIf_GetMaxSizeOfKeyElementOfGeneral();
  uint32 bufferSizeDst = CryIf_GetMaxSizeOfKeyElementOfGeneral();

  if(((keyElementTargetOffset + keyElementCopyLength) <= CryIf_GetMaxSizeOfKeyElementOfGeneral())){
    retVal = CryIf_GetKeyElementGetOfCryptoFunctions(cryptoFctIdxSrc)(cryptoKeyId, keyElementId, bufferSrc, &bufferSizeSrc);

    if(retVal == E_OK){
      if((keyElementSourceOffset + keyElementCopyLength) <= bufferSizeSrc)
      {
        retVal = CryIf_GetKeyElementGetOfCryptoFunctions(cryptoFctIdxDst)(targetCryptoKeyId, targetKeyElementId, bufferDst, &bufferSizeDst);
        switch(retVal)
        {
        case CRYPTO_E_KEY_EMPTY:
        {
          bufferSizeDst = 0u;
        }

        case E_OK:
        {
          if(bufferSizeDst < keyElementTargetOffset)
          {
            CryIf_Util_MemClr(&bufferDst[bufferSizeDst], keyElementTargetOffset - bufferSizeDst);
          }

          CryIf_Util_MemCpy(&bufferDst[keyElementTargetOffset], &bufferSrc[keyElementSourceOffset], keyElementCopyLength);

          bufferSizeDst = CryIf_Util_Max(bufferSizeDst, keyElementTargetOffset + keyElementCopyLength);

          retVal = CryIf_GetKeyElementSetOfCryptoFunctions(cryptoFctIdxDst)(targetCryptoKeyId, targetKeyElementId, bufferDst, bufferSizeDst);
        }
          break;

        default:

          break;
        }

      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
  }
  else{
    retVal = E_NOT_OK;
  }

  return retVal;
}

FUNC(void, CRYIF_CODE) CryIf_InitMemory(void){
#if(CRYIF_DEV_ERROR_DETECT == STD_ON)
  CryIf_ModuleInitialized = CRYIF_UNINIT;
#endif
}

FUNC(void, CRYIF_CODE) CryIf_Init(void){
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_INIT){
    errorId = CRYIF_E_ALREADY_INITIALIZED;
  }
  else
#endif
  {
#if(CRYIF_DEV_ERROR_DETECT == STD_ON)
    CryIf_ModuleInitialized = (uint8)CRYIF_INIT;
#endif
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_INIT, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif
}

#if(CRYIF_VERSION_INFO_API == STD_ON)

FUNC(void, CRYIF_CODE) CryIf_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CRYIF_APPL_VAR) versioninfo){
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)
  if(versioninfo == NULL_PTR){
    errorId = CRYIF_E_PARAM_POINTER;
  }
  else
#endif
  {
    versioninfo->vendorID = (CRYIF_VENDOR_ID);
    versioninfo->moduleID = (CRYIF_MODULE_ID);
    versioninfo->sw_major_version = (CRYIF_SW_MAJOR_VERSION);
    versioninfo->sw_minor_version = (CRYIF_SW_MINOR_VERSION);
    versioninfo->sw_patch_version = (CRYIF_SW_PATCH_VERSION);
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_GET_VERSION_INFO, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif
}
#endif

FUNC(void, CRYIF_CODE) CryIf_CallbackNotification(P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_VAR) job
   ,                                                 Std_ReturnType result){
  Csm_CallbackNotification(job, result);
}

FUNC(Std_ReturnType, CRYIF_CODE) EcuabCryIf_ProcessJob(uint32 channelId
   ,                                                 P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_VAR) job){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if(job == NULL_PTR){
    errorId = CRYIF_E_PARAM_POINTER;
  }

  else if(channelId >= CryIf_GetSizeOfChannel()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    if(job->jobPrimitiveInfo->cryIfKeyId < CryIf_GetSizeOfKey()){
      if(job->jobPrimitiveInfo->primitiveInfo->service < CRYIF_FIRST_KEY_PRIMITIVE)
      {
        job->cryptoKeyId = CryIf_GetRefOfKey( job->jobPrimitiveInfo->cryIfKeyId );
      }
      else
      {
        job->cryptoKeyId = CryIf_GetRefOfKey( job->jobPrimitiveInputOutput.cryIfKeyId);

        if(job->jobPrimitiveInfo->primitiveInfo->service == (Crypto_ServiceInfoType)CRYPTO_KEYDERIVE)
        {
          job->targetCryptoKeyId = CryIf_GetRefOfKey(job->jobPrimitiveInputOutput.targetCryIfKeyId);
        }
      }
#if(CRYIF_REDIRECTION == STD_ON)
#if(CRYIF_DEV_ERROR_DETECT)
      retVal = CryIf_UpdateRedirectionInfo(job);
      if(retVal == E_OK)
#else
      (void)CryIf_UpdateRedirectionInfo(job);
#endif
#endif
      {
        retVal = CryIf_GetProcessJobOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfChannel(channelId))(CryIf_GetDriverObjectRefOfChannel(channelId), job);
      }
    }
    else{
      retVal = CRYPTO_E_KEY_NOT_AVAILABLE;
    }
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_PROCESS_JOB, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) EcuabCryIf_CancelJob(uint32 channelId
   ,                                                P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_VAR) job){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if(job == NULL_PTR){
    errorId = CRYIF_E_PARAM_POINTER;
  }

  else if(channelId >= CryIf_GetSizeOfChannel()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    if(job->jobPrimitiveInfo->cryIfKeyId < CryIf_GetSizeOfKey()){
      if(job->jobPrimitiveInfo->primitiveInfo->service < CRYIF_FIRST_KEY_PRIMITIVE)
      {
        job->cryptoKeyId = CryIf_GetRefOfKey(job->jobPrimitiveInfo->cryIfKeyId);
      }
      else
      {
        job->cryptoKeyId = CryIf_GetRefOfKey(job->jobPrimitiveInputOutput.cryIfKeyId);

        if(job->jobPrimitiveInfo->primitiveInfo->service == (Crypto_ServiceInfoType)CRYPTO_KEYDERIVE)
        {
          job->targetCryptoKeyId = CryIf_GetRefOfKey(job->jobPrimitiveInputOutput.targetCryIfKeyId);
        }
      }
#if(EcuabCryIf_CancelJobWITHINFOTYPEOFCRYPTOFUNCTIONS == STD_ON)

      if(CryIf_GetCancelJobOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfChannel(channelId)) == NULL_PTR)
      {
        Crypto_JobInfoType jobInfo;
        jobInfo.jobId = job->jobInfo->jobId;
        jobInfo.jobPriority = job->jobInfo->jobPriority;

        retVal = CryIf_GetCancelJobWithInfoTypeOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfChannel(channelId))(CryIf_GetDriverObjectRefOfChannel(channelId), &jobInfo);
      }
      else
#endif
      {
        retVal = CryIf_GetCancelJobOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfChannel(channelId))(CryIf_GetDriverObjectRefOfChannel(channelId), job);
      }
    }
    else{
      retVal = CRYPTO_E_KEY_NOT_AVAILABLE;
    }
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_CANCEL_JOB, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementSet(uint32 cryIfKeyId
   ,                                                    uint32 keyElementId
   ,                                                    P2CONST(uint8, AUTOMATIC, CRYIF_APPL_DATA) keyPtr
   ,                                                    uint32 keyLength){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if(keyPtr == NULL_PTR){
    errorId = CRYIF_E_PARAM_POINTER;
  }

  else if(keyLength == 0u){
    errorId = CRYIF_E_PARAM_VALUE;
  }

  else if(cryIfKeyId >= CryIf_GetSizeOfKey()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    retVal = CryIf_GetKeyElementSetOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId)
   ,                                                    keyElementId
   ,                                                    keyPtr
   ,                                                    keyLength);
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_KEY_ELEMENT_SET, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeySetValid(uint32 cryIfKeyId){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if(cryIfKeyId >= CryIf_GetSizeOfKey()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    retVal = CryIf_GetKeyValidSetOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId));
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_KEY_SET_VALID, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementGet(uint32 cryIfKeyId
   ,                                                    uint32 keyElementId
   ,                                                    P2VAR(uint8, AUTOMATIC, CRYIF_APPL_VAR) resultPtr
   ,                                                    P2VAR(uint32, AUTOMATIC, CRYIF_APPL_VAR) resultLengthPtr){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if((resultPtr == NULL_PTR) || (resultLengthPtr == NULL_PTR)){
    errorId = CRYIF_E_PARAM_POINTER;
  }

  else if(*resultLengthPtr == 0u){
    errorId = CRYIF_E_PARAM_VALUE;
  }

  else if(cryIfKeyId >= CryIf_GetSizeOfKey()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    retVal = CryIf_GetKeyElementGetOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId)
   ,                                                                                                  keyElementId
   ,                                                                                                  resultPtr
   ,                                                                                                  resultLengthPtr);
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_KEY_ELEMENT_GET, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementCopy(uint32 cryIfKeyId
   ,                                                     uint32 keyElementId
   ,                                                     uint32 targetCryIfKeyId
   ,                                                     uint32 targetKeyElementId){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if((cryIfKeyId >= CryIf_GetSizeOfKey())
    || (targetCryIfKeyId >= CryIf_GetSizeOfKey())){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    CryIf_CryptoFunctionsIdxOfKeyType cryptoFctIdxSrc = CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId);
    CryIf_CryptoFunctionsIdxOfKeyType cryptoFctIdxDst = CryIf_GetCryptoFunctionsIdxOfKey(targetCryIfKeyId);
    CryIf_RefOfKeyType cryptoKeyIdSrc = CryIf_GetRefOfKey(cryIfKeyId);
    CryIf_RefOfKeyType cryptoKeyIdDst = CryIf_GetRefOfKey(targetCryIfKeyId);

    if(cryptoFctIdxSrc == cryptoFctIdxDst){
      retVal = CryIf_GetKeyElementCopyOfCryptoFunctions(cryptoFctIdxSrc)(cryptoKeyIdSrc, keyElementId, cryptoKeyIdDst, targetKeyElementId);
    }
    else{
      uint8 buffer[CryIf_GetMaxSizeOfKeyElementOfGeneral()];
      uint32 bufferSize = CryIf_GetMaxSizeOfKeyElementOfGeneral();

      if(CryIf_GetKeyElementGetOfCryptoFunctions(cryptoFctIdxSrc)(cryptoKeyIdSrc, keyElementId, buffer, &bufferSize) == E_OK)
      {
        retVal = CryIf_GetKeyElementSetOfCryptoFunctions(cryptoFctIdxDst)(cryptoKeyIdDst, targetKeyElementId, buffer, bufferSize);
      }
    }
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_KEY_ELEMENT_COPY, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementCopyPartial_Stub(uint32 cryIfKeyId
   ,                                                                 uint32 keyElementId
   ,                                                                 uint32 keyElementSourceOffset
   ,                                                                 uint32 keyElementTargetOffset
   ,                                                                 uint32 keyElementCopyLength
   ,                                                                 uint32 targetCryIfKeyId
   ,                                                                 uint32 targetKeyElementId){
  CRYIF_DUMMY_STATEMENT(cryIfKeyId);
  CRYIF_DUMMY_STATEMENT(keyElementId);
  CRYIF_DUMMY_STATEMENT(keyElementSourceOffset);
  CRYIF_DUMMY_STATEMENT(keyElementTargetOffset);
  CRYIF_DUMMY_STATEMENT(keyElementCopyLength);
  CRYIF_DUMMY_STATEMENT(targetCryIfKeyId);
  CRYIF_DUMMY_STATEMENT(targetKeyElementId);

  return E_NOT_OK;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementCopyPartial(uint32 cryIfKeyId
   ,                                                           uint32 keyElementId
   ,                                                           uint32 keyElementSourceOffset
   ,                                                           uint32 keyElementTargetOffset
   ,                                                           uint32 keyElementCopyLength
   ,                                                           uint32 targetCryIfKeyId
   ,                                                           uint32 targetKeyElementId){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if((cryIfKeyId >= CryIf_GetSizeOfKey())
    || (targetCryIfKeyId >= CryIf_GetSizeOfKey())){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    CryIf_CryptoFunctionsIdxOfKeyType cryptoFctIdxSrc = CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId);
    CryIf_CryptoFunctionsIdxOfKeyType cryptoFctIdxDst = CryIf_GetCryptoFunctionsIdxOfKey(targetCryIfKeyId);
    CryIf_RefOfKeyType cryptoKeyIdSrc = CryIf_GetRefOfKey(cryIfKeyId);
    CryIf_RefOfKeyType cryptoKeyIdDst = CryIf_GetRefOfKey(targetCryIfKeyId);

    if((cryptoFctIdxSrc == cryptoFctIdxDst) && (CryIf_IsSupportsKeyElementCopyPartialOfCryptoFunctions(cryptoFctIdxDst))){
      retVal = CryIf_GetKeyElementCopyPartialOfCryptoFunctions(cryptoFctIdxSrc)(cryptoKeyIdSrc, keyElementId, keyElementSourceOffset, keyElementTargetOffset, keyElementCopyLength, cryptoKeyIdDst, targetKeyElementId);
    }
    else{
      retVal = CryIf_KeyElementCopyPartial_Internal(cryptoFctIdxSrc, cryptoFctIdxDst, cryptoKeyIdSrc, keyElementId, keyElementSourceOffset, keyElementTargetOffset, keyElementCopyLength, cryptoKeyIdDst, targetKeyElementId);
    }
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_KEY_ELEMENT_COPY_PARTIAL, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyCopy(uint32 cryIfKeyId
   ,                                              uint32 targetCryIfKeyId){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if((cryIfKeyId >= CryIf_GetSizeOfKey())
    || (targetCryIfKeyId >= CryIf_GetSizeOfKey())){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    if(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId) == CryIf_GetCryptoFunctionsIdxOfKey(targetCryIfKeyId)){
      retVal = CryIf_GetKeyCopyOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId), CryIf_GetRefOfKey(targetCryIfKeyId));
    }
    else{
      retVal = CryIf_KeyCopyForDifferentDrivers(cryIfKeyId, targetCryIfKeyId);
    }
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_KEY_COPY, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) EcuabCryIf_RandomSeed(uint32 cryIfKeyId
   ,                                                 P2CONST(uint8, AUTOMATIC, CRYIF_APPL_DATA) seedPtr
   ,                                                 uint32 seedLength){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if(seedPtr == NULL_PTR){
    errorId = CRYIF_E_PARAM_POINTER;
  }

  else if(seedLength == 0u){
    errorId = CRYIF_E_PARAM_VALUE;
  }

  else if(cryIfKeyId >= CryIf_GetSizeOfKey()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    retVal = CryIf_GetRandomSeedOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId)
   ,                                                                                               seedPtr
   ,                                                                                               seedLength);
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_RANDOM_SEED, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) EcuabCryIf_KeyGenerate(uint32 cryIfKeyId){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if(cryIfKeyId >= CryIf_GetSizeOfKey()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    retVal = CryIf_GetKeyGenerateOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId));
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_KEY_GENERATE, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyDerive(uint32 cryIfKeyId
   ,                                                uint32 targetCryIfKeyId){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if((cryIfKeyId >= CryIf_GetSizeOfKey())
    || (targetCryIfKeyId >= CryIf_GetSizeOfKey())){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    retVal = CryIf_GetKeyDeriveOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId), CryIf_GetRefOfKey(targetCryIfKeyId));
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_KEY_DERIVE, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyExchangeCalcPubVal(uint32 cryIfKeyId
   ,                                                            P2VAR(uint8, AUTOMATIC, CRYIF_APPL_VAR) publicValuePtr
   ,                                                            P2VAR(uint32, AUTOMATIC, CRYIF_APPL_VAR) publicValueLengthPtr){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if((publicValuePtr == NULL_PTR) || (publicValueLengthPtr == NULL_PTR)){
    errorId = CRYIF_E_PARAM_POINTER;
  }

  else if(*publicValueLengthPtr == 0u){
    errorId = CRYIF_E_PARAM_VALUE;
  }

  else if(cryIfKeyId >= CryIf_GetSizeOfKey()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    retVal = CryIf_GetKeyExchangeCalcPubValOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId)
   ,                                                                                                          publicValuePtr
   ,                                                                                                          publicValueLengthPtr);
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_KEY_EXCHANGE_CALC_PUB_VAL, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyExchangeCalcSecret(uint32 cryIfKeyId
   ,                                                            P2CONST(uint8, AUTOMATIC, CRYIF_APPL_DATA) partnerPublicValuePtr
   ,                                                            uint32 partnerPublicValueLength){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if(partnerPublicValuePtr == NULL_PTR){
    errorId = CRYIF_E_PARAM_POINTER;
  }

  else if(partnerPublicValueLength == 0u){
    errorId = CRYIF_E_PARAM_VALUE;
  }

  else if(cryIfKeyId >= CryIf_GetSizeOfKey()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    retVal = CryIf_GetKeyExchangeCalcSecretOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId)
   ,                                                                                                          partnerPublicValuePtr
   ,                                                                                                          partnerPublicValueLength);
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_KEY_EXCHANGE_CALC_SECRET, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_CertificateParse(uint32 cryIfKeyId){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if(cryIfKeyId >= CryIf_GetSizeOfKey()){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    retVal = CryIf_GetCertificateParseOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId));
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_CERTIFICATE_PARSE, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_CertificateVerify(uint32 cryIfKeyId
   ,                                                        uint32 verifyCryIfKeyId
   ,                                                        P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYIF_APPL_VAR) verifyPtr){
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYIF_E_NO_ERROR;

#if(CRYIF_DEV_ERROR_DETECT == STD_ON)

  if(CryIf_ModuleInitialized == (uint8)CRYIF_UNINIT){
    errorId = CRYIF_E_UNINIT;
  }

  else if(verifyPtr == NULL_PTR){
    errorId = CRYIF_E_PARAM_POINTER;
  }

  else if((cryIfKeyId >= CryIf_GetSizeOfKey())
    || (verifyCryIfKeyId >= CryIf_GetSizeOfKey())){
    errorId = CRYIF_E_PARAM_HANDLE;
  }
  else
#endif
  {
    retVal = CryIf_GetCertificateVerifyOfCryptoFunctions(CryIf_GetCryptoFunctionsIdxOfKey(cryIfKeyId))(CryIf_GetRefOfKey(cryIfKeyId)
   ,                                                                                                      CryIf_GetRefOfKey(verifyCryIfKeyId)
   ,                                                                                                      verifyPtr);
  }

#if(CRYIF_DEV_ERROR_REPORT == STD_ON)
  if(errorId != CRYIF_E_NO_ERROR){
    (void)Det_ReportError(CRYIF_MODULE_ID, CRYIF_INSTANCE_ID_DET, CRYIF_SID_CERTIFICATE_VERIFY, errorId);
  }
#else
  CRYIF_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
}

#define CRYIF_STOP_SEC_CODE
#include "MemMap.hpp"

#ifdef __cplusplus
}
#endif
