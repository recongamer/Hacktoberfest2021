'''hello everyone!!! I am Pratyush and this is a basic matplotlib, scipy project to filter the noise from signals using Savitzky-Golay filter.

While observing radial velocities of stars using Redshift and spectroscopic measurements, we encounter many types of noise due to inter galactic dusts and cosmic rays etc. We are required to filter the information for further evaluation.

This is a 1-D filter. 

Parameters:

    1.signal(array) to be filtered

        
    2.window_length(int type):The length of the filter window (i.e., the number of coefficients). window_length must be a positive odd integer. 
    
    3.polyorder(int type):The order of the polynomial used to fit the samples. polyorder must be less than window_length.
    
    4.deriv(int type) (optional):The order of the derivative to compute. This must be a non-negative integer. The default is 0, which means to filter the data without differentiating.
    
    5.delta(float type)(optional): The spacing of the samples to which the filter will be applied. This is only used if deriv > 0. Default is 1.0.
    
    6.axis(int type)(optional):The axis of the array signal along which the filter is to be applied. Default is -1.
    
    7.mode(str type) (optional): Must be ‘mirror’, ‘constant’, ‘nearest’, ‘wrap’ or ‘interp’. This determines the type of extension to use for the padded signal to which the filter is applied. When mode is ‘constant’, the padding value is given by cval.  When the ‘interp’ mode is selected (the default), no extension is used. Instead, a degree polyorder polynomial is fit to the last window_length values of the edges, and this polynomial is used to evaluate the last window_length // 2 output values.
    
    8.cval(scalar type) (optional):Value to fill past the edges of the input if mode is ‘constant’. Default is 0.0.'''
    
#I have used vel_data.csv file as our source, which contains the noise added signals of radial velocity of some stars in neighborhood of our solar system.(i.e for d<3Kpc)    

import matplotlib.pyplot as plt
import pandas as pd
from scipy.signal import savgol_filter


vel_data = pd.read_csv('vel_data.csv')

plt.figure(figsize=(10,6))

#signal without filter plot showing
plt.title('velocity curve without filtering', fontdict={'fontweight':'bold', 'fontsize': 18})
plt.plot(vel_data['Time (years)'],vel_data['Observed Velocity (cm/s)']) 

plt.xlabel('time(in years)')
plt.ylabel('vel(in m/sec)')

plt.show()
plt.close()

#signal after noise filtering plot showing
Observed_Velocity_after_noise_removing = savgol_filter(vel_data['Observed Velocity (cm/s)'], 101, 2)
plt.title('velocity curve after filtering', fontdict={'fontweight':'bold', 'fontsize': 18})
plt.plot(vel_data['Time (years)'],Observed_Velocity_after_noise_removing) 

plt.xlabel('time(in years)')
plt.ylabel('vel(in m/sec)')

plt.savefig('vel.png', dpi=400)
plt.show()
