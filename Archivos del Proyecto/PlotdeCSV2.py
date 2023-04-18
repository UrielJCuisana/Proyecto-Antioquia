import csv
import matplotlib.pyplot as plt
import os

# get the current working directory
current_directory = os.getcwd()

# print the current directory to the console
print("Current directory: ", current_directory)
 
# list the files in the current directory
print("Files in current directory: ", os.listdir())

# Read data from CSV file
with open('data.csv', 'r') as csvfile:
    reader = csv.DictReader(csvfile)
    data = {'time': [], 'humidity': [], 'temperature': [], 'pressure': []}
    for row in reader:
        data['time'].append(row['time'])
        data['humidity'].append(float(row['humidity']))
        data['temperature'].append(float(row['temperature']))
        data['pressure'].append(float(row['pressure']))

# Create figure and axes for humidity
fig, axs = plt.subplots(3, 1, figsize=(10,10))
fig.suptitle('Arduino Data')

axs[0].plot(data['time'], data['humidity'], label='Humidity')
axs[0].set_ylabel('Humidity')
axs[0].legend()

# Create figure and axes for temperature
axs[1].plot(data['time'], data['temperature'], label='Temperature')
axs[1].set_ylabel('Temperature')
axs[1].legend()

# Create figure and axes for pressure
axs[2].plot(data['time'], data['pressure'], label='Pressure')
axs[2].set_xlabel('Time')
axs[2].set_ylabel('Pressure')
axs[2].legend()

# Display all plots in the same window
plt.show()
