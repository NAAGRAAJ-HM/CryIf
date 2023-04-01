#pragma once
/******************************************************************************/
/* File   : EcuabCryIf.hpp                                                         */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "ConstEcuabCryIf.hpp"
#include "CfgEcuabCryIf.hpp"
#include "EcuabCryIf_core.hpp"
#include "infEcuabCryIf_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_EcuabCryIf:
      INTERFACES_EXPORTED_CRYIF
      public abstract_module
   ,  public class_EcuabCryIf_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstEcuabCryIf_Type* lptrConst = (ConstEcuabCryIf_Type*)NULL_PTR;

   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      FUNC(void, CRYIF_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, CRYIF_CONST,       CRYIF_APPL_CONST) lptrConstModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   CRYIF_CONFIG_DATA, CRYIF_APPL_CONST) lptrCfgModule
      );
      FUNC(void, CRYIF_CODE) DeInitFunction (void);
      FUNC(void, CRYIF_CODE) MainFunction   (void);
      CRYIF_CORE_FUNCTIONALITIES
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
extern VAR(module_EcuabCryIf, CRYIF_VAR) EcuabCryIf;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

