import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf
import librosa.display

audio_file_path = "q4/q4_audio.wav" 
window_length = 512
hop_length = 256

from _4_a import split_audio_file_into_frames

signal, sr = librosa.load(audio_file_path, sr=None)
frames = split_audio_file_into_frames(audio_file_path, window_length, hop_length)  # Pass the file path here

def calculate_pitch_contour(frames, sr):
    pitch_contour = []
    for frame in frames:
        pitches, magnitudes = librosa.piptrack(y=frame, sr=sr)
        pitch_index = magnitudes.argmax()
        pitch = pitches[pitch_index]
        pitch_contour.append(pitch)

    
    return np.array(pitch_contour)

pitch=calculate_pitch_contour(frames, sr)


