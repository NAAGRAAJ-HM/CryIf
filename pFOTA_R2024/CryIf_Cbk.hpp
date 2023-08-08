

#if !defined (CRYIF_CBK_H)
# define CRYIF_CBK_H

# include "EcuabCryIf.hpp"

# define CRYIF_START_SEC_CODE
# include "MemMap.hpp"

FUNC(void, CRYIF_CODE) CryIf_CallbackNotification(P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_VAR) job,
  Std_ReturnType result);

# define CRYIF_STOP_SEC_CODE
# include "MemMap.hpp"

#endif

