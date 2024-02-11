import librosa
import numpy as np
import matplotlib.pyplot as plt


from _4_a import split_audio_file_into_frames

audio_file_path = "q4/q4_audio.wav"  
signal, sample_rate = librosa.load(audio_file_path, sr=None)  
window_length = 512
hop_length = 256


frames = split_audio_file_into_frames(audio_file_path, window_length, hop_length)

fft_result = np.fft.fft(signal)
frequencies = np.fft.fftfreq(len(fft_result), 1.0 / sample_rate)


plt.figure(figsize=(12, 6))
plt.subplot(2, 1, 1)
plt.plot(frequencies, np.abs(fft_result))
plt.title('FFT of the Entire Signal')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude')
plt.xlim(0, sample_rate / 2)
plt.grid()



frame_fft_results = [np.fft.fft(frame) for frame in frames[:5]]

frame_frequencies = np.fft.fftfreq(window_length, 1.0 / sample_rate)[:window_length]

plt.figure(figsize=(12, 4))
for i, frame_fft in enumerate(frame_fft_results):
    # i am plotting for first 5 frames only for the better visulization
    plt.subplot(5, 1, i + 1)
    plt.plot(frame_frequencies, np.abs(frame_fft))
    plt.title(f'FFT of Frame {i}')
    plt.xlabel('Frequency (Hz)')
    plt.ylabel('Magnitude')
    plt.xlim(0, sample_rate / 2)
    plt.grid()

plt.tight_layout()
plt.show()
