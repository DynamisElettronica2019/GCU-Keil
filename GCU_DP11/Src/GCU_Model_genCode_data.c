/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode_data.c
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.140
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu May 16 17:12:06 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "GCU_Model_genCode.h"

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Pooled Parameter (Expression: [uint16(0),uint16(100),uint16(200),uint16(300),uint16(400),uint16(500),uint16(600),uint16(700)])
   * Referenced by:
   *   '<S1>/1-D Lookup Table1'
   *   '<S1>/1-D Lookup Table2'
   *   '<S1>/1-D Lookup Table3'
   */
  { 0U, 100U, 200U, 300U, 400U, 500U, 600U, 700U },

  /* Pooled Parameter (Expression: [0:7])
   * Referenced by:
   *   '<S1>/1-D Lookup Table1'
   *   '<S1>/1-D Lookup Table2'
   *   '<S1>/1-D Lookup Table3'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Rate Transition1'
   *   '<Root>/Rate Transition2'
   *   '<Root>/Rate Transition27'
   *   '<Root>/Rate Transition4'
   *   '<Root>/Rate Transition8'
   *   '<S1>/Constant'
   *   '<S8>/debugValues'
   *   '<S10>/oil_sensor'
   *   '<S23>/Values'
   */
  0U,

  /* Computed Parameter: GCU_FEEDBACK_ID_Value
   * Referenced by: '<S43>/GCU_FEEDBACK_ID'
   */
  793U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
