import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf


from algorithms import *


filename = 'q4/q4_audio.wav'  
audio_signal, sample_rate = sf.read(filename)
audio_signal=audio_signal[:len(audio_signal)//2]

window_size = 800 
hop_size = 400     


num_frames = 1 + (len(audio_signal) - window_size) // hop_size
frames = [audio_signal[t * hop_size : t * hop_size + window_size] for t in range(num_frames)]

zcr_threshold = 12 # can be adjusted acc to need and data

classification = [energy_based_classification(frame, zcr_threshold) for frame in frames]





for t, frame_label in enumerate(classification):
 
    if(frame_label=="Voiced"):
        voiced_frame=frames[t]
        break
# magnitude spectrum for voiced frame
voiced_frame_length=len(voiced_frame)
voiced_frame_windowed=voiced_frame*np.hamming(voiced_frame_length)

voiced_magnitude_spectrum=np.abs(np.fft.fft(voiced_frame_windowed))
# reconstruction in time domain
# introducing random phase
voiced_phases=np.random.rand(len(voiced_magnitude_spectrum))*2*np.pi  

voiced_complex_spectrum=voiced_magnitude_spectrum*np.exp(1j*voiced_phases)

# inverse fft
voiced_reconstructed_signal=np.fft.ifft(voiced_complex_spectrum)
time_axis = np.arange(len(voiced_reconstructed_signal))

plt.subplot(3, 1, 1)
plt.plot(voiced_frame)
plt.title('Original Spectrum')
plt.xlabel('sample index ')
plt.ylabel('Magnitude')
plt.grid(True)

plt.subplot(3, 1, 2)
plt.plot(voiced_magnitude_spectrum)
plt.title('Magnitude Spectrum')
plt.xlabel('Frequency ')
plt.ylabel('Magnitude')
plt.grid(True)


plt.subplot(3, 1, 3)
plt.plot(time_axis, np.real(voiced_reconstructed_signal))
plt.title('Reconstructed Signal')
plt.xlabel('Sample Index')
plt.ylabel('Amplitude')
plt.grid(True)


plt.tight_layout()
plt.show()





