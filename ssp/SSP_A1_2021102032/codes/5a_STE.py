import numpy as np
import librosa
import matplotlib.pyplot as plt

def calculate_short_time_energy(signal, frame_length, hop_length):
    energy = []

    for i in range(0, len(signal) - frame_length + 1, hop_length):
        frame = signal[i:i+frame_length]
        frame_energy = np.sum(frame ** 2)
        energy.append(frame_energy)

    return energy

# Load an example audio file (replace 'your_audio_file.wav' with the actual file path)
audio_file = '1a.wav'
signal, sr = librosa.load(audio_file, sr=None)

# Define frame length and hop length in samples (adjust as needed)
frame_length = int(sr * 0.03) 
hop_length = int(sr * 0.01)     


energy = calculate_short_time_energy(signal, frame_length, hop_length)

# Create time axis array
num_frames = len(energy)
time_axis = np.linspace(0, len(signal) / sr, num_frames)

# Plot the short-time energy
plt.plot(time_axis, energy, label='Short-Time Energy')
plt.xlabel('Time (s)')
plt.ylabel('Energy')
plt.title('Short-Time Energy of Speech Signal')
plt.legend()
plt.show()
