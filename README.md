# ASR
Automatic speech recognition for Tiva-C LaunchPad

WORK IN PROGRESS!

Finished with the MFCC. 
ADC (with DMA) finished!
Now, onto Forward Algorithm for Probabilty Evaluation. I will find the Baum–Welch algorithm online for parameter reestimation. In MATLAB.

All the files besides are included, except for TivaWare libraries, which can be easily downloaded from the web.


Short description of MFCC: it is used for extracting the most useful components from human speech. It works by applying a filter bank of triangular filters to signal spectruum. This filterbank gives more priority to lower frequencies. 
