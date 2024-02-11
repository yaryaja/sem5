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

zcr_threshold = 4.3  


classification = [energy_based_classification(frame, zcr_threshold) for frame in frames]



for t, frame_label in enumerate(classification):
    # print(frame_label)
    if(frame_label=="Unvoiced"):
        unvoiced_frame=frames[t]
        break
# magnitude spectrum for voiced frame
unvoiced_frame_length=len(unvoiced_frame)
unvoiced_frame_windowed=unvoiced_frame*np.hamming(unvoiced_frame_length)

unvoiced_magnitude_spectrum=np.abs(np.fft.fft(unvoiced_frame_windowed))
# reconstruction in time domain
# introducing random phase
unvoiced_phases=np.random.rand(len(unvoiced_magnitude_spectrum))*2*np.pi  

unvoiced_complex_spectrum=unvoiced_magnitude_spectrum*np.exp(1j*unvoiced_phases)

# inverse fft
unvoiced_reconstructed_signal=np.fft.ifft(unvoiced_complex_spectrum)
time_axis = np.arange(len(unvoiced_reconstructed_signal))
#  code for unvoiced part magnitude spectrum and reconstruction


# Plot the magnitude spectrum in the second subplot
plt.subplot(3, 1, 1)
plt.plot(unvoiced_frame)
plt.title('Original Spectrum')
plt.xlabel('sample index ')
plt.ylabel('Magnitude')
plt.grid(True)


# Plot the magnitude spectrum in the second subplot
plt.subplot(3, 1, 2)
plt.plot(unvoiced_magnitude_spectrum)
plt.title('Magnitude Spectrum')
plt.xlabel('Frequency ')
plt.ylabel('Magnitude')
plt.grid(True)

# Plot the reconstructed signal in the first subplot
plt.subplot(3, 1, 3)
plt.plot(time_axis, np.real(unvoiced_reconstructed_signal))
plt.title('Reconstructed Signal')
plt.xlabel('Sample Index')
plt.ylabel('Amplitude')
plt.grid(True)


# Adjust layout and display the plot
plt.tight_layout()
plt.show()





