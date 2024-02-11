import librosa
import numpy as np
import matplotlib.pyplot as plt

from _4_a import split_audio_file_into_frames


audio_file_path = "q4/q4_audio.wav" 
window_length = 512
hop_length = 256


frames = split_audio_file_into_frames(audio_file_path, window_length, hop_length)

num_frames = frames.shape[0]
print("Number of frames:", num_frames)
print("Frame shape:", frames.shape[1])

# Plot 
signal, sr = librosa.load(audio_file_path, sr=None)  
plt.figure(figsize=(10, 6))
librosa.display.waveshow(signal, sr=sr)
plt.title("Time Domain Waveform")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.show()
