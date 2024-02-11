import numpy as np
import scipy.signal
import matplotlib.pyplot as plt
import soundfile as sf

# Load an audio file
filename = 'wavs/q3_audio.wav'  # Replace with your audio file path
audio_signal, sample_rate = sf.read(filename)


w_size = 1024  
hop_size = 512     
window_functions = [
    ('Rectangular', np.ones(w_size)),
    ('Triangular', scipy.signal.windows.triang(w_size)),
    ('Hanning', np.hanning(w_size))
]

plt.figure(figsize=(12, 8))
for i, (window_name, window) in enumerate(window_functions):
    stft_result = []
    num_frames = 1 + (len(audio_signal) - w_size) // hop_size
    for t in range(num_frames):
        frame = audio_signal[t * hop_size : t * hop_size + w_size] * window
        frame_fft = np.fft.fft(frame)
        stft_result.append(frame_fft[:w_size // 2 + 1])
    stft_matrix = np.array(stft_result).T

    time_edges = np.arange(num_frames) * hop_size / sample_rate
    freq_edges = np.fft.fftfreq(w_size, 1.0 / sample_rate)[:w_size // 2 + 1]
    plt.subplot(len(window_functions), 1, i + 1)
    plt.pcolormesh(time_edges, freq_edges, 20 * np.log10(np.abs(stft_matrix)), shading='auto')
    plt.colorbar(label='Magnitude (dB)')
    plt.title(f'STFT with {window_name} Window')
    plt.ylabel('Frequency (Hz)')
plt.xlabel('Time (s)')
plt.tight_layout()
plt.show()
