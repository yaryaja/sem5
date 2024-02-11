import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf


from algorithms import *



filename = 'q4/q4_audio.wav'  
audio_signal, sample_rate = sf.read(filename)
audio_signal=audio_signal[:len(audio_signal)//2]


window_size = 1024
hop_size = 512    

num_frames = 1 + (len(audio_signal) - window_size) // hop_size
frames = [audio_signal[t * hop_size : t * hop_size + window_size] for t in range(num_frames)]
print(num_frames)

zcr_threshold = 5  
classification = [energy_based_classification(frame, zcr_threshold) for frame in frames]

# Plot the frames as voiced or unvoiced
plt.figure(figsize=(12, 4))
for t, frame_label in enumerate(classification):
    plt.subplot(num_frames, 1, t + 1)
    plt.plot(frames[t])
    plt.title(f'Frame {t+1}: {frame_label}')
    # plt.xlabel('Sample Index')
    plt.ylabel('Amplitude')

plt.tight_layout()
plt.show()
