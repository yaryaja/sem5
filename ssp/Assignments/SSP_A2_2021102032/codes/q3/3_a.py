import numpy as np
import matplotlib.pyplot as plt
import soundfile as sf

filename = 'wavs/q3_audio.wav'
audio_signal, sample_rate = sf.read(filename)
# print(sample_rate)


w_size =1024  # window size
hop_size = 512      # Hop size
n_frames = 1 + (len(audio_signal) - w_size) // hop_size
stft_matrix = np.empty((w_size // 2 + 1, n_frames), dtype=np.complex128)

# Perform STFT using FFT
for t in range(n_frames):
    start = t * hop_size
    end = start + w_size
    frame = audio_signal[start:end]
    windowed_frame = frame * np.hanning(w_size)
    frame_fft = np.fft.fft(windowed_frame)

    stft_matrix[:, t] = frame_fft[:w_size // 2 + 1]

frequencies = np.fft.fftfreq(w_size, 1.0 / sample_rate)[:w_size // 2 + 1]

time_edges = np.arange(n_frames + 1) * hop_size / sample_rate
freq_edges = np.linspace(0, sample_rate / 2, len(frequencies) + 1)
print(freq_edges)

plt.figure(figsize=(12, 8))
plt.pcolormesh(time_edges, freq_edges, 20 * np.log10(np.abs(stft_matrix)), shading='auto')
plt.colorbar(label='Magnitude (dB)')
title = f'STFT with Window Size: {w_size}, Hop Length: {hop_size}'
plt.title(title)
plt.xlabel('Time (s)')
plt.ylabel('Frequency (Hz)')
plt.show()