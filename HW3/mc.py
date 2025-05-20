import numpy as np
import pandas as pd

def gbm(S, r, sig, v, dt):
    return S * np.exp((r + v - 0.5*sig**2)*(dt) + sig * np.sqrt(dt) * np.random.standard_normal())

def mc_gbm(r, sig, steps, T=1.0, S0=100, v=0, paths=100):
    dt = T/steps
    arr = np.zeros((steps + 1, paths))
    arr[0,:] = S0
    for i in range(1,steps+1):
        for j in range(paths):
            arr[i,j] = gbm(S=arr[i-1,j], r=r, sig=sig, v=v, dt=dt)
    return pd.DataFrame(arr)

def ou(S, sig, theta, mu, dt):
    return S + theta * (mu - S) * dt + sig * np.sqrt(dt) * np.random.standard_normal()

def mc_ou(sig, steps, theta=0.7, mu=None, T=1.0, S0=100, v=0, paths=100):
    if mu is None:
        mu = S0
    dt = T/steps
    arr = np.zeros((steps + 1, paths))
    arr[0,:] = S0
    for i in range(1,steps+1):
        for j in range(paths):
            arr[i,j] = ou(S=arr[i-1,j], sig=sig, theta=theta, mu=mu, dt=dt)
    return pd.DataFrame(arr)

def abm(S, r, sig, v, dt):
    return S + (r + v) * dt + sig * np.sqrt(dt) * np.random.standard_normal()

def mc_abm(r, sig, steps, T=1.0, S0=100, v=0, paths=100):
    dt = T/steps
    arr = np.zeros((steps + 1, paths))
    arr[0,:] = S0
    for i in range(1,steps+1):
        for j in range(paths):
            arr[i,j] = abm(S=arr[i-1,j], r=r, sig=sig, v=v, dt=dt)
    return pd.DataFrame(arr)

if __name__ == '__main__':
    print(mc_gbm(0, 0.2, steps=5, paths=2))