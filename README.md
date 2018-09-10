# ASR
Automatic speech recognition for Tiva-C LaunchPad

Het vordert goed

Latest update: It is kind of working. Definitely a good start. It requires me to speak the keyword at a particular speed, which has to be fixed, and also precision and generality are not the best. 80% for the former and 70% for the latter. But, the important thing is it is currently using ~16KB of memory (out of 32KB), so a lot of space for improvement, and also I could fit in, time-wise, as many operations as I am currently using.

All of the accompanying theory can be found here: http://www.ai.rug.nl/nl/vakinformatie/sr/articles/MSc-Thesis-MiMa-Clear-HMM-intro.pdf

For speech recognition I am using Hidden Markov Model (HMM) with four states (Gaussian distributions), not previosly mentioned Mixture-of-Gaussians HMM, for which it was difficult to get the necessary training algorithm. 

Features I have used to model speech are Mel-frequency cepstral coefficients (MFCCs). Twelve of them in total, 2nd-13th. No other data has been used, except for signal's FFT magnitudes to determine if any word has been spoken.

Things to do in the future: better voice activation detection, trim the training data signals (remove the silent parts), more robust microphone, add two more .c files for the sake of modularity, and do some documenting (Doxygen).

I will post a video showcasing its performance, sometime soon.


**FINAL REMARKS: The errors finaly got me. I was fixing them for about two months. I'm putting this on an indefinite hold. 
Here are some of the errors I have been dealing with: https://e2e.ti.com/search?author=336662 **

I am sure it is going to be of help to someone doing ASR, with these methods and packages.
I will put up a more updated, more modular version.

If you wonder how was its correctness checked, it was done by comparing its results with a (almost) same Python implementation on PC. One that works.
