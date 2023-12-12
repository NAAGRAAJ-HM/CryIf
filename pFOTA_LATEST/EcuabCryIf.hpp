

#if !defined (CRYIF_H)
#define CRYIF_H

#include "Types_SwcServiceCsm.hpp"
#include "CfgEcuabCryIf.hpp"

#define CRYIF_VENDOR_ID                                              (1u)
#define CRYIF_MODULE_ID                                              (112u)

#define CRYIF_AR_RELEASE_MAJOR_VERSION                               (4u)
#define CRYIF_AR_RELEASE_MINOR_VERSION                               (4u)
#define CRYIF_AR_RELEASE_REVISION_VERSION                            (0u)

#define CRYIF_SW_MAJOR_VERSION                                       (5u)
#define CRYIF_SW_MINOR_VERSION                                       (1u)
#define CRYIF_SW_PATCH_VERSION                                       (0u)

#define CRYIF_INSTANCE_ID_DET                                        (0x00u)

#define CRYIF_SID_INIT                                               (0x00u)
#define CRYIF_SID_GET_VERSION_INFO                                   (0x01u)
#define CRYIF_SID_PROCESS_JOB                                        (0x02u)
#define CRYIF_SID_CANCEL_JOB                                         (0x03u)
#define CRYIF_SID_KEY_ELEMENT_SET                                    (0x04u)
#define CRYIF_SID_KEY_SET_VALID                                      (0x05u)
#define CRYIF_SID_KEY_ELEMENT_GET                                    (0x06u)
#define CRYIF_SID_KEY_ELEMENT_COPY                                   (0x0fu)
#define CRYIF_SID_KEY_ELEMENT_COPY_PARTIAL                           (0x12u)
#define CRYIF_SID_KEY_COPY                                           (0x10u)
#define CRYIF_SID_RANDOM_SEED                                        (0x07u)
#define CRYIF_SID_KEY_GENERATE                                       (0x08u)
#define CRYIF_SID_KEY_DERIVE                                         (0x09u)
#define CRYIF_SID_KEY_EXCHANGE_CALC_PUB_VAL                          (0x0au)
#define CRYIF_SID_KEY_EXCHANGE_CALC_SECRET                           (0x0bu)
#define CRYIF_SID_CERTIFICATE_PARSE                                  (0x0cu)
#define CRYIF_SID_CERTIFICATE_VERIFY                                 (0x11u)

#define CRYIF_E_NO_ERROR                                             (0xFFu)
#define CRYIF_E_UNINIT                                               (0x00u)
#define CRYIF_E_INIT_FAILED                                          (0x01u)
#define CRYIF_E_PARAM_POINTER                                        (0x02u)
#define CRYIF_E_PARAM_HANDLE                                         (0x03u)
#define CRYIF_E_PARAM_VALUE                                          (0x04u)
#define CRYIF_E_ALREADY_INITIALIZED                                  (0x11u)

#define CRYIF_UNINIT                                                 (0x00u)
#define CRYIF_INIT                                                   (0x01u)

#define CRYIF_START_SEC_CODE
#include "MemMap.hpp"

FUNC(void, CRYIF_CODE) CryIf_InitMemory(void);

FUNC(void, CRYIF_CODE) CryIf_Init(void);

#if(CRYIF_VERSION_INFO_API == STD_ON)

FUNC(void, CRYIF_CODE) CryIf_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CRYIF_APPL_VAR) versioninfo);
#endif

FUNC(Std_ReturnType, CRYIF_CODE) EcuabCryIf_ProcessJob(uint32 channelId
   ,                                                 P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_VAR) job);

FUNC(Std_ReturnType, CRYIF_CODE) EcuabCryIf_CancelJob(uint32 channelId
   ,                                                P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_VAR) job);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementSet(uint32 cryIfKeyId
   ,                                                    uint32 keyElementId
   ,                                                    P2CONST(uint8, AUTOMATIC, CRYIF_APPL_DATA) keyPtr
   ,                                                    uint32 keyLength);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeySetValid(uint32 cryIfKeyId);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementGet(uint32 cryIfKeyId
   ,                                                    uint32 keyElementId
   ,                                                    P2VAR(uint8, AUTOMATIC, CRYIF_APPL_VAR) resultPtr
   ,                                                    P2VAR(uint32, AUTOMATIC, CRYIF_APPL_VAR) resultLengthPtr);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementCopy(uint32 cryIfKeyId
   ,                                                     uint32 keyElementId
   ,                                                     uint32 targetCryIfKeyId
   ,                                                     uint32 targetKeyElementId);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementCopyPartial(uint32 cryIfKeyId
   ,                                                           uint32 keyElementId
   ,                                                           uint32 keyElementSourceOffset
   ,                                                           uint32 keyElementTargetOffset
   ,                                                           uint32 keyElementCopyLength
   ,                                                           uint32 targetCryIfKeyId
   ,                                                           uint32 targetKeyElementId);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyCopy(uint32 cryIfKeyId
   ,                                              uint32 targetCryIfKeyId);

FUNC(Std_ReturnType, CRYIF_CODE) EcuabCryIf_RandomSeed(uint32 cryIfKeyId
   ,                                                 P2CONST(uint8, AUTOMATIC, CRYIF_APPL_DATA) seedPtr
   ,                                                 uint32 seedLength);

FUNC(Std_ReturnType, CRYIF_CODE) EcuabCryIf_KeyGenerate(uint32 cryIfKeyId);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyDerive(uint32 cryIfKeyId
   ,                                                uint32 targetCryIfKeyId);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyExchangeCalcPubVal(uint32 cryIfKeyId
   ,                                                            P2VAR(uint8, AUTOMATIC, CRYIF_APPL_VAR) publicValuePtr
   ,                                                            P2VAR(uint32, AUTOMATIC, CRYIF_APPL_VAR) publicValueLengthPtr);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyExchangeCalcSecret(uint32 cryIfKeyId
   ,                                                            P2CONST(uint8, AUTOMATIC, CRYIF_APPL_DATA) partnerPublicValuePtr
   ,                                                            uint32 partnerPublicValueLength);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_CertificateParse(uint32 cryIfKeyId);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_CertificateVerify(uint32 cryIfKeyId
   ,                                                        uint32 verifyCryIfKeyId
   ,                                                        P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYIF_APPL_VAR) verifyPtr);

FUNC(Std_ReturnType, CRYIF_CODE) CryIf_KeyElementCopyPartial_Stub(uint32 cryIfKeyId
   ,                                                                 uint32 keyElementId
   ,                                                                 uint32 keyElementSourceOffset
   ,                                                                 uint32 keyElementTargetOffset
   ,                                                                 uint32 keyElementCopyLength
   ,                                                                 uint32 targetCryIfKeyId
   ,                                                                 uint32 targetKeyElementId);

#define CRYIF_STOP_SEC_CODE
#include "MemMap.hpp"

#endif

