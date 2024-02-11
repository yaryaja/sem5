import numpy as np

def zero_crossing_rate_classification(signal, threshold):
    zcr = np.sum(np.abs(np.diff(np.sign(signal)))) / (2 * len(signal))
    if zcr < threshold:
        return "Voiced"
    else:
        return "Unvoiced"


def energy_based_classification(signal, threshold):
    energy = np.sum(signal ** 2)
    print(energy)
    if energy > threshold:
        return "Voiced"
    else:
        return "Unvoiced"
