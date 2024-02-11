import numpy as np
import matplotlib.pyplot as plt
import librosa

def ZCR(input_audio, frames, n_frames, Fs):
  
    
    # Mean justification
    for i in range(n_frames):
        frames[:, i] = frames[:, i] - np.mean(frames[:, i])
    
    # ZCR computation
    zcr = np.sum(np.logical_and(frames[:-1, :] * frames[1:, :] < 0, True), axis=0)
    
    # Plotting
    plt.figure()
    sampleTime = np.arange(1, len(input_audio) + 1) / Fs
    plt.subplot(2, 1, 1)
    plt.plot(sampleTime, input_audio)
    plt.ylabel('Amplitude')
    plt.title('Audio input')
    
    plt.subplot(2, 1, 2)
    plt.plot(zcr, '.-')
    plt.xlabel('sample')
    plt.ylabel('Count')
    plt.title('ZCR')
    
    plt.tight_layout()
    plt.show()

# Example usage
input_audio = 'sample.wav'
y, Fs = librosa.load(input_audio)
y = y * (2 ** 15)  # Convert to integer representation
print(Fs)

n_samples = len(y)


frame_length = int(Fs * 0.03)  # 30 ms 
overlap = frame_length // 3
n_frames = (n_samples - overlap) // (frame_length - overlap)

frames = np.zeros((frame_length, n_frames))
for i in range(n_frames):
    start = i * (frame_length - overlap)
    end = start + frame_length
    frames[:, i] = y[start:end]

ZCR(y, frames, n_frames, Fs)
