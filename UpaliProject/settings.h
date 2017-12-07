/**************************************************************************//**
* @file settings.h
* @brief Contains configurable #defines and widely used constant #defines
* @version 0.0.1
******************************************************************************/


#ifndef INC_SETTINGS_H_
#define INC_SETTINGS_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Constant #defines */

#define US3_TX_LOCATION 5
#define US3_RX_LOCATION 5
#define US3_CLK_LOCATION 5
#define US3_CS_LOCATION 5
#define BUFSIZE 1024
#define DATABUFSIZE (4 * BUFSIZE)
#define NUMTAPS 97
#define NUMTAPS_MEL 51
#define SAMPLE_RATE 8192
#define DMA_BUFFER_SIZE 4
#define FFTSIZE BUFSIZE / 2
#define MFCC_SIZE 24
#define USER_DATA_PAGE (volatile uint32_t *) 0x0FE00000
#define NORMFACTOR 0.02209708f

/* Word Defines for Access through candidates Array */

  // Candidate Groups
  #define CANDIDATE_GROUP_1 0

  // Candidates
  #define OFF 0
  #define BLUE 1
  #define RED 2
  #define GREEN 3
  #define ON 4

/* Configurable #defines */

  // Configures how hard it is to trigger a voice command (lower = more sensitive)
  #define BEGIN_SENSITIVITY 1.65f

  // Configures how much of the end of the word is recorded
  #define END_SENSITIVITY 1.25f

  // Number of extra samples to be taken
  // after sound passes below ending threshold
  #define EXTRA 256 // Value depends on max number of syllables in a keyword

  // Number of times that the background noise calibration loop is executed
  #define CALIB_NUM 15

  // Amount of time that is waited before starting background noise calibration
  #define CALIB_WAIT_TIME 8192 // Recommended >= 8192 if using STK's microphone

  // Number of words per candidate group
  #define MAX_NUM_CANDIDATES 5

  // Number of candidate groups : highest number of words in a command
  // Example: if a command was "set temp 1", NUM_CANDIDATE_GROUPS would be 3
  #define NUM_CANDIDATE_GROUPS 1

  // Number of times each keyword must be said to train
  #define NUM_TRAININGS 2

  // Determines whether the program will use the stored values in getCost.c
  // for MFCCs (false) or start training on startup (true)
  #define TRAINING_ENABLE false

#ifdef __cplusplus
}
#endif

#endif /* INC_SETTINGS_H_ */
	