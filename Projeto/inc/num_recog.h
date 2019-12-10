#ifndef numrecog
#define numrecog

#include <errno.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
/** @file num_recog.h
 *  This file provides a interface for number recognition from voice.
 */


/**
 * @brief This type defines the information set of each number recognition.
 */
typedef struct
{
   unsigned number; /*!< Detected number */   	
   clock_t clock; /*!< Monotonic time at the detection instant */
}T_numrecog_info;

/**
 * @brief This type defines the ring buffer of recognized numbers
 */
typedef struct
{
   T_numrecog_info * buffer; /*!< The buffer of recognizied */
   unsigned size; /*!< The buffer size in number of recognitions */
   unsigned count; /*!< Number recognitions in buffer */
   unsigned rd_pos; /*!< Position of next reading */
   unsigned wr_pos; /*!< Position of next writing */
   pthread_mutex_t lock; /*!< Mutex for safe access */
}T_numrecog_rbuffer;


/**
 * @brief This type defines the context of the number recognition
 */
typedef struct
{
   unsigned partial; /*!< Partial result */
   unsigned last_place; /*!< Place value of last recognition */
   clock_t last_clock; /*!< System clock of last recognition */
   clock_t no_answere_timeout_clock; /*!< Timeout to consider the question not answered.*/
   clock_t answere_timeout_clock; /*!< Timeout to consider the question answered */
   clock_t start_clock; /*!< Clock count at the startting */
   T_numrecog_rbuffer rbuffer; /*!< Ring buffer of recognized numbers */
   pthread_t thread_id; /*!< Id of scanning thread */
   int scan_file; /*!< Desriptor of scanned file */
   const char * scan_file_name; /*!< Absolute path of scanned file */
   char * charbuffer; /*!< buffer available to receive chars from scanned file */
   unsigned charlen; /*!< Size of charbuffer */
   unsigned charpos; /*!< Write position of charbuffer */
}T_numrecog_cotext;


/** 
 * @brief This function configures the number recognition
 *
 * @param[out] arg_context_ptr is a pointer to the context that receives these settings. 
 *       See #T_numrecog_cotext.
 * @param[in] arg_timeout_ms  is the timeout in milliseconds to consider "no recognition"
 * @param[in] arg_num_timout_ms is the timeout the end the recognition after the 
 *       recognition of a number that may be a complement, i.e "vinte" e "cinco".
 * @param[in] arg_buffer is the buffer available to store the recognized numbers. 
 *       See #T_numrecog_info.
 * @param[in] arg_size is the size of arg_bufer in number of elements #T_numrecog_info.
 * @param[in] arg_file_str is the absolute path of scanned file.
 * @param[in] arg_charbuffer_ptr is the buffer to receive chars from scanned file.
 * @param[in] arg_charlen is the length of arg_charbuffer_ptr.
 *
 * @return This function returns 0 when the setting is successfully perfomed, 
 *         otherwise it returns:
 *         - EFAULT, if arg_context_ptr is a invalid address;
 *         - The error code returned by pthread_mutex_init, if it fails initializing 
 *           ring buffer mutex.
 *         - The error code returned by pthread_create, if it fails creating the thread
 *           for regonition.
 */
int numrecog_start( T_numrecog_cotext * arg_context_ptr,
                    int arg_timeout_ms,
                    int arg_num_timout_ms,
                    T_numrecog_info * arg_buffer,
                    unsigned arg_size,
                    const char * arg_file_str,
                    char * arg_charbuffer_ptr,
                    unsigned arg_charlen );

/**
 * @brief This function reads the recognized numbers.
 *
 * @param[in] arg_context_ptr is a pointer to the context that receives these settings. 
 *       This pointer must be previously configured by the function #numrecog_start. 
 *       See #T_numrecog_cotext.
 * @param[out] arg_num_ptr is the address of the variable that receives the recognized number.
 * @param[out] arg_timeout_ptr points the the variable that receives logic value 'true' if the *       recognition has timed out with no detections. 
 *
 * @return This function returns the address arg_recog when a valid number has been 
 *         recognized, otherwise it returns NULL.
 *
 */
unsigned * numrecog_read( T_numrecog_cotext * arg_context_ptr, 
                          unsigned * arg_num_ptr,
                          bool * arg_timeout_ptr );

/**
 * @brief This function stops the voice-number recognition.
 * 
 * @param[in] arg_context_ptr is a pointer to the context of the number recognition
 *
 * @return This function returns 0 when the stopping is successfully performed, otherwise
 *         it returns -1.
 */
int numrecog_stop( T_numrecog_cotext * arg_context_ptr );


#endif

