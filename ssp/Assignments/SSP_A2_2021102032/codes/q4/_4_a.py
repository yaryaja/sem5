import librosa
import numpy as np

def split_audio_file_into_frames(audio_file, window_length, hop_length):
    signal, sr = librosa.load(audio_file, sr=None)  # Load audio file
    num_frames = 1 + (len(signal) - window_length) // hop_length
    frames = np.zeros((num_frames, window_length))
    for i in range(num_frames):
        start = i * hop_length
        end = start + window_length
        frames[i] = signal[start:end]

    return frames

audio_file_path = "q4/q4_audio.wav" 
window_length = 512
hop_length = 256

frames = split_audio_file_into_frames(audio_file_path, window_length, hop_length)
print("Number of frames:", frames.shape[0])
print("Frame shape:", frames.shape[1])
