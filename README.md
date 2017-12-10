# ASR
Automatic speech recognition for Tiva-C LaunchPad

WORK IN PROGRESS!

Finished with the MFCC. 
ADC (with DMA) finished!
Now, onto Forward Algorithm for Probabilty Evaluation. I will use the Baum–Welch algorithm for parameter reestimation. Python library is available for it, called hmmlearn.

All the files besides are included, except for TivaWare libraries, which can be easily downloaded from the web.


Short description of MFCC: it is used for extracting the most useful components from human speech. It works by applying a filter bank of triangular filters to signal spectruum. This filterbank gives more priority to lower frequencies. 
