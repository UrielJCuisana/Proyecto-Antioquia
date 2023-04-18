import csv
import matplotlib.pyplot as plt

import matplotlib.widgets as widgets
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
            

# Create figure and axes
fig, ax = plt.subplots()

# Plot data
humidity_plot, = ax.plot(data['time'], data['humidity'], label='Humidity')
temperature_plot, = ax.plot(data['time'], data['temperature'], label='Temperature')
pressure_plot, = ax.plot(data['time'], data['pressure'], label='Pressure')

# Set axis labels and title
ax.set_xlabel('Time')
ax.set_ylabel('Value')
ax.set_title('Arduino Data')

# Add legend
ax.legend()

# Define checkboxes
checkboxes_ax = plt.axes([0.05, 0.7, 0.1, 0.2])
checkboxes = widgets.CheckButtons(checkboxes_ax, labels=['Humidity', 'Temperature', 'Pressure'])

# Define dictionary to keep track of line visibility
line_visibility = {'Humidity': True, 'Temperature': True, 'Pressure': True}

# Define function to update plot based on checkbox state
def update_plot(label):
    if label == 'Humidity':
        line_visibility['Humidity'] = not line_visibility['Humidity']
        humidity_plot.set_visible(line_visibility['Humidity'])
    elif label == 'Temperature':
        line_visibility['Temperature'] = not line_visibility['Temperature']
        temperature_plot.set_visible(line_visibility['Temperature'])
    elif label == 'Pressure':
        line_visibility['Pressure'] = not line_visibility['Pressure']
        pressure_plot.set_visible(line_visibility['Pressure'])
    plt.draw()

# Register update function with checkboxes
checkboxes.on_clicked(update_plot)

# Display plot
plt.show()
